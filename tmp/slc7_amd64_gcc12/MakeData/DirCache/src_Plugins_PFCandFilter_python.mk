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
