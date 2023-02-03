<< README
このシェルスクリプトを実行するには、以下の手順を実行します。

Make_mca_cdf ディレクトリに移動します。

シェルスクリプトを実行するためのパーミッションを設定します。以下のコマンドを実行します:
chmod +x run_bnd.sh

シェルスクリプトを実行するには、以下のコマンドを実行します:
./run_bnd.sh
もし以下のように実行した場合make clean を実行します。
./run_bnd.sh clean
optionsはオプションです。必ずこのファイル内で入力してください。書き方は./onosawa/mca_ave/READMEを参照してください。


README

# Add path for shared library
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cdf/lib/

# Specify directory path
source_directory="./onosawa/mca_ave"

# Compile source files
make clean -C $source_directory
make -C $source_directory

# Remove compiled object files and executable
if [ "$1" == "clean" ]; then
make clean -C $source_directory
exit 0
fi

# Run the executable with options
options="1990 2 2 8"
$source_directory/bnd $options
