import cdflib
import numpy as np


def compare_cdf_files(input_cdf_name, compared_cdf_name):

    created_xary = cdflib.cdf_to_xarray(input_cdf_name)
    existing_xary = cdflib.cdf_to_xarray(compared_cdf_name)

    # compair these xarray
    flag = np.allclose(created_xary.to_array(), existing_xary.to_array())
    return flag
