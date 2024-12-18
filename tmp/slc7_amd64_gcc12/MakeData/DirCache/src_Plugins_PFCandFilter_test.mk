ifeq ($(strip $(testPFCandFilterPFCandFilterTP)),)
testPFCandFilterPFCandFilterTP := self/src/Plugins/PFCandFilter/test
testPFCandFilterPFCandFilterTP_files := $(patsubst src/Plugins/PFCandFilter/test/%,%,$(foreach file,test_catch2_*.cc,$(eval xfile:=$(wildcard src/Plugins/PFCandFilter/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/Plugins/PFCandFilter/test/$(file). Please fix src/Plugins/PFCandFilter/test/BuildFile.))))
testPFCandFilterPFCandFilterTP_BuildFile    := $(WORKINGDIR)/cache/bf/src/Plugins/PFCandFilter/test/BuildFile
testPFCandFilterPFCandFilterTP_LOC_USE := self   FWCore/TestProcessor catch2
testPFCandFilterPFCandFilterTP_PACKAGE := self/src/Plugins/PFCandFilter/test
ALL_PRODS += testPFCandFilterPFCandFilterTP
testPFCandFilterPFCandFilterTP_INIT_FUNC        += $$(eval $$(call Binary,testPFCandFilterPFCandFilterTP,src/Plugins/PFCandFilter/test,src_Plugins_PFCandFilter_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testPFCandFilterPFCandFilterTP_CLASS := TEST
testPFCandFilterPFCandFilterTP_TEST_RUNNER_CMD :=  testPFCandFilterPFCandFilterTP 
else
$(eval $(call MultipleWarningMsg,testPFCandFilterPFCandFilterTP,src/Plugins/PFCandFilter/test))
endif
ALL_COMMONRULES += src_Plugins_PFCandFilter_test
src_Plugins_PFCandFilter_test_parent := Plugins/PFCandFilter
src_Plugins_PFCandFilter_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_PFCandFilter_test,src/Plugins/PFCandFilter/test,TEST))
