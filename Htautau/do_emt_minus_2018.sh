./Make.sh FinalSelection2D_emt.cc
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/SingleMuon.root files_nominal_emt_2018/SingleMuon.root SingleMuon data_obs minus 2018
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/SingleElectron.root files_nominal_emt_2018/SingleElectron.root SingleElectron data_obs minus 2018
hadd -f files_nominal_emt_2018/Data.root files_nominal_emt_2018/SingleMuon.root files_nominal_emt_2018/SingleElectron.root 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/WZ3LNu.root files_nominal_emt_2018/WZLLLNu.root WZ3LNu_powheg WZ minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/ZZ4L.root files_nominal_emt_2018/ZZ4L.root ZZ4L_powheg ZZ minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/GGZZ4e.root files_nominal_emt_2018/GGZZ4e.root GGZZ4e ZZ minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/GGZZ4mu.root files_nominal_emt_2018/GGZZ4mu.root GGZZ4mu ZZ minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/GGZZ4tau.root files_nominal_emt_2018/GGZZ4tau.root GGZZ4tau ZZ minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/GGZZ2e2mu.root files_nominal_emt_2018/GGZZ2e2mu.root GGZZ2e2mu ZZ minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/GGZZ2e2tau.root files_nominal_emt_2018/GGZZ2e2tau.root GGZZ2e2tau ZZ minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/GGZZ2mu2tau.root files_nominal_emt_2018/GGZZ2mu2tau.root GGZZ2mu2tau ZZ minus 2018 
hadd -f files_nominal_emt_2018/VV.root files_nominal_emt_2018/WZLLLNu.root files_nominal_emt_2018/ZZ4L.root files_nominal_emt_2018/GGZZ4e.root files_nominal_emt_2018/GGZZ4mu.root files_nominal_emt_2018/GGZZ4tau.root files_nominal_emt_2018/GGZZ2e2mu.root files_nominal_emt_2018/GGZZ2e2tau.root files_nominal_emt_2018/GGZZ2mu2tau.root
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/TTZ.root files_nominal_emt_2018/TTZ.root ttZ TTV minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/TTW.root files_nominal_emt_2018/TTW.root ttW TTV minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/WWW.root files_nominal_emt_2018/WWW.root WWW TriBoson minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/WWZ.root files_nominal_emt_2018/WWZ.root WWZ TriBoson minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/WZZ.root files_nominal_emt_2018/WZZ.root WZZ TriBoson minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/ZZZ.root files_nominal_emt_2018/ZZZ.root ZZZ TriBoson minus 2018 
hadd -f files_nominal_emt_2018/Rare.root files_nominal_emt_2018/WWW.root files_nominal_emt_2018/WZZ.root files_nominal_emt_2018/ZZZ.root files_nominal_emt_2018/WWZ.root files_nominal_emt_2018/TTZ.root files_nominal_emt_2018/TTW.root 

./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/WminusHTT.root files_nominal_emt_2018/WminusH125.root WminusH125 WminusH_htt125 minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/WplusHTT.root files_nominal_emt_2018/WplusH125.root WplusH125 WplusH_htt125 minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/ZHTT.root files_nominal_emt_2018/ZH125.root ZH125 ZH_htt125 minus 2018 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/GGZHLLTT.root files_nominal_emt_2018/GGZHLLTT.root GGZHLLTT ggZH_htt125 minus 2018
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/WminusHWW.root files_nominal_emt_2018/WminusHWW.root WminusHWW WminusH_hww125 minus 2018
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/WplusHWW.root files_nominal_emt_2018/WplusHWW.root WplusHWW WplusH_hww125 minus 2018
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/ZHWW.root files_nominal_emt_2018/ZHWW.root ZHWW ZH_hww125 minus 2018
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2018_20jul/GGZHWW.root files_nominal_emt_2018/GGZHWW.root GGZHWW ggZH_hww125 minus 2018
hadd -f files_nominal_emt_2018/Higgs.root files_nominal_emt_2018/WminusH125.root files_nominal_emt_2018/WplusH125.root files_nominal_emt_2018/ZH125.root files_nominal_emt_2018/GGZHLLTT.root files_nominal_emt_2018/ZHWW.root files_nominal_emt_2018/GGZHWW.root files_nominal_emt_2018/WminusHWW.root files_nominal_emt_2018/WplusHWW.root 

python Create_fake_emt.py --year 2018


hadd -f wh_emt_2018_2D.root files_nominal_emt_2018/Data.root files_nominal_emt_2018/VV.root files_nominal_emt_2018/Fake_nominal.root files_nominal_emt_2018/Rare.root files_nominal_emt_2018/Higgs.root 
python Create_1D.py --year 2018 --channel emt --Wsign minus


