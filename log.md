本项目的计划在deepin上实现win版ss的功能。我习惯了win上能自由在全局和局部代理切换，在deepin上没有相应的软件，ss-qt５只能是要么全局，要么不开。

#### 项目初衷和一个小版本的总结

我最开始是想学习一下deepin的控件，比较deepin的界面做得很美观。学习使用CLion去写Qt，我比较喜欢JetBrains的全家桶，毕竟有着Java的IDEA神器。这个项目没有完全用CLion去写，部分界面用QtCreator写好，然后移植到CLion，目前我已经能比较熟练的移植QtCreator项目到CLion的CMake项目。熟悉CMake的一些用法。打一个简单的deb包。

```shell
tar -cvzf ss-0.0.1.tar.gz ss-0.0.1
dh_make -f ../ss-0.0.1.tar.gz
dpkg-buildpackage -us -uc -b
```

接下来把一些bug修一修，然后思考自己写的这份代码，看看能不能重构，把项目代码写得精致一些。在这几天中，随着代码量一点一点增加（其实没多少），慢慢感觉自己有些把握不好，有时候为了修好一个bug，又带入新的bug。

在功能方面，我就不那么强求了，对我自己来说够用了，我在ｗin上就用这么点，太高深的我也不知道。如果有需要可以提issue，我可以慢慢去学，再慢慢去做。不过相对而言，我比较关心的是，为什么代理对终端无效，必须用`proxychains`等软件才能用呢？不知道能不能完成终端走代理，这个很吸引我。在这个项目里，几个代理的切换是通过deepin的一个辅助类实现的。

```c++
using NetworkInter = com::deepin::daemon::Network;
QDBusPendingCallWatcher *w = new QDBusPendingCallWatcher(networkInter.SetProxyMethod(proxyMethod), this);
```

差不多就是这样吧。这些是我学习深度控制中心的代码中找到的。

由于CLion对Qt的支持不是特别好，而我在用Qt的时候，经常用到qrc资源文件，所以我想做一个带界面交互的qrc插件，方便自己学习。如果继续学习Qt的话，我会考虑学一下qmake转cmake的那个ruby脚本。

#### 安装依赖

```shell
sudo apt install libqtshadowsocks-dev
sudo apt install libssl-dev libbotan1.10-dev
```
#### win版功能对照

1. 系统代理设置
2. PAC 模式和全局模式
3. [GFWList](https://github.com/gfwlist/gfwlist) 和用户规则
4. 支持 HTTP 代理
5. 支持多服务器切换
6. 支持 UDP 代理

#### 当前进度

- 配合proxychains,能够进行代理
- 能够在PAC模式和全局模式之间切换
- 能够编辑服务器配置，并把配置文件写在`~/.ss/gui-config.json`，格式同其他的ss客户端
- pac文件默认从网上下载到本地，文件就是项目中的那个

ui界面

![ui界面](images/ui.gif)


![编辑服务器配置](images/editServer.png)

![editOnlinPacUrl.png](images/editOnlinPacUrl.png)

打包记录

```shell
sudo apt install dh-make fakeroot cmake
tar -cvzf shadowsocks-client-0.6.1.tar.gz shadowsocks-client-0.6.1
cd shadowsocks-client-0.6.1
dh_make -f ../shadowsocks-client-0.6.1.tar.gz -c gpl3 -s
dpkg-buildpackage -us -uc -b
sudo apt purge shadowsocks-client
```
保存 git密码
```
git config --global credential.helper store
```
gfwlist2pac使用方法
```shell
gfwlist2pac -i ~/Desktop/gfwlist.txt -f ~/Desktop/proxy.pac -p "SOCKS5 127.0.0.1:1080"
```

字符串搜索

```shell
find -type f -name '*.cpp'|xargs grep 'APP_AUTOSTART_CACHE'
```

updatedb
ctrl+z 挂起
jobs 显示暂停
bg 1
fg 1
编辑本地PAC文件
从GFWList更新本地PAC
编辑GFWList的用户规则
保护本地PAC
复制本地PAC网址
编辑在线PAC网址
​     

