

.text
.global _start

_start:

	/* 设置内存： sp栈*/
	ldr sp, =4096                             /*nand启动*/
	//ldr sp, =0x40000000+4096       /*nor启动*/

	/* 调用 led_on 传入参数4 */
	ldr r0, =4
	bl led_on

	/*延迟函数*/
	ldr r0, =100000
	bl delay

	/* 调用 led_on 传入参数5 */
	ldr r0, =5
	bl led_on

	
/*防止读取后面的不确定的代码*/
halt:
	b halt

	

