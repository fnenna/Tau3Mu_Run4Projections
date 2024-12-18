NCUTS = 9
NMU = 3
    
def BestTripletFinder(df, triplIndex):
    bestChi2 = 15000000000000000
    index = 0
    for i in range(len(triplIndex)):
        if df.TripletVtx2_Chi2.iloc[0][triplIndex[i]] < bestChi2:
            bestChi2 = df.TripletVtx2_Chi2.iloc[0][triplIndex[i]]
            index = triplIndex[i]
    return index

def DimuonMass(df, mu_index1, mu_index2):
    inv = 0
    charge1 = df.MuonCharge.iloc[0][mu_index1]
    charge2 = df.MuonCharge.iloc[0][mu_index2]
    pt1 = df.MuonPt.iloc[0][mu_index1]
    pt2 = df.MuonPt.iloc[0][mu_index2]
    eta1 = df.MuonEta.iloc[0][mu_index1]
    eta2 = df.MuonEta.iloc[0][mu_index2]
    phi1 = df.MuonPhi.iloc[0][mu_index1]
    phi2 = df.MuonPhi.iloc[0][mu_index2]
    en1 = df.MuonEnergy.iloc[0][mu_index1]
    en2 = df.MuonEnergy.iloc[0][mu_index2]
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
        
def DuplicateFinder(df, eta1, eta2, etaTr, phi1, phi2, phiTr, pt1, pt2, ptTr):
    if ((abs(eta1-etaTr)>0.0001 and abs(eta2-etaTr)>0.0001 and abs(phi1-phiTr)>0.0001 and abs(phi2-phiTr)>0.0001 and abs(pt1-ptTr)>0.0001 and abs(pt2-ptTr)>0.0001) and (abs(eta1-eta2)>0.0001 and abs(phi1-phi2)>0.0001 and abs(pt1-pt2)>0.0001) ):
        return True
    else: 
        return False
        
def Fill_CutName(df, listCut):
    nameCut = ["BeforeCuts", "L1_fired", "HLT_fired", "MuonID", "DiMu_mass", "TriMu_mass", "mu1_TrMatch", "mu12_TrMatch", "mu123_TrMatch"]
    print(len(nameCut))
    print(NCUTS)
    if len(nameCut) != NCUTS: 
        print("length of the cut names does not match number of cuts")
        return
    for i in range(NCUTS):
        listCut.append(nameCut[i])
    
def Draw_CutEffCanvas(df, canv, hist, cut, listCut):
    print(cut)
    canv = ROOT.TCanvas("", "")
    canv.cd()
    for k in range(len(listCut)):
        hist.Fill(k+1, cut[k])
        hist.GetXaxis().SetBinLabel(k+1, listCut[k])
    hist.DrawCopy("HIST TEXT0")
    hist.Write()

'''  
def Get_MuonAndTrackVariables(df, mu_Ind)#, pt, eta, phi):
    pt = [df.Mu01_Pt.iloc[0][mu_Ind[0]], df.Mu02_Pt.iloc[0][mu_Ind[1]], df.Tr_Pt.iloc[0][mu_Ind[2]]]
    eta = [df.Mu01_Eta.iloc[0][mu_Ind[0]], df.Mu02_Eta.iloc[0][mu_Ind[1]], df.Tr_Eta.iloc[0][mu_Ind[2]]]
    phi = [df.Mu01_Phi.iloc[0][mu_Ind[0]], df.Mu02_Phi.iloc[0][mu_Ind[1]], df.Tr_Phi.iloc[0][mu_Ind[2]]]
    return pt, eta, phi
'''

def Get_MuonAndTrackVariables(df, mu_Ind)#, pt, eta, phi):
    pt = [df.Mu01_Pt.iloc[0][mu_Ind[0]], df.Mu02_Pt.iloc[0][mu_Ind[1]], df.Tr_Pt.iloc[0][mu_Ind[2]]]
    eta = [df.Mu01_Eta.iloc[0][mu_Ind[0]], df.Mu02_Eta.iloc[0][mu_Ind[1]], df.Tr_Eta.iloc[0][mu_Ind[2]]]
    phi = [df.Mu01_Phi.iloc[0][mu_Ind[0]], df.Mu02_Phi.iloc[0][mu_Ind[1]], df.Tr_Phi.iloc[0][mu_Ind[2]]]
    return pt, eta, phi

#def MatchIndex(df, type, ind, mu_Ind, mu):
def MatchIndex(df, type, ind):
    list_ind = [ind, ind, ind]
    '''
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
    '''
    pt, eta, phi = Get_MuonAndTrackVariables(df, ind)
    mu = []
    if type == "ID":
        for k in range(NMU-1):
            mu.append(MuonFinder(df, pt[k], eta[k], phi[k]))
        mu.append(TrackFinder(df, pt[2], eta[2], phi[2]))
    return mu

def MuonFinder(df, pt, eta, phi):
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
    badOuterChi2 = 0
    for g in range(len(df.MuonPt.iloc[0])):
        if (pt == df.MuonPt.iloc[0][g] and eta == df.MuonEta.iloc[0][g] and phi == df.MuonPhi.iloc[0][g]):
            n+=1
            m = g
            if(df.Muon_outerTrack_normalizedChi2.iloc[0][g] == -999):
                badOuterChi2+=1
        
    
    #MULTIPLE muons (There is more than 1 muon that matches the conditions)
    if n>1:
        
        ####### CASE 0: there aren't muons w/ outerTrachChi2 != -999
        if (n-badOuterChi2) == 0:
            Chi2InnerTrackmin = [0,0] # Chi2InnerTrackmin[1] is the value of Chi2; Chi2InnerTrackmin[0] is the corresponding index
            Chi2InnerTrackmin[1] = 999
            # find the muon w/ the smallest innerTrackChi2
            for k in range(len(df.MuonPt.iloc[0])):
                if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and df.Muon_innerTrack_normalizedChi2.iloc[0][k] < Chi2InnerTrackmin[1]):
                    Chi2InnerTrackmin[1] = df.Muon_innerTrack_normalizedChi2.iloc[0][k]
                    Chi2InnerTrackmin[0] = k
            nMuonChi2InnerMin = 0
            for k in range(len(df.MuonPt.iloc[0])):
                if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and Chi2InnerTrackmin[1] == df.Muon_innerTrack_normalizedChi2.iloc[0][k]):
                    nMuonChi2InnerMin+=1
            if (nMuonChi2InnerMin == 1):
                return Chi2InnerTrackmin[0]
            # find the mu w/ the biggest number of matches
            else:
                NumberOfMatches = [0,0] #like Chi2InnerTrackmin[]
                for k in range(len(df.MuonPt.iloc[0])):
                    if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and Chi2InnerTrackmin[1] == df.Muon_innerTrack_normalizedChi2.iloc[0][k]):
                        if (df.Muon_numberOfMatches.iloc[0][k] > NumberOfMatches[1]):
                            NumberOfMatches[1] = df.Muon_numberOfMatches.iloc[0][k]
                            NumberOfMatches[0] = k

            nMuonMatchesMax = 0
            for k in range(len(df.MuonPt)):
                if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and Chi2InnerTrackmin[1] == df.Muon_innerTrack_normalizedChi2.iloc[0][k] and NumberOfMatches[1] == df.Muon_numberOfMatches.iloc[0][k]):
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
            for k in range(len(df.MuonPt.iloc[0])):
                if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and df.Muon_outerTrack_normalizedChi2.iloc[0][k] != -999):
                    indexGoodMu = k
        
            if (indexGoodMu == -1):
                print("There is a BUG for sure !!!")

            return indexGoodMu
    
        ####### CASE 2:  // There is more than 1 muon w/ outerTrachChi2 != -999
        elif (n-badOuterChi2) > 1:
            Chi2OuterTrackmin = [0,0]
            Chi2OuterTrackmin[1] = 999
            # find the one w/ the smallest outerTrackChi2
            for k in range(len(df.MuonPt.iloc[0])):
                if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and df.Muon_outerTrack_normalizedChi2.iloc[0][k] < Chi2OuterTrackmin[1]):
                    Chi2OuterTrackmin[1] = df.Muon_outerTrack_normalizedChi2.iloc[0][k]
                    Chi2OuterTrackmin[0] = k
            nMuonChi2OuterMin = 0
            for k in range(len(df.MuonPt)):
                if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and Chi2OuterTrackmin[1] == df.Muon_outerTrack_normalizedChi2.iloc[0][k]):
                    nMuonChi2OuterMin+=1
            if(nMuonChi2OuterMin == 1):  return Chi2OuterTrackmin[0]
            # if outerTrackChi2 are equal
            else:
                # consider the one w/ the smallest innerTrackChi2
                Chi2InnerTrackmin = [0,0]
                Chi2InnerTrackmin[1] = 999
                for k in range(len(df.MuonPt.iloc[0])):
                    if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and df.Muon_outerTrack_normalizedChi2.iloc[0][k] == Chi2OuterTrackmin[1] and df.Muon_innerTrack_normalizedChi2.iloc[0][k] < Chi2InnerTrackmin[1]):
                        Chi2InnerTrackmin[1] = df.Muon_innerTrack_normalizedChi2.iloc[0][k]
                        Chi2InnerTrackmin[0] = k
            
                nMuonChi2InnerMin = 0
                for k in range(len(df.MuonPt.iloc[0])):
                    if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and df.Muon_outerTrack_normalizedChi2.iloc[0][k] == Chi2OuterTrackmin[1] and Chi2InnerTrackmin[1] == df.Muon_innerTrack_normalizedChi2.iloc[0][k]):
                        nMuonChi2InnerMin+=1
                if(nMuonChi2InnerMin == 1): return Chi2InnerTrackmin[0]
                # find the one w/ the biggest number of matches
                else:
                    NumberOfMatches = [0,0]
                    for k in range(len(df.MuonPt.iloc[0])):
                        if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and df.Muon_outerTrack_normalizedChi2.iloc[0][k] == Chi2OuterTrackmin[1] and Chi2InnerTrackmin[1] == df.Muon_innerTrack_normalizedChi2.iloc[0][k]):
                            if(df.Muon_numberOfMatches.iloc[0][k] > NumberOfMatches[1]):
                                NumberOfMatches[1] = df.Muon_numberOfMatches.iloc[0][k]
                                NumberOfMatches[0] = k
                    nMuonMatchesMax = 0
                    for k in range(len(df.MuonPt.iloc[0])):
                        if (pt == df.MuonPt.iloc[0][k] and eta == df.MuonEta.iloc[0][k] and phi == df.MuonPhi.iloc[0][k] and df.Muon_outerTrack_normalizedChi2.iloc[0][k] == Chi2OuterTrackmin[1] and Chi2InnerTrackmin[1] == df.Muon_innerTrack_normalizedChi2.iloc[0][k] and NumberOfMatches[1] == df.Muon_numberOfMatches.iloc[0][k]):
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

def MuonP(df, pt, eta, phi):
    muon = ROOT.TVector3()
    muon.SetPtEtaPhi(pt, eta, phi)
    return muon.Mag()

def TrackFinder(df, pt, eta, phi):
    n = 0
    m = 0
    badChi2 = 0
    for g in range(len(df.Track_pt.iloc[0])):
        if pt == df.Track_pt.iloc[0][g] and eta == df.Track_eta.iloc[0][g] and phi == df.Track_phi.iloc[0][g]:
            n += 1
            m = g
            if df.Track_normalizedChi2.iloc[0][g] == -999:
                badChi2 += 1
    if n>1: print("Error: There is more than 1 track that matches the conditions!")
    elif n == 0: print("Error: There is NOT a track that matches the condition!")
    return m

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
