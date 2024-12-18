import FWCore.ParameterSet.Config as cms

process = cms.Process('Tau3MuSkim')

import copy

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration/Geometry/GeometryExtended2026D110Reco_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')

process.GlobalTag.globaltag = '140X_mcRun4_realistic_v6' #Run4MC 
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10000) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        #MC Run2024
        #"/BdTau3Mu_14TeV_Pythia8/jschulte-Phase2Spring24GSMiniAOD-PU200_140X_mcRun4_realistic_v4_v2-fab0e0c98a2058a3b66af3f42aa300fa/USER"
        #MC DsTau3Mu 2023
        #"/store/user/jschulte/BdTau3Mu_14TeV_Pythia8/Phase2Spring24DIGIRECOMiniAOD-PU200_140X_mcRun4_realistic_v4_v2/241203_134314/0000/XTau3Mu_GEN_SIM_DIGI_RAW_MINIAOD_10.root"
        'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/DsToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/2540000/5ef6393b-32c8-41c5-8a3f-af1b6529a9c9.root',
        'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/DsToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/2540000/b7fa0de1-fd0e-4094-a5ec-ceece64db4af.root',
        'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/DsToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/5ab61b39-05bc-41c9-889e-357c65922f03.root',
        'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/DsToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/8d67b4cd-f759-4b41-ae3e-179c72e98367.root',
        'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/DsToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/daa8ab3e-6cfc-4a96-a3ac-e4d677815a3f.root',

       #MC WTau3mu
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/2520000/e8fd601a-a377-4e20-a3a6-ee316975fbe8.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/0420aba2-5de3-490b-83b5-0c7e12666615.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/297b4d68-465f-4b0d-b1b2-434beba9a05b.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/37f2df9e-e23f-4d1c-8b30-bc2d2d824deb.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/7088360f-8483-4229-8d57-ec816b6ead4a.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/30000/76a34b30-5294-4f19-9805-4f2831a9beda.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/40000/8512727a-9222-4c1a-be50-36572c6698c3.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/40000/a6175f49-f3a8-4ca1-a4f6-af6622252adf.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/40000/f45163c1-632b-403f-8553-51e6908b36dc.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/50000/2fd1e51e-6aae-40fb-a26f-4d53b2c4cad9.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/50000/63c1a09f-c527-46e1-9d3e-f72369b2a542.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/50000/d04bad90-cf47-4947-a464-728119f33e43.root',
#'root://xrootd-cms.infn.it///store/mc/Run3Summer22MiniAODv4/WToTauTo3Mu_TuneCP5_13p6TeV_pythia8/MINIAODSIM/130X_mcRun3_2022_realistic_v5-v2/50000/da7fcca8-5064-41a8-9e63-f6cde6abf10f.root',
    ),
            #eventsToProcess = cms.untracked.VEventRange('320012:56448719')
)


process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("TreeMC.root"))

process.TreeMaker = cms.EDAnalyzer("GenAnalyzer",
   genParticleLabel=cms.InputTag("prunedGenParticles")
)

process.Tau3MuSkim = cms.Path( process.TreeMaker )
