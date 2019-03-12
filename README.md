# luoban
the program about 2440 

003_len_on
编写C语言函数设置LED
	a. 我们写出了main函数，是恶来调用它；
	b. main函数中的变量保存在内存中，这个内存地址时多少
答：我们还需要写一个汇编代码，给main函数设置内存，调用main

ldmia ia increatment after
stmdb	sp!, {fp, ip, lr, pc}
ldmia	sp, {fp, sp, pc}

db decreatment before
ia increatment after

上述几个指令是将后面sp所指地址的值赋给后面的寄存器（ldmia）/将寄存器的值存入sp所致的内存中（stmdb）
  * 注意这里的大得寄存器对应大的地址 fp = R11 ip = R12  lr = R14  pc = R15
  
  
Makefile中链接时 start.o 要放在 led_on.o 的前面
arm-linux-ld -Ttext 0 start.o led_on.o -o led_on.elf
