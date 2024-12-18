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
