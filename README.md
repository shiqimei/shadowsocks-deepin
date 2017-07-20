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

ui界面

![ui界面](./ui.gif)

### 说明

由于目前还很简陋，大量配置是写死的。

在使用前，需要自己有ss的账号。

ss配置文件在/etc/ss/ss.json

ss.json示例

```json
{
"server":"server addr",
"server_port":20526,
"local_address":"127.0.0.1",
"local_port":1080,
"password":"password",
"timeout":300,
"method":"aes-256-cfb",
"fast_open":false
}
```

更详细的请参考官网[shadowsocks Quick Guide](http://shadowsocks.org/en/config/quick-guide.html)

pac文件也放在/etc/ss下。项目中附带一个可用的pac文件。

我后面会写界面去调的。