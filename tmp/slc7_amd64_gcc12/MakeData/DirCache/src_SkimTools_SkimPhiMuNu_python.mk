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
