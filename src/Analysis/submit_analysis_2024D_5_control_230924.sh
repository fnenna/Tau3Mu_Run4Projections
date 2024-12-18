#!/bin/bash
chmod 777 -R *
cd 2024D_5_control_230924
echo condor_submit my_HTCondor_data_control_2024D_5_control_0.job -name ettore
condor_submit my_HTCondor_data_control_2024D_5_control_0.job -name ettore
echo condor_submit my_HTCondor_data_control_2024D_5_control_1.job -name ettore
condor_submit my_HTCondor_data_control_2024D_5_control_1.job -name ettore
echo condor_submit my_HTCondor_data_control_2024D_5_control_2.job -name ettore
condor_submit my_HTCondor_data_control_2024D_5_control_2.job -name ettore
