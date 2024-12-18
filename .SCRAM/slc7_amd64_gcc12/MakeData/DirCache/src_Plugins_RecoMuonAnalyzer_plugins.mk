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
