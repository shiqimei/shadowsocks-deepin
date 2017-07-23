# README

本项目的计划在deepin上实现win版ss的功能

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

