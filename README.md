# Shadowsocks Client for Deepin
![](https://img.shields.io/badge/version-1.2.1-blue.svg)
![](https://img.shields.io/badge/license-GPLv3-green.svg)
[Click here to see English version](./doc/README.en.md)

深度影梭客户端：一款专门为Deepin打造的小飞机，您的贴心好帮手。

![](http://images.lolimay.cn/18-8-12/98452500.jpg)

与 Shadowsocks-Qt5 相比的优势

|软件|系统代理模式|易用性|
|:-:|:-:|:-:|
|Shadowsocks-Qt5|仅支持全局模式|需要手动配置系统代理或配置Chrome拓展|
|Shadowsocks Client|既支持全局模式也支持pac模式|无需任何配置

# 下载使用

<a href="http://file.lolimay.cn/shadowsocks-client_1.2.1_amd64.deb"><img src="http://images.lolimay.cn/18-8-9/78116321.jpg"/></a>

软件开箱即用，只要正确填写了你的服务器配置、选择好系统代理模式并启动系统代理后，小飞机即可起飞，**不需要手动配置系统代理，软件会自动修改系统代理配置**，在使用的过程中如遇到任何问题，欢迎提 [**issue**](https://github.com/loliMay/shadowsocks-client/issues/new)，我收到后会及时回复的。

也可以尝试自己将源码打包成deb包，下面给出打包方法:

1. [下载最新源码](https://github.com/loliMay/shadowsocks-client/archive/master.zip)
2. 解压得到`shadowsocks-client-1.2.1`文件夹
3. 在该目录下**打开终端**
````bash
cd shadowsocks-client-1.2.1
dh_make -f ../shadowsocks-client-1.2.1.tar.gz -c gpl3 -s
dpkg-buildpackage -us -uc -b
````
如果在`shadowsocks-client-1.2.1.tar.gz`同目录下出现deb包则说明打包成功

# 参与开发

开发这个软件用到的原理，请参考 [影梭客户端原理剖析](doc/影梭客户端原理剖析.md)

````
sudo apt update
sudo apt install qt5-default qttools5-dev-tools qt5-qmake g++ qtcreator -y
sudo apt install libdtkbase-dev libdtkwidget-dev -y
sudo apt install libdframeworkdbus-dev -y
sudo apt install libqrencode-dev libzbar-dev -y
sudo apt install libdtkbase-dev libdtkcore-dev libdtksettings-dev libdtksettingsview-dev libdtkutil-dev libdtkwidget-dev libdtkwm-dev -y
sudo apt install dh-make fakeroot -y
cd shadowsocks-client
mkdir build && cd build
cmake ..
make -j4
./shadowsocks-client
````
# 更新日志
> 1.2.1版本 修复由于原pac文件地址失效导致的pac模式无法使用的BUG，最新pac文件地址为 http://file.lolimay.cn/autoproxy.pac
>
> 1.2.0版本 主要功能基本实现，支持全局模式和pac模式，支持切换服务器，支持二维码导入导出配置等高级功能。

# 关于
1.2.0版本之前由 **[@PikachuHy](https://github.com/PikachuHy)** 开发，1.2.1版本之后由 **[@lolimay](https://github.com/lolimay)** 维护。

# 开源许可

Shadowsocks Client 使用 [GPLv3](LICENSE) 许可协议.

非常感谢以下开源项目 

- [Deepin System Monitor](https://github.com/linuxdeepin/deepin-system-monitor)
- [Shadowsocks for Windows](https://github.com/shadowsocks/shadowsocks-windows)
- [libQtShadowsocks](https://github.com/shadowsocks/libQtShadowsocks)

## 依赖的开源组件

| 名称                   | 许可        | 链接                                      |
| ---------------------- | -------------- | ---------------------------------------- |
| Deepin Tool Kit Core   | GPLv3          | https://github.com/linuxdeepin/dtkcore   |
| Deepin Tool Kit Widget | GPLv3          | https://github.com/linuxdeepin/dtkwidget |
| Botan                  | Simplified BSD | https://github.com/randombit/botan       |
| libQtShadowsocks       | LGPLv3         | https://github.com/shadowsocks/libQtShadowsocks |
| ZBar                   | LGPLv2.1       | https://github.com/ZBar/ZBar             |
| libqrencode            | LGPLv2.1       | https://github.com/fukuchi/libqrencode   |


