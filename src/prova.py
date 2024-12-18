#!/usr/bin/env cmsRun
import FWCore.ParameterSet.Config as cms
process = cms.Process("GenDraw")

process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/lustre/cms/store/user/mbuonsan/Bs4Mu_13p6TeV-pythia8_Run3/124X_mcRun3_2022_realistic_postEE_v3_GEN-SIM/231030_133754/0000/Run3_Bs4Mu_step0_156.root'
        )
    )
