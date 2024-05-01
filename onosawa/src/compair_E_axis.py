# CDF-H0ディレクトリとCDF_H1_testディレクトリにある同じ日のそれぞれのCDFファイルのE_axis変数の値を比較する。
# 横軸を時刻、縦軸をE_axis(unicode文字列)を10を基数とした数値に変換したものとして、それぞれのCDFファイルのE_axisの値をプロットする。

import cdflib
import matplotlib.pyplot as plt

# CDFファイルの読み込み. xarray.datasetに変換
date = '19900201'
xry_h0 = cdflib.cdf_to_xarray('../data/CDF-H0/1990/ak_h0_mca_'+date+'_v01.cdf')
xry_h1 = cdflib.cdf_to_xarray('../data/CDF-H1_test/1990/ak_h1_mca_'+date+'_v02.cdf')

# H0データの前処理
h0Epoch = xry_h0['Epoch'].values
h0E_axis = xry_h0['E_axis'].values
# 変数Epochと変数E_axisの配列の長さがそろっているか確認。そろっていない場合は、短い方に合わせる。
if len(h0Epoch) > len(h0E_axis):
    h0Epoch = h0Epoch[:len(h0E_axis)]
elif len(h0Epoch) < len(h0E_axis):
    h0E_axis = h0E_axis[:len(h0Epoch)]
# Epochのうち、負の値を持つ要素を削除。除外した要素のインデックスを取得。E_axisの対応する要素も削除。
index = h0Epoch < 0
h0Epoch = h0Epoch[~index]
h0E_axis = h0E_axis[~index]
# Epochの値をdatetime型に変換
h0EpochDataTime = cdflib.cdfepoch.to_datetime(h0Epoch)
#E_axis(unicode文字列)の値を10進数に変換
h0E_axis_int = [ord(unicodeStr) for unicodeStr in h0E_axis]

# H1データの前処理
h1Epoch = xry_h1['Epoch'].values
h1E_axis = xry_h1['E_axis'].values
# Epochの値をdatetime型に変換
h1EpochDataTime = cdflib.cdfepoch.to_datetime(h1Epoch)
#E_axisの値を10進数に変換
h1E_axis_int = [ord(unicodeStr) for unicodeStr in h1E_axis]

# プロット
plt.figure(figsize=(10, 10))
plt.scatter(h0EpochDataTime, h0E_axis_int, label='H0')
plt.scatter(h1EpochDataTime, h1E_axis_int, label='H1')
plt.xlabel('Time')
plt.ylabel('E_axis')
plt.legend()
plt.show()