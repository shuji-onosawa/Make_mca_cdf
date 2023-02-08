import cdflib
import sys

with open("../execute/existing_8s_ave_cdf_structure.txt", "w") as f:
    sys.stdout = f

    for date in ['0201', '0202', '0203', '0204', '0205', '0206', '0207', '0208', '0209', '0210',
                '0211', '0212', '0213', '0214', '0215', '0216', '0217', '0218', '0219', '0220',
                '0221', '0222', '0223', '0224', '0225', '0226', '0227', '0228']:

        print(date)
        cdf_folder_name = '/Document/Akebono_analysis/VLF_mca/Akebono_MCA_data'
        cdf_name = cdf_folder_name+'/ak_h1_mca_1990' + date + '_v02.cdf'
        x_array = cdflib.cdf_to_xarray(cdf_name)

        print(x_array)
