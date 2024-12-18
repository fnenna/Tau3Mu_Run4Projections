NCUTS = 9
NMU = 3
mumass = 0.1056583715
PhiMass = 1.019461 # Phi mass in GeV
OmegaMass = 0.78265 # Omega mass in GeV
ptmin = 2.0

import ROOT
from python_utilities_control import Extended_MyAnalizerControl
'''
import TStyle
import TCanvas
import TRandom
import python_utilities_control
import stdio
import iostream
'''
import math



#using namespace std;

class Extended_MyAnalizerControl2(Extended_MyAnalizerControl):

    def Loop_DsPhiPi(self, type, datasetName):
        if (self.fChain == 0): return
        nentries = self.fChain.GetEntries()
    
        # Variables definition & init
        cutevt = []
        for i in range(NCUTS):
            cutevt.append(0)
        listCut = []
        self.Fill_CutName(listCut)
        debugMode = True
        L1seed = -99
        HLTpath = -99
        L1_DoubleMu0_er1p5 = 0
        L1_DoubleMu0_er1p4 = 0
        L1_DoubleMu4_dR1p2 = 0
        L1_DoubleMu4p5_dR1p2 = 0
        L1_DoubleMu0_er2p0 = 0
        L1_DoubleMu0_er2p0_bk = 0
        isMC = -99
        run_n = 0
        lumi_n = 0
        evt_n = 0
        L1 = 0
        nHLT = 0
        deltaR_max = 0
        deltaZ_max = 0
        Pmu3 = 0
        cLP = 0
        tKink = 0
        segmComp = 0
        tripletMass = 0
        tripletMassReso = 0
        fv_nC = 0
        fv_dphi3D = 0
        fv_d3D = 0
        fv_d3Dsig = 0
        d0 = 0
        nVtx=0
        d0sig = 0
        MVA1 = 0
        pileupFactor = 0; MVA2 = 0; MVA3 = 0; MVASoft1 = 0; MVASoft2 = 0; MVASoft3 = 0; d0sig_max = 0; mindca_iso = 0; trkRel = 0; Pmu1 = 0; Ptmu1 = 0; etamu1 = 0; phimu1 = 0; Pmu2 = 0; Ptmu2 = 0; etamu2 = 0; phimu2 = 0; Ptmu3 = 0; etamu3 = 0; phimu3 = 0; dispMu1 = 0; dispMu2 = 0; dispMu3 = 0; xydispMu1 = 0; xydispMu2 = 0; xydispMu3 = 0; P_trip = 0; Pt_trip = 0; eta_trip = 0; nStationsMu1 = 0; nStationsMu2 = 0; nStationsMu3 = 0; Iso03Mu1 = 0; Iso03Mu2 = 0; Iso03Mu3 = 0; Iso05Mu1 = 0; Iso05Mu2 = 0; Iso05Mu3 = 0; nMatchesMu1 = 0; nMatchesMu2 = 0; nMatchesMu3 = 0; timeAtIpInOutMu_sig1 = 0; timeAtIpInOutMu_sig2 = 0; timeAtIpInOutMu_sig3 = 0; cQ_uS = 0; cQ_tK = 0; cQ_gK = 0; cQ_tRChi2 = 0; cQ_sRChi2 = 0; cQ_Chi2LP = 0; cQ_Chi2LM = 0; cQ_lD = 0; cQ_gDEP = 0; cQ_tM = 0; cQ_gTP = 0; calEn_emMu1 = 0; calEn_emMu2 = 0; calEn_emMu3 = 0; calEn_hadMu1 = 0; calEn_hadMu2 = 0; calEn_hadMu3 = 0; caloComp = 0; fliDistPVSV_Chi2 = 0; isGlb1 = 0; isMedium1 = 0; isTracker1 = 0; isLoose1 = 0; isSoft1 = 0; SoftMVA1 = 0; isPF1 = 0; isRPC1 = 0; isSA1 = 0; isCalo1 = 0; isGlb2 = 0; isMedium2 = 0; isTracker2 = 0; isLoose2 = 0; isSoft2 = 0; SoftMVA2 = 0; isPF2 = 0; isRPC2 = 0; isSA2 = 0; isCalo2 = 0; isGlb3 = 0; isMedium3 = 0; isTracker3 = 0; isLoose3 = 0; isSoft3 = 0; SoftMVA3 = 0; isPF3 = 0; isRPC3 = 0; isSA3 = 0; isCalo3 = 0; vx1 = 0; vx2 = 0; vx3 = 0; vy1 = 0; vy2 = 0; vy3 = 0; vz1 = 0; vz2 = 0; vz3 = 0; Refvx1 = 0; Refvx2 = 0; Refvx3 = 0; Refvy1 = 0; Refvy2 = 0; Refvy3 = 0; Refvz1 = 0; Refvz2 = 0; Refvz3 = 0; SVx = 0; SVy = 0; SVz = 0; had03 = 0; had05 = 0; nJets03 = 0; nJets05 = 0; nTracks03 = 0; nTracks05 = 0; sumPt03 = 0; sumPt05 = 0; hadVeto03 = 0; hadVeto05 = 0; emVeto03 = 0; emVeto05 = 0; trVeto03 = 0; trVeto05 = 0; EnMu1 = 0; EnMu2 = 0; EnMu3 = 0; ChargeMu1 = 0; ChargeMu2 = 0; ChargeMu3 = 0; isQValid1 = 0; isTValid1 = 0; isIsoValid1 = 0; GLnormChi2_mu1 = 0; GL_nValidMuHits1 = 0; trkLayersWMeas1 = 0; nValidPixelHits1 = 0; outerTrk_P_1 = 0; outerTrk_Eta_1 = 0; outerTrk_normChi2_1 = 0; outerTrk_muStValidHits_1 = 0; innerTrk_P_1 = 0; innerTrk_Eta_1 = 0; innerTrk_normChi2_1 = 0; QInnerOuter_1 = 0; cQ_uS_1 = 0; cQ_tK_1 = 0; cQ_gK_1 = 0; cQ_tRChi2_1 = 0; cQ_sRChi2_1 = 0; cQ_Chi2LP_1 = 0; cQ_Chi2LM_1 = 0; cQ_lD_1 = 0; cQ_gDEP_1 = 0; cQ_tM_1 = 0; cQ_gTP_1 = 0; segmComp_1 = 0; caloComp_1 = 0; isQValid2 = 0; isTValid2 = 0; isIsoValid2 = 0; GLnormChi2_mu2 = 0; GL_nValidMuHits2 = 0; trkLayersWMeas2 = 0; nValidPixelHits2 = 0; outerTrk_P_2 = 0; outerTrk_Eta_2 = 0; outerTrk_normChi2_2 = 0; outerTrk_muStValidHits_2 = 0; innerTrk_P_2 = 0; innerTrk_Eta_2 = 0; innerTrk_normChi2_2 = 0; QInnerOuter_2 = 0; cQ_uS_2 = 0; cQ_tK_2 = 0; cQ_gK_2 = 0; cQ_tRChi2_2 = 0; cQ_sRChi2_2 = 0; cQ_Chi2LP_2 = 0; cQ_Chi2LM_2 = 0; cQ_lD_2 = 0; cQ_gDEP_2 = 0; cQ_tM_2 = 0; cQ_gTP_2 = 0; segmComp_2 = 0; caloComp_2 = 0; isQValid3 = 0; isTValid3 = 0; isIsoValid3 = 0; GLnormChi2_mu3 = 0; GL_nValidMuHits3 = 0; trkLayersWMeas3 = 0; nValidPixelHits3 = 0; outerTrk_P_3 = 0; outerTrk_Eta_3 = 0; outerTrk_normChi2_3 = 0; outerTrk_muStValidHits_3 = 0; innerTrk_P_3 = 0; innerTrk_Eta_3 = 0; innerTrk_normChi2_3 = 0; QInnerOuter_3 = 0; cQ_uS_3 = 0; cQ_tK_3 = 0; cQ_gK_3 = 0; cQ_tRChi2_3 = 0; cQ_sRChi2_3 = 0; cQ_Chi2LP_3 = 0; cQ_Chi2LM_3 = 0; cQ_lD_3 = 0; cQ_gDEP_3 = 0; cQ_tM_3 = 0; cQ_gTP_3 = 0; segmComp_3 = 0; caloComp_3 = 0; inTrk_highPurity_1 = 0; inTrk_ValidFraction_1 = 0; NvalidTrkHits_1 = 0; validMuHitComb_1 = 0; IP2D_BS_1 = 0; IP3D_BS_1 = 0; IP2D_PV_1 = 0; IP3D_PV_1 = 0; inTrk_highPurity_2 = 0; inTrk_ValidFraction_2 = 0; NvalidTrkHits_2 = 0; validMuHitComb_2 = 0; IP2D_BS_2 = 0; IP3D_BS_2 = 0; IP2D_PV_2 = 0; IP3D_PV_2 = 0; inTrk_highPurity_3 = 0; inTrk_ValidFraction_3 = 0; NvalidTrkHits_3 = 0; validMuHitComb_3 = 0; IP2D_BS_3 = 0; IP3D_BS_3 = 0; IP2D_PV_3 = 0; IP3D_PV_3 = 0; inTrk_highPurity_max = 0; inTrk_ValidFraction_max = 0; NvalidTrkHits_max = 0; validMuHitComb_max = 0; IP2D_BS_max = 0; IP3D_BS_max = 0; IP2D_PV_max = 0; IP3D_PV_max = 0; inTrk_highPurity_min = 0; inTrk_ValidFraction_min = 0; NvalidTrkHits_min = 0; validMuHitComb_min = 0; IP2D_BS_min = 0; IP3D_BS_min = 0; IP2D_PV_min = 0; IP3D_PV_min = 0; tripl_IsoMu1 = 0; tripl_IsoMu2 = 0; tripl_IsoMu3 = 0; DistXYPVSV = 0; DistXY_PVSV_sig = 0; FlightDistBSSV = 0; FlightDistBS_SV_sig = 0; diMu12_mass = 0; diMu23_mass = 0; diMu13_mass = 0; cTau = 0; cTau2 = 0; NMu_TrMatch = 0; IP1 = 0; IP2 = 0; IP3 = 0; IP1_sig = 0; IP2_sig = 0; IP3_sig = 0; muSimPdgId_1 = 0; muSimMotherPdgId_1 = 0; muSimPdgId_2 = 0; muSimMotherPdgId_2 = 0; muSimPdgId_3 = 0; muSimMotherPdgId_3 = 0; NTrk_RefittedPV = 0; RefittedPV_Chi2norm = 0; diMuVtx_dist_max = 0; diMuVtx_dist_min = 0; Chi2IP_max = 0;
        
        match1_dX_1=0; match1_pullX_1=0; match1_pullDxDz_1=0; match1_dY_1=0; match1_pullY_1=0; match1_pullDyDz_1=0; 
        match1_dX_2=0; match1_pullX_2=0; match1_pullDxDz_2=0; match1_dY_2=0; match1_pullY_2=0; match1_pullDyDz_2=0; 
        match1_dX_3=0; match1_pullX_3=0; match1_pullDxDz_3=0; match1_dY_3=0; match1_pullY_3=0; match1_pullDyDz_3=0; 
        match2_dX_1=0; match2_pullX_1=0; match2_pullDxDz_1=0; match2_dY_1=0; match2_pullY_1=0; match2_pullDyDz_1=0; 
        match2_dX_2=0; match2_pullX_2=0; match2_pullDxDz_2=0; match2_dY_2=0; match2_pullY_2=0; match2_pullDyDz_2=0; 
        match2_dX_3=0; match2_pullX_3=0; match2_pullDxDz_3=0; match2_dY_3=0; match2_pullY_3=0; match2_pullDyDz_3=0
        
        validMuonHitComb1=0
        validMuonHitComb2=0
        validMuonHitComb3=0
        nValidTrackerHits1=0
        nValidTrackerHits2=0
        nValidTrackerHits3=0

        innerTrk_ValidFraction_1=0
        innerTrk_ValidFraction_2=0
        innerTrk_ValidFraction_3=0
        innerTrk_highPurity_1=0
        innerTrk_highPurity_2=0
        innerTrk_highPurity_3=0

        # Creation of the output file
        root_fileName = self.filename
        fout = ROOT.TFile(root_fileName, "RECREATE")
        fout.cd()
        tree = ROOT.TTree("FinalTree","FinalTree")
        self.TreeFin_Init(tree, isMC, lumi_n, run_n, evt_n, pileupFactor, L1_DoubleMu0_er1p5, L1_DoubleMu0_er1p4, L1_DoubleMu4_dR1p2, L1_DoubleMu4p5_dR1p2, L1_DoubleMu0_er2p0, L1_DoubleMu0_er2p0_bk, L1seed, HLTpath, deltaR_max, deltaZ_max, Pmu3, cLP, tKink, segmComp, tripletMass, tripletMassReso, fv_nC, fv_dphi3D, fv_d3D, fv_d3Dsig, d0, nVtx, d0sig, MVA1, MVA2, MVA3, MVASoft1, MVASoft2, MVASoft3, d0sig_max, mindca_iso, trkRel, Pmu1, Ptmu1, etamu1, phimu1, Pmu2, Ptmu2, etamu2, phimu2, Ptmu3, etamu3, phimu3, dispMu1, dispMu2, dispMu3, xydispMu1, xydispMu2, xydispMu3, P_trip, Pt_trip, eta_trip, nStationsMu1, nStationsMu2, nStationsMu3, Iso03Mu1, Iso03Mu2, Iso03Mu3, Iso05Mu1, Iso05Mu2, Iso05Mu3, nMatchesMu1, nMatchesMu2, nMatchesMu3, timeAtIpInOutMu_sig1, timeAtIpInOutMu_sig2, timeAtIpInOutMu_sig3, cQ_uS, cQ_tK, cQ_gK, cQ_tRChi2, cQ_sRChi2, cQ_Chi2LP, cQ_Chi2LM, cQ_lD, cQ_gDEP, cQ_tM, cQ_gTP, calEn_emMu1, calEn_emMu2, calEn_emMu3, calEn_hadMu1, calEn_hadMu2, calEn_hadMu3, caloComp, fliDistPVSV_Chi2, isMedium1, isMedium2, isGlb1, isTracker1, isLoose1,  isSoft1, isPF1, isRPC1, isSA1, isCalo1, isGlb2, isTracker2, isLoose2,  isSoft2, isPF2, isRPC2, isSA2, isCalo2, isGlb3, isTracker3, isLoose3,  isSoft3, isPF3, isRPC3, isSA3, isCalo3, vx1, vx2, vx3, vy1, vy2, vy3, vz1, vz2, vz3, Refvx1, Refvx2, Refvx3, Refvy1, Refvy2, Refvy3, Refvz1, Refvz2, Refvz3, SVx, SVy, SVz, had03, had05, nJets03, nJets05, nTracks03, nTracks05, sumPt03, sumPt05, hadVeto03, hadVeto05, emVeto03, emVeto05, trVeto03, trVeto05, EnMu1, EnMu2, EnMu3, ChargeMu1, ChargeMu2, ChargeMu3, isQValid1, isTValid1, isIsoValid1, GLnormChi2_mu1, GL_nValidMuHits1, trkLayersWMeas1, nValidPixelHits1, outerTrk_P_1, outerTrk_Eta_1, outerTrk_normChi2_1, outerTrk_muStValidHits_1, innerTrk_P_1, innerTrk_Eta_1, innerTrk_normChi2_1, QInnerOuter_1, cQ_uS_1, cQ_tK_1, cQ_gK_1, cQ_tRChi2_1, cQ_sRChi2_1, cQ_Chi2LP_1, cQ_Chi2LM_1, cQ_lD_1, cQ_gDEP_1, cQ_tM_1, cQ_gTP_1, segmComp_1, caloComp_1, isQValid2, isTValid2, isIsoValid2, GLnormChi2_mu2, GL_nValidMuHits2, trkLayersWMeas2, nValidPixelHits2, outerTrk_P_2, outerTrk_Eta_2, outerTrk_normChi2_2, outerTrk_muStValidHits_2, innerTrk_P_2, innerTrk_Eta_2, innerTrk_normChi2_2, QInnerOuter_2, cQ_uS_2, cQ_tK_2, cQ_gK_2, cQ_tRChi2_2, cQ_sRChi2_2, cQ_Chi2LP_2, cQ_Chi2LM_2, cQ_lD_2, cQ_gDEP_2, cQ_tM_2, cQ_gTP_2, segmComp_2, caloComp_2, isQValid3, isTValid3, isIsoValid3, GLnormChi2_mu3, GL_nValidMuHits3, trkLayersWMeas3, nValidPixelHits3, outerTrk_P_3, outerTrk_Eta_3, outerTrk_normChi2_3, outerTrk_muStValidHits_3, innerTrk_P_3, innerTrk_Eta_3, innerTrk_normChi2_3, QInnerOuter_3, cQ_uS_3, cQ_tK_3, cQ_gK_3, cQ_tRChi2_3, cQ_sRChi2_3, cQ_Chi2LP_3, cQ_Chi2LM_3, cQ_lD_3, cQ_gDEP_3, cQ_tM_3, cQ_gTP_3, segmComp_3, caloComp_3, match1_dX_1, match1_pullX_1, match1_pullDxDz_1, match1_dY_1, match1_pullY_1, match1_pullDyDz_1, match2_dX_1, match2_pullX_1, match2_pullDxDz_1, match2_dY_1, match2_pullY_1, match2_pullDyDz_1, match1_dX_2, match1_pullX_2, match1_pullDxDz_2, match1_dY_2, match1_pullY_2, match1_pullDyDz_2, match2_dX_2, match2_pullX_2, match2_pullDxDz_2, match2_dY_2, match2_pullY_2, match2_pullDyDz_2, match1_dX_3, match1_pullX_3, match1_pullDxDz_3, match1_dY_3, match1_pullY_3, match1_pullDyDz_3, match2_dX_3, match2_pullX_3, match2_pullDxDz_3, match2_dY_3, match2_pullY_3, match2_pullDyDz_3, innerTrk_highPurity_1, innerTrk_highPurity_2, innerTrk_highPurity_3, innerTrk_ValidFraction_1, innerTrk_ValidFraction_2, innerTrk_ValidFraction_3, nValidTrackerHits1, nValidTrackerHits2, nValidTrackerHits3, validMuonHitComb1, validMuonHitComb2, validMuonHitComb3)
    
        hCutEffEvt = ROOT.TH1I("CutEff_NEvents", "CutEff_NEvents", NCUTS, 0.5, (NCUTS+0.5))

        print(f"datasetName: {datasetName}\n")
        if("2022" in datasetName or "2023" in datasetName): isMC=0
        else: isMC=5
    

        for  jentry in range(nentries):
            ientry = self.fChain.LoadTree(jentry)
            if (ientry < 0): break
            self.fChain.GetTree().GetEntry(ientry)
            # if (Cut(ientry) < 0) continue;

            if (debugMode): print(f"\n++++Event n. {jentry}\n")
            triplEff_counter = []
            for i in range(NCUTS):
                triplEff_counter.append(False)
            run_n = self.run, lumi_n = self.lumi, evt_n = self.evt

            triplEff_counter[0] = True
            mu_good = []
            mu_Ind_good = []
            ind_good = -99
            for i in range(NMU):
                mu_good[i] = ind_good
                mu_Ind_good[i] = ind_good 
            goodTriplInd = []
      
            #CUT 0 : Before cuts - skip event if no good triplets
            if (self.NGoodTriplets[0] < 1):
                cutevt[0]+=1
                continue


            # CUT 1 : Check L1 & HLT decision
            L1_passed = False
            HLT_passed = False
            L1seed = 0
            HLTpath = 0
            L1_DoubleMu0_er1p5 = -99
            L1_DoubleMu0_er1p4= -99
            L1_DoubleMu4_dR1p2= -99
            L1_DoubleMu4p5_dR1p2= -99
            L1_DoubleMu0_er2p0= -99
            L1_DoubleMu0_er2p0_bk= -99
            for h in range(len(self.Trigger_l1name)):
                l1Name = self.Trigger_l1name[h]
                if ("L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4" in l1Name or "L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4" in l1Name or "L1_DoubleMu4_SQ_OS_dR_Max1p2" in l1Name or "L1_DoubleMu4p5_SQ_OS_dR_Max1p2" in l1Name or "L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p6" in l1Name or "L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p5" in l1Name ) and self.Trigger_l1decision[h] == 1:
                    L1_passed = True
                    if(debugMode): print("L1 passed\n")
                    if ("L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4" in l1Name and self.Trigger_l1decision[h] == 1):
                        L1seed+=1
                        L1_DoubleMu0_er1p5=1
                    if ("L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4" in l1Name and self.Trigger_l1decision[h] == 1): L1_DoubleMu0_er1p4=1
                    if ("L1_DoubleMu4_SQ_OS_dR_Max1p2" in l1Name and self.Trigger_l1decision[h] == 1):
                        L1seed+=10
                        L1_DoubleMu4_dR1p2=1
                    if ("L1_DoubleMu4p5_SQ_OS_dR_Max1p2" in l1Name and self.Trigger_l1decision[h] == 1): L1_DoubleMu4p5_dR1p2=1
                    if ("L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p6" in l1Name and self.Trigger_l1decision[h] == 1):
                        L1seed+=1000
                        L1_DoubleMu0_er2p0=1
                    if ("L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p5" in l1Name and self.Trigger_l1decision[h] == 1): L1_DoubleMu0_er2p0_bk=1

            if (L1_passed): 
                triplEff_counter[1] = True
                if (debugMode): print(f"L1seed: {L1seed}\n")
            else:
                cutevt[0]+=1
                continue
        
            # Check HLT
            for h in range(len(self.Trigger_hltname)):
                hltName = self.Trigger_hltname[h]
                if ("HLT_DoubleMu3_Trk_Tau3mu_v" in hltName and self.Trigger_hltdecision[h] == 1):
                #if( (hltName.Contains("HLT_DoubleMu3_Trk_Tau3mu_v") || hltName.Contains("HLT_DoubleMu4_3_LowMass") || hltName.Contains("HLT_DoubleMu4_LowMass_Displaced") ) && Trigger_hltdecision->at(h) == 1) {
                    HLT_passed = True
                    if ("HLT_DoubleMu3_Trk_Tau3mu_v" in hltName and self.Trigger_hltdecision[h] == 1): HLTpath += 1
                    if ("HLT_DoubleMu4_3_LowMass" in hltName and self.Trigger_hltdecision[h] == 1): HLTpath += 10
                    if ("HLT_DoubleMu4_LowMass_Displaced" in hltName and self.Trigger_hltdecision[h] == 1): HLTpath += 100
            if (HLT_passed): triplEff_counter[2] = True
            if (debugMode): print(f"HLT passed -> HLTpath = {HLTpath}\n")
        
            if not HLT_passed:
                for i in range(2):
                    if (debugMode): print(f"triplEff_counter[{i}] = {triplEff_counter[i]}\n")
                    if(triplEff_counter[i] == True):
                        cutevt[i]+=1
                        if(debugMode): print("It's true!")
                continue

            #Loop over the TRIPLETS
            for j in range(len(self.TripletVtx_Chi2)):
                goodTripl = False
                if (debugMode):print(f"\nTriplet n. {j}\n")
                pt = []
                eta=[]
                phi=[]
                mu=[]
                mu_Ind=[]
                for i in range(NMU):
                    pt.append(0)
                    eta.append(0)
                    phi.append(0)
                    mu.append(0)
                    mu_Ind.append(0)
                if (self.Tr_Pt[j] < 2): continue
                self.MatchIndex("ID", j, mu_Ind, mu)
                self.Get_MuonAndTrackVariables(mu_Ind, pt, eta, phi)
            
                # CUT 2 : 2 Glb & Medium mu
                good_muonID = False
                if (self.Muon_isGlobal[mu[0]] == 1 and self.Muon_isMedium[mu[0]] == 1 
                    and self.Muon_isGlobal[mu[1]] == 1 and self.Muon_isMedium[mu[1]] == 1 
                    and self.Mu01_Pt[j] >= 2 and self.Mu02_Pt[j] >= 2 
                    and abs(self.Mu01_Eta[j])<=2.4 and abs(self.Mu02_Eta[j])<=2.4 
                    and self.Tr_Pt[j] >= 2 and abs(self.Tr_Eta[j])<=2.4 
                    and (self.Track_dz[mu[2]]) < 20 and self.Track_dxy[mu[2]] <0.3): # check duplicates
                    #if(Muon_isMedium->at(mu[0]) == 1 && Muon_isMedium->at(mu[1]) == 1 && Mu01_Pt->at(j) >= 2 && Mu02_Pt->at(j) >= 2 && abs(Mu01_Eta->at(j))<=2.4 && abs(Mu02_Eta->at(j))<=2.4 && Tr_Pt->at(j) >= 2 && abs(Tr_Eta->at(j))<=2.4 && (Track_dz->at(mu[2]) < 20 && Track_dxy->at(mu[2]) <0.3)) { // check duplicates
                    isDupl = self.DuplicateFinder(self.Mu01_Eta[j], self.Mu02_Eta[j], self.Tr_Eta[j], self.Mu01_Phi[j], self.Mu02_Phi[j], self.Tr_Phi[j], self.Mu01_Pt[j], self.Mu02_Pt[j], self.Tr_Pt[j])
                    if (isDupl and self.FlightDistBS_SV_Significance[j] >= 3.5 ):
                        good_muonID = True
                        if(debugMode): print("goodMuonID\n")
                    if not good_muonID: continue
                    else: triplEff_counter[3] = True
            
                # CUT 3 : OS DiMu mass in [0.98-1.06]
                good_diMuMass = False
                DiMuMass = [0,0,0]
                DiMuMass[0] = self.DimuonMass(mu[0], mu[1]) # diMuMass 12
                if (DiMuMass[0]<=1.06 and DiMuMass[0]>=0.98): good_diMuMass = True
                if not good_diMuMass: continue
                else: triplEff_counter[4] = True
            
                # CUT 4 : TripletMass in [1.62-2] GeV
                good_triMuMass = False
                if (self.Triplet2_Mass[j]<=2.1 and self.Triplet2_Mass[j]>=1.62):
                    good_triMuMass = True 
                    if (debugMode): print("goodTriMuMass: {Triplet2_Mass[j]}\n")
                if not good_triMuMass: continue
                else: triplEff_counter[5] = True
            
                # CUT 5 : HLT Trigger Matching
                triggerMatch = [False, False]
                #vector<double> HLT_obj_pt, HLT_obj_eta, HLT_obj_phi;
                HLT_obj_pt = []
                HLT_obj_eta = []
                HLT_obj_phi = []

                if(HLTpath==1 or HLTpath==11 or HLTpath==101 or HLTpath==111):
                    for i in range(len(self.MuonPt_HLT2017)):
                        HLT_obj_pt.append(self.MuonPt_HLT2017[i])
                        HLT_obj_eta.append(self.MuonEta_HLT2017[i])
                        HLT_obj_phi.append(self.MuonPhi_HLT2017[i])
                else:
                    if(HLTpath>=100):
                        for i in range(len(self.MuonPt_HLT_DiMu_Incl_displ)):
                            HLT_obj_pt.append(self.MuonPt_HLT_DiMu_Incl_displ[i])
                            HLT_obj_eta.append(self.MuonEta_HLT_DiMu_Incl_displ[i])
                            HLT_obj_phi.append(self.MuonPhi_HLT_DiMu_Incl_displ[i])
                    else:
                        for i in range(len(self.MuonPt_HLT_DiMu_Incl)):
                            HLT_obj_pt.append(self.MuonPt_HLT_DiMu_Incl[i])
                            HLT_obj_eta.append(self.MuonEta_HLT_DiMu_Incl[i])
                            HLT_obj_phi.append(self.MuonPhi_HLT_DiMu_Incl[i])
        
            
                for f in range(2):
                    for i in range(len(self.HLT_obj_pt)):
                        dphi = abs(phi[f] - HLT_obj_phi[i])
                        deta = abs(eta[f] - HLT_obj_eta[i])
                        if (dphi > math.pi()): dphi -= 2*math.pi()
                        dR = math.sqrt(dphi*dphi + deta*deta)
                        dpt = abs(pt[f] - HLT_obj_pt[i])/pt[f]
                        if (dR<0.03 and dpt<0.1): triggerMatch[f] = True
                if(triggerMatch[0] == True): triplEff_counter[6] = True
                if(triggerMatch[0] == True and triggerMatch[1] == True):
                    triplEff_counter[7] = True
                    triplEff_counter[8] = True

                if (triggerMatch[0] != True or triggerMatch[1] != True): continue
                else:
                    if (debugMode): print("Good trigger Matching\n")
            
                if (good_muonID == True and good_diMuMass == True and good_triMuMass == True and triggerMatch[0] == True and triggerMatch[1] == True):
                    goodTripl = True
                    if (debugMode): 
                        print("Questo tripletto è buono!!!\n")
                        goodTriplInd.append(j)
                    for i in range(NMU):
                        mu_Ind_good[i] = mu_Ind[i]
                        mu_good[i] = mu[i]
                else:
                    if (debugMode): print("C'è un baco!!!\n")
        # end loop on triplet
        
            for i in range(NCUTS):
                if (debugMode): print(f"triplEff_counter[{i}] = {triplEff_counter[i]}")
                if (triplEff_counter[i] == True):
                    if (debugMode):
                        print("It's true!")
                        cutevt[i]+=1
        
            if (debugMode): print("Lista di tripletti buoni nell'evento: ")
            for i in range(len(goodTriplInd)):
                if (debugMode): print(goodTriplInd[i])
        
        
            if(len(goodTriplInd)>0):
                ind_good = self.BestTripletFinder(goodTriplInd)
                if(debugMode):
                    print(f"\nQuesto è il tripletto buono: {ind_good}\nN tripletti buoni: {len(goodTriplInd)}")
                    print("\nFound a good triplet\n")
                self.MatchIndex("ID", ind_good, mu_Ind_good, mu_good)
                self.TreeFin_Fill(tree, isMC, debugMode, ind_good, mu_Ind_good, mu_good, lumi_n, run_n, evt_n, pileupFactor, L1_DoubleMu0_er1p5, L1_DoubleMu0_er1p4, L1_DoubleMu4_dR1p2, L1_DoubleMu4p5_dR1p2, L1_DoubleMu0_er2p0, L1_DoubleMu0_er2p0_bk, L1seed, HLTpath, deltaR_max, deltaZ_max, Pmu3, cLP, tKink, segmComp, tripletMass, tripletMassReso, fv_nC, fv_dphi3D, fv_d3D, fv_d3Dsig, d0, nVtx, d0sig, MVA1, MVA2, MVA3, MVASoft1, MVASoft2, MVASoft3,  d0sig_max, mindca_iso, trkRel, Pmu1, Ptmu1, etamu1, phimu1, Pmu2, Ptmu2, etamu2, phimu2, Ptmu3, etamu3, phimu3, dispMu1, dispMu2, dispMu3, xydispMu1, xydispMu2, xydispMu3, P_trip, Pt_trip, eta_trip, nStationsMu1, nStationsMu2, nStationsMu3, Iso03Mu1, Iso03Mu2, Iso03Mu3, Iso05Mu1, Iso05Mu2, Iso05Mu3, nMatchesMu1, nMatchesMu2, nMatchesMu3, timeAtIpInOutMu_sig1, timeAtIpInOutMu_sig2, timeAtIpInOutMu_sig3, cQ_uS, cQ_tK, cQ_gK, cQ_tRChi2, cQ_sRChi2, cQ_Chi2LP, cQ_Chi2LM, cQ_lD, cQ_gDEP, cQ_tM, cQ_gTP, calEn_emMu1, calEn_emMu2, calEn_emMu3, calEn_hadMu1, calEn_hadMu2, calEn_hadMu3, caloComp, fliDistPVSV_Chi2, isMedium1, isMedium2, isGlb1, isTracker1, isLoose1,  isSoft1, isPF1, isRPC1, isSA1, isCalo1, isGlb2, isTracker2, isLoose2,  isSoft2, isPF2, isRPC2, isSA2, isCalo2, isGlb3, isTracker3, isLoose3,  isSoft3, isPF3, isRPC3, isSA3, isCalo3, vx1, vx2, vx3, vy1, vy2, vy3, vz1, vz2, vz3, Refvx1, Refvx2, Refvx3, Refvy1, Refvy2, Refvy3, Refvz1, Refvz2, Refvz3, SVx, SVy, SVz, had03, had05, nJets03, nJets05, nTracks03, nTracks05, sumPt03, sumPt05, hadVeto03, hadVeto05, emVeto03, emVeto05, trVeto03, trVeto05, EnMu1, EnMu2, EnMu3, ChargeMu1, ChargeMu2, ChargeMu3, isQValid1, isTValid1, isIsoValid1, GLnormChi2_mu1, GL_nValidMuHits1, trkLayersWMeas1, nValidPixelHits1, outerTrk_P_1, outerTrk_Eta_1, outerTrk_normChi2_1, outerTrk_muStValidHits_1, innerTrk_P_1, innerTrk_Eta_1, innerTrk_normChi2_1, QInnerOuter_1, cQ_uS_1, cQ_tK_1, cQ_gK_1, cQ_tRChi2_1, cQ_sRChi2_1, cQ_Chi2LP_1, cQ_Chi2LM_1, cQ_lD_1, cQ_gDEP_1, cQ_tM_1, cQ_gTP_1, segmComp_1, caloComp_1, isQValid2, isTValid2, isIsoValid2, GLnormChi2_mu2, GL_nValidMuHits2, trkLayersWMeas2, nValidPixelHits2, outerTrk_P_2, outerTrk_Eta_2, outerTrk_normChi2_2, outerTrk_muStValidHits_2, innerTrk_P_2, innerTrk_Eta_2, innerTrk_normChi2_2, QInnerOuter_2, cQ_uS_2, cQ_tK_2, cQ_gK_2, cQ_tRChi2_2, cQ_sRChi2_2, cQ_Chi2LP_2, cQ_Chi2LM_2, cQ_lD_2, cQ_gDEP_2, cQ_tM_2, cQ_gTP_2, segmComp_2, caloComp_2, isQValid3, isTValid3, isIsoValid3, GLnormChi2_mu3, GL_nValidMuHits3, trkLayersWMeas3, nValidPixelHits3, outerTrk_P_3, outerTrk_Eta_3, outerTrk_normChi2_3, outerTrk_muStValidHits_3, innerTrk_P_3, innerTrk_Eta_3, innerTrk_normChi2_3, QInnerOuter_3, cQ_uS_3, cQ_tK_3, cQ_gK_3, cQ_tRChi2_3, cQ_sRChi2_3, cQ_Chi2LP_3, cQ_Chi2LM_3, cQ_lD_3, cQ_gDEP_3, cQ_tM_3, cQ_gTP_3, segmComp_3, caloComp_3, match1_dX_1, match1_pullX_1, match1_pullDxDz_1, match1_dY_1, match1_pullY_1, match1_pullDyDz_1, match2_dX_1, match2_pullX_1, match2_pullDxDz_1, match2_dY_1, match2_pullY_1, match2_pullDyDz_1, match1_dX_2, match1_pullX_2, match1_pullDxDz_2, match1_dY_2, match1_pullY_2, match1_pullDyDz_2, match2_dX_2, match2_pullX_2, match2_pullDxDz_2, match2_dY_2, match2_pullY_2, match2_pullDyDz_2, match1_dX_3, match1_pullX_3, match1_pullDxDz_3, match1_dY_3, match1_pullY_3, match1_pullDyDz_3, match2_dX_3, match2_pullX_3, match2_pullDxDz_3, match2_dY_3, match2_pullY_3, match2_pullDyDz_3, innerTrk_highPurity_1, innerTrk_highPurity_2, innerTrk_highPurity_3, innerTrk_ValidFraction_1, innerTrk_ValidFraction_2, innerTrk_ValidFraction_3, nValidTrackerHits1, nValidTrackerHits2, nValidTrackerHits3, validMuonHitComb1, validMuonHitComb2, validMuonHitComb3)
    
        #Histo of cuts Efficiency
        canvEvt = ROOT.TCanvas("CutEfficiency_Nevents", "CutEfficiency_Nevents", 0, 0, 1200, 1000)
        self.Draw_CutEffCanvas(canvEvt, hCutEffEvt, cutevt, listCut)
    
        #Write and close the file
        fout.Write()
        fout.Close()

