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
