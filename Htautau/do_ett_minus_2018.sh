./Make.sh FinalSelection2D_ett.cc

./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/Data.root files_nominal_ett_2018/Data.root data_obs data_obs minus 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WZ3LNu.root files_nominal_ett_2018/WZLLLNu.root WZLLLNu WZ minus 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/ZZ4L.root files_nominal_ett_2018/ZZ4L.root ZZ4L ZZ minus 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ2e2mu.root files_nominal_ett_2018/GGZZ2e2mu.root GGZZ2e2mu ZZ minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ2mu2tau.root files_nominal_ett_2018/GGZZ2mu2tau.root GGZZ2mu2tau ZZ minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ2e2tau.root files_nominal_ett_2018/GGZZ2e2tau.root GGZZ2e2tau ZZ minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ4e.root files_nominal_ett_2018/GGZZ4e.root GGZZ4e ZZ minus 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ4mu.root files_nominal_ett_2018/GGZZ4mu.root GGZZ4mu ZZ minus 2018 
#./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZZ4tau.root files_nominal_ett_2018/GGZZ4tau.root GGZZ4tau ZZ 02018 
hadd -f files_nominal_ett_2018/VV.root files_nominal_ett_2018/WZLLLNu.root files_nominal_ett_2018/ZZ4L.root files_nominal_ett_2018/GGZZ2e2mu.root files_nominal_ett_2018/GGZZ2mu2tau.root files_nominal_ett_2018/GGZZ2e2tau.root files_nominal_ett_2018/GGZZ4e.root files_nominal_ett_2018/GGZZ4mu.root #files_nominal_ett_2018/GGZZ4tau.root
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WWW.root files_nominal_ett_2018/WWW.root WWW TriBoson minus 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WWZ.root files_nominal_ett_2018/WWZ.root WWZ TriBoson minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WZZ.root files_nominal_ett_2018/WZZ.root WZZ TriBoson minus 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/ZZZ.root files_nominal_ett_2018/ZZZ.root ZZZ TriBoson minus 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/TTZ.root files_nominal_ett_2018/ttZ.root ttZ TTV minus 2018 
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/TTW.root files_nominal_ett_2018/ttW.root ttW TTV minus 2018 
hadd -f files_nominal_ett_2018/VVV.root files_nominal_ett_2018/WWW.root files_nominal_ett_2018/WZZ.root files_nominal_ett_2018/ZZZ.root files_nominal_ett_2018/ttZ.root files_nominal_ett_2018/ttW.root files_nominal_ett_2018/WWZ.root

./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WminusHTT.root files_nominal_ett_2018/WminusH125.root WminusH125 WminusH_htt125 minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WplusHTT.root files_nominal_ett_2018/WplusH125.root WplusH125 WplusH_htt125 minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/ZHTT.root files_nominal_ett_2018/ZH125.root ZH125 ZH_htt125 minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZHLLTT.root files_nominal_ett_2018/GGZHLLTT.root GGZHLLTT ggZH_htt125 minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WminusHWW.root files_nominal_ett_2018/WminusHWW.root WminusHWW WminusH_hww125 minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/WplusHWW.root files_nominal_ett_2018/WplusHWW.root WplusHWW WplusH_hww125 minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/ZHWW.root files_nominal_ett_2018/ZHWW.root ZHWW ZH_hww125 minus 2018
./FinalSelection2D_ett.exe /eos/cms/store/cmst3/user/ccaillol/whett2018_20jul/GGZHWW.root files_nominal_ett_2018/GGZHWW.root GGZHWW ggZH_hww125 minus 2018
hadd -f files_nominal_ett_2018/Higgs.root files_nominal_ett_2018/WminusH125.root files_nominal_ett_2018/WplusH125.root files_nominal_ett_2018/ZH125.root files_nominal_ett_2018/GGZHLLTT.root files_nominal_ett_2018/ZHWW.root files_nominal_ett_2018/GGZHWW.root files_nominal_ett_2018/WminusHWW.root files_nominal_ett_2018/WplusHWW.root

python Create_fake_ett.py --year 2018

hadd -f wh_ett_2018_2D.root files_nominal_ett_2018/Data.root files_nominal_ett_2018/VV.root files_nominal_ett_2018/VVV.root files_nominal_ett_2018/Fake_nominal.root files_nominal_ett_2018/Higgs.root 
python Create_1D.py --year 2018 --channel ett --Wsign minus

