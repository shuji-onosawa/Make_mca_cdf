# MGF data created by Prof. Yoshiya Kasahara

- 32 Hz サンプリング
- CDFに入っている配列の構造
  - Epoch * 3 * 16 の配列
  - 衛星座標系でBx, By, Bz3成分
  - Epoch は同じ秒数のデータが2個ずつ連続してはいっている(../execute/date_time_list.txtを参照)
  - 1秒間にとった3成分の32個のデータを2つの3 * 16 の配列に分けて格納している。
- 笠原先生のほうでMGF単体のcdfを持っている。絶対強度補正はしていない。ベクトル推定だけに使う。
- B0_spin はスピン変調を取り除く前のデータ
  - 衛星座標系での背景磁場のベクトル推定に使える

- CDFのvaratiribute情報\
    Epoch
    (Epoch)
    float64
    0.0 0.0 ... 6.28e+13 6.28e+13\
    CATDESC : Time recorded in the original raw data\
    DICT_KEY : TIME > Epoch\
    FIELDNAM : Time since 0 AD\
    FILLVAL : [0.] # 使えないところは0で埋められている\
    LABLAXIS : Epoch\
    MONOTON : INCREASE\
    SCALETYP : linear\
    UNITS : s\
    VALIDMAX : [6.39344448e+13]\
    VALIDMIN : [6.27668352e+13]\
    VAR_TYPE : support_data\
    standard_name : Time since 0 AD\
    long_name : Epoch\
    units : s

    B0_spin
    (Epoch, dim0, dim1)
    float32
    -1e+31 -1e+31 ... 2.738e+03 \
    CATDESC : Magnetic field \
    DEPEND_0 : Epoch\
    DICT_KEY : MAGNETIC_FIELD > amplitude \
    DISPLAY_TYPE : time_series \
    FIELDNAM : Magnetic field \
    FILLVAL : [-1.e+31] \
    FORMAT : %.20f \
    LABL_PTR_1 : Label_B0_spin \
    UNITS : T \
    VALIDMAX : [0.01] \
    VALIDMIN : [-0.01] \
    VAR_TYPE : data \
    standard_name : Magnetic field \
    units : T 