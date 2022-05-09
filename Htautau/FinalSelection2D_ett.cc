#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include "TMultiGraph.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <TF1.h>
#include <TDirectoryFile.h>
#include <TRandom3.h>
#include "TLorentzVector.h"
#include "TString.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TKey.h"
#include "THashList.h"
#include "THStack.h"
#include "TPaveLabel.h"
#include "TFile.h"
#include "myHelper.h"
#include "tr_Tree.h"
#include "GetTauFR.h"
#include "LumiReweightingStandAlone.h"
#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooFunctor.h"

using namespace std;

int main(int argc, char** argv) {

    std::string input = *(argv + 1);
    std::string output = *(argv + 2);
    std::string sample = *(argv + 3);
    std::string name = *(argv + 4);
    std::string Wsign = *(argv + 5);

    float year=2016;
    if (argc > 1) {
        year = atof(argv[6]);
    }

    TFile *f_Double = new TFile(input.c_str());
    cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<endl;
    TTree *arbre = (TTree*) f_Double->Get("ett_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);

    float xs=1.0; float weight=1.0; float luminosity=36330.0;
    if (year==2017) luminosity=41500.0;
    if (year==2018) luminosity=59500.0;

    if (sample=="DY" or sample=="ZL" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL"){ xs=5765.4; weight=luminosity*xs/ngen;}
    else if (sample=="TTL" or sample=="TT" or sample=="TTT" or sample=="TTJ") {xs=831.76; weight=luminosity*xs/ngen;}
    else if (sample=="TTTo2L2Nu") {xs=831.76*3*0.1086*3*0.1086; weight=luminosity*xs/ngen;}
    else if (sample=="TTToHadronic") {xs=831.76*0.6741*0.6741; weight=luminosity*xs/ngen;}
    else if (sample=="TTToSemiLeptonic") {xs=831.76*2*3*0.1086*0.6741; weight=luminosity*xs/ngen;}
    else if (sample=="W") {xs=61526.7; weight=luminosity*xs/ngen;}
    else if (sample=="QCD") {xs=720648000*0.00042; weight=luminosity*xs/ngen;}
    else if (sample=="data_obs"){weight=1.0;}
    else if (sample=="WZ1L1Nu2Q") {xs=10.71; weight=luminosity*xs/ngen;}
    else if (sample=="WZ1L3Nu") {xs=3.05; weight=luminosity*xs/ngen;}
    else if (sample=="WZJets") {xs=5.26; weight=luminosity*xs/ngen;}
    else if (sample=="WZLLLNu") {xs=4.708; weight=luminosity*xs/ngen;}
    else if (sample=="WZ2L2Q") {xs=5.595; weight=luminosity*xs/ngen;}
    else if (sample=="WW1L1Nu2Q") {xs=49.997; weight=luminosity*xs/ngen;}
    else if (sample=="HNL10") {xs=1.5*0.255; weight=luminosity*xs/ngen;}
    else if (sample=="HNL60") {xs=1.5*0.06675; weight=luminosity*xs/ngen;}
    else if (sample=="HNL150") {xs=1000*1.5*0.00007809; weight=luminosity*xs/ngen;}
    else if (sample=="HNL200") {xs=1000*1.5*0.00002463; weight=luminosity*xs/ngen;}
    else if (sample=="HNL400") {xs=1000*1.5*0.00000173; weight=luminosity*xs/ngen;}
    else if (sample=="HNL600") {xs=1000*1.5*0.000000347; weight=luminosity*xs/ngen;}
    else if (sample=="HNL800") {xs=1000*1.5*0.000000102; weight=luminosity*xs/ngen;}
    else if (sample=="HNL1000") {xs=1000*1.5*0.00000003659; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ4L") {xs=1.256*1.1; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ2L2Q") {xs=3.22; weight=luminosity*xs/ngen;}
    else if (sample=="VV2L2Nu") {xs=11.95; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_antitop") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_top") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_antitop") {xs=26.23; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_top") {xs=44.07; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ4L_powheg") {xs=1.256*1.1; weight=luminosity*xs/ngen;}
    else if (sample=="WZ3LNu_powheg") {xs=4.708; weight=luminosity*xs/ngen;}
    else if (sample=="ttZ") {xs=0.2529; weight=luminosity*xs/ngen;}
    else if (sample=="ttW") {xs=0.2043; weight=luminosity*xs/ngen;}
    else if (sample=="ZG") {xs=117.864; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ2e2mu") {xs=1.7*0.00319; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ2e2tau") {xs=1.7*0.00319; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ2mu2tau") {xs=1.7*0.00319; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ4e") {xs=1.7*0.00159; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ4mu") {xs=1.7*0.00159; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ4tau") {xs=1.7*0.00159; weight=luminosity*xs/ngen;}
    else if (sample=="WWW") {xs=0.2086; weight=luminosity*xs/ngen;}
    else if (sample=="WWZ") {xs=0.1651; weight=luminosity*xs/ngen;}
    else if (sample=="WZZ") {xs=0.05565; weight=luminosity*xs/ngen;}
    else if (sample=="ZZZ") {xs=0.01398; weight=luminosity*xs/ngen;}
    //else if (sample=="WplusH125") {xs=0.840*0.06208; weight=luminosity*xs/ngen;}
    //else if (sample=="WminusH125") {xs=0.5328*0.06208; weight=luminosity*xs/ngen;}
    //else if (sample=="ZH125") {xs=0.7612*0.06208; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH125") {xs=1.00*0.06208; weight=luminosity*xs/(ngen*0.3258);}
    else if (sample=="WplusH125") {xs=1.00*0.06208; weight=luminosity*xs/(ngen*0.3258);}
    else if (sample=="ZH125") {xs=1.00*0.06208; weight=luminosity*xs/(ngen*3*0.033658);}
    else if (sample=="GGZH") {xs=0.1223*0.06208; weight=luminosity*xs/ngen;}
    else if (sample=="GGZHLLTT") {xs=0.1223*0.06208*3*0.033658; weight=luminosity*xs/ngen;}
    else if (sample=="GGZHNNTT") {xs=0.1223*0.06208*0.2000; weight=luminosity*xs/ngen;}
    else if (sample=="GGZHQQTT") {xs=0.1223*0.06208*0.6991; weight=luminosity*xs/ngen;}
    //else if (sample=="WplusHWW") {xs=0.840*0.2203*0.3258*0.3258; weight=luminosity*xs/ngen;}
    //else if (sample=="WminusHWW") {xs=0.5328*0.2203*0.3258*0.3258; weight=luminosity*xs/ngen;}
    //else if (sample=="ZHWW") {xs=0.7612*0.2203; weight=luminosity*xs/ngen;}
    else if (sample=="WplusHWW") {xs=1.00*0.2203*0.3258*0.3258; weight=luminosity*xs/(ngen*0.3258);}
    else if (sample=="WminusHWW") {xs=1.00*0.2203*0.3258*0.3258; weight=luminosity*xs/(ngen*0.3258);}
    else if (sample=="ZHWW") {xs=1.00*0.2203; weight=luminosity*xs/(ngen*3*0.033658);}
    else if (sample=="GGZHWW") {xs=0.1223*0.2203; weight=luminosity*xs/ngen;}
    else if (sample=="ttH125") {xs=0.5033*0.06208; weight=luminosity*xs/ngen;}//FIXME
    else if (sample=="ttHTT") {xs=0.5033*0.06208; weight=luminosity*xs/ngen;}//FIXME
    else if (sample=="ttHnonBB") {xs=0.5033*(1-0.577); weight=luminosity*xs/ngen;}//FIXME
    else cout<<"Attention!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    arbre->SetBranchAddress("Rivet_higgsPt", &Rivet_higgsPt);
    arbre->SetBranchAddress("Rivet_VPt", &Rivet_VPt);
    arbre->SetBranchAddress("Rivet_nJets30", &Rivet_nJets30);
    arbre->SetBranchAddress("Rivet_stage1_1_fine_cat_pTjet30GeV", & Rivet_stage1_1_fine_cat_pTjet30GeV);
    arbre->SetBranchAddress("Rivet_stage1_1_cat_pTjet30GeV", & Rivet_stage1_1_cat_pTjet30GeV);
    arbre->SetBranchAddress("Rivet_stage1_cat_pTjet30GeV", & Rivet_stage1_cat_pTjet30GeV);
    arbre->SetBranchAddress("PythiaWeight_isr_muR2", &PythiaWeight_isr_muR2);
    arbre->SetBranchAddress("PythiaWeight_isr_muR0p5", &PythiaWeight_isr_muR0p5);
    arbre->SetBranchAddress("PythiaWeight_fsr_muR2", &PythiaWeight_fsr_muR2);
    arbre->SetBranchAddress("PythiaWeight_fsr_muR0p5", &PythiaWeight_fsr_muR0p5);
    arbre->SetBranchAddress("lheweight_muR0p5_muF0p5", &lheweight_muR0p5_muF0p5);
    arbre->SetBranchAddress("lheweight_muR2_muF2", &lheweight_muR2_muF2);
    arbre->SetBranchAddress("lheweight_nominal", &lheweight_nominal);
    arbre->SetBranchAddress("run", &run);
    arbre->SetBranchAddress("lumi", &lumi);
    arbre->SetBranchAddress("evt", &evt);
    arbre->SetBranchAddress("npv", &npv);
    arbre->SetBranchAddress("pt_1", &pt_1);
    arbre->SetBranchAddress("phi_1", &phi_1);
    arbre->SetBranchAddress("eta_1", &eta_1);
    arbre->SetBranchAddress("iso_1", &iso_1);
    arbre->SetBranchAddress("m_1", &m_1);
    arbre->SetBranchAddress("q_1", &q_1);
    arbre->SetBranchAddress("eid80iso_1", &eid80iso_1);
    arbre->SetBranchAddress("eid90iso_1", &eid90iso_1);
    arbre->SetBranchAddress("eid80noiso_1", &eid80noiso_1);
    arbre->SetBranchAddress("eid90noiso_1", &eid90noiso_1);
    arbre->SetBranchAddress("q_2", &q_2);
    arbre->SetBranchAddress("pt_2", &pt_2);
    arbre->SetBranchAddress("eta_2", &eta_2);
    arbre->SetBranchAddress("m_2", &m_2);
    arbre->SetBranchAddress("phi_2", &phi_2);
    arbre->SetBranchAddress("q_3", &q_3);
    arbre->SetBranchAddress("pt_3", &pt_3);
    arbre->SetBranchAddress("eta_3", &eta_3);
    arbre->SetBranchAddress("m_3", &m_3);
    arbre->SetBranchAddress("phi_3", &phi_3);
    arbre->SetBranchAddress("met", &met);
    arbre->SetBranchAddress("metphi", &metphi);
    arbre->SetBranchAddress("njets", &njets);
    arbre->SetBranchAddress("jpt_1", &jpt_1);
    arbre->SetBranchAddress("mjj", &mjj);
    arbre->SetBranchAddress("aMCatNLO_weight", &aMCatNLO_weight);
    arbre->SetBranchAddress("metphi_UESDown", &metphi_UESDown);
    arbre->SetBranchAddress("metphi_UESUp", &metphi_UESUp);
    arbre->SetBranchAddress("met_UESDown", &met_UESDown);
    arbre->SetBranchAddress("met_UESUp", &met_UESUp);

    arbre->SetBranchAddress("prefiring_weight", &prefiring_weight);
    arbre->SetBranchAddress("prefiring_weight_up", &prefiring_weight_up);
    arbre->SetBranchAddress("prefiring_weight_down", &prefiring_weight_down);
    arbre->SetBranchAddress("pt_1_ScaleDown", &pt_1_ScaleDown);
    arbre->SetBranchAddress("pt_1_ScaleUp", &pt_1_ScaleUp);
    arbre->SetBranchAddress("bweight", &bweight);

    arbre->SetBranchAddress("passEle27", &passEle27);
    arbre->SetBranchAddress("matchEle27_1", &matchEle27_1);
    arbre->SetBranchAddress("filterEle27_1", &filterEle27_1);
    arbre->SetBranchAddress("passEle32", &passEle32);
    arbre->SetBranchAddress("matchEle32_1", &matchEle32_1);
    arbre->SetBranchAddress("filterEle32_1", &filterEle32_1);
    arbre->SetBranchAddress("passEle35", &passEle35);
    arbre->SetBranchAddress("matchEle35_1", &matchEle35_1);
    arbre->SetBranchAddress("filterEle35_1", &filterEle35_1);
    arbre->SetBranchAddress("passEle25", &passEle25);
    arbre->SetBranchAddress("matchEle25_1", &matchEle25_1);
    arbre->SetBranchAddress("filterEle25_1", &filterEle25_1);
    arbre->SetBranchAddress("passEle24Tau30", &passEle24Tau30);
    arbre->SetBranchAddress("matchEle24Tau30_1", &matchEle24Tau30_1);
    arbre->SetBranchAddress("filterEle24Tau30_1", &filterEle24Tau30_1);
    arbre->SetBranchAddress("matchEle24Tau30_2", &matchEle24Tau30_2);
    arbre->SetBranchAddress("filterEle24Tau30_2", &filterEle24Tau30_2);
    arbre->SetBranchAddress("matchEle24Tau30_3", &matchEle24Tau30_3);
    arbre->SetBranchAddress("filterEle24Tau30_3", &filterEle24Tau30_3);
    arbre->SetBranchAddress("passEle24HPSTau30", &passEle24HPSTau30);
    arbre->SetBranchAddress("matchEle24HPSTau30_1", &matchEle24HPSTau30_1);
    arbre->SetBranchAddress("filterEle24HPSTau30_1", &filterEle24HPSTau30_1);
    arbre->SetBranchAddress("matchEle24HPSTau30_2", &matchEle24HPSTau30_2);
    arbre->SetBranchAddress("filterEle24HPSTau30_2", &filterEle24HPSTau30_2);
    arbre->SetBranchAddress("matchEle24HPSTau30_3", &matchEle24HPSTau30_3);
    arbre->SetBranchAddress("filterEle24HPSTau30_3", &filterEle24HPSTau30_3);

    arbre->SetBranchAddress("deepVVVLooseVSjet_3",&deepVVVLooseVSjet_3);
    arbre->SetBranchAddress("deepVVLooseVSjet_3",&deepVVLooseVSjet_3);
    arbre->SetBranchAddress("deepVLooseVSjet_3",&deepVLooseVSjet_3);
    arbre->SetBranchAddress("deepLooseVSjet_3",&deepLooseVSjet_3);
    arbre->SetBranchAddress("deepMediumVSjet_3",&deepMediumVSjet_3);
    arbre->SetBranchAddress("deepTightVSjet_3",&deepTightVSjet_3);
    arbre->SetBranchAddress("deepVTightVSjet_3",&deepVTightVSjet_3);
    arbre->SetBranchAddress("deepVVVLooseVSe_3",&deepVVVLooseVSe_3);
    arbre->SetBranchAddress("deepVVLooseVSe_3",&deepVVLooseVSe_3);
    arbre->SetBranchAddress("deepVLooseVSe_3",&deepVLooseVSe_3);
    arbre->SetBranchAddress("deepLooseVSe_3",&deepLooseVSe_3);
    arbre->SetBranchAddress("deepMediumVSe_3",&deepMediumVSe_3);
    arbre->SetBranchAddress("deepTightVSe_3",&deepTightVSe_3);
    arbre->SetBranchAddress("deepVTightVSe_3",&deepVTightVSe_3);
    arbre->SetBranchAddress("deepVVVLooseVSmu_3",&deepVVVLooseVSmu_3);
    arbre->SetBranchAddress("deepVVLooseVSmu_3",&deepVVLooseVSmu_3);
    arbre->SetBranchAddress("deepVLooseVSmu_3",&deepVLooseVSmu_3);
    arbre->SetBranchAddress("deepLooseVSmu_3",&deepLooseVSmu_3);
    arbre->SetBranchAddress("deepMediumVSmu_3",&deepMediumVSmu_3);
    arbre->SetBranchAddress("deepTightVSmu_3",&deepTightVSmu_3);
    arbre->SetBranchAddress("deepVTightVSmu_3",&deepVTightVSmu_3);

    arbre->SetBranchAddress("deepVVVLooseVSjet_2",&deepVVVLooseVSjet_2);
    arbre->SetBranchAddress("deepVVLooseVSjet_2",&deepVVLooseVSjet_2);
    arbre->SetBranchAddress("deepVLooseVSjet_2",&deepVLooseVSjet_2);
    arbre->SetBranchAddress("deepLooseVSjet_2",&deepLooseVSjet_2);
    arbre->SetBranchAddress("deepMediumVSjet_2",&deepMediumVSjet_2);
    arbre->SetBranchAddress("deepTightVSjet_2",&deepTightVSjet_2);
    arbre->SetBranchAddress("deepVTightVSjet_2",&deepVTightVSjet_2);
    arbre->SetBranchAddress("deepVVVLooseVSe_2",&deepVVVLooseVSe_2);
    arbre->SetBranchAddress("deepVVLooseVSe_2",&deepVVLooseVSe_2);
    arbre->SetBranchAddress("deepVLooseVSe_2",&deepVLooseVSe_2);
    arbre->SetBranchAddress("deepLooseVSe_2",&deepLooseVSe_2);
    arbre->SetBranchAddress("deepMediumVSe_2",&deepMediumVSe_2);
    arbre->SetBranchAddress("deepTightVSe_2",&deepTightVSe_2);
    arbre->SetBranchAddress("deepVTightVSe_2",&deepVTightVSe_2);
    arbre->SetBranchAddress("deepVVVLooseVSmu_2",&deepVVVLooseVSmu_2);
    arbre->SetBranchAddress("deepVVLooseVSmu_2",&deepVVLooseVSmu_2);
    arbre->SetBranchAddress("deepVLooseVSmu_2",&deepVLooseVSmu_2);
    arbre->SetBranchAddress("deepLooseVSmu_2",&deepLooseVSmu_2);
    arbre->SetBranchAddress("deepMediumVSmu_2",&deepMediumVSmu_2);
    arbre->SetBranchAddress("deepTightVSmu_2",&deepTightVSmu_2);
    arbre->SetBranchAddress("deepVTightVSmu_2",&deepVTightVSmu_2);

    arbre->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices);
    arbre->SetBranchAddress("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter);
    arbre->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter);
    arbre->SetBranchAddress("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter);
    arbre->SetBranchAddress("Flag_ecalBadCalibReducedMINIAODFilter", &Flag_ecalBadCalibReducedMINIAODFilter);
    arbre->SetBranchAddress("Flag_badMuons", &Flag_badMuons);
    arbre->SetBranchAddress("Flag_duplicateMuons", &Flag_duplicateMuons);
    arbre->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter);
    arbre->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter);
    arbre->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter);
    arbre->SetBranchAddress("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter);
    arbre->SetBranchAddress("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter);

    arbre->SetBranchAddress("l2_decayMode",&l2_decayMode);
    arbre->SetBranchAddress("l3_decayMode",&l3_decayMode);
    arbre->SetBranchAddress("gen_match_1",&gen_match_1);
    arbre->SetBranchAddress("gen_match_2",&gen_match_2);
    arbre->SetBranchAddress("gen_match_3",&gen_match_3);
    arbre->SetBranchAddress("m_vis",&m_vis);
    arbre->SetBranchAddress("npu",&npu);
    arbre->SetBranchAddress("genpT",&genpT);
    arbre->SetBranchAddress("genM",&genM);
    arbre->SetBranchAddress("pt_top1",&pt_top1);
    arbre->SetBranchAddress("pt_top2",&pt_top2);
    arbre->SetBranchAddress("numGenJets",&numGenJets);
    arbre->SetBranchAddress("nbtag",&nbtag);
    arbre->SetBranchAddress("bpt_1",&bpt_1);
    arbre->SetBranchAddress("bpt_2",&bpt_2);
    arbre->SetBranchAddress("bflavor_1",&bflavor_1);
    arbre->SetBranchAddress("bflavor_2",&bflavor_2);

   //float bins[] = {20,30,40,50,60,70,80,90,100,110,120,130,140};
   //int  binnum = sizeof(bins)/sizeof(Float_t) - 1;

   float bins[] = {0,50,70,90,110,130,150,170,290};
   int  binnum = sizeof(bins)/sizeof(Float_t) - 1;
   float binsPTV[] ={0,75,150,1000};
   int  binnumPTV = sizeof(binsPTV)/sizeof(Float_t) - 1;

   std::vector<TH2F*> h0_OS;
   std::vector<TH1F*> h0_SS;
   std::vector<TH2F*> h0_AIOS;
   std::vector<TH1F*> h0_AISS;
   std::vector<TH1F*> h0_lowOS;
   std::vector<TH1F*> h0_AIlowOS;

   int nbhist=1+28+56;

   for (int k=0; k<nbhist; ++k){
        ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
        h0_OS.push_back(new TH2F (HNS0OS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_OS[k]->Sumw2();

        ostringstream HNS0SS; HNS0SS << "h0_SS" << k;
        h0_SS.push_back(new TH1F (HNS0SS.str().c_str(),"InvMa",20,0,200)); h0_SS[k]->Sumw2();

        ostringstream HNS0AIOS; HNS0AIOS << "h0_AIOS" << k;
        h0_AIOS.push_back(new TH2F (HNS0AIOS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AIOS[k]->Sumw2();

        ostringstream HNS0AISS; HNS0AISS << "h0_AISS" << k;
        h0_AISS.push_back(new TH1F (HNS0AISS.str().c_str(),"InvMa",20,0,200)); h0_AISS[k]->Sumw2();

        ostringstream HNS0lowOS; HNS0lowOS << "h0_lowOS" << k;
        h0_lowOS.push_back(new TH1F (HNS0lowOS.str().c_str(),"InvMa",20,0,200)); h0_lowOS[k]->Sumw2();
        ostringstream HNS0AIlowOS; HNS0AIlowOS << "h0_AIlowOS" << k;
        h0_AIlowOS.push_back(new TH1F (HNS0AIlowOS.str().c_str(),"InvMa",20,0,200)); h0_AIlowOS[k]->Sumw2();
   }

    TFile *f_taufr=new TFile("FitHistograms_tauFR_2016.root");
    if (year==2016) f_taufr=new TFile("FitHistograms_tauFR_2016.root");
    if (year==2017) f_taufr=new TFile("FitHistograms_tauFR_2017.root");
    if (year==2018) f_taufr=new TFile("FitHistograms_tauFR_2018.root");
    TGraphAsymmErrors *g_taufr_dm0VT = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm0_Te_Tmu_deepverytight_hpt_dm0_Te_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm1VT = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm1_Te_Tmu_deepverytight_hpt_dm1_Te_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm10VT = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm10_Te_Tmu_deepverytight_hpt_dm10_Te_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm11VT = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm11_Te_Tmu_deepverytight_hpt_dm11_Te_Tmu_deepveryveryveryloose");

    TGraphAsymmErrors *g_taufr_dm0M = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm0_Te_Tmu_deepmedium_hpt_dm0_Te_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm1M = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm1_Te_Tmu_deepmedium_hpt_dm1_Te_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm10M = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm10_Te_Tmu_deepmedium_hpt_dm10_Te_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm11M = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm11_Te_Tmu_deepmedium_hpt_dm11_Te_Tmu_deepveryveryveryloose");

   TString postfixTES[29]={"","_CMS_scale_t_1prong_2017Down","_CMS_scale_t_1prong_2017Up","_CMS_scale_t_1prong1pizero_2017Down","_CMS_scale_t_1prong1pizero_2017Up","_CMS_scale_t_3prong_2017Down","_CMS_scale_t_3prong_2017Up","_CMS_scale_t_3prong1pizero_2017Down","_CMS_scale_t_3prong1pizero_2017Up","_CMS_tauideff_pt20to25_2017Down","_CMS_tauideff_pt20to25_2017Up","_CMS_tauideff_pt25to30_2017Down","_CMS_tauideff_pt25to30_2017Up","_CMS_tauideff_pt30to35_2017Down","_CMS_tauideff_pt30to35_2017Up","_CMS_tauideff_pt35to40_2017Down","_CMS_tauideff_pt35to40_2017Up","_CMS_tauideff_ptgt40_2017Down","_CMS_tauideff_ptgt40_2017Up","_CMS_scale_met_unclustered_2017Down","_CMS_scale_met_unclustered_2017Up","_CMS_scale_e_2017Down","_CMS_scale_e_2017Up","_CMS_prefiringDown","_CMS_prefiringUp","_FIXMEDown","_FIXMEUp","_qqVH_NLOEWKDown","_qqVH_NLOEWKUp"};

   TString postfixFake[56]={"_CMS_fakeTauVT_Te_dm0_pt20to25_2017Up","_CMS_fakeTauVT_Te_dm0_pt20to25_2017Down","_CMS_fakeTauVT_Te_dm0_pt25to30_2017Up","_CMS_fakeTauVT_Te_dm0_pt25to30_2017Down","_CMS_fakeTauVT_Te_dm0_pt30to35_2017Up","_CMS_fakeTauVT_Te_dm0_pt30to35_2017Down","_CMS_fakeTauVT_Te_dm0_pt35to40_2017Up","_CMS_fakeTauVT_Te_dm0_pt35to40_2017Down","_CMS_fakeTauVT_Te_dm0_pt40to50_2017Up","_CMS_fakeTauVT_Te_dm0_pt40to50_2017Down","_CMS_fakeTauVT_Te_dm0_pt50to60_2017Up","_CMS_fakeTauVT_Te_dm0_pt50to60_2017Down","_CMS_fakeTauVT_Te_dm0_ptgt60_2017Up","_CMS_fakeTauVT_Te_dm0_ptgt60_2017Down","_CMS_fakeTauVT_Te_dm1_pt20to25_2017Up","_CMS_fakeTauVT_Te_dm1_pt20to25_2017Down","_CMS_fakeTauVT_Te_dm1_pt25to30_2017Up","_CMS_fakeTauVT_Te_dm1_pt25to30_2017Down","_CMS_fakeTauVT_Te_dm1_pt30to35_2017Up","_CMS_fakeTauVT_Te_dm1_pt30to35_2017Down","_CMS_fakeTauVT_Te_dm1_pt35to40_2017Up","_CMS_fakeTauVT_Te_dm1_pt35to40_2017Down","_CMS_fakeTauVT_Te_dm1_pt40to50_2017Up","_CMS_fakeTauVT_Te_dm1_pt40to50_2017Down","_CMS_fakeTauVT_Te_dm1_pt50to60_2017Up","_CMS_fakeTauVT_Te_dm1_pt50to60_2017Down","_CMS_fakeTauVT_Te_dm1_ptgt60_2017Up","_CMS_fakeTauVT_Te_dm1_ptgt60_2017Down","_CMS_fakeTauVT_Te_dm10_pt20to25_2017Up","_CMS_fakeTauVT_Te_dm10_pt20to25_2017Down","_CMS_fakeTauVT_Te_dm10_pt25to30_2017Up","_CMS_fakeTauVT_Te_dm10_pt25to30_2017Down","_CMS_fakeTauVT_Te_dm10_pt30to35_2017Up","_CMS_fakeTauVT_Te_dm10_pt30to35_2017Down","_CMS_fakeTauVT_Te_dm10_pt35to40_2017Up","_CMS_fakeTauVT_Te_dm10_pt35to40_2017Down","_CMS_fakeTauVT_Te_dm10_pt40to50_2017Up","_CMS_fakeTauVT_Te_dm10_pt40to50_2017Down","_CMS_fakeTauVT_Te_dm10_pt50to60_2017Up","_CMS_fakeTauVT_Te_dm10_pt50to60_2017Down","_CMS_fakeTauVT_Te_dm10_ptgt60_2017Up","_CMS_fakeTauVT_Te_dm10_ptgt60_2017Down","_CMS_fakeTauVT_Te_dm11_pt20to25_2017Up","_CMS_fakeTauVT_Te_dm11_pt20to25_2017Down","_CMS_fakeTauVT_Te_dm11_pt25to30_2017Up","_CMS_fakeTauVT_Te_dm11_pt25to30_2017Down","_CMS_fakeTauVT_Te_dm11_pt30to35_2017Up","_CMS_fakeTauVT_Te_dm11_pt30to35_2017Down","_CMS_fakeTauVT_Te_dm11_pt35to40_2017Up","_CMS_fakeTauVT_Te_dm11_pt35to40_2017Down","_CMS_fakeTauVT_Te_dm11_pt40to50_2017Up","_CMS_fakeTauVT_Te_dm11_pt40to50_2017Down","_CMS_fakeTauVT_Te_dm11_pt50to60_2017Up","_CMS_fakeTauVT_Te_dm11_pt50to60_2017Down","_CMS_fakeTauVT_Te_dm11_ptgt60_2017Up","_CMS_fakeTauVT_Te_dm11_ptgt60_2017Down"};

   for (int k = 0; k < 56; ++k){
      if (year==2016) postfixFake[k]=postfixFake[k].ReplaceAll("2017",4,"2016",4);
      if (year==2018) postfixFake[k]=postfixFake[k].ReplaceAll("2017",4,"2018",4);
   }
   for (int k = 0; k < 25; ++k){
      if (year==2016) postfixTES[k]=postfixTES[k].ReplaceAll("2017",4,"2016",4);
      if (year==2018) postfixTES[k]=postfixTES[k].ReplaceAll("2017",4,"2018",4);
   }

   TFile *ftauid = new TFile("TauID_SF_pt_DeepTau2017v2p1VSjet_2016Legacy.root");
   if (year==2017) ftauid = new TFile("TauID_SF_pt_DeepTau2017v2p1VSjet_2017ReReco.root");
   if (year==2018) ftauid = new TFile("TauID_SF_pt_DeepTau2017v2p1VSjet_2018ReReco.root");
   TF1 *fct_tauidOS= (TF1*) ftauid->Get("Medium_cent");
   TF1 *fct_tauidSS= (TF1*) ftauid->Get("VTight_cent");
   TF1 *fct_tauidOS_up= (TF1*) ftauid->Get("Medium_up");
   TF1 *fct_tauidOS_down= (TF1*) ftauid->Get("Medium_down");
   TF1 *fct_tauidSS_up= (TF1*) ftauid->Get("VTight_up");
   TF1 *fct_tauidSS_down= (TF1*) ftauid->Get("VTight_down");

   float tes_dm0_do=0.991;
   float tes_dm1_do=0.994;
   float tes_dm10_do=0.993;
   float tes_dm11_do=0.988;
   float tes_dm0_up=1.009;
   float tes_dm1_up=1.006;
   float tes_dm10_up=1.007;
   float tes_dm11_up=1.012;
   if (year==2016){
    tes_dm0_do=0.992;
    tes_dm1_do=0.994;
    tes_dm10_do=0.992;
    tes_dm11_do=0.989;
    tes_dm0_up=1.008;
    tes_dm1_up=1.006;
    tes_dm10_up=1.008;
    tes_dm11_up=1.011;
   }
   if (year==2017){
    tes_dm0_do=0.990;
    tes_dm1_do=0.994;
    tes_dm10_do=0.993;
    tes_dm11_do=0.986;
    tes_dm0_up=1.010;
    tes_dm1_up=1.006;
    tes_dm10_up=1.007;
    tes_dm11_up=1.014;
   }

   TFile fwmc("htt_scalefactors_legacy_2016.root");
   RooWorkspace *wmc = (RooWorkspace*)fwmc.Get("w");
   fwmc.Close();
   if (year==2017){
     TFile fwmc("htt_scalefactors_legacy_2017.root");
     wmc = (RooWorkspace*)fwmc.Get("w");
     fwmc.Close();
   }
   if (year==2018){
     TFile fwmc("htt_scalefactors_legacy_2018.root");
     wmc = (RooWorkspace*)fwmc.Get("w");
     fwmc.Close();
   }

   reweight::LumiReWeighting* LumiWeights_12;
   LumiWeights_12 = new reweight::LumiReWeighting("MC_Moriond17_PU25ns_V1.root", "Data_Pileup_2016_271036-284044_80bins.root", "pileup", "pileup");
   if (year==2017){
      if (sample=="WplusH125") LumiWeights_12 = new reweight::LumiReWeighting("pu_distributions_mc_2017.root", "pu_distributions_data_2017.root", "pua/#WplusHToTauTau_M125_13TeV_powheg_pythia8#RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1#MINIAODSIM", "pileup");
      else if (sample=="WminusH125") LumiWeights_12 = new reweight::LumiReWeighting("pu_distributions_mc_2017.root", "pu_distributions_data_2017.root", "pua/#WminusHToTauTau_M125_13TeV_powheg_pythia8#RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1#MINIAODSIM", "pileup");
      else if (sample=="ZH125") LumiWeights_12 = new reweight::LumiReWeighting("pu_distributions_mc_2017.root", "pu_distributions_data_2017.root", "pua/#ZHToTauTau_M125_13TeV_powheg_pythia8#RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1#MINIAODSIM", "pileup");
      else LumiWeights_12 = new reweight::LumiReWeighting("pu_distributions_mc_2017.root", "pu_distributions_data_2017.root", "pua/#VBFHToTauTau_M125_13TeV_powheg_pythia8#RunIIFall17MiniAODv2-PU2017_12Apr2018_new_pmx_94X_mc2017_realistic_v14-v1#MINIAODSIM", "pileup");
   }
   if (year==2018)    LumiWeights_12 = new reweight::LumiReWeighting("pu_distributions_mc_2018.root", "pu_distributions_data_2018.root", "pileup", "pileup");

   float lheweight_nominalTo2_average=1.0;
   float lheweight_nominalTo0p5_average=1.0;
   TFile *f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/WplusHTT2018.root");
   if ((sample=="WplusHWW" or sample=="WplusH125") and year==2016) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/WplusHTT2016.root");
   if ((sample=="WminusHWW" or sample=="WminusH125") and year==2016) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/WminusHTT2016.root");
   if ((sample=="ZHWW" or sample=="ZH125") and year==2016) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/ZHTT2016.root");
   if ((sample=="GGZHWW" or sample=="GGZHLLTT") and year==2016) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/GGZHLLTT2016.root");
   if ((sample=="WplusHWW" or sample=="WplusH125") and year==2017) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/WplusHTT2017.root");
   if ((sample=="WminusHWW" or sample=="WminusH125") and year==2017) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/WminusHTT2017.root");
   if ((sample=="ZHWW" or sample=="ZH125") and year==2017) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/ZHTT2017.root");
   if ((sample=="GGZHWW" or sample=="GGZHLLTT") and year==2017) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/GGZHLLTT2017.root");
   if ((sample=="WplusHWW" or sample=="WplusH125") and year==2018) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/WplusHTT2018.root");
   if ((sample=="WminusHWW" or sample=="WminusH125") and year==2018) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/WminusHTT2018.root");
   if ((sample=="ZHWW" or sample=="ZH125") and year==2018) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/ZHTT2018.root");
   if ((sample=="GGZHWW" or sample=="GGZHLLTT") and year==2018) f_QCDScaleAcceptance_VHTT = new TFile("/afs/cern.ch/work/c/ccaillol/public/QCDScaleAcceptance/GGZHLLTT2018.root");


   TH1F *h_QCDScaleAcceptance_VH = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_vbf");
   TH1F *h_QCDScaleAcceptance_VH_scale_0jet = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_vbf_scale_0jet");
   TH1F *h_QCDScaleAcceptance_VH_scale_1jet = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_vbf_scale_1jet");
   TH1F *h_QCDScaleAcceptance_VH_scale_lowmjj = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_vbf_scale_lowmjj");
   TH1F *h_QCDScaleAcceptance_VH_scale_highmjj_lowpt = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_vbf_scale_highmjj_lowpt");
   TH1F *h_QCDScaleAcceptance_VH_scale_highmjj_highpt = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_vbf_scale_highmjj_highpt");
   TH1F *h_QCDScaleAcceptance_WH_lep = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_WH_lep");
   TH1F *h_QCDScaleAcceptance_ZH_lep = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_ZH_lep");
   TH1F *h_QCDScaleAcceptance_WH_scale_lowpt = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_WH_scale_lowpt");
   TH1F *h_QCDScaleAcceptance_WH_scale_highpt = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_WH_scale_highpt");
   TH1F *h_QCDScaleAcceptance_ZH_scale_lowpt = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_ZH_scale_lowpt");
   TH1F *h_QCDScaleAcceptance_ZH_scale_highpt = (TH1F*) f_QCDScaleAcceptance_VHTT->Get("demo/h_nevents_ZH_scale_highpt");

   // VH lep scale
   if (sample=="WminusHWW" or sample=="WplusHWW" or sample=="ZHWW" or sample=="GGZHWW" or sample=="WminusH125" or sample=="WplusH125" or sample=="ZH125" or sample=="GGZHLLTT" or sample=="GGZHNNTT"){
      if (name=="WH_lep_htt125" or name=="WH_lep_hww125") {lheweight_nominalTo2_average= h_QCDScaleAcceptance_WH_lep->GetBinContent(1)/h_QCDScaleAcceptance_WH_lep->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_WH_lep->GetBinContent(1)/h_QCDScaleAcceptance_WH_lep->GetBinContent(9); postfixTES[25]="_WHlep_scaleDown"; postfixTES[26]="_WHlep_scaleUp";}
      if (name=="ggZH_lep_htt125" or name=="ZH_lep_htt125" or name=="ggZH_lep_hww125" or name=="ZH_lep_hww125") {lheweight_nominalTo2_average= h_QCDScaleAcceptance_ZH_lep->GetBinContent(1)/h_QCDScaleAcceptance_ZH_lep->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_ZH_lep->GetBinContent(1)/h_QCDScaleAcceptance_ZH_lep->GetBinContent(9); postfixTES[25]="_ZHlep_scaleDown"; postfixTES[26]="_ZHlep_scaleUp";}
      if (name.find("WH_lep_PTV_0_75_h") < 140 or name.find("WH_lep_PTV_75_150_h") < 140 or name.find("WH_lep_PTV_150_250_0J_h") < 140 or name.find("WH_lep_PTV_150_250_GE1J_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(9); postfixTES[25]="_WH_scale_lowptDown"; postfixTES[26]="_WH_scale_lowptUp";}
      if (name.find("WH_lep_PTV_GT250_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(9); postfixTES[25]="_WH_scale_highptDown"; postfixTES[26]="_WH_scale_highptUp";}
      if (name.find("ZH_lep_PTV_0_75_h") < 140 or name.find("ZH_lep_PTV_75_150_h") < 140 or name.find("ZH_lep_PTV_150_250_0J_h") < 140 or name.find("ZH_lep_PTV_150_250_GE1J_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(9); postfixTES[25]="_ZH_scale_lowptDown"; postfixTES[26]="_ZH_scale_lowptUp";}
      if (name.find("ZH_lep_PTV_GT250_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(9); postfixTES[25]="_ZH_scale_highptDown"; postfixTES[26]="_ZH_scale_highptUp";}
   }

   TFile *f_Wm_nloEWKQCD = new TFile("Wm_nloEWK_weight_unnormalized.root");
   TH1F* h_Wm_nloEWKQCD=(TH1F*) f_Wm_nloEWKQCD->Get("SignalWeight_nloEWK_rebin");
   TH1F* h_Wm_nloEWKQCD_up=(TH1F*) f_Wm_nloEWKQCD->Get("SignalWeight_nloEWK_up_rebin");
   TH1F* h_Wm_nloEWKQCD_down=(TH1F*) f_Wm_nloEWKQCD->Get("SignalWeight_nloEWK_down_rebin");
   TFile *f_Wp_nloEWKQCD = new TFile("Wp_nloEWK_weight_unnormalized.root");
   TH1F* h_Wp_nloEWKQCD=(TH1F*) f_Wp_nloEWKQCD->Get("SignalWeight_nloEWK_rebin");
   TH1F* h_Wp_nloEWKQCD_up=(TH1F*) f_Wp_nloEWKQCD->Get("SignalWeight_nloEWK_up_rebin");
   TH1F* h_Wp_nloEWKQCD_down=(TH1F*) f_Wp_nloEWKQCD->Get("SignalWeight_nloEWK_down_rebin");
   TFile *f_Z_nloEWKQCD = new TFile("Zll_nloEWK_weight_unnormalized.root");
   TH1F* h_Z_nloEWKQCD=(TH1F*) f_Z_nloEWKQCD->Get("SignalWeight_nloEWK_rebin");
   TH1F* h_Z_nloEWKQCD_up=(TH1F*) f_Z_nloEWKQCD->Get("SignalWeight_nloEWK_up_rebin");
   TH1F* h_Z_nloEWKQCD_down=(TH1F*) f_Z_nloEWKQCD->Get("SignalWeight_nloEWK_down_rebin");

   Int_t nentries_wtn = (Int_t) arbre->GetEntries();
   for (Int_t i = 0; i < nentries_wtn; i++) {
        arbre->GetEntry(i);
        if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);

lheweight_nominal=1.0;

           if ((name.find("qqH_FWDH_htt1") < 140 or name.find("WH_had_FWDH_htt1") < 140 or name.find("ZH_had_FWDH_htt1") < 140 or name.find("VH_had_FWDH_htt1") < 140) && Rivet_stage1_1_cat_pTjet30GeV!=200) continue;
           if ((name.find("qqH_0J_htt1") < 140 or name.find("WH_had_0J_htt1") < 140 or name.find("ZH_had_0J_htt1") < 140 or name.find("VH_had_0J_htt1") < 140) && Rivet_stage1_1_cat_pTjet30GeV!=201) continue;
           if ((name.find("qqH_1J_htt1") < 140 or name.find("WH_had_1J_htt1") < 140 or name.find("ZH_had_1J_htt1") < 140 or name.find("VH_had_1J_htt1") < 140) && Rivet_stage1_1_cat_pTjet30GeV!=202) continue;
           if ((name.find("qqH_GE2J_MJJ_0_60_htt1") < 140 or name.find("ZH_had_GE2J_MJJ_0_60_htt1") < 140 or name.find("WH_had_GE2J_MJJ_0_60_htt1") < 140 or name.find("VH_had_GE2J_MJJ_0_60_htt1") < 140) && Rivet_stage1_1_cat_pTjet30GeV!=203) continue;
           if ((name.find("qqH_GE2J_MJJ_60_120_htt1") < 140 or name.find("ZH_had_GE2J_MJJ_60_120_htt1") < 140 or name.find("WH_had_GE2J_MJJ_60_120_htt1") < 140 or name.find("VH_had_GE2J_MJJ_60_120_htt1") < 140) && Rivet_stage1_1_cat_pTjet30GeV!=204) continue;
           if ((name.find("qqH_GE2J_MJJ_120_350_htt1") < 140 or name.find("ZH_had_GE2J_MJJ_120_350_htt1") < 140 or name.find("WH_had_GE2J_MJJ_120_350_htt1") < 140 or name.find("VH_had_GE2J_MJJ_120_350_htt1") < 140) && Rivet_stage1_1_cat_pTjet30GeV!=205) continue;
           if ((name.find("qqH_GE2J_MJJ_GE350_PTH_0_200_MJJ_350_700_PTHJJ_0_25_htt1") < 140 or name.find("ZH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_350_700_PTHJJ_0_25_htt1") < 140 or name.find("WH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_350_700_PTHJJ_0_25_htt1") < 140 or name.find("VH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_350_700_PTHJJ_0_25_htt1") < 140) && Rivet_stage1_1_cat_pTjet30GeV!=207) continue;
           if ((name.find("qqH_GE2J_MJJ_GE350_PTH_0_200_MJJ_350_700_PTHJJ_GE25_htt1") < 140 or name.find("ZH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_350_700_PTHJJ_GE25_htt1") < 140 or name.find("WH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_350_700_PTHJJ_GE25_htt1") < 140 or name.find("VH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_350_700_PTHJJ_GE25_htt1") < 140) && Rivet_stage1_1_cat_pTjet30GeV!=208) continue;
           if ((name.find("qqH_GE2J_MJJ_GE350_PTH_0_200_MJJ_GE700_PTHJJ_0_25_htt1") < 140 or name.find("ZH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_GE700_PTHJJ_0_25_htt1") < 140 or name.find("WH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_GE700_PTHJJ_0_25_htt1") < 140 or name.find("VH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_GE700_PTHJJ_0_25_htt1") < 140)&& Rivet_stage1_1_cat_pTjet30GeV!=209) continue;
           if ((name.find("qqH_GE2J_MJJ_GE350_PTH_0_200_MJJ_GE700_PTHJJ_GE25_htt1") < 140 or name.find("ZH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_GE700_PTHJJ_GE25_htt1") < 140 or name.find("WH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_GE700_PTHJJ_GE25_htt1") < 140 or name.find("VH_had_GE2J_MJJ_GE350_PTH_0_200_MJJ_GE700_PTHJJ_GE25_htt1") < 140) && Rivet_stage1_1_cat_pTjet30GeV!=210) continue;
           if ((name.find("qqH_GE2J_MJJ_GE350_PTH_GE200_htt1") < 140 or name.find("ZH_had_GE2J_MJJ_GE350_PTH_GE200_htt1") < 140 or name.find("WH_had_GE2J_MJJ_GE350_PTH_GE200_htt1") < 140 or name.find("VH_had_GE2J_MJJ_GE350_PTH_GE200_htt1") < 140) && Rivet_stage1_1_cat_pTjet30GeV!=206) continue;

           if (name.find("WH_lep_FWDH_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=300) continue;
           if (name.find("WH_lep_PTV_0_75_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=301) continue;
           if (name.find("WH_lep_PTV_75_150_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=302) continue;
           if (name.find("WH_lep_PTV_150_250_0J_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=303) continue;
           if (name.find("WH_lep_PTV_150_250_GE1J_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=304) continue;
           if (name.find("WH_lep_PTV_GT250_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=305) continue;
           if ((name=="ZH_lep_FWDH_htt125" or name=="ZH_lep_FWDH_hww125")  && Rivet_stage1_1_cat_pTjet30GeV!=400) continue;
           if ((name=="ZH_lep_PTV_0_75_htt125" or name=="ZH_lep_PTV_0_75_hww125") && Rivet_stage1_1_cat_pTjet30GeV!=401) continue;
           if ((name=="ZH_lep_PTV_75_150_htt125" or name=="ZH_lep_PTV_75_150_hww125") && Rivet_stage1_1_cat_pTjet30GeV!=402) continue;
           if ((name=="ZH_lep_PTV_150_250_0J_htt125" or name=="ZH_lep_PTV_150_250_0J_hww125") && Rivet_stage1_1_cat_pTjet30GeV!=403) continue;
           if ((name=="ZH_lep_PTV_150_250_GE1J_htt125" or name=="ZH_lep_PTV_150_250_GE1J_hww125") && Rivet_stage1_1_cat_pTjet30GeV!=404) continue;
           if ((name=="ZH_lep_PTV_GT250_htt125" or name=="ZH_lep_PTV_GT250_hww125") && Rivet_stage1_1_cat_pTjet30GeV!=405) continue;
           if (name.find("ggZH_lep_FWDH_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=500) continue;
           if (name.find("ggZH_lep_PTV_0_75_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=501) continue;
           if (name.find("ggZH_lep_PTV_75_150_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=502) continue;
           if (name.find("ggZH_lep_PTV_150_250_0J_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=503) continue;
           if (name.find("ggZH_lep_PTV_150_250_GE1J_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=504) continue;
           if (name.find("ggZH_lep_PTV_GT250_h") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=505) continue;

           if (name.find("ttH_FWDH_htt1") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=600) continue;
           if (name.find("ttH_stage1p1_htt1") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=601) continue;
           if (name.find("bbH_FWDH_htt1") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=700) continue;
           if (name.find("bbH_stage1p1_htt1") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=701) continue;
           if (name.find("tH_FWDH_htt1") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=800) continue;
           if (name.find("tH_stage1p1_htt1") < 140 && Rivet_stage1_1_cat_pTjet30GeV!=801) continue;
           /*if (name.find("ZH_lep_htt1") < 140 && Rivet_stage1_1_cat_pTjet30GeV<400) continue;
           if (name.find("ZH_had_htt1") < 140 && Rivet_stage1_1_cat_pTjet30GeV>=400) continue;
           if (name.find("WH_lep_htt1") < 140 && Rivet_stage1_1_cat_pTjet30GeV<300) continue;
           if (name.find("WH_had_htt1") < 140 && Rivet_stage1_1_cat_pTjet30GeV>=300) continue;*/


        if (Flag_goodVertices) continue;
        if (Flag_globalSuperTightHalo2016Filter) continue;
        if (Flag_HBHENoiseFilter) continue;
        if (Flag_HBHENoiseIsoFilter) continue;
        if (Flag_EcalDeadCellTriggerPrimitiveFilter) continue;
        if (Flag_BadPFMuonFilter) continue;
        if ((sample=="data_obs" or sample=="embedded") && Flag_eeBadScFilter) continue;
        if ((year==2017 or year==2018) && Flag_ecalBadCalibReducedMINIAODFilter) continue;

	if (!eid90noiso_1) continue;
	if (iso_1>0.15) continue;

        bool trigger1=true;
        bool trigger2=false;
        if (year==2016){
          trigger1=(passEle25 && matchEle25_1 && filterEle25_1 && pt_1>25.5 && fabs(eta_1)<2.1);
	  //trigger2=(passEle24Tau30 && matchEle24Tau30_1 && filterEle24Tau30_1 && pt_1>24.5 && pt_1<26.5 && fabs(eta_1)<2.1 && ((matchEle24Tau30_2 && filterEle24Tau30_2 && pt_2>34 && fabs(eta_2)<2.1) or (matchEle24Tau30_3 && filterEle24Tau30_3 && pt_3>34 && fabs(eta_3)<2.1)));
        }
        if (year==2017){
          trigger1=((passEle27 && matchEle27_1 && filterEle27_1 && pt_1>27.5 && fabs(eta_1)<2.1) or (passEle32 && matchEle32_1 && filterEle32_1 && pt_1>27.5 && fabs(eta_1)<2.1));
          //trigger2=(passEle24Tau30 && matchEle24Tau30_1 && filterEle24Tau30_1 && pt_1>24.5 && pt_1<28.5 && fabs(eta_1)<2.1 && ((matchEle24Tau30_2 && filterEle24Tau30_2 && pt_2>34 && fabs(eta_2)<2.1) or (matchEle24Tau30_3 && filterEle24Tau30_3 && pt_3>34 && fabs(eta_3)<2.1)));
        }
        if (year==2018){
          trigger1=((passEle32 && matchEle32_1 && filterEle32_1 && pt_1>32.5 && fabs(eta_1)<2.1) or (passEle35 && matchEle35_1 && filterEle35_1 && pt_1>32.5 && fabs(eta_1)<2.1));
	  //trigger2=(passEle24HPSTau30 && matchEle24HPSTau30_1 && filterEle24HPSTau30_1 && pt_1>24.5 && pt_1<33.5 && fabs(eta_1)<2.1 && ((matchEle24HPSTau30_2 && filterEle24HPSTau30_2 && pt_2>34 && fabs(eta_2)<2.1) or (matchEle24HPSTau30_3 && filterEle24HPSTau30_3 && pt_3>34 && fabs(eta_3)<2.1)));
          if (sample=="data_obs" && run<317509) trigger2=(passEle24Tau30 && matchEle24Tau30_1 && filterEle24Tau30_1 && pt_1>24.5 && pt_1<33.5 && fabs(eta_1)<2.1 && ((matchEle24Tau30_2 && filterEle24Tau30_2 && pt_2>34 && fabs(eta_2)<2.1) or (matchEle24Tau30_3 && filterEle24Tau30_3 && pt_3>34 && fabs(eta_3)<2.1)));
        }
	if (!trigger1) continue;
        //if (!trigger1 && !trigger2) continue;

        float tauiso_OS=deepMediumVSjet_2;
        float tauisoVL_SS=deepVVVLooseVSjet_3;
        float tauisoT_SS=deepVTightVSjet_3;
        float dm_OS=l2_decayMode;
        float dm_SS=l3_decayMode;
        float gen_match_OS=gen_match_2;
        float gen_match_SS=gen_match_3;
        if (q_1*q_2>0){
           tauiso_OS=deepMediumVSjet_3;
           tauisoVL_SS=deepVVVLooseVSjet_2;
           tauisoT_SS=deepVTightVSjet_2;
           dm_OS=l3_decayMode;
           dm_SS=l2_decayMode;
           gen_match_OS=gen_match_3;
           gen_match_SS=gen_match_2;
        }

        if (!deepVLooseVSmu_2 or !deepTightVSe_2 or !deepVLooseVSmu_3 or !deepTightVSe_3) continue;

	if ((sample=="TTTo2L2Nu" or sample=="TTToHadronic" or sample=="TTToSemiLeptonic" or sample=="DY" or sample=="TT") and gen_match_SS==6) continue;

	TLorentzVector mytauOS; 
        TLorentzVector mytauSS;
	if (q_1*q_2>0){ 
	   mytauSS.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
	   mytauOS.SetPtEtaPhiM(pt_3,eta_3,phi_3,m_3);
	}
	else{
           mytauOS.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
           mytauSS.SetPtEtaPhiM(pt_3,eta_3,phi_3,m_3);
        }
        TLorentzVector myele;
        myele.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);
        if (Wsign=="plus" and !(q_1>0)) continue;
        if (Wsign=="minus" and !(q_1<0)) continue;

	float signalRegion=(tauiso_OS and tauisoT_SS);
        float aiRegion=tauiso_OS and tauisoVL_SS and !tauisoT_SS;
	float signalRegionSS=deepTightVSjet_2 and deepTightVSjet_3;
	float ai0Region=deepVLooseVSjet_2 and !deepTightVSjet_2 and deepVLooseVSjet_3 and !deepTightVSjet_3;
        float ai1Region=deepTightVSjet_2 and deepVLooseVSjet_3 and !deepTightVSjet_3;
        float ai2Region=deepVLooseVSjet_2 and !deepMediumVSjet_2 and deepVTightVSjet_3;

	//***************** Weights **************

        if (sample=="W"){
            weight=57.3;
            if (numGenJets==1) weight=3.37;
            else if (numGenJets==2) weight=3.29;
            else if (numGenJets==3) weight=2.33;
            else if (numGenJets==4) weight=2.27;
        }
        if (sample=="DY"){
            weight=2.63;
            if (numGenJets==1)
                weight=0.7258;
            else if (numGenJets==2)
                weight=0.9387;
            else if (numGenJets==3)
                weight=1.683;
            else if (numGenJets==4)
                weight=0.4289;
        }

	if (nbtag>0) continue;

        float aweight=1.0;
        float vpt=Rivet_VPt;
        if (vpt>500) vpt=499;
        float nlo_corr=1.0;
        float nlo_corr_up=1.0;
        float nlo_corr_down=1.0;
        float ratio_nlo_up=1.0;
        float ratio_nlo_down=1.0;
        if (sample=="WminusH125" or sample=="WminusHWW"){
           nlo_corr=h_Wm_nloEWKQCD->GetBinContent(h_Wm_nloEWKQCD->GetXaxis()->FindBin(vpt));
           nlo_corr_up=h_Wm_nloEWKQCD_up->GetBinContent(h_Wm_nloEWKQCD_up->GetXaxis()->FindBin(vpt));
           nlo_corr_down=h_Wm_nloEWKQCD_down->GetBinContent(h_Wm_nloEWKQCD_down->GetXaxis()->FindBin(vpt));
           aweight=0.001*3*(61.51*nlo_corr+0.78+2.00);
           ratio_nlo_up=(61.51*nlo_corr_up+0.78+2.00)/(61.51*nlo_corr+0.78+2.00);
           ratio_nlo_down=(61.51*nlo_corr_down+0.78+2.00)/(61.51*nlo_corr+0.78+2.00);
        }
        if (sample=="WplusH125" or sample=="WplusHWW"){
           nlo_corr=h_Wp_nloEWKQCD->GetBinContent(h_Wp_nloEWKQCD->GetXaxis()->FindBin(vpt));
           nlo_corr_up=h_Wp_nloEWKQCD_up->GetBinContent(h_Wp_nloEWKQCD_up->GetXaxis()->FindBin(vpt));
           nlo_corr_down=h_Wp_nloEWKQCD_down->GetBinContent(h_Wp_nloEWKQCD_down->GetXaxis()->FindBin(vpt));
           aweight=0.001*3*(97.18*nlo_corr+1.20+3.09);
           ratio_nlo_up=(97.18*nlo_corr_up+1.20+3.09)/(97.18*nlo_corr+1.20+3.09);
           ratio_nlo_down=(97.18*nlo_corr_down+1.20+3.09)/(97.18*nlo_corr+1.20+3.09);
        }
        if (sample=="ZH125" or sample=="ZHWW"){
           nlo_corr=h_Z_nloEWKQCD->GetBinContent(h_Z_nloEWKQCD->GetXaxis()->FindBin(vpt));
           nlo_corr_up=h_Z_nloEWKQCD_up->GetBinContent(h_Z_nloEWKQCD_up->GetXaxis()->FindBin(vpt));
           nlo_corr_down=h_Z_nloEWKQCD_down->GetBinContent(h_Z_nloEWKQCD_down->GetXaxis()->FindBin(vpt));
           aweight=0.001*3*(26.66*nlo_corr+0.31+0.11);
           ratio_nlo_up=(26.66*nlo_corr_up+0.31+0.11)/(26.66*nlo_corr+0.31+0.11);
           ratio_nlo_down=(26.66*nlo_corr_down+0.31+0.11)/(26.66*nlo_corr+0.31+0.11);
        }

        if (year==2016 and sample!="data_obs"){
          aweight=aweight*aMCatNLO_weight*weight*LumiWeights_12->weight(npu);
          if (tauiso_OS && gen_match_OS==5) aweight=aweight*fct_tauidOS->Eval(mytauOS.Pt());
          if (tauisoT_SS && gen_match_SS==5) aweight=aweight*fct_tauidSS->Eval(mytauSS.Pt());
          if (gen_match_OS==1 or gen_match_OS==3){ // Medium VSe
             if (fabs(mytauOS.Eta())<1.448) aweight=aweight*1.44;
             else if (fabs(mytauOS.Eta())>1.558) aweight=aweight*1.08;
          }
          if (gen_match_OS==2 or gen_match_OS==4){ // VLoose VSmu
             if (fabs(mytauOS.Eta())<0.4) aweight=aweight*0.978*1.311;
             else if (fabs(mytauOS.Eta())<0.8) aweight=aweight*1.003*0.995;
             else if (fabs(mytauOS.Eta())<1.2) aweight=aweight*0.992*1.275;
             else if (fabs(mytauOS.Eta())<1.7) aweight=aweight*1.003*0.892;
             else aweight=aweight*0.966*5.111;
          }
          if (gen_match_SS==1 or gen_match_SS==3){ // Medium VSe
             if (fabs(mytauSS.Eta())<1.448) aweight=aweight*1.44;
             else if (fabs(mytauSS.Eta())>1.558) aweight=aweight*1.08;
          }
          if (gen_match_SS==2 or gen_match_SS==4){ // VLoose VSmu
             if (fabs(mytauSS.Eta())<0.4) aweight=aweight*0.978*1.311;
             else if (fabs(mytauSS.Eta())<0.8) aweight=aweight*1.003*0.995;
             else if (fabs(mytauSS.Eta())<1.2) aweight=aweight*0.992*1.275;
             else if (fabs(mytauSS.Eta())<1.7) aweight=aweight*1.003*0.892;
             else aweight=aweight*0.966*5.111;
          }
          wmc->var("e_pt")->setVal(myele.Pt());
          wmc->var("e_eta")->setVal(myele.Eta());
          wmc->var("e_iso")->setVal(iso_1);
          aweight=aweight*wmc->function("e_trk_ratio")->getVal();
          aweight=aweight*wmc->function("e_idiso_ic_ratio")->getVal();
          float sftrg1=wmc->function("e_trg_ic_ratio")->getVal();
          aweight=aweight*sftrg1;
          aweight=aweight*prefiring_weight;
          aweight=aweight*bweight;
        }
        if (year==2017 and sample!="data_obs"){
          aweight=aweight*aMCatNLO_weight*weight*LumiWeights_12->weight(npu);
          if (tauiso_OS && gen_match_OS==5) aweight=aweight*fct_tauidOS->Eval(mytauOS.Pt());
          if (tauisoT_SS && gen_match_SS==5) aweight=aweight*fct_tauidSS->Eval(mytauSS.Pt());
          if (gen_match_OS==1 or gen_match_OS==3){ // Medium VSe
             if (fabs(mytauOS.Eta())<1.448) aweight=aweight*1.18;
             else if (fabs(mytauOS.Eta())>1.558) aweight=aweight*0.86;
          }
          if (gen_match_OS==2 or gen_match_OS==4){ // VLoose VSmu
             if (fabs(mytauOS.Eta())<0.4) aweight=aweight*0.979*1.117;
             else if (fabs(mytauOS.Eta())<0.8) aweight=aweight*0.953*0.952;
             else if (fabs(mytauOS.Eta())<1.2) aweight=aweight*0.983*0.952;
             else if (fabs(mytauOS.Eta())<1.7) aweight=aweight*0.988*0.744;
             else aweight=aweight*1.004*4.592;
          }
          if (gen_match_SS==1 or gen_match_SS==3){ // Medium VSe
             if (fabs(mytauSS.Eta())<1.448) aweight=aweight*1.18;
             else if (fabs(mytauSS.Eta())>1.558) aweight=aweight*0.86;
          }
          if (gen_match_SS==2 or gen_match_SS==4){ // VLoose VSmu
             if (fabs(mytauSS.Eta())<0.4) aweight=aweight*0.979*1.117;
             else if (fabs(mytauSS.Eta())<0.8) aweight=aweight*0.953*0.952;
             else if (fabs(mytauSS.Eta())<1.2) aweight=aweight*0.983*0.952;
             else if (fabs(mytauSS.Eta())<1.7) aweight=aweight*0.988*0.744;
             else aweight=aweight*1.004*4.592;
          }
          wmc->var("e_pt")->setVal(myele.Pt());
          wmc->var("e_eta")->setVal(myele.Eta());
          wmc->var("e_iso")->setVal(iso_1);
          aweight=aweight*wmc->function("e_trk_ratio")->getVal();
          aweight=aweight*wmc->function("e_idiso_ic_ratio")->getVal();
          float sftrg1=wmc->function("e_trg_ic_ratio")->getVal();
          aweight=aweight*sftrg1;
          aweight=aweight*prefiring_weight;
          aweight=aweight*bweight;
        }
        if (year==2018 and sample!="data_obs"){
          aweight=aweight*aMCatNLO_weight*weight*LumiWeights_12->weight(npu);
          if (tauiso_OS && gen_match_OS==5) aweight=aweight*fct_tauidOS->Eval(mytauOS.Pt());
          if (tauisoT_SS && gen_match_SS==5) aweight=aweight*fct_tauidSS->Eval(mytauSS.Pt());
          if (gen_match_OS==1 or gen_match_OS==3){ // Medium VSe
             if (fabs(mytauOS.Eta())<1.448) aweight=aweight*1.25;
             else if (fabs(mytauOS.Eta())>1.558) aweight=aweight*0.65;
          }
          if (gen_match_OS==2 or gen_match_OS==4){ // VLoose VSmu
             if (fabs(mytauOS.Eta())<0.4) aweight=aweight*0.936*1.019;
             else if (fabs(mytauOS.Eta())<0.8) aweight=aweight*0.874*1.154;
             else if (fabs(mytauOS.Eta())<1.2) aweight=aweight*0.912*1.128;
             else if (fabs(mytauOS.Eta())<1.7) aweight=aweight*0.953*0.974;
             else aweight=aweight*0.936*5.342;
          }
          if (gen_match_SS==1 or gen_match_SS==3){ // Medium VSe
             if (fabs(mytauSS.Eta())<1.448) aweight=aweight*1.25;
             else if (fabs(mytauSS.Eta())>1.558) aweight=aweight*0.65;
          }
          if (gen_match_SS==2 or gen_match_SS==4){ // VLoose VSmu
             if (fabs(mytauSS.Eta())<0.4) aweight=aweight*0.936*1.019;
             else if (fabs(mytauSS.Eta())<0.8) aweight=aweight*0.874*1.154;
             else if (fabs(mytauSS.Eta())<1.2) aweight=aweight*0.912*1.128;
             else if (fabs(mytauSS.Eta())<1.7) aweight=aweight*0.953*0.974;
             else aweight=aweight*0.936*5.342;
          }
          wmc->var("e_pt")->setVal(myele.Pt());
          wmc->var("e_eta")->setVal(myele.Eta());
          wmc->var("e_iso")->setVal(iso_1);
          aweight=aweight*wmc->function("e_trk_ratio")->getVal();
          aweight=aweight*wmc->function("e_idiso_ic_ratio")->getVal();
          float sftrg1=wmc->function("e_trg_ic_ratio")->getVal();
          aweight=aweight*sftrg1;
          aweight=aweight*bweight;
        }
	if (sample=="data_obs") aweight=1.0;

        TLorentzVector myrawmet;
        myrawmet.SetPtEtaPhiM(met,0,metphi,0);
	TLorentzVector rawtauOS=mytauOS;
        TLorentzVector rawtauSS=mytauSS;
     	TLorentzVector myrawele=myele;

	for (int k=0; k<nbhist; ++k){

	    float weight2=1.0;

	    TLorentzVector mymet=myrawmet;
	    mytauOS=rawtauOS;
	    mytauSS=rawtauSS;
 	    myele=myrawele;

           if (sample!="data_obs" && sample!="embedded"){
              if (k>0 && k<9){ // TES x 8
                if (k==1){
		  if (dm_OS==0 && gen_match_OS==5){mytauOS*=tes_dm0_do; mymet=mymet+((1.0-tes_dm0_do)/tes_dm0_do)*mytauOS;}
                  if (dm_SS==0 && gen_match_SS==5){mytauSS*=tes_dm0_do; mymet=mymet+((1.0-tes_dm0_do)/tes_dm0_do)*mytauSS;}
		}
                else if (k==2){ 
                  if (dm_OS==0 && gen_match_OS==5){mytauOS*=tes_dm0_up; mymet=mymet+((1.0-tes_dm0_up)/tes_dm0_up)*mytauOS;}
                  if (dm_SS==0 && gen_match_SS==5){mytauSS*=tes_dm0_up; mymet=mymet+((1.0-tes_dm0_up)/tes_dm0_up)*mytauSS;}
                }
                else if (k==3){ 
                  if (dm_OS==1 && gen_match_OS==5){mytauOS*=tes_dm1_do; mymet=mymet+((1.0-tes_dm0_do)/tes_dm0_do)*mytauOS;}
                  if (dm_SS==1 && gen_match_SS==5){mytauSS*=tes_dm1_do; mymet=mymet+((1.0-tes_dm0_do)/tes_dm0_do)*mytauSS;}
                }
                else if (k==4){ 
                  if (dm_OS==1 && gen_match_OS==5){mytauOS*=tes_dm1_up; mymet=mymet+((1.0-tes_dm0_up)/tes_dm0_up)*mytauOS;}
                  if (dm_SS==1 && gen_match_SS==5){mytauSS*=tes_dm1_up; mymet=mymet+((1.0-tes_dm0_up)/tes_dm0_up)*mytauSS;}
                }
                else if (k==5){ 
                  if (dm_OS==10 && gen_match_OS==5){mytauOS*=tes_dm10_do; mymet=mymet+((1.0-tes_dm0_do)/tes_dm0_do)*mytauOS;}
                  if (dm_SS==10 && gen_match_SS==5){mytauSS*=tes_dm10_do; mymet=mymet+((1.0-tes_dm0_do)/tes_dm0_do)*mytauSS;}
                }
                else if (k==6){ 
                  if (dm_OS==10 && gen_match_OS==5){mytauOS*=tes_dm10_up; mymet=mymet+((1.0-tes_dm0_up)/tes_dm0_up)*mytauOS;}
                  if (dm_SS==10 && gen_match_SS==5){mytauSS*=tes_dm10_up; mymet=mymet+((1.0-tes_dm0_up)/tes_dm0_up)*mytauSS;}
                }
                else if (k==7){ 
                  if (dm_OS==11 && gen_match_OS==5){mytauOS*=tes_dm11_do; mymet=mymet+((1.0-tes_dm0_do)/tes_dm0_do)*mytauOS;}
                  if (dm_SS==11 && gen_match_SS==5){mytauSS*=tes_dm11_do; mymet=mymet+((1.0-tes_dm0_do)/tes_dm0_do)*mytauSS;}
                }
                else if (k==8){ 
                  if (dm_OS==11 && gen_match_OS==5){mytauOS*=tes_dm11_up; mymet=mymet+((1.0-tes_dm0_up)/tes_dm0_up)*mytauOS;}
                  if (dm_SS==11 && gen_match_SS==5){mytauSS*=tes_dm11_up; mymet=mymet+((1.0-tes_dm0_up)/tes_dm0_up)*mytauSS;}
                }
              }
              else if (k>8 && k<19){
                if (k==9){ 
		   if (mytauOS.Pt()>=20 && mytauOS.Pt()<25) weight2=fct_tauidOS_down->Eval(mytauOS.Pt())/fct_tauidOS->Eval(mytauOS.Pt());
		   if (mytauSS.Pt()>=20 && mytauSS.Pt()<25) weight2=fct_tauidSS_down->Eval(mytauSS.Pt())/fct_tauidSS->Eval(mytauSS.Pt());
		}
                else if (k==10){
                   if (mytauOS.Pt()>=20 && mytauOS.Pt()<25) weight2=fct_tauidOS_up->Eval(mytauOS.Pt())/fct_tauidOS->Eval(mytauOS.Pt());
                   if (mytauSS.Pt()>=20 && mytauSS.Pt()<25) weight2=fct_tauidSS_up->Eval(mytauSS.Pt())/fct_tauidSS->Eval(mytauSS.Pt());
                }
                else if (k==11){
                   if (mytauOS.Pt()>=25 && mytauOS.Pt()<30) weight2=fct_tauidOS_down->Eval(mytauOS.Pt())/fct_tauidOS->Eval(mytauOS.Pt());
                   if (mytauSS.Pt()>=25 && mytauSS.Pt()<30) weight2=fct_tauidSS_down->Eval(mytauSS.Pt())/fct_tauidSS->Eval(mytauSS.Pt());
                }
                else if (k==12){
                   if (mytauOS.Pt()>=25 && mytauOS.Pt()<30) weight2=fct_tauidOS_up->Eval(mytauOS.Pt())/fct_tauidOS->Eval(mytauOS.Pt());
                   if (mytauSS.Pt()>=25 && mytauSS.Pt()<30) weight2=fct_tauidSS_up->Eval(mytauSS.Pt())/fct_tauidSS->Eval(mytauSS.Pt());
                }
                else if (k==13){
                   if (mytauOS.Pt()>=30 && mytauOS.Pt()<35) weight2=fct_tauidOS_down->Eval(mytauOS.Pt())/fct_tauidOS->Eval(mytauOS.Pt());
                   if (mytauSS.Pt()>=30 && mytauSS.Pt()<35) weight2=fct_tauidSS_down->Eval(mytauSS.Pt())/fct_tauidSS->Eval(mytauSS.Pt());
                }
                else if (k==14){
                   if (mytauOS.Pt()>=30 && mytauOS.Pt()<35) weight2=fct_tauidOS_up->Eval(mytauOS.Pt())/fct_tauidOS->Eval(mytauOS.Pt());
                   if (mytauSS.Pt()>=30 && mytauSS.Pt()<35) weight2=fct_tauidSS_up->Eval(mytauSS.Pt())/fct_tauidSS->Eval(mytauSS.Pt());
                }
                else if (k==15){
                   if (mytauOS.Pt()>=35 && mytauOS.Pt()<40) weight2=fct_tauidOS_down->Eval(mytauOS.Pt())/fct_tauidOS->Eval(mytauOS.Pt());
                   if (mytauSS.Pt()>=35 && mytauSS.Pt()<40) weight2=fct_tauidSS_down->Eval(mytauSS.Pt())/fct_tauidSS->Eval(mytauSS.Pt());
                }
                else if (k==16){
                   if (mytauOS.Pt()>=35 && mytauOS.Pt()<40) weight2=fct_tauidOS_up->Eval(mytauOS.Pt())/fct_tauidOS->Eval(mytauOS.Pt());
                   if (mytauSS.Pt()>=35 && mytauSS.Pt()<40) weight2=fct_tauidSS_up->Eval(mytauSS.Pt())/fct_tauidSS->Eval(mytauSS.Pt());
                }
                else if (k==17){
                   if (mytauOS.Pt()>=40) weight2=fct_tauidOS_down->Eval(mytauOS.Pt())/fct_tauidOS->Eval(mytauOS.Pt());
                   if (mytauSS.Pt()>=40) weight2=fct_tauidSS_down->Eval(mytauSS.Pt())/fct_tauidSS->Eval(mytauSS.Pt());
                }
                else if (k==18){
                   if (mytauOS.Pt()>=40) weight2=fct_tauidOS_up->Eval(mytauOS.Pt())/fct_tauidOS->Eval(mytauOS.Pt());
                   if (mytauSS.Pt()>=40) weight2=fct_tauidSS_up->Eval(mytauSS.Pt())/fct_tauidSS->Eval(mytauSS.Pt());
                }
              }
              else if (k>18 && k<21){ // UES x 2
                if (k==19){mymet=myrawmet; mymet.SetPtEtaPhiM(met_UESDown, 0, metphi_UESDown, 0);}
                else if (k==20){mymet=myrawmet; mymet.SetPtEtaPhiM(met_UESUp, 0, metphi_UESUp, 0);}
              }
              if (k>20 && k<23){ // EES x 2 
                if (k==21){myele*=(pt_1_ScaleDown/myele.Pt()); mymet=mymet-myele+myrawele;}
                else if (k==22){myele*=(pt_1_ScaleUp/myele.Pt()); mymet=mymet-myele+myrawele;}
              }
              if (k>22 && k<25){ // prefiring x 2
                if (k==23) {weight2=prefiring_weight_down/(prefiring_weight+0.00000001);}
                else if (k==24) {weight2=prefiring_weight_up/(prefiring_weight+0.00000001);}
              }
              else if (k>24 && k<27){ // muR muF scale x 2
                if (k==25) weight2=lheweight_nominalTo0p5_average*(lheweight_muR0p5_muF0p5/lheweight_nominal);
                else if (k==26) weight2=lheweight_nominalTo2_average*(lheweight_muR2_muF2/lheweight_nominal);
              }
              else if (k>26 && k<29){ // qqVH reweighting x 2
                if (k==27) weight2=ratio_nlo_down;
                else if (k==28) weight2=ratio_nlo_up;
              }

            }

            if (year==2016){
              trigger1=(passEle25 && matchEle25_1 && filterEle25_1 && myele.Pt()>26 && fabs(myele.Eta())<2.1);
              //trigger2=(passEle24Tau30 && matchEle24Tau30_1 && filterEle24Tau30_1 && myele.Pt()>25 && myele.Pt()<26 && fabs(myele.Eta())<2.1 && ((fabs(mytauOS.Eta())<2.1 && mytauOS.Pt()>35) or (fabs(mytauSS.Eta())<2.1 && mytauSS.Pt()>35)));
            }
            if (year==2017){
              trigger1=((passEle27 && matchEle27_1 && filterEle27_1 && pt_1>28 && fabs(eta_1)<2.1) or (passEle32 && matchEle32_1 && filterEle32_1 && pt_1>28 && fabs(eta_1)<2.1));
	      //trigger2=(passEle24Tau30 && matchEle24Tau30_1 && filterEle24Tau30_1 && myele.Pt()>25 && myele.Pt()<28 && fabs(myele.Eta())<2.1 && ((fabs(mytauOS.Eta())<2.1 && mytauOS.Pt()>35) or (fabs(mytauSS.Eta())<2.1 && mytauSS.Pt()>35)));
            }
            if (year==2018){
              trigger1=((passEle32 && matchEle32_1 && filterEle32_1 && pt_1>33 && fabs(eta_1)<2.1) or (passEle35 && matchEle35_1 && filterEle35_1 && pt_1>33 && fabs(eta_1)<2.1));
	      //trigger2=(passEle24HPSTau30 && matchEle24HPSTau30_1 && filterEle24HPSTau30_1 && myele.Pt()>25 && myele.Pt()<33 && fabs(myele.Eta())<2.1 && ((fabs(mytauOS.Eta())<2.1 && mytauOS.Pt()>35) or (fabs(mytauSS.Eta())<2.1 && mytauSS.Pt()>35)));
              //if (sample=="data_obs" && run<317509) trigger2=(passEle24Tau30 && matchEle24Tau30_1 && filterEle24Tau30_1 && myele.Pt()>25 && myele.Pt()<26 && fabs(myele.Eta())<2.1 && ((fabs(mytauOS.Eta())<2.1 && mytauOS.Pt()>35) or (fabs(mytauSS.Eta())<2.1 && mytauSS.Pt()>35)));
            }
            //if (!trigger1 && !trigger2) continue;
            if (!trigger1) continue;


	    if (sample=="data_obs") {aweight=1.0; weight2=1.0;}

	    float fr=GetTauFR(mytauSS.Pt(),dm_SS,g_taufr_dm0VT,g_taufr_dm1VT,g_taufr_dm10VT,g_taufr_dm11VT,0);
            float fr1=GetTauFR(pt_3,l3_decayMode,g_taufr_dm0M,g_taufr_dm1M,g_taufr_dm10M,g_taufr_dm11M,0);
            float fr2=GetTauFR(pt_2,l2_decayMode,g_taufr_dm0M,g_taufr_dm1M,g_taufr_dm10M,g_taufr_dm11M,0);

	    if (k>28 && k<85){
	      fr=GetTauFR(mytauSS.Pt(),dm_SS,g_taufr_dm0VT,g_taufr_dm1VT,g_taufr_dm10VT,g_taufr_dm11VT,k-28);
              fr1=GetTauFR(pt_3,l3_decayMode,g_taufr_dm0M,g_taufr_dm1M,g_taufr_dm10M,g_taufr_dm11M,k-28);
              fr2=GetTauFR(pt_2,l2_decayMode,g_taufr_dm0M,g_taufr_dm1M,g_taufr_dm10M,g_taufr_dm11M,k-28);
	    }
            float wfr=fr/(1-fr);
            float wfr1=fr1/(1-fr1);
            float wfr2=fr2/(1-fr2);
	    if (trigger2 && matchEle24Tau30_2) wfr2=1.3*fr2/(1-1.3*fr2);
            else if (trigger2 && matchEle24Tau30_3) wfr1=1.3*fr1/(1-1.3*fr1);

            //bool selection = mytauOS.Pt()>20 && mytauSS.Pt()>30 && (myele.Pt()+mytauSS.Pt()+mytauOS.Pt())>120 && fabs(eta_2-eta_3)<2.0 and (mytauSS+mytauOS+myele+mymet).Pt()<80;
            bool selection = mytauSS.Pt()>30 && (myele.Pt()+mytauSS.Pt()+mytauOS.Pt())>130 and (mytauSS+mytauOS+myele+mymet).Pt()<70;
	    float var=(mytauSS+mytauOS).M();
            float factor=0.47;
            TLorentzVector metFromHiggs=(mytauSS+mytauOS)*factor;
            float ptv=(myele+mymet-metFromHiggs).Pt();
            var=(1.0+factor)*(mytauSS+mytauOS).M();
 	    float controlvar=ptv;

	    if (selection){
                if (signalRegion && q_2*q_3<0)
                    h0_OS[k]->Fill(ptv,var,weight2*aweight);
                if (signalRegion && q_2*q_3>0)
                    h0_SS[k]->Fill(controlvar,weight2*aweight);
	  	if (q_2*q_3<0 && aiRegion)
                    h0_AIOS[k]->Fill(ptv,var,weight2*aweight*wfr);
                if (q_2*q_3>0 && ai0Region)
                    h0_AISS[k]->Fill(controlvar,weight2*aweight*wfr1*wfr2*(-1));
                if (q_2*q_3>0 && ai1Region)
                    h0_AISS[k]->Fill(controlvar,weight2*aweight*wfr1);
                if (q_2*q_3>0 && ai2Region)
                    h0_AISS[k]->Fill(controlvar,weight2*aweight*wfr2);

	    }
            if (!selection){
                if (signalRegion && q_2*q_3<0)
                    h0_lowOS[k]->Fill(controlvar,weight2*aweight);
                if (q_2*q_3<0 && aiRegion)
                    h0_AIlowOS[k]->Fill(controlvar,weight2*aweight*wfr);
            }

	}
				
    } // end of loop over events


    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();

    TString postfix="";

    TDirectory *OS =fout->mkdir("ett");
    TDirectory *SS =fout->mkdir("ettSS");
    TDirectory *AIOS =fout->mkdir("AIOS");
    TDirectory *AISS =fout->mkdir("AISS");
    TDirectory *low =fout->mkdir("ettlow");
    TDirectory *AIlowOS =fout->mkdir("AIlowOS");

    for (int k=0; k<nbhist; ++k){

       if (k<29) postfix=postfixTES[k];
       if (k>=29) postfix=postfixFake[k-29];

       OS->cd();
       h0_OS[k]->SetName(name.c_str()+postfix);
       h0_OS[k]->Write();
       SS->cd();
       h0_SS[k]->SetName(name.c_str()+postfix);
       h0_SS[k]->Write();
       AIOS->cd();
       h0_AIOS[k]->SetName(name.c_str()+postfix);
       h0_AIOS[k]->Write();
       AISS->cd();
       h0_AISS[k]->SetName(name.c_str()+postfix);
       h0_AISS[k]->Write();
       low->cd();
       h0_lowOS[k]->SetName(name.c_str()+postfix);
       h0_lowOS[k]->Write();
       AIlowOS->cd();
       h0_AIlowOS[k]->SetName(name.c_str()+postfix);
       h0_AIlowOS[k]->Write();
    }
    fout->cd();
    fout->Close();

} 


