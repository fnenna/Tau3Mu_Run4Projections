ifeq ($(strip $(PyPluginsRecoMuonAnalyzer)),)
PyPluginsRecoMuonAnalyzer := self/src/Plugins/RecoMuonAnalyzer/python
src_Plugins_RecoMuonAnalyzer_python_parent := src/Plugins/RecoMuonAnalyzer
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Plugins/RecoMuonAnalyzer/python)
PyPluginsRecoMuonAnalyzer_files := $(patsubst src/Plugins/RecoMuonAnalyzer/python/%,%,$(wildcard $(foreach dir,src/Plugins/RecoMuonAnalyzer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyPluginsRecoMuonAnalyzer_LOC_USE := self   
PyPluginsRecoMuonAnalyzer_PACKAGE := self/src/Plugins/RecoMuonAnalyzer/python
ALL_PRODS += PyPluginsRecoMuonAnalyzer
PyPluginsRecoMuonAnalyzer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyPluginsRecoMuonAnalyzer,src/Plugins/RecoMuonAnalyzer/python,src_Plugins_RecoMuonAnalyzer_python))
else
$(eval $(call MultipleWarningMsg,PyPluginsRecoMuonAnalyzer,src/Plugins/RecoMuonAnalyzer/python))
endif
ALL_COMMONRULES += src_Plugins_RecoMuonAnalyzer_python
src_Plugins_RecoMuonAnalyzer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_RecoMuonAnalyzer_python,src/Plugins/RecoMuonAnalyzer/python,PYTHON))
