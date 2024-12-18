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
