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
