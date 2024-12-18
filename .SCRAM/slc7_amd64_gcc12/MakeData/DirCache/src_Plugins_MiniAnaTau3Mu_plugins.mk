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
