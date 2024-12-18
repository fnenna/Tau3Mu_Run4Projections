#!/bin/bash
chmod 777 -R *
cd 2024B_0_control_230924
echo condor_submit my_HTCondor_data_control_2024B_0_control_0.job -name ettore
condor_submit my_HTCondor_data_control_2024B_0_control_0.job -name ettore
