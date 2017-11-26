# Shadowsocks Client

Shadowsocks Client: If you want to keep a secret, you must also hide it from yourself.

Thanks a lot for [Shadowsocks for Windows](https://github.com/shadowsocks/shadowsocks-windows),
[libQtShadowsocks](https://github.com/shadowsocks/libQtShadowsocks).

[English](./README.en.md)

开发这个软件用到的原理，技术请参考[影梭客户端原理剖析](影梭客户端原理剖析.md)

关于这个软件的开发进展，可以去deepin论坛，看[这个帖子](https://bbs.deepin.org/forum.php?mod=viewthread&tid=142900)

本次升级日志：

1. QtShadowsocks升级到2.0.0beta版，采用静态链接

2. Botan升级到2.3，采用静态链接

3. 新增没有配置服务器的情况下启动，会跳出配置服务器的界面

4. 主要功能点是升级底层库后支持了chacha20-ietf-poly1305，(注：上次会议后不少服务商都改用这个方法了)

5. 小的遗憾，SSR还是没有搞定，(为啥SSR那么坚挺呢？)
## 使用
建议直接下载我打包好的deb包 [最新发布](https://github.com/PikachuHy/shadowsocks-client/releases)
如需自己编译，可以使用同目录下的release.sh脚本
```
./release.sh
```
安装后
配置文件存储在`~/.config/shadowsocks-client/config.ini`
大概长这个样子，这里是借鉴(chao)的ss-qt5
```ini
[General]
ConfigVersion=2.6000000000000001
HideWindowOnStartup=false
NativeMenuBar=false
OnlyOneInstance=true
ShowFilterBar=true
ShowToolbar=true
StartAtLogin=false
ToolbarStyle=4

[Profile]
1\SQProfile="@Variant()"
size=1
```
日志文字存储在`~/.cache/pikachu/shadowsocks-client/shadowsocks-client.log`
libQtShadowsocks2.0的版本把日志直接输出了，现在应该是看不到什么有用的信息了吧。。。
出了问题，可以参考一下
### 几点说明：

本项目的基本目标在deepin上

1. 提供基本的sock5代理功能（抄ss-qt）
2. 提供方便快捷的全局代理模式和pac代理模式之间的切换（抄深度控制中心），但是比较遗憾的是没有完成直接使用dropbox的目标
3. 提供同ss-win的使用习惯（抄ss-win）

### 几个基本问题

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
## Develop

[CLion 2017.2](https://www.jetbrains.com/clion/) & [Qt 5.6](https://www.qt.io/) are required.

```shell
sudo apt update 
sudo apt install qt5-default qttools5-dev-tools -y
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

