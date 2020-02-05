# 代码解析
**2020-02-04**
>1. Soft  Channel 和 Raw Soft Channel的区别

Soft channel 不做任何转换，直接把值读到VAL域。
Raw Soft Channel把值先读到RVAL域，然后按照LINR定义的转换规则对RVAL进行转换。转换后的值赋予VAL。

>2. 记录支持和设备支持

记录支持实现软件层面PV变量(record)的初始化、处理、转化等。记录支持和设备支持是调用关系。