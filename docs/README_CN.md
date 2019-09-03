<p align="center"><a href="https://github.com/lolimay/shadowsocks-deepin" target="_blank" rel="noopener noreferrer"><img width="100" src="http://images.lolimay.cn/18-9-28/52492273.jpg" alt="Shadowsocks logo"></a></p><p align="center">
  <a href="https://github.com/lolimay/shadowsocks-deepin"><img src="https://img.shields.io/github/stars/lolimay/shadowsocks-deepin.svg" alt="License"></a>
  <a href="https://github.com/lolimay/shadowsocks-deepin"><img src="https://img.shields.io/badge/version-1.2.2-brightgreen.svg" alt="Version"></a>
  <a href="https://github.com/lolimay/shadowsocks-deepin"><img src="https://img.shields.io/badge/license-GPLv3-green.svg" alt="License"></a>
</p>

<h2 align="center">Shadowsocks for Deepin</h2>

**<p align="center"><a href="https://github.com/lolimay/shadowsocks-deepin">English</a> | 中文</p>**

Shadowsocks-deepin 是一款专门为 deepin 打造的小飞机，科学上网必备！

![](/docs/images/shadowsocks-deepin.jpg)


与 Shadowsocks-Qt5 相比的优势

|软件|系统代理模式|易用性|
|:-:|:-:|:-:|
|Shadowsocks-Qt5|仅支持全局模式|需要手动配置系统代理或配置Chrome拓展|
|Shadowsocks-Deepin|既支持全局模式也支持pac模式|无需任何配置

# 下载安装
<br>
<p align="center"><a href="http://file.lolimay.cn/shadowsocks-deepin_1.2.2_amd64.deb"><img src="http://images.lolimay.cn/18-9-28/51226561.jpg"/></a></p>

软件开箱即用，只要正确填写了你的服务器配置、选择好系统代理模式并启动系统代理后，小飞机即可起飞，**不需要手动配置系统代理，软件会自动修改系统代理配置**，在使用的过程中如遇到任何问题，欢迎提 [**issues**](https://github.com/loliMay/shadowsocks-deepin/issues/new)。

也可以尝试自己将源码打包，下面给出打包方法:
````bash
sudo apt update #更新源
sudo apt install git dh-make cmake fakeroot qtcreator-dde qttools5-dev g++ -y #安装相关依赖
mkdir shadowsocks && cd shadowsocks #新建shadowsocks文件夹并打开该文件夹
git clone git@github.com:loliMay/shadowsocks-deepin.git #克隆shadowsocks-deepin仓库
mv shadowsocks-deepin shadowsocks-deepin-1.2.2 #重命名
tar -zcvf shadowsocks-deepin-1.2.2.tar.gz shadowsocks-deepin-1.2.2 #打成.tar.gz包
cd shadowsocks-deepin-1.2.2 #进入项目根目录
dpkg-buildpackage -us -uc -b #打成.deb包
````

右键在文件管理器中打开，若在`shadowsocks`目录下出现`.deb`包则说明打包成功。


# 终端代理
默认情况下，终端无法通过 shadowsocks 代理访问目标URL，无论是应用全局模式还是 pac 模式。[Proxychains](https://github.com/haad/proxychains) 是一个强制任何TCP连接走 shadowsocks 代理的工具。 按照以下步骤操作，可以使任何终端命令通过 shadowsocks 代理访问网络：

1. `sudo apt install proxychains -y # 安装 proxychains`
2. `echo -e "[ProxyList]\nsocks5 127.0.0.1 1080" | tee ~/.proxychains/proxychains.conf # 初始化配置`
3. 为希望通过代理访问网络的命令添加 `proxychains` 前缀：

例：
````bash
npm install chalk # 未使用代理
proxychains npm install chalk # 使用代理
proxychains git clone git@github.com:lolimay/shadowsocks-deepin.git # 使用代理
````

# 参与开发

开发这个软件用到的原理，请参考 [影梭客户端原理剖析](/docs/影梭客户端原理剖析.md)

````
sudo apt update
sudo apt install qt5-default qttools5-dev-tools qt5-qmake g++ qtcreator qttools5-dev -y
sudo apt install libdtkbase-dev libdtkwidget-dev -y
sudo apt install libdframeworkdbus-dev -y
sudo apt install libqrencode-dev libzbar-dev -y
sudo apt install libdtkcore-dev libdtkwidget-dev libdtkwm-dev libdtkcore-bin -y
sudo apt install libdtksettings-dev libdtksettingsview-dev -y
sudo apt install dh-make fakeroot -y
cd shadowsocks-deepin
mkdir build && cd build
cmake ..
make -j4
cd src
./shadowsocks-deepin
````
# 更新日志
> 1.2.2版本 修复 [#9](https://github.com/lolimay/shadowsocks-deepin/issues/9)，汉化软件主要界面，将流量上下标改成 [shadowsocks-windows](https://github.com/shadowsocks/shadowsocks-windows) 风格
>
> 1.2.1版本 修复由于原pac文件地址失效导致的pac模式无法使用的BUG，最新pac文件地址为 http://file.lolimay.cn/autoproxy.pac
>
> 1.2.0版本 主要功能基本实现，支持全局模式和pac模式，支持切换服务器，支持二维码导入导出配置等高级功能。

# 关于
1.2.0版本之前由 **[@PikachuHy](https://github.com/PikachuHy)** 开发，1.2.1版本之后由 **[@lolimay](https://github.com/lolimay)** 维护。

# 开源许可

Shadowsocks-Deepin 使用 [GPLv3](LICENSE) 许可协议.

非常感谢以下开源项目 

- [Deepin System Monitor](https://github.com/linuxdeepin/deepin-system-monitor)
- [Shadowsocks for Windows](https://github.com/shadowsocks/shadowsocks-windows)
- [libQtShadowsocks](https://github.com/shadowsocks/libQtShadowsocks)

## 依赖的开源组件
| 名称                   | 许可        |
| ---------------------- | -------------- |
| [Deepin Tool Kit Core](https://github.com/linuxdeepin/dtkcore)   | GPLv3          |
| [Deepin Tool Kit Widget](https://github.com/linuxdeepin/dtkwidget) | GPLv3          |
| [Botan](https://github.com/randombit/botanss)                  | Simplified BSD |
| [libQtShadowsocks](https://github.com/shadowsocks/libQtShadowsocks)       | LGPLv3         |
| [ZBar](https://github.com/ZBar/ZBar)                   | LGPLv2.1       |
| [libqrencode](https://github.com/fukuchi/libqrencode)            | LGPLv2.1       |



