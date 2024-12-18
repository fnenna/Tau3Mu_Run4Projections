// -*- C++ -*-
//
// Package:    GenAnalyser/GenAnalyzer
// Class:      GenAnalyzer
//
/**\class GenAnalyzer GenAnalyzer.cc GenAnalyser/GenAnalyzer/plugins/GenAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Federica Maria Simone
//         Created:  Thu, 28 Mar 2024 08:07:39 GMT
//
//

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"

#include "TTree.h"
//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.

using reco::TrackCollection;

class GenAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources> {
public:
  explicit GenAnalyzer(const edm::ParameterSet&);
  ~GenAnalyzer() override;

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  void beginJob() override;
  void analyze(const edm::Event&, const edm::EventSetup&) override;
  void endJob() override;

  // ----------member data ---------------------------
  //edm::EDGetTokenT<TrackCollection> tracksToken_;  //used to select what tracks to read from configuration file
  edm::EDGetTokenT<edm::View<reco::GenParticle> > genParticles_;

  //tree
  TTree*      tree_;
  edm::Service<TFileService> fs;
  
  std::vector<int> GenParticle_PdgId, GenParticle_MotherPdgId, GenParticle_GrandMotherPdgId;
  std::vector<double> GenParticle_P, GenParticle_Pt, GenParticle_Eta,    GenParticle_Phi, GenParticle_vx, GenParticle_vy, GenParticle_vz;
    
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
GenAnalyzer::GenAnalyzer(const edm::ParameterSet& iConfig){
  genParticles_ = consumes<edm::View<reco::GenParticle>  > (iConfig.getParameter<edm::InputTag>("genParticleLabel"));
}

GenAnalyzer::~GenAnalyzer() {
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  //
  // please remove this method altogether if it would be left empty
}

//
// member functions
//

// ------------ method called for each event  ------------
void GenAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  using namespace edm;

  edm::Handle< edm::View<reco::GenParticle> > genParticles;
  iEvent.getByToken(genParticles_, genParticles);

  uint j=0;
  uint ngenP=genParticles->size();
  std::vector<int> genPidx;
  //uint tauRaw=-999; //int DsRaw=-999;
  
//          cout<<"****************GenLevel Info Begin********************"<<endl;
  for(edm::View<reco::GenParticle>::const_iterator gp=genParticles->begin(); gp!=genParticles->end(), j<ngenP; ++gp , ++j){
      //if(fabs(gp->pdgId())==15) tauRaw = j;
          
    if(fabs(gp->pdgId())==13 || fabs(gp->pdgId())==15  || fabs(gp->pdgId())==11 || fabs(gp->pdgId())==211 || fabs(gp->pdgId())==321 ||  fabs(gp->pdgId())==12  || fabs(gp->pdgId())==14 || fabs(gp->pdgId())==16 || fabs(gp->pdgId())==431 || fabs(gp->pdgId())==511 || fabs(gp->pdgId())==521) {
        GenParticle_PdgId.push_back(gp->pdgId());
        GenParticle_P.push_back(gp->p());
        GenParticle_Pt.push_back(gp->pt());
        GenParticle_Eta.push_back(gp->eta());
        GenParticle_Phi.push_back(gp->phi());
        GenParticle_vx.push_back(gp->vx());
        GenParticle_vy.push_back(gp->vy());
        GenParticle_vz.push_back(gp->vz());
        if (gp->numberOfMothers()) {
            GenParticle_MotherPdgId.push_back(gp->mother(0)->pdgId());
            if(gp->mother(0)->mother(0)) {
                GenParticle_GrandMotherPdgId.push_back(gp->mother(0)->mother(0)->pdgId());
            }else{
                GenParticle_GrandMotherPdgId.push_back(-99);
            }
        }else{
            GenParticle_MotherPdgId.push_back(-99);
        }
    }
 //   if(fabs(gp->pdgId())==13){
 //     if (gp->numberOfMothers()) {
 //       if(fabs(gp->mother(0)->pdgId())==15){
 //         if(gp->mother(0)->mother(0)) {
 //           if(fabs(gp->mother(0)->mother(0)->pdgId())==431 || fabs(gp->mother(0)->mother(0)->pdgId())==34 ){
 //              genPidx.push_back(j);
 //              genPt.push_back(j);
 //           }
 //         }
 //       }
 //     }
 //   }
  }
  tree_->Fill();

  GenParticle_PdgId.clear();
  GenParticle_Pt.clear();
  GenParticle_P.clear();
  GenParticle_Eta.clear();
  GenParticle_Phi.clear();
  GenParticle_MotherPdgId.clear();
  GenParticle_GrandMotherPdgId.clear();
  GenParticle_vx.clear();
  GenParticle_vy.clear();
  GenParticle_vz.clear();
}

// ------------ method called once each job just before starting event loop  ------------
void GenAnalyzer::beginJob() {
  // please remove this method if not needed
  tree_ = fs->make<TTree>("ntuple","LFVTau ntuple");

  tree_->Branch("GenParticle_PdgId", &GenParticle_PdgId);
  tree_->Branch("GenParticle_Pt", &GenParticle_Pt);
  tree_->Branch("GenParticle_P",  &GenParticle_P);
  tree_->Branch("GenParticle_Eta", &GenParticle_Eta);
  tree_->Branch("GenParticle_Phi", &GenParticle_Phi);
  tree_->Branch("GenParticle_MotherPdgId", &GenParticle_MotherPdgId);
  tree_->Branch("GenParticle_GrandMotherPdgId", &GenParticle_GrandMotherPdgId);
  tree_->Branch("GenParticle_vx", &GenParticle_vx);
  tree_->Branch("GenParticle_vy", &GenParticle_vy);
  tree_->Branch("GenParticle_vz", &GenParticle_vz);

}

// ------------ method called once each job just after ending the event loop  ------------
void GenAnalyzer::endJob() {
  tree_->GetDirectory()->cd();
  tree_->Write();
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void GenAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addWithDefaultLabel(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(GenAnalyzer);
