#include "cdf.h"
CDFid id;
CDFstatus status;
long dataType, numElements;

status = CDFopen ("filename.cdf", &id);
if (status < CDF_OK) QuitCDF ("1.0", status);

status = CDFinquire(id, CDF_EPOCH0_TYPE, &dataType, &numElements);
if (status < CDF_OK) QuitCDF ("1.1", status);

if (dataType == CDF_EPOCH) {
    printf("CDF_EPOCH\n");
} else if (dataType == CDF_EPOCH16) {
    printf("CDF_EPOCH16\n");
}

status = CDFclose (id);
if (status < CDF_OK) QuitCDF ("1.2", status);