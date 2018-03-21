# Shadowsocks Client

Shadowsocks Client: If you want to keep a secret, you must also hide it from yourself.

Thanks a lot for [Deepin System Monitor](https://github.com/linuxdeepin/deepin-system-monitor), [Shadowsocks for Windows](https://github.com/shadowsocks/shadowsocks-windows),
[libQtShadowsocks](https://github.com/shadowsocks/libQtShadowsocks).

[English](./doc/README.en.md)

开发这个软件用到的原理，技术请参考[影梭客户端原理剖析](doc/影梭客户端原理剖析.md)

关于这个软件的开发进展，可以去deepin论坛，看[这个帖子](https://bbs.deepin.org/forum.php?mod=viewthread&tid=142900)

## 与其他客户端的比较

|                    | [ss-win](https://github.com/shadowsocks/shadowsocks-csharp) | [ssx-ng](https://github.com/shadowsocks/ShadowsocksX-NG) | [ss-qt5](https://github.com/shadowsocks/shadowsocks-qt5) | [ss-android](https://github.com/shadowsocks/shadowsocks-android) | ss-client |
| ------------------ | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | --------- |
| System Proxy       | ✓                                        | ✓                                        | ✗                                        | ✓                                        | ✓         |
| CHNRoutes          | ✓                                        | ✓                                        | ✗                                        | ✓                                        | ✗         |
| PAC Configuration  | ✓                                        | ✓                                        | ✗                                        | ✗                                        | ✓         |
| Profile Switching  | ✓                                        | ✓                                        | ✓                                        | ✓                                        | ✓         |
| QR Code Scan       | ✓                                        | ✓                                        | ✓                                        | ✓                                        | ✗         |
| QR Code Generation | ✓                                        | ✓                                        | ✓                                        | ✓                                        | ✗         |



## 使用
建议直接下载我打包好的deb包 [最新发布](https://github.com/PikachuHy/shadowsocks-client/releases)

日志文字存储在`~/.cache/pikachu/shadowsocks-client/`
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

