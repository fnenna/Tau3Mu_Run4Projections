DIRECTORY_PATH = "/lustrehome/felicenenna/tau3mu/CMSSW_14_0_12/src/Analysis/JobAdd_perEra_2024/"
PLOT_PATH = "/lustrehome/felicenenna/tau3mu/CMSSW_14_0_12/src/Utilities/new_felice"
#FILE_LIST = ["Era_B_control","Era_C_control","Era_D_control","Era_E-v1_control","Era_E-v2_control","Era_F_control"]#,"Era_G_control"]
FILE_LIST = ["Era_B_control","Era_C_control","Era_D_control","Era_E_control","Era_F_control"]#,"Era_G_control"]
LUMI = [0.656, 7.434, 8.301, 11.920, 28.433, 5.484]#, 61.42]
ROOT_FORMAT = ".root"
#importing all the libraries necessary.
import uproot
import ROOT
import math
import awkward as ak
import hist
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import pandas as pd
import scipy.stats as sts
import matplotlib as mpl
import matplotlib.mlab as mlab
from scipy.optimize import curve_fit
from scipy.special import factorial
import mplhep as hep
import argparse
import os
import sys
import matplotlib.pylab as plab
import matplotlib.ticker as ticke
import cmsstyle as CMS

def main():
    yields = []
    yields_errors=[]
    #loop on the eras
    # Create a canvas for drawing the histogram
    canvas = ROOT.TCanvas("canvas", "Canvas for Histogram", 800, 600)
    for i in range(len(FILE_LIST)):
        print(FILE_LIST[i])
        dir_path = PLOT_PATH + "/" + FILE_LIST[i]
        try:
            os.makedirs(dir_path)
            print(f"directory created successfully.")
        except FileExistsError:
            print(f"directory already exists.")
        file_path = DIRECTORY_PATH + FILE_LIST[i]+ROOT_FORMAT
        #file = uproot.open(file_path)
        file = ROOT.TFile.Open(file_path)
        #print(file.keys())
        tree = file.Get("FinalTree")
        # Create a 1D histogram with 100 bins, ranging from 0 to 100
        n_bins = 70
        hist = ROOT.TH1F(FILE_LIST[i], "Triplet Mass Distribution", n_bins, 1.65, 2.08)
        min = hist.GetXaxis().GetXmin()
        max = hist.GetXaxis().GetXmax()
        hist_range = max-min
        bin_width = hist_range/n_bins
        tree.Draw("tripletMass>>"+FILE_LIST[i])
        #tree.show()
        '''
        events =tree["evt"].array()
        runs =tree["run"].array()
        print(events)
        print(runs)
        '''
        #tripletMass = tree["tripletMass"].array()
        '''
        fig, axs = plt.subplots(1,1, figsize = (7, 7))
        axs.hist(tripletMass, bins = 100, histtype = "step")
        axs.set_xlabel(fr"3$\mu$ invariant mass [GeV]")
        axs.set_ylabel("# events")
        #fig.savefig(dir_path + "/"+ FILE_LIST[i]+"_preliminary_triplet_mass_plot.png")
        '''
        # Set histogram properties
        hist.SetFillColor(38)  # Set the color of the histogram bars
        hist.GetXaxis().SetTitle("3#mu invariant mass [GeV/c^{2}]")
        hist.GetYaxis().SetTitle(f"# events / {bin_width*1e-3:.1f} MeV/c^{{2}}")
        hist.SetTitle("Histogram of Triplet Mass Distribution")
        #hist.Draw()
        #xMin = np.min(tripletMass)
        #xMax = np.max(tripletMass)
        #### FIT ####
        x = ROOT.RooRealVar("xVar", "m(3#mu) [GeV/c^{2}]", 1.65, 2.08); 
        x.setBins(n_bins)
        TriHist = ROOT.RooDataHist("data", "Data", ROOT.RooArgList(x), hist)
        # Parameters of the Gaussian: mean and sigma
        mean1 = ROOT.RooRealVar("mean1", "mean of gaussian1", 1.85, 1.80, 1.90)
        sigma1 = ROOT.RooRealVar("sigma1", "width of gaussian1", 0.05, 0.01, 0.1)
        # Parameters of the Gaussian: mean and sigma
        mean2 = ROOT.RooRealVar("mean", "mean of gaussian", 1.97, 1.93, 2.0)
        sigma2 = ROOT.RooRealVar("sigma", "width of gaussian", 0.05, 0.01, 0.1)
        gauss1= ROOT.RooGaussian("gauss1", "gaussian PDF", x, mean1, sigma1)
        gauss2= ROOT.RooGaussian("gauss2", "gaussian PDF", x, mean2, sigma2)
        gamma = ROOT.RooRealVar("#Gamma","Gamma",-1e-1, -2., -1e-2)
        bkgExpPdf = ROOT.RooExponential("bkgExpPdf","bkgExpPdf",x, gamma)
        nBkgExp = ROOT.RooRealVar("N_{EXPBKG}","nBkgExp",120e+3,1.,1e+6)
        nSig1 = ROOT.RooRealVar("N_{SIG}1","nSig1",2e+5,1.,1e+6)
        nSig2 = ROOT.RooRealVar("N_{SIG}2","nSig2",2e+5,1.,1e+6)
        totalCBExpPDF = ROOT.RooAddPdf("totalCBExpPDF","totalCBExpPDF", ROOT.RooArgList(gauss1, gauss2, bkgExpPdf), ROOT.RooArgList(nSig1, nSig2, nBkgExp))
        totalCBExpPDF.fitTo(TriHist)
        xframe = x.frame()
        xframe.SetTitle(hist.GetTitle())
        TriHist.plotOn(xframe)
        totalCBExpPDF.plotOn(xframe)
        totalCBExpPDF.plotOn(xframe, ROOT.RooFit.Components(ROOT.RooArgSet(gauss1)), ROOT.RooFit.LineColor(ROOT.kOrange+8), ROOT.RooFit.LineStyle(ROOT.kDashed))
        totalCBExpPDF.plotOn(xframe, ROOT.RooFit.Components(ROOT.RooArgSet(gauss2)), ROOT.RooFit.LineColor(ROOT.kOrange+8), ROOT.RooFit.LineStyle(ROOT.kDashed))
        totalCBExpPDF.plotOn(xframe, ROOT.RooFit.Components(ROOT.RooArgSet(bkgExpPdf)), ROOT.RooFit.LineColor(ROOT.kGreen), ROOT.RooFit.LineStyle(ROOT.kDashed) )
        '''
        # Create a TLegend
        legend = ROOT.TLegend(1.67, 50, 100, 1.8)  # Adjust position (x1, y1, x2, y2) as needed

        # Add entries to the legend
        legend.AddEntry(TriHist, "Data", "lep")  # "lep" = line, error bars, points
        legend.AddEntry(totalCBExpPDF, "Total", "l")  # "l" = line
        legend.AddEntry("", "D^{+} and D_{S}^{+}", "l")  # Use a placeholder entry
        legend.AddEntry("", "Background", "l")

        # Manually set colors and styles in the legend to match the plot
        legend.GetListOfPrimitives()[2].SetLineColor(ROOT.kOrange)
        legend.GetListOfPrimitives()[2].SetLineStyle(ROOT.kDashed)
        legend.GetListOfPrimitives()[3].SetLineColor(ROOT.kGreen)
        legend.GetListOfPrimitives()[3].SetLineStyle(ROOT.kDashed)
        '''
        #xframe.Draw()

        framePull = x.frame() # frame for the pulls
        framePull.SetTitle("Pulls bin-by-bin")
        framePull.addObject( xframe.pullHist(), "p" )# RooPlot has a list of objects (TObjects) that can be drawn
        framePull.SetMinimum(-6)
        framePull.SetMaximum(6)

        CMS.SetExtraText("Preliminary")
        CMS.SetLumi("#")
        CMS.SetEnergy(13.6)
        canvas = CMS.cmsCanvas('', 1.65, 2.08, 0, hist.GetMaximum()*1.2, 'm(#mu^{+}#mu^{-}#pi^{+}) [GeV/c^{2}]', f"Events / {bin_width*1e3:.1f} MeV/c^{{2}}", square = CMS.kSquare, extraSpace=0.02, iPos=0)
        canvas.SetCanvasSize(1000,1000)
        #canvas.Divide(0,2)
        #canvas.cd(2)
        #ROOT.gPad.SetPad(0.,0.,1.,0.3)
        #framePull.Draw("same")
        legend = CMS.cmsLeg(0.2, 0.2, 0.4, 0.4)
        # Create a dummy TGraphErrors for the legend entry
        dummy_graph = ROOT.TGraphErrors(1)  # Create a dummy graph
        dummy_graph.SetPoint(0, 0, 0)  # Set a dummy point
        dummy_graph.SetMarkerStyle(20)  # Circle marker
        dummy_graph.SetMarkerSize(1.0)  # Size of the markers
        dummy_graph.SetLineColor(ROOT.kBlack)  # Color of the line
        dummy_graph.SetMarkerColor(ROOT.kBlack)  # Color of the marker
        # Draw a dummy error bar to use in the legend
        dummy_graph.SetPoint(0, 1, 1)  # Dummy point for display
        dummy_graph.SetPointError(0, 0.1, 0.2)  # Error with caps
        # Add entries to the legend
        #legend.AddEntry(TriHist, "Data", "ep")  # "lep" = line, error bars, points
        legend.AddEntry(dummy_graph, "Data", "ep")  # "lep" = line, error bars, points
        # Set the marker style for the legend entry to circles
        legend.GetListOfPrimitives()[0].SetMarkerStyle(20)  # 20 is the code for circles
        sum_pdf = ROOT.TGraph()
        sum_pdf.SetLineColor(ROOT.kBlue)
        sum_pdf.SetLineWidth(2)  # Set line width to 2 for thickness

        legend.AddEntry(sum_pdf, "Total", "l")  # "l" = line
        
        # Create dummy graphs for component entries
        dummy_gauss1 = ROOT.TGraph()  # Dummy graph for D+ and DS+
        dummy_gauss2 = ROOT.TGraph()  # Dummy graph for background

        # Set colors and styles for the dummy graphs
        dummy_gauss1.SetLineColor(ROOT.kOrange+8)
        dummy_gauss1.SetLineStyle(ROOT.kDashed)
        dummy_gauss1.SetLineWidth(2)  # Set line width to 2 for thickness

        dummy_gauss2.SetLineColor(ROOT.kGreen)
        dummy_gauss2.SetLineStyle(ROOT.kDashed)
        dummy_gauss2.SetLineWidth(2)  # Set line width to 2 for thickness


        # Add entries for the components
        legend.AddEntry(dummy_gauss1, "D^{+} and D_{S}^{+}", "l")
        legend.AddEntry(dummy_gauss2, "Background", "l")
        #canvas.cd(1)
        #ROOT.gPad.SetPad(0.,0.3,1.,1.)
        legend.Draw("same")
        xframe.Draw("same")
        canvas.Update()
        canvas.SaveAs(dir_path + "/"+ FILE_LIST[i]+"_FIT_preliminary_triplet_mass_plot_pyroot.png")
        canvas.Clear()
        ##### save the signal yields:
        Ds_yield = nSig1.getVal()
        Ds_charged_yield = nSig2.getVal()
        signal_yield = Ds_yield + Ds_charged_yield
        Ds_yield_err = nSig1.getError()
        Ds_charged_yield_err = nSig2.getError()
        signal_yield_err = Ds_yield_err + Ds_charged_yield_err
        yields.append(signal_yield)
        yields_errors.append(signal_yield_err)
    fig, axs = plt.subplots(1,1, figsize = (6,6))
    eras = ["B", "C", "D", "E", "F"]
    colors = ["red", "blue", "green","magenta", "orange"]
    plt.style.use(hep.style.CMS)
    for era in range(len(yields)):
        axs.errorbar(LUMI[era], yields[era], yerr = yields_errors[era], fmt = "s",capsize=5, capthick=2, label = "Era "+eras[era])
        axs.set_xlabel("Era luminosity [/fb]", fontsize = 12)
        axs.set_ylabel(f"D$_{{S}}$ signal yield", fontsize = 12)
    axs.grid(True, which="both", axis="both", linestyle="--", color = "gray")
    axs.legend(frameon = True, fontsize = 12)#loc = "upper left", fontsize = "small")
    axs.set_yscale("log")
    axs.text(
    0., 1.05,                 
    fr"$\bf{{CMS}}$ Preliminary",          
    fontsize=12,                
    verticalalignment='top',    
    fontproperties="Tex Gyre Heros:italic", transform = axs.transAxes
    )
    axs.text(
    1., 1.05,                 
    "(13.6 TeV)",          
    fontsize=12,                
    verticalalignment='top',
    horizontalalignment = "right",
    fontproperties="Tex Gyre Heros:italic", transform = axs.transAxes
    )
    #axs.text(0.01, 1., "2024", transform = axs.transAxes)
    fig.tight_layout()
    fig.savefig("control_yield_lumi_log.png")



if __name__ == "__main__":
    main()