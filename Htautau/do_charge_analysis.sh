sh do_emt_plus_2016.sh
sh do_emt_minus_2016.sh
sh do_mmt_plus_2016.sh
sh do_mmt_minus_2016.sh
sh do_ett_plus_2016.sh
sh do_ett_minus_2016.sh
sh do_mtt_plus_2016.sh
sh do_mtt_minus_2016.sh

sh do_emt_plus_2017.sh
sh do_emt_minus_2017.sh
sh do_mmt_plus_2017.sh
sh do_mmt_minus_2017.sh
sh do_ett_plus_2017.sh
sh do_ett_minus_2017.sh
sh do_mtt_plus_2017.sh
sh do_mtt_minus_2017.sh

sh do_emt_plus_2018.sh
sh do_emt_minus_2018.sh
sh do_mmt_plus_2018.sh
sh do_mmt_minus_2018.sh
sh do_ett_plus_2018.sh
sh do_ett_minus_2018.sh
sh do_mtt_plus_2018.sh
sh do_mtt_minus_2018.sh

hadd -f whcharge_2016.root wh_emtminus_2016.root wh_emtplus_2016.root wh_mmtminus_2016.root wh_mmtplus_2016.root wh_ettminus_2016.root wh_ettplus_2016.root wh_mttminus_2016.root wh_mttplus_2016.root 
hadd -f whcharge_2017.root wh_emtminus_2017.root wh_emtplus_2017.root wh_mmtminus_2017.root wh_mmtplus_2017.root wh_ettminus_2017.root wh_ettplus_2017.root wh_mttminus_2017.root wh_mttplus_2017.root
hadd -f whcharge_2018.root wh_emtminus_2018.root wh_emtplus_2018.root wh_mmtminus_2018.root wh_mmtplus_2018.root wh_ettminus_2018.root wh_ettplus_2018.root wh_mttminus_2018.root wh_mttplus_2018.root

