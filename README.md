# pcs_epics_base
**作者：Johnson Han
日期：2020-02-02** 

运行环境： centos 7

<center>软件版本号</center>

|名称|版本号|
|-----|------|
|Linux| 3.10.0-1062.9.1.rt56.1033.el7.x86_64|
|gcc|4.8.5|
|javaopenjdk |1.8.0_232|
|CSS版本|cs-studio-ess-4.6.1.24|
##一、 EPICS base 更新日志 
###  *base 文件夹*
>基于 EPICS Base 3.14.12.5
1. 增加对EPID的记录支持和设备支持。（Soft Channel）
2. 增加对Pulse Train的记录支持和设备支持。（发现Pulse Train必须有硬件支持，没有软的设备支持）
3. 增加了SCAN 域的选项：“600 Second” “300 second” “.05 second”  
---
### *HeaterIoc 文件夹*
> 加热器IOC，包含PID温度控制、启停控制和超温连锁和复位

>包含db文件

dbExample1： 加热模块变量 
dbExample2： 模拟通道变量（列表中*号标注）
user.substitutions ：宏替代
 tmsr_heater_release 
db变量列表
```
$(Heater):alarmTempFB    *报警温度反馈 <--
$(Heater):powerOutput     功率输出0-100%
$(Heater):tempFeedbk      *目标温度反馈 <--
$(Heater):alarmTempSet  报警温度设定
$(Heater):powerOut          * 针对倍福AO通道输出，0-24576 -->
$(Heater):targetTempSet  目标温度设定
$(Heater):alarmStatus      报警状态
$(Heater):AKN                 报警复位
$(Heater):CtrlOut             * 加热BO输出通道变量 -->     
$(Heater):controlOut         启动控制输出
$(Heater):start                 加热启动 脉冲触发
$(Heater):stop                 加热停止  脉冲触发
$(Heater):alarmRS           报警触发器
$(Heater):startRS             加热启动触发器
$(Heater):targetTempCalc  阶段目标温度计算
$(Heater):pid                    pid模块
```

`1.加强器启停控制部分`

![VDCT 变量关系 ](/images/heaterCtl.png "加热器开关控制")

<center>启动控制模块变量说明

|名称|变量名称|注释|类型|
|--|--|--|--|
|启动控制|$(Heater):start|1:启动 0：停止|bo|
|开关输出|$(Heater):CtrlOut|输出给DB连接\$(CTRL_OUT)<br>此处宏可直接替代为BO输出板卡通道的变量名 |bo|
|启动RS触发器|$(Heater):startRS|A && (!(B\|\|D)) \|\| ( (!(B\|\|D) && C )<br> A:\$(Heater):start <br>B: \$(Heater):alarm<br> C:\$(Heater):startRS <br>D:\$(Heater):stop|calc|

<center>超温报警模块变量说明

|名称|变量名称|注释|类型|
|--|--|--|--|
|连锁复位|\$(Heater):AKN|脉冲复位|bo|
|报警温度设定|\$(Heater):alarmTempSet||ao|
|报警状态计算|\$(Heater):alarmRS|公式:!(A && (!(B>D)) \|\| ( (!(B>D)) && !C ))<br>相当于RS触发器取反,S:复位 R:温度判断(B>D的判断值)<br>A：\$(Heater):AKN 复位<br>B：\$(ALRM_TMP_FB) 连锁温度点反馈，可直接替代位版卡温度通道的变量名<br>D:\$(Heater):alarmTempSet 报警温度设定值 <br>C：\$(Heater):alarmRS通道本身上次的值|calc|


![PID 变量关系 ](/images/HeaterPID.png "集热器PID工作模块")