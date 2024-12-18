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
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_386.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_381.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_143.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_5.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_30.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_111.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_156.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_63.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_102.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_222.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_364.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_256.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_321.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_401.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_180.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_197.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_282.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_235.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_92.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_179.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_290.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_432.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_244.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_73.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_27.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_355.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_24.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_392.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_89.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_202.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_356.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_424.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_253.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_459.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_319.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_429.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_49.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_247.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_280.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_228.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_452.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_214.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_310.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_320.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_87.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_372.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_449.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_98.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_413.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_195.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_404.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_2.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_177.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_159.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_276.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_262.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_406.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_227.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_468.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_139.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_7.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_60.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_84.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_33.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_379.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_435.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_85.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_324.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_334.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_130.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_170.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_444.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_318.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_284.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_181.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_136.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_110.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_325.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_249.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_101.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_358.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_121.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_210.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_315.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_367.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_53.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_295.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_80.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_446.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_357.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_19.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_20.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_135.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_414.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_394.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_17.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_106.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_322.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_416.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_122.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_373.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_160.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_198.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_34.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_252.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_115.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_191.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_363.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_445.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_417.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_186.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_354.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_109.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_103.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_200.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_378.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_291.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_127.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_91.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_436.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_113.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_189.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_418.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_314.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_99.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_207.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_275.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_272.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_403.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_59.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_317.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_410.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_360.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_460.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_12.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_182.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_44.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_4.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_70.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_346.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_174.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_81.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_165.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_430.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_42.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_50.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_132.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_208.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_455.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_402.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_327.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_297.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_8.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_83.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_204.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_35.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_224.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_248.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_408.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_32.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_126.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_166.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_250.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_471.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_64.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_328.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_97.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_220.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_415.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_285.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_296.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_370.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_120.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_265.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_231.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_467.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_100.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_348.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_454.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_456.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_277.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_390.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_376.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_332.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_72.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_209.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_196.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_335.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_466.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_443.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_241.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_264.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_18.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_351.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_21.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_190.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_366.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_361.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_396.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass3/SkimDsPhiPi_2024eraD_stream3_Mini_v3/240917_161520/0000/Tree_PhiPi_287.root");
        fileout = "AnalysedTree_data_control_2024D_3_control1.root";
        myAnalizer_control class_data(chain, fileout);
        class_data.Loop_DsPhiPi(type, datasetName); 
    }

    return 0;
}
