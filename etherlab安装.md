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

<code> \$ ./configure</code>
<code> \$ make all modules</code>

<code> \# make modules_install install </code>
<code> \# depmod </code>

... and linking the init script and copying the sysconfig file from $PREFIX/etc
to the appropriate locations and customizing the sysconfig file.

<code> # ln -s \${PREFIX}/etc/init.d/ethercat /etc/init.d/ethercat
<code> # cp \${PREFIX}/etc/sysconfig/ethercat /etc/sysconfig/ethercat
<code> # vi /etc/sysconfig/ethercat

Make sure, that the 'udev' package is installed, to automatically create the
EtherCAT character devices. The character devices will be created with mode
0660 and group root by default. If you want to give normal users reading
access, create a udev rule like this:

<code> # echo KERNEL==\"EtherCAT[0-9]*\", MODE=\"0664\" > /etc/udev/rules.d/99-EtherCAT.rules

Now you can start the EtherCAT master:

<code> # /etc/init.d/ethercat start