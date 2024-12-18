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
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_420.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_439.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_389.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_369.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_234.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_298.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_447.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_146.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_352.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_353.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_267.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_338.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_472.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_242.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_144.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_213.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_380.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_395.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_216.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_175.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_117.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_313.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_442.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_114.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_43.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_75.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_308.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_486.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_307.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_293.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_193.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_66.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_333.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_93.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_150.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_37.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_339.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_86.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_464.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_62.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_458.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_173.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_365.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_350.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_147.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_491.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_94.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_69.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_387.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_289.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_359.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_448.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_283.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_161.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_331.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_123.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_10.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_268.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_199.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_243.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_201.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_479.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_437.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_441.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_309.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_167.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_25.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_55.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_178.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_153.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_451.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_145.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_28.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_3.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_229.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_215.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_440.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_421.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_236.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_211.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_48.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_251.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_107.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_385.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_465.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_65.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_433.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_323.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_475.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_39.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_162.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_187.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_345.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_116.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_425.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_409.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_362.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_128.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_239.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_71.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_255.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_398.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_225.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_371.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_233.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_461.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_340.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_232.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_11.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_411.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_78.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_155.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_484.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_419.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_374.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_206.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_15.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_337.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_13.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_226.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_438.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_82.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_292.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_245.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_261.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_269.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_119.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_219.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_240.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_260.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_23.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_183.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_281.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_463.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_47.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_316.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_152.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_397.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_257.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_149.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_129.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_407.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_112.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_157.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_457.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_77.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_36.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_124.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_142.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_412.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_54.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_148.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_422.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_305.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_133.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_46.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_1.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_104.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_487.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_164.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_172.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_68.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_453.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_76.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_306.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_26.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_426.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_400.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_478.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_493.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_221.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_141.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_169.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_56.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_38.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_299.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_138.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_263.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_399.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_205.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_14.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_476.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_450.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_469.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_375.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_288.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_137.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_473.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_388.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_74.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_61.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_347.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_203.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_279.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_51.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_482.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_184.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_342.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_154.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraC_stream7_Mini_v3/240917_200946/0000/Tree_PhiPi_329.root");
        fileout = "AnalysedTree_data_control_2024C_7_control0.root";
        myAnalizer_control class_data(chain, fileout);
        class_data.Loop_DsPhiPi(type, datasetName); 
    }

    return 0;
}
