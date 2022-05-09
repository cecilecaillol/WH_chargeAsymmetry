#!/usr/bin/env python
import ROOT
from ROOT import *
import re
from array import array

import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--channel', default="mtt", choices=['mtt','ett','emt','mmt'], help="Which TES?")
parser.add_argument('--year', default="2016", choices=['2016', '2017', '2018'], help="Which TES?")
parser.add_argument('--Wsign', default="", choices=['', 'plus', 'minus'])

options = parser.parse_args()


islog=1
unrollSV=1

file=ROOT.TFile("wh_"+options.channel+"_"+options.year+"_2D.root","r")
file1=ROOT.TFile("wh_"+options.channel+options.Wsign+"_"+options.year+".root","recreate")


file.cd()
dirList = gDirectory.GetListOfKeys()
for k1 in dirList:
      if "emt" in k1.GetName() or "ett" in k1.GetName() or "mmt" in k1.GetName() or k1.GetName()=="mtt":
         h1 = k1.ReadObj()
         newname=h1.GetName()
         if "us" in options.Wsign:
	    newname=h1.GetName()+"_"+options.Wsign
         file1.mkdir(newname)
         h1.cd()
         dirList2 = gDirectory.GetListOfKeys()
         for k2 in dirList2:
            h2 = k2.ReadObj()
            h3=h2.Clone()
            nn=h3.GetSize()
            nx=h3.GetXaxis().GetNbins()
   	    ny=h3.GetYaxis().GetNbins()
   	    h1d=ROOT.TH1F("h1d","h1d",nx*ny,0,nx*ny)
            dir1=nx
            dir2=ny
	    l=0
            for j in range(1,dir1+1):
      		for k in range(1,dir2+1):
        	   l=l+1
        	   n = h3.GetBin(j,k);
        	   h1d.SetBinContent(l,h3.GetBinContent(n))
        	   h1d.SetBinError(l,h3.GetBinError(n))
            file1.cd(newname)
            h1d.SetName(k2.GetName())
	    h1d.Write()

