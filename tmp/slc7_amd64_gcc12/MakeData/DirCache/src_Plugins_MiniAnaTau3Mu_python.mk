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
