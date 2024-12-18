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
