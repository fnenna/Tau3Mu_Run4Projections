ifeq ($(strip $(testTrackFromCandProducerTrackFromCandProducerTP)),)
testTrackFromCandProducerTrackFromCandProducerTP := self/src/Plugins/TrackFromCandProducer/test
testTrackFromCandProducerTrackFromCandProducerTP_files := $(patsubst src/Plugins/TrackFromCandProducer/test/%,%,$(foreach file,test_catch2_*.cc,$(eval xfile:=$(wildcard src/Plugins/TrackFromCandProducer/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/Plugins/TrackFromCandProducer/test/$(file). Please fix src/Plugins/TrackFromCandProducer/test/BuildFile.))))
testTrackFromCandProducerTrackFromCandProducerTP_BuildFile    := $(WORKINGDIR)/cache/bf/src/Plugins/TrackFromCandProducer/test/BuildFile
testTrackFromCandProducerTrackFromCandProducerTP_LOC_USE := self   FWCore/TestProcessor catch2
testTrackFromCandProducerTrackFromCandProducerTP_PACKAGE := self/src/Plugins/TrackFromCandProducer/test
ALL_PRODS += testTrackFromCandProducerTrackFromCandProducerTP
testTrackFromCandProducerTrackFromCandProducerTP_INIT_FUNC        += $$(eval $$(call Binary,testTrackFromCandProducerTrackFromCandProducerTP,src/Plugins/TrackFromCandProducer/test,src_Plugins_TrackFromCandProducer_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
testTrackFromCandProducerTrackFromCandProducerTP_CLASS := TEST
testTrackFromCandProducerTrackFromCandProducerTP_TEST_RUNNER_CMD :=  testTrackFromCandProducerTrackFromCandProducerTP 
else
$(eval $(call MultipleWarningMsg,testTrackFromCandProducerTrackFromCandProducerTP,src/Plugins/TrackFromCandProducer/test))
endif
ALL_COMMONRULES += src_Plugins_TrackFromCandProducer_test
src_Plugins_TrackFromCandProducer_test_parent := Plugins/TrackFromCandProducer
src_Plugins_TrackFromCandProducer_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_TrackFromCandProducer_test,src/Plugins/TrackFromCandProducer/test,TEST))
