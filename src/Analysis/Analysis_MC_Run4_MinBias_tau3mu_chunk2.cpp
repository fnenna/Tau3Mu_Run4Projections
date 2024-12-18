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
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3711.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3617.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3038.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3095.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3246.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3229.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3753.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3307.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3289.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3582.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3676.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3824.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3934.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3104.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3761.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3740.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3783.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3651.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3268.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3305.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3702.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3380.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3088.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3919.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3080.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3286.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3054.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3342.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3168.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3252.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3141.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3699.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3206.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3435.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3966.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3412.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3819.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3066.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3407.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3280.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3636.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3908.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3266.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3330.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3045.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3820.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3687.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3319.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3472.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3424.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3086.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3969.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3681.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3791.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3118.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3557.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3940.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3073.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3786.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3984.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3162.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3522.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3833.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3620.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3333.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3777.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3396.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3960.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3292.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3633.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3362.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3551.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3218.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3281.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3125.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3789.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3493.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3050.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3145.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3025.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3847.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3771.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3924.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3772.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3821.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3757.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3768.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3871.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3734.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3485.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3057.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3535.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3627.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3800.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3189.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3181.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3227.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3570.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3464.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3456.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3964.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3654.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3410.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3949.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3517.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3047.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3606.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3909.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3499.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3857.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3476.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3724.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3237.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3793.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3287.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3980.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3531.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3744.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3942.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3795.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3436.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3625.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3404.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3236.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3602.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3828.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3696.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3831.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3507.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3645.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3014.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3272.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3764.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3622.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3781.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3941.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3898.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3778.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3842.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3044.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3697.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3902.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3019.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3591.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3064.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3926.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3087.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3972.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3903.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3720.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3552.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3818.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3434.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3767.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3965.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3174.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3304.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3796.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3194.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3787.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3098.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3490.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3785.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3166.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3114.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3353.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3922.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3157.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3629.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3225.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3131.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3704.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3144.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3138.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3694.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3947.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3504.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3865.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3293.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3011.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3315.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3204.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3126.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3364.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3448.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3979.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3001.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3327.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3889.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3175.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3427.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3648.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3155.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3970.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3880.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3379.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3335.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3053.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3609.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3015.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3623.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3090.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3688.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3270.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3628.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3318.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3491.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3158.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3486.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3127.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3640.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3509.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3803.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3440.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3998.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3422.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3034.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3626.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3794.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3897.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3119.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3446.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3644.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3852.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3325.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3733.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3291.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3245.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3387.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3957.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3161.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3154.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3971.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3274.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3525.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3192.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3658.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3548.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3124.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3540.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3975.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3471.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3678.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3614.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3361.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3689.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3075.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3028.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3585.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3323.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3031.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3539.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3562.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3505.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0003/TreeMC_3814.root");
        fileout = "AnalysedTree_MC_Run4_MinBias_tau3mu2.root";
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
