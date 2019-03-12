

.text
.global _start

_start:

	/* 关闭看门狗*/
	ldr r0,  =0x53000000
	ldr r1,   =0
	str r1,  [r0]
	

	/* 设置内存： sp栈自动识别nor启动/nand启动
	 * 写入0地址然后读取0地址的值
	 * 如果写成功那么说明是sram -->nand启动
	 * 如果写不成功那么说明是nor启动
	 */
	mov r1, #0
	ldr r0, [r1]                              /*保存0地址的值*/ 
	str r1, [r1]                               /*向0地址写入0*/   
	ldr r2, [r1]                              /*读出0地址的值到r1*/  
	cmp r1, r2                               /*比较r1和r2两者的值*/
	ldr sp, =0x40000000 + 4096   /*默认nor启动*/
	moveq sp, #4096                      /*如果r1 == r2 nand启动*/
	streq r0, [r1]                           /*如果是nand启动要恢复0地址的数据*/
	 

	bl main

	
/*防止读取后面的不确定的代码*/
halt:
	b halt

	

