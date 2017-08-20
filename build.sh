#!/usr/bin/env bash
# build deb package
if [ $# -lt 1 ]; then
    echo "error.. need args"
    exit 1
fi
echo "commond is $0"
echo "args are:"
for arg in "$@"
do
echo $arg
done
cd ..
# remove top deb and tar.gz file
if [ -d "*.deb" ]; then
rm *.deb
fi
if [ -d "*.tar.gz" ]; then
rm *.tar.gz
fi
project=shadowsocks-client
dir="$project-$1"
if [ -d "$dir" ]; then
echo "remove dir $dir"
rm -r $dir
fi
mkdir $dir
filelist=`ls $project`
# copy file to dir except build and bak
for file in $filelist
do
if [ $file = "cmake-build-debug" ]; then
    echo "ignore"
    continue
fi
if [[ $file = "debian.bak" ]]; then
    echo "ignore"
    continue
fi
cp -rp $project/$file $dir/
done
echo "copy done"
# begin build
tar -cvzf "$dir.tar.gz" $dir
cd $dir
dh_make -f "../$dir.tar.gz" -c gpl3 -s -y
filelist=`ls ../$project/debian.bak`
for file in $filelist
do
target_file="debian/$file"
echo $file,$target_file
if [ -d "$target_file" ]; then
    rm $target_file
fi
cp ../$project/debian.bak/$file $target_file
echo "copy $file"
done
dpkg-buildpackage -us -uc -b
echo "done"