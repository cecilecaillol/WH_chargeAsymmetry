./Make.sh FinalSelection2D_ett.cc

./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/Data.root files_nominal_ett_2016/Data.root data_obs data_obs all 2016 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/WZ3LNu.root files_nominal_ett_2016/WZLLLNu.root WZLLLNu WZ all 2016 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/ZZ4L.root files_nominal_ett_2016/ZZ4L.root ZZ4L ZZ all 2016 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/GGZZ2e2mu.root files_nominal_ett_2016/GGZZ2e2mu.root GGZZ2e2mu ZZ all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/GGZZ2mu2tau.root files_nominal_ett_2016/GGZZ2mu2tau.root GGZZ2mu2tau ZZ all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/GGZZ2e2tau.root files_nominal_ett_2016/GGZZ2e2tau.root GGZZ2e2tau ZZ all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/GGZZ4e.root files_nominal_ett_2016/GGZZ4e.root GGZZ4e ZZ all 2016 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/GGZZ4mu.root files_nominal_ett_2016/GGZZ4mu.root GGZZ4mu ZZ all 2016 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/GGZZ4tau.root files_nominal_ett_2016/GGZZ4tau.root GGZZ4tau ZZ 02016 
hadd -f files_nominal_ett_2016/VV.root files_nominal_ett_2016/WZLLLNu.root files_nominal_ett_2016/ZZ4L.root files_nominal_ett_2016/GGZZ2e2mu.root files_nominal_ett_2016/GGZZ2mu2tau.root files_nominal_ett_2016/GGZZ2e2tau.root files_nominal_ett_2016/GGZZ4e.root files_nominal_ett_2016/GGZZ4mu.root files_nominal_ett_2016/GGZZ4tau.root
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/WWW.root files_nominal_ett_2016/WWW.root WWW TriBoson all 2016 
#./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/WWZ.root files_nominal_ett_2016/WWZ.root WWZ TriBoson all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/WZZ.root files_nominal_ett_2016/WZZ.root WZZ TriBoson all 2016 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/ZZZ.root files_nominal_ett_2016/ZZZ.root ZZZ TriBoson all 2016 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/TTZ.root files_nominal_ett_2016/ttZ.root ttZ TTV all 2016 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/TTW.root files_nominal_ett_2016/ttW.root ttW TTV all 2016 
hadd -f files_nominal_ett_2016/VVV.root files_nominal_ett_2016/WWW.root files_nominal_ett_2016/WZZ.root files_nominal_ett_2016/ZZZ.root files_nominal_ett_2016/ttZ.root files_nominal_ett_2016/ttW.root 

./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/WminusHTT.root files_nominal_ett_2016/WminusH125.root WminusH125 WH_lep_htt125 all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/WplusHTT.root files_nominal_ett_2016/WplusH125.root WplusH125 WH_lep_htt125 all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/ZHTT.root files_nominal_ett_2016/ZH125.root ZH125 ZH_lep_htt125 all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/GGZHLLTT.root files_nominal_ett_2016/GGZHLLTT.root GGZHLLTT ggZH_lep_htt125 all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/WminusHWW.root files_nominal_ett_2016/WminusHWW.root WminusHWW WH_lep_hww125 all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/WplusHWW.root files_nominal_ett_2016/WplusHWW.root WplusHWW WH_lep_hww125 all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/ZHWW.root files_nominal_ett_2016/ZHWW.root ZHWW ZH_lep_hww125 all 2016
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2016_20jul/GGZHWW.root files_nominal_ett_2016/GGZHWW.root GGZHWW ZH_lep_hww125 all 2016
hadd -f files_nominal_ett_2016/Higgs.root files_nominal_ett_2016/WminusH125.root files_nominal_ett_2016/WplusH125.root files_nominal_ett_2016/ZH125.root files_nominal_ett_2016/GGZHLLTT.root files_nominal_ett_2016/ZHWW.root files_nominal_ett_2016/GGZHWW.root files_nominal_ett_2016/WminusHWW.root files_nominal_ett_2016/WplusHWW.root 

python Create_fake_ett.py --year 2016
sh do_rivet_ett_2016.sh
sh do_hwwrivet_ett_2016.sh

hadd -f wh_ett_2016_2D.root files_nominal_ett_2016/Data.root files_nominal_ett_2016/VV.root files_nominal_ett_2016/VVV.root files_nominal_ett_2016/Fake_nominal.root files_nominal_ett_2016/Higgs.root files_nominal_ett_2016/rivet_ZHlep.root files_nominal_ett_2016/rivet_WHlep.root files_nominal_ett_2016/GGZHLLTT_rivet125.root files_nominal_ett_2016/rivet_ZHWWlep.root files_nominal_ett_2016/rivet_WHWWlep.root files_nominal_ett_2016/GGZHWW_rivet125.root
python Create_1D.py --year 2016 --channel ett

python PlotSingleChannel.py --fs ett2016
