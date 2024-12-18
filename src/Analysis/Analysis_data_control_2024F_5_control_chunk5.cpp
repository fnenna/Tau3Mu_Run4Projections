#include "myAnalizer.C"
#include "myAnalizer_control.C"
#include <TROOT.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(int narg, char** arg){
    TTree *tree;
    char type[10];
    strcpy(type, arg[1]);
    cout << "type : " << type << endl;
    char datasetName[20];
    strcpy(datasetName, arg[2]);
    cout << "datasetName : " << datasetName << endl << endl;
    //TString fileout = "/lustrehome/mbuonsante/Tau_3mu/CMSSW_12_4_11_patch3/src/Analysis/Out/file.root";
    TString fileout = "";

    // Check input arguments
    if(strcmp(type, "MC") != 0 && strcmp(type, "data") != 0 && strcmp(type, "data_control") != 0){
        cout << "The first argument is wrong! Please choose among 'MC', 'data', 'data_control'" << endl;
        //return -1;
    }
    if( strcmp(type, "MC") == 0 && (strcmp(datasetName, "DsPhiPi_preE") != 0 && strcmp(datasetName, "DsPhiPi_postE") != 0 && strcmp(datasetName, "DsPhiMuNu") != 0 && strcmp(datasetName, "Ds_preE") != 0 && strcmp(datasetName, "Ds_postE") != 0 && strcmp(datasetName, "Bp_preE") != 0 && strcmp(datasetName, "Bp_postE") != 0 && strcmp(datasetName, "B0_preE") != 0 && strcmp(datasetName, "B0_postE") != 0 && strcmp(datasetName, "Ds_2018") != 0 && strcmp(datasetName, "DsPhiPi_preBPix") != 0 && strcmp(datasetName, "DsPhiPi_postBPix") != 0 && strcmp(datasetName, "Ds_preBPix") != 0 && strcmp(datasetName, "Ds_postBPix") != 0 && strcmp(datasetName, "Bp_preBPix") != 0 && strcmp(datasetName, "Bp_postBPix") != 0 && strcmp(datasetName, "B0_preBPix") != 0 && strcmp(datasetName, "B0_postBPix") != 0) ){
        cout << "The second argument is wrong! Please choose between 'Ds_preE - Ds_postE', 'B0_preE - B0_postE', 'Bp_preE - Bp_postE', 'DsPhiMuNu' and 'DsPhiPi_preE - DsPhiPi_postE'" << endl;
        return -1;
    }

    // ################ MC
    if ( strcmp(type, "MC") == 0 ){
        cout << "This is a MC" << endl;
        // ###SIGNAL samples
        // Ds -> Tau -> 3Mu
        if (strcmp(datasetName, "Ds_preE") == 0 || strcmp(datasetName, "Ds_preBPix") == 0){
            cout << "MC Dataset : Ds -> Tau -> 3Mu" << endl << endl;
            TChain* chain = new TChain("TreeMakerBkg/ntuple");
        //AddFile_MCDs_preE_tau3mu
        //OutFile_MCDs_preE_tau3mu
        //AddFile_MCDs_preBPix_tau3mu
        //OutFile_MCDs_preBPix_tau3mu
        myAnalizer class_data(chain, fileout);
        class_data.Loop_Tau3mu(type, datasetName);
        }
        if (strcmp(datasetName, "Ds_2018") == 0){
            cout << "MC Dataset : Ds -> Tau -> 3Mu" << endl << endl;
            TChain* chain = new TChain("TreeMakerBkg/ntuple");
        //AddFile_MCDs_2018_tau3mu
        //OutFile_MCDs_2018_tau3mu
        myAnalizer class_data(chain, fileout);
        class_data.Loop_Tau3mu(type, datasetName);
        }
	if (strcmp(datasetName, "Ds_postE") == 0 || strcmp(datasetName, "Ds_postBPix") == 0){
            cout << "MC Dataset : Ds -> Tau -> 3Mu" << endl << endl;
            TChain* chain = new TChain("TreeMakerBkg/ntuple");
        //AddFile_MCDs_postE_tau3mu
        //OutFile_MCDs_postE_tau3mu
        //AddFile_MCDs_postBPix_tau3mu
        //OutFile_MCDs_postBPix_tau3mu
        myAnalizer class_data(chain, fileout);
        class_data.Loop_Tau3mu(type, datasetName);
        }
        // Bd -> Tau -> 3Mu
        if (strcmp(datasetName, "B0_preE") == 0 || strcmp(datasetName, "B0_preBPix") == 0){
            cout << "MC Dataset : B0 -> Tau -> 3Mu" << endl << endl;
            TChain* chain = new TChain("TreeMakerBkg/ntuple");
        //AddFile_MCB0_preE_tau3mu
        //OutFile_MCB0_preE_tau3mu
        //AddFile_MCB0_preBPix_tau3mu
        //OutFile_MCB0_preBPix_tau3mu
        myAnalizer class_data(chain, fileout);
        class_data.Loop_Tau3mu(type, datasetName);
        }
	// Bd -> Tau -> 3Mu
        if (strcmp(datasetName, "B0_postE") == 0 || strcmp(datasetName, "B0_postBPix") == 0){
            cout << "MC Dataset : B0 -> Tau -> 3Mu" << endl << endl;
            TChain* chain = new TChain("TreeMakerBkg/ntuple");
        //AddFile_MCB0_postE_tau3mu
        //OutFile_MCB0_postE_tau3mu
        //AddFile_MCB0_postBPix_tau3mu
        //OutFile_MCB0_postBPix_tau3mu
        myAnalizer class_data(chain, fileout);
        class_data.Loop_Tau3mu(type, datasetName);
        }
        // Bu -> Tau -> 3Mu
        if (strcmp(datasetName, "Bp_preE") == 0 || strcmp(datasetName, "Bp_preBPix") == 0 ){
            cout << "MC Dataset : Bp -> Tau -> 3Mu" << endl << endl;
            TChain* chain = new TChain("TreeMakerBkg/ntuple");
        //AddFile_MCBp_preE_tau3mu
        //OutFile_MCBp_preE_tau3mu
        //AddFile_MCBp_preBPix_tau3mu
        //OutFile_MCBp_preBPix_tau3mu
        myAnalizer class_data(chain, fileout);
        class_data.Loop_Tau3mu(type, datasetName);
        }
	// Bu -> Tau -> 3Mu
        if (strcmp(datasetName, "Bp_postE") == 0 || strcmp(datasetName, "Bp_postBPix") == 0){
            cout << "MC Dataset : Bp -> Tau -> 3Mu" << endl << endl;
            TChain* chain = new TChain("TreeMakerBkg/ntuple");
        //AddFile_MCBp_postE_tau3mu
        //OutFile_MCBp_postE_tau3mu
        //AddFile_MCBp_postBPix_tau3mu
        //OutFile_MCBp_postBPix_tau3mu
        myAnalizer class_data(chain, fileout);
        class_data.Loop_Tau3mu(type, datasetName);
        }
        
        // ###Other samples
        // Ds -> PhiPi -> MuMuPi
         if (strcmp(datasetName, "DsPhiPi_preE") == 0 || strcmp(datasetName, "DsPhiPi_preBPix") == 0){
            cout << "MC Dataset : Ds -> PhiPi -> MuMuPi" << endl << endl;
            TChain* chain = new TChain("Tree3Mu/ntuple");
        //AddFile_MCDsPhiPi_preE_tau3mu
        //OutFile_MCDsPhiPi_preE_tau3mu
        //AddFile_MCDsPhiPi_preBPix_tau3mu
        //OutFile_MCDsPhiPi_preBPix_tau3mu
            myAnalizer_control class_data(chain, fileout);
            class_data.Loop_DsPhiPi(type, datasetName);
         }
	// Ds -> PhiPi -> MuMuPi
         if (strcmp(datasetName, "DsPhiPi_postE") == 0 || strcmp(datasetName, "DsPhiPi_postBPix") == 0){
            cout << "MC Dataset : Ds -> PhiPi -> MuMuPi" << endl << endl;
            TChain* chain = new TChain("Tree3Mu/ntuple");
        //AddFile_MCDsPhiPi_postE_tau3mu
        //OutFile_MCDsPhiPi_postE_tau3mu
        //AddFile_MCDsPhiPi_postBPix_tau3mu
        //OutFile_MCDsPhiPi_postBPix_tau3mu
            myAnalizer_control class_data(chain, fileout);
            class_data.Loop_DsPhiPi(type, datasetName);
         }
        // Ds -> PhiMuNu -> 3MuNu
         if (strcmp(datasetName, "DsPhiMuNu") == 0){
         cout << "MC Dataset : Ds -> PhiMuNu -> 3MuNu" << endl << endl;
         TChain* chain = new TChain("TreeMakerBkg/ntuple");
        //AddFile_MCDsPhiMuNu_tau3mu
        //OutFile_MCDsPhiMuNu_tau3mu
        myAnalizer class_data(chain, fileout);
        class_data.Loop_Tau3mu(type, datasetName);
	}
   }

   //Data - tau3mu
   if(strcmp(type, "data") == 0){
	cout << "this is data" << endl;
        cout << "Data " << datasetName << endl << endl;
        TChain* chain = new TChain("TreeMakerBkg/ntuple");
        //AddFile_data_tau3mu
        //OutFile_data_tau3mu
        myAnalizer class_data(chain, fileout);
        class_data.Loop_Tau3mu(type, datasetName);
    }
    
    if (strcmp(type, "data_control") == 0){
        cout << "Control channel analysis on data" << endl;
        cout << "Data " << datasetName << endl << endl;
        TChain* chain = new TChain("Tree3Mu/ntuple");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1278.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1298.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1217.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1070.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1358.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1125.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1167.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1265.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1240.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1328.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1085.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1184.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1321.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1378.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1118.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1072.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1038.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1373.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1248.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1386.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1223.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1320.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1113.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1297.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1371.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1154.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1128.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1414.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1370.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1225.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1361.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1086.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1031.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1390.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1062.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1230.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1100.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1301.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1045.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1334.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1391.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1151.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1162.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1280.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1080.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1346.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1384.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1011.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1176.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1392.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1164.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1152.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1172.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1287.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1124.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1133.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1180.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1353.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1171.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1238.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1069.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1056.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1232.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1229.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1103.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1252.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1157.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1131.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1097.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1289.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1149.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1032.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1166.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1142.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1276.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1357.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1360.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1222.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1333.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1021.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1158.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1343.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1375.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1025.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1314.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1302.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1326.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1007.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1209.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1060.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1001.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1019.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1382.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1129.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1286.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1015.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1132.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1231.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1307.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1258.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1156.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1351.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1385.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1183.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1091.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1059.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1117.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1146.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1088.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1003.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1081.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1108.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1233.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1365.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1237.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1359.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1355.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1111.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1089.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1402.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1135.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1063.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1004.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1290.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1093.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1394.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1169.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1174.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1284.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1034.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1339.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1337.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1094.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1388.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1393.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1067.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1253.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1106.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1363.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1262.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1260.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1415.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1071.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1052.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1076.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1018.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1218.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1136.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1364.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1219.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1035.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1300.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1053.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1079.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1347.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1066.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1047.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1406.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1349.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1107.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1012.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1277.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1264.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1036.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1291.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1292.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1145.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1214.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1030.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1013.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1202.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1153.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1336.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1317.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1205.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1099.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1024.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1282.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1410.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1335.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1272.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1281.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1366.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1212.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1246.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1203.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1329.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1087.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1207.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1115.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1409.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1270.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1243.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1404.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1023.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1048.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1228.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1354.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1213.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0001/Tree_PhiPi_1116.root");
        fileout = "AnalysedTree_data_control_2024F_5_control5.root";
        myAnalizer_control class_data(chain, fileout);
        class_data.Loop_DsPhiPi(type, datasetName); 
    }

    return 0;
}
