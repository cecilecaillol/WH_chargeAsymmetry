# WH charge asymmetry measurement

##1. Documentation

Theory paper about constraining light quark Yukawa couplings from WH charge asymmetry: https://arxiv.org/abs/1609.06592

Legacy WH Htautau analysis: HIG-19-010, AN-2020-089

CombineHarvester: http://cms-analysis.github.io/CombineHarvester/

Combine: http://cms-analysis.github.io/HiggsAnalysis-CombinedLimit/

##2. Installation

To do only the first time. The next times, just type "cmsenv" in the project area to set up the CMS environment.

```
mkdir MySummerStudentProject
export SCRAM_ARCH=slc7_amd64_gcc700
cmsrel CMSSW_10_2_13
cd CMSSW_10_2_13/src
cmsenv
git clone https://github.com/cms-analysis/HiggsAnalysis-CombinedLimit.git HiggsAnalysis/CombinedLimit
git clone https://github.com/cms-analysis/CombineHarvester.git CombineHarvester
scram b
git clone https://github.com/cecilecaillol/WH_chargeAsymmetry.git
```

##3. H to tau tau

Run a single year/final state/charge configuration, e.g. mu+tauh+tauh, W plus, 2018:

```
sh do_mtt_plus_2018.sh
```

Run everything to make the final datacard:

```
sh do_charge_analysis.sh
```

##4. Combination
