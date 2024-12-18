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
