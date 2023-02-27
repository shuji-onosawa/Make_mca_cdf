import cdflib
import numpy as np


def compare_cdf_files(input_cdf_name, compared_cdf_name):

    created_xary = cdflib.cdf_to_xarray(input_cdf_name)
    existing_xary = cdflib.cdf_to_xarray(compared_cdf_name)

    # compair these xarray
    flag = np.allclose(created_xary.to_array(), existing_xary.to_array())
    return flag


with open("../execute/compare_8scdf_files.txt", "w") as f:
    for date in ['0201', '0202', '0203', '0204', '0205', '0206', '0207', '0208', '0209', '0210',
                '0211', '0212', '0213', '0214', '0215', '0216', '0217', '0218', '0219', '0220',
                '0221', '0222', '0223', '0224', '0225', '0226', '0227', '0228']:

        createdcdf_name = '../data/CDF-H1_test1/1990/ak_h1_mca_1990' + date + '_v02.cdf'
        existingcdf_name = '../data/CDF-H1_provided_by_Kasahara/ak_h1_mca_1990' + date + '_v02.cdf'
        print(date)
        f.write(date+'\n')
        try:
            flag = compare_cdf_files(createdcdf_name, existingcdf_name)
            f.write('same file:'+str(flag)+'\n')
        except Exception as e:
            f.write(str(e)+'\n')
