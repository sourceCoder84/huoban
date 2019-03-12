# luoban
the program about 2440 

006_len
编写C语言函数设置LED
1. 关闭看门狗
2. 自动识别nor启动还是nand启动
3. 循环点亮led
4. 添加寄存器头文件: s3c2440_soc.h
5. 使用按键操作led
	/*按键点亮
	 * 对应关系:
	 * 按键                       led
	 * ENIT0(GPF0)                D12(GPF6)
	 * ENIT2(GPF2)                D11(GPF5)
	 * ENIT11(GPG3)               D10(GPF4)
	 */	