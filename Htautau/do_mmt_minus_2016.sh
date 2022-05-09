mkdir -p files_nominal_mmt_2016
./Make.sh FinalSelection2D_mmt.cc
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/Data.root files_nominal_mmt_2016/Data.root data_obs data_obs minus 2016 
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/WZ3LNu.root files_nominal_mmt_2016/WZ3LNu.root WZ3LNu WZ minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/ZZ4L.root files_nominal_mmt_2016/ZZ4L.root ZZ4L ZZ minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/GGZZ4e.root files_nominal_mmt_2016/GGZZ4e.root GGZZ4e ZZ minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/GGZZ4mu.root files_nominal_mmt_2016/GGZZ4mu.root GGZZ4mu ZZ minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/GGZZ4tau.root files_nominal_mmt_2016/GGZZ4tau.root GGZZ4tau ZZ minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/GGZZ2e2mu.root files_nominal_mmt_2016/GGZZ2e2mu.root GGZZ2e2mu ZZ minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/GGZZ2e2tau.root files_nominal_mmt_2016/GGZZ2e2tau.root GGZZ2e2tau ZZ minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/GGZZ2mu2tau.root files_nominal_mmt_2016/GGZZ2mu2tau.root GGZZ2mu2tau ZZ minus 2016
hadd -f files_nominal_mmt_2016/VV.root files_nominal_mmt_2016/ZZ4L.root files_nominal_mmt_2016/WZ3LNu.root files_nominal_mmt_2016/GGZZ4e.root files_nominal_mmt_2016/GGZZ4mu.root files_nominal_mmt_2016/GGZZ4tau.root files_nominal_mmt_2016/GGZZ2e2mu.root files_nominal_mmt_2016/GGZZ2e2tau.root files_nominal_mmt_2016/GGZZ2mu2tau.root

./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/TTZ.root files_nominal_mmt_2016/TTZ.root ttZ TTV minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/TTW.root files_nominal_mmt_2016/TTW.root ttW TTV minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/WWW.root files_nominal_mmt_2016/WWW.root WWW TriBoson minus 2016
#./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/WWZ.root files_nominal_mmt_2016/WWZ.root WWZ TriBoson minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/WZZ.root files_nominal_mmt_2016/WZZ.root WZZ TriBoson minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/ZZZ.root files_nominal_mmt_2016/ZZZ.root ZZZ TriBoson minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/TTToSemiLeptonic.root files_nominal_mmt_2016/TTToSemiLeptonic.root TTToSemiLeptonic TT minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/TTToSemiLeptonic.root files_nominal_mmt_2016/TTTo2L2Nu.root TTTo2L2Nu TT minus 2016
hadd -f files_nominal_mmt_2016/Rare.root files_nominal_mmt_2016/WWW.root files_nominal_mmt_2016/WZZ.root files_nominal_mmt_2016/ZZZ.root files_nominal_mmt_2016/TTToSemiLeptonic.root files_nominal_mmt_2016/TTTo2L2Nu.root files_nominal_mmt_2016/TTZ.root files_nominal_mmt_2016/TTW.root 

./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/WminusHTT.root files_nominal_mmt_2016/WminusH125.root WminusH125 WminusH_htt125 minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/WplusHTT.root files_nominal_mmt_2016/WplusH125.root WplusH125 WplusH_htt125 minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/ZHTT.root files_nominal_mmt_2016/ZH125.root ZH125 ZH_htt125 minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/GGZHLLTT.root files_nominal_mmt_2016/GGZHLLTT.root GGZHLLTT ggZH_htt125 minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/WminusHWW.root files_nominal_mmt_2016/WminusHWW.root WminusHWW WminusH_hww125 minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/WplusHWW.root files_nominal_mmt_2016/WplusHWW.root WplusHWW WplusH_hww125 minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/ZHWW.root files_nominal_mmt_2016/ZHWW.root ZHWW ZH_hww125 minus 2016
./FinalSelection2D_mmt.exe /eos/cms/store/cmst3/user/ccaillol/whmmt2016_20jul/GGZHWW.root files_nominal_mmt_2016/GGZHWW.root GGZHWW ggZH_hww125 minus 2016
hadd -f files_nominal_mmt_2016/Higgs.root files_nominal_mmt_2016/WminusH125.root files_nominal_mmt_2016/WplusH125.root files_nominal_mmt_2016/ZH125.root files_nominal_mmt_2016/GGZHLLTT.root files_nominal_mmt_2016/ZHWW.root files_nominal_mmt_2016/GGZHWW.root files_nominal_mmt_2016/WminusHWW.root files_nominal_mmt_2016/WplusHWW.root

python Create_fake_mmt.py --year 2016

hadd -f wh_mmt_2016_2D.root files_nominal_mmt_2016/Data.root files_nominal_mmt_2016/VV.root files_nominal_mmt_2016/Fake_nominal.root files_nominal_mmt_2016/Rare.root files_nominal_mmt_2016/Higgs.root 
python Create_1D.py --year 2016 --channel mmt --Wsign minus


