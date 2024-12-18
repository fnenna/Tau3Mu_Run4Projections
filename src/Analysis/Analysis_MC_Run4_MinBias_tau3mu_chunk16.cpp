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
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_600.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_493.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_352.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_657.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_694.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_570.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_636.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_730.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_514.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_504.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_108.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_557.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_28.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_877.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_403.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_295.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_729.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_245.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_44.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_699.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_784.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_486.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_506.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_515.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_680.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_217.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_525.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_882.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_522.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_298.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_991.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_777.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_954.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_172.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_771.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_722.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_176.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_247.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_534.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_828.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_393.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_82.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_563.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_629.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_702.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_241.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_663.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_248.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_604.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_297.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_944.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_122.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_719.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_958.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_565.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_387.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_50.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_608.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_666.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_392.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_619.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_6.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_455.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_302.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_363.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_596.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_228.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_749.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_34.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_404.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_204.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_853.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_941.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_316.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_724.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_90.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_480.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_210.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_606.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_10.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_394.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_201.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_630.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_558.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_72.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_855.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_155.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_391.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_227.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_127.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_355.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_166.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_453.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_416.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_911.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_804.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_781.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_191.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_885.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_20.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_459.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_984.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_767.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_775.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_860.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_280.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_801.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_847.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_933.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_819.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_490.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_383.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_341.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_299.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_102.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_955.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_188.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_190.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_671.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_324.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_194.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_873.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_274.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_829.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_916.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_315.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_697.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_417.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_307.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_47.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_849.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_325.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_649.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_601.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_751.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_256.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_883.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_173.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_37.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_905.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_309.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_229.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_310.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_648.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_747.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_491.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_52.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_149.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_764.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_246.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_542.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_598.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_26.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_520.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_121.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_170.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_615.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_148.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_340.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_623.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_840.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_419.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_181.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_930.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_888.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_21.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_758.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_46.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_249.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_271.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_447.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_120.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_929.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_347.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_642.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_252.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_449.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_942.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0000/TreeMC_561.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1292.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1080.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1083.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1169.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1592.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1204.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1492.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1670.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1326.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1168.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1417.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1211.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1258.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1172.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1193.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1757.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1050.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1431.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1700.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1917.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1270.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1890.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1017.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1034.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1855.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1893.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1594.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1276.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1934.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1553.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1786.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1773.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1103.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1701.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1226.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1943.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1693.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1366.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1403.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1278.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1479.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1772.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1209.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1729.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1964.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1756.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1777.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1194.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1497.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1865.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1037.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1825.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1260.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1641.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1850.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1066.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1288.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1434.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1968.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1543.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1596.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1506.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1065.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1848.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1705.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1090.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1611.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1387.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1659.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1026.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1706.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1984.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1329.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1982.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1096.root");
        chain->AddFile("/lustre/cms/store/user/fnenna/MinBias_TuneCP5_14TeV-pythia8/SkimTau3mu_MC_Run4/241129_110406/0001/TreeMC_1134.root");
        fileout = "AnalysedTree_MC_Run4_MinBias_tau3mu16.root";
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
