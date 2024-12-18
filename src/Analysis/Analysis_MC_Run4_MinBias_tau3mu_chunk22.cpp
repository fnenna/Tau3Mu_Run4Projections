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
    if( strcmp(type, "MC") == 0 && (strcmp(datasetName, "Run4_MinBias")!=0 && strcmp(datasetName, "DsPhiPi_preE") != 0 && strcmp(datasetName, "DsPhiPi_postE") != 0 && strcmp(datasetName, "DsPhiMuNu") != 0 && strcmp(datasetName, "Ds_preE") != 0 && strcmp(datasetName, "Ds_postE") != 0 && strcmp(datasetName, "Bp_preE") != 0 && strcmp(datasetName, "Bp_postE") != 0 && strcmp(datasetName, "B0_preE") != 0 && strcmp(datasetName, "B0_postE") != 0 && strcmp(datasetName, "Ds_2018") != 0 && strcmp(datasetName, "DsPhiPi_preBPix") != 0 && strcmp(datasetName, "DsPhiPi_postBPix") != 0 && strcmp(datasetName, "Ds_preBPix") != 0 && strcmp(datasetName, "Ds_postBPix") != 0 && strcmp(datasetName, "Bp_preBPix") != 0 && strcmp(datasetName, "Bp_postBPix") != 0 && strcmp(datasetName, "B0_preBPix") != 0 && strcmp(datasetName, "B0_postBPix") != 0) ){
        cout << "The second argument is wrong! Please choose between 'Run4_MinBias', 'Ds_preE - Ds_postE', 'B0_preE - B0_postE', 'Bp_preE - Bp_postE', 'DsPhiMuNu' and 'DsPhiPi_preE - DsPhiPi_postE'" << endl;
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
    //Run 4
    if (strcmp(datasetName, "Run4_MinBias") == 0){
         cout << "MC Dataset : Min Bias for Run4" << endl << endl;
         TChain* chain = new TChain("TreeMakerBkg/ntuple");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2544.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2604.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2903.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2866.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2196.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2286.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2749.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2796.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2085.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2811.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2703.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2881.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2584.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2322.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2115.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2418.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2048.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2894.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2068.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2501.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2118.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2605.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2327.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2666.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2990.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2763.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2649.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2021.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2889.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2709.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2504.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2595.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2610.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2436.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2362.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2088.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2097.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2044.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2774.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2729.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2912.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2824.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2448.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2995.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2743.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2528.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2988.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2674.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2158.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2764.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2921.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2251.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2941.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2913.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2836.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2971.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2134.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2810.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2238.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2506.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2642.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2662.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2226.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2735.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2787.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2785.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2077.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2543.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2470.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2033.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2273.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2252.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2786.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2439.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2771.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2321.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2725.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2830.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2357.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2775.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2282.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2367.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2025.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2560.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2562.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2283.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2582.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2702.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2255.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2550.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2664.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2391.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2681.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2568.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2831.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2369.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2475.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2061.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2139.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2402.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2621.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2335.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2144.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2647.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2942.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2730.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2887.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2855.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2452.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2318.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2458.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2615.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2271.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2686.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2104.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2278.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2651.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2011.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2298.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2424.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2016.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2508.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2095.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2669.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2633.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2163.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2266.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2330.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2268.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2791.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2892.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2429.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2844.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2209.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2548.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2111.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2076.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2954.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2461.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2804.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2907.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2301.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2338.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2601.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2923.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2447.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2096.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2142.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2806.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2638.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2343.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2374.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2116.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2769.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2191.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2680.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2040.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2819.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2788.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2293.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2389.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2353.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2776.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2404.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2212.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2818.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2174.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2967.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2336.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2670.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2194.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2989.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2136.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2311.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2192.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2736.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2079.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2026.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2929.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2107.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2745.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2354.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2213.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2427.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2200.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2808.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2617.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2484.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2083.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2125.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2968.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2547.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2947.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2292.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2715.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2460.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2500.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2415.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2746.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2575.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2324.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2726.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2375.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2370.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2133.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2961.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2502.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2237.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2316.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2221.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2631.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2549.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2757.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2563.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2148.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2756.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2574.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2127.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2556.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2975.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2567.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2074.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2082.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2926.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2862.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2720.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2525.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2620.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2654.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2297.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2738.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2692.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2430.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2569.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2533.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2564.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2022.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2882.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2966.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2114.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2928.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2288.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2261.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2628.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2087.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2813.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2978.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2498.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2970.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2817.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2883.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2464.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2639.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2625.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0002/TreeMC_2217.root");
        fileout = "AnalysedTree_MC_Run4_MinBias_tau3mu22.root";
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
        //AddFile_data_control_control
        //OutFile_data_control_control
        myAnalizer_control class_data(chain, fileout);
        class_data.Loop_DsPhiPi(type, datasetName); 
    }

    return 0;
}
