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
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_420.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_944.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_849.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_996.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_937.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_747.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_439.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_389.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_976.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_369.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_924.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_234.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_298.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_447.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_146.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_551.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_720.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_506.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_870.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_352.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_353.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_648.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_958.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_637.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_267.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_537.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_338.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_472.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_922.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_765.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_592.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_242.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_920.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_614.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_516.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_670.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_820.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_593.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_144.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_213.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_904.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_557.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_763.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_380.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_395.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_697.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_216.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_175.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_117.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_872.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_313.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_731.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_442.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_652.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_894.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_114.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_43.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_75.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_723.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_308.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_706.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_534.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_722.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_486.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_957.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_827.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_307.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_664.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_293.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_193.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_843.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_66.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_919.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_646.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_578.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_945.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_333.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_950.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_946.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_93.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_766.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_150.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_37.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_339.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_517.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_695.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_86.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_918.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_464.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_62.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_816.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_554.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_564.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_458.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_173.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_365.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_552.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_350.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_147.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_491.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_94.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_984.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_912.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_69.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_685.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_387.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_544.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_784.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_573.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_906.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_876.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_289.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_526.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_656.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_359.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_448.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_979.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_283.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_909.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_161.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_966.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_331.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_123.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_10.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_657.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_268.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_926.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_927.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_542.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_199.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_243.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_201.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_692.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_479.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_437.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_757.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_441.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_309.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_612.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_519.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_933.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_167.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_535.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_838.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_875.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_662.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_943.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_25.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_55.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_178.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_830.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_153.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_826.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_846.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_715.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_588.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_639.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_606.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_451.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_549.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_145.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_512.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_497.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_28.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_3.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_229.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_959.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_941.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_215.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_902.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_440.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_914.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_421.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_236.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_895.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_769.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_718.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_744.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_211.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_48.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_638.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_732.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_251.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_674.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_107.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_385.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_465.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_972.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_65.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_867.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_433.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_323.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_928.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_576.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_475.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_39.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_162.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_907.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_509.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraF_stream5_Mini_v3/240917_161951/0000/Tree_PhiPi_672.root");
        fileout = "AnalysedTree_data_control_2024F_5_control0.root";
        myAnalizer_control class_data(chain, fileout);
        class_data.Loop_DsPhiPi(type, datasetName); 
    }

    return 0;
}
