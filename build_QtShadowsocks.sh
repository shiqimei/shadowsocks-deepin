cd libQtShadowsocks
if [ -f "build" ]; then
    echo "remove folder build"
    rm -rf build
fi
if [ ! -d "build" ];then
    echo "make direction build"
      mkdir -p build
fi
if [ -d "build" ];then
echo "build文件夹存在"
    rm -rf build/*
else
echo "build文件夹不存在"
    mkdir build
fi
cd build
cmake -DBUILD_SHARED_LIBS=OFF ..
make QtShadowsocks