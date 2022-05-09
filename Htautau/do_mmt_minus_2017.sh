./Make.sh FinalSelection2D_mmt.cc
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/Data.root files_nominal_mmt_2017/Data.root data_obs data_obs minus 2017 
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/WZ3LNu.root files_nominal_mmt_2017/WZ3LNu.root WZ3LNu WZ minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/ZZ4L.root files_nominal_mmt_2017/ZZ4L.root ZZ4L ZZ minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/GGZZ4e.root files_nominal_mmt_2017/GGZZ4e.root GGZZ4e ZZ minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/GGZZ4mu.root files_nominal_mmt_2017/GGZZ4mu.root GGZZ4mu ZZ minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/GGZZ4tau.root files_nominal_mmt_2017/GGZZ4tau.root GGZZ4tau ZZ minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/GGZZ2e2mu.root files_nominal_mmt_2017/GGZZ2e2mu.root GGZZ2e2mu ZZ minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/GGZZ2e2tau.root files_nominal_mmt_2017/GGZZ2e2tau.root GGZZ2e2tau ZZ minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/GGZZ2mu2tau.root files_nominal_mmt_2017/GGZZ2mu2tau.root GGZZ2mu2tau ZZ minus 2017
hadd -f files_nominal_mmt_2017/VV.root files_nominal_mmt_2017/ZZ4L.root files_nominal_mmt_2017/WZ3LNu.root files_nominal_mmt_2017/GGZZ4e.root files_nominal_mmt_2017/GGZZ4mu.root files_nominal_mmt_2017/GGZZ4tau.root files_nominal_mmt_2017/GGZZ2e2mu.root files_nominal_mmt_2017/GGZZ2e2tau.root files_nominal_mmt_2017/GGZZ2mu2tau.root
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/TTZ.root files_nominal_mmt_2017/TTZ.root ttZ TTV minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/TTW.root files_nominal_mmt_2017/TTW.root ttW TTV minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/WWW.root files_nominal_mmt_2017/WWW.root WWW TriBoson minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/WWZ.root files_nominal_mmt_2017/WWZ.root WWZ TriBoson minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/WZZ.root files_nominal_mmt_2017/WZZ.root WZZ TriBoson minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/ZZZ.root files_nominal_mmt_2017/ZZZ.root ZZZ TriBoson minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/TTToSemiLeptonic.root files_nominal_mmt_2017/TTToSemiLeptonic.root TTToSemiLeptonic TT minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/TTTo2L2Nu.root files_nominal_mmt_2017/TTTo2L2Nu.root TTTo2L2Nu TT minus 2017
hadd -f files_nominal_mmt_2017/Rare.root files_nominal_mmt_2017/WWW.root files_nominal_mmt_2017/WZZ.root files_nominal_mmt_2017/ZZZ.root files_nominal_mmt_2017/WWZ.root files_nominal_mmt_2017/TTZ.root files_nominal_mmt_2017/TTW.root files_nominal_mmt_2017/TTToSemiLeptonic.root files_nominal_mmt_2017/TTTo2L2Nu.root 

./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/WminusHTT.root files_nominal_mmt_2017/WminusH125.root WminusH125 WminusH_htt125 minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/WplusHTT.root files_nominal_mmt_2017/WplusH125.root WplusH125 WplusH_htt125 minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/ZHTT.root files_nominal_mmt_2017/ZH125.root ZH125 ZH_htt125 minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/GGZHLLTT.root files_nominal_mmt_2017/GGZHLLTT.root GGZHLLTT ggZH_htt125 minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/WminusHWW.root files_nominal_mmt_2017/WminusHWW.root WminusHWW WminusH_hww125 minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/WplusHWW.root files_nominal_mmt_2017/WplusHWW.root WplusHWW WplusH_hww125 minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/ZHWW.root files_nominal_mmt_2017/ZHWW.root ZHWW ZH_hww125 minus 2017
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2017_20jul/GGZHWW.root files_nominal_mmt_2017/GGZHWW.root GGZHWW ggZH_hww125 minus 2017
hadd -f files_nominal_mmt_2017/Higgs.root files_nominal_mmt_2017/WminusH125.root files_nominal_mmt_2017/WplusH125.root files_nominal_mmt_2017/ZH125.root files_nominal_mmt_2017/GGZHLLTT.root files_nominal_mmt_2017/ZHWW.root files_nominal_mmt_2017/GGZHWW.root files_nominal_mmt_2017/WminusHWW.root files_nominal_mmt_2017/WplusHWW.root

python Create_fake_mmt.py --year 2017

hadd -f wh_mmt_2017_2D.root files_nominal_mmt_2017/Data.root files_nominal_mmt_2017/VV.root files_nominal_mmt_2017/Fake_nominal.root files_nominal_mmt_2017/Rare.root files_nominal_mmt_2017/Higgs.root 
python Create_1D.py --year 2017 --channel mmt --Wsign minus


