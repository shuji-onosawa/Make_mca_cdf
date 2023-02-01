<< README
このシェルスクリプトを実行するには、以下の手順を実行します。

シェルスクリプトを実行するためのパーミッションを設定します。以下のコマンドを実行します:
chmod +x run_bnd.sh

シェルスクリプトを実行するには、以下のコマンドを実行します:
./run_bnd.sh
optionsはオプションです。必ず入力してください。書き方は./onosawa/mca_ave/READMEを参照してください。
README

# Add path for shared library
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cdf/lib/

# Change directory to where the source files are located
cd ./onosawa/mca_ave

# Compile source files
make

# Run the executable with options
options="2008 2 1 8"
./bnd $options
