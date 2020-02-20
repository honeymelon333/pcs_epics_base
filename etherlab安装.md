# Etherlab 安装  

## 1. 软件包 
> etherlabmaster-code

1. 本软件包基于 [IgH EtherCAT Master for Linux](http://etherlab.org/en/ethercat/index.php)

2. 按照 [钻石光源DLS](http://controls.diamond.ac.uk/downloads/support/ethercat/4-7/documentation/doxygen/building.html) 的描述打了 [补丁](http://controls.diamond.ac.uk/downloads/support/ethercat/4-7/documentation/doxygen/configurable-error-suppression.patch)
<code> patch -p1 < ./configurable-error-suppression.patch</code>

3. 补丁下载以后/lib/liberror.c 和 /lib/lib/liberror.h 对报错字符串的定义不对照,修改为如下：
<code><u>char *ecrt_errstring[ERRSTRING_LEN];</u></code>


## 2. 正常的安装过程

<code> \$ ./boostrap  # 根据系统生成配置温文件 </code>

<code> \$ ./configure --enble-generic --disable-r8169 --disable-8139too </code>
<code> \$ make all modules</code>

<code> \# make modules_install install </code>
<code> \# depmod </code>

## 3. 开机自启动脚本

script 文件夹中包含systemd 和 initd 两种进程使用启动脚本。[(systemd 与 initd 比较)](http://www.ruanyifeng.com/blog/2016/03/systemd-tutorial-commands.html)

* **systemd**：
> 系统服务：<u>/script/ethercat.service</u>

> 配置文件 <u>/script/ethercat.conf</u>

安装位置： /etc/ethercat.conf   修改该文件中

<code>MASTER0_DEVICE="your mac addr"</code>
<code>DEVICE_MODULES="generic" </code>

* **initd**:
> 系统服务：<u>/script/init.d/ethercat</u>

> 配置文件：<u>/script/sysconfig/ethercat</u>

两种启动守护进程的方式作用一样。