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
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5944.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5166.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5819.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5629.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5370.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5800.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5914.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5745.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5102.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5078.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5389.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5072.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5774.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5423.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5667.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5993.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5655.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5363.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5891.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5476.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5860.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5067.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5446.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5992.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5125.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5369.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5559.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5646.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5540.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5209.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5781.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5620.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5603.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5339.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5008.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5150.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5703.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5957.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5783.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5305.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5463.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5593.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5433.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5457.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5637.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5829.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5228.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5695.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5276.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5184.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5080.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5685.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5242.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5354.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5733.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5995.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5931.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5834.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5484.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5742.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5387.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5825.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5567.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5851.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5212.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5934.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5816.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5024.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5107.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5187.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5845.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5178.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5878.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5237.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5126.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5709.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5324.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5444.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5676.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5832.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5267.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5255.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5270.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5751.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5158.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5420.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5552.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5859.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5600.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5503.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5946.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5921.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5254.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5960.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5118.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5933.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5570.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5010.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5725.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5758.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5382.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5579.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5465.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5084.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5288.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5167.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5750.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5984.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5809.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5083.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5361.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5880.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5458.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5691.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5360.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5963.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5621.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5023.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5515.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5662.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5669.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5506.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5109.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5338.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5062.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5340.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5726.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5753.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5585.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5232.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5521.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5512.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5757.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5971.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5499.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5453.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5490.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5630.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5040.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5099.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5478.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5359.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5345.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5170.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5325.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5871.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5795.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5710.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5542.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5951.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5882.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5573.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5025.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5904.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5412.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5588.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5070.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5411.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5674.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5645.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5259.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5541.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5240.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5965.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5388.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5524.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5366.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5462.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5474.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5068.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5606.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5509.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5991.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5287.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5988.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5849.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5590.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5888.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5827.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5157.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5374.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5858.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5021.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5487.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5529.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5114.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5461.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5241.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5375.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5956.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5616.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5528.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5358.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5139.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5566.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5246.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5006.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5728.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5872.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5120.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5424.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5592.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5203.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5507.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5171.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5802.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5258.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5227.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5803.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5866.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5818.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5431.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5903.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5223.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5722.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5386.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5191.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5717.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5030.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5658.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5469.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5716.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5731.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5138.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5049.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5310.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5445.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5749.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5978.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5135.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5857.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5482.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5418.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5196.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5983.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5763.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5652.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5615.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5279.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5778.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5011.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5298.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5958.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5711.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5955.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5141.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5317.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5863.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5303.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5702.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5916.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5035.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5675.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5079.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0005/TreeMC_5654.root");
        fileout = "AnalysedTree_MC_Run4_MinBias_tau3mu10.root";
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
