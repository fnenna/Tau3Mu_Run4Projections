ALL_SUBSYSTEMS+=Plugins
subdirs_src_Plugins = src_Plugins_MiniAnaTau3Mu src_Plugins_TrackFromCandProducer src_Plugins_RecoMuonAnalyzer src_Plugins_SimpleEventCounter src_Plugins_DsPhiPiTreeMakerMINI src_Plugins_PFCandFilter
subdirs_src += src_Plugins
ALL_PACKAGES += Analysis/2024E-v1_2_control_230924
subdirs_src_Analysis_2024E-v1_2_control_230924 := 
ALL_PACKAGES += Analysis/2024B_3_control_230924
subdirs_src_Analysis_2024B_3_control_230924 := 
ALL_PACKAGES += Analysis/2024D_3_control_230924
subdirs_src_Analysis_2024D_3_control_230924 := 
ALL_PACKAGES += CrabSubmission/MC_2023
subdirs_src_CrabSubmission_MC_2023 := 
ALL_SUBSYSTEMS+=SkimTools
subdirs_src_SkimTools = src_SkimTools_SkimTau3Mu src_SkimTools_SkimPhiPi src_SkimTools_SkimPhiMuNu
subdirs_src += src_SkimTools
ALL_PACKAGES += Analysis/2024D_4_control_230924
subdirs_src_Analysis_2024D_4_control_230924 := 
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
ALL_PACKAGES += Analysis/2024F_6_control_230924
subdirs_src_Analysis_2024F_6_control_230924 := 
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
ALL_PACKAGES += Analysis/2024F_7_control_230924
subdirs_src_Analysis_2024F_7_control_230924 := 
ALL_PACKAGES += Analysis/2024F_1_control_230924
subdirs_src_Analysis_2024F_1_control_230924 := 
ALL_PACKAGES += Analysis/2024E-v1_5_control_230924
subdirs_src_Analysis_2024E-v1_5_control_230924 := 
ALL_PACKAGES += CrabSubmission/Data_2024
subdirs_src_CrabSubmission_Data_2024 := 
ALL_SUBSYSTEMS+=GenAnalyser
subdirs_src_GenAnalyser = src_GenAnalyser_GenAnalyzer
subdirs_src += src_GenAnalyser
ALL_PACKAGES += Analysis/2024C_1_control_230924
subdirs_src_Analysis_2024C_1_control_230924 := 
ALL_PACKAGES += SkimTools/SkimPhiPi
subdirs_src_SkimTools_SkimPhiPi := src_SkimTools_SkimPhiPi_python src_SkimTools_SkimPhiPi_test
ifeq ($(strip $(PyPluginsTrackFromCandProducer)),)
PyPluginsTrackFromCandProducer := self/src/Plugins/TrackFromCandProducer/python
src_Plugins_TrackFromCandProducer_python_parent := src/Plugins/TrackFromCandProducer
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Plugins/TrackFromCandProducer/python)
PyPluginsTrackFromCandProducer_files := $(patsubst src/Plugins/TrackFromCandProducer/python/%,%,$(wildcard $(foreach dir,src/Plugins/TrackFromCandProducer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyPluginsTrackFromCandProducer_LOC_USE := self   
PyPluginsTrackFromCandProducer_PACKAGE := self/src/Plugins/TrackFromCandProducer/python
ALL_PRODS += PyPluginsTrackFromCandProducer
PyPluginsTrackFromCandProducer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyPluginsTrackFromCandProducer,src/Plugins/TrackFromCandProducer/python,src_Plugins_TrackFromCandProducer_python))
else
$(eval $(call MultipleWarningMsg,PyPluginsTrackFromCandProducer,src/Plugins/TrackFromCandProducer/python))
endif
ALL_COMMONRULES += src_Plugins_TrackFromCandProducer_python
src_Plugins_TrackFromCandProducer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_TrackFromCandProducer_python,src/Plugins/TrackFromCandProducer/python,PYTHON))
ALL_PACKAGES += Analysis/2024E-v1_1_control_230924
subdirs_src_Analysis_2024E-v1_1_control_230924 := 
ALL_SUBSYSTEMS+=XGBoost
subdirs_src_XGBoost = 
subdirs_src += src_XGBoost
ALL_PACKAGES += CrabSubmission/MC
subdirs_src_CrabSubmission_MC := 
ALL_PACKAGES += Plugins/RecoMuonAnalyzer
subdirs_src_Plugins_RecoMuonAnalyzer := src_Plugins_RecoMuonAnalyzer_plugins src_Plugins_RecoMuonAnalyzer_python
ALL_PACKAGES += Analysis/2024B_5_control_230924
subdirs_src_Analysis_2024B_5_control_230924 := 
ALL_PACKAGES += SkimTools/SkimTau3Mu
subdirs_src_SkimTools_SkimTau3Mu := src_SkimTools_SkimTau3Mu_python src_SkimTools_SkimTau3Mu_test
ALL_PACKAGES += Analysis/2024D_2_control_230924
subdirs_src_Analysis_2024D_2_control_230924 := 
ifeq ($(strip $(PyGenAnalyserGenAnalyzer)),)
PyGenAnalyserGenAnalyzer := self/src/GenAnalyser/GenAnalyzer/python
src_GenAnalyser_GenAnalyzer_python_parent := src/GenAnalyser/GenAnalyzer
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/GenAnalyser/GenAnalyzer/python)
PyGenAnalyserGenAnalyzer_files := $(patsubst src/GenAnalyser/GenAnalyzer/python/%,%,$(wildcard $(foreach dir,src/GenAnalyser/GenAnalyzer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyGenAnalyserGenAnalyzer_LOC_USE := self   
PyGenAnalyserGenAnalyzer_PACKAGE := self/src/GenAnalyser/GenAnalyzer/python
ALL_PRODS += PyGenAnalyserGenAnalyzer
PyGenAnalyserGenAnalyzer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyGenAnalyserGenAnalyzer,src/GenAnalyser/GenAnalyzer/python,src_GenAnalyser_GenAnalyzer_python))
else
$(eval $(call MultipleWarningMsg,PyGenAnalyserGenAnalyzer,src/GenAnalyser/GenAnalyzer/python))
endif
ALL_COMMONRULES += src_GenAnalyser_GenAnalyzer_python
src_GenAnalyser_GenAnalyzer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_GenAnalyser_GenAnalyzer_python,src/GenAnalyser/GenAnalyzer/python,PYTHON))
ALL_PACKAGES += Analysis/Run4_DsTau3mu_tau3mu_Run4_DsTau3Mu
subdirs_src_Analysis_Run4_DsTau3mu_tau3mu_Run4_DsTau3Mu := 
ALL_PACKAGES += Analysis/2024B_0_control_230924
subdirs_src_Analysis_2024B_0_control_230924 := 
ALL_PACKAGES += Analysis/2024E-v2_2_control_230924
subdirs_src_Analysis_2024E-v2_2_control_230924 := 
ALL_PACKAGES += Plugins/MiniAnaTau3Mu
subdirs_src_Plugins_MiniAnaTau3Mu := src_Plugins_MiniAnaTau3Mu_plugins src_Plugins_MiniAnaTau3Mu_python src_Plugins_MiniAnaTau3Mu_test
ALL_PACKAGES += Analysis/Run4_MinBias_tau3mu_Run4_minBias021224
subdirs_src_Analysis_Run4_MinBias_tau3mu_Run4_minBias021224 := 
ALL_PACKAGES += Analysis/2024B_4_control_230924
subdirs_src_Analysis_2024B_4_control_230924 := 
ALL_PACKAGES += CrabSubmission/Data_2023
subdirs_src_CrabSubmission_Data_2023 := 
ALL_PACKAGES += Analysis/2024E-v2_4_control_230924
subdirs_src_Analysis_2024E-v2_4_control_230924 := 
ALL_PACKAGES += Analysis/2024E-v2_0_control_230924
subdirs_src_Analysis_2024E-v2_0_control_230924 := 
ALL_PACKAGES += CrabSubmission/Data
subdirs_src_CrabSubmission_Data := 
ALL_PACKAGES += Analysis/2024F_5_control_230924
subdirs_src_Analysis_2024F_5_control_230924 := 
ALL_SUBSYSTEMS+=GenAna
subdirs_src_GenAna = src_GenAna_GenAnalyser
subdirs_src += src_GenAna
ALL_PACKAGES += Plugins/DsPhiPiTreeMakerMINI
subdirs_src_Plugins_DsPhiPiTreeMakerMINI := src_Plugins_DsPhiPiTreeMakerMINI_plugins
ALL_SUBSYSTEMS+=Utilities
subdirs_src_Utilities = src_Utilities_new_felice src_Utilities_Previous_codes
subdirs_src += src_Utilities
ALL_PACKAGES += GenAnalyser/GenAnalyzer
subdirs_src_GenAnalyser_GenAnalyzer := src_GenAnalyser_GenAnalyzer_plugins src_GenAnalyser_GenAnalyzer_python src_GenAnalyser_GenAnalyzer_test
ALL_PACKAGES += Analysis/2024E-v1_6_control_230924
subdirs_src_Analysis_2024E-v1_6_control_230924 := 
ifeq ($(strip $(PyPluginsSimpleEventCounter)),)
PyPluginsSimpleEventCounter := self/src/Plugins/SimpleEventCounter/python
src_Plugins_SimpleEventCounter_python_parent := src/Plugins/SimpleEventCounter
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Plugins/SimpleEventCounter/python)
PyPluginsSimpleEventCounter_files := $(patsubst src/Plugins/SimpleEventCounter/python/%,%,$(wildcard $(foreach dir,src/Plugins/SimpleEventCounter/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyPluginsSimpleEventCounter_LOC_USE := self   
PyPluginsSimpleEventCounter_PACKAGE := self/src/Plugins/SimpleEventCounter/python
ALL_PRODS += PyPluginsSimpleEventCounter
PyPluginsSimpleEventCounter_INIT_FUNC        += $$(eval $$(call PythonProduct,PyPluginsSimpleEventCounter,src/Plugins/SimpleEventCounter/python,src_Plugins_SimpleEventCounter_python))
else
$(eval $(call MultipleWarningMsg,PyPluginsSimpleEventCounter,src/Plugins/SimpleEventCounter/python))
endif
ALL_COMMONRULES += src_Plugins_SimpleEventCounter_python
src_Plugins_SimpleEventCounter_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_SimpleEventCounter_python,src/Plugins/SimpleEventCounter/python,PYTHON))
ALL_PACKAGES += Analysis/2024C_0_control_230924
subdirs_src_Analysis_2024C_0_control_230924 := 
ifeq ($(strip $(PySkimToolsSkimTau3Mu)),)
PySkimToolsSkimTau3Mu := self/src/SkimTools/SkimTau3Mu/python
src_SkimTools_SkimTau3Mu_python_parent := src/SkimTools/SkimTau3Mu
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SkimTools/SkimTau3Mu/python)
PySkimToolsSkimTau3Mu_files := $(patsubst src/SkimTools/SkimTau3Mu/python/%,%,$(wildcard $(foreach dir,src/SkimTools/SkimTau3Mu/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySkimToolsSkimTau3Mu_LOC_USE := self   
PySkimToolsSkimTau3Mu_PACKAGE := self/src/SkimTools/SkimTau3Mu/python
ALL_PRODS += PySkimToolsSkimTau3Mu
PySkimToolsSkimTau3Mu_INIT_FUNC        += $$(eval $$(call PythonProduct,PySkimToolsSkimTau3Mu,src/SkimTools/SkimTau3Mu/python,src_SkimTools_SkimTau3Mu_python))
else
$(eval $(call MultipleWarningMsg,PySkimToolsSkimTau3Mu,src/SkimTools/SkimTau3Mu/python))
endif
ALL_COMMONRULES += src_SkimTools_SkimTau3Mu_python
src_SkimTools_SkimTau3Mu_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SkimTools_SkimTau3Mu_python,src/SkimTools/SkimTau3Mu/python,PYTHON))
ALL_PACKAGES += Analysis/2024F_4_control_230924
subdirs_src_Analysis_2024F_4_control_230924 := 
ALL_PACKAGES += Analysis/2024B_2_control_230924
subdirs_src_Analysis_2024B_2_control_230924 := 
ALL_PACKAGES += Analysis/2024D_5_control_230924
subdirs_src_Analysis_2024D_5_control_230924 := 
ALL_PACKAGES += Analysis/2024C_4_control_230924
subdirs_src_Analysis_2024C_4_control_230924 := 
ALL_SUBSYSTEMS+=Analysis
subdirs_src_Analysis = src_Analysis_2024E-v2_4_control_230924 src_Analysis_2024B_6_control_230924 src_Analysis_2024C_2_control_230924 src_Analysis_2024E-v1_7_control_230924 src_Analysis_2024E-v1_5_control_230924 src_Analysis_2024B_0_control_230924 src_Analysis_2024D_1_control_230924 src_Analysis_2024E-v2_0_control_230924 src_Analysis_2024E-v1_4_control_230924 src_Analysis_2024F_0_control_230924 src_Analysis_2024C_1_control_230924 src_Analysis_2024B_5_control_230924 src_Analysis_2024C_4_control_230924 src_Analysis_templates src_Analysis_2024E-v1_0_control_230924 src_Analysis_2024D_0_control_230924 src_Analysis_JobAdd_perEra_2024 src_Analysis_2024F_6_control_230924 src_Analysis_2024B_7_control_230924 src_Analysis_2024F_1_control_230924 src_Analysis_2024F_7_control_230924 src_Analysis_2024F_4_control_230924 src_Analysis_2024B_3_control_230924 src_Analysis_2024E-v2_5_control_230924 src_Analysis_2024E-v1_1_control_230924 src_Analysis_2024E-v2_6_control_230924 src_Analysis_2024D_6_control_230924 src_Analysis_2024C_6_control_230924 src_Analysis_2024W_control_test src_Analysis_2024E-v1_6_control_230924 src_Analysis_2024B_4_control_230924 src_Analysis_2024E-v1_2_control_230924 src_Analysis_2024E-v2_7_control_230924 src_Analysis_2024C_7_control_230924 src_Analysis_2024E-v2_1_control_230924 src_Analysis_2024D_2_control_230924 src_Analysis_Run4_MinBias_tau3mu_Run4_minBias021224 src_Analysis_2024C_5_control_230924 src_Analysis_2024B_2_control_230924 src_Analysis_2024D_7_control_230924 src_Analysis_2024D_5_control_230924 src_Analysis_2024F_2_control_230924 src_Analysis_2024C_0_control_230924 src_Analysis_Run4_DsTau3mu_tau3mu_Run4_DsTau3Mu src_Analysis_2024D_3_control_230924 src_Analysis_2024E-v2_2_control_230924 src_Analysis_2024C_3_control_230924 src_Analysis_2024F_5_control_230924 src_Analysis_2024E-v2_3_control_230924 src_Analysis_2024B_1_control_230924 src_Analysis_2024D_4_control_230924 src_Analysis_2024E-v1_3_control_230924 src_Analysis_2024F_3_control_230924
subdirs_src += src_Analysis
ALL_PACKAGES += Analysis/2024D_6_control_230924
subdirs_src_Analysis_2024D_6_control_230924 := 
ALL_PACKAGES += Analysis/2024F_3_control_230924
subdirs_src_Analysis_2024F_3_control_230924 := 
ALL_PACKAGES += Utilities/new_felice
subdirs_src_Utilities_new_felice := 
ALL_PACKAGES += Analysis/2024D_1_control_230924
subdirs_src_Analysis_2024D_1_control_230924 := 
ALL_PACKAGES += Analysis/2024B_1_control_230924
subdirs_src_Analysis_2024B_1_control_230924 := 
ALL_PACKAGES += Analysis/2024D_0_control_230924
subdirs_src_Analysis_2024D_0_control_230924 := 
ifeq ($(strip $(PyPluginsPFCandFilter)),)
PyPluginsPFCandFilter := self/src/Plugins/PFCandFilter/python
src_Plugins_PFCandFilter_python_parent := src/Plugins/PFCandFilter
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Plugins/PFCandFilter/python)
PyPluginsPFCandFilter_files := $(patsubst src/Plugins/PFCandFilter/python/%,%,$(wildcard $(foreach dir,src/Plugins/PFCandFilter/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyPluginsPFCandFilter_LOC_USE := self   
PyPluginsPFCandFilter_PACKAGE := self/src/Plugins/PFCandFilter/python
ALL_PRODS += PyPluginsPFCandFilter
PyPluginsPFCandFilter_INIT_FUNC        += $$(eval $$(call PythonProduct,PyPluginsPFCandFilter,src/Plugins/PFCandFilter/python,src_Plugins_PFCandFilter_python))
else
$(eval $(call MultipleWarningMsg,PyPluginsPFCandFilter,src/Plugins/PFCandFilter/python))
endif
ALL_COMMONRULES += src_Plugins_PFCandFilter_python
src_Plugins_PFCandFilter_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_PFCandFilter_python,src/Plugins/PFCandFilter/python,PYTHON))
ALL_PACKAGES += GenAna/GenAnalyser
subdirs_src_GenAna_GenAnalyser := 
ALL_PACKAGES += Analysis/2024E-v1_4_control_230924
subdirs_src_Analysis_2024E-v1_4_control_230924 := 
ALL_PACKAGES += Analysis/2024C_7_control_230924
subdirs_src_Analysis_2024C_7_control_230924 := 
ALL_PACKAGES += Plugins/SimpleEventCounter
subdirs_src_Plugins_SimpleEventCounter := src_Plugins_SimpleEventCounter_plugins src_Plugins_SimpleEventCounter_python
ALL_PACKAGES += Analysis/2024B_6_control_230924
subdirs_src_Analysis_2024B_6_control_230924 := 
ALL_PACKAGES += Analysis/2024E-v2_3_control_230924
subdirs_src_Analysis_2024E-v2_3_control_230924 := 
ALL_PACKAGES += Analysis/2024E-v1_0_control_230924
subdirs_src_Analysis_2024E-v1_0_control_230924 := 
ALL_PACKAGES += Analysis/2024B_7_control_230924
subdirs_src_Analysis_2024B_7_control_230924 := 
ALL_PACKAGES += Analysis/2024C_5_control_230924
subdirs_src_Analysis_2024C_5_control_230924 := 
ALL_PACKAGES += Analysis/2024C_6_control_230924
subdirs_src_Analysis_2024C_6_control_230924 := 
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
ALL_PACKAGES += Analysis/templates
subdirs_src_Analysis_templates := 
ALL_PACKAGES += Analysis/2024F_0_control_230924
subdirs_src_Analysis_2024F_0_control_230924 := 
ALL_PACKAGES += Analysis/2024F_2_control_230924
subdirs_src_Analysis_2024F_2_control_230924 := 
ALL_SUBSYSTEMS+=CrabSubmission
subdirs_src_CrabSubmission = src_CrabSubmission_Data_2023 src_CrabSubmission_MC_2023 src_CrabSubmission_Data_2024 src_CrabSubmission_Data src_CrabSubmission_MC
subdirs_src += src_CrabSubmission
ALL_PACKAGES += Analysis/2024E-v2_7_control_230924
subdirs_src_Analysis_2024E-v2_7_control_230924 := 
ALL_PACKAGES += SkimTools/SkimPhiMuNu
subdirs_src_SkimTools_SkimPhiMuNu := src_SkimTools_SkimPhiMuNu_python src_SkimTools_SkimPhiMuNu_test
ALL_PACKAGES += Analysis/2024E-v2_6_control_230924
subdirs_src_Analysis_2024E-v2_6_control_230924 := 
ALL_PACKAGES += Analysis/2024D_7_control_230924
subdirs_src_Analysis_2024D_7_control_230924 := 
ALL_PACKAGES += Plugins/TrackFromCandProducer
subdirs_src_Plugins_TrackFromCandProducer := src_Plugins_TrackFromCandProducer_plugins src_Plugins_TrackFromCandProducer_python src_Plugins_TrackFromCandProducer_test
ifeq ($(strip $(PySkimToolsSkimPhiMuNu)),)
PySkimToolsSkimPhiMuNu := self/src/SkimTools/SkimPhiMuNu/python
src_SkimTools_SkimPhiMuNu_python_parent := src/SkimTools/SkimPhiMuNu
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SkimTools/SkimPhiMuNu/python)
PySkimToolsSkimPhiMuNu_files := $(patsubst src/SkimTools/SkimPhiMuNu/python/%,%,$(wildcard $(foreach dir,src/SkimTools/SkimPhiMuNu/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySkimToolsSkimPhiMuNu_LOC_USE := self   
PySkimToolsSkimPhiMuNu_PACKAGE := self/src/SkimTools/SkimPhiMuNu/python
ALL_PRODS += PySkimToolsSkimPhiMuNu
PySkimToolsSkimPhiMuNu_INIT_FUNC        += $$(eval $$(call PythonProduct,PySkimToolsSkimPhiMuNu,src/SkimTools/SkimPhiMuNu/python,src_SkimTools_SkimPhiMuNu_python))
else
$(eval $(call MultipleWarningMsg,PySkimToolsSkimPhiMuNu,src/SkimTools/SkimPhiMuNu/python))
endif
ALL_COMMONRULES += src_SkimTools_SkimPhiMuNu_python
src_SkimTools_SkimPhiMuNu_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SkimTools_SkimPhiMuNu_python,src/SkimTools/SkimPhiMuNu/python,PYTHON))
ALL_PACKAGES += Plugins/PFCandFilter
subdirs_src_Plugins_PFCandFilter := src_Plugins_PFCandFilter_plugins src_Plugins_PFCandFilter_python src_Plugins_PFCandFilter_test
ALL_PACKAGES += Analysis/2024E-v1_3_control_230924
subdirs_src_Analysis_2024E-v1_3_control_230924 := 
ALL_PACKAGES += Analysis/2024E-v1_7_control_230924
subdirs_src_Analysis_2024E-v1_7_control_230924 := 
ifeq ($(strip $(PyPluginsMiniAnaTau3Mu)),)
PyPluginsMiniAnaTau3Mu := self/src/Plugins/MiniAnaTau3Mu/python
src_Plugins_MiniAnaTau3Mu_python_parent := src/Plugins/MiniAnaTau3Mu
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Plugins/MiniAnaTau3Mu/python)
PyPluginsMiniAnaTau3Mu_files := $(patsubst src/Plugins/MiniAnaTau3Mu/python/%,%,$(wildcard $(foreach dir,src/Plugins/MiniAnaTau3Mu/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyPluginsMiniAnaTau3Mu_LOC_USE := self   
PyPluginsMiniAnaTau3Mu_PACKAGE := self/src/Plugins/MiniAnaTau3Mu/python
ALL_PRODS += PyPluginsMiniAnaTau3Mu
PyPluginsMiniAnaTau3Mu_INIT_FUNC        += $$(eval $$(call PythonProduct,PyPluginsMiniAnaTau3Mu,src/Plugins/MiniAnaTau3Mu/python,src_Plugins_MiniAnaTau3Mu_python))
else
$(eval $(call MultipleWarningMsg,PyPluginsMiniAnaTau3Mu,src/Plugins/MiniAnaTau3Mu/python))
endif
ALL_COMMONRULES += src_Plugins_MiniAnaTau3Mu_python
src_Plugins_MiniAnaTau3Mu_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Plugins_MiniAnaTau3Mu_python,src/Plugins/MiniAnaTau3Mu/python,PYTHON))
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
ALL_PACKAGES += Analysis/2024E-v2_5_control_230924
subdirs_src_Analysis_2024E-v2_5_control_230924 := 
ALL_PACKAGES += Analysis/2024C_2_control_230924
subdirs_src_Analysis_2024C_2_control_230924 := 
ALL_PACKAGES += Analysis/JobAdd_perEra_2024
subdirs_src_Analysis_JobAdd_perEra_2024 := 
ALL_PACKAGES += Analysis/2024C_3_control_230924
subdirs_src_Analysis_2024C_3_control_230924 := 
ALL_PACKAGES += Analysis/2024W_control_test
subdirs_src_Analysis_2024W_control_test := 
ALL_PACKAGES += Analysis/2024E-v2_1_control_230924
subdirs_src_Analysis_2024E-v2_1_control_230924 := 
ALL_PACKAGES += Utilities/Previous_codes
subdirs_src_Utilities_Previous_codes := 
ifeq ($(strip $(PySkimToolsSkimPhiPi)),)
PySkimToolsSkimPhiPi := self/src/SkimTools/SkimPhiPi/python
src_SkimTools_SkimPhiPi_python_parent := src/SkimTools/SkimPhiPi
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/SkimTools/SkimPhiPi/python)
PySkimToolsSkimPhiPi_files := $(patsubst src/SkimTools/SkimPhiPi/python/%,%,$(wildcard $(foreach dir,src/SkimTools/SkimPhiPi/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PySkimToolsSkimPhiPi_LOC_USE := self   
PySkimToolsSkimPhiPi_PACKAGE := self/src/SkimTools/SkimPhiPi/python
ALL_PRODS += PySkimToolsSkimPhiPi
PySkimToolsSkimPhiPi_INIT_FUNC        += $$(eval $$(call PythonProduct,PySkimToolsSkimPhiPi,src/SkimTools/SkimPhiPi/python,src_SkimTools_SkimPhiPi_python))
else
$(eval $(call MultipleWarningMsg,PySkimToolsSkimPhiPi,src/SkimTools/SkimPhiPi/python))
endif
ALL_COMMONRULES += src_SkimTools_SkimPhiPi_python
src_SkimTools_SkimPhiPi_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_SkimTools_SkimPhiPi_python,src/SkimTools/SkimPhiPi/python,PYTHON))
