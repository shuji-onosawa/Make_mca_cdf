# MCA(Multi Channel Analyser) data property

## Time resolution
- 0.5 s (Bit rate Hのとき) or 0.25（Bit rate Mのとき）

## Component
- 電場
  - 1成分。スピン面内の2本のワイヤアンテナのうちいずれか1本で計測されたもの
  - スピン軸は 2.5度以内の精度で太陽を向いている


# MCA cdf データの構造
メモ書き。詳しくは同じフォルダにある尾崎さん卒論を参照。
## cdf 一般の話
- 時刻データ
    - CDF_EPOCH, CDF_EPOCH16, CDF_TIME_TT2000という3タイプがある。
        - CDF_EPOCH: 西暦0年から1ミリ秒単位で数えた時刻, float in python　→　MCA cdfではこれ
        - CDF_EPOCH16: 西暦0年から1ピコ秒単位で数えた時刻, complex in python
        - CDF_TIME_TT2000: よくわからん
    - そのまま```pyspedas.time_string(epoch)```とかやっても正しい時刻に直らない。→```cdflib.cdfepoch.breakdown(epoch)```で年月日時分秒に直せる。

## 生データ(h0cdf)
- 1日1file
- レコードはスパースレコードとして保存されている
- スパースレコード(Sparse record)とは
    - 「Sparse record」とは、データが頻繁に存在しない属性（フィールド）を含むレコードのことを指します。このようなレコードでは、多くのフィールドが「空」または「null」の値を持つことがあります。Sparse recordは、データベースやデータストレージシステムで使用すると効率的な利用ができる場合があります。

- ~~Emax, Eave, Bmax, Bave, E_WIDA, B_WIDA, E_axis, channel 変数はデータ欠損部分はその直前の値で埋めるようになっていると尾崎さん卒論にはあるが、そうだとすると長さがそろっていないのはなぜ？~~
- 長さが短いのは単純にその日の終わり付近で観測データがないから
    - 残りの部分はデータなしだと思って埋めればよい
    - mca_ave.cで平均する際は↑の処理はプログラムに含まれている



## 平均データ(h1cdf)
- 1日1file
- ../mca_ave/内のプログラム作成されたh1cdfファイルの中にはpytplot.cdf_to_tplot()でtplot変数にできないファイルがある。
    - それらの日のh0cdfでは  
    Epochが入った配列, PostGapが入った配列 の長さ > その他の変数が入った配列の長さ