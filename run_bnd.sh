<< README
このシェルスクリプトを実行するには、以下の手順を実行します。
onosawa/data/CDF-H0/ ディレクトリとonosawa/data/CDF-H1 ディレクトリがあることを確認
なければ作成
CDF-H0内にYYYYディレクトリを作成し、その中にak_h0_mca_YYYYMMDD_v01.cdfファイルをおく

Make_mca_cdf ディレクトリに移動します。

このファイル内のyearとmonthを作成したい年と月に変更します。
このファイル内のtimeResolutionを作成したい時間分解能に変更します。

./onosawa/mca_ave/average.h 内のCRNAMEを作成したcdfファイルの保存先にします。
保存先のパスはMake_mca_cdfディレクトリからのパスにします。
CRNAMEとsave_directoryの $year の前までは同じにします。
1日のcdfファイルを作成する場合は、dayを指定し、Single versionで実行します。(Loop versionはコメントアウトしてください。)
1ヶ月のcdfファイルを作成する場合は、Loop versionで実行します。(Single versionはコメントアウトしてください。)

シェルスクリプトを実行するには、以下のコマンドを実行します:
./run_bnd.sh
もし以下のように実行した場合make clean を実行します。
./run_bnd.sh clean


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
year="1989"
month="3"
timeResolution="0.5"
# make directory whose name is $year in CDF-H1
save_directory="./onosawa/data/CDF-H1/$year"
if [ ! -d $save_directory ]; then  # if directory does not exist, make directory
  mkdir $save_directory
fi

# Run bnd
# SINGLE_VERSION
day='1'
$source_directory/bnd $year $month $day $timeResolution

# LOOP_VERSION
# Loop through each day of the month
# if [ "$month" == "2" ]; then
#   for day in {1..28}
#   do
#     options="$year $month"
#     options+=" $day $timeResolution"
#     $source_directory/bnd $options
#   done
# elif [ "$month" == "4" ] || [ "$month" == "6" ] || [ "$month" == "9" ] || [ "$month" == "11" ]; then
#   for day in {1..30}
#   do
#     options="$year $month"
#     options+=" $day $timeResolution"
#     $source_directory/bnd $options
#   done
# else
#   for day in {1..31}
#   do
#     options="$year $month"
#     options+=" $day $timeResolution"
#     $source_directory/bnd $options
#   done
# fi
