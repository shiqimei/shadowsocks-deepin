# Shadowsocks-Client for Deepin
![](https://img.shields.io/badge/version-1.2.1-blue.svg)
![](https://img.shields.io/badge/license-GPLv3-green.svg)
[Click here to see English version](./doc/README.en.md)

Shadowsocks-Client: If you want to keep a secret, you must also hide it from yourself.

深度影梭客户端：一款专门为Deepin打造的工具，您的贴心好帮手。

**软件原作者: [@PikachuHy](https://bbs.deepin.org/home.php?mod=space&uid=71319)**

> 由于[一些原因](https://bbs.deepin.org/forum.php?mod=viewthread&tid=166674)，[@PikachuHy](https://bbs.deepin.org/home.php?mod=space&uid=71319) 大神删除了自己在deepin论坛上所有的帖子以及github上shadowsocks-client仓库，这是shadowsocks-client 1.2.0版本的备份。

由于原仓库被删，原pac配置(https://raw.githubusercontent.com/PikachuHy/shadowsocks-client/master/autoproxy.pac)失效从而导致pac模式无法正常使用，故将源码中的pac源修改为个人的七牛云pac配置(http://file.lolimay.cn/autoproxy.pac)，**并将版本号更新为1.2.1以区别之前的1.2.0版本**。

下面是我打包的版本，如果偷懒的话可以直接下载使用：

<a href="http://file.lolimay.cn/shadowsocks-client_1.2.1_amd64.deb"><img src="http://images.lolimay.cn/18-8-9/78116321.jpg"/></a>

如果不能正常使用，可以尝试自己打包，以下给出打包方法:

1. [下载最新的源码](https://github.com/loliMay/shadowsocks-client/archive/v1.2.1.tar.gz)
2. 解压至当前文件夹得到`shadowsocks-client-1.2.1`文件夹
3. 右击文件管理器**在终端中打开** 输入以下命令
````bash
cd shadowsocks-client-1.2.1
dh_make -f ../shadowsocks-client-1.2.1.tar.gz -c gpl3 -s
dpkg-buildpackage -us -uc -b
````


Thanks a lot for 

- [Deepin System Monitor](https://github.com/linuxdeepin/deepin-system-monitor)
- [Shadowsocks for Windows](https://github.com/shadowsocks/shadowsocks-windows)
- [libQtShadowsocks](https://github.com/shadowsocks/libQtShadowsocks)

开发这个软件用到的原理，技术请参考[影梭客户端原理剖析](doc/影梭客户端原理剖析.md)

关于这个软件的开发进展，可以去deepin论坛，看[这个帖子](https://bbs.deepin.org/forum.php?mod=viewthread&tid=142900)

如果遇到任何问题，请及时提Issues，或者去论坛发帖，我会尽快解决。

## 与其他客户端的比较

|                    | [ss-win](https://github.com/shadowsocks/shadowsocks-csharp) | [ssx-ng](https://github.com/shadowsocks/ShadowsocksX-NG) | [ss-qt5](https://github.com/shadowsocks/shadowsocks-qt5) | [ss-android](https://github.com/shadowsocks/shadowsocks-android) | ss-client |
| ------------------ | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | --------- |
| System Proxy       | ✓                                        | ✓                                        | ✗                                        | ✓                                        | ✓         |
| CHNRoutes          | ✓                                        | ✓                                        | ✗                                        | ✓                                        | ✗         |
| PAC Configuration  | ✓                                        | ✓                                        | ✗                                        | ✗                                        | ✓         |
| Profile Switching  | ✓                                        | ✓                                        | ✓                                        | ✓                                        | ✓         |
| QR Code Scan       | ✓                                        | ✓                                        | ✓                                        | ✓                                        | ✓         |
| QR Code Generation | ✓                                        | ✓                                        | ✓                                        | ✓                                        | ✓         |



## 使用
建议直接下载我打包好的deb包 [最新发布](https://github.com/PikachuHy/shadowsocks-client/releases)

日志文字存储在`~/.cache/pikachu/shadowsocks-client/`

###  PAC配置

默认使用pac配置文件，`https://raw.githubusercontent.com/PikachuHy/shadowsocks-client/master/autoproxy.pac`

如果需要自己配置pac文件，可以使用genpac

使用命令

```shell
genpac --format pac --pac-proxy "SOCKS5 127.0.0.1:1080" > autoproxy.pac
```

即可以生成需要的pac文件

## Develop

[CLion 2017.3](https://www.jetbrains.com/clion/) & [Qt 5.6](https://www.qt.io/) are required.

```shell
sudo apt update 
sudo apt install qt5-default qttools5-dev-tools -y
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

特别注意，需要Botan2.3以上版本，libQtShadowsocks 2.0.2以上版本

### License

Shadowsocks Client is licensed under [GPLv3](LICENSE).

### Open Source Components / Libraries

| NAME                   | LICENSE        | URL                                      |
| ---------------------- | -------------- | ---------------------------------------- |
| Deepin Tool Kit Core   | GPLv3          | https://github.com/linuxdeepin/dtkcore   |
| Deepin Tool Kit Widget | GPLv3          | https://github.com/linuxdeepin/dtkwidget |
| Botan                  | Simplified BSD | https://github.com/randombit/botan       |
| libQtShadowsocks       | LGPLv3         | https://github.com/shadowsocks/libQtShadowsocks |
| ZBar                   | LGPLv2.1       | https://github.com/ZBar/ZBar             |
| libqrencode            | LGPLv2.1       | https://github.com/fukuchi/libqrencode   |


