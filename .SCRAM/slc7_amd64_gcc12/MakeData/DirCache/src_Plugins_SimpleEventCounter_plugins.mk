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
