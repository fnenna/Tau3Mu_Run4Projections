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
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_163.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_312.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_336.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_286.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_40.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_278.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_217.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_192.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_300.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_212.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_254.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_271.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_45.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_90.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_259.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_427.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_134.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_58.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_29.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_105.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_22.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_52.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_428.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_223.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_368.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_151.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_31.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_270.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_301.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_274.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_108.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_6.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_168.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_238.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_391.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_9.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_258.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_171.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_405.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_194.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_41.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_237.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_266.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_125.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_434.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_377.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_311.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_304.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_470.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_230.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_384.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_349.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_294.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_343.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_326.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_95.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_140.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_131.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_118.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_57.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_67.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_462.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_383.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_393.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_158.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_96.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_382.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass5/SkimDsPhiPi_2024eraD_stream5_Mini_v3/240917_161541/0000/Tree_PhiPi_185.root");
        fileout = "AnalysedTree_data_control_2024D_5_control2.root";
        myAnalizer_control class_data(chain, fileout);
        class_data.Loop_DsPhiPi(type, datasetName); 
    }

    return 0;
}
