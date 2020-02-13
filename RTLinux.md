# 实时linux安装指南
_作者：Johson Han   时间：2020/2/13_

> 0. 系统升级 

<code> # yum update </code>

升级到
> 1. 实时linux依赖Tuned 和tuned-profiles-realtime. 
_参考：《Linux Performance Tuning Guide》_

> 2. 安装实时内核


* kernel-rt.x86_64.0.3.10.0-1062.12.1.rt56.1042.el7
* rt-setup.x86_64.0.2.0-9.el7 
* -rt-tests.x86_64.0.1.0-16.el7 
* rtcheck.x86_64.0.0.7.7-6.el7 
* rtctl.noarch.0.1.13-2.el7 
* rteval.noarch.0.2.14-12.el7 
* rteval-common.noarch.0.2.14-12.el7 
* rteval-loads.noarch.0.1.4-2.el7 