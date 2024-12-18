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
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_597.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_767.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_923.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_759.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_210.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_315.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_775.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_494.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_735.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_367.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_668.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_774.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_53.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_591.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_295.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_609.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_977.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_580.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_654.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_856.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_80.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_752.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_446.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_357.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_19.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_841.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_20.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_135.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_414.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_394.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_607.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_725.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_17.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_106.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_804.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_322.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_899.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_416.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_122.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_373.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_160.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_198.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_34.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_963.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_252.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_115.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_191.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_728.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_363.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_445.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_417.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_186.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_354.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_109.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_103.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_200.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_655.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_378.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_974.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_291.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_866.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_521.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_786.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_127.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_91.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_596.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_436.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_113.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_513.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_917.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_189.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_418.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_887.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_921.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_764.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_667.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_314.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_527.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_99.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_815.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_510.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_207.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_677.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_543.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_782.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_647.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_661.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_577.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_807.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_275.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_817.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_854.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_272.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_608.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_403.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_59.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_799.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_965.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_317.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_410.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_360.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_460.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_531.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_518.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_12.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_182.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_968.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_44.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_4.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_70.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_880.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_346.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_174.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_669.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_954.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_485.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_165.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_835.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_430.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_862.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_489.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_42.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_50.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_575.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_132.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_208.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_455.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_402.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_327.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_931.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_297.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_8.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_483.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_83.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_204.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_842.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_642.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_703.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_611.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_726.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_978.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_869.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_35.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_859.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_224.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_686.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_724.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_783.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_248.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_408.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_32.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_650.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_126.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_823.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_530.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_166.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_852.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_250.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_471.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_64.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_328.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_547.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_97.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_220.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_524.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_632.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_415.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_999.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_746.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_285.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_991.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_296.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_837.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_370.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_754.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_688.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_604.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_845.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_528.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_949.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_903.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_120.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_663.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_265.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_231.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_908.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_467.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_675.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_100.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_348.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_730.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_900.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_825.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_809.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_793.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_454.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_694.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_456.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_989.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass1/SkimDsPhiPi_2024eraF_stream1_Mini_v3/240917_161910/0000/Tree_PhiPi_886.root");
        fileout = "AnalysedTree_data_control_2024F_1_control3.root";
        myAnalizer_control class_data(chain, fileout);
        class_data.Loop_DsPhiPi(type, datasetName); 
    }

    return 0;
}
