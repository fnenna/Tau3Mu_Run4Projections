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
