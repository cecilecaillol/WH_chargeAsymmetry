./Make.sh FinalSelection2D_ett.cc

./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/Data.root files_nominal_ett_2018/Data.root data_obs data_obs all 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WZ3LNu.root files_nominal_ett_2018/WZLLLNu.root WZLLLNu WZ all 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/ZZ4L.root files_nominal_ett_2018/ZZ4L.root ZZ4L ZZ all 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ2e2mu.root files_nominal_ett_2018/GGZZ2e2mu.root GGZZ2e2mu ZZ all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ2mu2tau.root files_nominal_ett_2018/GGZZ2mu2tau.root GGZZ2mu2tau ZZ all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ2e2tau.root files_nominal_ett_2018/GGZZ2e2tau.root GGZZ2e2tau ZZ all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ4e.root files_nominal_ett_2018/GGZZ4e.root GGZZ4e ZZ all 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ4mu.root files_nominal_ett_2018/GGZZ4mu.root GGZZ4mu ZZ all 2018 
#./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ4tau.root files_nominal_ett_2018/GGZZ4tau.root GGZZ4tau ZZ 02018 
hadd -f files_nominal_ett_2018/VV.root files_nominal_ett_2018/WZLLLNu.root files_nominal_ett_2018/ZZ4L.root files_nominal_ett_2018/GGZZ2e2mu.root files_nominal_ett_2018/GGZZ2mu2tau.root files_nominal_ett_2018/GGZZ2e2tau.root files_nominal_ett_2018/GGZZ4e.root files_nominal_ett_2018/GGZZ4mu.root #files_nominal_ett_2018/GGZZ4tau.root
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WWW.root files_nominal_ett_2018/WWW.root WWW TriBoson all 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WWZ.root files_nominal_ett_2018/WWZ.root WWZ TriBoson all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WZZ.root files_nominal_ett_2018/WZZ.root WZZ TriBoson all 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/ZZZ.root files_nominal_ett_2018/ZZZ.root ZZZ TriBoson all 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/TTZ.root files_nominal_ett_2018/ttZ.root ttZ TTV all 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/TTW.root files_nominal_ett_2018/ttW.root ttW TTV all 2018 
hadd -f files_nominal_ett_2018/VVV.root files_nominal_ett_2018/WWW.root files_nominal_ett_2018/WZZ.root files_nominal_ett_2018/ZZZ.root files_nominal_ett_2018/ttZ.root files_nominal_ett_2018/ttW.root files_nominal_ett_2018/WWZ.root

./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WminusHTT.root files_nominal_ett_2018/WminusH125.root WminusH125 WH_lep_htt125 all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WplusHTT.root files_nominal_ett_2018/WplusH125.root WplusH125 WH_lep_htt125 all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/ZHTT.root files_nominal_ett_2018/ZH125.root ZH125 ZH_lep_htt125 all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZHLLTT.root files_nominal_ett_2018/GGZHLLTT.root GGZHLLTT ggZH_lep_htt125 all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WminusHWW.root files_nominal_ett_2018/WminusHWW.root WminusHWW WH_lep_hww125 all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WplusHWW.root files_nominal_ett_2018/WplusHWW.root WplusHWW WH_lep_hww125 all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/ZHWW.root files_nominal_ett_2018/ZHWW.root ZHWW ZH_lep_hww125 all 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZHWW.root files_nominal_ett_2018/GGZHWW.root GGZHWW ZH_lep_hww125 all 2018
hadd -f files_nominal_ett_2018/Higgs.root files_nominal_ett_2018/WminusH125.root files_nominal_ett_2018/WplusH125.root files_nominal_ett_2018/ZH125.root files_nominal_ett_2018/GGZHLLTT.root files_nominal_ett_2018/ZHWW.root files_nominal_ett_2018/GGZHWW.root files_nominal_ett_2018/WminusHWW.root files_nominal_ett_2018/WplusHWW.root

python Create_fake_ett.py --year 2018
sh do_rivet_ett_2018.sh
sh do_hwwrivet_ett_2018.sh

hadd -f wh_ett_2018_2D.root files_nominal_ett_2018/Data.root files_nominal_ett_2018/VV.root files_nominal_ett_2018/VVV.root files_nominal_ett_2018/Fake_nominal.root files_nominal_ett_2018/Higgs.root files_nominal_ett_2018/rivet_ZHlep.root files_nominal_ett_2018/rivet_WHlep.root files_nominal_ett_2018/GGZHLLTT_rivet125.root files_nominal_ett_2018/rivet_ZHWWlep.root files_nominal_ett_2018/rivet_WHWWlep.root files_nominal_ett_2018/GGZHWW_rivet125.root
python Create_1D.py --year 2018 --channel ett

python PlotSingleChannel.py --fs ett2018
