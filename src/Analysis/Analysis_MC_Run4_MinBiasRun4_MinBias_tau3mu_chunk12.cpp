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
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6180.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6053.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6113.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6135.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6015.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6155.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6042.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6071.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6143.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6179.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6062.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6076.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6101.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6130.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6249.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6122.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6035.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6120.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6218.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6027.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6183.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6219.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6177.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6235.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6119.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6045.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6091.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6017.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6086.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6204.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6255.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6161.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6072.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6252.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6105.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6181.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6166.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6197.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6214.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6192.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6186.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6239.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6172.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6083.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6142.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6229.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6165.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6221.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6022.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6058.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6150.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6078.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6163.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6002.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6084.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6098.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6176.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6049.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6151.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6134.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6085.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6170.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6202.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6007.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6160.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6026.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6125.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6158.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6245.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6205.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6132.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6036.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6038.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6189.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6044.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6016.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6236.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6057.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6209.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6037.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6216.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6033.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6169.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6095.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6220.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6067.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6184.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6014.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6187.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6126.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6188.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6032.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6225.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6028.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6174.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6147.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6079.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6136.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6010.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6090.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6201.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6200.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6146.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6222.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6031.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6198.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6195.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6153.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6242.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6106.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6043.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6141.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6077.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6128.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6006.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6127.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6088.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6190.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6096.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6093.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6029.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6009.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6213.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6123.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6250.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6052.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6117.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6094.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6173.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6107.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6131.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6051.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6193.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6244.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6247.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6034.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6116.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6243.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6003.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6054.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6019.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6025.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6256.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6257.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6063.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6099.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6137.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6012.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6226.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6232.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6046.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6138.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6223.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6065.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6040.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6129.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6217.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6103.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6013.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6194.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6240.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6196.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6191.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6074.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6047.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6185.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6199.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6050.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6159.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6251.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6149.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6241.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6059.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6056.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6207.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6203.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6178.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6162.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6001.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6075.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6168.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6246.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6227.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6253.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6080.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6171.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6234.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6048.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6144.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6066.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6064.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6097.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6208.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6110.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6212.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6111.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6145.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6139.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6175.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0006/TreeMC_6081.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_489.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_963.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_318.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_300.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_113.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_85.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_875.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_251.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_835.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_214.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_205.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_734.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_281.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_55.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_943.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_177.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_581.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_8.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_621.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_610.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_532.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_627.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_157.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_275.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_566.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_254.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_818.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_559.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_212.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_791.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_650.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_79.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_934.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_369.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_476.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_792.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_45.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_633.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_60.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_409.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_128.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_9.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_358.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_100.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_802.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_516.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_676.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_706.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_707.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_41.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_151.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_448.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_428.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_896.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_909.root");
        fileout = "AnalysedTree_MC_Run4_MinBias_tau3mu12.root";
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
