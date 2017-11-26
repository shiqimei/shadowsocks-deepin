#!/usr/bin/env bash
echo '安装构建deb包的依赖'
sudo apt update
sudo apt install qt5-default qttools5-dev-tools -y
# sudo apt install libqtshadowsocks-dev -y
sudo apt install libssl-dev libbotan1.10-dev -y
sudo apt install libdtkbase-dev libdtkwidget-dev -y
sudo apt install libdframeworkdbus-dev -y
sudo apt install libqrencode-dev libzbar-dev -y
sudo apt install libdtkbase-dev libdtkcore-dev libdtksettings-dev libdtksettingsview-dev libdtkutil-dev libdtkwidget-dev libdtkwm-dev -y
sudo apt install dh-make fakeroot -y
echo '开始构建deb包'
./build.sh 1.1.0-alpha