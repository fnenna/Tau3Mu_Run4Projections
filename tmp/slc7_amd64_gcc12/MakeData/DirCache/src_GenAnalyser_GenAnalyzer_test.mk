ifeq ($(strip $(testGenAnalyserGenAnalyzerTP)),)
testGenAnalyserGenAnalyzerTP := self/src/GenAnalyser/GenAnalyzer/test
testGenAnalyserGenAnalyzerTP_files := $(patsubst src/GenAnalyser/GenAnalyzer/test/%,%,$(foreach file,test_catch2_*.cc,$(eval xfile:=$(wildcard src/GenAnalyser/GenAnalyzer/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/GenAnalyser/GenAnalyzer/test/$(file). Please fix src/GenAnalyser/GenAnalyzer/test/BuildFile.))))
testGenAnalyserGenAnalyzerTP_BuildFile    := $(WORKINGDIR)/cache/bf/src/GenAnalyser/GenAnalyzer/test/BuildFile
testGenAnalyserGenAnalyzerTP_LOC_USE := self   FWCore/TestProcessor catch2
testGenAnalyserGenAnalyzerTP_PACKAGE := self/src/GenAnalyser/GenAnalyzer/test
ALL_PRODS += testGenAnalyserGenAnalyzerTP
testGenAnalyserGenAnalyzerTP_INIT_FUNC        += $$(eval $$(call Binary,testGenAnalyserGenAnalyzerTP,src/GenAnalyser/GenAnalyzer/test,src_GenAnalyser_GenAnalyzer_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testGenAnalyserGenAnalyzerTP_CLASS := TEST
testGenAnalyserGenAnalyzerTP_TEST_RUNNER_CMD :=  testGenAnalyserGenAnalyzerTP 
else
$(eval $(call MultipleWarningMsg,testGenAnalyserGenAnalyzerTP,src/GenAnalyser/GenAnalyzer/test))
endif
ALL_COMMONRULES += src_GenAnalyser_GenAnalyzer_test
src_GenAnalyser_GenAnalyzer_test_parent := GenAnalyser/GenAnalyzer
src_GenAnalyser_GenAnalyzer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_GenAnalyser_GenAnalyzer_test,src/GenAnalyser/GenAnalyzer/test,TEST))
