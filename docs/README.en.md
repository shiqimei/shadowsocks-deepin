# Shadowsocks Client

Shadowsocks Client: If you want to keep a secret, you must also hide it from yourself.

Thanks a lot for [Shadowsocks for Windows](https://github.com/shadowsocks/shadowsocks-windows).

[中文说明](https://github.com/PikachuHy/deepin-shadowsocks-client/wiki/%E6%B7%B1%E5%BA%A6%E5%BD%B1%E6%A2%AD%E5%AE%A2%E6%88%B7%E7%AB%AF%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E)

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
