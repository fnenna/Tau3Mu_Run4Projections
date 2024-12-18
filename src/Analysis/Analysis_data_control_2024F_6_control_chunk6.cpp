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
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1354.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1213.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1116.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1008.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1178.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1313.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1295.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1168.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1383.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1312.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1215.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1058.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1175.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1315.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1077.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1160.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1275.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1247.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1042.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1055.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1380.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1049.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1185.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1268.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1261.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1344.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1288.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1319.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1037.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1120.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1372.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1000.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1192.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1416.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1110.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1112.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1161.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1006.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1350.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1374.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1412.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1121.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1309.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1144.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1224.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1084.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1220.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1191.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1376.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1242.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1026.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1323.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1122.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1417.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1249.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1043.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1196.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1208.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1345.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1101.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1028.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1352.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1294.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1029.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1259.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1293.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1092.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1114.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1046.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1227.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1408.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1104.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1342.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1400.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1327.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1126.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1283.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1057.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1159.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1041.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1256.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1395.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1009.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1369.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1316.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1074.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1377.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1061.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1005.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1311.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1204.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1187.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1397.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1254.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1082.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1195.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1379.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1064.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1267.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1147.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1150.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1239.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1226.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1198.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1083.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1241.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1182.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1188.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1271.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1163.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1308.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1181.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1324.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1199.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1033.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1020.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1189.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1201.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1040.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1251.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1255.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1123.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1236.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1137.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1250.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1263.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1143.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1216.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1078.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1002.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1134.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1130.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1304.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1299.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1090.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1348.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1305.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1389.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1285.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1279.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1234.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1039.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1065.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1141.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1331.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1193.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1367.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1244.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1396.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1411.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1109.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1338.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1096.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1318.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1138.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1387.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1399.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1356.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1190.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1405.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1273.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1194.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1186.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1165.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1322.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1051.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1266.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1177.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1017.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1119.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1221.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1155.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1296.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1303.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1044.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1197.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1368.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1200.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1105.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1068.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1095.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1269.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1148.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1407.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1140.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1341.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1010.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1054.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1098.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1257.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1362.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1102.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1170.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1014.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1420.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1330.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1401.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1413.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1206.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraF_stream6_Mini_v3/240917_162004/0001/Tree_PhiPi_1073.root");
        fileout = "AnalysedTree_data_control_2024F_6_control6.root";
        myAnalizer_control class_data(chain, fileout);
        class_data.Loop_DsPhiPi(type, datasetName); 
    }

    return 0;
}
