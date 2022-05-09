./Make.sh FinalSelection2D_emt.cc
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/SingleMuon.root files_nominal_emt_2016/SingleMuon.root SingleMuon data_obs plus 2016
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/SingleElectron.root files_nominal_emt_2016/SingleElectron.root SingleElectron data_obs plus 2016
hadd -f files_nominal_emt_2016/Data.root files_nominal_emt_2016/SingleMuon.root files_nominal_emt_2016/SingleElectron.root 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/WZ3LNu.root files_nominal_emt_2016/WZLLLNu.root WZ3LNu_powheg WZ plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/ZZ4L.root files_nominal_emt_2016/ZZ4L.root ZZ4L_powheg ZZ plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/GGZZ4e.root files_nominal_emt_2016/GGZZ4e.root GGZZ4e ZZ plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/GGZZ4mu.root files_nominal_emt_2016/GGZZ4mu.root GGZZ4mu ZZ plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/GGZZ4tau.root files_nominal_emt_2016/GGZZ4tau.root GGZZ4tau ZZ plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/GGZZ2e2mu.root files_nominal_emt_2016/GGZZ2e2mu.root GGZZ2e2mu ZZ plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/GGZZ2e2tau.root files_nominal_emt_2016/GGZZ2e2tau.root GGZZ2e2tau ZZ plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/GGZZ2mu2tau.root files_nominal_emt_2016/GGZZ2mu2tau.root GGZZ2mu2tau ZZ plus 2016 
hadd -f files_nominal_emt_2016/VV.root files_nominal_emt_2016/WZLLLNu.root files_nominal_emt_2016/ZZ4L.root files_nominal_emt_2016/GGZZ4e.root files_nominal_emt_2016/GGZZ4mu.root files_nominal_emt_2016/GGZZ4tau.root files_nominal_emt_2016/GGZZ2e2mu.root files_nominal_emt_2016/GGZZ2e2tau.root files_nominal_emt_2016/GGZZ2mu2tau.root
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/TTZ.root files_nominal_emt_2016/TTZ.root ttZ TTV plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/TTW.root files_nominal_emt_2016/TTW.root ttW TTV plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/WWW.root files_nominal_emt_2016/WWW.root WWW TriBoson plus 2016 
#./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/WWZ.root files_nominal_emt_2016/WWZ.root WWZ TriBoson plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/WZZ.root files_nominal_emt_2016/WZZ.root WZZ TriBoson plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/ZZZ.root files_nominal_emt_2016/ZZZ.root ZZZ TriBoson plus 2016 
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/TTTo2L2Nu.root files_nominal_emt_2016/TTTo2L2Nu.root TTTo2L2Nu TT plus 2016
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/TTToSemiLeptonic.root files_nominal_emt_2016/TTToSemiLeptonic.root TTToSemiLeptonic TT plus 2016
hadd -f files_nominal_emt_2016/Rare.root files_nominal_emt_2016/WWW.root files_nominal_emt_2016/WZZ.root files_nominal_emt_2016/ZZZ.root files_nominal_emt_2016/TTTo2L2Nu.root files_nominal_emt_2016/TTToSemiLeptonic.root files_nominal_emt_2016/TTZ.root files_nominal_emt_2016/TTW.root 

./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/WminusHTT.root files_nominal_emt_2016/WminusH125.root WminusH125 WminusH_htt125 plus 2016
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/WplusHTT.root files_nominal_emt_2016/WplusH125.root WplusH125 WplusH_htt125 plus 2016
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/ZHTT.root files_nominal_emt_2016/ZH125.root ZH125 ZH_htt125 plus 2016
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/GGZHLLTT.root files_nominal_emt_2016/GGZHLLTT.root GGZHLLTT ggZH_htt125 plus 2016
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/WminusHWW.root files_nominal_emt_2016/WminusHWW.root WminusHWW WminusH_hww125 plus 2016
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/WplusHWW.root files_nominal_emt_2016/WplusHWW.root WplusHWW WplusH_hww125 plus 2016
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/ZHWW.root files_nominal_emt_2016/ZHWW.root ZHWW ZH_hww125 plus 2016
./FinalSelection2D_emt.exe /eos/cms/store/cmst3/user/ccaillol/whemt2016_20jul/GGZHWW.root files_nominal_emt_2016/GGZHWW.root GGZHWW ggZH_hww125 plus 2016
hadd -f files_nominal_emt_2016/Higgs.root files_nominal_emt_2016/WminusH125.root files_nominal_emt_2016/WplusH125.root files_nominal_emt_2016/ZH125.root files_nominal_emt_2016/GGZHLLTT.root files_nominal_emt_2016/WminusHWW.root files_nominal_emt_2016/WplusHWW.root files_nominal_emt_2016/ZHWW.root files_nominal_emt_2016/GGZHWW.root

python Create_fake_emt.py --year 2016


hadd -f wh_emt_2016_2D.root files_nominal_emt_2016/Data.root files_nominal_emt_2016/VV.root files_nominal_emt_2016/Fake_nominal.root files_nominal_emt_2016/Rare.root files_nominal_emt_2016/Higgs.root
python Create_1D.py --year 2016 --channel emt --Wsign plus


