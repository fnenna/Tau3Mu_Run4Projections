from python_analysis_update_041124 import *
import hist
import dask
import awkward as ak
import hist.dask as hda
import dask_awkward as dak
import argparse, sys
from coffea import processor
from coffea.dataset_tools import (
    apply_to_fileset,
    max_chunks,
    preprocess,
)
from distributed import Client


client = Client()


class MyProcessor(processor.ProcessorABC):
    def __init__(self, type, datasetName, fileout):
        self.type = type
        self.datasetName = datasetName
        self.fileout = fileout

    def process(self, events):
        Loop_DsPhiPi(events, type, datasetName, fileout)

    def postprocess(self, accumulator):
        pass

parser = argparse.ArgumentParser(
                    prog='ProgramName',
                    description='Analysis tau3mu control channel (DsPhiPi)',
                    epilog='Text at the bottom of help')
parser.add_argument('-n','--narg')           # positional argument
parser.add_argument('-t','--type')      # option that takes a value
parser.add_argument('-d','--data')      # option that takes a value
args = parser.parse_args()
print(args.type)
#print(args.filename, args.count, args.verbose)
fileout = ""

tree = ROOT.TTree()
print(args.type)
type = args.type
print(f"type: {type}\n")
datasetName = args.data
print(f"datasetName : {datasetName}\n")

fileset = {}
files = {}
files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1126.root"] = "Tree3Mu/ntuple"
files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1283.root"] = "Tree3Mu/ntuple"
files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1057.root"] = "Tree3Mu/ntuple"
files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1159.root"] = "Tree3Mu/ntuple"
files["/lustre/cms/store/user/fnenna/ParkingDoubleMuonLowMass7/SkimDsPhiPi_2024eraF_stream7_Mini_v3/240917_162014/0001/Tree_PhiPi_1041.root"] = "Tree3Mu/ntuple"


fileset["files"] = files
uproot_options = {
    "file_handler": "file",
}
print(fileset)
dataset_runnable, dataset_updated = preprocess(
    fileset,
    align_clusters=False,
    step_size=100_000,
    files_per_batch=1,
    skip_bad_files=True,
    save_form=False,
    uproot_options = uproot_options
)

to_compute = apply_to_fileset(
                MyProcessor(type, datasetName, fileout),
                max_chunks(dataset_runnable, 300),
                schemaclass=BaseSchema,
            )

(out,) = dask.compute(to_compute)
print(out)