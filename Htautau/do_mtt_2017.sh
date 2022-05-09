./Make.sh FinalSelection2D_mtt.cc

./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/Data.root files_nominal_mtt_2017/Data.root data_obs data_obs all 2017
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/WZ3LNu.root files_nominal_mtt_2017/WZ3LNu.root WZLLLNu WZ all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/ZZ4L.root files_nominal_mtt_2017/ZZ4L.root ZZ4L ZZ all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/GGZZ4e.root files_nominal_mtt_2017/GGZZ4e.root GGZZ4e ZZ all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/GGZZ4mu.root files_nominal_mtt_2017/GGZZ4mu.root GGZZ4mu ZZ all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/GGZZ4tau.root files_nominal_mtt_2017/GGZZ4tau.root GGZZ4tau ZZ all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/GGZZ2e2mu.root files_nominal_mtt_2017/GGZZ2e2mu.root GGZZ2e2mu ZZ all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/GGZZ2e2tau.root files_nominal_mtt_2017/GGZZ2e2tau.root GGZZ2e2tau ZZ all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/GGZZ2mu2tau.root files_nominal_mtt_2017/GGZZ2mu2tau.root GGZZ2mu2tau ZZ all 2017 
hadd -f files_nominal_mtt_2017/VV.root files_nominal_mtt_2017/WZ3LNu.root files_nominal_mtt_2017/ZZ4L.root files_nominal_mtt_2017/GGZZ4e.root files_nominal_mtt_2017/GGZZ4mu.root files_nominal_mtt_2017/GGZZ4tau.root files_nominal_mtt_2017/GGZZ2e2mu.root files_nominal_mtt_2017/GGZZ2e2tau.root files_nominal_mtt_2017/GGZZ2mu2tau.root
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/TTZ.root files_nominal_mtt_2017/TTZ.root ttZ TTV all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/TTW.root files_nominal_mtt_2017/TTW.root ttW TTV all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/WWW.root files_nominal_mtt_2017/WWW.root WWW TriBoson all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/WWZ.root files_nominal_mtt_2017/WWZ.root WWZ TriBoson all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/WZZ.root files_nominal_mtt_2017/WZZ.root WZZ TriBoson all 2017 
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/ZZZ.root files_nominal_mtt_2017/ZZZ.root ZZZ TriBoson all 2017 
hadd -f files_nominal_mtt_2017/Rare.root files_nominal_mtt_2017/WWW.root files_nominal_mtt_2017/WZZ.root files_nominal_mtt_2017/ZZZ.root files_nominal_mtt_2017/WWZ.root files_nominal_mtt_2017/TTZ.root files_nominal_mtt_2017/TTW.root 

./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/WminusHTT.root files_nominal_mtt_2017/WminusH125.root WminusH125 WH_lep_htt125 all 2017
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/WplusHTT.root files_nominal_mtt_2017/WplusH125.root WplusH125 WH_lep_htt125 all 2017
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/ZHTT.root files_nominal_mtt_2017/ZH125.root ZH125 ZH_lep_htt125 all 2017
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/GGZHLLTT.root files_nominal_mtt_2017/GGZHLLTT.root GGZHLLTT ggZH_lep_htt125 all 2017
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/WminusHWW.root files_nominal_mtt_2017/WminusHWW.root WminusHWW WH_lep_hww125 all 2017
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/WplusHWW.root files_nominal_mtt_2017/WplusHWW.root WplusHWW WH_lep_hww125 all 2017
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/ZHWW.root files_nominal_mtt_2017/ZHWW.root ZHWW ZH_lep_hww125 all 2017
./FinalSelection2D_mtt.exe /eos/cms/store/cmst3/user/ccaillol/whmtt2017_20jul/GGZHWW.root files_nominal_mtt_2017/GGZHWW.root GGZHWW ZH_lep_hww125 all 2017
hadd -f files_nominal_mtt_2017/Higgs.root files_nominal_mtt_2017/WminusH125.root files_nominal_mtt_2017/WplusH125.root files_nominal_mtt_2017/ZH125.root files_nominal_mtt_2017/GGZHLLTT.root files_nominal_mtt_2017/ZHWW.root files_nominal_mtt_2017/GGZHWW.root files_nominal_mtt_2017/WminusHWW.root files_nominal_mtt_2017/WplusHWW.root

sh do_rivet_mtt_2017.sh
sh do_hwwrivet_mtt_2017.sh

python Create_fake.py --year 2017

hadd -f wh_mtt_2017_2D.root files_nominal_mtt_2017/Data.root files_nominal_mtt_2017/VV.root files_nominal_mtt_2017/Higgs.root files_nominal_mtt_2017/Fake_nominal.root files_nominal_mtt_2017/Rare.root files_nominal_mtt_2017/rivet_ZHlep.root files_nominal_mtt_2017/rivet_WHlep.root files_nominal_mtt_2017/GGZHLLTT_rivet125.root files_nominal_mtt_2017/rivet_ZHWWlep.root files_nominal_mtt_2017/rivet_WHWWlep.root files_nominal_mtt_2017/GGZHWW_rivet125.root

python Create_1D.py --year 2017 --channel mtt

python PlotSingleChannel.py --fs mtt2017
