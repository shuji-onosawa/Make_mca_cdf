import cdflib
import numpy as np
import math
import pandas as pd


def unit_vector(vector):
    """与えられたベクトルの単位ベクトルを計算する関数"""
    magnitude = np.linalg.norm(vector) # ベクトルの大きさを計算
    if magnitude == 0:
        return vector # ベクトルの大きさが0の場合はそのまま返す
    return vector / magnitude # ベクトルを大きさで除算して単位ベクトルを計算


def angle_between_vectors(u, v):
    """与えられた二つの単位ベクトルのなす角を計算する関数"""
    dot_product = np.dot(u, v) # 内積を計算
    angle = math.acos(np.clip(dot_product, -1.0, 1.0)) # 余弦から逆余弦を取得して角度を計算
    return np.degrees(angle) # ラジアンから度数に変換して返す


Ey_antenna_vector = np.array([-np.sin(np.deg2rad(35)),
                              np.cos(np.deg2rad(35)),
                              0])
sBy_antenna_vector = np.array([0.0, -1.0, 0.0])

date = '0201'
cdf_name = '../data/mgf_CDF-H0/ak_h0_mgf_19900201_v01.cdf'
mgf_xary = cdflib.cdf_to_xarray(cdf_name)


B0_ary = mgf_xary['B0_spin'].data
angle_btwn_B0_Ey = np.empty(B0_ary.shape[0])
angle_btwn_B0_sBy = np.empty(B0_ary.shape[0])

for i in range(B0_ary.shape[0]):
    B0_vector = np.array([B0_ary[i][0][7],
                          B0_ary[i][1][7],
                          B0_ary[i][2][7]])
    B0_unit_vector = unit_vector(B0_vector)
    angle_btwn_B0_Ey[i] = angle_between_vectors(B0_unit_vector, Ey_antenna_vector)
    angle_btwn_B0_sBy[i] = angle_between_vectors(B0_unit_vector, sBy_antenna_vector)

# CSVファイルに結果を出力
output_df = pd.DataFrame({'angle_btwn_B0_Ey': angle_btwn_B0_Ey,
                          'angle_btwn_B0_sBy': angle_btwn_B0_sBy})
output_df.to_csv('../execute/output.csv', index=False)

import matplotlib.pyplot as plt

fig, axs = plt.subplots()
plt.plot(np.arange(angle_btwn_B0_Ey.size), angle_btwn_B0_Ey)
