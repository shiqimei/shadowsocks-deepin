# Shadowsocks Client

Shadowsocks Client: If you want to keep a secret, you must also hide it from yourself.

Thanks a lot for [Shadowsocks for Windows](https://github.com/shadowsocks/shadowsocks-windows).

[中文说明](https://github.com/PikachuHy/deepin-shadowsocks-client/wiki/%E6%B7%B1%E5%BA%A6%E5%BD%B1%E6%A2%AD%E5%AE%A2%E6%88%B7%E7%AB%AF%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E)
[影梭客户端原理剖析](影梭客户端原理剖析.md)

如需自己编译，可以使用同目录下的release.sh脚本
```
./release.sh
```

几点说明：
本项目的基本目标在deepin上
1. 提供基本的sock5代理功能（抄ss-qt）
2. 提供方便快捷的全局代理模式和pac代理模式之间的切换（抄深度控制中心），但是比较遗憾的是没有完成直接使用dropbox的目标
3. 提供同ss-win的使用习惯（抄ss-win）

几个基本问题

Q:ubuntu能不能用这个
A:我不知道
Q:非debian系能不能用
A:也许可以，也许不知道
Q:能否适配其他的linux系统
A:我只保证ss-client在deepin上稳定运行，其他的我没有时间去弄
Q:这个项目会不会停
A:只要deepin还在更新，只要我还在使用deepin,就不会停止更新。除非你懂的。
Q:关于增加新的功能
A:由于我的C++水平有限，很多C++在项目中的高级运用不是很懂，否则也不会抄这么多的项目了。
除非是新功能对deepin用户体验有明显的提升，否则我只会在空闲的时间偶尔弄一下。
因为需要学习的东西很多，我的精力有限，平时用的也不是C++。
Q:关于ssr
A:有计划，但目前缺少像ss-qt5这样可以直接抄的代码，没有办法很好的在deepin上集成
Q:关于代码
A:我这个代码除了辅助类写得比较烂以外，其他的东西还行

暂时补充这么多。。。
### Features

1. System proxy configuration
2. PAC mode and global mode
### Download

Download the [latest release.](https://github.com/PikachuHy/deepin-shadowsocks-client/releases)

### Requirements

[Deepin 15.4.1](https://www.deepin.org/download/) or higher.

### Basic

1. Find Shadowsocks icon
2. You can add multiple servers in servers menu
3. Select `Enable System Proxy` menu to enable system proxy. Please disable other
  proxy addons in your browser, or set them to use system proxy
4. You can also configure your browser proxy manually if you don't want to enable
  system proxy. Set Socks5 or HTTP proxy to 127.0.0.1:1080. You can change this
  port in `Servers -> Edit Servers`

### PAC

1. You can change PAC rules by editing the PAC file. When you save the PAC file
  with any editor, Shadowsocks will notify browsers about the change automatically
2. You can also use online PAC URL

### Develop

[CLion 2017.2](https://www.jetbrains.com/clion/) & [Qt 5.6](https://www.qt.io/) are required.

```shell
sudo apt update 
sudo apt install qt5-default qttools5-dev-tools -y
sudo apt install libqtshadowsocks-dev -y
sudo apt install libssl-dev libbotan1.10-dev -y
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
```



### License

Shadowsocks Client is licensed under [GPLv3](LICENSE).
