import cdflib
import numpy as np
import sys
with open("../execute/compare_8scdf_files.txt", "w") as f:
    sys.stdout = f
    for date in ['0201', '0202', '0203', '0204', '0205', '0206', '0207', '0208', '0209', '0210',
                '0211', '0212', '0213', '0214', '0215', '0216', '0217', '0218', '0219', '0220',
                '0221', '0222', '0223', '0224', '0225', '0226', '0227', '0228']:
        
        createdcdf_name = '../CDF-H1_test/1990/ak_h1_mca_1990' + date + '_v02.cdf'
        existingcdf_name = '/Document/Akebono_analysis/VLF_mca/Akebono_MCA_data/ak_h1_mca_1990' + date + '_v02.cdf'
        
        createdcdf_name = existingcdf_name
        # convert cdf to xarray
        try:
            created_xary = cdflib.cdf_to_xarray(createdcdf_name)
            existing_xary = cdflib.cdf_to_xarray(existingcdf_name)
        except:
            print('error')
            continue

        # compair these xarray
        flag = np.allclose(created_xary.to_array(), existing_xary.to_array())
        print(flag)
