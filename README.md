# make_cdf

## Environment for C programs
- gcc version 11.3.0 (Ubuntu 11.3.0-1ubuntu1~22.04)
- CDF Sowtware Distribution Version 3.8.1

## Environment for Python programs
- Python version 3.10.6
- Library: cdflib, pytplot

## How to set up the environment
- make vertual environment. The name of the environment is "venv". If you want to change the name, please change the name in ./onosawa/mca_ave/Makefile and run_bnd.sh.
At Make_mca_cdf directory, run the following command.
```
$ python3 -m venv .venv
```
- activate the environment
```
$ source .venv/bin/activate
```
- install python libraries
```
$ python3 -m pip install -r requirement.txt
```
- install CDF distribution
```
$ source install_cdflib.sh
```

## How to run the program
The H0 version of the spectral data observed by VLF/MCA is divided by day and stored in cdf. Follow the procedure below to create the H1 version cdf for yyyymmdd.
- If there are not the directories "./onosawa/data/CDF-H0" and "./onosawa/data/CDF-H1", make them.
These directories are used to store the H0 and H1 version cdf files, respectively.
cf. the part of "定数宣言" in ./onosawa/mca_ave/average.h.
- Make directory "./onosawa/data/CDF-H0/yyyy/" and store the H0 version cdf files("ak_h0_mca_yyyymmdd_v01.cdf") in it.
- Read README in run_bnd.sh and set parameters: year, month, day.
- Run the following command.
```
$ ./run_bnd.sh
```
