from python_analysis_update_041124 import *
import ROOT
import sys
import argparse
import uproot
import pandas as pd
import awkward as ak
import dask_awkward as dak

def main():
    parser = argparse.ArgumentParser(
                        prog='ProgramName',
                        description='Analysis tau3mu control channel (DsPhiPi)',
                        epilog='Text at the bottom of help')
    parser.add_argument('-n','--narg')           # positional argument
    parser.add_argument('-t','--type')      # option that takes a value
    parser.add_argument('-d','--data')      # option that takes a value
    args = parser.parse_args()
    print(args.type)
    #print(args.filename, args.count, args.verbose)
    fileout = ""

    tree = ROOT.TTree()
    print(args.type)
    type = args.type
    print(f"type: {type}\n")
    datasetName = args.data
    print(f"datasetName : {datasetName}\n")

    if type == "data_control":
        print("Control channel analysis on data\n")
        print(f"Data {datasetName}")
        files = {}
        files = "/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1116.root:Tree3Mu/ntuple"
        '''
        files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1283.root"] = "Tree3Mu/ntuple"
        files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1057.root"] = "Tree3Mu/ntuple"
        files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1159.root"] = "Tree3Mu/ntuple"
        files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1041.root"] = "Tree3Mu/ntuple"
        files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1256.root"] = "Tree3Mu/ntuple"
        files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1395.root"] = "Tree3Mu/ntuple"
        files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1009.root"] = "Tree3Mu/ntuple"
        files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1369.root"] = "Tree3Mu/ntuple"
        files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1316.root"] = "Tree3Mu/ntuple"
        files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1074.root"] = "Tree3Mu/ntuple"
        '''
        fileout = "AnalysedTree_data_control_2024W_control5.root"
        start = time.time()
        chain = uproot.open(files).arrays()
        #chain = dchain.compute()
        print(len(chain))
        Loop_DsPhiPi(chain, type, datasetName, fileout)
        stop = time.time()
        print(f"time to open 1 file: {stop - start}")
        #Loop_DsPhiPi(chain, type, datasetName, fileout)
        #Loop_DsPhiPi(chain, type, datasetName, fileout)
    else: 
        print("Input not valid, analysis has not be developped for not control channel")


if __name__ == "__main__":
    main()