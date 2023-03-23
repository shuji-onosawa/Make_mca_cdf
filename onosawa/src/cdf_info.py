import cdflib
import csv


def write_cdf_info(cdf_template, output_file):

    # CDFファイルの日付を変更する
    dates = ['0201', '0202', '0203', '0204', '0205', '0206', '0207', '0208',
             '0209', '0210', '0211', '0212', '0213', '0214', '0215', '0216',
             '0217', '0218', '0219', '0220', '0221', '0222', '0223', '0224',
             '0225', '0226', '0227', '0228']

    # CSVファイルを開く
    with open("../execute/"+output_file, "w", newline="") as f:
        writer = csv.writer(f)

        for date in dates:
            # CDFファイルを開く
            cdf_name = cdf_template.format(date)
            cdf_file = cdflib.CDF(cdf_name)

            # 変数名のリストを取得する
            variable_names = cdf_file._get_varnames()

            if date == '0201':
                # グローバル属性を記入
                dict_cdf_globalattr = cdf_file.globalattsget()
                for key, value in dict_cdf_globalattr.items():
                    writer.writerow([key, value])
                writer.writerow('\n')
                # ヘッダーを記入
                header = ['date'] + variable_names[1]
                writer.writerow(header)

            # 各変数について処理する
            var_size_list = []
            for name in variable_names[1]:
                # 変数を読み込む
                variable = cdf_file.varget(name)
                var_size_list += [variable.shape]
                # 日付、変数名、要素数を出力する
            writer.writerow([date] + var_size_list)

            # CDFファイルを閉じる
            cdf_file.close()


# write_cdf_info(cdf_template='/home/onosawa/Document/Make_mca_cdf/onosawa/data/CDF-H1_provided_by_Kasahara/ak_h1_mca_1990{}_v02.cdf',
#                output_file='h1cdf_info.csv')

# write_cdf_info(cdf_template='/home/onosawa/Document/Make_mca_cdf/onosawa/data/CDF-H0/1990/ak_h0_mca_1990{}_v01.cdf',
#                output_file='h0cdf_info.csv')

write_cdf_info(cdf_template='../data/CDF-H1_ave1s/1990/ak_h1_mca_1990{}_v02.cdf',
               output_file='created_h1cdf_info_ave1s.csv')
