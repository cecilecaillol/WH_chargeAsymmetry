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
#include "TGraphAsymmErrors.h"
#include "TH1F.h"
#include "TKey.h"
#include "THashList.h"
#include "THStack.h"
#include "TPaveLabel.h"
#include "TFile.h"
#include "myHelper.h"
#include "tr_Tree.h"
#include "LumiReweightingStandAlone.h"
#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooFunctor.h"
#include "GetTauFR.h"

using namespace std;

int main(int argc, char** argv) {

    std::string input = *(argv + 1);
    std::string output = *(argv + 2);
    std::string sample = *(argv + 3);
    std::string name = *(argv + 4);
    std::string Wsign = *(argv + 5);

    int year=2016;
    if (argc > 1) {
        year = atof(argv[6]);
    }

    TFile *f_Double = new TFile(input.c_str());
    cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<endl;
    TTree *arbre = (TTree*) f_Double->Get("emt_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);

    TFile *f_taufr=new TFile("FitHistograms_tauFR_2016.root");
    if (year==2016) f_taufr=new TFile("FitHistograms_tauFR_2016.root");
    if (year==2017) f_taufr=new TFile("FitHistograms_tauFR_2017.root");
    if (year==2018) f_taufr=new TFile("FitHistograms_tauFR_2018.root");
    TGraphAsymmErrors *g_taufr_dm0T = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm0_Te_Tmu_deeptight_hpt_dm0_Te_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm1T = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm1_Te_Tmu_deeptight_hpt_dm1_Te_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm10T = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm10_Te_Tmu_deeptight_hpt_dm10_Te_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm11T = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm11_Te_Tmu_deeptight_hpt_dm11_Te_Tmu_deepveryveryveryloose");

    TFile *f_mufr=new TFile("FitHistograms_muFR_2016.root");
    if (year==2016) f_mufr=new TFile("FitHistograms_muFR_2016.root");
    if (year==2017) f_mufr=new TFile("FitHistograms_muFR_2017.root");
    if (year==2018) f_mufr=new TFile("FitHistograms_muFR_2018.root");
    TGraphAsymmErrors *g_mufr = (TGraphAsymmErrors*) f_mufr->Get("mufr_numerator_mufr_denominator");
    Double_t *mufr_y = g_mufr->GetY();
    Double_t *mufr_ylow = g_mufr->GetEYlow();
    Double_t *mufr_yhigh = g_mufr->GetEYhigh();

    TFile *f_mufr_sub09=new TFile("FitHistograms_muFR_2016_sub09.root");
    if (year==2016) f_mufr_sub09=new TFile("FitHistograms_muFR_2016_sub09.root");
    if (year==2017) f_mufr_sub09=new TFile("FitHistograms_muFR_2017_sub09.root");
    if (year==2018) f_mufr_sub09=new TFile("FitHistograms_muFR_2018_sub09.root");
    TGraphAsymmErrors *g_mufr_sub09 = (TGraphAsymmErrors*) f_mufr_sub09->Get("mufr_numerator_mufr_denominator");
    TFile *f_mufr_sub11=new TFile("FitHistograms_muFR_2016_sub11.root");
    if (year==2016) f_mufr_sub11=new TFile("FitHistograms_muFR_2016_sub11.root");
    if (year==2017) f_mufr_sub11=new TFile("FitHistograms_muFR_2017_sub11.root");
    if (year==2018) f_mufr_sub11=new TFile("FitHistograms_muFR_2018_sub11.root");
    TGraphAsymmErrors *g_mufr_sub11 = (TGraphAsymmErrors*) f_mufr_sub11->Get("mufr_numerator_mufr_denominator");

    TFile *f_efr=new TFile("FitHistograms_eleFR_2016.root");
    if (year==2016) f_efr=new TFile("FitHistograms_eleFR_2016.root");
    if (year==2017) f_efr=new TFile("FitHistograms_eleFR_2017.root");
    if (year==2018) f_efr=new TFile("FitHistograms_eleFR_2018.root");
    TGraphAsymmErrors *g_efr = (TGraphAsymmErrors*) f_efr->Get("efr_numerator_efr_denominator");
    Double_t *efr_y = g_efr->GetY();
    Double_t *efr_ylow = g_efr->GetEYlow();
    Double_t *efr_yhigh = g_efr->GetEYhigh();

    TFile *f_efr_sub09=new TFile("FitHistograms_eleFR_2016_sub09.root");
    if (year==2016) f_efr_sub09=new TFile("FitHistograms_eleFR_2016_sub09.root");
    if (year==2017) f_efr_sub09=new TFile("FitHistograms_eleFR_2017_sub09.root");
    if (year==2018) f_efr_sub09=new TFile("FitHistograms_eleFR_2018_sub09.root");
    TGraphAsymmErrors *g_efr_sub09 = (TGraphAsymmErrors*) f_efr_sub09->Get("efr_numerator_efr_denominator");
    TFile *f_efr_sub11=new TFile("FitHistograms_eleFR_2016_sub11.root");
    if (year==2016) f_efr_sub11=new TFile("FitHistograms_eleFR_2016_sub11.root");
    if (year==2017) f_efr_sub11=new TFile("FitHistograms_eleFR_2017_sub11.root");
    if (year==2018) f_efr_sub11=new TFile("FitHistograms_eleFR_2018_sub11.root");
    TGraphAsymmErrors *g_efr_sub11 = (TGraphAsymmErrors*) f_efr_sub11->Get("efr_numerator_efr_denominator");

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
    else if (name=="data_obs"){weight=1.0;}
    else if (sample=="WZ1L1Nu2Q") {xs=10.71; weight=luminosity*xs/ngen;}
    else if (sample=="WZ1L3Nu") {xs=3.05; weight=luminosity*xs/ngen;}
    else if (sample=="WZJets") {xs=5.26; weight=luminosity*xs/ngen;}
    else if (sample=="WZLLLNu") {xs=4.708; weight=luminosity*xs/ngen;}
    else if (sample=="WZ2L2Q") {xs=5.595; weight=luminosity*xs/ngen;}
    else if (sample=="WW1L1Nu2Q") {xs=49.997; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ4L") {xs=1.256*1.1; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ2L2Q") {xs=3.22; weight=luminosity*xs/ngen;}
    else if (sample=="VV2L2Nu") {xs=11.95; weight=luminosity*xs/ngen;}
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
    else if (sample=="ttHnonBB") {xs=0.5033*(1-0.5760); weight=luminosity*xs/ngen;}//FIXME
    else cout<<"Attention!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    arbre->SetBranchAddress("Rivet_higgsPt", &Rivet_higgsPt);
    arbre->SetBranchAddress("Rivet_VPt", &Rivet_VPt);
    arbre->SetBranchAddress("Rivet_nJets30", &Rivet_nJets30);
    arbre->SetBranchAddress("Rivet_stage1_1_fine_cat_pTjet30GeV", & Rivet_stage1_1_fine_cat_pTjet30GeV);
    arbre->SetBranchAddress("Rivet_stage1_1_cat_pTjet30GeV", & Rivet_stage1_1_cat_pTjet30GeV);
    arbre->SetBranchAddress("Rivet_stage1_cat_pTjet30GeV", & Rivet_stage1_cat_pTjet30GeV);
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
    arbre->SetBranchAddress("iso_2", &iso_2);
    arbre->SetBranchAddress("id_m_medium_2", &id_m_medium_2);
    arbre->SetBranchAddress("m_2", &m_2);
    arbre->SetBranchAddress("phi_2", &phi_2);
    arbre->SetBranchAddress("q_3", &q_3);
    arbre->SetBranchAddress("pt_3", &pt_3);
    arbre->SetBranchAddress("eta_3", &eta_3);
    arbre->SetBranchAddress("m_3", &m_3);
    arbre->SetBranchAddress("iso_3", &iso_3);
    arbre->SetBranchAddress("phi_3", &phi_3);

    arbre->SetBranchAddress("PythiaWeight_isr_muR2", &PythiaWeight_isr_muR2);
    arbre->SetBranchAddress("PythiaWeight_isr_muR0p5", &PythiaWeight_isr_muR0p5);
    arbre->SetBranchAddress("PythiaWeight_fsr_muR2", &PythiaWeight_fsr_muR2);
    arbre->SetBranchAddress("PythiaWeight_fsr_muR0p5", &PythiaWeight_fsr_muR0p5);
    arbre->SetBranchAddress("lheweight_muR0p5_muF0p5", &lheweight_muR0p5_muF0p5);
    arbre->SetBranchAddress("lheweight_muR2_muF2", &lheweight_muR2_muF2);
    arbre->SetBranchAddress("lheweight_nominal", &lheweight_nominal);

    arbre->SetBranchAddress("passMu22eta2p1", &passMu22eta2p1);
    arbre->SetBranchAddress("passTkMu22eta2p1", &passTkMu22eta2p1);
    arbre->SetBranchAddress("matchMu22eta2p1_2", &matchMu22eta2p1_2);
    arbre->SetBranchAddress("matchTkMu22eta2p1_2", &matchTkMu22eta2p1_2);
    arbre->SetBranchAddress("filterMu22eta2p1_2", &filterMu22eta2p1_2);
    arbre->SetBranchAddress("filterTkMu22eta2p1_2", &filterTkMu22eta2p1_2);
    arbre->SetBranchAddress("passMu22", &passMu22);
    arbre->SetBranchAddress("passTkMu22", &passTkMu22);
    arbre->SetBranchAddress("matchMu22_2", &matchMu22_2);
    arbre->SetBranchAddress("matchTkMu22_2", &matchTkMu22_2);
    arbre->SetBranchAddress("filterMu22_2", &filterMu22_2);
    arbre->SetBranchAddress("filterTkMu22_2", &filterTkMu22_2);
    arbre->SetBranchAddress("passMu24", &passMu24);
    arbre->SetBranchAddress("matchMu24_2", &matchMu24_2);
    arbre->SetBranchAddress("filterMu24_2", &filterMu24_2);
    arbre->SetBranchAddress("passMu27", &passMu27);
    arbre->SetBranchAddress("matchMu27_2", &matchMu27_2);
    arbre->SetBranchAddress("filterMu27_2", &filterMu27_2);
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
    arbre->SetBranchAddress("passMu19Tau20SingleL1", &passMu19Tau20SingleL1);
    arbre->SetBranchAddress("passMu19Tau20", &passMu19Tau20);
    arbre->SetBranchAddress("matchMu19Tau20_2", &matchMu19Tau20_2);
    arbre->SetBranchAddress("matchMu19Tau20_3", &matchMu19Tau20_3);
    arbre->SetBranchAddress("matchMu19Tau20SingleL1_2", &matchMu19Tau20SingleL1_2);
    arbre->SetBranchAddress("matchMu19Tau20SingleL1_3", &matchMu19Tau20SingleL1_3);
    arbre->SetBranchAddress("filterMu19Tau20_2", &filterMu19Tau20_2);
    arbre->SetBranchAddress("filterMu19Tau20_3", &filterMu19Tau20_3);
    arbre->SetBranchAddress("filterMu19Tau20SingleL1_3", &filterMu19Tau20SingleL1_3);
    arbre->SetBranchAddress("filterMu19Tau20SingleL1_2", &filterMu19Tau20SingleL1_2);
    arbre->SetBranchAddress("passMu20Tau27", &passMu20Tau27);
    arbre->SetBranchAddress("matchMu20Tau27_2", &matchMu20Tau27_2);
    arbre->SetBranchAddress("filterMu20Tau27_2", &filterMu20Tau27_2);
    arbre->SetBranchAddress("matchMu20Tau27_3", &matchMu20Tau27_3);
    arbre->SetBranchAddress("filterMu20Tau27_3", &filterMu20Tau27_3);
    arbre->SetBranchAddress("passMu20HPSTau27", &passMu20HPSTau27);
    arbre->SetBranchAddress("matchMu20HPSTau27_2", &matchMu20HPSTau27_2);
    arbre->SetBranchAddress("filterMu20HPSTau27_2", &filterMu20HPSTau27_2);
    arbre->SetBranchAddress("matchMu20HPSTau27_3", &matchMu20HPSTau27_3);
    arbre->SetBranchAddress("filterMu20HPSTau27_3", &filterMu20HPSTau27_3);


    arbre->SetBranchAddress("prefiring_weight", &prefiring_weight);
    arbre->SetBranchAddress("prefiring_weight_up", &prefiring_weight_up);
    arbre->SetBranchAddress("prefiring_weight_down", &prefiring_weight_down);
    arbre->SetBranchAddress("pt_1_ScaleDown", &pt_1_ScaleDown);
    arbre->SetBranchAddress("pt_1_ScaleUp", &pt_1_ScaleUp);
    arbre->SetBranchAddress("bweight", &bweight);

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
    arbre->SetBranchAddress("deepVLooseVSmu_3",&deepVLooseVSmu_3);
    arbre->SetBranchAddress("deepLooseVSmu_3",&deepLooseVSmu_3);
    arbre->SetBranchAddress("deepMediumVSmu_3",&deepMediumVSmu_3);
    arbre->SetBranchAddress("deepTightVSmu_3",&deepTightVSmu_3);
    arbre->SetBranchAddress("deepVTightVSmu_3",&deepVTightVSmu_3);

    arbre->SetBranchAddress("met", &met);
    arbre->SetBranchAddress("metphi", &metphi);
    arbre->SetBranchAddress("njets", &njets);
    arbre->SetBranchAddress("nbtag", &nbtag);
    arbre->SetBranchAddress("jpt_1", &jpt_1);
    arbre->SetBranchAddress("aMCatNLO_weight", &aMCatNLO_weight);
    arbre->SetBranchAddress("metphi_JESDown", &metphi_JESDown);
    arbre->SetBranchAddress("metphi_JESUp", &metphi_JESUp);
    arbre->SetBranchAddress("met_JESDown", &met_JESDown);
    arbre->SetBranchAddress("met_JESUp", &met_JESUp);
    arbre->SetBranchAddress("metphi_UESDown", &metphi_UESDown);
    arbre->SetBranchAddress("metphi_UESUp", &metphi_UESUp);
    arbre->SetBranchAddress("met_UESDown", &met_UESDown);
    arbre->SetBranchAddress("met_UESUp", &met_UESUp);
    arbre->SetBranchAddress("njets_JESDown", &njets_JESDown);
    arbre->SetBranchAddress("njets_JESUp", &njets_JESUp);

    arbre->SetBranchAddress("l3_decayMode",&l3_decayMode);
    arbre->SetBranchAddress("gen_match_1",&gen_match_1);
    arbre->SetBranchAddress("gen_match_2",&gen_match_2);
    arbre->SetBranchAddress("gen_match_3",&gen_match_3);
    arbre->SetBranchAddress("npu",&npu);
    arbre->SetBranchAddress("genpT",&genpT);
    arbre->SetBranchAddress("genM",&genM);
    arbre->SetBranchAddress("pt_top1",&pt_top1);
    arbre->SetBranchAddress("pt_top2",&pt_top2);
    arbre->SetBranchAddress("numGenJets",&numGenJets);
    arbre->SetBranchAddress("bpt_1",&bpt_1);
    arbre->SetBranchAddress("bpt_2",&bpt_2);
    arbre->SetBranchAddress("bflavor_1",&bflavor_1);
    arbre->SetBranchAddress("bflavor_2",&bflavor_2);

   /*float bins0[] = {0,25,50,75,100,150,200,250};
   float binsLow[] = {0,25,50,75,100,150,200,250};
   float binsHigh[] = {0,25,50,75,100,150,200};
   float bins1[] = {0,25,50,75,100,150,200,250};*/

   /*float bins0[] = {20,30,40,50,60,70,80,90,100,110,120,130,140};
   float binsLow[] = {20,30,40,50,60,70,80,90,100,110,120,130,140};
   float binsHigh[] = {20,30,40,50,60,70,80,90,100,110,120,130,140};
   float bins1[] = {20,30,40,50,60,70,80,90,100,110,120,130,140};*/

   /*float bins0[] = {0,25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,450};
   float binsLow[] = {0,25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,450};
   float binsHigh[] = {0,25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,450};
   float bins1[] = {0,25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,450};

   int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
   int  binnumLow = sizeof(binsLow)/sizeof(Float_t) - 1;
   int  binnumHigh = sizeof(binsHigh)/sizeof(Float_t) - 1;
   int  binnum1 = sizeof(bins1)/sizeof(Float_t) - 1;*/

   float bins[] = {0,50,70,90,110,130,150,170,290};
   int  binnum = sizeof(bins)/sizeof(Float_t) - 1;
   float binsPTV[] ={0,75,150,1000};
   int  binnumPTV = sizeof(binsPTV)/sizeof(Float_t) - 1;

   std::vector<TH2F*> h0_OS;
   std::vector<TH2F*> h0_SS;
   std::vector<TH2F*> h0_AIOS;
   std::vector<TH2F*> h0_AISS;
   std::vector<TH2F*> h0_AI0OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH2F*> h0_AI0SS; //Region with same-sign anti-isolated taus
   std::vector<TH2F*> h0_AI1OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH2F*> h0_AI1SS; //Region with same-sign anti-isolated taus
   std::vector<TH2F*> h0_AI2OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH2F*> h0_AI2SS; //Region with same-sign anti-isolated taus

   std::vector<TH1F*> h1_OS;
   std::vector<TH1F*> h1_SS;
   std::vector<TH1F*> h1_AIOS;
   std::vector<TH1F*> h1_AISS;
   std::vector<TH1F*> h1_AI0OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h1_AI0SS; //Region with same-sign anti-isolated taus
   std::vector<TH1F*> h1_AI1OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h1_AI1SS; //Region with same-sign anti-isolated taus
   std::vector<TH1F*> h1_AI2OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h1_AI2SS; //Region with same-sign anti-isolated taus

   TH1F* h_deta=new TH1F("h_deta","h_deta",20,0,5);
   TH1F* h_dphi=new TH1F("h_dphi","h_dphi",20,0,3.1415);
   TH1F* h_lt=new TH1F("h_lt","h_lt",15,0,300);

   int nbhist=1+34+56+20+4;

   for (int k=0; k<nbhist; ++k){
        ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
        h0_OS.push_back(new TH2F (HNS0OS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_OS[k]->Sumw2();

        ostringstream HNS0SS; HNS0OS << "h0_SS" << k;
        h0_SS.push_back(new TH2F (HNS0SS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_SS[k]->Sumw2();

        ostringstream HNS0AIOS; HNS0AIOS << "h0_AIOS" << k;
        h0_AIOS.push_back(new TH2F (HNS0AIOS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AIOS[k]->Sumw2();

        ostringstream HNS0AISS; HNS0AISS << "h0_AISS" << k;
        h0_AISS.push_back(new TH2F (HNS0AISS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AISS[k]->Sumw2();

        ostringstream HNS0AI0OS; HNS0AI0OS << "h0_AI0OS" << k;
        h0_AI0OS.push_back(new TH2F (HNS0AI0OS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AI0OS[k]->Sumw2();

        ostringstream HNS0AI0SS; HNS0AI0SS << "h0_AI0SS" << k;
        h0_AI0SS.push_back(new TH2F (HNS0AI0SS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AI0SS[k]->Sumw2();

        ostringstream HNS0AI1OS; HNS0AI1OS << "h0_AI1OS" << k;
        h0_AI1OS.push_back(new TH2F (HNS0AI1OS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AI1OS[k]->Sumw2();

        ostringstream HNS0AI1SS; HNS0AI1SS << "h0_AI1SS" << k;
        h0_AI1SS.push_back(new TH2F (HNS0AI1SS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AI1SS[k]->Sumw2();

        ostringstream HNS0AI2OS; HNS0AI2OS << "h0_AI2OS" << k;
        h0_AI2OS.push_back(new TH2F (HNS0AI2OS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AI2OS[k]->Sumw2();

        ostringstream HNS0AI2SS; HNS0AI2SS << "h0_AI2SS" << k;
        h0_AI2SS.push_back(new TH2F (HNS0AI2SS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AI2SS[k]->Sumw2();

        ostringstream HNS1OS; HNS1OS << "h1_OS" << k;
        h1_OS.push_back(new TH1F (HNS1OS.str().c_str(),"InvMa",20,0,200)); h1_OS[k]->Sumw2();

        ostringstream HNS1SS; HNS1OS << "h1_SS" << k;
        h1_SS.push_back(new TH1F (HNS1SS.str().c_str(),"InvMa",20,0,200)); h1_SS[k]->Sumw2();

        ostringstream HNS1AIOS; HNS1AIOS << "h1_AIOS" << k;
        h1_AIOS.push_back(new TH1F (HNS1AIOS.str().c_str(),"InvMa",20,0,200)); h1_AIOS[k]->Sumw2();

        ostringstream HNS1AISS; HNS1AISS << "h1_AISS" << k;
        h1_AISS.push_back(new TH1F (HNS1AISS.str().c_str(),"InvMa",20,0,200)); h1_AISS[k]->Sumw2();

        ostringstream HNS1AI0OS; HNS1AI0OS << "h1_AI0OS" << k;
        h1_AI0OS.push_back(new TH1F (HNS1AI0OS.str().c_str(),"InvMa",20,0,200)); h1_AI0OS[k]->Sumw2();

        ostringstream HNS1AI0SS; HNS1AI0SS << "h1_AI0SS" << k;
        h1_AI0SS.push_back(new TH1F (HNS1AI0SS.str().c_str(),"InvMa",20,0,200)); h1_AI0SS[k]->Sumw2();

        ostringstream HNS1AI1OS; HNS1AI1OS << "h1_AI1OS" << k;
        h1_AI1OS.push_back(new TH1F (HNS1AI1OS.str().c_str(),"InvMa",20,0,200)); h1_AI1OS[k]->Sumw2();

        ostringstream HNS1AI1SS; HNS1AI1SS << "h1_AI1SS" << k;
        h1_AI1SS.push_back(new TH1F (HNS1AI1SS.str().c_str(),"InvMa",20,0,200)); h1_AI1SS[k]->Sumw2();

        ostringstream HNS1AI2OS; HNS1AI2OS << "h1_AI2OS" << k;
        h1_AI2OS.push_back(new TH1F (HNS1AI2OS.str().c_str(),"InvMa",20,0,200)); h1_AI2OS[k]->Sumw2();

        ostringstream HNS1AI2SS; HNS1AI2SS << "h1_AI2SS" << k;
        h1_AI2SS.push_back(new TH1F (HNS1AI2SS.str().c_str(),"InvMa",20,0,200)); h1_AI2SS[k]->Sumw2();
   }


   TString postfixTES[35]={"","_CMS_scale_t_1prong_2017Down","_CMS_scale_t_1prong_2017Up","_CMS_scale_t_1prong1pizero_2017Down","_CMS_scale_t_1prong1pizero_2017Up","_CMS_scale_t_3prong_2017Down","_CMS_scale_t_3prong_2017Up","_CMS_scale_t_3prong1pizero_2017Down","_CMS_scale_t_3prong1pizero_2017Up","_CMS_tauideff_pt20to25_2017Down","_CMS_tauideff_pt20to25_2017Up","_CMS_tauideff_pt25to30_2017Down","_CMS_tauideff_pt25to30_2017Up","_CMS_tauideff_pt30to35_2017Down","_CMS_tauideff_pt30to35_2017Up","_CMS_tauideff_pt35to40_2017Down","_CMS_tauideff_pt35to40_2017Up","_CMS_tauideff_ptgt40_2017Down","_CMS_tauideff_ptgt40_2017Up","_CMS_scale_met_unclustered_2017Down","_CMS_scale_met_unclustered_2017Up","_CMS_scale_e_2017Down","_CMS_scale_e_2017Up","_CMS_scale_m_etalt1p2_2017Down","_CMS_scale_m_etalt1p2_2017Up","_CMS_scale_m_eta1p2to2p1_2017Down","_CMS_scale_m_eta1p2to2p1_2017Up","_CMS_scale_m_etagt2p1_2017Down","_CMS_scale_m_etagt2p1_2017Up","_CMS_prefiringDown","_CMS_prefiringUp","_FIXMEDown","_FIXMEUp","_qqVH_NLOEWKDown","_qqVH_NLOEWKUp"};

   TString postfixFake[80]={"_CMS_fakeTauVT_Te_dm0_pt20to25_2017Up","_CMS_fakeTauVT_Te_dm0_pt20to25_2017Down","_CMS_fakeTauVT_Te_dm0_pt25to30_2017Up","_CMS_fakeTauVT_Te_dm0_pt25to30_2017Down","_CMS_fakeTauVT_Te_dm0_pt30to35_2017Up","_CMS_fakeTauVT_Te_dm0_pt30to35_2017Down","_CMS_fakeTauVT_Te_dm0_pt35to40_2017Up","_CMS_fakeTauVT_Te_dm0_pt35to40_2017Down","_CMS_fakeTauVT_Te_dm0_pt40to50_2017Up","_CMS_fakeTauVT_Te_dm0_pt40to50_2017Down","_CMS_fakeTauVT_Te_dm0_pt50to60_2017Up","_CMS_fakeTauVT_Te_dm0_pt50to60_2017Down","_CMS_fakeTauVT_Te_dm0_ptgt60_2017Up","_CMS_fakeTauVT_Te_dm0_ptgt60_2017Down","_CMS_fakeTauVT_Te_dm1_pt20to25_2017Up","_CMS_fakeTauVT_Te_dm1_pt20to25_2017Down","_CMS_fakeTauVT_Te_dm1_pt25to30_2017Up","_CMS_fakeTauVT_Te_dm1_pt25to30_2017Down","_CMS_fakeTauVT_Te_dm1_pt30to35_2017Up","_CMS_fakeTauVT_Te_dm1_pt30to35_2017Down","_CMS_fakeTauVT_Te_dm1_pt35to40_2017Up","_CMS_fakeTauVT_Te_dm1_pt35to40_2017Down","_CMS_fakeTauVT_Te_dm1_pt40to50_2017Up","_CMS_fakeTauVT_Te_dm1_pt40to50_2017Down","_CMS_fakeTauVT_Te_dm1_pt50to60_2017Up","_CMS_fakeTauVT_Te_dm1_pt50to60_2017Down","_CMS_fakeTauVT_Te_dm1_ptgt60_2017Up","_CMS_fakeTauVT_Te_dm1_ptgt60_2017Down","_CMS_fakeTauVT_Te_dm10_pt20to25_2017Up","_CMS_fakeTauVT_Te_dm10_pt20to25_2017Down","_CMS_fakeTauVT_Te_dm10_pt25to30_2017Up","_CMS_fakeTauVT_Te_dm10_pt25to30_2017Down","_CMS_fakeTauVT_Te_dm10_pt30to35_2017Up","_CMS_fakeTauVT_Te_dm10_pt30to35_2017Down","_CMS_fakeTauVT_Te_dm10_pt35to40_2017Up","_CMS_fakeTauVT_Te_dm10_pt35to40_2017Down","_CMS_fakeTauVT_Te_dm10_pt40to50_2017Up","_CMS_fakeTauVT_Te_dm10_pt40to50_2017Down","_CMS_fakeTauVT_Te_dm10_pt50to60_2017Up","_CMS_fakeTauVT_Te_dm10_pt50to60_2017Down","_CMS_fakeTauVT_Te_dm10_ptgt60_2017Up","_CMS_fakeTauVT_Te_dm10_ptgt60_2017Down","_CMS_fakeTauVT_Te_dm11_pt20to25_2017Up","_CMS_fakeTauVT_Te_dm11_pt20to25_2017Down","_CMS_fakeTauVT_Te_dm11_pt25to30_2017Up","_CMS_fakeTauVT_Te_dm11_pt25to30_2017Down","_CMS_fakeTauVT_Te_dm11_pt30to35_2017Up","_CMS_fakeTauVT_Te_dm11_pt30to35_2017Down","_CMS_fakeTauVT_Te_dm11_pt35to40_2017Up","_CMS_fakeTauVT_Te_dm11_pt35to40_2017Down","_CMS_fakeTauVT_Te_dm11_pt40to50_2017Up","_CMS_fakeTauVT_Te_dm11_pt40to50_2017Down","_CMS_fakeTauVT_Te_dm11_pt50to60_2017Up","_CMS_fakeTauVT_Te_dm11_pt50to60_2017Down","_CMS_fakeTauVT_Te_dm11_ptgt60_2017Up","_CMS_fakeTauVT_Te_dm11_ptgt60_2017Down","_CMS_fakeEle_pt10to15_2017Up","_CMS_fakeEle_pt10to15_2017Down","_CMS_fakeEle_pt15to20_2017Up","_CMS_fakeEle_pt15to20_2017Down","_CMS_fakeEle_pt20to30_2017Up","_CMS_fakeEle_pt20to30_2017Down","_CMS_fakeEle_pt30to40_2017Up","_CMS_fakeEle_pt30to40_2017Down","_CMS_fakeEle_ptgt40_2017Up","_CMS_fakeEle_ptgt40_2017Down","_CMS_fakeMu_pt10to15_2017Up","_CMS_fakeMu_pt10to15_2017Down","_CMS_fakeMu_pt15to20_2017Up","_CMS_fakeMu_pt15to20_2017Down","_CMS_fakeMu_pt20to30_2017Up","_CMS_fakeMu_pt20to30_2017Down","_CMS_fakeMu_pt30to40_2017Up","_CMS_fakeMu_pt30to40_2017Down","_CMS_fakeMu_ptgt40_2017Up","_CMS_fakeMu_ptgt40_2017Down","_CMS_fakeEle_promptSubtraction_2017Down","_CMS_fakeEle_promptSubtraction_2017Up","_CMS_fakeMu_promptSubtraction_2017Down","_CMS_fakeMu_promptSubtraction_2017Up"};

   for (int k = 0; k < 80; ++k){
      if (year==2016) postfixFake[k]=postfixFake[k].ReplaceAll("2017",4,"2016",4);
      if (year==2018) postfixFake[k]=postfixFake[k].ReplaceAll("2017",4,"2018",4);
   }
   for (int k = 0; k < 31; ++k){
      if (year==2016) postfixTES[k]=postfixTES[k].ReplaceAll("2017",4,"2016",4);
      if (year==2018) postfixTES[k]=postfixTES[k].ReplaceAll("2017",4,"2018",4);
   }

   TFile *ftauid = new TFile("TauID_SF_pt_DeepTau2017v2p1VSjet_2016Legacy.root");
   if (year==2017) ftauid = new TFile("TauID_SF_pt_DeepTau2017v2p1VSjet_2017ReReco.root");
   if (year==2018) ftauid = new TFile("TauID_SF_pt_DeepTau2017v2p1VSjet_2018ReReco.root");
   TF1 *fct_tauid= (TF1*) ftauid->Get("Tight_cent");
   TF1 *fct_tauid_up= (TF1*) ftauid->Get("Tight_up");
   TF1 *fct_tauid_down= (TF1*) ftauid->Get("Tight_down"); //FIXME
   /*TF1 *fct_tauid= (TF1*) ftauid->Get("Medium_cent");
   TF1 *fct_tauid_up= (TF1*) ftauid->Get("Medium_up");
   TF1 *fct_tauid_down= (TF1*) ftauid->Get("Medium_down");*/

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
      if (name=="WH_lep_htt125" or name=="WH_lep_hww125") {lheweight_nominalTo2_average= h_QCDScaleAcceptance_WH_lep->GetBinContent(1)/h_QCDScaleAcceptance_WH_lep->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_WH_lep->GetBinContent(1)/h_QCDScaleAcceptance_WH_lep->GetBinContent(9); postfixTES[31]="_WHlep_scaleDown"; postfixTES[32]="_WHlep_scaleUp";}
      if (name=="ggZH_lep_htt125" or name=="ZH_lep_htt125" or name=="ggZH_lep_hww125" or name=="ZH_lep_hww125") {lheweight_nominalTo2_average= h_QCDScaleAcceptance_ZH_lep->GetBinContent(1)/h_QCDScaleAcceptance_ZH_lep->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_ZH_lep->GetBinContent(1)/h_QCDScaleAcceptance_ZH_lep->GetBinContent(9); postfixTES[31]="_ZHlep_scaleDown"; postfixTES[32]="_ZHlep_scaleUp";}
      if (name.find("WH_lep_PTV_0_75_h") < 140 or name.find("WH_lep_PTV_75_150_h") < 140 or name.find("WH_lep_PTV_150_250_0J_h") < 140 or name.find("WH_lep_PTV_150_250_GE1J_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(9); postfixTES[31]="_WH_scale_lowptDown"; postfixTES[32]="_WH_scale_lowptUp";}
      if (name.find("WH_lep_PTV_GT250_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(9); postfixTES[31]="_WH_scale_highptDown"; postfixTES[32]="_WH_scale_highptUp";}
      if (name.find("ZH_lep_PTV_0_75_h") < 140 or name.find("ZH_lep_PTV_75_150_h") < 140 or name.find("ZH_lep_PTV_150_250_0J_h") < 140 or name.find("ZH_lep_PTV_150_250_GE1J_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(9); postfixTES[31]="_ZH_scale_lowptDown"; postfixTES[32]="_ZH_scale_lowptUp";}
      if (name.find("ZH_lep_PTV_GT250_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(9); postfixTES[31]="_ZH_scale_highptDown"; postfixTES[32]="_ZH_scale_highptUp";}
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
lheweight_nominal=1.0;//

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


        if (Flag_goodVertices) continue;
        if (Flag_globalSuperTightHalo2016Filter) continue;
        if (Flag_HBHENoiseFilter) continue;
        if (Flag_HBHENoiseIsoFilter) continue;
        if (Flag_EcalDeadCellTriggerPrimitiveFilter) continue;
        if (Flag_BadPFMuonFilter) continue;
        if ((sample=="data_obs" or sample=="embedded") && Flag_eeBadScFilter) continue;
        if ((year==2017 or year==2018) && Flag_ecalBadCalibReducedMINIAODFilter) continue;

	if (pt_1<10 or pt_2<10 or pt_3<19.5) continue;
	if (fabs(eta_1)>2.5 or fabs(eta_2)>2.4 or fabs(eta_3)>2.3) continue;

        bool trigger1=true;
        bool trigger2=true;
        if (year==2016){
           trigger1=(passEle25 && matchEle25_1 && filterEle25_1 && pt_1>25.5 && fabs(eta_1)<2.1 && pt_2<23.5);
           trigger2=((passMu22eta2p1 && matchMu22eta2p1_2 && filterMu22eta2p1_2 && pt_2>22.5 && fabs(eta_2)<2.1) or (passTkMu22eta2p1 && matchTkMu22eta2p1_2 && filterTkMu22eta2p1_2 && pt_2>22.5 && fabs(eta_2)<2.1) or (passMu22 && matchMu22_2 && filterMu22_2 && pt_2>22.5 && fabs(eta_2)<2.1) or (passTkMu22 && matchTkMu22_2 && filterTkMu22_2 && pt_2>22.5 && fabs(eta_2)<2.1));
        }
        if (year==2017){
           trigger1=((passEle27 && matchEle27_1 && filterEle27_1 && pt_1>27.5 && fabs(eta_1)<2.1 && pt_2<25.5) or (passEle32 && matchEle32_1 && filterEle32_1 && pt_1>27.5 && fabs(eta_1)<2.1 && pt_2<25.5));
           trigger2=((passMu24 && matchMu24_2 && filterMu24_2 && pt_2>24.5 && fabs(eta_2)<2.1) or (passMu27 && matchMu27_2 && filterMu27_2 && pt_2>24.5 && fabs(eta_2)<2.1));
        }
        if (year==2018){
           trigger1=((passEle32 && matchEle32_1 && filterEle32_1 && pt_1>32.5 && fabs(eta_1)<2.1 && pt_2<25.5) or (passEle35 && matchEle35_1 && filterEle35_1 && pt_1>32.5 && fabs(eta_1)<2.1 && pt_2<25.5));
           trigger2=((passMu24 && matchMu24_2 && filterMu24_2 && pt_2>24.5 && fabs(eta_2)<2.1) or (passMu27 && matchMu27_2 && filterMu27_2 && pt_2>24.5 && fabs(eta_2)<2.1));
        }
	if (sample=="SingleElectron" && trigger2) continue;
        if (sample=="SingleMuon" && !trigger2) continue;
        if (!trigger1 && !trigger2) continue;

	bool eleID=eid90noiso_1 && iso_1<0.15;
	bool muonID=true;
	if (!id_m_medium_2) muonID=false;
        if (iso_2>0.15) muonID=false;

	if (name!="data_obs" and gen_match_3==6) continue;
	if ((name=="DY" or name=="TT" or name=="W") and gen_match_1!=6 and gen_match_2!=6 and gen_match_3!=6) continue;//
	if ((name=="DY" or name=="TT" or name=="W") and !(trigger2 and gen_match_2==6 and gen_match_1!=6 and gen_match_3!=6)) continue;
        if ((name=="DY" or name=="TT" or name=="W") and !(!trigger2 and gen_match_1==6 and gen_match_2!=6 and gen_match_3!=6)) continue;

        TLorentzVector myele;
        myele.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);
        TLorentzVector mymu;
        mymu.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
        TLorentzVector mytau;
        mytau.SetPtEtaPhiM(pt_3,eta_3,phi_3,m_3);

	if (Wsign=="plus" and !((myele.Pt()>mymu.Pt() && q_1>0) or (mymu.Pt()>myele.Pt() && q_2>0))) continue;
        if (Wsign=="minus" and !((myele.Pt()>mymu.Pt() && q_1<0) or (mymu.Pt()>myele.Pt() && q_2<0))) continue;

	bool eleT=true;

	// B jet veto (different technique for data and MC to apply good scale factors)
        if (nbtag>0) continue; // For data just remove events with a btag

        if (!deepTightVSe_3 or !deepTightVSmu_3) continue;

	bool is_vsjet=deepTightVSjet_3;//FIXME
        float signalRegion=eleID && muonID && is_vsjet && deepVVVLooseVSjet_3;
        float aiRegion=eleID && muonID &&  !is_vsjet && deepVVVLooseVSjet_3;
        float ai1Region=((!(trigger2) && eleID && !muonID) or ((trigger2) && !eleID && muonID)) && is_vsjet && deepVVVLooseVSjet_3; 
        float ai2Region=eleID && muonID && !is_vsjet && deepVVVLooseVSjet_3; 
        float ai0Region=((!(trigger2) && eleID && !muonID) or ((trigger2) && !eleID && muonID)) && is_vsjet && deepVVVLooseVSjet_3;

	//***************** Weights **************

	// stitch W samples split by jet multiplicity
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
          if (is_vsjet && gen_match_3==5) aweight=aweight*fct_tauid->Eval(mytau.Pt());
          if (gen_match_3==1 or gen_match_3==3){ // Medium VSe
             if (fabs(mytau.Eta())<1.448) aweight=aweight*1.44;
             else if (fabs(mytau.Eta())>1.558) aweight=aweight*1.08;
          }
          if (gen_match_3==2 or gen_match_3==4){ // Medium VSmu
             if (fabs(mytau.Eta())<0.4) aweight=aweight*0.978*1.442;
             else if (fabs(mytau.Eta())<0.8) aweight=aweight*1.003*0.941;
             else if (fabs(mytau.Eta())<1.2) aweight=aweight*0.992*1.288;
             else if (fabs(mytau.Eta())<1.7) aweight=aweight*1.003*1.054;
             else aweight=aweight*0.966*5.341;
          }
          wmc->var("e_pt")->setVal(myele.Pt());
          wmc->var("e_eta")->setVal(myele.Eta());
          wmc->var("e_iso")->setVal(iso_1);
          aweight=aweight*wmc->function("e_trk_ratio")->getVal();
          aweight=aweight*wmc->function("e_idiso_ic_ratio")->getVal();
          float sftrg1=wmc->function("e_trg_ic_ratio")->getVal();
          wmc->var("m_pt")->setVal(mymu.Pt());
          wmc->var("m_eta")->setVal(mymu.Eta());
          wmc->var("m_iso")->setVal(iso_2);
          aweight=aweight*wmc->function("m_trk_ratio")->getVal();
          aweight=aweight*wmc->function("m_idiso_ic_ratio")->getVal();
          float sftrg2=wmc->function("m_trg_ic_ratio")->getVal();
          if (trigger1 && !trigger2) aweight=aweight*sftrg1;
          if (!trigger1 && trigger2) aweight=aweight*sftrg2;
          aweight=aweight*prefiring_weight;
          aweight=aweight*bweight;
        }
        if (year==2017 and sample!="data_obs"){
          aweight=aweight*aMCatNLO_weight*weight*LumiWeights_12->weight(npu);
          if (is_vsjet && gen_match_3==5) aweight=aweight*fct_tauid->Eval(mytau.Pt());
          if (gen_match_3==1 or gen_match_3==3){ // Medium VSe
             if (fabs(mytau.Eta())<1.460) aweight=aweight*1.18;
             else if (fabs(mytau.Eta())>1.558) aweight=aweight*0.86;
          }
          if (gen_match_3==2 or gen_match_3==4){ // Medium VSmu
             if (fabs(mytau.Eta())<0.4) aweight=aweight*0.979*1.062;
             else if (fabs(mytau.Eta())<0.8) aweight=aweight*0.953*0.819;
             else if (fabs(mytau.Eta())<1.2) aweight=aweight*0.983*0.819;
             else if (fabs(mytau.Eta())<1.7) aweight=aweight*0.988*1.021;
             else aweight=aweight*1.004*4.235;
          }
          wmc->var("e_pt")->setVal(myele.Pt());
          wmc->var("e_eta")->setVal(myele.Eta());
          wmc->var("e_iso")->setVal(iso_1);
          aweight=aweight*wmc->function("e_trk_ratio")->getVal();
          aweight=aweight*wmc->function("e_idiso_ic_ratio")->getVal();
          float sftrg1=wmc->function("e_trg_ic_ratio")->getVal();
          wmc->var("m_pt")->setVal(mymu.Pt());
          wmc->var("m_eta")->setVal(mymu.Eta());
          wmc->var("m_iso")->setVal(iso_2);
          aweight=aweight*wmc->function("m_trk_ratio")->getVal();
          aweight=aweight*wmc->function("m_idiso_ic_ratio")->getVal();
          float sftrg2=wmc->function("m_trg_ic_ratio")->getVal();
          if (trigger1 && !trigger2) aweight=aweight*sftrg1;
          if (!trigger1 && trigger2) aweight=aweight*sftrg2;
          aweight=aweight*prefiring_weight;
          aweight=aweight*bweight;
        }
        if (year==2018 and sample!="data_obs"){
          aweight=aweight*aMCatNLO_weight*weight*LumiWeights_12->weight(npu);
          if (is_vsjet && gen_match_3==5) aweight=aweight*fct_tauid->Eval(mytau.Pt());
          if (gen_match_3==1 or gen_match_3==3){ // Medium VSe
             if (fabs(mytau.Eta())<1.448) aweight=aweight*1.25;
             else if (fabs(mytau.Eta())>1.558) aweight=aweight*0.65;
          }
          if (gen_match_3==2 or gen_match_3==4){ // Medium VSmu
             if (fabs(mytau.Eta())<0.4) aweight=aweight*0.978*1.463;
             else if (fabs(mytau.Eta())<0.8) aweight=aweight*1.003*0.722;
             else if (fabs(mytau.Eta())<1.2) aweight=aweight*0.992*1.337;
             else if (fabs(mytau.Eta())<1.7) aweight=aweight*1.003*0.966;
             else aweight=aweight*0.966*5.451;
          }
          wmc->var("e_pt")->setVal(myele.Pt());
          wmc->var("e_eta")->setVal(myele.Eta());
          wmc->var("e_iso")->setVal(iso_1);
          aweight=aweight*wmc->function("e_trk_ratio")->getVal();
          aweight=aweight*wmc->function("e_idiso_ic_ratio")->getVal();
          float sftrg1=wmc->function("e_trg_ic_ratio")->getVal();
          wmc->var("m_pt")->setVal(mymu.Pt());
          wmc->var("m_eta")->setVal(mymu.Eta());
          wmc->var("m_iso")->setVal(iso_2);
          aweight=aweight*wmc->function("m_trk_ratio")->getVal();
          aweight=aweight*wmc->function("m_idiso_ic_ratio")->getVal();
          float sftrg2=wmc->function("m_trg_ic_ratio")->getVal();
          if (trigger1 && !trigger2) aweight=aweight*sftrg1;
          if (!trigger1 && trigger2) aweight=aweight*sftrg2;
          aweight=aweight*bweight;
        }

	if (name=="data_obs") aweight=1.0;

	// ############################################################
	// ############### Loop over uncertainty sources ##############
	// ############################################################
	//
        TLorentzVector myrawmet;
        myrawmet.SetPtEtaPhiM(met,0,metphi,0);
	TLorentzVector myrawele=myele;
	TLorentzVector myrawmu=mymu;
	TLorentzVector myrawtau=mytau;

	for (int k=0; k<nbhist; ++k){

	    // for each iteration start from the nominal objects
	    float weight2=1.0;
	    TLorentzVector mymet=myrawmet;
	    myele=myrawele;
	    mymu=myrawmu;
	    mytau=myrawtau;

	    
           if (sample!="data_obs" && sample!="embedded"){
              if (k>0 && k<9){ // TES x 8
                if (k==1 && l3_decayMode==0 && gen_match_3==5) {mytau*=tes_dm0_do; mymet=mymet+((1.0-tes_dm0_do)/tes_dm0_do)*mytau;}
                else if (k==2 && l3_decayMode==0 && gen_match_3==5) {mytau*=tes_dm0_up; mymet=mymet+((1.0-tes_dm0_up)/tes_dm0_up)*mytau;}
                else if (k==3 && l3_decayMode==1 && gen_match_3==5) {mytau*=tes_dm1_do; mymet=mymet+((1.0-tes_dm1_do)/tes_dm1_do)*mytau;}
                else if (k==4 && l3_decayMode==1 && gen_match_3==5) {mytau*=tes_dm1_up; mymet=mymet+((1.0-tes_dm1_up)/tes_dm1_up)*mytau;}
                else if (k==5 && l3_decayMode==10 && gen_match_3==5) {mytau*=tes_dm10_do; mymet=mymet+((1.0-tes_dm10_do)/tes_dm10_do)*mytau;}
                else if (k==6 && l3_decayMode==10 && gen_match_3==5) {mytau*=tes_dm10_up; mymet=mymet+((1.0-tes_dm10_up)/tes_dm10_up)*mytau;}
                else if (k==7 && l3_decayMode==11 && gen_match_3==5) {mytau*=tes_dm11_do; mymet=mymet+((1.0-tes_dm11_do)/tes_dm11_do)*mytau;}
                else if (k==8 && l3_decayMode==11 && gen_match_3==5) {mytau*=tes_dm11_up; mymet=mymet+((1.0-tes_dm11_up)/tes_dm11_up)*mytau;}
              }
              else if (k>8 && k<19){
                if (k==9 && mytau.Pt()>=20 && mytau.Pt()<25) weight2=fct_tauid_down->Eval(mytau.Pt())/fct_tauid->Eval(mytau.Pt());
		else if (k==10 && mytau.Pt()>=20 && mytau.Pt()<25) weight2=fct_tauid_up->Eval(mytau.Pt())/fct_tauid->Eval(mytau.Pt());
                else if (k==11 && mytau.Pt()>=25 && mytau.Pt()<30) weight2=fct_tauid_down->Eval(mytau.Pt())/fct_tauid->Eval(mytau.Pt());
                else if (k==12 && mytau.Pt()>=25 && mytau.Pt()<30) weight2=fct_tauid_up->Eval(mytau.Pt())/fct_tauid->Eval(mytau.Pt());
                else if (k==13 && mytau.Pt()>=30 && mytau.Pt()<35) weight2=fct_tauid_down->Eval(mytau.Pt())/fct_tauid->Eval(mytau.Pt());
                else if (k==14 && mytau.Pt()>=30 && mytau.Pt()<35) weight2=fct_tauid_up->Eval(mytau.Pt())/fct_tauid->Eval(mytau.Pt());
                else if (k==15 && mytau.Pt()>=35 && mytau.Pt()<40) weight2=fct_tauid_down->Eval(mytau.Pt())/fct_tauid->Eval(mytau.Pt());
                else if (k==16 && mytau.Pt()>=35 && mytau.Pt()<40) weight2=fct_tauid_up->Eval(mytau.Pt())/fct_tauid->Eval(mytau.Pt());
                else if (k==17 && mytau.Pt()>=40) weight2=fct_tauid_down->Eval(mytau.Pt())/fct_tauid->Eval(mytau.Pt());
                else if (k==18 && mytau.Pt()>=40) weight2=fct_tauid_up->Eval(mytau.Pt())/fct_tauid->Eval(mytau.Pt());

              }
              else if (k>18 && k<21){ // UES x 2
                if (k==19){mymet=myrawmet; mymet.SetPtEtaPhiM(met_UESDown, 0, metphi_UESDown, 0);}
                else if (k==20){mymet=myrawmet; mymet.SetPtEtaPhiM(met_UESUp, 0, metphi_UESUp, 0);}
              }
              else if (k>20 && k<23){ // EES x 2 
                if (k==21){myele*=(pt_1_ScaleDown/myele.Pt()); mymet=mymet-myele+myrawele;}
                else if (k==22){myele*=(pt_1_ScaleUp/myele.Pt()); mymet=mymet-myele+myrawele;}
              }
              else if (k>22 && k<29){ // MES x 6 
                if (k==23 && fabs(mymu.Eta())<1.2){mymu*=0.996; mymet=mymet-mymu+myrawmu;}
                else if (k==24 && fabs(mymu.Eta())<1.2){mymu*=1.004; mymet=mymet-mymu+myrawmu;}
                else if (k==25 && fabs(mymu.Eta())>1.2 && fabs(mymu.Eta())<2.1){mymu*=0.993; mymet=mymet-mymu+myrawmu;}
                else if (k==26 && fabs(mymu.Eta())>1.2 && fabs(mymu.Eta())<2.1){mymu*=1.007; mymet=mymet-mymu+myrawmu;}
                else if (k==27 && fabs(mymu.Eta())>2.1){mymu*=0.973; mymet=mymet-mymu+myrawmu;}
                else if (k==28 && fabs(mymu.Eta())>2.1){mymu*=1.027; mymet=mymet-mymu+myrawmu;}
              }
              else if (k>28 && k<31){ // prefiring x 2
                if (k==29) {weight2=prefiring_weight_down/(prefiring_weight+0.00000001);}
                else if (k==30) {weight2=prefiring_weight_up/(prefiring_weight+0.00000001);}
              }
              else if (k>30 && k<33){ // muR muF scale x 2
                if (k==31) weight2=lheweight_nominalTo0p5_average*(lheweight_muR0p5_muF0p5/lheweight_nominal);
                else if (k==32) weight2=lheweight_nominalTo2_average*(lheweight_muR2_muF2/lheweight_nominal);
              }
              else if (k>32 && k<35){ // qqVH reweighting x 2
                if (k==33) weight2=ratio_nlo_down;
                else if (k==34) weight2=ratio_nlo_up;
              }
            }

            if (year==2016){
               trigger1=(passEle25 && matchEle25_1 && filterEle25_1 && myele.Pt()>26 && fabs(eta_1)<2.1 && mymu.Pt()<23);
               trigger2=((passMu22eta2p1 && matchMu22eta2p1_2 && filterMu22eta2p1_2 && mymu.Pt()>23 && fabs(eta_2)<2.1) or (passTkMu22eta2p1 && matchTkMu22eta2p1_2 && filterTkMu22eta2p1_2 && mymu.Pt()>23 && fabs(eta_2)<2.1) or (passMu22 && matchMu22_2 && filterMu22_2 && mymu.Pt()>23 && fabs(eta_2)<2.1) or (passTkMu22 && matchTkMu22_2 && filterTkMu22_2 && mymu.Pt()>23 && fabs(eta_2)<2.1));
            }
            if (year==2017){
               trigger1=((passEle27 && matchEle27_1 && filterEle27_1 && myele.Pt()>28 && fabs(eta_1)<2.1 && mymu.Pt()<25) or (passEle32 && matchEle32_1 && filterEle32_1 && myele.Pt()>28 && fabs(eta_1)<2.1 && mymu.Pt()<25));
               trigger2=((passMu24 && matchMu24_2 && filterMu24_2 && mymu.Pt()>25 && fabs(eta_2)<2.1) or (passMu27 && matchMu27_2 && filterMu27_2 && mymu.Pt()>25 && fabs(eta_2)<2.1));
            }
            if (year==2018){
               trigger1=((passEle32 && matchEle32_1 && filterEle32_1 && myele.Pt()>33 && fabs(eta_1)<2.1 && mymu.Pt()<25) or (passEle35 && matchEle35_1 && filterEle35_1 && myele.Pt()>33 && fabs(eta_1)<2.1 && mymu.Pt()<25));
               trigger2=((passMu24 && matchMu24_2 && filterMu24_2 && mymu.Pt()>25 && fabs(eta_2)<2.1) or (passMu27 && matchMu27_2 && filterMu27_2 && mymu.Pt()>25 && fabs(eta_2)<2.1));
            }
            if (!trigger1 && !trigger2) continue;

	    // pT cuts for the leptons
            if (myele.Pt()<10) continue; // Could be as low as 10 GeV
            if (mymu.Pt()<10) continue; // Could be as low as 10 GeV
	    if (mytau.Pt()<20) continue; // 20 is the minimum pT for taus

	    if (name=="data_obs") {aweight=1.0; weight2=1.0;}

	    //Definition of the fake rates

	    float fr=1.0;
	    float fre=1.0;
	    float frm=1.0;

            fr=GetTauFR(mytau.Pt(),l3_decayMode,g_taufr_dm0T,g_taufr_dm1T,g_taufr_dm10T,g_taufr_dm11T,0);//FIXME
	    fre=GetEleFR(myele.Pt(),g_efr,0);
            frm=GetMuFR(mymu.Pt(),g_mufr,0);

            if (k>34 && k<91){
              fr=GetTauFR(mytau.Pt(),l3_decayMode,g_taufr_dm0T,g_taufr_dm1T,g_taufr_dm10T,g_taufr_dm11T,k-34);//FIXME
            }
	    if (k>90 && k<101){
	       fre=GetEleFR(myele.Pt(),g_efr,k-90);
	    }
            if (k>100 && k<111){
               frm=GetMuFR(mymu.Pt(),g_mufr,k-100);
            }
	    if (k==111) fre=GetEleFR(myele.Pt(),g_efr_sub09,0);
            if (k==112) fre=GetEleFR(myele.Pt(),g_efr_sub11,0);
            if (k==113) frm=GetMuFR(mymu.Pt(),g_mufr_sub09,0);
            if (k==114) frm=GetMuFR(mymu.Pt(),g_mufr_sub11,0);

            float wfrt=fr/(1-fr); // weight for taus 
            float wfre=fre/(1-fre); // weight for electrons
            float wfrm=frm/(1-frm); // weight for muons

	    float mt1=TMass_F(myele.Pt(),mymet.Pt(),myele.Px(),mymet.Px(),myele.Py(),mymet.Py());
            float mtmu=TMass_F(mymu.Pt(),mymet.Pt(),mymu.Px(),mymet.Px(),mymu.Py(),mymet.Py());
            float mtele=TMass_F(myele.Pt(),mymet.Pt(),myele.Px(),mymet.Px(),myele.Py(),mymet.Py());

	    float deta=fabs(mymu.Eta()-(myele+mytau).Eta());
            float dphi=fabs(mymu.DeltaPhi(myele+mytau));
	    if (mymu.Pt()<myele.Pt()){ 
		deta=fabs(myele.Eta()-(mymu+mytau).Eta());
		dphi=fabs(myele.DeltaPhi(mymu+mytau));
	    }
	    bool selection_low = !((myele.Pt()+mymu.Pt()+mytau.Pt()>=100) && deta<2.0 && dphi>2.0);
            bool selection_high =(myele.Pt()+mymu.Pt()+mytau.Pt()>=100) && deta<2.0 && dphi>2.0;

	    //************************* Fill histograms **********************
	    
            float var=(mymu+mytau).M();
            float varSS=0.69*(mymu+mytau).M();
            if (q_1*q_3<0) varSS=0.69*(myele+mytau).M();
            TLorentzVector metFromHiggsSS=(mymu+mytau)*0.69;
	    float ptvSS=(myele+mymet-metFromHiggsSS).Pt();
            if (q_1*q_3<0){
		metFromHiggsSS=(myele+mytau)*0.69;
	        ptvSS=(mymu+mymet-metFromHiggsSS).Pt();
	    }

            float charge2=q_2;
            if (mymu.Pt()>myele.Pt()){
                var=(myele+mytau).M();
                charge2=q_1;
            }

            float factor=0.69;
            TLorentzVector metFromHiggs=(mymu+mytau)*factor;
            float ptv=(myele+mymet-metFromHiggs).Pt();
            var=(1.0+factor)*(mymu+mytau).M();
            if (mymu.Pt()>myele.Pt()){
		metFromHiggs=(myele+mytau)*factor;
                ptv=(mymu+mymet-metFromHiggs).Pt();
                var=(1.0+factor)*(myele+mytau).M();
	    }
	    float controlvar=ptv;

	    float wfrl=wfre;
            if (!(trigger2)) wfrl=wfrm;

	    if ((sample!="data_obs" && signalRegion && charge2*q_3<0 && q_1*q_2>0) or (sample=="data_obs" && aiRegion && charge2*q_3<0 && q_1*q_2>0)){
	      h_lt->Fill((myele.Pt()+mymu.Pt()+mytau.Pt()));
	      h_deta->Fill(deta);
	      h_dphi->Fill(dphi);
	    }

	    bool selectionSS=fabs(q_1+q_2+q_3)<30;
	    if (selection_high){
                if (signalRegion && charge2*q_3<0 && q_1*q_2>0)
                    h0_OS[k]->Fill(ptv,var,weight2*aweight);
                if (signalRegion && q_1*q_2<0 && fabs(q_1+q_2+q_3)<3)
                    h0_SS[k]->Fill(ptvSS,varSS,weight2*aweight);
	  	if (aiRegion && charge2*q_3<0 && q_1*q_2>0)
                    h0_AIOS[k]->Fill(ptv,var,weight2*aweight*wfrt);
                if (q_1*q_2<0 && fabs(q_1+q_2+q_3)<3 && aiRegion)
                    h0_AISS[k]->Fill(ptvSS,varSS,weight2*aweight*wfrt);
                if (ai0Region && charge2*q_3<0 && q_1*q_2>0)
                    h0_AI0OS[k]->Fill(ptv,var,weight2*aweight*wfrt*wfrl);
                if (q_1*q_2<0 && fabs(q_1+q_2+q_3)<3 && ai0Region)
                    h0_AI0SS[k]->Fill(ptvSS,varSS,weight2*aweight*wfrt*wfrl);
                if (ai1Region && charge2*q_3<0 && q_1*q_2>0)
                    h0_AI1OS[k]->Fill(ptv,var,weight2*aweight*wfrl);
                if (q_1*q_2<0 && fabs(q_1+q_2+q_3)<3 && ai1Region)
                    h0_AI1SS[k]->Fill(ptvSS,varSS,weight2*aweight*wfrl);
                if (ai2Region && charge2*q_3<0 && q_1*q_2>0)
                    h0_AI2OS[k]->Fill(ptv,var,weight2*aweight*wfrt);
                if (q_1*q_2<0 && fabs(q_1+q_2+q_3)<3 && ai2Region)
                    h0_AI2SS[k]->Fill(ptvSS,varSS,weight2*aweight*wfrt);
	    }

            if (selection_low){
                if (signalRegion && charge2*q_3<0 && q_1*q_2>0)
                    h1_OS[k]->Fill(controlvar,weight2*aweight);
                if (fabs(q_1+q_2+q_3)==3 && signalRegion)
                    h1_SS[k]->Fill(controlvar,weight2*aweight);
                if (aiRegion && charge2*q_3<0 && q_1*q_2>0)
                    h1_AIOS[k]->Fill(controlvar,weight2*aweight*wfrt);
                if (fabs(q_1+q_2+q_3)==3 && aiRegion)
                    h1_AISS[k]->Fill(controlvar,weight2*aweight*wfrt);
                if (ai0Region && charge2*q_3<0 && q_1*q_2>0)
                    h1_AI0OS[k]->Fill(controlvar,weight2*aweight*wfrt*wfrl);
                if (fabs(q_1+q_2+q_3)==3 && ai0Region)
                    h1_AI0SS[k]->Fill(controlvar,weight2*aweight*wfrt*wfrl);
                if (ai1Region && charge2*q_3<0 && q_1*q_2>0)
                    h1_AI1OS[k]->Fill(controlvar,weight2*aweight*wfrl);
                if (fabs(q_1+q_2+q_3)==3 && ai1Region)
                    h1_AI1SS[k]->Fill(controlvar,weight2*aweight*wfrl);
                if (ai2Region && charge2*q_3<0 && q_1*q_2>0)
                    h1_AI2OS[k]->Fill(controlvar,weight2*aweight*wfrt);
                if (fabs(q_1+q_2+q_3)==3 && ai2Region)
                    h1_AI2SS[k]->Fill(controlvar,weight2*aweight*wfrt);
            }
	}
    } // end of loop over events


    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    h_lt->Write();
    h_deta->Write();
    h_dphi->Write();

    TString postfix="";

    TDirectory *OS =fout->mkdir("emt_high");
    TDirectory *SS =fout->mkdir("emt_highSS");
    TDirectory *AIOS =fout->mkdir("AIOS");
    TDirectory *AISS =fout->mkdir("AISS");
    TDirectory *AI0OS =fout->mkdir("AI0OS");
    TDirectory *AI0SS =fout->mkdir("AI0SS");
    TDirectory *AI1OS =fout->mkdir("AI1OS");
    TDirectory *AI1SS =fout->mkdir("AI1SS");
    TDirectory *AI2OS =fout->mkdir("AI2OS");
    TDirectory *AI2SS =fout->mkdir("AI2SS");

    TDirectory *OS1 =fout->mkdir("emt_low");
    TDirectory *SS1 =fout->mkdir("emt_lowSS");
    TDirectory *AIOS1 =fout->mkdir("AIOS1");
    TDirectory *AISS1 =fout->mkdir("AISS1");
    TDirectory *AI0OS1 =fout->mkdir("AI0OS1");
    TDirectory *AI0SS1 =fout->mkdir("AI0SS1");
    TDirectory *AI1OS1 =fout->mkdir("AI1OS1");
    TDirectory *AI1SS1 =fout->mkdir("AI1SS1");
    TDirectory *AI2OS1 =fout->mkdir("AI2OS1");
    TDirectory *AI2SS1 =fout->mkdir("AI2SS1");

    for (int k=0; k<nbhist; ++k){

       if (k<35) postfix=postfixTES[k];
       if (k>=35) postfix=postfixFake[k-35];

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

       AI0OS->cd();
       h0_AI0OS[k]->SetName(name.c_str()+postfix);
       h0_AI0OS[k]->Write();
       AI0SS->cd();
       h0_AI0SS[k]->SetName(name.c_str()+postfix);
       h0_AI0SS[k]->Write();
       AI1OS->cd();
       h0_AI1OS[k]->SetName(name.c_str()+postfix);
       h0_AI1OS[k]->Write();
       AI1SS->cd();
       h0_AI1SS[k]->SetName(name.c_str()+postfix);
       h0_AI1SS[k]->Write();
       AI2OS->cd();
       h0_AI2OS[k]->SetName(name.c_str()+postfix);
       h0_AI2OS[k]->Write();
       AI2SS->cd();
       h0_AI2SS[k]->SetName(name.c_str()+postfix);
       h0_AI2SS[k]->Write();

       OS1->cd();
       h1_OS[k]->SetName(name.c_str()+postfix);
       h1_OS[k]->Write();
       SS1->cd();
       h1_SS[k]->SetName(name.c_str()+postfix);
       h1_SS[k]->Write();
       AIOS1->cd();
       h1_AIOS[k]->SetName(name.c_str()+postfix);
       h1_AIOS[k]->Write();
       AISS1->cd();
       h1_AISS[k]->SetName(name.c_str()+postfix);
       h1_AISS[k]->Write();

       AI0OS1->cd();
       h1_AI0OS[k]->SetName(name.c_str()+postfix);
       h1_AI0OS[k]->Write();
       AI0SS1->cd();
       h1_AI0SS[k]->SetName(name.c_str()+postfix);
       h1_AI0SS[k]->Write();
       AI1OS1->cd();
       h1_AI1OS[k]->SetName(name.c_str()+postfix);
       h1_AI1OS[k]->Write();
       AI1SS1->cd();
       h1_AI1SS[k]->SetName(name.c_str()+postfix);
       h1_AI1SS[k]->Write();
       AI2OS1->cd();
       h1_AI2OS[k]->SetName(name.c_str()+postfix);
       h1_AI2OS[k]->Write();
       AI2SS1->cd();
       h1_AI2SS[k]->SetName(name.c_str()+postfix);
       h1_AI2SS[k]->Write();

    }
    fout->Close();

cout<<h0_OS[0]->Integral()<<endl;
} 


