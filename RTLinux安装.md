# 实时linux安装指南
_作者：Johson Han   时间：2020/2/13_

## 1. 系统升级   

> 最新系统版本：linux 3.10.0-1062.12.1  

这里要保证内核版本与实时内核版本一致。
因为etherlab编译时，要用到内核文件
_/usr/src/kernels/$(uname -r)_ 的内核原文件。

<code> # yum update </code>


## 2. 安装实时linux依赖

Tuned 和tuned-profiles-realtime. 
tuned 版本领先于tuned-profiles-realtime
目前最新匹配版本：


_参考：《Linux Performance Tuning Guide》_
~ <u>tuned.noarch                                2.9.0-1.el7fdp  
tuned-profiles-realtime.noarch              2.9.0-1.el7_5.2</u>

## 3. 安装实时内核 

1. 下载实时内核源的配置文件:
    [CentOS-RT.repo](http://linuxsoft.cern.ch/cern/centos/7/rt/CentOS-RT.repo)

2. 存储到：
    /etc/yum.repos.d/CentOS-RT.repo 

3. 安装实时内核软件宝：

<code># yum groupinstall RT</cord>

[参考：CERN实时内核](http://linux.web.cern.ch/linux/rt/)
* kernel-rt.x86_64.0.3.10.0-1062.12.1.rt56.1042.el7
* rt-setup.x86_64.0.2.0-9.el7 
* -rt-tests.x86_64.0.1.0-16.el7 
* rtcheck.x86_64.0.0.7.7-6.el7 
* rtctl.noarch.0.1.13-2.el7 
* rteval.noarch.0.2.14-12.el7 
* rteval-common.noarch.0.2.14-12.el7 
* rteval-loads.noarch.0.1.4-2.el7 