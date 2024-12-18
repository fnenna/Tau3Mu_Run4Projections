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
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_117.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_114.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_43.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_75.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_66.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_93.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_37.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_86.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_62.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_94.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_69.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_10.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_25.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_55.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_28.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_3.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_48.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_107.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_65.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_39.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_116.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_71.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_11.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_78.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_15.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_13.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_82.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_119.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_23.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_47.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_112.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_77.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_36.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_54.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_46.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_1.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_104.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_68.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_76.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_26.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_56.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_38.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_14.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_74.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_61.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_51.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_79.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_88.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_16.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_5.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_30.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_111.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_63.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_102.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_92.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_73.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_27.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_24.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_89.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_49.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_87.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_98.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_2.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_7.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_60.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_84.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_33.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_85.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_110.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_101.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_121.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_53.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_80.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_19.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_20.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_17.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_106.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_34.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_115.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_109.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_103.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_91.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_113.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_99.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_59.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_12.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_44.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_4.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_70.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_81.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_42.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_50.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_8.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_83.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_35.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_32.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_64.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_97.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_120.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_100.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_72.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_18.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_21.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_40.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_45.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_90.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_58.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_29.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_105.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_22.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_52.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_31.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_108.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_6.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_9.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_41.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_95.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_118.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_57.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_67.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass6/SkimDsPhiPi_2024eraB_stream6_Mini_v3/240917_152215/0000/Tree_PhiPi_96.root");
        fileout = "AnalysedTree_data_control_2024B_6_control0.root";
        myAnalizer_control class_data(chain, fileout);
        class_data.Loop_DsPhiPi(type, datasetName); 
    }

    return 0;
}
