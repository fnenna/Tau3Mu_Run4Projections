from python_myAnalizer_control_class import MyAnalizerControl
import math
import ROOT


NMU = 3
NCUTS = 9
mumass = 0.1056583715 # Muon mass in GeV
PhiMass = 1.019461 # Phi mass in GeV
sigmaPhiMass = 0.011 #sigma of Phi mass in GeV 
OmegaMass = 0.78265 # Omega mass in GeV
sigmaOmegaMass = 0.0085 #sigma of Omega mass in GeV
ptmin = 2.0

class Extended_MyAnalizerControl(MyAnalizerControl):

    def BestTripletFinder(self, triplIndex):
        bestChi2 = 15000000000000000
        index = 0
        for i in range(len(triplIndex)):
            if self.TripletVtx2_Chi2[(triplIndex[i])] < bestChi2:
                bestChi2 = self.TripletVtx2_Chi2[(triplIndex[i])]
                index = triplIndex[i]
        return index

    def DimuonMass(self, mu_index1, mu_index2):
        inv = 0
        charge1 = self.MuonCharge[mu_index1]
        charge2 = self.MuonCharge[mu_index2]
        pt1 = self.MuonPt[mu_index1]
        pt2 = self.MuonPt[mu_index2]
        eta1 = self.MuonEta[mu_index1]
        eta2 = self.MuonEta[mu_index2]
        phi1 = self.MuonPhi[mu_index1]
        phi2 = self.MuonPhi[mu_index2]
        en1 = self.MuonEnergy[mu_index1]
        en2 = self.MuonEnergy[mu_index2]
        total_charge = charge1 + charge2
        if total_charge != 0: return inv
        else:
            mu1 = ROOT.TLorentzVector()
            mu1.SetPtEtaPhiE(pt1, eta1, phi1, en1)
            mu2 = ROOT.TLorentzVector()
            mu2.SetPtEtaPhiE(pt2, eta2, phi2, en2)
            mutot = ROOT.TLorentzVector()
            mutot = mu1 + mu2
            return mutot.M()
        
    def DuplicateFinder(self, eta1, eta2, etaTr, phi1, phi2, phiTr, pt1, pt2, ptTr):
        if ((abs(eta1-etaTr)>0.0001 & abs(eta2-etaTr)>0.0001 & abs(phi1-phiTr)>0.0001 & abs(phi2-phiTr)>0.0001 & abs(pt1-ptTr)>0.0001 & abs(pt2-ptTr)>0.0001) & (abs(eta1-eta2)>0.0001 & abs(phi1-phi2)>0.0001 & abs(pt1-pt2)>0.0001) ):
            return True
        else: 
            return False
        
    def Fill_CutName(self, listCut):
        nameCut = ["BeforeCuts", "L1_fired", "HLT_fired", "MuonID", "DiMu_mass", "TriMu_mass", "mu1_TrMatch", "mu12_TrMatch", "mu123_TrMatch"]
        print(len(nameCut))
        print(NCUTS)
        if len(nameCut) != NCUTS: 
            print("length of the cut names does not match number of cuts")
            return
        for i in range(NCUTS):
            listCut.append(nameCut[i])
    
    def Draw_CutEffCanvas(self, canv, hist, cut, listCut):
        print(cut)
        for k in range(len(listCut)):
            hist.Fill(k+1, cut[k])
            hist.GetXaxis().SetBinLabel(k+1, listCut[k])
        hist.DrawCopy("HIST TEXT0")
        hist.Write()

    
    def Get_MuonAndTrackVariables(self, mu_Ind, pt, eta, phi):
        pt[0] = self.Mu01_Pt[mu_Ind[0]]
        pt[1] = self.Mu02_Pt[mu_Ind[1]]
        pt[2] = self.Tr_Pt[mu_Ind[2]]
        eta[0] = self.Mu01_Eta[mu_Ind[0]]
        eta[1] = self.Mu02_Eta[mu_Ind[1]]
        eta[2] = self.Tr_Eta[mu_Ind[2]]
        phi[0] = self.Mu01_Phi[mu_Ind[0]]
        phi[1] = self.Mu02_Phi[mu_Ind[1]]
        phi[2] = self.Tr_Phi[mu_Ind[2]]

    def MatchIndex(self, type, ind, mu_Ind, mu):
        mu_Ind[0] = ind
        mu_Ind[1] = ind
        mu_Ind[2] = ind
        if (mu_Ind[0] != ind or mu_Ind[1] != ind or mu_Ind[2] != ind):
            print("Error : Different triplet mu indices!")
        pt = []
        eta = []
        phi = []
        for i in range(NMU):
            pt.append(0)
            eta.append(0)
            phi.append(0)
        self.Get_MuonAndTrackVariables(mu_Ind, pt, eta, phi)
        if type == "ID":
            for k in range(NMU-1):
                mu[k] = self.MuonFinder(pt[k], eta[k], phi[k])
        mu[2] = self.TrackFinder(pt[2], eta[2], phi[2])

    def MuonFinder(self, pt, eta, phi):
        # Given the characteristics of a muon (pt, eta, phi), the function returns the index of the corresponding muon in the event
    
        # PRIORITY [in case there is more than 1 muon that matches the conditions]
    
        # *** if (there aren't muons w/ outerTrachChi2 != -999)    ## CASE 0 ##
        #      -> consider the one w/ the smallest innerTrackChi2
        #      -> if innerTrackChi2 are equal:
        #          -> consider the one w/ the biggest number of matches
        #           (if they are equal, print an error message and return the index of the last one)
        #
        # *** if (outerTrack != -999)                              ## CASE 1,2 ##
        #      -> consider the one w/ the smallest outerTrackChi2
        #      -> if outerTrackChi2 are equal:
        #          -> consider the one w/ the smallest innerTrackChi2
        #              -> consider the one w/ the biggest number of matches
        #                   (if they are equal, print an error message and return the index of the last one)
        n = 0
        m = 0
        BadOuterChi2 = 0
        for g in range(len(self.MuonPt)):
            if(pt == self.MuonPt[g] & eta == self.MuonEta[g] & phi == self.MuonPhi[g]):
                n+=1
                m = g
                if(self.Muon_outerTrack_normalizedChi2[g] == -999):
                    badOuterChi2+=1
        
    
        #MULTIPLE muons (There is more than 1 muon that matches the conditions)
        if n>1:
        
            ####### CASE 0: there aren't muons w/ outerTrachChi2 != -999
            if (n-badOuterChi2) == 0:
                Chi2InnerTrackmin = [0,0] # Chi2InnerTrackmin[1] is the value of Chi2; Chi2InnerTrackmin[0] is the corresponding index
                Chi2InnerTrackmin[1] = 999
                # find the muon w/ the smallest innerTrackChi2
                for k in range(len(self.MuonPt)):
                    if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & self.Muon_innerTrack_normalizedChi2[k] < Chi2InnerTrackmin[1]):
                        Chi2InnerTrackmin[1] = self.Muon_innerTrack_normalizedChi2[k];
                        Chi2InnerTrackmin[0] = k
                nMuonChi2InnerMin = 0
                for k in range(len(self.MuonPt)):
                    if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & Chi2InnerTrackmin[1] == self.Muon_innerTrack_normalizedChi2[k]):
                        nMuonChi2InnerMin+=1
                if (nMuonChi2InnerMin == 1):
                    return Chi2InnerTrackmin[0]
                # find the mu w/ the biggest number of matches
                else:
                    NumberOfMatches = [0,0] #like Chi2InnerTrackmin[]
                    for k in range(len(self.MuonPt)):
                        if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & Chi2InnerTrackmin[1] == self.Muon_innerTrack_normalizedChi2[k]):
                            if(self.Muon_numberOfMatches[k] > NumberOfMatches[1]):
                                NumberOfMatches[1] = self.Muon_numberOfMatches[k]
                                NumberOfMatches[0] = k

                nMuonMatchesMax = 0
                for k in range(len(self.MuonPt)):
                    if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & Chi2InnerTrackmin[1] == self.Muon_innerTrack_normalizedChi2[k] & NumberOfMatches[1] == self.Muon_numberOfMatches[k]):
                        nMuonMatchesMax+=1
                if (nMuonMatchesMax == 1):
                    return NumberOfMatches[0]
                # They are equal, therefore print an error message and return the index of the last one
                else:
                    print("Multiple muons with outerChi2 = -999! ")
                    return NumberOfMatches[0]
        
            ####### CASE 1:  // There is ONLY 1 muon that has outerTrachChi2 != -999
            elif ((n-badOuterChi2) == 1): 
                # Find this muon and return its index
                indexGoodMu = -1
                for k in range(len(self.MuonPt)):
                    if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & self.Muon_outerTrack_normalizedChi2[k] != -999):
                        indexGoodMu = k
            
                if (indexGoodMu == -1):
                    print("There is a BUG for sure !!!")

                return indexGoodMu
        
            ####### CASE 2:  // There is more than 1 muon w/ outerTrachChi2 != -999
            elif (n-badOuterChi2) > 1:
                Chi2OuterTrackmin = [0,0]
                Chi2OuterTrackmin[1] = 999
                # find the one w/ the smallest outerTrackChi2
                for k in range(len(self.MuonPt)):
                    if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & self.Muon_outerTrack_normalizedChi2[k] < Chi2OuterTrackmin[1]):
                        Chi2OuterTrackmin[1] = self.Muon_outerTrack_normalizedChi2[k]
                        Chi2OuterTrackmin[0] = k
                nMuonChi2OuterMin = 0
                for k in range(len(self.MuonPt)):
                    if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & Chi2OuterTrackmin[1] == self.Muon_outerTrack_normalizedChi2[k]):
                        nMuonChi2OuterMin+=1
                if(nMuonChi2OuterMin == 1):  return Chi2OuterTrackmin[0]
                # if outerTrackChi2 are equal
                else:
                    # consider the one w/ the smallest innerTrackChi2
                    Chi2InnerTrackmin = [0,0]
                    Chi2InnerTrackmin[1] = 999
                    for k in range(len(self.MuonPt)):
                        if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & self.Muon_outerTrack_normalizedChi2[k] == Chi2OuterTrackmin[1] & self.Muon_innerTrack_normalizedChi2[k] < Chi2InnerTrackmin[1]):
                            Chi2InnerTrackmin[1] = self.Muon_innerTrack_normalizedChi2[k]
                            Chi2InnerTrackmin[0] = k
                
                    nMuonChi2InnerMin = 0
                    for k in range(len(self.MuonPt)):
                        if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & self.Muon_outerTrack_normalizedChi2[k] == Chi2OuterTrackmin[1] & Chi2InnerTrackmin[1] == self.Muon_innerTrack_normalizedChi2[k]):
                            nMuonChi2InnerMin+=1
                    if(nMuonChi2InnerMin == 1): return Chi2InnerTrackmin[0]
                    # find the one w/ the biggest number of matches
                    else:
                        NumberOfMatches = [0,0]
                        for k in range(len(self.MuonPt)):
                            if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & self.Muon_outerTrack_normalizedChi2[k] == Chi2OuterTrackmin[1] & Chi2InnerTrackmin[1] == self.Muon_innerTrack_normalizedChi2[k]):
                                if(self.Muon_numberOfMatches[k] > NumberOfMatches[1]):
                                    NumberOfMatches[1] = self.Muon_numberOfMatches[k]
                                    NumberOfMatches[0] = k
                        nMuonMatchesMax = 0
                        for k in range(len(self.MuonPt)):
                            if (pt == self.MuonPt[k] & eta == self.MuonEta[k] & phi == self.MuonPhi[k] & self.Muon_outerTrack_normalizedChi2[k] == Chi2OuterTrackmin[1] & Chi2InnerTrackmin[1] == self.Muon_innerTrack_normalizedChi2[k] & NumberOfMatches[1] == self.Muon_numberOfMatches[k]):
                                nMuonMatchesMax+=1
                        if (nMuonMatchesMax == 1): return NumberOfMatches[0]
                        # They are equal, therefore print an error message and return the index of the last one
                        else:
                            print("Multiple muons with outerChi2 != -999! ")
                            return NumberOfMatches[0]
            else: # Error
                print("ERROR in multiple muon number!")
                return m
        # end multiple muons section
    
        else:
            return m
    
    def MuonP(self, pt, eta, phi):
        muon = ROOT.TVector3()
        muon.SetPtEtaPhi(pt, eta, phi)
        return muon.Mag()

    def TrackFinder(self, pt, eta, phi):
        n = 0
        m = 0
        badChi = 0
        for g in range(len(self.Track_pt)):
            if pt == self.Track_pt[g] & eta == self.Track_eta[g] & phi == self.Track_phi[g]:
                n += 1
                m = g
                if self.Track_normalizedChi2[g] == -999:
                    badChi2 += 1
        if n>1: print("Error: There is more than 1 track that matches the conditions!")
        elif n == 0: print("Error: There is NOT a track that matches the condition!")
        return m

    def TreeFin_Angle(self, ind):
        a_x = self.TripletVtx2_x[ind] - self.RefittedPV2_x[ind]
        a_y = self.TripletVtx2_y[ind] - self.RefittedPV2_y[ind]
        a_z = self.TripletVtx2_z[ind] - self.RefittedPV2_z[ind]
        b = ROOT.TVector3()
        b.SetPtEtaPhi(self.Triplet2_Pt[ind], self.Triplet2_Eta[ind],self.Triplet2_Phi[ind])
        b_x = b.Px()
        b_y = b.Py()
        b_z = b.Pz()
        a_mod = abs(self.FlightDistPVSV2[ind])
        b_mod = abs(b.Mag())
        cos_ang = ((a_x*b_x)+(a_y*b_y)+(a_z*b_z))/(a_mod*b_mod)
        angle = math.acos(min(max(cos_ang,-1.0),1.0))
        return angle
    
    def TreeFinFill(self, tree, isMC, debugMode, ind, mu_Ind, mu, lumi, run, evt, puFactor, L1_DoubleMu0_er1p5,
                    L1_DoubleMu0_er1p4, L1_DoubleMu4_dR1p2, L1_DoubleMu4p5_dR1p2, L1_DoubleMu0_er2p0, L1_DoubleMu0_er2p0_bk, L1seed, HLTpath, DeltaR_max,
                    DeltaZ_max, Pmu3, cLP, tKink, segmComp, tripletMass, tripletMassReso, fv_nC, fv_dphi3D, fv_d3D,  fv_d3Dsig, d0, nVtx, d0sig, MVA1, MVA2,
                    MVA3, MVASoft1, MVASoft2, MVASoft3, d0sig_max, mindca_iso, trkRel, Pmu1, Ptmu1, etamu1, phimu1, Pmu2, Ptmu2, etamu2, phimu2, Ptmu3, etamu3,
                    phimu3, dispMu1, dispMu2, dispMu3, xydispMu1, xydispMu2, xydispMu3, P_trip, Pt_trip, eta_trip, nStationsMu1, nStationsMu2, nStationsMu3, 
                    Iso03Mu1, Iso03Mu2, Iso03Mu3, Iso05Mu1, Iso05Mu2, Iso05Mu3, nMatchesMu1, nMatchesMu2, nMatchesMu3, timeAtIpInOut_sig1, timeAtIpInOut_sig2, 
                    timeAtIpInOut_sig3, cQ_uS, cQ_tK, cQ_gK, cQ_tRChi2, cQ_sRChi2, cQ_Chi2LP, cQ_Chi2LM, cQ_lD, cQ_gDEP, cQ_tM, cQ_gTP, calEn_emMu1, calEn_emMu2, 
                    calEn_emMu3, calEn_hadMu1, calEn_hadMu2, calEn_hadMu3, caloComp, fliDistPVSV_Chi2, isMedium1, isMedium2, isGlb1, isTracker1, isLoose1, isSoft1, 
                    isPF1, isRPC1, isSA1, isCalo1, isGlb2, isTracker2, isLoose2, isSoft2, isPF2, isRPC2, isSA2, isCalo2, isGlb3, isTracker3, isLoose3, isSoft3, isPF3, isRPC3, 
                    isSA3, isCalo3, Vx1, Vx2, Vx3, Vy1, Vy2, Vy3, Vz1, Vz2, Vz3, RefVx1, RefVx2, RefVx3, RefVy1, RefVy2, RefVy3, RefVz1, RefVz2, RefVz3, SVx, SVy, SVz, had03, 
                    had05, nJets03, nJets05, nTracks03, nTracks05, sumPt03, sumPt05, hadVeto03, hadVeto05, emVeto03, emVeto05, trVeto03, trVeto05, EnMu1, EnMu2, EnMu3, ChargeMu1, 
                    ChargeMu2, ChargeMu3, isQValid1, isTValid1, isIsoValid1, GLnormChi2_mu1, GL_nValidMuHits1, trkLayersWMeas1, nValidPixelHits1, outerTrk_P_1, outerTrk_Eta_1, 
                    outerTrk_normChi2_1, outerTrk_muStValidHits_1, innerTrk_P_1, innerTrk_Eta_1, innerTrk_normChi2_1, QInnerOuter_1, cQ_uS_1, cQ_tK_1, cQ_gK_1, cQ_tRChi2_1, cQ_sRChi2_1, 
                    cQ_Chi2LP_1, cQ_Chi2LM_1, cQ_lD_1, cQ_gDEP_1, cQ_tM_1, cQ_gTP_1, segmComp_1, caloComp_1, isQValid2, isTValid2, isIsoValid2, GLnormChi2_mu2, GL_nValidMuHits2,
                    trkLayersWMeas2, nValidPixelHits2, outerTrk_P_2, outerTrk_Eta_2, outerTrk_normChi2_2, outerTrk_muStValidHits_2, innerTrk_P_2, innerTrk_Eta_2, innerTrk_normChi2_2, QInnerOuter_2,
                    cQ_uS_2, cQ_tK_2, cQ_gK_2, cQ_tRChi2_2, cQ_sRChi2_2, cQ_Chi2LP_2, cQ_Chi2LM_2, cQ_lD_2, cQ_gDEP_2, cQ_tM_2, cQ_gTP_2, segmComp_2, caloComp_2, isQValid3, isTValid3, isIsoValid3,
                    GLnormChi2_mu3, GL_nValidMuHits3, trkLayersWMeas3, nValidPixelHits3, outerTrk_P_3, outerTrk_Eta_3, outerTrk_normChi2_3, outerTrk_muStValidHits_3, innerTrk_P_3, innerTrk_Eta_3, 
                    innerTrk_normChi2_3, QInnerOuter_3, cQ_uS_3, cQ_tK_3, cQ_gK_3, cQ_tRChi2_3, cQ_sRChi2_3, cQ_Chi2LP_3, cQ_Chi2LM_3, cQ_lD_3, cQ_gDEP_3, cQ_tM_3, 
                    cQ_gTP_3, segmComp_3, caloComp_3, match1_dX_1, match1_pullX_1, match1_pullDxDz_1, match1_dY_1, match1_pullY_1, match1_pullDyDz_1, match2_dX_1, match2_pullX_1, 
                    match2_pullDxDz_1, match2_dY_1, match2_pullY_1, match2_pullDyDz_1, match1_dX_2, match1_pullX_2, match1_pullDxDz_2, match1_dY_2, match1_pullY_2, match1_pullDyDz_2, match2_dX_2, 
                    match2_pullX_2, match2_pullDxDz_2, match2_dY_2, match2_pullY_2, match2_pullDyDz_2, match1_dX_3, match1_pullX_3, match1_pullDxDz_3, match1_dY_3, match1_pullY_3, match1_pullDyDz_3, match2_dX_3, 
                    match2_pullX_3, match2_pullDxDz_3, match2_dY_3, match2_pullY_3, match2_pullDyDz_3, innerTrk_highPurity_1, innerTrk_highPurity_2, innerTrk_highPurity_3, innerTrk_ValidFraction_1, innerTrk_ValidFraction_2, 
                    innerTrk_ValidFraction_3, nValidTrackerHits1, nValidTrackerHits2, nValidTrackerHits3, validMuonHitComb1, validMuonHitComb2, validMuonHitComb3):
        print("il baco è qui")
        if debugMode:
            print("Ciao1")
        self.MatchIndex("ID", ind, mu_Ind, mu)
        pt = []
        eta = []
        phi = []
        temp1 = []
        temp = []
        dR = []
        dZ = []
        for i in range(NMU):
            pt[i] = 0
            eta[i] = 0
            phi[i] = 0
            temp1[i] = 0
            temp[i] = 0
            dR[i] = 0
            dZ[i] = 0
        self.Get_MuonAndTrackVariables(mu_Ind, pt, eta, phi)
        Pmu3 = self.MuonP(pt[2], eta[2], phi[2])
        cLP = -999
        tKink = -999
        segmComp = 999
        DeltaR_max = -999
        DeltaZ_max = -999
        temp1[0] = self.dxy_mu1[mu_Ind[0]]
        temp1[1] = self.dxy_mu2[mu_Ind[1]]
        temp1[2] = self.dxy_mu3[mu_Ind[2]]
        dR[0] = math.sqrt(pow((eta[0]-eta[1]),2)+pow((phi[0]-phi[1]),2))
        dR[1] = math.sqrt(pow((eta[0]-eta[2]),2)+pow((phi[0]-phi[2]),2))
        dR[2] = math.sqrt(pow((eta[2]-eta[1]),2)+pow((phi[2]-phi[1]),2))
        dZ[0] = abs(self.Muon_vz[mu[0]] - self.Muon_vz[mu[1]] )
        dZ[1] = abs(self.Muon_vz[mu[0]] - self.Muon_vz[mu[2]] )
        dZ[2] = abs(self.Muon_vz[mu[2]]  - self.Muon_vz[mu[1]] )
        d0 = 999
        temp[0] = abs(self.dxy_mu1[mu_Ind[0]]/ self.dxyErr_mu1[mu_Ind[0]])
        temp[1] = abs(self.dxy_mu2[mu_Ind[1]]/ self.dxyErr_mu2[mu_Ind[1]])
        temp[2] = abs(self.dxy_mu3[mu_Ind[2]]/ self.dxyErr_mu3[mu_Ind[2]])
        d0sig = 999
        d0sig_max = -999
        if debugMode: print("Ciao2")
        for k in range(2):
            if (self.Muon_combinedQuality_chi2LocalPosition[mu[k]] > cLP): cLP = self.Muon_combinedQuality_chi2LocalPosition[mu[k]]
            if (self.Muon_combinedQuality_trkKink[mu[k]] > tKink): tKink = self.Muon_combinedQuality_trkKink[mu[k]]
            if (self.Muon_segmentCompatibility[mu[k]] < segmComp): segmComp = self.Muon_segmentCompatibility[mu[k]]
            if (temp1[k] < d0): d0 = temp1[k]
            if (temp[k] < d0sig): d0sig = temp[k]
            if (temp[k] > d0sig_max): d0sig_max = temp[k]
            if (dR[k] > DeltaR_max): DeltaR_max = dR[k]
            if (dZ[k] > DeltaZ_max): DeltaZ_max = dZ[k]
        
        if debugMode: print("Ciao3")

        if (isMC!=0): puFactor = self.nPileUpInt
        else: 
            puFactor = self.pileupFactor  
        tripletMass = self.Triplet2_Mass[ind]
        if (tripletMass>2.1 or tripletMass<1.62):
	        print(f"ECCO IL BACO !!!!\nTripletMass: {tripletMass}\nrun = {run} lumi = {lumi} evt = {evt}")
        #tripletMassReso = ResoTriplMass(mu_Ind, mu)
        fv_nC = self.TripletVtx2_Chi2[ind]/3
        fv_dphi3D = self.TreeFin_Angle(ind)
        fv_d3Dsig = self.FlightDistPVSV2_Significance[ind]
        fv_d3D = self.FlightDistPVSV2[ind]
        mindca_iso = self.Triplet_mindca_iso[ind]
        trkRel = self.Triplet_relativeiso[ind]
    
        if(debugMode): print("Ciao4")

        # Other variables
        # Single mu variables
        if (debugMode): print("Ciao5")
        Pmu1 = self.MuonP(self.Mu01_Pt[mu_Ind[0]], self.Mu01_Eta[mu_Ind[0]], self.Mu01_Phi[mu_Ind[0]])
        Ptmu1 = self.Mu01_Pt[mu_Ind[0]]
        etamu1 = self.Mu01_Eta[mu_Ind[0]]
        phimu1 = self.Mu01_Phi[mu_Ind[0]]
        Pmu2 = self.MuonP(self.Mu02_Pt[mu_Ind[1]], self.Mu02_Eta[mu_Ind[1]], self.Mu02_Phi[mu_Ind[1]])
        Ptmu2 = self.Mu02_Pt[mu_Ind[1]]
        etamu2 = self.Mu02_Eta[mu_Ind[1]]
        phimu2 = self.Mu02_Phi[mu_Ind[1]]
        Ptmu3 = self.Tr_Pt[mu_Ind[2]]
        etamu3 = self.Tr_Eta[mu_Ind[2]]
        phimu3 = self.Tr_Phi[(mu_Ind[2])]
    
        dispMu1 = math.sqrt(pow(self.BS_x[mu_Ind[0]] - self.Muon_vx[mu[0]],2) + pow(self.BS_y[mu_Ind[0]] - self.Muon_vy[mu[0]],2) + pow(self.BS_z[mu_Ind[0]] - self.Muon_vz[mu[0]],2))
        dispMu2 = math.sqrt(pow(self.BS_x[mu_Ind[1]] - self.Muon_vx[mu[1]],2) + pow(self.BS_y[mu_Ind[1]] - self.Muon_vy[mu[1]],2) + pow(self.BS_z[mu_Ind[1]] - self.Muon_vz[mu[1]],2))
        #dispMu3 = TMath::Sqrt(TMath::Power(BS_x->at(mu_Ind[2]) - Muon_vx->at(mu[2]),2) + TMath::Power(BS_y->at(mu_Ind[2]) - Muon_vy->at(mu[2]),2) + TMath::Power(BS_z->at(mu_Ind[2]) - Muon_vz->at(mu[1]),2));
        xydispMu1 = math.sqrt(pow(self.BS_x[mu_Ind[0]] - self.Muon_vx[mu[0]],2) + pow(self.BS_y[mu_Ind[0]] - self.Muon_vy[mu[0]],2))
        xydispMu2 = math.sqrt(pow(self.BS_x[mu_Ind[1]] - self.Muon_vx[mu[1]],2) + pow(self.BS_y[mu_Ind[1]] - self.Muon_vy[mu[1]],2))
        #xydispMu3 = TMath::Sqrt(TMath::Power(BS_x->at(mu_Ind[2]) - Muon_vx->at(mu[2]),2) + TMath::Power(BS_y->at(mu_Ind[2]) - Muon_vy->at(mu[2]),2));

        if (debugMode): print("Ciao5_bis")
        nStationsMu1 = self.Muon_numberOfMatchedStations[mu[0]]
        nStationsMu2 = self.Muon_numberOfMatchedStations[mu[1]]
        if(debugMode): print("Ciao5_bis2")
        Iso03Mu1 = self.Mu1_NTracks03iso[mu_Ind[0]]
        Iso03Mu2 = self.Mu2_NTracks03iso[mu_Ind[1]]
        Iso03Mu3 = self.Tr_NTracks03iso[mu_Ind[2]]
        Iso05Mu1 = self.Muon_emEt05[mu[0]]
        Iso05Mu2 = self.Muon_emEt05[mu[1]]
        #Iso05Mu3 = Muon_emEt05->at(mu[2]);
        if(debugMode): print("Ciao5_bis3")
        # Triplet variables
        P_trip = self.MuonP(self.Triplet2_Pt[ind], self.Triplet2_Eta[ind], self.Triplet2_Phi[ind])
        Pt_trip = self.Triplet2_Pt[ind]
        eta_trip = self.Triplet2_Eta[ind]
        if(debugMode): print("Ciao6")
        nMatchesMu1 = self.Muon_numberOfMatches[mu[0]]
        nMatchesMu2 = self.Muon_numberOfMatches[mu[1]]
        #nMatchesMu3 = Muon_numberOfMatches->at(mu[2]);
        timeAtIpInOut_sig1 = self.Muon_timeAtIpInOut[mu[0]]/ self.Muon_timeAtIpInOutErr[mu[0]]
        timeAtIpInOut_sig2 = self.Muon_timeAtIpInOut[mu[1]]/ self.Muon_timeAtIpInOutErr[mu[1]]
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
            if (self.Muon_combinedQuality_updatedSta[mu[k]] > cQ_uS): cQ_uS = self.Muon_combinedQuality_updatedSta[mu[k]]
            if (self.Muon_combinedQuality_trkKink[mu[k]] > cQ_tK): cQ_tK = self.Muon_combinedQuality_trkKink[mu[k]]
            if (self.Muon_combinedQuality_glbKink[mu[k]] > cQ_gK): cQ_gK = self.Muon_combinedQuality_glbKink[mu[k]]
            if (self.Muon_combinedQuality_trkRelChi2[mu[k]] > cQ_tRChi2): cQ_tRChi2 = self.Muon_combinedQuality_trkRelChi2[mu[k]]
            if (self.Muon_combinedQuality_staRelChi2[mu[k]] > cQ_sRChi2): cQ_sRChi2 = self.Muon_combinedQuality_staRelChi2[mu[k]]
            if (self.Muon_combinedQuality_chi2LocalPosition[mu[k]] > cQ_Chi2LP): cQ_Chi2LP = self.Muon_combinedQuality_chi2LocalPosition[mu[k]]
            if (self.Muon_combinedQuality_chi2LocalMomentum[mu[k]] > cQ_Chi2LM): cQ_Chi2LM = self.Muon_combinedQuality_chi2LocalMomentum[mu[k]]
            if (self.Muon_combinedQuality_localDistance[mu[k]] > cQ_lD): cQ_lD = self.Muon_combinedQuality_localDistance[mu[k]]
            if (self.Muon_combinedQuality_globalDeltaEtaPhi[mu[k]] > cQ_gDEP): cQ_gDEP = self.Muon_combinedQuality_globalDeltaEtaPhi[mu[k]]
            if (self.Muon_combinedQuality_tightMatch[mu[k]] > cQ_tM): cQ_tM = self.Muon_combinedQuality_tightMatch[mu[k]]
            if (self.Muon_combinedQuality_glbTrackProbability[mu[k]] > cQ_gTP): cQ_gTP = self.Muon_combinedQuality_glbTrackProbability[mu[k]]
            if (self.Muon_caloCompatibility[mu[k]] < caloComp): caloComp = self.Muon_caloCompatibility[mu[k]]
        calEn_emMu1 = self.Muon_calEnergy_em[mu[0]]
        calEn_emMu2 = self.Muon_calEnergy_em[mu[1]]
        #calEn_emMu3 = Muon_calEnergy_em->at(mu[2]);
        calEn_hadMu1 = self.Muon_calEnergy_had[mu[0]]
        calEn_hadMu2 = self.Muon_calEnergy_had[mu[1]]
        #calEn_hadMu3 = Muon_calEnergy_had->at(mu[2]);
        #fliDistPVSV_Chi2 = FlightDistPVSV_chi2->at(ind);
        if(debugMode): print("Ciao7")
        nVtx = self.PVCollection_Size
        ####muon ID
        isMedium1 = self.Muon_isMedium[mu[0]]
        isMedium2 = self.Muon_isMedium[mu[0]]
        isGlb1 = self.Muon_isGlobal[mu[0]]
        isTracker1 = self.Muon_isTrackerMuon[mu[0]]
        isLoose1 = self.Muon_isLoose[mu[0]]
        isSoft1 = self.Muon_isSoft[mu[0]]
        MVA1 = self.Muon_MVA[mu[0]]
        MVA2 = self.Muon_MVA[mu[1]]
        #MVA3 = Muon_MVA->at(mu[2]);
        MVA3 = 0.
        MVASoft1 = self.Muon_SoftMVA_Val[mu[0]]
        MVASoft2 = self.Muon_SoftMVA_Val[mu[1]]
        #MVASoft3 = Muon_SoftMVA_Val->at(mu[2]);
        MVASoft3 = 0.
        isPF1 = self.Muon_isPF[mu[0]]
        isRPC1 = self.Muon_isRPCMuon[mu[0]]
        isSA1 = self.Muon_isStandAloneMuon[mu[0]]
        isCalo1 = self.Muon_isCaloMuon[mu[0]]
        isGlb2 = self.Muon_isGlobal[mu[1]]
        isTracker2 = self.Muon_isTrackerMuon[mu[1]]
        isLoose2 = self.Muon_isLoose[mu[1]]
        isSoft2 = self.Muon_isSoft[mu[1]]
        isPF2 = self.Muon_isPF[mu[1]]
        isRPC2 = self.Muon_isRPCMuon[mu[1]]
        isSA2 = self.Muon_isStandAloneMuon[mu[1]]
        isCalo2 = self.Muon_isCaloMuon[mu[1]]
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
        if(debugMode): print("Ciao8")
        Vx1 = self.Muon_vx[mu[0]]
        Vx2 = self.Muon_vx[mu[1]]
        Vx3 = self.Track_vx[mu[2]]
        Vy1 = self.Muon_vy[mu[0]]
        Vy2 = self.Muon_vy[mu[1]]
        Vy3 = self.Track_vy[mu[2]]
        Vz1 = self.Muon_vz[mu[0]]
        Vz2 = self.Muon_vz[mu[1]]
        Vz3 = self.Track_vz[mu[2]]
        RefVx1 = self.RefittedPV2_x[ind]
        RefVy1 = self.RefittedPV2_y[ind]
        RefVz1 = self.RefittedPV2_z[ind]
        SVx = self.TripletVtx2_x[ind]
        SVy = self.TripletVtx2_y[ind]
        SVz = self.TripletVtx2_z[ind]
        #had03 = self.Muon_hadEt03->at(mu[2])
        #had05 = self.Muon_hadEt05->at(mu[2])
        #nJets03 = self.Muon_nJets03->at(mu[2])
        #nJets05 = self.Muon_nJets05->at(mu[2])
        #nTracks03 = self.Muon_nTracks03->at(mu[2])
        #nTracks05 = self.Muon_nTracks05->at(mu[2])
        #sumPt03 = self.Muon_sumPt03->at(mu[2])
        #sumPt05 = self.Muon_sumPt05->at(mu[2])
        #hadVeto03 = self.Muon_hadVetoEt03->at(mu[2])
        #hadVeto05 = self.Muon_hadVetoEt05->at(mu[2])
        #emVeto03 = self.Muon_emVetoEt03->at(mu[2])
        #emVeto05 = self.Muon_emVetoEt05->at(mu[2])
        #trVeto03 = self.Muon_trackerVetoPt03->at(mu[2])
        #trVeto05 = self.Muon_trackerVetoPt05->at(mu[2])
        #
        if(debugMode): print("Ciao9")
        EnMu1 = self.MuonEnergy[mu[0]]
        EnMu2 = self.MuonEnergy[mu[1]]
        #EnMu3 = self.MuonEnergy[mu[2]]
        ChargeMu1 = self.MuonCharge[mu[0]]
        ChargeMu2 = self.MuonCharge[mu[1]]
        ChargeMu3 = self.Track_charge[mu[2]]
        #
        # mu1
        if(debugMode): print("Ciao10")
        isQValid1 = self.Muon_isQualityValid[mu[0]]
        isTValid1 = self.Muon_isTimeValid[mu[0]]
        isIsoValid1 = self.Muon_isIsolationValid[mu[0]]
        GLnormChi2_mu1 = self.Muon_GLnormChi2[mu[0]]
        GL_nValidMuHits1 = self.Muon_GLhitPattern_numberOfValidMuonHits[mu[0]]
        trkLayersWMeas1 = self.Muon_trackerLayersWithMeasurement[mu[0]]
        validMuonHitComb1 = self.Muon_validMuonHitComb[mu[0]]
        nValidTrackerHits1 = self.Muon_Numberofvalidtrackerhits[mu[0]]
        nValidPixelHits1 = self.Muon_Numberofvalidpixelhits[mu[0]]
        outerTrk_P_1 = self.Muon_outerTrack_p[mu[0]]
        outerTrk_Eta_1 = self.Muon_outerTrack_eta[mu[0]]
        outerTrk_normChi2_1 = self.Muon_outerTrack_normalizedChi2[mu[0]]
        outerTrk_muStValidHits_1 = self.Muon_outerTrack_muonStationsWithValidHits[mu[0]]
        innerTrk_P_1 = self.Muon_innerTrack_p[mu[0]]
        innerTrk_Eta_1 = self.Muon_innerTrack_eta[mu[0]]
        innerTrk_normChi2_1 = self.Muon_innerTrack_normalizedChi2[mu[0]]
        innerTrk_highPurity_1 = self.Muon_innerTrack_highPurity[mu[0]]
        innerTrk_ValidFraction_1 = self.Muon_innerTrack_ValidFraction[mu[0]]
        QInnerOuter_1 = self.Muon_QInnerOuter[mu[0]]
        cQ_uS_1 = self.Muon_combinedQuality_updatedSta[mu[0]]
        cQ_tK_1 = self.Muon_combinedQuality_trkKink[mu[0]]
        cQ_gK_1 = self.Muon_combinedQuality_glbKink[mu[0]]
        cQ_tRChi2_1 = self.Muon_combinedQuality_trkRelChi2[mu[0]]
        cQ_sRChi2_1 = self.Muon_combinedQuality_staRelChi2[mu[0]]
        cQ_Chi2LP_1 = self.Muon_combinedQuality_chi2LocalPosition[mu[0]]
        cQ_Chi2LM_1 = self.Muon_combinedQuality_chi2LocalMomentum[mu[0]]
        cQ_lD_1 = self.Muon_combinedQuality_localDistance[mu[0]]
        cQ_gDEP_1 = self.Muon_combinedQuality_globalDeltaEtaPhi[mu[0]]
        cQ_tM_1 = self.Muon_combinedQuality_tightMatch[mu[0]]
        cQ_gTP_1 = self.Muon_combinedQuality_glbTrackProbability[mu[0]]
        segmComp_1 = self.Muon_segmentCompatibility[mu[0]]
        caloComp_1 = self.Muon_caloCompatibility[mu[0]]
        match1_dX_1 = self.Muon_combinedQuality_match1_dX[mu[0]]
        match1_pullX_1 = self.Muon_combinedQuality_match1_pullX[mu[0]]
        match1_pullDxDz_1 = self.Muon_combinedQuality_match1_pullDxDz[mu[0]]
        match1_dY_1 = self.Muon_combinedQuality_match1_dY[mu[0]]
        match1_pullY_1 = self.Muon_combinedQuality_match1_pullY[mu[0]]
        match1_pullDyDz_1 = self.Muon_combinedQuality_match1_pullDyDz[mu[0]]
        match2_dX_1 = self.Muon_combinedQuality_match2_dX[mu[0]]
        match2_pullX_1 = self.Muon_combinedQuality_match2_pullX[mu[0]]
        match2_pullDxDz_1 = self.Muon_combinedQuality_match2_pullDxDz[mu[0]]
        match2_dY_1 = self.Muon_combinedQuality_match2_dY[mu[0]]
        match2_pullY_1 = self.Muon_combinedQuality_match2_pullY[mu[0]]
        match2_pullDyDz_1 = self.Muon_combinedQuality_match2_pullDyDz[mu[0]]
        if(debugMode): print("Ciao11")
        # mu2
        isQValid2 = self.Muon_isQualityValid[mu[1]]
        isTValid2 = self.Muon_isTimeValid[mu[1]]
        isIsoValid2 = self.Muon_isIsolationValid[mu[1]]
        GLnormChi2_mu2 = self.Muon_GLnormChi2[mu[1]]
        GL_nValidMuHits2 = self.Muon_GLhitPattern_numberOfValidMuonHits[mu[1]]
        trkLayersWMeas2 = self.Muon_trackerLayersWithMeasurement[mu[1]]
        validMuonHitComb2 = self.Muon_validMuonHitComb[mu[1]]
        nValidTrackerHits2 = self.Muon_Numberofvalidtrackerhits[mu[1]]
        nValidPixelHits2 = self.Muon_Numberofvalidpixelhits[mu[1]]
        outerTrk_P_2 = self.Muon_outerTrack_p[mu[1]]
        outerTrk_Eta_2 = self.Muon_outerTrack_eta[mu[1]]
        outerTrk_normChi2_2 = self.Muon_outerTrack_normalizedChi2[mu[1]]
        outerTrk_muStValidHits_2 = self.Muon_outerTrack_muonStationsWithValidHits[mu[1]]
        innerTrk_P_2 = self.Muon_innerTrack_p[mu[1]]
        innerTrk_Eta_2 = self.Muon_innerTrack_eta[mu[1]]
        innerTrk_normChi2_2 = self.Muon_innerTrack_normalizedChi2[mu[1]]
        innerTrk_highPurity_2 = self.Muon_innerTrack_highPurity[mu[1]]
        innerTrk_ValidFraction_2 = self.Muon_innerTrack_ValidFraction[mu[1]]
        QInnerOuter_2 = self.Muon_QInnerOuter[mu[1]]
        cQ_uS_2 = self.Muon_combinedQuality_updatedSta[mu[1]]
        cQ_tK_2 = self.Muon_combinedQuality_trkKink[mu[1]]
        cQ_gK_2 = self.Muon_combinedQuality_glbKink[mu[1]]
        cQ_tRChi2_2 = self.Muon_combinedQuality_trkRelChi2[mu[1]]
        cQ_sRChi2_2 = self.Muon_combinedQuality_staRelChi2[mu[1]]
        cQ_Chi2LP_2 = self.Muon_combinedQuality_chi2LocalPosition[mu[1]]
        cQ_Chi2LM_2 = self.Muon_combinedQuality_chi2LocalMomentum[mu[1]]
        cQ_lD_2 = self.Muon_combinedQuality_localDistance[mu[1]]
        cQ_gDEP_2 = self.Muon_combinedQuality_globalDeltaEtaPhi[mu[1]]
        cQ_tM_2 = self.Muon_combinedQuality_tightMatch[mu[1]]
        cQ_gTP_2 = self.Muon_combinedQuality_glbTrackProbability[mu[1]]
        segmComp_2 = self.Muon_segmentCompatibility[mu[1]]
        caloComp_2 = self.Muon_caloCompatibility[mu[1]]
        match1_dX_2 = self.Muon_combinedQuality_match1_dX[mu[1]]
        match1_pullX_2 = self.Muon_combinedQuality_match1_pullX[mu[1]]
        match1_pullDxDz_2 = self.Muon_combinedQuality_match1_pullDxDz[mu[1]]
        match1_dY_2 = self.Muon_combinedQuality_match1_dY[mu[1]]
        match1_pullY_2 = self.Muon_combinedQuality_match1_pullY[mu[1]]
        match1_pullDyDz_2 = self.Muon_combinedQuality_match1_pullDyDz[mu[1]]
        match2_dX_2 = self.Muon_combinedQuality_match2_dX[mu[1]]
        match2_pullX_2 = self.Muon_combinedQuality_match2_pullX[mu[1]]
        match2_pullDxDz_2 = self.Muon_combinedQuality_match2_pullDxDz[mu[1]]
        match2_dY_2 = self.Muon_combinedQuality_match2_dY[mu[1]]
        match2_pullY_2 = self.Muon_combinedQuality_match2_pullY[mu[1]]
        match2_pullDyDz_2 = self.Muon_combinedQuality_match2_pullDyDz[mu[1]]
        if(debugMode): print("Ciao12")
        # mu3
        '''
        isQValid3 = self.Muon_isQualityValid[mu[2]]
        isTValid3 = self.Muon_isTimeValid[mu[2]]
        isIsoValid3 = self.Muon_isIsolationValid[mu[2]]
        GLnormChi2_mu3 = self.Muon_GLnormChi2[mu[2]]
        GL_nValidMuHits3 = self.Muon_GLhitPattern_numberOfValidMuonHits[mu[2]]
        trkLayersWMeas3 = self.Muon_trackerLayersWithMeasurement[mu[2]]
        nValidPixelHits3 = self.Muon_Numberofvalidpixelhits[mu[2]]
        outerTrk_P_3 = self.Muon_outerTrack_p[mu[2]]
        outerTrk_Eta_3 = self.Muon_outerTrack_eta[mu[2]]
        outerTrk_normChi2_3 = self.Muon_outerTrack_normalizedChi2[mu[2]]
        outerTrk_muStValidHits_3 = self.Muon_outerTrack_muonStationsWithValidHits[mu[2]]
        innerTrk_P_3 = self.Muon_innerTrack_p[mu[2]]
        innerTrk_Eta_3 = self.Muon_innerTrack_eta[mu[2]]
        innerTrk_normChi2_3 = self.Muon_innerTrack_normalizedChi2[mu[2]]
        QInnerOuter_3 = self.Muon_QInnerOuter[mu[2]]
        cQ_uS_3 = self.Muon_combinedQuality_updatedSta[mu[2]]
        cQ_tK_3 = self.Muon_combinedQuality_trkKink[mu[2]]
        cQ_gK_3 = self.Muon_combinedQuality_glbKink[mu[2]]
        cQ_tRChi2_3 = self.Muon_combinedQuality_trkRelChi2[mu[2]]
        cQ_sRChi2_3 = self.Muon_combinedQuality_staRelChi2[mu[2]]
        cQ_Chi2LP_3 = self.Muon_combinedQuality_chi2LocalPosition[mu[2]]
        cQ_Chi2LM_3 = self.Muon_combinedQuality_chi2LocalMomentum[mu[2]]
        cQ_lD_3 = self.Muon_combinedQuality_localDistance[mu[2]]
        cQ_gDEP_3 = self.Muon_combinedQuality_globalDeltaEtaPhi[mu[2]]
        cQ_tM_3 = self.Muon_combinedQuality_tightMatch[mu[2]]
        cQ_gTP_3 = self.Muon_combinedQuality_glbTrackProbability[mu[2]]
        segmComp_3 = self.Muon_segmentCompatibility[mu[2]]
        caloComp_3 = self.Muon_caloCompatibility[mu[2]]
        '''    
        if(debugMode): print("Ciao13")
        tree.Fill()

    def TreeFin_Init(self, tree, isMC, lumi, run, evt, puFactor, L1_DoubleMu0_er1p5,
                    L1_DoubleMu0_er1p4, L1_DoubleMu4_dR1p2, L1_DoubleMu4p5_dR1p2, L1_DoubleMu0_er2p0, L1_DoubleMu0_er2p0_bk, L1seed, HLTpath, DeltaR_max,
                    DeltaZ_max, Pmu3, cLP, tKink, segmComp, tripletMass, tripletMassReso, fv_nC, fv_dphi3D, fv_d3D,  fv_d3Dsig, d0, nVtx, d0sig, MVA1, MVA2,
                    MVA3, MVASoft1, MVASoft2, MVASoft3, d0sig_max, mindca_iso, trkRel, Pmu1, Ptmu1, etamu1, phimu1, Pmu2, Ptmu2, etamu2, phimu2, Ptmu3, etamu3,
                    phimu3, dispMu1, dispMu2, dispMu3, xydispMu1, xydispMu2, xydispMu3, P_trip, Pt_trip, eta_trip, nStationsMu1, nStationsMu2, nStationsMu3, 
                    Iso03Mu1, Iso03Mu2, Iso03Mu3, Iso05Mu1, Iso05Mu2, Iso05Mu3, nMatchesMu1, nMatchesMu2, nMatchesMu3, timeAtIpInOut_sig1, timeAtIpInOut_sig2, 
                    timeAtIpInOut_sig3, cQ_uS, cQ_tK, cQ_gK, cQ_tRChi2, cQ_sRChi2, cQ_Chi2LP, cQ_Chi2LM, cQ_lD, cQ_gDEP, cQ_tM, cQ_gTP, calEn_emMu1, calEn_emMu2, 
                    calEn_emMu3, calEn_hadMu1, calEn_hadMu2, calEn_hadMu3, caloComp, fliDistPVSV_Chi2, isMedium1, isMedium2, isGlb1, isTracker1, isLoose1, isSoft1, 
                    isPF1, isRPC1, isSA1, isCalo1, isGlb2, isTracker2, isLoose2, isSoft2, isPF2, isRPC2, isSA2, isCalo2, isGlb3, isTracker3, isLoose3, isSoft3, isPF3, isRPC3, 
                    isSA3, isCalo3, Vx1, Vx2, Vx3, Vy1, Vy2, Vy3, Vz1, Vz2, Vz3, RefVx1, RefVx2, RefVx3, RefVy1, RefVy2, RefVy3, RefVz1, RefVz2, RefVz3, SVx, SVy, SVz, had03, 
                    had05, nJets03, nJets05, nTracks03, nTracks05, sumPt03, sumPt05, hadVeto03, hadVeto05, emVeto03, emVeto05, trVeto03, trVeto05, EnMu1, EnMu2, EnMu3, ChargeMu1, 
                    ChargeMu2, ChargeMu3, isQValid1, isTValid1, isIsoValid1, GLnormChi2_mu1, GL_nValidMuHits1, trkLayersWMeas1, nValidPixelHits1, outerTrk_P_1, outerTrk_Eta_1, 
                    outerTrk_normChi2_1, outerTrk_muStValidHits_1, innerTrk_P_1, innerTrk_Eta_1, innerTrk_normChi2_1, QInnerOuter_1, cQ_uS_1, cQ_tK_1, cQ_gK_1, cQ_tRChi2_1, cQ_sRChi2_1, 
                    cQ_Chi2LP_1, cQ_Chi2LM_1, cQ_lD_1, cQ_gDEP_1, cQ_tM_1, cQ_gTP_1, segmComp_1, caloComp_1, isQValid2, isTValid2, isIsoValid2, GLnormChi2_mu2, GL_nValidMuHits2,
                    trkLayersWMeas2, nValidPixelHits2, outerTrk_P_2, outerTrk_Eta_2, outerTrk_normChi2_2, outerTrk_muStValidHits_2, innerTrk_P_2, innerTrk_Eta_2, innerTrk_normChi2_2, QInnerOuter_2,
                    cQ_uS_2, cQ_tK_2, cQ_gK_2, cQ_tRChi2_2, cQ_sRChi2_2, cQ_Chi2LP_2, cQ_Chi2LM_2, cQ_lD_2, cQ_gDEP_2, cQ_tM_2, cQ_gTP_2, segmComp_2, caloComp_2, isQValid3, isTValid3, isIsoValid3,
                    GLnormChi2_mu3, GL_nValidMuHits3, trkLayersWMeas3, nValidPixelHits3, outerTrk_P_3, outerTrk_Eta_3, outerTrk_normChi2_3, outerTrk_muStValidHits_3, innerTrk_P_3, innerTrk_Eta_3, 
                    innerTrk_normChi2_3, QInnerOuter_3, cQ_uS_3, cQ_tK_3, cQ_gK_3, cQ_tRChi2_3, cQ_sRChi2_3, cQ_Chi2LP_3, cQ_Chi2LM_3, cQ_lD_3, cQ_gDEP_3, cQ_tM_3, 
                    cQ_gTP_3, segmComp_3, caloComp_3, match1_dX_1, match1_pullX_1, match1_pullDxDz_1, match1_dY_1, match1_pullY_1, match1_pullDyDz_1, match2_dX_1, match2_pullX_1, 
                    match2_pullDxDz_1, match2_dY_1, match2_pullY_1, match2_pullDyDz_1, match1_dX_2, match1_pullX_2, match1_pullDxDz_2, match1_dY_2, match1_pullY_2, match1_pullDyDz_2, match2_dX_2, 
                    match2_pullX_2, match2_pullDxDz_2, match2_dY_2, match2_pullY_2, match2_pullDyDz_2, match1_dX_3, match1_pullX_3, match1_pullDxDz_3, match1_dY_3, match1_pullY_3, match1_pullDyDz_3, match2_dX_3, 
                    match2_pullX_3, match2_pullDxDz_3, match2_dY_3, match2_pullY_3, match2_pullDyDz_3, innerTrk_highPurity_1, innerTrk_highPurity_2, innerTrk_highPurity_3, innerTrk_ValidFraction_1, innerTrk_ValidFraction_2, 
                    innerTrk_ValidFraction_3, nValidTrackerHits1, nValidTrackerHits2, nValidTrackerHits3, validMuonHitComb1, validMuonHitComb2, validMuonHitComb3):
        df = ROOT.RDataFrame(tree)
        df["isMC"]= isMC
        df["lumi"]= lumi
        df["run"]= run
        df["evt"]= evt
        df["puFactor"]= puFactor
        df["L1_DoubleMu0_er1p5"]= L1_DoubleMu0_er1p5
        df["L1_DoubleMu0_er1p4"]= L1_DoubleMu0_er1p4
        df["L1_DoubleMu4_dR1p2"]= L1_DoubleMu4_dR1p2
        df["L1_DoubleMu4p5_dR1p2"]= L1_DoubleMu4p5_dR1p2
        df["L1_DoubleMu0_er2p0"]= L1_DoubleMu0_er2p0
        df["L1_DoubleMu0_er2p0_bk"]= L1_DoubleMu0_er2p0_bk
        df["L1seed"]= L1seed
        df["HLTpath"]= HLTpath
        df["DeltaR_max"]= DeltaR_max
        df["DeltaZ_max"]= DeltaZ_max
        df["Pmu3"]= Pmu3
        df["cLP"]= cLP
        df["tKink"]= tKink
        df["segmComp"]= segmComp
        df["tripletMass"]= tripletMass
        df["tripletMassReso"]= tripletMassReso
        df["fv_nC"]= fv_nC
        df["fv_dphi3D"]= fv_dphi3D
        df["fv_d3D"]= fv_d3D
        df["fv_d3Dsig"]= fv_d3Dsig
        df["d0"]= d0
        df["nVtx"]= nVtx
        df["d0sig"]= d0sig
        df["MVA1"]= MVA1
        df["MVA2"]= MVA2
        df["MVA3"]= MVA3
        df["MVASoft1"]= MVASoft1
        df["MVASoft2"]= MVASoft2
        df["MVASoft3"]= MVASoft3
        df["d0sig_max"]= d0sig_max
        df["mindca_iso"]= mindca_iso
        df["trkRel"]= trkRel
        df["Pmu1"]= Pmu1
        df["Ptmu1"]= Ptmu1
        df["Etamu1"]= etamu1
        df["Phimu1"]= phimu1
        df["Pmu2"]= Pmu2
        df["Ptmu2"]= Ptmu2
        df["Etamu2"]= etamu2
        df["Phimu2"]= phimu2
        df["Ptmu3"]= Ptmu3
        df["Etamu3"]= etamu3
        df["Phimu3"]= phimu3

        df["dispMu1"]= dispMu1
        df["dispMu2"]= dispMu2
        df["dispMu3"]= dispMu3
        df["xydispMu1"]= xydispMu1
        df["xydispMu2"]= xydispMu2
        df["xydispMu3"]= xydispMu3

        df["P_tripl"]= P_trip
        df["Pt_tripl"]= Pt_trip
        df["Eta_tripl"]= eta_trip
        df["nStMu1"]= nStationsMu1
        df["nStMu2"]= nStationsMu2
        df["nStMu3"]= nStationsMu3
        df["Iso03Mu1"]= Iso03Mu1
        df["Iso03Mu2"]= Iso03Mu2
        df["Iso03Mu3"]= Iso03Mu3
        df["Iso05Mu1"]= Iso05Mu1
        df["Iso05Mu2"]= Iso05Mu2
        df["Iso05Mu3"]= Iso05Mu3
        df["nMatchesMu1"]= nMatchesMu1
        df["nMatchesMu2"]= nMatchesMu2
        df["nMatchesMu3"]= nMatchesMu3
        df["timeAtIpInOut_sig1"]= timeAtIpInOut_sig1
        df["timeAtIpInOut_sig2"]= timeAtIpInOut_sig2
        df["timeAtIpInOut_sig3"]= timeAtIpInOut_sig3
        df["cQ_uS"]= cQ_uS
        df["cQ_tK"]= cQ_tK
        df["cQ_gK"]= cQ_gK
        df["cQ_tRChi2"]= cQ_tRChi2
        df["cQ_sRChi2"]= cQ_sRChi2
        df["cQ_Chi2LP"]= cQ_Chi2LP
        df["cQ_Chi2LM"]= cQ_Chi2LM
        df["cQ_lD"]= cQ_lD
        df["cQ_gDEP"]= cQ_gDEP
        df["cQ_tM"]= cQ_tM
        df["cQ_gTP"]= cQ_gTP
        df["calEn_emMu1"]= calEn_emMu1
        df["calEn_emMu2"]= calEn_emMu2
        df["calEn_emMu3"]= calEn_emMu3
        df["calEn_hadMu1"]= calEn_hadMu1
        df["calEn_hadMu2"]= calEn_hadMu2
        df["calEn_hadMu3"]= calEn_hadMu3
        df["caloComp"]= caloComp
        df["fliDistPVSV_Chi2"]= fliDistPVSV_Chi2
        df["isGlb1"]= isGlb1
        df["isMedium1"]= isMedium1
        df["isMedium2"]= isMedium2
        df["isTracker1"]= isTracker1
        df["isLoose1"]= isLoose1
        df["isSoft1"]= isSoft1
        df["isPF1"]= isPF1
        df["isRPC1"]= isRPC1
        df["isSA1"]= isSA1
        df["isCalo1"]= isCalo1
        df["isGlb2"]= isGlb2
        df["isTracker2"]= isTracker2
        df["isLoose2"]= isLoose2
        df["isSoft2"]= isSoft2
        df["isPF2"]= isPF2
        df["isRPC2"]= isRPC2
        df["isSA2"]= isSA2
        df["isCalo2"]= isCalo2
        df["isGlb3"]= isGlb3
        df["isTracker3"]= isTracker3
        df["isLoose3"]= isLoose3
        df["isSoft3"]= isSoft3
        df["isPF3"]= isPF3
        df["isRPC3"]= isRPC3
        df["isSA3"]= isSA3
        df["isCalo3"]= isCalo3
        df["Vx1"]= Vx1
        df["Vx2"]= Vx2
        df["Vx3"]= Vx3
        df["Vy1"]= Vy1
        df["Vy2"]= Vy2
        df["Vy3"]= Vy3
        df["Vz1"]= Vz1
        df["Vz2"]= Vz2
        df["Vz3"]= Vz3
        df["RefVx1"]= RefVx1
        df["RefVx2"]= RefVx2
        df["RefVx3"]= RefVx3
        df["RefVy1"]= RefVy1
        df["RefVy2"]= RefVy2
        df["RefVy3"]= RefVy3
        df["RefVz1"]= RefVz1
        df["RefVz2"]= RefVz2
        df["RefVz3"]= RefVz3
        df["SVx"]= SVx
        df["SVy"]= SVy
        df["SVz"]= SVz
        df["had03"]= had03
        df["had05"]= had05
        df["nJets03"]= nJets03
        df["nJets05"]= nJets05
        df["nTracks03"]= nTracks03
        df["nTracks05"]= nTracks05
        df["sumPt03"]= sumPt03
        df["sumPt05"]= sumPt05
        df["hadVeto03"]= hadVeto03
        df["hadVeto05"]= hadVeto05
        df["emVeto03"]= emVeto03
        df["emVeto05"]= emVeto05
        df["trVeto03"]= trVeto03
        df["trVeto05"]= trVeto05
        
        # new branches
        df["EnMu1"]= EnMu1
        df["EnMu2"]= EnMu2
        df["EnMu3"]= EnMu3
        df["ChargeMu1"]= ChargeMu1
        df["ChargeMu2"]= ChargeMu2
        df["ChargeMu3"]= ChargeMu3
        # Mu1
        df["isQValid1"]= isQValid1
        df["isTValid1"]= isTValid1
        df["isIsoValid1"]= isIsoValid1
        df["GLnormChi2_mu1"]= GLnormChi2_mu1
        df["GL_nValidMuHits1"]= GL_nValidMuHits1
        df["trkLayersWMeas1"]= trkLayersWMeas1
        df["validMuonHitComb1"]= validMuonHitComb1
        df["nValidTrackerHits1"]= nValidTrackerHits1
        df["nValidPixelHits1"]= nValidPixelHits1
        df["outerTrk_P_1"]= outerTrk_P_1
        df["outerTrk_Eta_1"]= outerTrk_Eta_1
        df["outerTrk_normChi2_1"]= outerTrk_normChi2_1
        df["outerTrk_muStValidHits_1"]= outerTrk_muStValidHits_1
        df["innerTrk_P_1"]= innerTrk_P_1
        df["innerTrk_Eta_1"]= innerTrk_Eta_1
        df["innerTrk_normChi2_1"]= innerTrk_normChi2_1
        df["innerTrk_highPurity_1"]= innerTrk_highPurity_1
        df["innerTrk_ValidFraction_1"]= innerTrk_ValidFraction_1
        df["QInnerOuter_1"]= QInnerOuter_1
        df["cQ_uS_1"]= cQ_uS_1
        df["cQ_tK_1"]= cQ_tK_1
        df["cQ_gK_1"]= cQ_gK_1
        df["cQ_tRChi2_1"]= cQ_tRChi2_1
        df["cQ_sRChi2_1"]= cQ_sRChi2_1
        df["cQ_Chi2LP_1"]= cQ_Chi2LP_1
        df["cQ_Chi2LM_1"]= cQ_Chi2LM_1
        df["cQ_lD_1"]= cQ_lD_1
        df["cQ_gDEP_1"]= cQ_gDEP_1
        df["cQ_tM_1"]= cQ_tM_1
        df["cQ_gTP_1"]= cQ_gTP_1
        df["segmComp_1"]= segmComp_1
        df["caloComp_1"]= caloComp_1
        df["match1_dX_1"]= match1_dX_1
        df["match1_pullX_1"]= match1_pullX_1
        df["match1_pullDxDz_1"]= match1_pullDxDz_1
        df["match1_dY_1"]= match1_dY_1
        df["match1_pullY_1"]= match1_pullY_1
        df["match1_pullDyDz_1"]= match1_pullDyDz_1
        df["match2_dX_1"]= match2_dX_1
        df["match2_pullX_1"]= match2_pullX_1
        df["match2_pullDxDz_1"]= match2_pullDxDz_1
        df["match2_dY_1"]= match2_dY_1
        df["match2_pullY_1"]= match2_pullY_1
        df["match2_pullDyDz_1"]= match2_pullDyDz_1
        # Mu2
        df["isQValid2"]= isQValid2
        df["isTValid2"]= isTValid2
        df["isIsoValid2"]= isIsoValid2
        df["GLnormChi2_mu2"]= GLnormChi2_mu2
        df["GL_nValidMuHits2"]= GL_nValidMuHits2
        df["trkLayersWMeas2"]= trkLayersWMeas2
        df["validMuonHitComb2"]= validMuonHitComb2
        df["nValidTrackerHits2"]= nValidTrackerHits2
        df["nValidPixelHits2"]= nValidPixelHits2
        df["outerTrk_P_2"]= outerTrk_P_2
        df["outerTrk_Eta_2"]= outerTrk_Eta_2
        df["outerTrk_normChi2_2"]= outerTrk_normChi2_2
        df["outerTrk_muStValidHits_2"]= outerTrk_muStValidHits_2
        df["innerTrk_P_2"]= innerTrk_P_2
        df["innerTrk_Eta_2"]= innerTrk_Eta_2
        df["innerTrk_normChi2_2"]= innerTrk_normChi2_2
        df["innerTrk_highPurity_2"]= innerTrk_highPurity_2
        df["innerTrk_ValidFraction_2"]= innerTrk_ValidFraction_2
        df["QInnerOuter_2"]= QInnerOuter_2
        df["cQ_uS_2"]= cQ_uS_2
        df["cQ_tK_2"]= cQ_tK_2
        df["cQ_gK_2"]= cQ_gK_2
        df["cQ_tRChi2_2"]= cQ_tRChi2_2
        df["cQ_sRChi2_2"]= cQ_sRChi2_2
        df["cQ_Chi2LP_2"]= cQ_Chi2LP_2
        df["cQ_Chi2LM_2"]= cQ_Chi2LM_2
        df["cQ_lD_2"]= cQ_lD_2
        df["cQ_gDEP_2"]= cQ_gDEP_2
        df["cQ_tM_2"]= cQ_tM_2
        df["cQ_gTP_2"]= cQ_gTP_2
        df["segmComp_2"]= segmComp_2
        df["caloComp_2"]= caloComp_2
        df["match1_dX_2"]= match1_dX_2
        df["match1_pullX_2"]= match1_pullX_2
        df["match1_pullDxDz_2"]= match1_pullDxDz_2
        df["match1_dY_2"]= match1_dY_2
        df["match1_pullY_2"]= match1_pullY_2
        df["match1_pullDyDz_2"]= match1_pullDyDz_2
        df["match2_dX_2"]= match2_dX_2
        df["match2_pullX_2"]= match2_pullX_2
        df["match2_pullDxDz_2"]= match2_pullDxDz_2
        df["match2_dY_2"]= match2_dY_2
        df["match2_pullY_2"]= match2_pullY_2
        df["match2_pullDyDz_2"]= match2_pullDyDz_2
        # Mu3
        df["isQValid3"]= isQValid3
        df["isTValid3"]= isTValid3
        df["isIsoValid3"]= isIsoValid3
        df["GLnormChi2_mu3"]= GLnormChi2_mu3
        df["GL_nValidMuHits3"]= GL_nValidMuHits3
        df["trkLayersWMeas3"]= trkLayersWMeas3
        df["validMuonHitComb3"]= validMuonHitComb3
        df["nValidTrackerHits3"]= nValidTrackerHits3
        df["nValidPixelHits3"]= nValidPixelHits3
        df["outerTrk_P_3"]= outerTrk_P_3
        df["outerTrk_Eta_3"]= outerTrk_Eta_3
        df["outerTrk_normChi2_3"]= outerTrk_normChi2_3
        df["outerTrk_muStValidHits_3"]= outerTrk_muStValidHits_3
        df["innerTrk_P_3"]= innerTrk_P_3
        df["innerTrk_Eta_3"]= innerTrk_Eta_3
        df["innerTrk_normChi2_3"]= innerTrk_normChi2_3
        df["innerTrk_highPurity_3"]= innerTrk_highPurity_3
        df["innerTrk_ValidFraction_3"]= innerTrk_ValidFraction_3
        df["QInnerOuter_3"]= QInnerOuter_3
        df["cQ_uS_3"]= cQ_uS_3
        df["cQ_tK_3"]= cQ_tK_3
        df["cQ_gK_3"]= cQ_gK_3
        df["cQ_tRChi2_3"]= cQ_tRChi2_3
        df["cQ_sRChi2_3"]= cQ_sRChi2_3
        df["cQ_Chi2LP_3"]= cQ_Chi2LP_3
        df["cQ_Chi2LM_3"]= cQ_Chi2LM_3
        df["cQ_lD_3"]= cQ_lD_3
        df["cQ_gDEP_3"]= cQ_gDEP_3
        df["cQ_tM_3"]= cQ_tM_3
        df["cQ_gTP_3"]= cQ_gTP_3
        df["segmComp_3"]= segmComp_3
        df["caloComp_3"]= caloComp_3
        df["match1_dX_3"]= match1_dX_3
        df["match1_pullX_3"]= match1_pullX_3
        df["match1_pullDxDz_3"]= match1_pullDxDz_3
        df["match1_dY_3"]= match1_dY_3
        df["match1_pullY_3"]= match1_pullY_3
        df["match1_pullDyDz_3"]= match1_pullDyDz_3
        df["match2_dX_3"]= match2_dX_3
        df["match2_pullX_3"]= match2_pullX_3
        df["match2_pullDxDz_3"]= match2_pullDxDz_3
        df["match2_dY_3"]= match2_dY_3
        df["match2_pullY_3"]= match2_pullY_3
        df["match2_pullDyDz_3"]= match2_pullDyDz_3
        df.Snapshot("FinalTree", "output_file.root")
        tree = ROOT.TTree("output_file.root")

        
        