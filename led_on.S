

/*
 * 点亮LED: gpf4
 */

.text
.global _start

_start:

	/*  配置GPF4为输出引脚
	 *  把0x100写入地址0x56000050
	 */
	ldr R1 , =0x56000050
  	ldr R0 , =0x100
  	str R0, [R1]

	/* 设置GPF4输出低电平
	 * 把0写入到地址0x56000054
	 */
	ldr R1, =0x56000054
	ldr r0, =0
	str r0, [R1]
	
	/*防止读取后面的不确定的代码*/
halt:
	b halt;

  
