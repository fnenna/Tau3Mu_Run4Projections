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
