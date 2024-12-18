import sys
sys.path.append('..')
import config_info

from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = 'MCRun4_DsTau3Mu_private'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'

config.JobType.psetName = config_info.cmssw_dir + 'src/GenAnalyser/GenAnalyzer/python/genAnalyser_cff.py'
#config.Data.inputDataset = "/DSTau3Mu_14TeV_Pythia8/jschulte-Phase2Spring24DIGIRECOMiniAOD-PU200_140X_mcRun4_realistic_v4_v2-fab0e0c98a2058a3b66af3f42aa300fa/USER"
config.Data.inputDataset = '/DSTau3Mu_14TeV_Pythia8/jschulte-Phase2Spring24DIGIRECOMiniAOD-PU200_140X_mcRun4_realistic_v4_MiniAODTest_v1-515bee752741ef71814a39d75a17d442/USER'
config.Data.inputDBS = 'phys03'
#config.Data.splitting = 'LumiBased'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 100
config.Data.outLFNDirBase = config_info.store
#config.Data.publication = True
config.Data.outputDatasetTag = "DsTau3mu_test_MCRun4"
config.JobType.allowUndistributedCMSSW = True 
config.Site.storageSite = config_info.storageSite
config.Site.ignoreGlobalBlacklist  = True

