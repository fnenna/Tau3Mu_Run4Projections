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
