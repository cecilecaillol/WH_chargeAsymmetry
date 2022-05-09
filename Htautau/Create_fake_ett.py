if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allJES','fake','tes'], help="Which TES?")
    parser.add_argument('--year', default="2016", choices=['2016', '2017', '2018'], help="Which TES?")

    nbhist=1+24+56

    options = parser.parse_args()

    postfixName=["","_CMS_scale_t_1prong_"+options.year+"Down","_CMS_scale_t_1prong_"+options.year+"Up","_CMS_scale_t_1prong1pizero_"+options.year+"Down","_CMS_scale_t_1prong1pizero_"+options.year+"Up","_CMS_scale_t_3prong_"+options.year+"Down","_CMS_scale_t_3prong_"+options.year+"Up","_CMS_scale_t_3prong1pizero_"+options.year+"Down","_CMS_scale_t_3prong1pizero_"+options.year+"Up","_CMS_tauideff_pt20to25_"+options.year+"Down","_CMS_tauideff_pt20to25_"+options.year+"Up","_CMS_tauideff_pt25to30_"+options.year+"Down","_CMS_tauideff_pt25to30_"+options.year+"Up","_CMS_tauideff_pt30to35_"+options.year+"Down","_CMS_tauideff_pt30to35_"+options.year+"Up","_CMS_tauideff_pt35to40_"+options.year+"Down","_CMS_tauideff_pt35to40_"+options.year+"Up","_CMS_tauideff_ptgt40_"+options.year+"Down","_CMS_tauideff_ptgt40_"+options.year+"Up","_CMS_scale_met_unclustered_"+options.year+"Down","_CMS_scale_met_unclustered_"+options.year+"Up","_CMS_scale_e_"+options.year+"Down","_CMS_scale_e_"+options.year+"Up","_CMS_prefiringDown","_CMS_prefiringUp",
    "_CMS_fakeTauVT_Te_dm0_pt20to25_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt20to25_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_pt25to30_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt25to30_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_pt30to35_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt30to35_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_pt35to40_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt35to40_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_pt40to50_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt40to50_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_pt50to60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt50to60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_ptgt60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_ptgt60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt20to25_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt20to25_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt25to30_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt25to30_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt30to35_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt30to35_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt35to40_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt35to40_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt40to50_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt40to50_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt50to60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt50to60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_ptgt60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_ptgt60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt20to25_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt20to25_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt25to30_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt25to30_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt30to35_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt30to35_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt35to40_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt35to40_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt40to50_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt40to50_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt50to60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt50to60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_ptgt60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_ptgt60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt20to25_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt20to25_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt25to30_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt25to30_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt30to35_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt30to35_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt35to40_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt35to40_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt40to50_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt40to50_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt50to60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt50to60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_ptgt60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_ptgt60_"+options.year+"Down"]

    fVV=ROOT.TFile("files_nominal_ett_"+options.year+"/VV.root","r")
    fData=ROOT.TFile("files_nominal_ett_"+options.year+"/Data.root","r")
    if options.scale=="fake":
       fData=ROOT.TFile("files_nominal_ett_"+options.year+"/DataSyst.root","r")
       fVV=ROOT.TFile("files_nominal_ett_"+options.year+"/VVSyst.root","r")
    if options.scale=="tes":
       fVV=ROOT.TFile("files_scale_ett_"+options.year+"/VV.root","r")
    fout=ROOT.TFile("files_nominal_ett_"+options.year+"/Fake_"+options.scale+".root","recreate")

    dirOS=fout.mkdir("ett")
    dirSS=fout.mkdir("ettSS")
    dirlowOS=fout.mkdir("ettlow")

    for k in range(0,nbhist):

       postfix=postfixName[k]
       hOS=fData.Get("AIOS/data_obs"+postfix)
       hOS.Add(fVV.Get("AIOS/ZZ"+postfix),-1)
       hOS.Add(fVV.Get("AIOS/WZ"+postfix),-1)
       for i in range(0,hOS.GetSize()-2):
           if hOS.GetBinContent(i)<0:
               hOS.SetBinError(i,max(0,hOS.GetBinError(i)+hOS.GetBinError(i)))
               hOS.SetBinContent(i,0)

       hSS=fData.Get("AISS/data_obs"+postfix)
       hSS.Add(fVV.Get("AISS/ZZ"+postfix),-1)
       hSS.Add(fVV.Get("AISS/WZ"+postfix),-1)
       for i in range(0,hSS.GetSize()-2):
           if hSS.GetBinContent(i)<0:
               hSS.SetBinError(i,max(0,hSS.GetBinError(i)+hSS.GetBinError(i)))
               hSS.SetBinContent(i,0)

       hlowOS=fData.Get("AIlowOS/data_obs"+postfix)
       hlowOS.Add(fVV.Get("AIlowOS/ZZ"+postfix),-1)
       hlowOS.Add(fVV.Get("AIlowOS/WZ"+postfix),-1)
       for i in range(0,hlowOS.GetSize()-2):
           if hlowOS.GetBinContent(i)<0:
               hlowOS.SetBinError(i,max(0,hlowOS.GetBinError(i)+hlowOS.GetBinError(i)))
               hlowOS.SetBinContent(i,0)

       fout.cd()
       dirOS.cd()
       hOS.SetName("jetFakes"+postfix)
       hOS.Write()

       dirSS.cd()
       hSS.SetName("jetFakes"+postfix)
       hSS.Write()

       dirlowOS.cd()
       hlowOS.SetName("jetFakes"+postfix)
       hlowOS.Write()

