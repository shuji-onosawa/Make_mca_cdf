<< README
このシェルスクリプトを実行するには、以下の手順を実行します。

Make_mca_cdf ディレクトリに移動します。

./onosawa/mca_ave/average.h 内のCRNAMEを作成したcdfファイルの保存先にします。
保存先のパスはMake_mca_cdfディレクトリからのパスにします。
YYYY年のファイルを作成する場合は、CRNAMEの下にYYYYディレクトリを作成します。
CRNAMEとsave_directoryの $year の前までは同じにします。

シェルスクリプトを実行するには、以下のコマンドを実行します:
./run_bnd.sh
もし以下のように実行した場合make clean を実行します。
./run_bnd.sh clean
optionsはオプションです。必ずこのファイル内で入力してください。書き方は./onosawa/mca_ave/READMEを参照してください。


README

# Add path for shared library
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.venv/cdf38_1-dist/src/lib

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

# Define year, month, and options
year="1990"
month="3"
options="$year $month"

# Loop through each day in March 1989
for day in {1..31}
do
  options="$year $month"
  options+=" $day 0.5"
  $source_directory/bnd $options
done
