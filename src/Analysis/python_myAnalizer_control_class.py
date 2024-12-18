import ROOT

class MyAnalizerControl:
    #poichè voglio utilizzare pyroot al posto di un TTree utilizzerei un RDataFrame
    #line 655
    def __init__(self, tree, fname):
        self.filename = fname
        self.evt = 0
        self.lumi = 0
        self.run = 0
        # dynamic variables
        self.NGoodTriplets = 0 
        self.Trigger_l1name = 0 
        self.Trigger_l1decision = 0 
        self.Trigger_l1prescale = 0 
        self.Trigger_hltname = 0 
        self.Trigger_hltdecision = 0 
        self.GenParticle_PdgId = 0 
        self.GenParticle_Pt = 0 
        self.GenParticle_Eta = 0 
        self.GenParticle_Phi = 0 
        self.GenParticle_isDs = 0 
        self.GenParticle_isB = 0 
        self.GenParticle_isBdecay = 0 
        self.GenParticle_MotherPdgId = 0 
        self.MuonPt = 0 
        self.MuonEnergy = 0 
        self.MuonCharge = 0 
        self.MuonEta = 0 
        self.MuonPhi = 0 
        self.Muon_PdgId = 0 
        self.Muon_MotherPdgId = 0 
        self.Muon_simFlavour = 0 
        self.Muon_vx = 0 
        self.Muon_vy = 0 
        self.Muon_vz = 0 
        self.Muon_isGlobal = 0 
        self.Muon_isSoft = 0 
        self.Muon_MVA = 0 
        self.Muon_SoftMVA_Val = 0 
        self.Muon_isLoose = 0 
        self.Muon_isMedium = 0 
        self.Muon_isPF = 0 
        self.Muon_isRPCMuon = 0 
        self.Muon_isStandAloneMuon = 0 
        self.Muon_isTrackerMuon = 0 
        self.Muon_isCaloMuon = 0 
        self.Muon_isQualityValid = 0 
        self.Muon_isTimeValid = 0 
        self.Muon_isIsolationValid = 0 
        self.Muon_numberOfMatchedStations = 0 
        self.Muon_numberOfMatches = 0 
        self.Muon_timeAtIpInOut = 0 
        self.Muon_timeAtIpInOutErr = 0 
        self.Muon_GLnormChi2 = 0 
        self.Muon_GLhitPattern_numberOfValidMuonHits = 0 
        self.Muon_trackerLayersWithMeasurement = 0 
        self.Muon_Numberofvalidpixelhits = 0 
        self.Muon_outerTrack_p = 0 
        self.Muon_outerTrack_eta = 0 
        self.Muon_outerTrack_phi = 0 
        self.Muon_outerTrack_normalizedChi2 = 0 
        self.Muon_outerTrack_muonStationsWithValidHits = 0 
        self.Muon_innerTrack_p = 0 
        self.Muon_innerTrack_eta = 0 
        self.Muon_innerTrack_phi = 0 
        self.Muon_innerTrack_normalizedChi2 = 0 
        self.Muon_QInnerOuter = 0 
        self.Muon_combinedQuality_updatedSta = 0 
        self.Muon_combinedQuality_trkKink = 0 
        self.Muon_combinedQuality_glbKink = 0 
        self.Muon_combinedQuality_trkRelChi2 = 0 
        self.Muon_combinedQuality_staRelChi2 = 0 
        self.Muon_combinedQuality_chi2LocalPosition = 0 
        self.Muon_combinedQuality_chi2LocalMomentum = 0 
        self.Muon_combinedQuality_localDistance = 0 
        self.Muon_combinedQuality_globalDeltaEtaPhi = 0 
        self.Muon_combinedQuality_tightMatch = 0 
        self.Muon_combinedQuality_glbTrackProbability = 0 
        self.Muon_calEnergy_em = 0 
        self.Muon_calEnergy_emS9 = 0 
        self.Muon_calEnergy_emS25 = 0 
        self.Muon_calEnergy_had = 0 
        self.Muon_calEnergy_hadS9 = 0 
        self.Muon_segmentCompatibility = 0 
        self.Muon_caloCompatibility = 0 
        self.Muon_ptErrOverPt = 0 
        self.Muon_BestTrackPt = 0 
        self.Muon_BestTrackPtErr = 0 
        self.Muon_BestTrackEta = 0 
        self.Muon_BestTrackEtaErr = 0 
        self.Muon_BestTrackPhi = 0 
        self.Muon_BestTrackPhiErr = 0 
   
        self.Muon_combinedQuality_match1_dX = 0 
        self.Muon_combinedQuality_match1_pullX = 0 
        self.Muon_combinedQuality_match1_pullDxDz = 0 
        self.Muon_combinedQuality_match1_dY = 0 
        self.Muon_combinedQuality_match1_pullY = 0 
        self.Muon_combinedQuality_match1_pullDyDz = 0 

        self.Muon_combinedQuality_match2_dX = 0 
        self.Muon_combinedQuality_match2_pullX = 0 
        self.Muon_combinedQuality_match2_pullDxDz = 0 
        self.Muon_combinedQuality_match2_dY = 0 
        self.Muon_combinedQuality_match2_pullY = 0 
        self.Muon_combinedQuality_match2_pullDyDz = 0 

        self.Muon_emEt03 = 0 
        self.Muon_hadEt03 = 0 
        self.Muon_nJets03 = 0 
        self.Muon_nTracks03 = 0 
        self.Muon_sumPt03 = 0 
        self.Muon_hadVetoEt03 = 0 
        self.Muon_emVetoEt03 = 0 
        self.Muon_trackerVetoPt03 = 0 
        self.Muon_emEt05 = 0 
        self.Muon_hadEt05 = 0 
        self.Muon_nJets05 = 0 
        self.Muon_nTracks05 = 0 
        self.Muon_sumPt05 = 0 
        self.Muon_hadVetoEt05 = 0 
        self.Muon_emVetoEt05 = 0 
        self.Muon_trackerVetoPt05 = 0 
#       L2Muons_pt = 0 
#       L2Muons_eta = 0 
#       L2Muons_phi = 0 
#       L2Muons_charge = 0 
#       L3Muons_pt = 0 
#       L3Muons_eta = 0 
#       L3Muons_phi = 0 
#       L3Muons_charge = 0 
        self.Track_pt = 0 
        self.Track_eta = 0 
        self.Track_phi = 0 
        self.Track_normalizedChi2 = 0 
        self.Track_numberOfValidHits = 0 
        self.Track_charge = 0 
        self.Track_dxy = 0 
        self.Track_dxyError = 0 
        self.Track_dz = 0 
        self.Track_dzError = 0 
        self.Track_vx = 0 
        self.Track_vy = 0 
        self.Track_vz = 0 
        self.Muon_validMuonHitComb = 0 
        self.Muon_innerTrack_ValidFraction = 0 
        self.Muon_Numberofvalidtrackerhits = 0 
        self.Muon_innerTrack_highPurity = 0 
        self.Track_pdgId = 0 
        self.PV_x = 0 
        self.PV_y = 0 
        self.PV_z = 0 
        self.PV_NTracks = 0 
        self.BS_x = 0 
        self.BS_y = 0 
        self.BS_z = 0 
        self.Vtx12_x = 0 
        self.Vtx23_x = 0 
        self.Vtx13_x = 0 
        self.Vtx12_y = 0 
        self.Vtx23_y = 0 
        self.Vtx13_y = 0 
        self.Vtx12_z = 0 
        self.Vtx23_z = 0 
        self.Vtx13_z = 0 
        self.Vtx12_Chi2 = 0 
        self.Vtx23_Chi2 = 0 
        self.Vtx13_Chi2 = 0 
        self.Vtx12_nDOF = 0 
        self.Vtx23_nDOF = 0 
        self.Vtx13_nDOF = 0 
        self.Mu01_Pt = 0 
        self.Mu01_Eta = 0 
        self.Mu01_Phi = 0 
        self.Mu01_dRtriggerMatch = 0 
        self.Mu01_TripletIndex = 0 
        self.Mu1_NTracks03iso = 0 
        self.Mu02_Pt = 0 
        self.Mu02_Eta = 0 
        self.Mu02_Phi = 0 
        self.Mu02_dRtriggerMatch = 0 
        self.Mu02_TripletIndex = 0 
        self.Mu2_NTracks03iso = 0 
        self.Tr_Pt = 0 
        self.Tr_Eta = 0 
        self.Tr_Phi = 0 
        self.Tr_dRtriggerMatch = 0 
        self.Tr_TripletIndex = 0 
        self.Tr_NTracks03iso = 0 
        self.selectedTripletsIndex = 0 
        self.GenMatchMu01_SimPt = 0 
        self.GenMatchMu02_SimPt = 0 
        self.GenMatchMu01_SimEta = 0 
        self.GenMatchMu02_SimEta = 0 
        self.GenMatchMu01_SimPhi = 0 
        self.GenMatchMu02_SimPhi = 0 
        self.GenMatchMu01_Pt = 0 
        self.GenMatchMu02_Pt = 0 
        self.GenMatchMu01_Eta = 0 
        self.GenMatchMu02_Eta = 0 
        self.GenMatchMu01_Phi = 0 
        self.GenMatchMu02_Phi = 0 
        self.Triplet_mindca_iso = 0 
        self.Triplet_relativeiso = 0 
        self.Triplet_relativeiso2 = 0 
        self.TripletVtx2_x = 0 
        self.TripletVtx2_y = 0 
        self.TripletVtx2_z = 0 
        self.TripletVtx2_Chi2 = 0 
        self.TripletVtx2_NDOF = 0 
        self.Triplet2_Mass = 0 
        self.Triplet2_Pt = 0 
        self.Triplet2_Eta = 0 
        self.Triplet2_Phi = 0 
        self.Triplet2_Charge = 0 
        self.RefittedPV2_x = 0 
        self.RefittedPV2_y = 0 
        self.RefittedPV2_z = 0 
        self.RefittedPV2_NTracks = 0 
        self.RefittedPV2_isValid = 0 
        self.RefittedPV_Chi2 = 0 
        self.RefittedPV_nDOF = 0 
        self.PV_bis_Chi2 = 0 
        self.PV_bis_nDOF = 0 
        self.FlightDistPVSV2 = 0 
        self.FlightDistPVSV2_Err = 0 
        self.FlightDistPVSV2_Significance = 0 
        self.FlightDistPVSV2_chi2 = 0 
        self.dxy_mu1 = 0 
        self.dxy_mu2 = 0 
        self.dxy_mu3 = 0 
        self.dxyErr_mu1 = 0 
        self.dxyErr_mu2 = 0 
        self.dxyErr_mu3 = 0 
        self.DistXY_PVSV = 0 
        self.DistXY_significance_PVSV = 0 
        self.Triplet_IsoMu1 = 0 
        self.Triplet_IsoMu2 = 0 
        self.Triplet_IsoMu3 = 0 
        self.FlightDistBS_SV = 0 
        self.FlightDistBS_SV_Err = 0 
        self.FlightDistBS_SV_Significance = 0 
        self.RefTrack1_Pt = 0 
        self.RefTrack1_Eta = 0 
        self.RefTrack1_Phi = 0 
        self.RefTrack1_TripletIndex = 0 
        self.RefTrack2_Pt = 0 
        self.RefTrack2_Eta = 0 
        self.RefTrack2_Phi = 0 
        self.RefTrack2_TripletIndex = 0 
        self.RefTrack3_Pt = 0 
        self.RefTrack3_Eta = 0 
        self.RefTrack3_Phi = 0 
        self.RefTrack3_TripletIndex = 0 
        self.RefittedSV_Chi2 = 0 
        self.RefittedSV_nDOF = 0 
        self.RefittedSV_Mass = 0 
        self.IsoTrackMu1_Pt = 0 
        self.IsoTrackMu1_Eta = 0 
        self.IsoTrackMu1_Phi = 0 
        self.IsoTrackMu2_Pt = 0 
        self.IsoTrackMu2_Eta = 0 
        self.IsoTrackMu2_Phi = 0 
        self.IsoTrackMu3_Pt = 0 
        self.IsoTrackMu3_Eta = 0 
        self.IsoTrackMu3_Phi = 0 
        self.Mu1_dRtriggerMatch_Mu7 = 0 
        self.Mu1_dRtriggerMatch_Mu8 = 0 
        self.Mu2_dRtriggerMatch_Mu7 = 0 
        self.Mu2_dRtriggerMatch_Mu8 = 0 
        self.Mu3_dRtriggerMatch_Mu7 = 0 
        self.Mu3_dRtriggerMatch_Mu8 = 0 
        self.Mu1_dRtriggerMatch_Mu8_IP5 = 0 
        self.Mu1_dRtriggerMatch_Mu8_IP6 = 0 
        self.Mu1_dRtriggerMatch_Mu9_IP0 = 0 
        self.Mu1_dRtriggerMatch_Mu9_IP3 = 0 
        self.Mu1_dRtriggerMatch_Mu9_IP4 = 0 
        self.Mu1_dRtriggerMatch_Mu9_IP5 = 0 
        self.Mu1_dRtriggerMatch_Mu9_IP6 = 0 
        self.Mu1_dRtriggerMatch_Mu12_IP6 = 0 
        self.Mu1_dRtriggerMatch_2017 = 0 
        self.Mu2_dRtriggerMatch_2017 = 0 
        self.Mu3_dRtriggerMatch_2017 = 0 
        self.MuonPt_HLT2017 = 0 
        self.MuonEta_HLT2017 = 0 
        self.MuonPhi_HLT2017 = 0 
        self.MuonPt_HLT_DiMu_Incl= 0 
        self.MuonEta_HLT_DiMu_Incl= 0 
        self.MuonPhi_HLT_DiMu_Incl= 0 
        self.MuonPt_HLT_DiMu_Incl_displ= 0 
        self.MuonEta_HLT_DiMu_Incl_displ= 0 
        self.MuonPhi_HLT_DiMu_Incl_displ= 0 
        self.MuonPt_HLT_Dimuon = 0 
        self.MuonEta_HLT_Dimuon = 0 
        self.MuonPhi_HLT_Dimuon = 0 
        self.MuonPt_HLT = 0 
        self.MuonEta_HLT = 0 
        self.MuonPhi_HLT = 0 
        self.L1Muon_Pt= 0 
        self.L1Muon_Eta= 0 
        self.L1Muon_Phi= 0 
        self.L1Muon_EtaAtVtx= 0 
        self.L1Muon_PhiAtVtx= 0 
        self.L1Muon_BX= 0 
        self.L1Muon_Quality= 0 
        self.L1Muon_Charge= 0 
        self.L1Muon_ChargeValid= 0 
        self.L1Muon_TfMuonIndex= 0 
        self.L1Muon_rank= 0 
        self.L1Muon_isoSum= 0

        self.list_of_names =[ 'NGoodTriplets', 
        'Trigger_l1name', 
        'Trigger_l1decision', 
        'Trigger_l1prescale', 
        'Trigger_hltname', 
        'Trigger_hltdecision', 
        'GenParticle_PdgId', 
        'GenParticle_Pt', 
        'GenParticle_Eta', 
        'GenParticle_Phi', 
        'GenParticle_isDs', 
        'GenParticle_isB', 
        'GenParticle_isBdecay', 
        'GenParticle_MotherPdgId', 
        'MuonPt', 
        'MuonEnergy', 
        'MuonCharge', 
        'MuonEta', 
        'MuonPhi', 
        'Muon_PdgId', 
        'Muon_MotherPdgId', 
        'Muon_simFlavour', 
        'Muon_vx', 
        'Muon_vy', 
        'Muon_vz', 
        'Muon_isGlobal', 
        'Muon_isSoft', 
        'Muon_MVA', 
        'Muon_SoftMVA_Val', 
        'Muon_isLoose', 
        'Muon_isMedium', 
        'Muon_isPF', 
        'Muon_isRPCMuon', 
        'Muon_isStandAloneMuon', 
        'Muon_isTrackerMuon', 
        'Muon_isCaloMuon', 
        'Muon_isQualityValid', 
        'Muon_isTimeValid', 
        'Muon_isIsolationValid', 
        'Muon_numberOfMatchedStations', 
        'Muon_numberOfMatches', 
        'Muon_timeAtIpInOut', 
        'Muon_timeAtIpInOutErr', 
        'Muon_GLnormChi2', 
        'Muon_GLhitPattern_numberOfValidMuonHits', 
        'Muon_trackerLayersWithMeasurement', 
        'Muon_Numberofvalidpixelhits', 
        'Muon_outerTrack_p', 
        'Muon_outerTrack_eta', 
        'Muon_outerTrack_phi', 
        'Muon_outerTrack_normalizedChi2', 
        'Muon_outerTrack_muonStationsWithValidHits', 
        'Muon_innerTrack_p', 
        'Muon_innerTrack_eta', 
        'Muon_innerTrack_phi', 
        'Muon_innerTrack_normalizedChi2', 
        'Muon_QInnerOuter', 
        'Muon_combinedQuality_updatedSta', 
        'Muon_combinedQuality_trkKink', 
        'Muon_combinedQuality_glbKink', 
        'Muon_combinedQuality_trkRelChi2', 
        'Muon_combinedQuality_staRelChi2', 
        'Muon_combinedQuality_chi2LocalPosition', 
        'Muon_combinedQuality_chi2LocalMomentum', 
        'Muon_combinedQuality_localDistance', 
        'Muon_combinedQuality_globalDeltaEtaPhi', 
        'Muon_combinedQuality_tightMatch', 
        'Muon_combinedQuality_glbTrackProbability', 
        'Muon_calEnergy_em', 
        'Muon_calEnergy_emS9', 
        'Muon_calEnergy_emS25', 
        'Muon_calEnergy_had', 
        'Muon_calEnergy_hadS9', 
        'Muon_segmentCompatibility', 
        'Muon_caloCompatibility', 
        'Muon_ptErrOverPt', 
        'Muon_BestTrackPt', 
        'Muon_BestTrackPtErr', 
        'Muon_BestTrackEta', 
        'Muon_BestTrackEtaErr', 
        'Muon_BestTrackPhi', 
        'Muon_BestTrackPhiErr', 
   
        'Muon_combinedQuality_match1_dX', 
        'Muon_combinedQuality_match1_pullX', 
        'Muon_combinedQuality_match1_pullDxDz', 
        'Muon_combinedQuality_match1_dY', 
        'Muon_combinedQuality_match1_pullY', 
        'Muon_combinedQuality_match1_pullDyDz', 

        'Muon_combinedQuality_match2_dX', 
        'Muon_combinedQuality_match2_pullX', 
        'Muon_combinedQuality_match2_pullDxDz', 
        'Muon_combinedQuality_match2_dY', 
        'Muon_combinedQuality_match2_pullY', 
        'Muon_combinedQuality_match2_pullDyDz', 

        'Muon_emEt03', 
        'Muon_hadEt03', 
        'Muon_nJets03', 
        'Muon_nTracks03', 
        'Muon_sumPt03', 
        'Muon_hadVetoEt03', 
        'Muon_emVetoEt03', 
        'Muon_trackerVetoPt03', 
        'Muon_emEt05', 
        'Muon_hadEt05', 
        'Muon_nJets05', 
        'Muon_nTracks05', 
        'Muon_sumPt05', 
        'Muon_hadVetoEt05', 
        'Muon_emVetoEt05', 
        'Muon_trackerVetoPt05', 
#       L2Muons_pt', 
#       L2Muons_eta', 
#       L2Muons_phi', 
#       L2Muons_charge', 
#       L3Muons_pt', 
#       L3Muons_eta', 
#       L3Muons_phi', 
#       L3Muons_charge', 
        'Track_pt', 
        'Track_eta', 
        'Track_phi', 
        'Track_normalizedChi2', 
        'Track_numberOfValidHits', 
        'Track_charge', 
        'Track_dxy', 
        'Track_dxyError', 
        'Track_dz', 
        'Track_dzError', 
        'Track_vx', 
        'Track_vy', 
        'Track_vz', 
        'Muon_validMuonHitComb', 
        'Muon_innerTrack_ValidFraction', 
        'Muon_Numberofvalidtrackerhits', 
        'Muon_innerTrack_highPurity', 
        'Track_pdgId', 
        'PV_x', 
        'PV_y', 
        'PV_z', 
        'PV_NTracks', 
        'BS_x', 
        'BS_y', 
        'BS_z', 
        'Vtx12_x', 
        'Vtx23_x', 
        'Vtx13_x', 
        'Vtx12_y', 
        'Vtx23_y', 
        'Vtx13_y', 
        'Vtx12_z', 
        'Vtx23_z', 
        'Vtx13_z', 
        'Vtx12_Chi2', 
        'Vtx23_Chi2', 
        'Vtx13_Chi2', 
        'Vtx12_nDOF', 
        'Vtx23_nDOF', 
        'Vtx13_nDOF', 
        'Mu01_Pt', 
        'Mu01_Eta', 
        'Mu01_Phi', 
        'Mu01_dRtriggerMatch', 
        'Mu01_TripletIndex', 
        'Mu1_NTracks03iso', 
        'Mu02_Pt', 
        'Mu02_Eta', 
        'Mu02_Phi', 
        'Mu02_dRtriggerMatch', 
        'Mu02_TripletIndex', 
        'Mu2_NTracks03iso', 
        'Tr_Pt', 
        'Tr_Eta', 
        'Tr_Phi', 
        'Tr_dRtriggerMatch', 
        'Tr_TripletIndex', 
        'Tr_NTracks03iso', 
        'selectedTripletsIndex', 
        'GenMatchMu01_SimPt', 
        'GenMatchMu02_SimPt', 
        'GenMatchMu01_SimEta', 
        'GenMatchMu02_SimEta', 
        'GenMatchMu01_SimPhi', 
        'GenMatchMu02_SimPhi', 
        'GenMatchMu01_Pt', 
        'GenMatchMu02_Pt', 
        'GenMatchMu01_Eta', 
        'GenMatchMu02_Eta', 
        'GenMatchMu01_Phi', 
        'GenMatchMu02_Phi', 
        'Triplet_mindca_iso', 
        'Triplet_relativeiso', 
        'Triplet_relativeiso2', 
        'TripletVtx2_x', 
        'TripletVtx2_y', 
        'TripletVtx2_z', 
        'TripletVtx2_Chi2', 
        'TripletVtx2_NDOF', 
        'Triplet2_Mass', 
        'Triplet2_Pt', 
        'Triplet2_Eta', 
        'Triplet2_Phi', 
        'Triplet2_Charge', 
        'RefittedPV2_x', 
        'RefittedPV2_y', 
        'RefittedPV2_z', 
        'RefittedPV2_NTracks', 
        'RefittedPV2_isValid', 
        'RefittedPV_Chi2', 
        'RefittedPV_nDOF', 
        'PV_bis_Chi2', 
        'PV_bis_nDOF', 
        'FlightDistPVSV2', 
        'FlightDistPVSV2_Err', 
        'FlightDistPVSV2_Significance', 
        'FlightDistPVSV2_chi2', 
        'dxy_mu1', 
        'dxy_mu2', 
        'dxy_mu3', 
        'dxyErr_mu1', 
        'dxyErr_mu2', 
        'dxyErr_mu3', 
        'DistXY_PVSV', 
        'DistXY_significance_PVSV', 
        'Triplet_IsoMu1', 
        'Triplet_IsoMu2', 
        'Triplet_IsoMu3', 
        'FlightDistBS_SV', 
        'FlightDistBS_SV_Err', 
        'FlightDistBS_SV_Significance', 
        'RefTrack1_Pt', 
        'RefTrack1_Eta', 
        'RefTrack1_Phi', 
        'RefTrack1_TripletIndex', 
        'RefTrack2_Pt', 
        'RefTrack2_Eta', 
        'RefTrack2_Phi', 
        'RefTrack2_TripletIndex', 
        'RefTrack3_Pt', 
        'RefTrack3_Eta', 
        'RefTrack3_Phi', 
        'RefTrack3_TripletIndex', 
        'RefittedSV_Chi2', 
        'RefittedSV_nDOF', 
        'RefittedSV_Mass', 
        'IsoTrackMu1_Pt', 
        'IsoTrackMu1_Eta', 
        'IsoTrackMu1_Phi', 
        'IsoTrackMu2_Pt', 
        'IsoTrackMu2_Eta', 
        'IsoTrackMu2_Phi', 
        'IsoTrackMu3_Pt', 
        'IsoTrackMu3_Eta', 
        'IsoTrackMu3_Phi', 
        'Mu1_dRtriggerMatch_Mu7', 
        'Mu1_dRtriggerMatch_Mu8', 
        'Mu2_dRtriggerMatch_Mu7', 
        'Mu2_dRtriggerMatch_Mu8', 
        'Mu3_dRtriggerMatch_Mu7', 
        'Mu3_dRtriggerMatch_Mu8', 
        'Mu1_dRtriggerMatch_Mu8_IP5', 
        'Mu1_dRtriggerMatch_Mu8_IP6', 
        'Mu1_dRtriggerMatch_Mu9_IP0', 
        'Mu1_dRtriggerMatch_Mu9_IP3', 
        'Mu1_dRtriggerMatch_Mu9_IP4', 
        'Mu1_dRtriggerMatch_Mu9_IP5', 
        'Mu1_dRtriggerMatch_Mu9_IP6', 
        'Mu1_dRtriggerMatch_Mu12_IP6', 
        'Mu1_dRtriggerMatch_2017', 
        'Mu2_dRtriggerMatch_2017', 
        'Mu3_dRtriggerMatch_2017', 
        'MuonPt_HLT2017', 
        'MuonEta_HLT2017', 
        'MuonPhi_HLT2017', 
        'MuonPt_HLT_DiMu_Incl', 
        'MuonEta_HLT_DiMu_Incl', 
        'MuonPhi_HLT_DiMu_Incl', 
        'MuonPt_HLT_DiMu_Incl_displ', 
        'MuonEta_HLT_DiMu_Incl_displ', 
        'MuonPhi_HLT_DiMu_Incl_displ', 
        'MuonPt_HLT_Dimuon', 
        'MuonEta_HLT_Dimuon', 
        'MuonPhi_HLT_Dimuon', 
        'MuonPt_HLT', 
        'MuonEta_HLT', 
        'MuonPhi_HLT', 
        'L1Muon_Pt', 
        'L1Muon_Eta', 
        'L1Muon_Phi', 
        'L1Muon_EtaAtVtx', 
        'L1Muon_PhiAtVtx', 
        'L1Muon_BX', 
        'L1Muon_Quality', 
        'L1Muon_Charge', 
        'L1Muon_ChargeValid', 
        'L1Muon_TfMuonIndex', 
        'L1Muon_rank', 
        'L1Muon_isoSum']

        self.list_of_variables = [self.NGoodTriplets, 
        self.Trigger_l1name, 
        self.Trigger_l1decision, 
        self.Trigger_l1prescale, 
        self.Trigger_hltname, 
        self.Trigger_hltdecision, 
        self.GenParticle_PdgId, 
        self.GenParticle_Pt, 
        self.GenParticle_Eta, 
        self.GenParticle_Phi, 
        self.GenParticle_isDs, 
        self.GenParticle_isB, 
        self.GenParticle_isBdecay, 
        self.GenParticle_MotherPdgId, 
        self.MuonPt, 
        self.MuonEnergy, 
        self.MuonCharge, 
        self.MuonEta, 
        self.MuonPhi, 
        self.Muon_PdgId, 
        self.Muon_MotherPdgId, 
        self.Muon_simFlavour, 
        self.Muon_vx, 
        self.Muon_vy, 
        self.Muon_vz, 
        self.Muon_isGlobal, 
        self.Muon_isSoft, 
        self.Muon_MVA, 
        self.Muon_SoftMVA_Val, 
        self.Muon_isLoose, 
        self.Muon_isMedium, 
        self.Muon_isPF, 
        self.Muon_isRPCMuon, 
        self.Muon_isStandAloneMuon, 
        self.Muon_isTrackerMuon, 
        self.Muon_isCaloMuon, 
        self.Muon_isQualityValid, 
        self.Muon_isTimeValid, 
        self.Muon_isIsolationValid, 
        self.Muon_numberOfMatchedStations, 
        self.Muon_numberOfMatches, 
        self.Muon_timeAtIpInOut, 
        self.Muon_timeAtIpInOutErr, 
        self.Muon_GLnormChi2, 
        self.Muon_GLhitPattern_numberOfValidMuonHits, 
        self.Muon_trackerLayersWithMeasurement, 
        self.Muon_Numberofvalidpixelhits, 
        self.Muon_outerTrack_p, 
        self.Muon_outerTrack_eta, 
        self.Muon_outerTrack_phi, 
        self.Muon_outerTrack_normalizedChi2, 
        self.Muon_outerTrack_muonStationsWithValidHits, 
        self.Muon_innerTrack_p, 
        self.Muon_innerTrack_eta, 
        self.Muon_innerTrack_phi, 
        self.Muon_innerTrack_normalizedChi2, 
        self.Muon_QInnerOuter, 
        self.Muon_combinedQuality_updatedSta, 
        self.Muon_combinedQuality_trkKink, 
        self.Muon_combinedQuality_glbKink, 
        self.Muon_combinedQuality_trkRelChi2, 
        self.Muon_combinedQuality_staRelChi2, 
        self.Muon_combinedQuality_chi2LocalPosition, 
        self.Muon_combinedQuality_chi2LocalMomentum, 
        self.Muon_combinedQuality_localDistance, 
        self.Muon_combinedQuality_globalDeltaEtaPhi, 
        self.Muon_combinedQuality_tightMatch, 
        self.Muon_combinedQuality_glbTrackProbability, 
        self.Muon_calEnergy_em, 
        self.Muon_calEnergy_emS9, 
        self.Muon_calEnergy_emS25, 
        self.Muon_calEnergy_had, 
        self.Muon_calEnergy_hadS9, 
        self.Muon_segmentCompatibility, 
        self.Muon_caloCompatibility, 
        self.Muon_ptErrOverPt, 
        self.Muon_BestTrackPt, 
        self.Muon_BestTrackPtErr, 
        self.Muon_BestTrackEta, 
        self.Muon_BestTrackEtaErr, 
        self.Muon_BestTrackPhi, 
        self.Muon_BestTrackPhiErr, 
   
        self.Muon_combinedQuality_match1_dX, 
        self.Muon_combinedQuality_match1_pullX, 
        self.Muon_combinedQuality_match1_pullDxDz, 
        self.Muon_combinedQuality_match1_dY, 
        self.Muon_combinedQuality_match1_pullY, 
        self.Muon_combinedQuality_match1_pullDyDz, 

        self.Muon_combinedQuality_match2_dX, 
        self.Muon_combinedQuality_match2_pullX, 
        self.Muon_combinedQuality_match2_pullDxDz, 
        self.Muon_combinedQuality_match2_dY, 
        self.Muon_combinedQuality_match2_pullY, 
        self.Muon_combinedQuality_match2_pullDyDz, 

        self.Muon_emEt03, 
        self.Muon_hadEt03, 
        self.Muon_nJets03, 
        self.Muon_nTracks03, 
        self.Muon_sumPt03, 
        self.Muon_hadVetoEt03, 
        self.Muon_emVetoEt03, 
        self.Muon_trackerVetoPt03, 
        self.Muon_emEt05, 
        self.Muon_hadEt05, 
        self.Muon_nJets05, 
        self.Muon_nTracks05, 
        self.Muon_sumPt05, 
        self.Muon_hadVetoEt05, 
        self.Muon_emVetoEt05, 
        self.Muon_trackerVetoPt05, 
#       L2Muons_pt, 
#       L2Muons_eta, 
#       L2Muons_phi, 
#       L2Muons_charge, 
#       L3Muons_pt, 
#       L3Muons_eta, 
#       L3Muons_phi, 
#       L3Muons_charge, 
        self.Track_pt, 
        self.Track_eta, 
        self.Track_phi, 
        self.Track_normalizedChi2, 
        self.Track_numberOfValidHits, 
        self.Track_charge, 
        self.Track_dxy, 
        self.Track_dxyError, 
        self.Track_dz, 
        self.Track_dzError, 
        self.Track_vx, 
        self.Track_vy, 
        self.Track_vz, 
        self.Muon_validMuonHitComb, 
        self.Muon_innerTrack_ValidFraction, 
        self.Muon_Numberofvalidtrackerhits, 
        self.Muon_innerTrack_highPurity, 
        self.Track_pdgId, 
        self.PV_x, 
        self.PV_y, 
        self.PV_z, 
        self.PV_NTracks, 
        self.BS_x, 
        self.BS_y, 
        self.BS_z, 
        self.Vtx12_x, 
        self.Vtx23_x, 
        self.Vtx13_x, 
        self.Vtx12_y, 
        self.Vtx23_y, 
        self.Vtx13_y, 
        self.Vtx12_z, 
        self.Vtx23_z, 
        self.Vtx13_z, 
        self.Vtx12_Chi2, 
        self.Vtx23_Chi2, 
        self.Vtx13_Chi2, 
        self.Vtx12_nDOF, 
        self.Vtx23_nDOF, 
        self.Vtx13_nDOF, 
        self.Mu01_Pt, 
        self.Mu01_Eta, 
        self.Mu01_Phi, 
        self.Mu01_dRtriggerMatch, 
        self.Mu01_TripletIndex, 
        self.Mu1_NTracks03iso, 
        self.Mu02_Pt, 
        self.Mu02_Eta, 
        self.Mu02_Phi, 
        self.Mu02_dRtriggerMatch, 
        self.Mu02_TripletIndex, 
        self.Mu2_NTracks03iso, 
        self.Tr_Pt, 
        self.Tr_Eta, 
        self.Tr_Phi, 
        self.Tr_dRtriggerMatch, 
        self.Tr_TripletIndex, 
        self.Tr_NTracks03iso, 
        self.selectedTripletsIndex, 
        self.GenMatchMu01_SimPt, 
        self.GenMatchMu02_SimPt, 
        self.GenMatchMu01_SimEta, 
        self.GenMatchMu02_SimEta, 
        self.GenMatchMu01_SimPhi, 
        self.GenMatchMu02_SimPhi, 
        self.GenMatchMu01_Pt, 
        self.GenMatchMu02_Pt, 
        self.GenMatchMu01_Eta, 
        self.GenMatchMu02_Eta, 
        self.GenMatchMu01_Phi, 
        self.GenMatchMu02_Phi, 
        self.Triplet_mindca_iso, 
        self.Triplet_relativeiso, 
        self.Triplet_relativeiso2, 
        self.TripletVtx2_x, 
        self.TripletVtx2_y, 
        self.TripletVtx2_z, 
        self.TripletVtx2_Chi2, 
        self.TripletVtx2_NDOF, 
        self.Triplet2_Mass, 
        self.Triplet2_Pt, 
        self.Triplet2_Eta, 
        self.Triplet2_Phi, 
        self.Triplet2_Charge, 
        self.RefittedPV2_x, 
        self.RefittedPV2_y, 
        self.RefittedPV2_z, 
        self.RefittedPV2_NTracks, 
        self.RefittedPV2_isValid, 
        self.RefittedPV_Chi2, 
        self.RefittedPV_nDOF, 
        self.PV_bis_Chi2, 
        self.PV_bis_nDOF, 
        self.FlightDistPVSV2, 
        self.FlightDistPVSV2_Err, 
        self.FlightDistPVSV2_Significance, 
        self.FlightDistPVSV2_chi2, 
        self.dxy_mu1, 
        self.dxy_mu2, 
        self.dxy_mu3, 
        self.dxyErr_mu1, 
        self.dxyErr_mu2, 
        self.dxyErr_mu3, 
        self.DistXY_PVSV, 
        self.DistXY_significance_PVSV, 
        self.Triplet_IsoMu1, 
        self.Triplet_IsoMu2, 
        self.Triplet_IsoMu3, 
        self.FlightDistBS_SV, 
        self.FlightDistBS_SV_Err, 
        self.FlightDistBS_SV_Significance, 
        self.RefTrack1_Pt, 
        self.RefTrack1_Eta, 
        self.RefTrack1_Phi, 
        self.RefTrack1_TripletIndex, 
        self.RefTrack2_Pt, 
        self.RefTrack2_Eta, 
        self.RefTrack2_Phi, 
        self.RefTrack2_TripletIndex, 
        self.RefTrack3_Pt, 
        self.RefTrack3_Eta, 
        self.RefTrack3_Phi, 
        self.RefTrack3_TripletIndex, 
        self.RefittedSV_Chi2, 
        self.RefittedSV_nDOF, 
        self.RefittedSV_Mass, 
        self.IsoTrackMu1_Pt, 
        self.IsoTrackMu1_Eta, 
        self.IsoTrackMu1_Phi, 
        self.IsoTrackMu2_Pt, 
        self.IsoTrackMu2_Eta, 
        self.IsoTrackMu2_Phi, 
        self.IsoTrackMu3_Pt, 
        self.IsoTrackMu3_Eta, 
        self.IsoTrackMu3_Phi, 
        self.Mu1_dRtriggerMatch_Mu7, 
        self.Mu1_dRtriggerMatch_Mu8, 
        self.Mu2_dRtriggerMatch_Mu7, 
        self.Mu2_dRtriggerMatch_Mu8, 
        self.Mu3_dRtriggerMatch_Mu7, 
        self.Mu3_dRtriggerMatch_Mu8, 
        self.Mu1_dRtriggerMatch_Mu8_IP5, 
        self.Mu1_dRtriggerMatch_Mu8_IP6, 
        self.Mu1_dRtriggerMatch_Mu9_IP0, 
        self.Mu1_dRtriggerMatch_Mu9_IP3, 
        self.Mu1_dRtriggerMatch_Mu9_IP4, 
        self.Mu1_dRtriggerMatch_Mu9_IP5, 
        self.Mu1_dRtriggerMatch_Mu9_IP6, 
        self.Mu1_dRtriggerMatch_Mu12_IP6, 
        self.Mu1_dRtriggerMatch_2017, 
        self.Mu2_dRtriggerMatch_2017, 
        self.Mu3_dRtriggerMatch_2017, 
        self.MuonPt_HLT2017, 
        self.MuonEta_HLT2017, 
        self.MuonPhi_HLT2017, 
        self.MuonPt_HLT_DiMu_Incl, 
        self.MuonEta_HLT_DiMu_Incl, 
        self.MuonPhi_HLT_DiMu_Incl, 
        self.MuonPt_HLT_DiMu_Incl_displ, 
        self.MuonEta_HLT_DiMu_Incl_displ, 
        self.MuonPhi_HLT_DiMu_Incl_displ, 
        self.MuonPt_HLT_Dimuon, 
        self.MuonEta_HLT_Dimuon, 
        self.MuonPhi_HLT_Dimuon, 
        self.MuonPt_HLT, 
        self.MuonEta_HLT, 
        self.MuonPhi_HLT, 
        self.L1Muon_Pt, 
        self.L1Muon_Eta, 
        self.L1Muon_Phi, 
        self.L1Muon_EtaAtVtx, 
        self.L1Muon_PhiAtVtx, 
        self.L1Muon_BX, 
        self.L1Muon_Quality, 
        self.L1Muon_Charge, 
        self.L1Muon_ChargeValid, 
        self.L1Muon_TfMuonIndex, 
        self.L1Muon_rank, 
        self.L1Muon_isoSum]
         
        if len(self.list_of_variables)!=len(self.list_of_names):
            print("Error: Variable names do not match variables initiated!!!")
        if not tree:
            return
        #self.fChain = tree
        self.fChain = ROOT.RDataFrame(tree)
        columns = self.fChain.GetColumnNames()
        print(columns)
        self.fCurrent = -1
        #self.fChain.SetMakeClass(1)

        for variable in columns:
            self.variable = self.fChain.variable
            #new_branch = ROOT.TBranch()
            #self.fChain.SetBranchAddress(self.list_of_names[i], self.list_of_variables[i], new_branch)
        
        self.Notify()

    def Notify(self):
        # The Notify() function is called when a new file is opened. This
        # can be either for a new TTree in a TChain or when when a new TTree
        # is started when using PROOF. It is normally not necessary to make changes
        # to the generated code, but the routine can be extended by the
        # user if needed. The return value is currently not used.
        return True

    def Show(self, entry):
        # Print contents of entry.
        # If entry is not specified, print current entry
        if not self.fChain: return
        self.fChain.Show(entry)


    def Cut(self, entry):
        # This function may be called from Loop.
        # returns  1 if entry is accepted.
        # returns -1 otherwise.
        return 1