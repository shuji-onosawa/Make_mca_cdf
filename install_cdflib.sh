#!/bin/bash

# CDF library version
cdf_version="cdf38_1-dist"

# Download CDF library and extract it
vertualenv_dir=".venv"
if [ ! -d "$vertualenv_dir/$cdf_version" ]; then
    echo "Downloading CDF library..."
    curl -O https://spdf.gsfc.nasa.gov/pub/software/cdf/dist/cdf38_1/cdf38_1-dist-all.tar.gz
    echo "Extracting CDF library..."
    tar -xzf cdf38_1-dist-all.tar.gz
    rm cdf38_1-dist-all.tar.gz
    mv cdf38_1-dist .venv/
fi

# Install CDF library
echo "Installing CDF library..."
cd ".venv/$cdf_version"
make OS=linux ENV=gnu all
sudo make install

# Return to the root directory
cd ../../
