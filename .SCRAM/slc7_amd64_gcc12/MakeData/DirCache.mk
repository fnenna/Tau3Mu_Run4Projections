ifeq ($(strip $(PluginsTrackFromCandProducerAuto)),)
PluginsTrackFromCandProducerAuto := self/src/Plugins/TrackFromCandProducer/plugins
PLUGINS:=yes
PluginsTrackFromCandProducerAuto_files := $(patsubst src/Plugins/TrackFromCandProducer/plugins/%,%,$(wildcard $(foreach dir,src/Plugins/TrackFromCandProducer/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PluginsTrackFromCandProducerAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Plugins/TrackFromCandProducer/plugins/BuildFile
PluginsTrackFromCandProducerAuto_LOC_USE := self   FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/PatCandidates DataFormats/HepMCCandidate DataFormats/Candidate FWCore/Utilities CommonTools/UtilAlgos TrackingTools/IPTools L1Trigger/L1TGlobal DataFormats/Common DataFormats/HLTReco CondFormats/DataRecord CondFormats/L1TObjects DataFormats/TrackReco RecoVertex/KalmanVertexFit DataFormats/MuonReco RecoVertex/AdaptiveVertexFit RecoBTag/SecondaryVertex DataFormats/BeamSpot TrackingTools/TransientTrack TrackingTools/Records RecoVertex/KinematicFit RecoVertex/KinematicFitPrimitives RecoVertex/VertexPrimitives HLTrigger/HLTcore rootcore rootgraphics root
PluginsTrackFromCandProducerAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,PluginsTrackFromCandProducerAuto,PluginsTrackFromCandProducerAuto,$(SCRAMSTORENAME_LIB),src/Plugins/TrackFromCandProducer/plugins))
PluginsTrackFromCandProducerAuto_PACKAGE := self/src/Plugins/TrackFromCandProducer/plugins
ALL_PRODS += PluginsTrackFromCandProducerAuto
Plugins/TrackFromCandProducer_forbigobj+=PluginsTrackFromCandProducerAuto
PluginsTrackFromCandProducerAuto_INIT_FUNC        += $$(eval $$(call Library,PluginsTrackFromCandProducerAuto,src/Plugins/TrackFromCandProducer/plugins,src_Plugins_TrackFromCandProducer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
PluginsTrackFromCandProducerAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,PluginsTrackFromCandProducerAuto,src/Plugins/TrackFromCandProducer/plugins))
endif
ALL_COMMONRULES += src_Plugins_TrackFromCandProducer_plugins
src_Plugins_TrackFromCandProducer_plugins_parent := Plugins/TrackFromCandProducer
src_Plugins_TrackFromCandProducer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_TrackFromCandProducer_plugins,src/Plugins/TrackFromCandProducer/plugins,PLUGINS))
ifeq ($(strip $(PluginsMiniAnaTau3MuAuto)),)
PluginsMiniAnaTau3MuAuto := self/src/Plugins/MiniAnaTau3Mu/plugins
PLUGINS:=yes
PluginsMiniAnaTau3MuAuto_files := $(patsubst src/Plugins/MiniAnaTau3Mu/plugins/%,%,$(wildcard $(foreach dir,src/Plugins/MiniAnaTau3Mu/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PluginsMiniAnaTau3MuAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Plugins/MiniAnaTau3Mu/plugins/BuildFile
PluginsMiniAnaTau3MuAuto_LOC_USE := self   DataFormats/PatCandidates DataFormats/HepMCCandidate DataFormats/Candidate FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/Utilities CommonTools/UtilAlgos TrackingTools/IPTools L1Trigger/L1TGlobal DataFormats/Common DataFormats/HLTReco CondFormats/DataRecord CondFormats/L1TObjects DataFormats/TrackReco RecoVertex/KalmanVertexFit DataFormats/MuonReco RecoVertex/AdaptiveVertexFit RecoBTag/SecondaryVertex DataFormats/BeamSpot TrackingTools/TransientTrack TrackingTools/Records RecoVertex/KinematicFit RecoVertex/KinematicFitPrimitives RecoVertex/VertexPrimitives HLTrigger/HLTcore rootcore rootgraphics root
PluginsMiniAnaTau3MuAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,PluginsMiniAnaTau3MuAuto,PluginsMiniAnaTau3MuAuto,$(SCRAMSTORENAME_LIB),src/Plugins/MiniAnaTau3Mu/plugins))
PluginsMiniAnaTau3MuAuto_PACKAGE := self/src/Plugins/MiniAnaTau3Mu/plugins
ALL_PRODS += PluginsMiniAnaTau3MuAuto
Plugins/MiniAnaTau3Mu_forbigobj+=PluginsMiniAnaTau3MuAuto
PluginsMiniAnaTau3MuAuto_INIT_FUNC        += $$(eval $$(call Library,PluginsMiniAnaTau3MuAuto,src/Plugins/MiniAnaTau3Mu/plugins,src_Plugins_MiniAnaTau3Mu_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
PluginsMiniAnaTau3MuAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,PluginsMiniAnaTau3MuAuto,src/Plugins/MiniAnaTau3Mu/plugins))
endif
ALL_COMMONRULES += src_Plugins_MiniAnaTau3Mu_plugins
src_Plugins_MiniAnaTau3Mu_plugins_parent := Plugins/MiniAnaTau3Mu
src_Plugins_MiniAnaTau3Mu_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_MiniAnaTau3Mu_plugins,src/Plugins/MiniAnaTau3Mu/plugins,PLUGINS))
ifeq ($(strip $(PluginsSimpleEventCounterAuto)),)
PluginsSimpleEventCounterAuto := self/src/Plugins/SimpleEventCounter/plugins
PLUGINS:=yes
PluginsSimpleEventCounterAuto_files := $(patsubst src/Plugins/SimpleEventCounter/plugins/%,%,$(wildcard $(foreach dir,src/Plugins/SimpleEventCounter/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PluginsSimpleEventCounterAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Plugins/SimpleEventCounter/plugins/BuildFile
PluginsSimpleEventCounterAuto_LOC_USE := self   FWCore/Framework FWCore/PluginManager FWCore/ParameterSet RecoMuon/MuonIdentification DataFormats/HepMCCandidate DataFormats/Candidate DataFormats/Math FWCore/ServiceRegistry Geometry/CommonTopologies Geometry/GEMGeometry CommonTools/UtilAlgos Utilities/General DataFormats/MuonReco TrackingTools/TransientTrack clhep DataFormats/GEMRecHit DataFormats/DetId DataFormats/GeometrySurface DataFormats/GeometryVector DataFormats/MuonDetId DataFormats/GEMDigi Geometry/CommonDetUnit Geometry/RPCGeometry Geometry/Records MagneticField/Records MagneticField/Engine SimDataFormats/GeneratorProducts SimDataFormats/Track SimDataFormats/TrackingHit SimDataFormats/Vertex SimGeneral/HepPDTRecord SimDataFormats/TrackingAnalysis RecoMuon/DetLayers RecoMuon/Records rootcore rootgraphics root boost RecoMuon/StandAloneTrackFinder RecoMuon/TrackingTools TrackingTools/DetLayers TrackingTools/PatternTools DataFormats/Common DataFormats/TrackReco DataFormats/TrajectorySeed
PluginsSimpleEventCounterAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,PluginsSimpleEventCounterAuto,PluginsSimpleEventCounterAuto,$(SCRAMSTORENAME_LIB),src/Plugins/SimpleEventCounter/plugins))
PluginsSimpleEventCounterAuto_PACKAGE := self/src/Plugins/SimpleEventCounter/plugins
ALL_PRODS += PluginsSimpleEventCounterAuto
Plugins/SimpleEventCounter_forbigobj+=PluginsSimpleEventCounterAuto
PluginsSimpleEventCounterAuto_INIT_FUNC        += $$(eval $$(call Library,PluginsSimpleEventCounterAuto,src/Plugins/SimpleEventCounter/plugins,src_Plugins_SimpleEventCounter_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
PluginsSimpleEventCounterAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,PluginsSimpleEventCounterAuto,src/Plugins/SimpleEventCounter/plugins))
endif
ALL_COMMONRULES += src_Plugins_SimpleEventCounter_plugins
src_Plugins_SimpleEventCounter_plugins_parent := Plugins/SimpleEventCounter
src_Plugins_SimpleEventCounter_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_SimpleEventCounter_plugins,src/Plugins/SimpleEventCounter/plugins,PLUGINS))
ifeq ($(strip $(PluginsRecoMuonAnalyzerAuto)),)
PluginsRecoMuonAnalyzerAuto := self/src/Plugins/RecoMuonAnalyzer/plugins
PLUGINS:=yes
PluginsRecoMuonAnalyzerAuto_files := $(patsubst src/Plugins/RecoMuonAnalyzer/plugins/%,%,$(wildcard $(foreach dir,src/Plugins/RecoMuonAnalyzer/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PluginsRecoMuonAnalyzerAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Plugins/RecoMuonAnalyzer/plugins/BuildFile
PluginsRecoMuonAnalyzerAuto_LOC_USE := self   FWCore/Framework FWCore/PluginManager FWCore/ParameterSet RecoMuon/MuonIdentification DataFormats/MuonReco DataFormats/HepMCCandidate DataFormats/Candidate DataFormats/Math FWCore/ServiceRegistry Geometry/CommonTopologies CommonTools/UtilAlgos Utilities/General TrackingTools/TransientTrack clhep DataFormats/GEMRecHit DataFormats/DetId DataFormats/GeometrySurface DataFormats/GeometryVector DataFormats/MuonDetId DataFormats/GEMDigi Geometry/CommonDetUnit Geometry/RPCGeometry Geometry/GEMGeometry Geometry/Records MagneticField/Records MagneticField/Engine SimDataFormats/GeneratorProducts SimDataFormats/Track SimDataFormats/TrackingHit SimDataFormats/Vertex SimGeneral/HepPDTRecord SimDataFormats/TrackingAnalysis RecoMuon/DetLayers RecoMuon/Records rootcore rootgraphics root boost RecoMuon/StandAloneTrackFinder RecoMuon/TrackingTools TrackingTools/DetLayers TrackingTools/PatternTools DataFormats/Common DataFormats/TrackReco DataFormats/TrajectorySeed
PluginsRecoMuonAnalyzerAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,PluginsRecoMuonAnalyzerAuto,PluginsRecoMuonAnalyzerAuto,$(SCRAMSTORENAME_LIB),src/Plugins/RecoMuonAnalyzer/plugins))
PluginsRecoMuonAnalyzerAuto_PACKAGE := self/src/Plugins/RecoMuonAnalyzer/plugins
ALL_PRODS += PluginsRecoMuonAnalyzerAuto
Plugins/RecoMuonAnalyzer_forbigobj+=PluginsRecoMuonAnalyzerAuto
PluginsRecoMuonAnalyzerAuto_INIT_FUNC        += $$(eval $$(call Library,PluginsRecoMuonAnalyzerAuto,src/Plugins/RecoMuonAnalyzer/plugins,src_Plugins_RecoMuonAnalyzer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
PluginsRecoMuonAnalyzerAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,PluginsRecoMuonAnalyzerAuto,src/Plugins/RecoMuonAnalyzer/plugins))
endif
ALL_COMMONRULES += src_Plugins_RecoMuonAnalyzer_plugins
src_Plugins_RecoMuonAnalyzer_plugins_parent := Plugins/RecoMuonAnalyzer
src_Plugins_RecoMuonAnalyzer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_RecoMuonAnalyzer_plugins,src/Plugins/RecoMuonAnalyzer/plugins,PLUGINS))
ifeq ($(strip $(GenAnalyserGenAnalyzerAuto)),)
GenAnalyserGenAnalyzerAuto := self/src/GenAnalyser/GenAnalyzer/plugins
PLUGINS:=yes
GenAnalyserGenAnalyzerAuto_files := $(patsubst src/GenAnalyser/GenAnalyzer/plugins/%,%,$(wildcard $(foreach dir,src/GenAnalyser/GenAnalyzer/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
GenAnalyserGenAnalyzerAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/GenAnalyser/GenAnalyzer/plugins/BuildFile
GenAnalyserGenAnalyzerAuto_LOC_USE := self   DataFormats/PatCandidates DataFormats/HepMCCandidate DataFormats/Candidate FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/Utilities CommonTools/UtilAlgos TrackingTools/IPTools L1Trigger/L1TGlobal DataFormats/Common DataFormats/HLTReco CondFormats/DataRecord CondFormats/L1TObjects DataFormats/TrackReco RecoVertex/KalmanVertexFit DataFormats/MuonReco RecoVertex/AdaptiveVertexFit RecoBTag/SecondaryVertex DataFormats/BeamSpot TrackingTools/TransientTrack TrackingTools/Records RecoVertex/KinematicFit RecoVertex/KinematicFitPrimitives RecoVertex/VertexPrimitives HLTrigger/HLTcore rootcore rootgraphics root
GenAnalyserGenAnalyzerAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,GenAnalyserGenAnalyzerAuto,GenAnalyserGenAnalyzerAuto,$(SCRAMSTORENAME_LIB),src/GenAnalyser/GenAnalyzer/plugins))
GenAnalyserGenAnalyzerAuto_PACKAGE := self/src/GenAnalyser/GenAnalyzer/plugins
ALL_PRODS += GenAnalyserGenAnalyzerAuto
GenAnalyser/GenAnalyzer_forbigobj+=GenAnalyserGenAnalyzerAuto
GenAnalyserGenAnalyzerAuto_INIT_FUNC        += $$(eval $$(call Library,GenAnalyserGenAnalyzerAuto,src/GenAnalyser/GenAnalyzer/plugins,src_GenAnalyser_GenAnalyzer_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
GenAnalyserGenAnalyzerAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,GenAnalyserGenAnalyzerAuto,src/GenAnalyser/GenAnalyzer/plugins))
endif
ALL_COMMONRULES += src_GenAnalyser_GenAnalyzer_plugins
src_GenAnalyser_GenAnalyzer_plugins_parent := GenAnalyser/GenAnalyzer
src_GenAnalyser_GenAnalyzer_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_GenAnalyser_GenAnalyzer_plugins,src/GenAnalyser/GenAnalyzer/plugins,PLUGINS))
ifeq ($(strip $(PluginsDsPhiPiTreeMakerMINIAuto)),)
PluginsDsPhiPiTreeMakerMINIAuto := self/src/Plugins/DsPhiPiTreeMakerMINI/plugins
PLUGINS:=yes
PluginsDsPhiPiTreeMakerMINIAuto_files := $(patsubst src/Plugins/DsPhiPiTreeMakerMINI/plugins/%,%,$(wildcard $(foreach dir,src/Plugins/DsPhiPiTreeMakerMINI/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PluginsDsPhiPiTreeMakerMINIAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Plugins/DsPhiPiTreeMakerMINI/plugins/BuildFile
PluginsDsPhiPiTreeMakerMINIAuto_LOC_USE := self   DataFormats/PatCandidates DataFormats/HepMCCandidate DataFormats/Candidate FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/Utilities TrackingTools/IPTools L1Trigger/L1TGlobal DataFormats/Common DataFormats/HLTReco CondFormats/DataRecord CondFormats/L1TObjects CommonTools/UtilAlgos DataFormats/TrackReco RecoVertex/KalmanVertexFit DataFormats/MuonReco RecoVertex/AdaptiveVertexFit RecoBTag/SecondaryVertex DataFormats/BeamSpot TrackingTools/TransientTrack TrackingTools/Records RecoVertex/KinematicFit RecoVertex/KinematicFitPrimitives RecoVertex/VertexPrimitives HLTrigger/HLTcore rootcore rootgraphics root
PluginsDsPhiPiTreeMakerMINIAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,PluginsDsPhiPiTreeMakerMINIAuto,PluginsDsPhiPiTreeMakerMINIAuto,$(SCRAMSTORENAME_LIB),src/Plugins/DsPhiPiTreeMakerMINI/plugins))
PluginsDsPhiPiTreeMakerMINIAuto_PACKAGE := self/src/Plugins/DsPhiPiTreeMakerMINI/plugins
ALL_PRODS += PluginsDsPhiPiTreeMakerMINIAuto
Plugins/DsPhiPiTreeMakerMINI_forbigobj+=PluginsDsPhiPiTreeMakerMINIAuto
PluginsDsPhiPiTreeMakerMINIAuto_INIT_FUNC        += $$(eval $$(call Library,PluginsDsPhiPiTreeMakerMINIAuto,src/Plugins/DsPhiPiTreeMakerMINI/plugins,src_Plugins_DsPhiPiTreeMakerMINI_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
PluginsDsPhiPiTreeMakerMINIAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,PluginsDsPhiPiTreeMakerMINIAuto,src/Plugins/DsPhiPiTreeMakerMINI/plugins))
endif
ALL_COMMONRULES += src_Plugins_DsPhiPiTreeMakerMINI_plugins
src_Plugins_DsPhiPiTreeMakerMINI_plugins_parent := Plugins/DsPhiPiTreeMakerMINI
src_Plugins_DsPhiPiTreeMakerMINI_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_DsPhiPiTreeMakerMINI_plugins,src/Plugins/DsPhiPiTreeMakerMINI/plugins,PLUGINS))
ifeq ($(strip $(PluginsPFCandFilterAuto)),)
PluginsPFCandFilterAuto := self/src/Plugins/PFCandFilter/plugins
PLUGINS:=yes
PluginsPFCandFilterAuto_files := $(patsubst src/Plugins/PFCandFilter/plugins/%,%,$(wildcard $(foreach dir,src/Plugins/PFCandFilter/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PluginsPFCandFilterAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Plugins/PFCandFilter/plugins/BuildFile
PluginsPFCandFilterAuto_LOC_USE := self   FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/PatCandidates DataFormats/HepMCCandidate DataFormats/Candidate FWCore/Utilities CommonTools/UtilAlgos TrackingTools/IPTools L1Trigger/L1TGlobal DataFormats/Common DataFormats/HLTReco CondFormats/DataRecord CondFormats/L1TObjects DataFormats/TrackReco RecoVertex/KalmanVertexFit DataFormats/MuonReco RecoVertex/AdaptiveVertexFit RecoBTag/SecondaryVertex DataFormats/BeamSpot TrackingTools/TransientTrack TrackingTools/Records RecoVertex/KinematicFit RecoVertex/KinematicFitPrimitives RecoVertex/VertexPrimitives HLTrigger/HLTcore rootcore rootgraphics root
PluginsPFCandFilterAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,PluginsPFCandFilterAuto,PluginsPFCandFilterAuto,$(SCRAMSTORENAME_LIB),src/Plugins/PFCandFilter/plugins))
PluginsPFCandFilterAuto_PACKAGE := self/src/Plugins/PFCandFilter/plugins
ALL_PRODS += PluginsPFCandFilterAuto
Plugins/PFCandFilter_forbigobj+=PluginsPFCandFilterAuto
PluginsPFCandFilterAuto_INIT_FUNC        += $$(eval $$(call Library,PluginsPFCandFilterAuto,src/Plugins/PFCandFilter/plugins,src_Plugins_PFCandFilter_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS),edm))
PluginsPFCandFilterAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,PluginsPFCandFilterAuto,src/Plugins/PFCandFilter/plugins))
endif
ALL_COMMONRULES += src_Plugins_PFCandFilter_plugins
src_Plugins_PFCandFilter_plugins_parent := Plugins/PFCandFilter
src_Plugins_PFCandFilter_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_PFCandFilter_plugins,src/Plugins/PFCandFilter/plugins,PLUGINS))
