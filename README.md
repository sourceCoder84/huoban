# luoban
the program about 2440 

004_len_on
编写C语言函数设置LED
1. 关闭看门狗
2. 自动识别nor启动还是nand启动
3. 循环点亮led

注意 将start.S 中的mov r1 #0       换成 ldr r1 =0
				moveq sp, #4096 换成 ldreq sp, #4096 	
  转成汇编代码是一样的