import ROOT
import math
import pandas as pd
import uproot
import sys, os, time
import re
import numpy as np
import awkward as ak
import dask_awkward as dak
import dask.dataframe as dd
#import awkward.operations.str as akstr
import pyarrow
import matplotlib.pyplot as plt
from math import sqrt
import dask

NCUTS = 9
NMU = 3

def DimuonMass(sub_df):
    # Calculate the momentum components for each particle
    px1 = sub_df["Mu01_Pt"] * np.cos(sub_df["Mu01_Phi"])
    py1 = sub_df["Mu01_Pt"] * np.sin(sub_df["Mu01_Phi"])
    pz1 = sub_df["Mu01_Pt"] * np.sinh(sub_df["Mu01_Eta"])   

    px2 = sub_df["Mu02_Pt"] * np.cos(sub_df["Mu02_Phi"])
    py2 = sub_df["Mu02_Pt"] * np.sin(sub_df["Mu02_Phi"])
    pz2 = sub_df["Mu02_Pt"] * np.sinh(sub_df["Mu02_Eta"])

    # Total energy and momentum components
    E_total = sub_df["Mu01_energy"]  + sub_df["Mu02_energy"] 
    px_total = px1 + px2
    py_total = py1 + py2
    pz_total = pz1 + pz2

    # Invariant mass calculation
    invariant_mass = np.sqrt(E_total*E_total - (px_total*px_total + py_total*py_total + pz_total*pz_total))
    invariant_mass = dak.where(sub_df["Mu0102_charge"]!=0, 0, invariant_mass)
    return invariant_mass
    
def ak_abs(array):
    return dak.where(array < 0, -array, array)

def DuplicateFinder(df):
    return ((abs(df.Mu01_Eta-df.Tr_Eta)>0.0001)&(abs(df.Mu02_Eta-df.Tr_Eta)>0.0001)&(abs(df.Mu01_Phi-df.Tr_Phi)>0.0001)&(abs(df.Mu02_Phi-df.Tr_Phi)>0.0001)&(abs(df.Mu01_Pt-df.Tr_Pt)>0.0001)&(abs(df.Mu02_Pt-df.Tr_Pt)>0.0001)&(abs(df.Mu01_Eta-df.Mu02_Eta)>0.0001)&(abs(df.Mu01_Phi-df.Mu02_Phi)>0.0001)&(abs(df.Mu01_Pt-df.Mu02_Pt)>0.0001))

        
def Fill_CutName(df, listCut):
    nameCut = ["BeforeCuts", "L1_fired", "HLT_fired", "MuonID", "DiMu_mass", "TriMu_mass", "mu1_TrMatch", "mu12_TrMatch", "mu123_TrMatch"]
    #print(len(nameCut))
    #print(NCUTS)
    if len(nameCut) != NCUTS: 
        print("length of the cut names does not match number of cuts")
        return
    for i in range(NCUTS):
        listCut.append(nameCut[i])
    
def Draw_CutEffCanvas(df, canv, hist, cut, listCut):
    #print(cut)
    canv = ROOT.TCanvas("", "")
    canv.cd()
    for k in range(len(listCut)):
        hist.Fill(k+1, cut[k])
        hist.GetXaxis().SetBinLabel(k+1, listCut[k])
    hist.DrawCopy("HIST TEXT0")
    hist.Write()


def Get_MuonAndTrackVariables(df, mu_Ind): #, pt, eta, phi)
    #print(df.Mu01_Pt.iloc[0])
    pt = [df.Mu01_Pt.iloc[0][mu_Ind[0]], df.Mu02_Pt.iloc[0][mu_Ind[1]], df.Tr_Pt.iloc[0][mu_Ind[2]]]
    eta = [df.Mu01_Eta.iloc[0][mu_Ind[0]], df.Mu02_Eta.iloc[0][mu_Ind[1]], df.Tr_Eta.iloc[0][mu_Ind[2]]]
    phi = [df.Mu01_Phi.iloc[0][mu_Ind[0]], df.Mu02_Phi.iloc[0][mu_Ind[1]], df.Tr_Phi.iloc[0][mu_Ind[2]]]
    return pt, eta, phi

def MuonP(df, pt, eta, phi):
    muon = ROOT.TVector3()
    muon.SetPtEtaPhi(pt, eta, phi)
    return muon.Mag()

def TreeFin_Angle(df, ind):
    a_x = df.TripletVtx2_x.iloc[0][ind] - df.RefittedPV2_x.iloc[0][ind]
    a_y = df.TripletVtx2_y.iloc[0][ind] - df.RefittedPV2_y.iloc[0][ind]
    a_z = df.TripletVtx2_z.iloc[0][ind] - df.RefittedPV2_z.iloc[0][ind]
    b = ROOT.TVector3()
    b.SetPtEtaPhi(df.Triplet2_Pt.iloc[0][ind], df.Triplet2_Eta.iloc[0][ind],df.Triplet2_Phi.iloc[0][ind])
    b_x = b.Px()
    b_y = b.Py()
    b_z = b.Pz()
    a_mod = abs(df.FlightDistPVSV2.iloc[0][ind])
    b_mod = abs(b.Mag())
    cos_ang = ((a_x*b_x)+(a_y*b_y)+(a_z*b_z))/(a_mod*b_mod)
    angle = math.acos(min(max(cos_ang,-1.0),1.0))
    return angle


def TreeFin_Fill(df, jentry, df_fin, debugMode, isMC, ind, mu_Ind, mu, lumi, run, evt, L1_DoubleMu0_er1p5, L1_DoubleMu0_er1p4, L1_DoubleMu4_dR1p2,L1_DoubleMu4p5_dR1p2, L1_DoubleMu0_er2p0, L1_DoubleMu0_er2p0_bk, L1seed, HLTpath):
    #print("il baco è qui")
    if debugMode:
        print("Ciao1")
    #mu = MatchIndex(df, "ID", ind)
    #print(mu_Ind)
    #print(df.Mu01_Pt.iloc[0])
    pt, eta, phi = Get_MuonAndTrackVariables(df, mu_Ind)#, pt, eta, phi)
    cLP = -999
    tKink = -999
    segmComp = 999
    DeltaR_max = -999
    DeltaZ_max = -999
    temp1 = []
    temp = []
    dR = []
    dZ = []
    temp1.append(df.dxy_mu1.iloc[0][mu_Ind[0]])
    temp1.append(df.dxy_mu2.iloc[0][mu_Ind[1]])
    temp1.append(df.dxy_mu3.iloc[0][mu_Ind[2]])
    dR.append(math.sqrt(pow((eta[0]-eta[1]),2)+pow((phi[0]-phi[1]),2)))
    dR.append(math.sqrt(pow((eta[0]-eta[2]),2)+pow((phi[0]-phi[2]),2)))
    dR.append(math.sqrt(pow((eta[2]-eta[1]),2)+pow((phi[2]-phi[1]),2)))
    dZ.append(abs(df.Muon_vz.iloc[0][mu[0]] - df.Muon_vz.iloc[0][mu[1]] ))
    dZ.append(abs(df.Muon_vz.iloc[0][mu[0]] - df.Track_vz.iloc[0][mu[2]] ))
    dZ.append(abs(df.Track_vz.iloc[0][mu[2]]  - df.Muon_vz.iloc[0][mu[1]] ))
    d0 = 999
    temp.append(abs(df.dxy_mu1.iloc[0][mu_Ind[0]]/ df.dxyErr_mu1.iloc[0][mu_Ind[0]]))
    temp.append(abs(df.dxy_mu2.iloc[0][mu_Ind[1]]/ df.dxyErr_mu2.iloc[0][mu_Ind[1]]))
    temp.append(abs(df.dxy_mu3.iloc[0][mu_Ind[2]]/ df.dxyErr_mu3.iloc[0][mu_Ind[2]]))
    d0sig = 999
    d0sig_max = -999
    if debugMode: print("Ciao2")
    for k in range(2):
        if (df.Muon_combinedQuality_chi2LocalPosition.iloc[0][mu[k]] > cLP): cLP = df.Muon_combinedQuality_chi2LocalPosition.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_trkKink.iloc[0][mu[k]] > tKink): tKink = df.Muon_combinedQuality_trkKink.iloc[0][mu[k]]
        if (df.Muon_segmentCompatibility.iloc[0][mu[k]] < segmComp): segmComp = df.Muon_segmentCompatibility.iloc[0][mu[k]]
        if (temp1[k] < d0): d0 = temp1[k]
        if (temp[k] < d0sig): d0sig = temp[k]
        if (temp[k] > d0sig_max): d0sig_max = temp[k]
        if (dR[k] > DeltaR_max): DeltaR_max = dR[k]
        if (dZ[k] > DeltaZ_max): DeltaZ_max = dZ[k]

    if debugMode: print("Ciao3")

    if (isMC!=0): puFactor = df.nPileUpInt.iloc[0]
    else: 
        puFactor = df.pileupFactor.iloc[0]  
    tripletMass = df.Triplet2_Mass.iloc[0][ind]
    if (tripletMass>2.1 or tripletMass<1.62):
        print(f"ECCO IL BACO !!!!\nTripletMass: {tripletMass}\nrun = {run} lumi = {lumi} evt = {evt}")
    #tripletMassReso = ResoTriplMass(mu_Ind, mu)    
    #timeAtIpInOut_sig3 = Muon_timeAtIpInOut->at(mu[2])/ Muon_timeAtIpInOutErr->at(mu[2]);
    cQ_uS = 0
    cQ_tK = 0
    cQ_gK = 0
    cQ_tRChi2 = 0
    cQ_sRChi2 = 0
    cQ_Chi2LM = 0
    cQ_Chi2LP = 0
    cQ_lD = 0
    cQ_gDEP = 0
    cQ_tM = 0
    cQ_gTP = 0
    caloComp = 999
    for k in range(2):
        if (df.Muon_combinedQuality_updatedSta.iloc[0][mu[k]] > cQ_uS): cQ_uS = df.Muon_combinedQuality_updatedSta.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_trkKink.iloc[0][mu[k]] > cQ_tK): cQ_tK = df.Muon_combinedQuality_trkKink.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_glbKink.iloc[0][mu[k]] > cQ_gK): cQ_gK = df.Muon_combinedQuality_glbKink.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_trkRelChi2.iloc[0][mu[k]] > cQ_tRChi2): cQ_tRChi2 = df.Muon_combinedQuality_trkRelChi2.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_staRelChi2.iloc[0][mu[k]] > cQ_sRChi2): cQ_sRChi2 = df.Muon_combinedQuality_staRelChi2.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_chi2LocalPosition.iloc[0][mu[k]] > cQ_Chi2LP): cQ_Chi2LP = df.Muon_combinedQuality_chi2LocalPosition.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_chi2LocalMomentum.iloc[0][mu[k]] > cQ_Chi2LM): cQ_Chi2LM = df.Muon_combinedQuality_chi2LocalMomentum.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_localDistance.iloc[0][mu[k]] > cQ_lD): cQ_lD = df.Muon_combinedQuality_localDistance.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_globalDeltaEtaPhi.iloc[0][mu[k]] > cQ_gDEP): cQ_gDEP = df.Muon_combinedQuality_globalDeltaEtaPhi.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_tightMatch.iloc[0][mu[k]] > cQ_tM): cQ_tM = df.Muon_combinedQuality_tightMatch.iloc[0][mu[k]]
        if (df.Muon_combinedQuality_glbTrackProbability.iloc[0][mu[k]] > cQ_gTP): cQ_gTP = df.Muon_combinedQuality_glbTrackProbability.iloc[0][mu[k]]
        if (df.Muon_caloCompatibility.iloc[0][mu[k]] < caloComp): caloComp = df.Muon_caloCompatibility.iloc[0][mu[k]]
    #calEn_hadMu3 = Muon_calEnergy_had->at(mu[2]);
    #fliDistPVSV_Chi2 = FlightDistPVSV_chi2->at(ind);
    '''
    //isGlb3 = Muon_isGlobal->at(mu[2]);
    //isTracker3 = Muon_isTrackerMuon->at(mu[2]);
    //isLoose3 = Muon_isLoose->at(mu[2]);
    //isSoft3 = Muon_isSoft->at(mu[2]);
    //isPF3 = Muon_isPF->at(mu[2]);
    //isRPC3 = Muon_isRPCMuon->at(mu[2]);
    //isSA3 = Muon_isStandAloneMuon->at(mu[2]);
    //isCalo3 = Muon_isCaloMuon->at(mu[2]);
    '''
    #had03 = df.Muon_hadEt03->at(mu[2])
    #had05 = df.Muon_hadEt05->at(mu[2])
    #nJets03 = df.Muon_nJets03->at(mu[2])
    #nJets05 = df.Muon_nJets05->at(mu[2])
    #nTracks03 = df.Muon_nTracks03->at(mu[2])
    #nTracks05 = df.Muon_nTracks05->at(mu[2])
    #sumPt03 = df.Muon_sumPt03->at(mu[2])
    #sumPt05 = df.Muon_sumPt05->at(mu[2])
    #hadVeto03 = df.Muon_hadVetoEt03->at(mu[2])
    #hadVeto05 = df.Muon_hadVetoEt05->at(mu[2])
    #emVeto03 = df.Muon_emVetoEt03->at(mu[2])
    #emVeto05 = df.Muon_emVetoEt05->at(mu[2])
    #trVeto03 = df.Muon_trackerVetoPt03->at(mu[2])
    #trVeto05 = df.Muon_trackerVetoPt05->at(mu[2])
    #
    #
    # mu1
    # mu3
    '''
    isQValid3 = df.Muon_isQualityValid.iloc[0][mu[2]]
    isTValid3 = df.Muon_isTimeValid.iloc[0][mu[2]]
    isIsoValid3 = df.Muon_isIsolationValid.iloc[0][mu[2]]
    GLnormChi2_mu3 = df.Muon_GLnormChi2.iloc[0][mu[2]]
    GL_nValidMuHits3 = df.Muon_GLhitPattern_numberOfValidMuonHits.iloc[0][mu[2]]
    trkLayersWMeas3 = df.Muon_trackerLayersWithMeasurement.iloc[0][mu[2]]
    nValidPixelHits3 = df.Muon_Numberofvalidpixelhits.iloc[0][mu[2]]
    outerTrk_P_3 = df.Muon_outerTrack_p.iloc[0][mu[2]]
    outerTrk_Eta_3 = df.Muon_outerTrack_eta.iloc[0][mu[2]]
    outerTrk_normChi2_3 = df.Muon_outerTrack_normalizedChi2.iloc[0][mu[2]]
    outerTrk_muStValidHits_3 = df.Muon_outerTrack_muonStationsWithValidHits.iloc[0][mu[2]]
    innerTrk_P_3 = df.Muon_innerTrack_p.iloc[0][mu[2]]
    innerTrk_Eta_3 = df.Muon_innerTrack_eta.iloc[0][mu[2]]
    innerTrk_normChi2_3 = df.Muon_innerTrack_normalizedChi2.iloc[0][mu[2]]
    QInnerOuter_3 = df.Muon_QInnerOuter.iloc[0][mu[2]]
    cQ_uS_3 = df.Muon_combinedQuality_updatedSta.iloc[0][mu[2]]
    cQ_tK_3 = df.Muon_combinedQuality_trkKink.iloc[0][mu[2]]
    cQ_gK_3 = df.Muon_combinedQuality_glbKink.iloc[0][mu[2]]
    cQ_tRChi2_3 = df.Muon_combinedQuality_trkRelChi2.iloc[0][mu[2]]
    cQ_sRChi2_3 = df.Muon_combinedQuality_staRelChi2.iloc[0][mu[2]]
    cQ_Chi2LP_3 = df.Muon_combinedQuality_chi2LocalPosition.iloc[0][mu[2]]
    cQ_Chi2LM_3 = df.Muon_combinedQuality_chi2LocalMomentum.iloc[0][mu[2]]
    cQ_lD_3 = df.Muon_combinedQuality_localDistance.iloc[0][mu[2]]
    cQ_gDEP_3 = df.Muon_combinedQuality_globalDeltaEtaPhi.iloc[0][mu[2]]
    cQ_tM_3 = df.Muon_combinedQuality_tightMatch.iloc[0][mu[2]]
    cQ_gTP_3 = df.Muon_combinedQuality_glbTrackProbability.iloc[0][mu[2]]
    segmComp_3 = df.Muon_segmentCompatibility.iloc[0][mu[2]]
    caloComp_3 = df.Muon_caloCompatibility.iloc[0][mu[2]]
    '''    
    start = time.time()
    if(debugMode): print("Ciao13")
    #df_fin["isMC"].append(isMC)
    #print(df_fin)
    #print("success!")
    df_fin["isMC"][jentry] = ((isMC))
    df_fin["lumi"][jentry] = ((lumi))
    df_fin["run"][jentry] = ((run))
    df_fin["evt"][jentry] = ((evt))
    df_fin["puFactor"][jentry] = ((puFactor))
    df_fin["L1_DoubleMu0_er1p5"][jentry] = ((L1_DoubleMu0_er1p5))
    df_fin["L1_DoubleMu0_er1p4"][jentry] = ((L1_DoubleMu0_er1p4))
    df_fin["L1_DoubleMu4_dR1p2"][jentry] = ((L1_DoubleMu4_dR1p2))
    df_fin["L1_DoubleMu4p5_dR1p2"][jentry] = ((L1_DoubleMu4p5_dR1p2))
    df_fin["L1_DoubleMu0_er2p0"][jentry] = ((L1_DoubleMu0_er2p0))
    df_fin["L1_DoubleMu0_er2p0_bk"][jentry] = ((L1_DoubleMu0_er2p0_bk))
    df_fin["L1seed"][jentry] = ((L1seed))
    df_fin["HLTpath"][jentry] = ((HLTpath))
    df_fin["DeltaR_max"][jentry] = ((DeltaR_max))
    df_fin["DeltaZ_max"][jentry] = ((DeltaZ_max))
    df_fin["Pmu3"][jentry] = (MuonP(df, pt[2], eta[2], phi[2]))
    df_fin["cLP"][jentry] = ((cLP))
    df_fin["tKink"][jentry] = ((tKink))
    df_fin["segmComp"][jentry] = ((segmComp))
    df_fin["tripletMass"][jentry] = ((tripletMass))
    ####df_fin["tripletMassReso"][jentry] = ((tripletMassReso))
    df_fin["fv_nC"][jentry] = (df.TripletVtx2_Chi2.iloc[0][ind]/3)
    df_fin["fv_dphi3D"][jentry] = (TreeFin_Angle(df, ind))
    df_fin["fv_d3D"][jentry] = (df.FlightDistPVSV2.iloc[0][ind])
    df_fin["fv_d3Dsig"][jentry] = (df.FlightDistPVSV2_Significance.iloc[0][ind])
    df_fin["d0"][jentry] = ((d0))
    df_fin["nVtx"][jentry] = (df.PVCollection_Size.iloc[0])
    df_fin["d0sig"][jentry] = ((d0sig))
    df_fin["MVA1"][jentry] = ( df.Muon_MVA.iloc[0][mu[0]])
    df_fin["MVA2"][jentry] = ( df.Muon_MVA.iloc[0][mu[1]])
    df_fin["MVA3"][jentry] = (0.)
    df_fin["MVASoft1"][jentry] = ( df.Muon_SoftMVA_Val.iloc[0][mu[0]])
    df_fin["MVASoft2"][jentry] = (df.Muon_SoftMVA_Val.iloc[0][mu[1]])
    df_fin["MVASoft3"][jentry] = (0.)
    df_fin["d0sig_max"][jentry] = ((d0sig_max))
    df_fin["mindca_iso"][jentry] = (df.Triplet_mindca_iso.iloc[0][ind])
    df_fin["trkRel"][jentry] = (df.Triplet_relativeiso.iloc[0][ind])
    df_fin["Pmu1"][jentry] = (MuonP(df, df.Mu01_Pt.iloc[0][mu_Ind[0]], df.Mu01_Eta.iloc[0][mu_Ind[0]], df.Mu01_Phi.iloc[0][mu_Ind[0]]))
    df_fin["Ptmu1"][jentry] = (df.Mu01_Pt.iloc[0][mu_Ind[0]])
    df_fin["Etamu1"][jentry] = (df.Mu01_Eta.iloc[0][mu_Ind[0]])
    df_fin["Phimu1"][jentry] = (df.Mu01_Phi.iloc[0][mu_Ind[0]])
    df_fin["Pmu2"][jentry] = (MuonP(df, df.Mu02_Pt.iloc[0][mu_Ind[1]], df.Mu02_Eta.iloc[0][mu_Ind[1]], df.Mu02_Phi.iloc[0][mu_Ind[1]]))
    df_fin["Ptmu2"][jentry] = (df.Mu02_Pt.iloc[0][mu_Ind[1]])
    df_fin["Etamu2"][jentry] = (df.Mu02_Eta.iloc[0][mu_Ind[1]])
    df_fin["Phimu2"][jentry] = (df.Mu02_Phi.iloc[0][mu_Ind[1]])
    df_fin["Ptmu3"][jentry] = (df.Tr_Pt.iloc[0][mu_Ind[2]])
    df_fin["Etamu3"][jentry] = (df.Tr_Eta.iloc[0][mu_Ind[2]])
    df_fin["Phimu3"][jentry] = (df.Tr_Phi.iloc[0][(mu_Ind[2])])
    df_fin["dispMu1"][jentry] = (math.sqrt(pow(df.BS_x.iloc[0][mu_Ind[0]] - df.Muon_vx.iloc[0][mu[0]],2) + pow(df.BS_y.iloc[0][mu_Ind[0]] - df.Muon_vy.iloc[0][mu[0]],2) + pow(df.BS_z.iloc[0][mu_Ind[0]] - df.Muon_vz.iloc[0][mu[0]],2)))
    df_fin["dispMu2"][jentry] = (math.sqrt(pow(df.BS_x.iloc[0][mu_Ind[1]] - df.Muon_vx.iloc[0][mu[1]],2) + pow(df.BS_y.iloc[0][mu_Ind[1]] - df.Muon_vy.iloc[0][mu[1]],2) + pow(df.BS_z.iloc[0][mu_Ind[1]] - df.Muon_vz.iloc[0][mu[1]],2)))
    ####df_fin["dispMu3"][jentry] = ((dispMu3))
    df_fin["xydispMu1"][jentry] = (math.sqrt(pow(df.BS_x.iloc[0][mu_Ind[0]] - df.Muon_vx.iloc[0][mu[0]],2) + pow(df.BS_y.iloc[0][mu_Ind[0]] - df.Muon_vy.iloc[0][mu[0]],2)))
    df_fin["xydispMu2"][jentry] = (math.sqrt(pow(df.BS_x.iloc[0][mu_Ind[1]] - df.Muon_vx.iloc[0][mu[1]],2) + pow(df.BS_y.iloc[0][mu_Ind[1]] - df.Muon_vy.iloc[0][mu[1]],2)))
    ####df_fin["xydispMu3"][jentry] = ((xydispMu3))
    df_fin["P_tripl"][jentry] = (MuonP(df, df.Triplet2_Pt.iloc[0][ind], df.Triplet2_Eta.iloc[0][ind], df.Triplet2_Phi.iloc[0][ind]))
    df_fin["Pt_tripl"][jentry] = (df.Triplet2_Pt.iloc[0][ind])
    df_fin["Eta_tripl"][jentry] = (df.Triplet2_Eta.iloc[0][ind])
    df_fin["nStMu1"][jentry] = (df.Muon_numberOfMatchedStations.iloc[0][mu[0]])
    df_fin["nStMu2"][jentry] = (df.Muon_numberOfMatchedStations.iloc[0][mu[1]])
    ####df_fin["nStMu3"][jentry] = ((nStationsMu3))
    df_fin["Iso03Mu1"][jentry] = (df.Mu1_NTracks03iso.iloc[0][mu_Ind[0]])
    df_fin["Iso03Mu2"][jentry] = (df.Mu2_NTracks03iso.iloc[0][mu_Ind[1]])
    df_fin["Iso03Mu3"][jentry] = (df.Tr_NTracks03iso.iloc[0][mu_Ind[2]])
    df_fin["Iso05Mu1"][jentry] = (df.Muon_emEt05.iloc[0][mu[0]])
    df_fin["Iso05Mu2"][jentry] = (df.Muon_emEt05.iloc[0][mu[1]])
    ####df_fin["Iso05Mu3"][jentry] = ((Iso05Mu3))
    df_fin["nMatchesMu1"][jentry] = (df.Muon_numberOfMatches.iloc[0][mu[0]])
    df_fin["nMatchesMu2"][jentry] = (df.Muon_numberOfMatches.iloc[0][mu[1]])
    ####df_fin["nMatchesMu3"][jentry] = ((nMatchesMu3))
    df_fin["timeAtIpInOut_sig1"][jentry] = (df.Muon_timeAtIpInOut.iloc[0][mu[0]]/ df.Muon_timeAtIpInOutErr.iloc[0][mu[0]])
    df_fin["timeAtIpInOut_sig2"][jentry] = (df.Muon_timeAtIpInOut.iloc[0][mu[1]]/ df.Muon_timeAtIpInOutErr.iloc[0][mu[1]])
    ####df_fin["timeAtIpInOut_sig3"][jentry] = ((timeAtIpInOut_sig3))
    df_fin["cQ_uS"][jentry] = ((cQ_uS))
    df_fin["cQ_tK"][jentry] = ((cQ_tK))
    df_fin["cQ_gK"][jentry] = ((cQ_gK))
    df_fin["cQ_tRChi2"][jentry] = ((cQ_tRChi2))
    df_fin["cQ_sRChi2"][jentry] = ((cQ_sRChi2))
    df_fin["cQ_Chi2LP"][jentry] = ((cQ_Chi2LP))
    df_fin["cQ_Chi2LM"][jentry] = ((cQ_Chi2LM))
    df_fin["cQ_lD"][jentry] = ((cQ_lD))
    df_fin["cQ_gDEP"][jentry] = ((cQ_gDEP))
    df_fin["cQ_tM"][jentry] = ((cQ_tM))
    df_fin["cQ_gTP"][jentry] = ((cQ_gTP))
    df_fin["calEn_emMu1"][jentry] = (df.Muon_calEnergy_em.iloc[0][mu[0]])
    df_fin["calEn_emMu2"][jentry] = (df.Muon_calEnergy_em.iloc[0][mu[1]])
    ####df_fin["calEn_emMu3"][jentry] = ((calEn_emMu3))
    df_fin["calEn_hadMu1"][jentry] = (df.Muon_calEnergy_had.iloc[0][mu[0]])
    df_fin["calEn_hadMu2"][jentry] = (df.Muon_calEnergy_had.iloc[0][mu[1]])
    ####df_fin["calEn_hadMu3"][jentry] = ((calEn_hadMu3))
    df_fin["caloComp"][jentry] = ((caloComp))
    ####df_fin["fliDistPVSV_Chi2"][jentry] = ((fliDistPVSV_Chi2))
    df_fin["isGlb1"][jentry] = (df.Muon_isGlobal.iloc[0][mu[0]])
    df_fin["isMedium1"][jentry] = (df.Muon_isMedium.iloc[0][mu[0]])
    df_fin["isTracker1"][jentry] = (df.Muon_isTrackerMuon.iloc[0][mu[0]])
    df_fin["isLoose1"][jentry] = (df.Muon_isLoose.iloc[0][mu[0]])
    df_fin["isSoft1"][jentry] = (df.Muon_isSoft.iloc[0][mu[0]])
    df_fin["isPF1"][jentry] = ( df.Muon_isPF.iloc[0][mu[0]])
    df_fin["isRPC1"][jentry] = (df.Muon_isRPCMuon.iloc[0][mu[0]])
    df_fin["isSA1"][jentry] = (df.Muon_isStandAloneMuon.iloc[0][mu[0]])
    df_fin["isCalo1"][jentry] = (df.Muon_isCaloMuon.iloc[0][mu[0]])
    df_fin["isGlb2"][jentry] = (df.Muon_isGlobal.iloc[0][mu[1]])
    df_fin["isMedium2"][jentry] = (df.Muon_isMedium.iloc[0][mu[1]])
    df_fin["isTracker2"][jentry] = (df.Muon_isTrackerMuon.iloc[0][mu[1]])
    df_fin["isLoose2"][jentry] = (df.Muon_isLoose.iloc[0][mu[1]])
    df_fin["isSoft2"][jentry] = (df.Muon_isSoft.iloc[0][mu[1]])
    df_fin["isPF2"][jentry] = (df.Muon_isPF.iloc[0][mu[1]])
    df_fin["isRPC2"][jentry] = (df.Muon_isRPCMuon.iloc[0][mu[1]])
    df_fin["isSA2"][jentry] = (df.Muon_isStandAloneMuon.iloc[0][mu[1]])
    df_fin["isCalo2"][jentry] = (df.Muon_isCaloMuon.iloc[0][mu[1]])
    ''')
    df_fin["isGlb3"][jentry] = ((isGlb3))
    df_fin["isTracker3"][jentry] = ((isTracker3))
    df_fin["isLoose3"][jentry] = ((isLoose3))
    df_fin["isSoft3"][jentry] = ((isSoft3))
    df_fin["isPF3"][jentry] = ((isPF3))
    df_fin["isRPC3"][jentry] = ((isRPC3))
    df_fin["isSA3"][jentry] = ((isSA3))
    df_fin["isCalo3"][jentry] = ((isCalo3))
    '''
    df_fin["Vx1"][jentry] = (df.Muon_vx.iloc[0][mu[0]])
    df_fin["Vx2"][jentry] = (df.Muon_vx.iloc[0][mu[1]])
    df_fin["Vx3"][jentry] = (df.Track_vx.iloc[0][mu[2]])
    df_fin["Vy1"][jentry] = (df.Muon_vy.iloc[0][mu[0]])
    df_fin["Vy2"][jentry] = (df.Muon_vy.iloc[0][mu[1]])
    df_fin["Vy3"][jentry] = (df.Track_vy.iloc[0][mu[2]])
    df_fin["Vz1"][jentry] = (df.Muon_vz.iloc[0][mu[0]])
    df_fin["Vz2"][jentry] = (df.Muon_vz.iloc[0][mu[1]])
    df_fin["Vz3"][jentry] = (df.Track_vz.iloc[0][mu[2]])
    df_fin["RefVx1"][jentry] = (df.RefittedPV2_x.iloc[0][ind])
    ####df_fin["RefVx2"][jentry] = ((RefVx2))
    ####df_fin["RefVx3"][jentry] = ((RefVx3))
    df_fin["RefVy1"][jentry] = (df.RefittedPV2_y.iloc[0][ind])
    ####df_fin["RefVy2"][jentry] = ((RefVy2))
    ####df_fin["RefVy3"][jentry] = ((RefVy3))
    df_fin["RefVz1"][jentry] = (df.RefittedPV2_z.iloc[0][ind])
    ####df_fin["RefVz2"][jentry] = ((RefVz2))
    ####df_fin["RefVz3"][jentry] = ((RefVz3))
    df_fin["SVx"][jentry] = (df.TripletVtx2_x.iloc[0][ind])
    df_fin["SVy"][jentry] = (df.TripletVtx2_y.iloc[0][ind])
    df_fin["SVz"][jentry] = (df.TripletVtx2_z.iloc[0][ind])
    ''')
    df_fin["had03"][jentry] = ((had03))
    df_fin["had05"][jentry] = ((had05))
    df_fin["nJets03"][jentry] = ((nJets03))
    df_fin["nJets05"][jentry] = ((nJets05))
    df_fin["nTracks03"][jentry] = ((nTracks03))
    df_fin["nTracks05"][jentry] = ((nTracks05))
    df_fin["sumPt03"][jentry] = ((sumPt03))
    df_fin["sumPt05"][jentry] = ((sumPt05))
    df_fin["hadVeto03"][jentry] = ((hadVeto03))
    df_fin["hadVeto05"][jentry] = ((hadVeto05))
    df_fin["emVeto03"][jentry] = ((emVeto03))
    df_fin["emVeto05"][jentry] = ((emVeto05))
    df_fin["trVeto03"][jentry] = ((trVeto03))
    df_fin["trVeto05"][jentry] = ((trVeto05))
    '''
    #)new)branches))
    df_fin["EnMu1"][jentry] = (df.MuonEnergy.iloc[0][mu[0]])
    df_fin["EnMu2"][jentry] = (df.MuonEnergy.iloc[0][mu[1]])
    #####df_fin["EnMu3"][jentry] = ((EnMu3))
    df_fin["ChargeMu1"][jentry] = (df.MuonCharge.iloc[0][mu[0]])
    df_fin["ChargeMu2"][jentry] = (df.MuonCharge.iloc[0][mu[1]])
    df_fin["ChargeMu3"][jentry] = (df.Track_charge.iloc[0][mu[2]])
    #)Mu1))
    df_fin["isQValid1"][jentry] = (df.Muon_isQualityValid.iloc[0][mu[0]])
    df_fin["isTValid1"][jentry] = (df.Muon_isTimeValid.iloc[0][mu[0]])
    df_fin["isIsoValid1"][jentry] = (df.Muon_isIsolationValid.iloc[0][mu[0]])
    df_fin["GLnormChi2_mu1"][jentry] = (df.Muon_GLnormChi2.iloc[0][mu[0]])
    df_fin["GL_nValidMuHits1"][jentry] = (df.Muon_GLhitPattern_numberOfValidMuonHits.iloc[0][mu[0]])
    df_fin["trkLayersWMeas1"][jentry] = (df.Muon_trackerLayersWithMeasurement.iloc[0][mu[0]])
    df_fin["validMuonHitComb1"][jentry] = (df.Muon_validMuonHitComb.iloc[0][mu[0]])
    df_fin["nValidTrackerHits1"][jentry] = (df.Muon_Numberofvalidtrackerhits.iloc[0][mu[0]])
    df_fin["nValidPixelHits1"][jentry] = (df.Muon_Numberofvalidpixelhits.iloc[0][mu[0]])
    df_fin["outerTrk_P_1"][jentry] = (df.Muon_outerTrack_p.iloc[0][mu[0]])
    df_fin["outerTrk_Eta_1"][jentry] = (df.Muon_outerTrack_eta.iloc[0][mu[0]])
    df_fin["outerTrk_normChi2_1"][jentry] = (df.Muon_outerTrack_normalizedChi2.iloc[0][mu[0]])
    df_fin["outerTrk_muStValidHits_1"][jentry] = (df.Muon_outerTrack_muonStationsWithValidHits.iloc[0][mu[0]])
    df_fin["innerTrk_P_1"][jentry] = (df.Muon_innerTrack_p.iloc[0][mu[0]])
    df_fin["innerTrk_Eta_1"][jentry] = (df.Muon_innerTrack_eta.iloc[0][mu[0]])
    df_fin["innerTrk_normChi2_1"][jentry] = (df.Muon_innerTrack_normalizedChi2.iloc[0][mu[0]])
    df_fin['innerTrk_highPurity_1'][jentry] = (df.Muon_innerTrack_highPurity.iloc[0][mu[0]])
    df_fin['innerTrk_ValidFraction_1'][jentry] = (df.Muon_innerTrack_ValidFraction.iloc[0][mu[0]])
    df_fin['QInnerOuter_1'][jentry] = (df.Muon_QInnerOuter.iloc[0][mu[0]])
    df_fin['cQ_uS_1'][jentry] = (df.Muon_combinedQuality_updatedSta.iloc[0][mu[0]])
    df_fin['cQ_tK_1'][jentry] = (df.Muon_combinedQuality_trkKink.iloc[0][mu[0]])
    df_fin['cQ_gK_1'][jentry] = (df.Muon_combinedQuality_glbKink.iloc[0][mu[0]])
    df_fin['cQ_tRChi2_1'][jentry] = (df.Muon_combinedQuality_trkRelChi2.iloc[0][mu[0]])
    df_fin['cQ_sRChi2_1'][jentry] = (df.Muon_combinedQuality_staRelChi2.iloc[0][mu[0]])
    df_fin['cQ_Chi2LP_1'][jentry] = (df.Muon_combinedQuality_chi2LocalPosition.iloc[0][mu[0]])
    df_fin['cQ_Chi2LM_1'][jentry] = (df.Muon_combinedQuality_chi2LocalMomentum.iloc[0][mu[0]])
    df_fin['cQ_lD_1'][jentry] = (df.Muon_combinedQuality_localDistance.iloc[0][mu[0]])
    df_fin['cQ_gDEP_1'][jentry] = (df.Muon_combinedQuality_globalDeltaEtaPhi.iloc[0][mu[0]])
    df_fin['cQ_tM_1'][jentry] = (df.Muon_combinedQuality_tightMatch.iloc[0][mu[0]])
    df_fin['cQ_gTP_1'][jentry] = (df.Muon_combinedQuality_glbTrackProbability.iloc[0][mu[0]])
    df_fin['segmComp_1'][jentry] = (df.Muon_segmentCompatibility.iloc[0][mu[0]])
    df_fin['caloComp_1'][jentry] = (df.Muon_caloCompatibility.iloc[0][mu[0]])
    df_fin['match1_dX_1'][jentry] = (df.Muon_combinedQuality_match1_dX.iloc[0][mu[0]])
    df_fin['match1_pullX_1'][jentry] = (df.Muon_combinedQuality_match1_pullX.iloc[0][mu[0]])
    df_fin['match1_pullDxDz_1'][jentry] = (df.Muon_combinedQuality_match1_pullDxDz.iloc[0][mu[0]])
    df_fin['match1_dY_1'][jentry] = (df.Muon_combinedQuality_match1_dY.iloc[0][mu[0]])
    df_fin['match1_pullY_1'][jentry] = (df.Muon_combinedQuality_match1_pullY.iloc[0][mu[0]])
    df_fin['match1_pullDyDz_1'][jentry] = (df.Muon_combinedQuality_match1_pullDyDz.iloc[0][mu[0]])
    df_fin['match2_dX_1'][jentry] = (df.Muon_combinedQuality_match2_dX.iloc[0][mu[0]])
    df_fin['match2_pullX_1'][jentry] = (df.Muon_combinedQuality_match2_pullX.iloc[0][mu[0]])
    df_fin['match2_pullDxDz_1'][jentry] = (df.Muon_combinedQuality_match2_pullDxDz.iloc[0][mu[0]])
    df_fin['match2_dY_1'][jentry] = (df.Muon_combinedQuality_match2_dY.iloc[0][mu[0]])
    df_fin['match2_pullY_1'][jentry] = (df.Muon_combinedQuality_match2_pullY.iloc[0][mu[0]])
    df_fin['match2_pullDyDz_1'][jentry] = (df.Muon_combinedQuality_match2_pullDyDz.iloc[0][mu[0]])
    df_fin['isQValid2'][jentry] = (df.Muon_isQualityValid.iloc[0][mu[1]])
    df_fin['isTValid2'][jentry] = (df.Muon_isTimeValid.iloc[0][mu[1]])
    df_fin['isIsoValid2'][jentry] = (df.Muon_isIsolationValid.iloc[0][mu[1]])
    df_fin['GLnormChi2_mu2'][jentry] = (df.Muon_GLnormChi2.iloc[0][mu[1]])
    df_fin['GL_nValidMuHits2'][jentry] = (df.Muon_GLhitPattern_numberOfValidMuonHits.iloc[0][mu[1]])
    df_fin['trkLayersWMeas2'][jentry] = (df.Muon_trackerLayersWithMeasurement.iloc[0][mu[1]])
    df_fin['validMuonHitComb2'][jentry] = (df.Muon_validMuonHitComb.iloc[0][mu[1]])
    df_fin['nValidTrackerHits2'][jentry] = (df.Muon_Numberofvalidtrackerhits.iloc[0][mu[1]])
    df_fin['nValidPixelHits2'][jentry] = (df.Muon_Numberofvalidpixelhits.iloc[0][mu[1]])
    df_fin['outerTrk_P_2'][jentry] = (df.Muon_outerTrack_p.iloc[0][mu[1]])
    df_fin['outerTrk_Eta_2'][jentry] = (df.Muon_outerTrack_eta.iloc[0][mu[1]])
    df_fin['outerTrk_normChi2_2'][jentry] = (df.Muon_outerTrack_normalizedChi2.iloc[0][mu[1]])
    df_fin['outerTrk_muStValidHits_2'][jentry] = (df.Muon_outerTrack_muonStationsWithValidHits.iloc[0][mu[1]])
    df_fin['innerTrk_P_2'][jentry] = (df.Muon_innerTrack_p.iloc[0][mu[1]])
    df_fin['innerTrk_Eta_2'][jentry] = (df.Muon_innerTrack_eta.iloc[0][mu[1]])
    df_fin['innerTrk_normChi2_2'][jentry] = (df.Muon_innerTrack_normalizedChi2.iloc[0][mu[1]])
    df_fin['innerTrk_highPurity_2'][jentry] = (df.Muon_innerTrack_highPurity.iloc[0][mu[1]])
    df_fin['innerTrk_ValidFraction_2'][jentry] = (df.Muon_innerTrack_ValidFraction.iloc[0][mu[1]])
    df_fin['QInnerOuter_2'][jentry] = (df.Muon_QInnerOuter.iloc[0][mu[1]])
    df_fin['cQ_uS_2'][jentry] = (df.Muon_combinedQuality_updatedSta.iloc[0][mu[1]])
    df_fin['cQ_tK_2'][jentry] = (df.Muon_combinedQuality_trkKink.iloc[0][mu[1]])
    df_fin['cQ_gK_2'][jentry] = (df.Muon_combinedQuality_glbKink.iloc[0][mu[1]])
    df_fin['cQ_tRChi2_2'][jentry] = (df.Muon_combinedQuality_trkRelChi2.iloc[0][mu[1]])
    df_fin['cQ_sRChi2_2'][jentry] = (df.Muon_combinedQuality_staRelChi2.iloc[0][mu[1]])
    df_fin['cQ_Chi2LP_2'][jentry] = (df.Muon_combinedQuality_chi2LocalPosition.iloc[0][mu[1]])
    df_fin['cQ_Chi2LM_2'][jentry] = (df.Muon_combinedQuality_chi2LocalMomentum.iloc[0][mu[1]])
    df_fin['cQ_lD_2'][jentry] = (df.Muon_combinedQuality_localDistance.iloc[0][mu[1]])
    df_fin['cQ_gDEP_2'][jentry] = (df.Muon_combinedQuality_globalDeltaEtaPhi.iloc[0][mu[1]])
    df_fin['cQ_tM_2'][jentry] = (df.Muon_combinedQuality_tightMatch.iloc[0][mu[1]])
    df_fin['cQ_gTP_2'][jentry] = (df.Muon_combinedQuality_glbTrackProbability.iloc[0][mu[1]])
    df_fin['segmComp_2'][jentry] = (df.Muon_segmentCompatibility.iloc[0][mu[1]])
    df_fin['caloComp_2'][jentry] = (df.Muon_caloCompatibility.iloc[0][mu[1]])
    df_fin['match1_dX_2'][jentry] = (df.Muon_combinedQuality_match1_dX.iloc[0][mu[1]])
    df_fin['match1_pullX_2'][jentry] = (df.Muon_combinedQuality_match1_pullX.iloc[0][mu[1]])
    df_fin['match1_pullDxDz_2'][jentry] = (df.Muon_combinedQuality_match1_pullDxDz.iloc[0][mu[1]])
    df_fin['match1_dY_2'][jentry] = (df.Muon_combinedQuality_match1_dY.iloc[0][mu[1]])
    df_fin['match1_pullY_2'][jentry] = (df.Muon_combinedQuality_match1_pullY.iloc[0][mu[1]])
    df_fin['match1_pullDyDz_2'][jentry] = (df.Muon_combinedQuality_match1_pullDyDz.iloc[0][mu[1]])
    df_fin['match2_dX_2'][jentry] = (df.Muon_combinedQuality_match2_dX.iloc[0][mu[1]])
    df_fin['match2_pullX_2'][jentry] = (df.Muon_combinedQuality_match2_pullX.iloc[0][mu[1]])
    df_fin['match2_pullDxDz_2'][jentry] = (df.Muon_combinedQuality_match2_pullDxDz.iloc[0][mu[1]])
    df_fin['match2_dY_2'][jentry] = (df.Muon_combinedQuality_match2_dY.iloc[0][mu[1]])
    df_fin['match2_pullY_2'][jentry] = (df.Muon_combinedQuality_match2_pullY.iloc[0][mu[1]])
    df_fin['match2_pullDyDz_2'][jentry] = (df.Muon_combinedQuality_match2_pullDyDz.iloc[0][mu[1]])
    #)Mu3))
    ''')
    df_fin["isQValid3"][jentry] = ((isQValid3))
    df_fin["isTValid3"][jentry] = ((isTValid3))
    df_fin["isIsoValid3"][jentry] = ((isIsoValid3))
    df_fin["GLnormChi2_mu3"][jentry] = ((GLnormChi2_mu3))
    df_fin["GL_nValidMuHits3"][jentry] = ((GL_nValidMuHits3))
    df_fin["trkLayersWMeas3"][jentry] = ((trkLayersWMeas3))
    df_fin["validMuonHitComb3"][jentry] = ((validMuonHitComb3))
    df_fin["nValidTrackerHits3"][jentry] = ((nValidTrackerHits3))
    df_fin["nValidPixelHits3"][jentry] = ((nValidPixelHits3))
    df_fin["outerTrk_P_3"][jentry] = ((outerTrk_P_3))
    df_fin["outerTrk_Eta_3"][jentry] = ((outerTrk_Eta_3))
    df_fin["outerTrk_normChi2_3"][jentry] = ((outerTrk_normChi2_3))
    df_fin["outerTrk_muStValidHits_3"][jentry] = ((outerTrk_muStValidHits_3))
    df_fin["innerTrk_P_3"][jentry] = ((innerTrk_P_3))
    df_fin["innerTrk_Eta_3"][jentry] = ((innerTrk_Eta_3))
    df_fin["innerTrk_normChi2_3"][jentry] = ((innerTrk_normChi2_3))
    df_fin["innerTrk_highPurity_3"][jentry] = ((innerTrk_highPurity_3))
    df_fin["innerTrk_ValidFraction_3"][jentry] = ((innerTrk_ValidFraction_3))
    df_fin["QInnerOuter_3"][jentry] = ((QInnerOuter_3))
    df_fin["cQ_uS_3"][jentry] = ((cQ_uS_3))
    df_fin["cQ_tK_3"][jentry] = ((cQ_tK_3))
    df_fin["cQ_gK_3"][jentry] = ((cQ_gK_3))
    df_fin["cQ_tRChi2_3"][jentry] = ((cQ_tRChi2_3))
    df_fin["cQ_sRChi2_3"][jentry] = ((cQ_sRChi2_3))
    df_fin["cQ_Chi2LP_3"][jentry] = ((cQ_Chi2LP_3))
    df_fin["cQ_Chi2LM_3"][jentry] = ((cQ_Chi2LM_3))
    df_fin["cQ_lD_3"][jentry] = ((cQ_lD_3))
    df_fin["cQ_gDEP_3"][jentry] = ((cQ_gDEP_3))
    df_fin["cQ_tM_3"][jentry] = ((cQ_tM_3))
    df_fin["cQ_gTP_3"][jentry] = ((cQ_gTP_3))
    df_fin["segmComp_3"][jentry] = ((segmComp_3))
    df_fin["caloComp_3"][jentry] = ((caloComp_3))
    df_fin["match1_dX_3"][jentry] = ((match1_dX_3))
    df_fin["match1_pullX_3"][jentry] = ((match1_pullX_3))
    df_fin["match1_pullDxDz_3"][jentry] = ((match1_pullDxDz_3))
    df_fin["match1_dY_3"][jentry] = ((match1_dY_3))
    df_fin["match1_pullY_3"][jentry] = ((match1_pullY_3))
    df_fin["match1_pullDyDz_3"][jentry] = ((match1_pullDyDz_3))
    df_fin["match2_dX_3"][jentry] = ((match2_dX_3))
    df_fin["match2_pullX_3"][jentry] = ((match2_pullX_3))
    df_fin["match2_pullDxDz_3"][jentry] = ((match2_pullDxDz_3))
    df_fin["match2_dY_3"][jentry] = ((match2_dY_3))
    df_fin["match2_pullY_3"][jentry] = ((match2_pullY_3))
    df_fin["match2_pullDyDz_3"][jentry] = ((match2_pullDyDz_3))
    '''
    stop = time.time()
    dtime = stop - start
    print(f"Time: {dtime}")

#@dask.delayed
def twoMuonsFinder(dataframe):
    ####check over muon 1
    muon_pt = dataframe.MuonPt
    mu01_pt = dataframe.Mu01_Pt
    mu02_pt = dataframe.Mu02_Pt
    muon_eta = dataframe.MuonEta
    mu01_eta = dataframe.Mu01_Eta
    mu02_eta = dataframe.Mu02_Eta
    muon_phi = dataframe.MuonPhi
    mu01_phi = dataframe.Mu01_Phi
    mu02_phi = dataframe.Mu02_Phi
    #print(muon_pt)
    index_muon = dak.local_index(muon_pt, axis = 1)
    #print(index_muon)
    index_mu01 = dak.local_index(mu01_pt, axis = 1)
    index_mu02 = dak.local_index(mu02_pt, axis = 1)
    pairs_tri_index_1, pairs_index_1= dak.unzip(dak.cartesian([index_mu01, index_muon]))
    pairs_tri_index_2, pairs_index_2 = dak.unzip(dak.cartesian([index_mu02, index_muon]))
    pairs_pt_1 = dak.cartesian([mu01_pt, muon_pt])
    pairs_eta_1 = dak.cartesian([mu01_eta, muon_eta])
    pairs_phi_1 = dak.cartesian([mu01_phi, muon_phi])
    pairs_pt_2 = dak.cartesian([mu02_pt, muon_pt])
    pairs_eta_2 = dak.cartesian([mu02_eta, muon_eta])
    pairs_phi_2 = dak.cartesian([mu02_phi, muon_phi])
    ratio_pt_1 = pairs_pt_1["0"]==pairs_pt_1["1"]
    ratio_phi_1 = pairs_phi_1["0"]==pairs_phi_1["1"]
    ratio_eta_1 = pairs_eta_1["0"]==pairs_eta_1["1"]
    ratio_pt_2 = pairs_pt_2["0"]==pairs_pt_2["1"]
    ratio_phi_2 = pairs_phi_2["0"]==pairs_phi_2["1"]
    ratio_eta_2 = pairs_eta_2["0"]==pairs_eta_2["1"]
    selection_mu1 = (ratio_pt_1) & (ratio_eta_1) & (ratio_phi_1)
    selection_mu2 = (ratio_pt_2) & (ratio_eta_2) & (ratio_phi_2)
    pairs_mu01_index = pairs_index_1[selection_mu1]
    pairs_tri_mu01_index = pairs_tri_index_1[selection_mu1]
    pairs_mu02_index = pairs_index_2[selection_mu2]
    pairs_tri_mu02_index = pairs_tri_index_2[selection_mu2]
    return pairs_mu01_index, pairs_tri_mu01_index, pairs_mu02_index, pairs_tri_mu02_index

#@dask.delayed
def trackFinder(dataframe):
    track_pt = dataframe.Track_pt
    trk_trip_pt = dataframe.Tr_Pt
    track_eta = dataframe.Track_eta
    trk_trip_eta = dataframe.Tr_Eta
    track_phi = dataframe.Track_phi
    trk_trip_phi = dataframe.Tr_Phi
    index_track = dak.local_index(track_pt, axis = 1)
    #print(index_muon)
    index_trk_trip = dak.local_index(trk_trip_pt, axis = 1)
    pairs_pt_tr = dak.cartesian([trk_trip_pt, track_pt])
    pairs_eta_tr = dak.cartesian([trk_trip_eta, track_eta])
    pairs_phi_tr = dak.cartesian([trk_trip_phi, track_phi])
    ratio_pt_tr = pairs_pt_tr["0"]==pairs_pt_tr["1"]
    ratio_phi_tr = pairs_phi_tr["0"]==pairs_phi_tr["1"]
    ratio_eta_tr = pairs_eta_tr["0"]==pairs_eta_tr["1"]
    _, pairs_index_tr = dak.unzip(dak.cartesian([trk_trip_pt, index_track]))
    pairs_tri_index_tr, _ = dak.unzip(dak.cartesian([index_trk_trip, track_pt]))
    #selection_tr = (ratio_pt_tr == 1) & (ratio_eta_tr == 1) & (ratio_phi_tr == 1)
    selection_tr = (ratio_pt_tr) & (ratio_eta_tr) & (ratio_phi_tr)
    pairs_track_index = (pairs_index_tr[selection_tr])
    pairs_tri_track_index = (pairs_tri_index_tr[selection_tr])
    return pairs_track_index, pairs_tri_track_index

# Define a function to remove extra duplicates, keeping each unique element once
def remove_extra_duplicates(sublist):
    #print(sublist)
    seen = set()
    unique_list = []
    for item in sublist:
        if item not in seen:
            unique_list.append(item)
            seen.add(item)
    return unique_list

def contains_elements(array1, array2):
    return dak.Array([[elem in sub2 for elem in sub1] for sub1, sub2 in zip(array1, array2)])

#@dask.delayed
def trigger_match(dataframe, pairs_mu01_index, pairs_mu02_index):
    HLT_obj_pt = dataframe.MuonPt_HLT2017
    pt1, HLT_obj_pt = dak.unzip(dak.cartesian([dataframe.Mu01_Pt, HLT_obj_pt]))
    index_pt1, _ = dak.unzip(dak.cartesian([dak.local_index(dataframe.Mu01_Pt), HLT_obj_pt]))
    dpt1 = abs(pt1 - HLT_obj_pt)/pt1
    pt2, HLT_obj_pt = dak.unzip(dak.cartesian([dataframe.Mu02_Pt, HLT_obj_pt]))
    index_pt2, _ = dak.unzip(dak.cartesian([dak.local_index(dataframe.Mu02_Pt), HLT_obj_pt]))
    dpt2 = abs(pt2 - HLT_obj_pt)/pt2
    HLT_obj_phi = dataframe.MuonPhi_HLT2017
    phi1, HLT_obj_phi = dak.unzip(dak.cartesian([dataframe.Mu01_Phi, HLT_obj_phi]))
    dphi1 = abs(phi1 - HLT_obj_phi)
    phi2, HLT_obj_phi = dak.unzip(dak.cartesian([dataframe.Mu02_Phi, HLT_obj_phi]))
    dphi2 = abs(phi2 - HLT_obj_phi)
    HLT_obj_eta = dataframe.MuonEta_HLT2017
    eta1, HLT_obj_eta = dak.unzip(dak.cartesian([dataframe.Mu01_Eta, HLT_obj_eta]))
    deta1 = abs(eta1 - HLT_obj_eta)
    eta2, HLT_obj_eta = dak.unzip(dak.cartesian([dataframe.Mu02_Eta, HLT_obj_eta]))
    deta2 = abs(eta2 - HLT_obj_eta)
    dphi1 = dak.where(dphi1>math.pi, dphi1 - 2*math.pi, dphi1)
    dphi2 = dak.where(dphi2>math.pi, dphi2 - 2*math.pi, dphi2)
    #print(dphi1)
    #if (dphi1 > math.pi): dphi1 -= 2*math.pi
    dR1 = np.sqrt(dphi1*dphi1 + deta1*deta1)
    dR_cut1 = (dR1<0.03)
    dpt_cut1 = (dpt1<0.1)
    dRdpt_cut1 = dpt_cut1 & dR_cut1
    # Apply the function
    #trigger_match1 = contains_elements(pt_index1, index_pt1[dRdpt_cut1])
    index_pt1_sel = index_pt1[dRdpt_cut1]
    index_pt1_sel = dak.where(dak.num(index_pt1_sel, axis =1)==0, [[-1]], index_pt1_sel)
    pt_index1 = dak.local_index(dataframe.Mu01_Pt, axis = 1)
    print(pt_index1[dataframe.evt == 2313273593])
    print(HLT_obj_pt[dataframe.evt == 2313273593])
    print(index_pt1_sel[dataframe.evt == 2313273593])
    print(index_pt1_sel)
    # Apply the function
    #trigger_match1 = contains_elements(pt_index1, index_pt1[dRdpt_cut1])
    #print(ak.cartesian([pt_index1, index_pt1[dRdpt_cut1]])[ak.num(ak.cartesian([pt_index1, index_pt1[dRdpt_cut1]]), axis = 1)>0])
    trigger_support, _ = dak.unzip(ak.cartesian([pt_index1, index_pt1_sel]))
    #print(trigger_support[dataframe.evt == 2313273593])
    trigger_support = dak.run_lengths(trigger_support)
    #print(trigger_support[dataframe.evt == 2313273593])
    #print(ak.cartesian([pt_index1, index_pt1_sel])[dataframe.evt == 2313273593])
    #print(trigger_support[ak.num(ak.cartesian([pt_index1, index_pt1[dRdpt_cut1]]), axis = 1)>0])
    #trigger_support = ak.where(ak.num(trigger_support, axis =1) == 0, ak.Array([[1]]), trigger_support)
    trigger_match1_pairs = dak.unflatten(dak.cartesian([pt_index1, index_pt1_sel]), dak.flatten(trigger_support), axis = 1)
    #print(trigger_match1_pairs[ak.num(ak.cartesian([pt_index1, index_pt1[dRdpt_cut1]]), axis = 1)>0])
    trigger_match1 = dak.any(trigger_match1_pairs["0"]==trigger_match1_pairs["1"], axis = 2)
    #print(pt_index1)
    #print(trigger_match1[dak.num(dak.cartesian([pt_index1, index_pt1[dRdpt_cut1]]), axis = 1)>0])
    #print(dR_cut1)
    #triggerMatch_1 = dak.values_astype(dak.any(dpt_cut1 & dR_cut1, axis = 1), int)
    dR2 = np.sqrt(dphi2*dphi2 + deta2*deta2)
    dR_cut2 = (dR2<0.03)
    dpt_cut2 = (dpt2<0.1)
    dRdpt_cut2 = dpt_cut2 & dR_cut2
    index_pt2_sel = index_pt2[dRdpt_cut2]
    index_pt2_sel = dak.where(dak.num(index_pt2_sel, axis =1)==0, [[-1]], index_pt2_sel)
    pt_index2 = dak.local_index(dataframe.Mu02_Pt, axis = 1)
    # Apply the function
    #trigger_match2 = contains_elements(pt_index2, index_pt2[dRdpt_cut2])
    trigger_support2, _ = dak.unzip(dak.cartesian([pt_index2, index_pt2_sel]))
    trigger_support2 = dak.run_lengths(trigger_support2)
    #print(trigger_support[ak.num(ak.cartesian([pt_index1, index_pt1[dRdpt_cut1]]), axis = 1)>0])
    #trigger_support = ak.where(ak.num(trigger_support, axis =1) == 0, ak.Array([[1]]), trigger_support)
    trigger_match2_pairs = dak.unflatten(dak.cartesian([pt_index2, index_pt2_sel]), dak.flatten(trigger_support2), axis = 1)
    #print(trigger_match1_pairs[ak.num(ak.cartesian([pt_index1, index_pt1[dRdpt_cut1]]), axis = 1)>0])
    trigger_match2 = dak.any(trigger_match2_pairs["0"]==trigger_match2_pairs["1"], axis = 2)
    #trigger_match2.visualize()
    #print(dR_cut1)
    trigger_match3 = trigger_match2
    return trigger_match1, trigger_match2, trigger_match3

#@dask.delayed
def process_event(sub_df, debugMode, cutevt, df_fin, isMC, tree_Filled):
    start1 = time.time()
    #jentry = np.arange(dak.num(sub_df["run"], axis = 0)) #array of indeces
    #print(jentry)
    #sub_df["event_id"] = jentry
    run_n = sub_df.run
    lumi_n = sub_df.lumi
    evt_n = sub_df.evt
    print("NO CUTS:")
    #print(dak.num(dak.drop_none(sub_df.MuonPt[dak.num(sub_df.MuonPt, axis = 1)>0]), axis = 0))  #in this way because the negation as logic condition is a bit problematic
    #CUT 0 : Before cuts - skip event if no good triplets
    #print(sub_df.NGoodTriplets)
    GoodTriplets = (sub_df.NGoodTriplets >= 1)
    NoGoodTriplets = (sub_df.NGoodTriplets < 1)
    #print(NoGoodTriplets)
    #cutevt[0] = dak.num(sub_df[NoGoodTriplets], axis = 0)  #is the number of events that do not have good triplets
    #cutevt[0] = dak.num(sub_df[GoodTriplets], axis = 0)  #is the number of events that have good triplets
    #print(cutevt[0])
    sub_df = sub_df[dak.any(GoodTriplets, axis = 1)]
    # CUT 1 : Check L1 and HLT decision
    # Check L1trigger
    #print(sub_df.Trigger_l1decision)
    #print((dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4"))|(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4"))|(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu4_SQ_OS_dR_Max1p2"))|(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu4p5_SQ_OS_dR_Max1p2"))|(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p6"))|(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p5")))
    L1_passed = (dak.any(((dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4"))|(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4"))|(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu4_SQ_OS_dR_Max1p2"))|(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu4p5_SQ_OS_dR_Max1p2"))|(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p6"))|(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p5")))&((sub_df.Trigger_l1decision) == 1), axis =1)) #keepdims = True
    #print(L1_passed)
    #cutevt[0] += dak.num(sub_df, axis = 0) - dak.num(sub_df[L1_passed], axis = 0)  #in this way because the negation as logic condition is a bit problematic
    cutevt[0] = dak.num(dak.drop_none(sub_df.MuonPt[L1_passed][dak.num(sub_df.MuonPt[L1_passed], axis = 1)>0]), axis = 0)  #in this way because the negation as logic condition is a bit problematic
    #print("L1 Trigger:")
    #print(cutevt[0])
    #From now on I ony take into account the events that have at least one of the required L1 passed.
    sub_df = sub_df[L1_passed]
    L1seed = (1*dak.values_astype(dak.any(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4") & (sub_df.Trigger_l1decision == 1), axis = 1), int)
            + 10*dak.values_astype(dak.any(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu4_SQ_OS_dR_Max1p2") & (sub_df.Trigger_l1decision == 1), axis = 1), int)
            + 1000*dak.values_astype(dak.any(dak.str.match_substring(sub_df.Trigger_l1name,"L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p6") & (sub_df.Trigger_l1decision == 1), axis =1), int))
    # Check HLT
    HLT_passed = dak.any(dak.str.match_substring(sub_df.Trigger_hltname,"HLT_DoubleMu3_Trk_Tau3mu_v") & (sub_df.Trigger_hltdecision == 1), axis = 1)
    #cutevt[1] = dak.num(sub_df, axis = 0) - dak.num(sub_df[HLT_passed], axis = 0)
    cutevt[1] = dak.num(dak.drop_none(sub_df.MuonPt[HLT_passed][dak.num(sub_df.MuonPt[HLT_passed], axis = 1)>0]), axis=0)  #in this way because the negation as logic condition is a bit problematic
    #print("HLT Trigger")
    #print(cutevt[1])
    sub_df = sub_df[HLT_passed]
    HLTpath = (1*dak.values_astype(dak.any(dak.str.match_substring(sub_df.Trigger_hltname, "HLT_string_DoubleMu3_Trk_Tau3mu_v") & (sub_df.Trigger_hltdecision == 1), axis = 1), int)
            + 10*dak.values_astype(dak.any(dak.str.match_substring(sub_df.Trigger_hltname, "HLT_DoubleMu4_3_LowMass") & (sub_df.Trigger_hltdecision == 1), axis = 1), int)
            + 100*dak.values_astype(dak.any(dak.str.match_substring(sub_df.Trigger_hltname, "HLT_DoubleMu4_LowMass_Displaced") & (sub_df.Trigger_hltdecision == 1), axis = 1), int))
    sub_df["HLTpath"] = HLTpath
    events_now = sub_df["evt"]
    ################################################################################################
    #Loop over the TRIPLETS
    # find the indeces of the muons (and track) in the Muon branches corresponding to the muons (and track) in Mu0{1/2} branches
    pairs_mu01_index, pairs_tri_mu01_index, pairs_mu02_index, pairs_tri_mu02_index = twoMuonsFinder(sub_df)
    pairs_track_index, pairs_tri_track_index = trackFinder(sub_df)
    sub_df["Mu01_isGlb"] = sub_df.Muon_isGlobal[:][pairs_mu01_index]
    sub_df["Mu02_isGlb"] = sub_df.Muon_isGlobal[:][pairs_mu02_index]
    sub_df["Mu01_isMdm"] = sub_df.Muon_isMedium[:][pairs_mu01_index]
    sub_df["Mu02_isMdm"] = sub_df.Muon_isMedium[:][pairs_mu02_index]
    sub_df["Tr_dz"] = sub_df.Track_dz[:][pairs_track_index]
    sub_df["Tr_dxy"] = sub_df.Track_dxy[:][pairs_track_index]
    sub_df["Mu01_charge"] = sub_df.MuonCharge[:][pairs_mu01_index]
    sub_df["Mu02_charge"] = sub_df.MuonCharge[:][pairs_mu02_index]
    sub_df["Mu01_energy"] = sub_df.MuonEnergy[:][pairs_mu01_index]
    sub_df["Mu02_energy"] = sub_df.MuonEnergy[:][pairs_mu02_index]
    sub_df = sub_df[dak.num(sub_df["Mu01_Pt"], axis  =1)==dak.num(sub_df["Mu01_charge"], axis = 1)]
    sub_df = sub_df[dak.num(sub_df["Mu01_charge"], axis  =1)==dak.num(sub_df["Mu02_charge"], axis = 1)]
    sub_df["Mu0102_charge"] = sub_df["Mu01_charge"]+sub_df["Mu02_charge"]
    #for each triplet I require that the muons are in the acceptance range 
    #acceptance_limitations_barrel = (sub_df.Mu01_Pt>=3.5)&(sub_df.Mu02_Pt>=3.5)&(abs(sub_df.Mu01_Eta)<=1.2)&(abs(sub_df.Mu01_Eta)<=1.2)
    #acceptance = (acceptance_limitations_endcap|acceptance_limitations_barrel) & (sub_df.Tr_Pt>1.2)
    #and that the tracks are in their acceptance range, too.
    #I require each triplet to have 2 muons Glb & Mdm and the track good
    acceptance_limitations_endcap = (sub_df.Mu01_Pt>=2)&(sub_df.Mu02_Pt>=2)&(abs(sub_df.Mu01_Eta)<=2.4)&(abs(sub_df.Mu02_Eta)<=2.4)#(abs(sub_df.Mu01_Eta)>1.2)&(abs(sub_df.Mu01_Eta)<=2.4)&(abs(sub_df.Mu02_Eta)>1.2)&(abs(sub_df.Mu02_Eta)<=2.4)
    acceptance = (acceptance_limitations_endcap)&(sub_df.Tr_Pt>=2)&(abs(sub_df.Tr_Eta)<=2.4)#& (sub_df.Tr_Pt>1.2)
    not_duplicated = (DuplicateFinder(sub_df))
    triMuonMass = (sub_df.Triplet2_Mass>1.62)&(sub_df.Triplet2_Mass<2.1)
    cut_Pv_Sv_significance = (sub_df.FlightDistBS_SV_Significance>=3.5)
    muons_GlbMdm = (sub_df.Mu01_isGlb==1)&(sub_df.Mu02_isGlb==1)&(sub_df.Mu01_isMdm==1)&(sub_df.Mu02_isMdm==1)&(sub_df.Tr_dz<20)&(sub_df.Tr_dxy<0.3)
    #sub_df["Mu0102_Mass"] = DimuonMass(sub_df)
    #phi_mass = (sub_df["Mu0102_Mass"]<=1.06) & (sub_df["Mu0102_Mass"]>=0.98)
    #triggerMatch_1, triggerMatch_2, triggerMatch_3 = trigger_match(sub_df, pairs_mu01_index, pairs_mu02_index)
    for col in dak.fields(sub_df):
        if col.startswith("Mu0") or col.startswith("Tr_"):  # Pattern matching, adjust as necessary
            sub_df[col] = sub_df[col][acceptance&not_duplicated&cut_Pv_Sv_significance&muons_GlbMdm]#&triMuonMass&triggerMatch_1&triggerMatch_2&triggerMatch_3]
    events_now = sub_df["evt"][dak.num(sub_df.Mu01_Pt, axis = 1)>0]
    sub_df["Triplet2_Mass"] = sub_df["Triplet2_Mass"][acceptance&not_duplicated&cut_Pv_Sv_significance&muons_GlbMdm]
    #print("MUON ID:")
    #print(dak.sum(dak.flatten(muons_GlbMdm, axis=0), axis = 0))
    #print(dak.num(sub_df.Mu01_Pt[dak.num(sub_df.Mu01_Pt, axis = 1)>0], axis = 0))
    sub_df["Mu0102_Mass"] = DimuonMass(sub_df)
    #print(sub_df["Mu0102_Mass"])
    phi_mass = (sub_df["Mu0102_Mass"]<=1.06) & (sub_df["Mu0102_Mass"]>=0.98)
    for col in dak.fields(sub_df):
        if col.startswith("Mu0") or col.startswith("Tr_"):  # Pattern matching, adjust as necessary
            sub_df[col] = sub_df[col][phi_mass]
    sub_df["Triplet2_Mass"] = sub_df["Triplet2_Mass"][phi_mass]
    #print(dak.num(sub_df.Mu01_Pt[dak.num(sub_df.Mu01_Pt, axis = 1)>0], axis = 0))
    triMuonMass = (sub_df.Triplet2_Mass>1.62)&(sub_df.Triplet2_Mass<2.1)
    for col in dak.fields(sub_df):
        if col.startswith("Mu0") or col.startswith("Tr_") or col.startswith("TripletVtx2_Chi2"):  # Pattern matching, adjust as necessary
            sub_df[col] = sub_df[col][triMuonMass]
    #print("TriMuonMass:")
    #print(dak.sum(dak.flatten(muons_GlbMdm, axis=0), axis = 0))
    #print(dak.num(sub_df.Mu01_Pt[dak.num(sub_df.Mu01_Pt, axis = 1)>0], axis = 0))
    #se ci sono più tripletti buoni devo selezionare quello con il minore chi2
    # il chi2 è fornito per i tripletti quindi va ripreso l'indice del tripletto
    #print("TRIGGER MATCH")
    triggerMatch_1, triggerMatch_2, triggerMatch_3 = trigger_match(sub_df, pairs_mu01_index, pairs_mu02_index)
    for col in dak.fields(sub_df):
        if col.startswith("Mu0") or col.startswith("Tr_") or col.startswith("TripletVtx2_Chi2"):  # Pattern matching, adjust as necessary
            sub_df[col] = sub_df[col][triggerMatch_1]
    triggerMatch_2 = triggerMatch_2[triggerMatch_1]
    for col in dak.fields(sub_df):
        if col.startswith("Mu0") or col.startswith("Tr_") or col.startswith("TripletVtx2_Chi2"):  # Pattern matching, adjust as necessary
            sub_df[col] = sub_df[col][triggerMatch_2]
    #print(dak.num(sub_df.Mu01_Pt[dak.num(sub_df.Mu01_Pt, axis = 1)>0], axis = 0))
    sub_df = sub_df[dak.num(sub_df.Mu01_Pt, axis = 1)>0]
    #sub_df = sub_df.compute()
    return sub_df

def process_df(df):   
    print(df)

def Loop_DsPhiPi(tree, type, datasetName, filename):
    df = tree
    print(df)
    start1 = time.time()
    '''
    length = len(df)
    #print(length)
    if length==0: return
    nentries = length
    '''

    debugMode = False

    cutevt = [0]*NCUTS
    '''
    listCut = ["BeforeCuts", "L1_fired", "HLT_fired", "MuonID", "DiMu_mass", "TriMu_mass", "mu1_TrMatch", "mu12_TrMatch", "mu123_TrMatch"]
    debugMode = False
    headers = pd.read_csv("headers.csv")
    #df_fin = pd.DataFrame(index = range(nentries), columns = headers.columns)
    '''
    if("2022" in datasetName or "2023" in datasetName): isMC=0
    else: isMC=5
    
    tree_Filled = 0
    df_fin = 0

    arrays = dask.delayed(process_event(df, debugMode, cutevt, df_fin, isMC, tree_Filled))
    #arrays = arrays.compute()
    print("computed")
    #new_df = dak.copy(sub_df)
    new_df = {}
    # Define an empty pandas DataFrame to provide structure
    empty_df = pd.DataFrame(columns=["column1", "column2", "column3"])

    # Convert the empty pandas DataFrame to a Dask DataFrame
    dask_df = dd.from_pandas(empty_df, npartitions=1)   
    '''
    for col in dak.fields(arrays):
        #print("computing...")
        if col.startswith("Mu0") or col.startswith("Tr_"):# or col.startswith("TripletVtx2_Chi2"):  # Pattern matching, adjust as necessary
            #print(col)
            #min_value = dak.firsts(dak.min(sub_df.TripletVtx2_Chi2, axis = 1, keepdims = True))
            #column = dak.flatten(sub_df[col][sub_df.TripletVtx2_Chi2 == min_value])
            dask_df[col] = dak.flatten(arrays[col])
    '''
    dask_df = arrays.to_dask_dataframe()
    csv_file= "/lustrehome/felicenenna/tau3mu/CMSSW_14_0_12/src/Analysis/csv_output_prova.csv"
    dask_df.to_csv(csv_file)
    stop1 = time.time()
    dtime1 = stop1 -start1
    #print(f"tempo impegato a processare un evento: {dtime1}")
    #print(f"tempo impegato a processare un evento: {dtime1}")
    #print(arrays)
    #arrays = dak.to_rdataframe(arrays)
    #df_fin = df_fin[~df_fin.evt.isna()]
    #print(tree_Filled)
    #print(df_fin[~df_fin.evt.isna()])
    #print(df_fin.L1seed[~df_fin.evt.isna()])
    #listCut = ["BeforeCuts", "L1_fired", "HLT_fired", "MuonID", "DiMu_mass", "TriMu_mass", "mu1_TrMatch", "mu12_TrMatch", "mu123_TrMatch"]
    #selections = listCut
    #heights = cutevt
    '''
    # Creating a bar plot (histogram-like)
    plt.bar(selections, heights)

    # Adding labels and title
    plt.xlabel('Selections')
    plt.ylabel('Height')
    plt.title('Histogram of Selections vs Heights') 
    plt.savefig("cuts_efficiency.png")
    # Convert the DataFrame into a dictionary of arrays (one for each column)
    arrays = {col: df_fin[col].values for col in df_fin.columns}
    '''
    #print(df)
    # Open a ROOT file and write the TTree
    return dask_df
    '''
    with uproot.recreate(filename) as root_file:
        root_file["FinalTree"] = new_df  # Write the arrays to the tree
    '''
    #df_fin.Snapshot("FinalTree", filename)


