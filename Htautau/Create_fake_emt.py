if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'tes', 'fake', 'up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allJES'], help="Which TES?")
    parser.add_argument('--year', default="2016", choices=['2016', '2017', '2018'], help="Which TES?")

    nbhist=1

    options = parser.parse_args()

    fVV=ROOT.TFile("files_nominal_emt_"+options.year+"/VV.root","r")
    fData=ROOT.TFile("files_nominal_emt_"+options.year+"/Data.root","r")
    if options.scale=="fake":
       fData=ROOT.TFile("files_nominal_emt_"+options.year+"/DataSyst.root","r")
       fVV=ROOT.TFile("files_nominal_emt_"+options.year+"/VVSyst.root","r")
    if options.scale=="tes":
       fVV=ROOT.TFile("files_scale_emt_"+options.year+"/VV.root","r")
    fout=ROOT.TFile("files_nominal_emt_"+options.year+"/Fake_"+options.scale+".root","recreate")

    dirOS_high=fout.mkdir("emt_high")
    dirSS_high=fout.mkdir("emt_highSS")
    dirOS_low=fout.mkdir("emt_low")
    dirSS_low=fout.mkdir("emt_lowSS")
	
    nbhist=1+30+80

    postfixName=["","_CMS_scale_t_1prong_"+options.year+"Down","_CMS_scale_t_1prong_"+options.year+"Up","_CMS_scale_t_1prong1pizero_"+options.year+"Down","_CMS_scale_t_1prong1pizero_"+options.year+"Up","_CMS_scale_t_3prong_"+options.year+"Down","_CMS_scale_t_3prong_"+options.year+"Up","_CMS_scale_t_3prong1pizero_"+options.year+"Down","_CMS_scale_t_3prong1pizero_"+options.year+"Up","_CMS_tauideff_pt20to25_"+options.year+"Down","_CMS_tauideff_pt20to25_"+options.year+"Up","_CMS_tauideff_pt25to30_"+options.year+"Down","_CMS_tauideff_pt25to30_"+options.year+"Up","_CMS_tauideff_pt30to35_"+options.year+"Down","_CMS_tauideff_pt30to35_"+options.year+"Up","_CMS_tauideff_pt35to40_"+options.year+"Down","_CMS_tauideff_pt35to40_"+options.year+"Up","_CMS_tauideff_ptgt40_"+options.year+"Down","_CMS_tauideff_ptgt40_"+options.year+"Up","_CMS_scale_met_unclustered_"+options.year+"Down","_CMS_scale_met_unclustered_"+options.year+"Up","_CMS_scale_e_"+options.year+"Down","_CMS_scale_e_"+options.year+"Up","_CMS_scale_m_etalt1p2_"+options.year+"Down","_CMS_scale_m_etalt1p2_"+options.year+"Up","_CMS_scale_m_eta1p2to2p1_"+options.year+"Down","_CMS_scale_m_eta1p2to2p1_"+options.year+"Up","_CMS_scale_m_etagt2p1_"+options.year+"Down","_CMS_scale_m_etagt2p1_"+options.year+"Up","_CMS_prefiringDown","_CMS_prefiringUp",
    "_CMS_fakeTauVT_Te_dm0_pt20to25_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt20to25_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_pt25to30_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt25to30_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_pt30to35_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt30to35_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_pt35to40_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt35to40_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_pt40to50_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt40to50_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_pt50to60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_pt50to60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm0_ptgt60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm0_ptgt60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt20to25_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt20to25_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt25to30_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt25to30_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt30to35_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt30to35_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt35to40_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt35to40_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt40to50_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt40to50_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_pt50to60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_pt50to60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm1_ptgt60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm1_ptgt60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt20to25_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt20to25_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt25to30_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt25to30_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt30to35_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt30to35_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt35to40_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt35to40_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt40to50_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt40to50_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_pt50to60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_pt50to60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm10_ptgt60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm10_ptgt60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt20to25_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt20to25_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt25to30_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt25to30_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt30to35_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt30to35_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt35to40_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt35to40_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt40to50_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt40to50_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_pt50to60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_pt50to60_"+options.year+"Down","_CMS_fakeTauVT_Te_dm11_ptgt60_"+options.year+"Up","_CMS_fakeTauVT_Te_dm11_ptgt60_"+options.year+"Down","_CMS_fakeEle_pt10to15_"+options.year+"Up","_CMS_fakeEle_pt10to15_"+options.year+"Down","_CMS_fakeEle_pt15to20_"+options.year+"Up","_CMS_fakeEle_pt15to20_"+options.year+"Down","_CMS_fakeEle_pt20to30_"+options.year+"Up","_CMS_fakeEle_pt20to30_"+options.year+"Down","_CMS_fakeEle_pt30to40_"+options.year+"Up","_CMS_fakeEle_pt30to40_"+options.year+"Down","_CMS_fakeEle_ptgt40_"+options.year+"Up","_CMS_fakeEle_ptgt40_"+options.year+"Down","_CMS_fakeMu_pt10to15_"+options.year+"Up","_CMS_fakeMu_pt10to15_"+options.year+"Down","_CMS_fakeMu_pt15to20_"+options.year+"Up","_CMS_fakeMu_pt15to20_"+options.year+"Down","_CMS_fakeMu_pt20to30_"+options.year+"Up","_CMS_fakeMu_pt20to30_"+options.year+"Down","_CMS_fakeMu_pt30to40_"+options.year+"Up","_CMS_fakeMu_pt30to40_"+options.year+"Down","_CMS_fakeMu_ptgt40_"+options.year+"Up","_CMS_fakeMu_ptgt40_"+options.year+"Down","_CMS_fakeEle_promptSubtraction_"+options.year+"Down","_CMS_fakeEle_promptSubtraction_"+options.year+"Up","_CMS_fakeMu_promptSubtraction_"+options.year+"Down","_CMS_fakeMu_promptSubtraction_"+options.year+"Up"]

    for k in range(0,nbhist):
       postfix=postfixName[k]

       hOS_high=fData.Get("AIOS/data_obs"+postfix)
       hOS_high.Add(fVV.Get("AIOS/ZZ"+postfix),-1)
       hOS_high.Add(fVV.Get("AIOS/WZ"+postfix),-1)
       for i in range(0,hOS_high.GetSize()-2):
           if hOS_high.GetBinContent(i)<0:
               hOS_high.SetBinError(i,max(0,hOS_high.GetBinError(i)+hOS_high.GetBinError(i)))
               hOS_high.SetBinContent(i,0)

       hSS_high=fData.Get("AISS/data_obs"+postfix)
       hSS_high.Add(fVV.Get("AISS/ZZ"+postfix),-1)
       hSS_high.Add(fVV.Get("AISS/WZ"+postfix),-1)
       for i in range(0,hSS_high.GetSize()-2):
           if hSS_high.GetBinContent(i)<0:
               hSS_high.SetBinError(i,max(0,hSS_high.GetBinError(i)+hSS_high.GetBinError(i)))
               hSS_high.SetBinContent(i,0)

       hOS_low=fData.Get("AIOS1/data_obs"+postfix)
       hOS_low.Add(fVV.Get("AIOS1/ZZ"+postfix),-1)
       hOS_low.Add(fVV.Get("AIOS1/WZ"+postfix),-1)
       for i in range(0,hOS_low.GetSize()-2):
           if hOS_low.GetBinContent(i)<0:
               hOS_low.SetBinError(i,max(0,hOS_low.GetBinError(i)+hOS_low.GetBinError(i)))
               hOS_low.SetBinContent(i,0)

       hSS_low=fData.Get("AISS1/data_obs"+postfix)
       hSS_low.Add(fVV.Get("AISS1/ZZ"+postfix),-1)
       hSS_low.Add(fVV.Get("AISS1/WZ"+postfix),-1)
       for i in range(0,hSS_low.GetSize()-2):
           if hSS_low.GetBinContent(i)<0:
               hSS_low.SetBinError(i,max(0,hSS_low.GetBinError(i)+hSS_low.GetBinError(i)))
               hSS_low.SetBinContent(i,0)

       h1OS_high=fData.Get("AI1OS/data_obs"+postfix)
       h1OS_high.Add(fVV.Get("AI1OS/ZZ"+postfix),-1)
       h1OS_high.Add(fVV.Get("AI1OS/WZ"+postfix),-1)
       h1OS_high.Add(fData.Get("AI2OS/data_obs"+postfix))
       h1OS_high.Add(fVV.Get("AI2OS/ZZ"+postfix),-1)
       h1OS_high.Add(fVV.Get("AI2OS/WZ"+postfix),-1)
       h1OS_high.Add(fData.Get("AI0OS/data_obs"+postfix),-1)
       h1OS_high.Add(fVV.Get("AI0OS/ZZ"+postfix))
       h1OS_high.Add(fVV.Get("AI0OS/WZ"+postfix))
       for i in range(0,h1OS_high.GetSize()-2):
           if h1OS_high.GetBinContent(i)<0:
               h1OS_high.SetBinError(i,max(0,h1OS_high.GetBinError(i)+h1OS_high.GetBinError(i)))
               h1OS_high.SetBinContent(i,0)

       h1SS_high=fData.Get("AI1SS/data_obs"+postfix)
       h1SS_high.Add(fVV.Get("AI1SS/ZZ"+postfix),-1)
       h1SS_high.Add(fVV.Get("AI1SS/WZ"+postfix),-1)
       h1SS_high.Add(fData.Get("AI2SS/data_obs"+postfix))
       h1SS_high.Add(fVV.Get("AI2SS/ZZ"+postfix),-1)
       h1SS_high.Add(fVV.Get("AI2SS/WZ"+postfix),-1)
       h1SS_high.Add(fData.Get("AI0SS/data_obs"+postfix),-1)
       h1SS_high.Add(fVV.Get("AI0SS/ZZ"+postfix))
       h1SS_high.Add(fVV.Get("AI0SS/WZ"+postfix))
       for i in range(0,h1SS_high.GetSize()-2):
           if h1SS_high.GetBinContent(i)<0:
               h1SS_high.SetBinError(i,max(0,h1SS_high.GetBinError(i)+h1SS_high.GetBinError(i)))
               h1SS_high.SetBinContent(i,0)

       h1OS_low=fData.Get("AI1OS1/data_obs"+postfix)
       h1OS_low.Add(fVV.Get("AI1OS1/ZZ"+postfix),-1)
       h1OS_low.Add(fVV.Get("AI1OS1/WZ"+postfix),-1)
       h1OS_low.Add(fData.Get("AI2OS1/data_obs"+postfix))
       h1OS_low.Add(fVV.Get("AI2OS1/ZZ"+postfix),-1)
       h1OS_low.Add(fVV.Get("AI2OS1/WZ"+postfix),-1)
       h1OS_low.Add(fData.Get("AI0OS1/data_obs"+postfix),-1)
       h1OS_low.Add(fVV.Get("AI0OS1/ZZ"+postfix))
       h1OS_low.Add(fVV.Get("AI0OS1/WZ"+postfix))
       for i in range(0,h1OS_low.GetSize()-2):
           if h1OS_low.GetBinContent(i)<0:
               h1OS_low.SetBinError(i,max(0,h1OS_low.GetBinError(i)+h1OS_low.GetBinError(i)))
               h1OS_low.SetBinContent(i,0)

       h1SS_low=fData.Get("AI1SS1/data_obs"+postfix)
       h1SS_low.Add(fVV.Get("AI1SS1/ZZ"+postfix),-1)
       h1SS_low.Add(fVV.Get("AI1SS1/WZ"+postfix),-1)
       h1SS_low.Add(fData.Get("AI2SS1/data_obs"+postfix))
       h1SS_low.Add(fVV.Get("AI2SS1/ZZ"+postfix),-1)
       h1SS_low.Add(fVV.Get("AI2SS1/WZ"+postfix),-1)
       h1SS_low.Add(fData.Get("AI0SS1/data_obs"+postfix),-1)
       h1SS_low.Add(fVV.Get("AI0SS1/ZZ"+postfix))
       h1SS_low.Add(fVV.Get("AI0SS1/WZ"+postfix))
       for i in range(0,h1SS_low.GetSize()-2):
           if h1SS_low.GetBinContent(i)<0:
               h1SS_low.SetBinError(i,max(0,h1SS_low.GetBinError(i)+h1SS_low.GetBinError(i)))
               h1SS_low.SetBinContent(i,0)


       fout.cd()
       dirOS_high.cd()
       hOS_high.SetName("jetFakes"+postfix)
       h1OS_high.SetName("allFakes"+postfix)
       hOS_high.Write()
       h1OS_high.Write()

       dirSS_high.cd()
       hSS_high.SetName("jetFakes"+postfix)
       hSS_high.Write()
       h1SS_high.SetName("allFakes"+postfix)
       h1SS_high.Write()

       dirOS_low.cd()
       hOS_low.SetName("jetFakes"+postfix)
       h1OS_low.SetName("allFakes"+postfix)
       hOS_low.Write()
       h1OS_low.Write()

       dirSS_low.cd()
       hSS_low.SetName("jetFakes"+postfix)
       hSS_low.Write()
       h1SS_low.SetName("allFakes"+postfix)
       h1SS_low.Write()



