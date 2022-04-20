cd build
rm -rf *
cmake .. -DCMAKE_VERBOSE_MAKEFILE=ON
make V=1
./cppDemo