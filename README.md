# pcs_epics_base
**作者：Johnson Han
日期：2020-02-02** 

|运行环境 centos 7|
|============================｜
|名称|版本号|
|:------|------：|
|Linux内核| 3.10.0-1062.9.1.rt56.1033.el7.x86_64|
|gcc | 4.8.5| 
|java|openjdk "1.8.0_232"|
|CSS版本| cs-studio-ess-4.6.1.24|
##一、 EPICS base 更新日志 
###  *base 文件夹*
>基于 EPICS Base 3.14.12.5
1. 增加对EPID的记录支持和设备支持。（Soft Channel）
2. 增加对Pulse Train的记录支持和设备支持。（发现Pulse Train必须有硬件支持，没有软的设备支持）
3. 增加了SCAN 域的选项：“600 Second” “300 second” “.05 second”  
---
### *HeaterIoc 文件夹*
<p>加热器IOC，包含PID温度控制、启停控制和超温连锁和复位</p>