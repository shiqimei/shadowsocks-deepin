# remove build directory
if [ -d "build" ]; then
rm build -rf
fi

# create new build directory
mkdir build && cd build

# install cmake if not it install yet
if [ ! -f "/usr/bin/cmake" ]; then
echo -e "\033[31mError: cmake is not installed!"
exit 1
fi

# compile
cmake .. && make -j4
cd src
./shadowsocks-deepin