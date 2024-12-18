#!/bin/sh
# Usage:
#    submitAllJobs.sh

crab submit -c crab_MCRun4_BdTau3Mu_cfg.py
sleep 5
crab submit -c crab_MCRun4_BuTau3Mu_cfg.py
sleep 5
crab submit -c crab_MCRun4_DsTau3Mu_cfg.py
