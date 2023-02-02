
# Add path for shared library
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cdf/lib/

# Specify directory path
source_directory="./onosawa/mca_ave"

# Compile source files
make clean -C $source_directory
make -C $source_directory

# Remove compiled object files and executable
if [ "$1" == "clean" ]; then
make clean -C $source_directory
exit 0
fi

# Run the executable with options
options="1990 2 4 8"
$source_directory/bnd $options
