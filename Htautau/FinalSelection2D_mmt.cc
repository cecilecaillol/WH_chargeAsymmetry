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
#include "LumiReweightingStandAlone.h"
#include "btagSF.h"
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

    float year=0;
    if (argc > 1) {
        year = atof(argv[6]);
    }

    TFile *f_Double = new TFile(input.c_str());
    cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<endl;
    TTree *arbre = (TTree*) f_Double->Get("mmt_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2); //FIXME

    TFile *f_taufr=new TFile("FitHistograms_tauFR_2016.root");
    if (year==2016) f_taufr=new TFile("FitHistograms_tauFR_2016.root");
    if (year==2017) f_taufr=new TFile("FitHistograms_tauFR_2017.root");
    if (year==2018) f_taufr=new TFile("FitHistograms_tauFR_2018.root");
    TGraphAsymmErrors *g_taufr_dm0T = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm0_VLe_Tmu_deeptight_hpt_dm0_VLe_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm1T = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm1_VLe_Tmu_deeptight_hpt_dm1_VLe_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm10T = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm10_VLe_Tmu_deeptight_hpt_dm10_VLe_Tmu_deepveryveryveryloose");
    TGraphAsymmErrors *g_taufr_dm11T = (TGraphAsymmErrors*) f_taufr->Get("hpt_dm11_VLe_Tmu_deeptight_hpt_dm11_VLe_Tmu_deepveryveryveryloose");

    Double_t *taufr_dm0_y = g_taufr_dm0T->GetY();
    Double_t *taufr_dm1_y = g_taufr_dm1T->GetY();
    Double_t *taufr_dm10_y = g_taufr_dm10T->GetY();
    Double_t *taufr_dm11_y = g_taufr_dm11T->GetY();
    Double_t *taufr_dm0_ylow = g_taufr_dm0T->GetEYlow();
    Double_t *taufr_dm1_ylow = g_taufr_dm1T->GetEYlow();
    Double_t *taufr_dm10_ylow = g_taufr_dm10T->GetEYlow();
    Double_t *taufr_dm11_ylow = g_taufr_dm11T->GetEYlow();
    Double_t *taufr_dm0_yhigh = g_taufr_dm0T->GetEYhigh();
    Double_t *taufr_dm1_yhigh = g_taufr_dm1T->GetEYhigh();
    Double_t *taufr_dm10_yhigh = g_taufr_dm10T->GetEYhigh();
    Double_t *taufr_dm11_yhigh = g_taufr_dm11T->GetEYhigh();

cout<<taufr_dm0_y[0]<<" "<<taufr_dm0_ylow[0]<<" "<<taufr_dm0_yhigh[0]<<endl;

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


//Normalization os MC samples
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
    else if (sample=="ZZ4L") {xs=1.212; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ2L2Q") {xs=3.22; weight=luminosity*xs/ngen;}
    else if (sample=="VV2L2Nu") {xs=11.95; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_antitop") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_top") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_antitop") {xs=26.23; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_top") {xs=44.07; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ4L") {xs=1.256; weight=luminosity*xs/ngen;}
    else if (sample=="WZ3LNu") {xs=4.708; weight=luminosity*xs/ngen;}
    else if (sample=="ttZ") {xs=0.2529; weight=luminosity*xs/ngen;}
    else if (sample=="ttW") {xs=0.2043; weight=luminosity*xs/ngen;}
    else if (sample=="ZG") {xs=117.864; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ2e2mu") {xs=0.00319; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ2e2tau") {xs=0.00319; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ2mu2tau") {xs=0.00319; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ4e") {xs=0.00159; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ4mu") {xs=0.00159; weight=luminosity*xs/ngen;}
    else if (sample=="GGZZ4tau") {xs=0.00159; weight=luminosity*xs/ngen;}
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
    arbre->SetBranchAddress("PythiaWeight_isr_muR2", &PythiaWeight_isr_muR2);
    arbre->SetBranchAddress("PythiaWeight_isr_muR0p5", &PythiaWeight_isr_muR0p5);
    arbre->SetBranchAddress("PythiaWeight_fsr_muR2", &PythiaWeight_fsr_muR2);
    arbre->SetBranchAddress("PythiaWeight_fsr_muR0p5", &PythiaWeight_fsr_muR0p5);
    arbre->SetBranchAddress("lheweight_muR0p5_muF0p5", &lheweight_muR0p5_muF0p5);
    arbre->SetBranchAddress("lheweight_muR2_muF2", &lheweight_muR2_muF2);
    arbre->SetBranchAddress("lheweight_nominal", &lheweight_nominal);
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
    arbre->SetBranchAddress("q_2", &q_2);
    arbre->SetBranchAddress("pt_2", &pt_2);
    arbre->SetBranchAddress("eta_2", &eta_2);
    arbre->SetBranchAddress("iso_2", &iso_2);
    arbre->SetBranchAddress("id_m_medium_2", &id_m_medium_2);
    arbre->SetBranchAddress("id_m_medium_1", &id_m_medium_1);
    arbre->SetBranchAddress("m_2", &m_2);
    arbre->SetBranchAddress("phi_2", &phi_2);
    arbre->SetBranchAddress("q_3", &q_3);
    arbre->SetBranchAddress("pt_3", &pt_3);
    arbre->SetBranchAddress("eta_3", &eta_3);
    arbre->SetBranchAddress("m_3", &m_3);
    arbre->SetBranchAddress("phi_3", &phi_3);

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
    arbre->SetBranchAddress("metphi_UESDown", &metphi_UESDown);
    arbre->SetBranchAddress("metphi_UESUp", &metphi_UESUp);
    arbre->SetBranchAddress("met_UESDown", &met_UESDown);
    arbre->SetBranchAddress("met_UESUp", &met_UESUp);

    arbre->SetBranchAddress("prefiring_weight", &prefiring_weight);
    arbre->SetBranchAddress("prefiring_weight_up", &prefiring_weight_up);
    arbre->SetBranchAddress("prefiring_weight_down", &prefiring_weight_down);
    arbre->SetBranchAddress("bweight", &bweight);

    arbre->SetBranchAddress("passMu19Tau20", &passMu19Tau20);
    arbre->SetBranchAddress("passMu19Tau20SingleL1", &passMu19Tau20SingleL1);
    arbre->SetBranchAddress("matchMu19Tau20_1", &matchMu19Tau20_1);
    arbre->SetBranchAddress("matchMu19Tau20_2", &matchMu19Tau20_2);
    arbre->SetBranchAddress("matchMu19Tau20_3", &matchMu19Tau20_3);
    arbre->SetBranchAddress("matchMu19Tau20SingleL1_1", &matchMu19Tau20SingleL1_1);
    arbre->SetBranchAddress("matchMu19Tau20SingleL1_2", &matchMu19Tau20SingleL1_2);
    arbre->SetBranchAddress("matchMu19Tau20SingleL1_3", &matchMu19Tau20SingleL1_3);
    arbre->SetBranchAddress("filterMu19Tau20_1", &filterMu19Tau20_1);
    arbre->SetBranchAddress("filterMu19Tau20_2", &filterMu19Tau20_2);
    arbre->SetBranchAddress("filterMu19Tau20_3", &filterMu19Tau20_3);
    arbre->SetBranchAddress("filterMu19Tau20SingleL1_1", &filterMu19Tau20SingleL1_1);
    arbre->SetBranchAddress("filterMu19Tau20SingleL1_3", &filterMu19Tau20SingleL1_3);
    arbre->SetBranchAddress("filterMu19Tau20SingleL1_2", &filterMu19Tau20SingleL1_2);
    arbre->SetBranchAddress("passMu20Tau27", &passMu20Tau27);
    arbre->SetBranchAddress("matchMu20Tau27_1", &matchMu20Tau27_1);
    arbre->SetBranchAddress("filterMu20Tau27_1", &filterMu20Tau27_1);
    arbre->SetBranchAddress("matchMu20Tau27_2", &matchMu20Tau27_2);
    arbre->SetBranchAddress("filterMu20Tau27_2", &filterMu20Tau27_2);
    arbre->SetBranchAddress("matchMu20Tau27_3", &matchMu20Tau27_3);
    arbre->SetBranchAddress("filterMu20Tau27_3", &filterMu20Tau27_3);
    arbre->SetBranchAddress("passMu20HPSTau27", &passMu20HPSTau27);
    arbre->SetBranchAddress("matchMu20HPSTau27_1", &matchMu20HPSTau27_1);
    arbre->SetBranchAddress("filterMu20HPSTau27_1", &filterMu20HPSTau27_1);
    arbre->SetBranchAddress("matchMu20HPSTau27_2", &matchMu20HPSTau27_2);
    arbre->SetBranchAddress("filterMu20HPSTau27_2", &filterMu20HPSTau27_2);
    arbre->SetBranchAddress("matchMu20HPSTau27_3", &matchMu20HPSTau27_3);
    arbre->SetBranchAddress("filterMu20HPSTau27_3", &filterMu20HPSTau27_3);
    arbre->SetBranchAddress("passMu22eta2p1", &passMu22eta2p1);
    arbre->SetBranchAddress("passTkMu22eta2p1", &passTkMu22eta2p1);
    arbre->SetBranchAddress("matchMu22eta2p1_2", &matchMu22eta2p1_2);
    arbre->SetBranchAddress("matchTkMu22eta2p1_2", &matchTkMu22eta2p1_2);
    arbre->SetBranchAddress("matchMu22eta2p1_1", &matchMu22eta2p1_1);
    arbre->SetBranchAddress("matchTkMu22eta2p1_1", &matchTkMu22eta2p1_1);
    arbre->SetBranchAddress("filterMu22eta2p1_2", &filterMu22eta2p1_2);
    arbre->SetBranchAddress("filterTkMu22eta2p1_2", &filterTkMu22eta2p1_2);
    arbre->SetBranchAddress("filterMu22eta2p1_1", &filterMu22eta2p1_1);
    arbre->SetBranchAddress("filterTkMu22eta2p1_1", &filterTkMu22eta2p1_1);
    arbre->SetBranchAddress("passMu22", &passMu22);
    arbre->SetBranchAddress("passTkMu22", &passTkMu22);
    arbre->SetBranchAddress("matchMu22_2", &matchMu22_2);
    arbre->SetBranchAddress("matchTkMu22_2", &matchTkMu22_2);
    arbre->SetBranchAddress("matchMu22_1", &matchMu22_1);
    arbre->SetBranchAddress("matchTkMu22_1", &matchTkMu22_1);
    arbre->SetBranchAddress("filterMu22_2", &filterMu22_2);
    arbre->SetBranchAddress("filterTkMu22_2", &filterTkMu22_2);
    arbre->SetBranchAddress("filterMu22_1", &filterMu22_1);
    arbre->SetBranchAddress("filterTkMu22_1", &filterTkMu22_1);
    arbre->SetBranchAddress("passMu24", &passMu24);
    arbre->SetBranchAddress("matchMu24_2", &matchMu24_2);
    arbre->SetBranchAddress("filterMu24_2", &filterMu24_2);
    arbre->SetBranchAddress("matchMu24_1", &matchMu24_1);
    arbre->SetBranchAddress("filterMu24_1", &filterMu24_1);
    arbre->SetBranchAddress("passMu27", &passMu27);
    arbre->SetBranchAddress("matchMu27_2", &matchMu27_2);
    arbre->SetBranchAddress("filterMu27_2", &filterMu27_2);
    arbre->SetBranchAddress("matchMu27_1", &matchMu27_1);
    arbre->SetBranchAddress("filterMu27_1", &filterMu27_1);

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

   /*float bins0[] = {20,30,40,50,60,70,80,90,100,110,120,130,140};
   float binsHigh[] = {20,30,40,50,60,70,80,90,100,110,120,130,140};
   float binsLow[] = {20,30,40,50,60,70,80,90,100,110,120,130,140};
   float bins1[] = {20,30,40,50,60,70,80,90,100,110,120,130,140};

   int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
   int  binnumHigh = sizeof(binsHigh)/sizeof(Float_t) - 1;
   int  binnumLow = sizeof(binsLow)/sizeof(Float_t) - 1;
   int  binnum1 = sizeof(bins1)/sizeof(Float_t) - 1;*/

   float bins[] = {0,50,70,90,110,130,150,170,290};
   int  binnum = sizeof(bins)/sizeof(Float_t) - 1;
   float binsPTV[] ={0,75,150,1000};
   int  binnumPTV = sizeof(binsPTV)/sizeof(Float_t) - 1;


   std::vector<TH2F*> h0_OS;//Signal region, opposite-sign taus
   std::vector<TH1F*> h0_SS; //Signal region, same-sign taus
   std::vector<TH2F*> h0_AIOS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h0_AISS; //Region with same-sign anti-isolated taus
   std::vector<TH2F*> h0_AI0OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h0_AI0SS; //Region with same-sign anti-isolated taus
   std::vector<TH2F*> h0_AI1OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h0_AI1SS; //Region with same-sign anti-isolated taus
   std::vector<TH2F*> h0_AI2OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h0_AI2SS; //Region with same-sign anti-isolated taus

   std::vector<TH1F*> h1_OS;//Signal region, opposite-sign taus
   std::vector<TH1F*> h1_SS; //Signal region, same-sign taus
   std::vector<TH1F*> h1_AIOS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h1_AISS; //Region with same-sign anti-isolated taus
   std::vector<TH1F*> h1_AI0OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h1_AI0SS; //Region with same-sign anti-isolated taus
   std::vector<TH1F*> h1_AI1OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h1_AI1SS; //Region with same-sign anti-isolated taus
   std::vector<TH1F*> h1_AI2OS; //Region with opposite-sign anti-isolated taus
   std::vector<TH1F*> h1_AI2SS; //Region with same-sign anti-isolated taus

//For shape systematics
   int nbhist=1+32+58+10;

   for (int k=0; k<nbhist; ++k){
        ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
        h0_OS.push_back(new TH2F (HNS0OS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_OS[k]->Sumw2();

        ostringstream HNS0SS; HNS0OS << "h0_SS" << k;
        h0_SS.push_back(new TH1F (HNS0SS.str().c_str(),"InvMa",20,0,200)); h0_SS[k]->Sumw2();

        ostringstream HNS0AIOS; HNS0AIOS << "h0_AIOS" << k;
        h0_AIOS.push_back(new TH2F (HNS0AIOS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AIOS[k]->Sumw2();

        ostringstream HNS0AISS; HNS0AISS << "h0_AISS" << k;
        h0_AISS.push_back(new TH1F (HNS0AISS.str().c_str(),"InvMa",20,0,200)); h0_AISS[k]->Sumw2();

        ostringstream HNS0AI0OS; HNS0AI0OS << "h0_AI0OS" << k;
        h0_AI0OS.push_back(new TH2F (HNS0AI0OS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AI0OS[k]->Sumw2();

        ostringstream HNS0AI0SS; HNS0AI0SS << "h0_AI0SS" << k;
        h0_AI0SS.push_back(new TH1F (HNS0AI0SS.str().c_str(),"InvMa",20,0,200)); h0_AI0SS[k]->Sumw2();

        ostringstream HNS0AI1OS; HNS0AI1OS << "h0_AI1OS" << k;
        h0_AI1OS.push_back(new TH2F (HNS0AI1OS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AI1OS[k]->Sumw2();

        ostringstream HNS0AI1SS; HNS0AI1SS << "h0_AI1SS" << k;
        h0_AI1SS.push_back(new TH1F (HNS0AI1SS.str().c_str(),"InvMa",20,0,200)); h0_AI1SS[k]->Sumw2();

        ostringstream HNS0AI2OS; HNS0AI2OS << "h0_AI2OS" << k;
        h0_AI2OS.push_back(new TH2F (HNS0AI2OS.str().c_str(),"InvMa",binnumPTV,binsPTV,binnum,bins)); h0_AI2OS[k]->Sumw2();

        ostringstream HNS0AI2SS; HNS0AI2SS << "h0_AI2SS" << k;
        h0_AI2SS.push_back(new TH1F (HNS0AI2SS.str().c_str(),"InvMa",20,0,200)); h0_AI2SS[k]->Sumw2();

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

   TString postfixTES[33]={"","_CMS_scale_t_1prong_2017Down","_CMS_scale_t_1prong_2017Up","_CMS_scale_t_1prong1pizero_2017Down","_CMS_scale_t_1prong1pizero_2017Up","_CMS_scale_t_3prong_2017Down","_CMS_scale_t_3prong_2017Up","_CMS_scale_t_3prong1pizero_2017Down","_CMS_scale_t_3prong1pizero_2017Up","_CMS_tauideff_pt20to25_2017Down","_CMS_tauideff_pt20to25_2017Up","_CMS_tauideff_pt25to30_2017Down","_CMS_tauideff_pt25to30_2017Up","_CMS_tauideff_pt30to35_2017Down","_CMS_tauideff_pt30to35_2017Up","_CMS_tauideff_pt35to40_2017Down","_CMS_tauideff_pt35to40_2017Up","_CMS_tauideff_ptgt40_2017Down","_CMS_tauideff_ptgt40_2017Up","_CMS_scale_met_unclustered_2017Down","_CMS_scale_met_unclustered_2017Up","_CMS_scale_m_etalt1p2_2017Down","_CMS_scale_m_etalt1p2_2017Up","_CMS_scale_m_eta1p2to2p1_2017Down","_CMS_scale_m_eta1p2to2p1_2017Up","_CMS_scale_m_etagt2p1_2017Down","_CMS_scale_m_etagt2p1_2017Up","_CMS_prefiringDown","_CMS_prefiringUp","_FIXMEDown","_FIXMEUp","_qqVH_NLOEWKDown","_qqVH_NLOEWKUp"};

   TString postfixFake[68]={"_CMS_fakeTauVT_dm0_pt20to25_2017Up","_CMS_fakeTauVT_dm0_pt20to25_2017Down","_CMS_fakeTauVT_dm0_pt25to30_2017Up","_CMS_fakeTauVT_dm0_pt25to30_2017Down","_CMS_fakeTauVT_dm0_pt30to35_2017Up","_CMS_fakeTauVT_dm0_pt30to35_2017Down","_CMS_fakeTauVT_dm0_pt35to40_2017Up","_CMS_fakeTauVT_dm0_pt35to40_2017Down","_CMS_fakeTauVT_dm0_pt40to50_2017Up","_CMS_fakeTauVT_dm0_pt40to50_2017Down","_CMS_fakeTauVT_dm0_pt50to60_2017Up","_CMS_fakeTauVT_dm0_pt50to60_2017Down","_CMS_fakeTauVT_dm0_ptgt60_2017Up","_CMS_fakeTauVT_dm0_ptgt60_2017Down","_CMS_fakeTauVT_dm1_pt20to25_2017Up","_CMS_fakeTauVT_dm1_pt20to25_2017Down","_CMS_fakeTauVT_dm1_pt25to30_2017Up","_CMS_fakeTauVT_dm1_pt25to30_2017Down","_CMS_fakeTauVT_dm1_pt30to35_2017Up","_CMS_fakeTauVT_dm1_pt30to35_2017Down","_CMS_fakeTauVT_dm1_pt35to40_2017Up","_CMS_fakeTauVT_dm1_pt35to40_2017Down","_CMS_fakeTauVT_dm1_pt40to50_2017Up","_CMS_fakeTauVT_dm1_pt40to50_2017Down","_CMS_fakeTauVT_dm1_pt50to60_2017Up","_CMS_fakeTauVT_dm1_pt50to60_2017Down","_CMS_fakeTauVT_dm1_ptgt60_2017Up","_CMS_fakeTauVT_dm1_ptgt60_2017Down","_CMS_fakeTauVT_dm10_pt20to25_2017Up","_CMS_fakeTauVT_dm10_pt20to25_2017Down","_CMS_fakeTauVT_dm10_pt25to30_2017Up","_CMS_fakeTauVT_dm10_pt25to30_2017Down","_CMS_fakeTauVT_dm10_pt30to35_2017Up","_CMS_fakeTauVT_dm10_pt30to35_2017Down","_CMS_fakeTauVT_dm10_pt35to40_2017Up","_CMS_fakeTauVT_dm10_pt35to40_2017Down","_CMS_fakeTauVT_dm10_pt40to50_2017Up","_CMS_fakeTauVT_dm10_pt40to50_2017Down","_CMS_fakeTauVT_dm10_pt50to60_2017Up","_CMS_fakeTauVT_dm10_pt50to60_2017Down","_CMS_fakeTauVT_dm10_ptgt60_2017Up","_CMS_fakeTauVT_dm10_ptgt60_2017Down","_CMS_fakeTauVT_dm11_pt20to25_2017Up","_CMS_fakeTauVT_dm11_pt20to25_2017Down","_CMS_fakeTauVT_dm11_pt25to30_2017Up","_CMS_fakeTauVT_dm11_pt25to30_2017Down","_CMS_fakeTauVT_dm11_pt30to35_2017Up","_CMS_fakeTauVT_dm11_pt30to35_2017Down","_CMS_fakeTauVT_dm11_pt35to40_2017Up","_CMS_fakeTauVT_dm11_pt35to40_2017Down","_CMS_fakeTauVT_dm11_pt40to50_2017Up","_CMS_fakeTauVT_dm11_pt40to50_2017Down","_CMS_fakeTauVT_dm11_pt50to60_2017Up","_CMS_fakeTauVT_dm11_pt50to60_2017Down","_CMS_fakeTauVT_dm11_ptgt60_2017Up","_CMS_fakeTauVT_dm11_ptgt60_2017Down","_CMS_fakeMu_pt10to15_2017Up","_CMS_fakeMu_pt10to15_2017Down","_CMS_fakeMu_pt15to20_2017Up","_CMS_fakeMu_pt15to20_2017Down","_CMS_fakeMu_pt20to30_2017Up","_CMS_fakeMu_pt20to30_2017Down","_CMS_fakeMu_pt30to40_2017Up","_CMS_fakeMu_pt30to40_2017Down","_CMS_fakeMu_ptgt40_2017Up","_CMS_fakeMu_ptgt40_2017Down","_CMS_fakeMu_promptSubtraction_2017Down","_CMS_fakeMu_promptSubtraction_2017Up"};

   for (int k = 0; k < 68; ++k){
      if (year==2016) postfixFake[k]=postfixFake[k].ReplaceAll("2017",4,"2016",4);
      if (year==2018) postfixFake[k]=postfixFake[k].ReplaceAll("2017",4,"2018",4);
   }
   for (int k = 0; k < 29; ++k){
      if (year==2016) postfixTES[k]=postfixTES[k].ReplaceAll("2017",4,"2016",4);
      if (year==2018) postfixTES[k]=postfixTES[k].ReplaceAll("2017",4,"2018",4);
   }

   TFile *ftauid = new TFile("TauID_SF_pt_DeepTau2017v2p1VSjet_2016Legacy.root");
   if (year==2017) ftauid = new TFile("TauID_SF_pt_DeepTau2017v2p1VSjet_2017ReReco.root");
   if (year==2018) ftauid = new TFile("TauID_SF_pt_DeepTau2017v2p1VSjet_2018ReReco.root");
   TF1 *fct_tauid= (TF1*) ftauid->Get("Tight_cent");
   TF1 *fct_tauid_up= (TF1*) ftauid->Get("Tight_up");
   TF1 *fct_tauid_down= (TF1*) ftauid->Get("Tight_down");

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
      if (name=="WH_lep_htt125" or name=="WH_lep_hww125") {lheweight_nominalTo2_average= h_QCDScaleAcceptance_WH_lep->GetBinContent(1)/h_QCDScaleAcceptance_WH_lep->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_WH_lep->GetBinContent(1)/h_QCDScaleAcceptance_WH_lep->GetBinContent(9); postfixTES[29]="_WHlep_scaleDown"; postfixTES[30]="_WHlep_scaleUp";}
      if (name=="ggZH_lep_htt125" or name=="ZH_lep_htt125" or name=="ggZH_lep_hww125" or name=="ZH_lep_hww125") {lheweight_nominalTo2_average= h_QCDScaleAcceptance_ZH_lep->GetBinContent(1)/h_QCDScaleAcceptance_ZH_lep->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_ZH_lep->GetBinContent(1)/h_QCDScaleAcceptance_ZH_lep->GetBinContent(9); postfixTES[29]="_ZHlep_scaleDown"; postfixTES[30]="_ZHlep_scaleUp";}
      if (name.find("WH_lep_PTV_0_75_h") < 140 or name.find("WH_lep_PTV_75_150_h") < 140 or name.find("WH_lep_PTV_150_250_0J_h") < 140 or name.find("WH_lep_PTV_150_250_GE1J_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_lowpt->GetBinContent(9); postfixTES[29]="_WH_scale_lowptDown"; postfixTES[30]="_WH_scale_lowptUp";}
      if (name.find("WH_lep_PTV_GT250_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_WH_scale_highpt->GetBinContent(9); postfixTES[29]="_WH_scale_highptDown"; postfixTES[30]="_WH_scale_highptUp";}
      if (name.find("ZH_lep_PTV_0_75_h") < 140 or name.find("ZH_lep_PTV_75_150_h") < 140 or name.find("ZH_lep_PTV_150_250_0J_h") < 140 or name.find("ZH_lep_PTV_150_250_GE1J_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_lowpt->GetBinContent(9); postfixTES[29]="_ZH_scale_lowptDown"; postfixTES[30]="_ZH_scale_lowptUp";}
      if (name.find("ZH_lep_PTV_GT250_h") < 140) {lheweight_nominalTo2_average= h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(5);  lheweight_nominalTo0p5_average=h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(1)/h_QCDScaleAcceptance_ZH_scale_highpt->GetBinContent(9); postfixTES[29]="_ZH_scale_highptDown"; postfixTES[30]="_ZH_scale_highptUp";}
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

        bool trigger1=true;
        bool trigger2=false;

         if (year==2016){
            trigger1=((passMu22eta2p1 && matchMu22eta2p1_1 && filterMu22eta2p1_1 && pt_1>22.5 && fabs(eta_1)<2.1) or (passTkMu22eta2p1 && matchTkMu22eta2p1_1 && filterTkMu22eta2p1_1 && pt_1>22.5 && fabs(eta_1)<2.1) or (passMu22 && matchMu22_1 && filterMu22_1 && pt_1>22.5 && fabs(eta_1)<2.1) or (passTkMu22 && matchTkMu22_1 && filterTkMu22_1 && pt_1>22.5 && fabs(eta_1)<2.1));
	    //trigger2=((passMu19Tau20 && filterMu19Tau20_1 && pt_1>19.5 && pt_1<23.5 && filterMu19Tau20_3 && pt_3>24.5 && fabs(eta_3)<2.1) or (passMu19Tau20SingleL1 && matchMu19Tau20SingleL1_1 && pt_1>19.5 && pt_1<23.5 && matchMu19Tau20SingleL1_3 && filterMu19Tau20SingleL1_3 && pt_3>24.5 && fabs(eta_3)<2.1));
        }
        if (year==2017){
           trigger1=((passMu24 && matchMu24_1 && filterMu24_1 && pt_1>24.5 && fabs(eta_1)<2.1) or (passMu27 && matchMu27_1 && filterMu27_1 && pt_1>24.5 && fabs(eta_1)<2.1));
        }
        if (year==2018){
           trigger1=((passMu24 && matchMu24_1 && filterMu24_1 && pt_1>24.5 && fabs(eta_1)<2.1) or (passMu27 && matchMu27_1 && filterMu27_1 && pt_1>24.5 && fabs(eta_1)<2.1));
        }
        if (!trigger1 && !trigger2) continue;

	if (fabs(eta_1)>2.1) continue;
        if (fabs(eta_2)>2.4) continue;
        if (fabs(eta_3)>2.3) continue;

        if (q_1*q_2<0) continue;//The two muons have the same sign to reduce TT and DY

	// Remove MC events with jet->tau fakes
        if (sample!="data_obs" and gen_match_3==6) continue;
        if (sample!="data_obs" and gen_match_2==6) continue; // Now events with fake subleading muon are also taken from data

	// Muon ID
	bool muonID2=true;
	if (!id_m_medium_2) muonID2=false;
	if (iso_2>0.15) muonID2=false;

	bool muonID1=true;
	if (!id_m_medium_1) muonID1=false;
        if (iso_1>0.15) muonID1=false;
	if (!muonID1) continue;

	// Build objects
        TLorentzVector mymu1;
        mymu1.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);
        TLorentzVector mymu2;
        mymu2.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
        TLorentzVector mytau;
        mytau.SetPtEtaPhiM(pt_3,eta_3,phi_3,m_3);

        if (Wsign=="plus" and !((mymu1.Pt()>mymu2.Pt() && q_1>0) or (mymu2.Pt()>mymu1.Pt() && q_2>0))) continue;
        if (Wsign=="minus" and !((mymu1.Pt()>mymu2.Pt() && q_1<0) or (mymu2.Pt()>mymu1.Pt() && q_2<0))) continue;

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
	if (!deepVLooseVSe_3 or !deepTightVSmu_3) continue;

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
          if (deepTightVSjet_3 && gen_match_2==5) aweight=aweight*fct_tauid->Eval(mytau.Pt());
          if (gen_match_3==1 or gen_match_3==3){ // VLoose VSe
             if (fabs(mytau.Eta())<1.448) aweight=aweight*1.22;
             else if (fabs(mytau.Eta())>1.558) aweight=aweight*1.13;
          }
          if (gen_match_3==2 or gen_match_3==4){ // Medium VSmu
             if (fabs(mytau.Eta())<0.4) aweight=aweight*0.978*1.442;
             else if (fabs(mytau.Eta())<0.8) aweight=aweight*1.003*0.941;
             else if (fabs(mytau.Eta())<1.2) aweight=aweight*0.992*1.288;
             else if (fabs(mytau.Eta())<1.7) aweight=aweight*1.003*1.054;
             else aweight=aweight*0.966*5.341;
          }
          wmc->var("m_pt")->setVal(mymu1.Pt());
          wmc->var("m_eta")->setVal(mymu1.Eta());
          wmc->var("m_iso")->setVal(iso_1);
          aweight=aweight*wmc->function("m_trk_ratio")->getVal();
          aweight=aweight*wmc->function("m_idiso_ic_ratio")->getVal();
          float sftrg1=wmc->function("m_trg_ic_ratio")->getVal();
          /*float sftrg2=wmc->function("m_trg_19_ic_ratio")->getVal();
          wmc->var("t_pt")->setVal(mytau.Pt());
          wmc->var("t_eta")->setVal(mytau.Eta());
          wmc->var("t_phi")->setVal(mytau.Phi());
          wmc->var("t_dm")->setVal(l3_decayMode);
          sftrg2=sftrg2*wmc->function("t_trg_pog_deeptau_medium_mutau_ratio")->getVal();*/
          wmc->var("m_pt")->setVal(mymu2.Pt());
          wmc->var("m_eta")->setVal(mymu2.Eta());
          wmc->var("m_iso")->setVal(iso_2);
          aweight=aweight*wmc->function("m_trk_ratio")->getVal();
          aweight=aweight*wmc->function("m_idiso_ic_ratio")->getVal();
	  aweight=aweight*sftrg1;
          aweight=aweight*prefiring_weight;
          aweight=aweight*bweight;
        }
        if (year==2017 and sample!="data_obs"){
          aweight=aweight*aMCatNLO_weight*weight*LumiWeights_12->weight(npu);
          if (deepTightVSjet_3 && gen_match_2==5) aweight=aweight*fct_tauid->Eval(mytau.Pt());
          if (gen_match_3==1 or gen_match_3==3){ // VLoose VSe
             if (fabs(mytau.Eta())<1.460) aweight=aweight*0.93;
             else if (fabs(mytau.Eta())>1.558) aweight=aweight*1.00;
          }
          if (gen_match_3==2 or gen_match_3==4){ // Medium VSmu
             if (fabs(mytau.Eta())<0.4) aweight=aweight*0.979*1.062;
             else if (fabs(mytau.Eta())<0.8) aweight=aweight*0.953*0.819;
             else if (fabs(mytau.Eta())<1.2) aweight=aweight*0.983*0.819;
             else if (fabs(mytau.Eta())<1.7) aweight=aweight*0.988*1.021;
             else aweight=aweight*1.004*4.235;
          }
          wmc->var("m_pt")->setVal(mymu1.Pt());
          wmc->var("m_eta")->setVal(mymu1.Eta());
          wmc->var("m_iso")->setVal(iso_1);
          aweight=aweight*wmc->function("m_trk_ratio")->getVal();
          aweight=aweight*wmc->function("m_idiso_ic_ratio")->getVal();
          float sftrg1=wmc->function("m_trg_ic_ratio")->getVal();
          wmc->var("m_pt")->setVal(mymu2.Pt());
          wmc->var("m_eta")->setVal(mymu2.Eta());
          wmc->var("m_iso")->setVal(iso_2);
          aweight=aweight*wmc->function("m_trk_ratio")->getVal();
          aweight=aweight*wmc->function("m_idiso_ic_ratio")->getVal();
          /*float sftrg2=wmc->function("m_trg_ic_ratio")->getVal();
          if (trigger1 && trigger2) aweight=aweight*(1-((1-sftrg1)*(1-sftrg2)));
          else if (trigger1 && !trigger2) aweight=aweight*sftrg1;
          else if (!trigger1 && trigger2) aweight=aweight*sftrg2;*/
	  aweight=aweight*sftrg1;
          aweight=aweight*prefiring_weight;
          aweight=aweight*bweight;
        }
        if (year==2018 and sample!="data_obs"){
          aweight=aweight*aMCatNLO_weight*weight*LumiWeights_12->weight(npu);
          if (deepTightVSjet_3 && gen_match_2==5) aweight=aweight*fct_tauid->Eval(mytau.Pt());
          if (gen_match_3==1 or gen_match_3==3){ // VLoose VSe
             if (fabs(mytau.Eta())<1.448) aweight=aweight*0.95;
             else if (fabs(mytau.Eta())>1.558) aweight=aweight*0.86;
          }
          if (gen_match_3==2 or gen_match_3==4){ // Medium VSmu
             if (fabs(mytau.Eta())<0.4) aweight=aweight*0.978*1.463;
             else if (fabs(mytau.Eta())<0.8) aweight=aweight*1.003*0.722;
             else if (fabs(mytau.Eta())<1.2) aweight=aweight*0.992*1.337;
             else if (fabs(mytau.Eta())<1.7) aweight=aweight*1.003*0.966;
             else aweight=aweight*0.966*5.451;
          }
          wmc->var("m_pt")->setVal(mymu1.Pt());
          wmc->var("m_eta")->setVal(mymu1.Eta());
          wmc->var("m_iso")->setVal(iso_1);
          aweight=aweight*wmc->function("m_trk_ratio")->getVal();
          aweight=aweight*wmc->function("m_idiso_ic_ratio")->getVal();
          float sftrg1=wmc->function("m_trg_ic_ratio")->getVal();
          wmc->var("m_pt")->setVal(mymu2.Pt());
          wmc->var("m_eta")->setVal(mymu2.Eta());
          wmc->var("m_iso")->setVal(iso_2);
          aweight=aweight*wmc->function("m_trk_ratio")->getVal();
          aweight=aweight*wmc->function("m_idiso_ic_ratio")->getVal();
          /*float sftrg2=wmc->function("m_trg_ic_ratio")->getVal();
          if (trigger1 && trigger2) aweight=aweight*(1-((1-sftrg1)*(1-sftrg2)));
          else if (trigger1 && !trigger2) aweight=aweight*sftrg1;
          else if (!trigger1 && trigger2) aweight=aweight*sftrg2;*/
	  aweight=aweight*sftrg1;
          aweight=aweight*bweight;
	}

	// Btag veto and scale factors
	if (nbtag>0) continue;

	// Definition of signal and anti-isolated regions

	float signalRegion=muonID1 && muonID2 && deepVVVLooseVSjet_3 && deepTightVSjet_3 && deepVLooseVSe_3 && deepTightVSmu_3;
        float aiRegion=muonID1 && muonID2 && deepVVVLooseVSjet_3 && !deepTightVSjet_3 && deepVLooseVSe_3 && deepTightVSmu_3; 
        float ai0Region=muonID1 && !muonID2 && deepVVVLooseVSjet_3 && !deepTightVSjet_3 && deepVLooseVSe_3 && deepTightVSmu_3;
        float ai1Region=muonID1 && !muonID2 && deepVVVLooseVSjet_3 && deepTightVSjet_3 && deepVLooseVSe_3 && deepTightVSmu_3;
        float ai2Region=muonID1 && muonID2 && deepVVVLooseVSjet_3 && !deepTightVSjet_3 && deepVLooseVSe_3 && deepTightVSmu_3;

	if (sample=="data_obs") aweight=1.0;

	// Store objects for the future iterations
        TLorentzVector myrawmet;
        myrawmet.SetPtEtaPhiM(met,0,metphi,0);
	TLorentzVector myrawmu1=mymu1;
        TLorentzVector myrawmu2=mymu2;
        TLorentzVector myrawtau=mytau;

	for (int k=0; k<nbhist; ++k){

	    float weight2=1.0;
	    TLorentzVector mymet=myrawmet;
	    mymu1=myrawmu1;
	    mymu2=myrawmu2;
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
              if (k>20 && k<27){ // MES x 6 
                if (k==21 && fabs(mymu1.Eta())<1.2){mymu1*=0.996; mymet=mymet-mymu1+myrawmu1;}
                else if (k==22 && fabs(mymu1.Eta())<1.2){mymu1*=1.004; mymet=mymet-mymu1+myrawmu1;}
                else if (k==23 && fabs(mymu1.Eta())>1.2 && fabs(mymu1.Eta())<2.1){mymu1*=0.993; mymet=mymet-mymu1+myrawmu1;}
                else if (k==24 && fabs(mymu1.Eta())>1.2 && fabs(mymu1.Eta())<2.1){mymu1*=1.007; mymet=mymet-mymu1+myrawmu1;}
                else if (k==25 && fabs(mymu1.Eta())>2.1){mymu1*=0.973; mymet=mymet-mymu1+myrawmu1;}
                else if (k==26 && fabs(mymu1.Eta())>2.1){mymu1*=1.027; mymet=mymet-mymu1+myrawmu1;}
                if (k==21 && fabs(mymu2.Eta())<1.2){mymu2*=0.996; mymet=mymet-mymu2+myrawmu2;}
                else if (k==22 && fabs(mymu2.Eta())<1.2){mymu2*=1.004; mymet=mymet-mymu2+myrawmu2;}
                else if (k==23 && fabs(mymu2.Eta())>1.2 && fabs(mymu2.Eta())<2.1){mymu2*=0.993; mymet=mymet-mymu2+myrawmu2;}
                else if (k==24 && fabs(mymu2.Eta())>1.2 && fabs(mymu2.Eta())<2.1){mymu2*=1.007; mymet=mymet-mymu2+myrawmu2;}
                else if (k==25 && fabs(mymu2.Eta())>2.1){mymu2*=0.973; mymet=mymet-mymu2+myrawmu2;}
                else if (k==26 && fabs(mymu2.Eta())>2.1){mymu2*=1.027; mymet=mymet-mymu2+myrawmu2;}
              }
              if (k>26 && k<29){ // prefiring x 2
                if (k==27) {weight2=prefiring_weight_down/(prefiring_weight+0.00000001);}
                else if (k==28) {weight2=prefiring_weight_up/(prefiring_weight+0.00000001);}
              }
              else if (k>28 && k<31){ // muR muF scale x 2
                if (k==29) weight2=lheweight_nominalTo0p5_average*(lheweight_muR0p5_muF0p5/lheweight_nominal);
                else if (k==30) weight2=lheweight_nominalTo2_average*(lheweight_muR2_muF2/lheweight_nominal);
              }
              else if (k>30 && k<33){ // qqVH reweighting x 2
                if (k==31) weight2=ratio_nlo_down;
                else if (k==32) weight2=ratio_nlo_up;
              }

            }

	    if (mytau.Pt()<20) continue; // Can be as low as 20 GeV

            if (year==2016){
                trigger1=((passMu22eta2p1 && matchMu22eta2p1_1 && filterMu22eta2p1_1 && mymu1.Pt()>23 && fabs(eta_1)<2.1) or (passTkMu22eta2p1 && matchTkMu22eta2p1_1 && filterTkMu22eta2p1_1 && mymu1.Pt()>23 && fabs(eta_1)<2.1) or (passMu22 && matchMu22_1 && filterMu22_1 && mymu1.Pt()>23 && fabs(eta_1)<2.1) or (passTkMu22 && matchTkMu22_1 && filterTkMu22_1 && mymu1.Pt()>23 && fabs(eta_1)<2.1));
		//trigger2=((passMu19Tau20 && filterMu19Tau20_1 && mymu1.Pt()>20 && mymu1.Pt()<23 && filterMu19Tau20_3 && mytau.Pt()>25 && fabs(eta_3)<2.1) or (passMu19Tau20SingleL1 && matchMu19Tau20SingleL1_1 && mymu1.Pt()>20 && mymu1.Pt()<23 && matchMu19Tau20SingleL1_3 && filterMu19Tau20SingleL1_3 && mytau.Pt()>25 && fabs(eta_3)<2.1));
            }
            if (year==2017){
               trigger1=((passMu24 && matchMu24_1 && filterMu24_1 && mymu1.Pt()>25 && fabs(eta_1)<2.1) or (passMu27 && matchMu27_1 && filterMu27_1 && mymu1.Pt()>25 && fabs(eta_1)<2.1));
            }
            if (year==2018){
               trigger1=((passMu24 && matchMu24_1 && filterMu24_1 && mymu1.Pt()>25 && fabs(eta_1)<2.1) or (passMu27 && matchMu27_1 && filterMu27_1 && mymu1.Pt()>25 && fabs(eta_1)<2.1));
            }
            if (!trigger1 && !trigger2) continue;


            if (sample=="data_obs") {aweight=1.0; weight2=1.0;}

            float fr=1.0;
            float frm2=1.0;

            fr=GetTauFR(mytau.Pt(),l3_decayMode,g_taufr_dm0T,g_taufr_dm1T,g_taufr_dm10T,g_taufr_dm11T,0);
            frm2=GetMuFR(mymu2.Pt(),g_mufr,0);

	    if (k>32 && k<89){
               fr=GetTauFR(mytau.Pt(),l3_decayMode,g_taufr_dm0T,g_taufr_dm1T,g_taufr_dm10T,g_taufr_dm11T,k-32);
	    }
	    if (k>88 && k<99){
	       frm2=GetMuFR(mymu2.Pt(),g_mufr,k-88);
	    }
            if (k==99) frm2=GetMuFR(mymu2.Pt(),g_mufr_sub09,0);
            if (k==100) frm2=GetMuFR(mymu2.Pt(),g_mufr_sub11,0);

	    float wfr=fr/(1-fr);
            float wfrm=frm2/(1-frm2);
            float wfrt=fr/(1-fr);

	    bool selection =true;

	    if (mymu2.Pt()<15) continue;

            float deta=fabs(mymu1.Eta()-(mymu2+mytau).Eta());
            float dphi=fabs(mymu1.DeltaPhi(mymu2+mytau));
            bool selection_low =!((mymu1.Pt()+mymu2.Pt()+mytau.Pt()>=100) && deta<2.0 && dphi>2.0);
            bool selection_high =(mymu1.Pt()+mymu2.Pt()+mytau.Pt()>=100) && deta<2.0 && dphi>2.0;
	    selection_high =deta<2.0 && dphi>2.0;

            //************************* Fill histograms **********************

            // The mass of the subleading lepton and of the tau is the observable
            float var=(mymu2+mytau).M();
            float varSS=var;
            float charge2=q_2;
            if (mymu2.Pt()>mymu1.Pt()){
                charge2=q_1;
	    }
            float factor=0.69;
            TLorentzVector metFromHiggs=(mymu2+mytau)*factor;
            float ptv=(mymu1+mymet-metFromHiggs).Pt();
            var=(1.0+factor)*(mymu2+mytau).M();
            if (mymu2.Pt()>mymu1.Pt()){
                metFromHiggs=(mymu1+mytau)*factor;
                ptv=(mymu2+mymet-metFromHiggs).Pt();
                var=(1.0+factor)*(mymu1+mytau).M();
            }
	    float controlvar=ptv;

	    if (selection_high){
                if (signalRegion && q_2*q_3<0){
                    h0_OS[k]->Fill(ptv,var,weight2*aweight);
	  	}
                if (signalRegion && fabs(q_1+q_2+q_3)==3)
                    h0_SS[k]->Fill(controlvar,weight2*aweight);
	  	if (q_2*q_3<0 && aiRegion)
                    h0_AIOS[k]->Fill(ptv,var,weight2*aweight*wfr);
                if (aiRegion && fabs(q_1+q_2+q_3)==3)
                    h0_AISS[k]->Fill(controlvar,weight2*aweight*wfr);
                if (q_2*q_3<0 && ai0Region)
                    h0_AI0OS[k]->Fill(ptv,var,weight2*aweight*wfrt*wfrm);
                if (ai0Region && fabs(q_1+q_2+q_3)==3)
                    h0_AI0SS[k]->Fill(controlvar,weight2*aweight*wfrt*wfrm);
                if (q_2*q_3<0 && ai1Region)
                    h0_AI1OS[k]->Fill(ptv,var,weight2*aweight*wfrm);
                if (ai1Region && fabs(q_1+q_2+q_3)==3)
                    h0_AI1SS[k]->Fill(controlvar,weight2*aweight*wfrm);
                if (q_2*q_3<0 && ai2Region)
                    h0_AI2OS[k]->Fill(ptv,var,weight2*aweight*wfrt);
                if (ai2Region && fabs(q_1+q_2+q_3)==3)
                    h0_AI2SS[k]->Fill(controlvar,weight2*aweight*wfrt);
	    }
            if (selection_low){
                if (signalRegion && q_2*q_3<0)
                    h1_OS[k]->Fill(controlvar,weight2*aweight);
                if (signalRegion && q_2*q_3>0)
                    h1_SS[k]->Fill(controlvar,weight2*aweight);
                if (q_2*q_3<0 && aiRegion)
                    h1_AIOS[k]->Fill(controlvar,weight2*aweight*wfr);
                if (q_2*q_3>0 && aiRegion)
                    h1_AISS[k]->Fill(controlvar,weight2*aweight*wfr);
                if (q_2*q_3<0 && ai0Region)
                    h1_AI0OS[k]->Fill(controlvar,weight2*aweight*wfrt*wfrm);
                if (q_2*q_3>0 && ai0Region)
                    h1_AI0SS[k]->Fill(controlvar,weight2*aweight*wfrt*wfrm);
                if (q_2*q_3<0 && ai1Region)
                    h1_AI1OS[k]->Fill(controlvar,weight2*aweight*wfrm);
                if (q_2*q_3>0 && ai1Region)
                    h1_AI1SS[k]->Fill(controlvar,weight2*aweight*wfrm);
                if (q_2*q_3<0 && ai2Region)
                    h1_AI2OS[k]->Fill(controlvar,weight2*aweight*wfrt);
                if (q_2*q_3>0 && ai2Region)
                    h1_AI2SS[k]->Fill(controlvar,weight2*aweight*wfrt);
            }
	}
				
    } // end of loop over events


    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();

    TString postfix="";

    TDirectory *OS =fout->mkdir("mmt_high");
    TDirectory *SS =fout->mkdir("mmt_highSS");
    TDirectory *OS1 =fout->mkdir("mmt_low");
    TDirectory *SS1 =fout->mkdir("mmt_lowSS");
    TDirectory *AIOS =fout->mkdir("AIOS");
    TDirectory *AISS =fout->mkdir("AISS");
    TDirectory *AI0OS =fout->mkdir("AI0OS");
    TDirectory *AI0SS =fout->mkdir("AI0SS");
    TDirectory *AI1OS =fout->mkdir("AI1OS");
    TDirectory *AI1SS =fout->mkdir("AI1SS");
    TDirectory *AI2OS =fout->mkdir("AI2OS");
    TDirectory *AI2SS =fout->mkdir("AI2SS");
    TDirectory *AIOS1 =fout->mkdir("AIOS1");
    TDirectory *AISS1 =fout->mkdir("AISS1");
    TDirectory *AI0OS1 =fout->mkdir("AI0OS1");
    TDirectory *AI0SS1 =fout->mkdir("AI0SS1");
    TDirectory *AI1OS1 =fout->mkdir("AI1OS1");
    TDirectory *AI1SS1 =fout->mkdir("AI1SS1");
    TDirectory *AI2OS1 =fout->mkdir("AI2OS1");
    TDirectory *AI2SS1 =fout->mkdir("AI2SS1");

    for (int k=0; k<nbhist; ++k){

       if (k<33) postfix=postfixTES[k];
       if (k>=33) postfix=postfixFake[k-33];

       OS->cd();
       h0_OS[k]->SetName(name.c_str()+postfix);
       h0_OS[k]->Write();
cout<<k<<" "<<h0_OS[k]->Integral()<<" "<<postfix<<endl;
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
//cout<<k<<" "<<h0_AI1OS[k]->Integral()<<" "<<postfix<<endl;
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
} 


