#!/bin/bash
chmod 777 -R *
cd Run4_DsTau3mu_tau3mu_Run4_DsTau3Mu
echo condor_submit my_HTCondor_MC_Run4_DsTau3muRun4_DsTau3mu_tau3mu_0.job -name ettore
condor_submit my_HTCondor_MC_Run4_DsTau3muRun4_DsTau3mu_tau3mu_0.job -name ettore
