

/*
 * 点亮LED: gpf5
 * 也可以直接修改bin文件将 
 * e3a00c01 修改为e3a00b01	
 * 通过ARM Architecture Reference Manual
 * 查看mov指令的格式计算出立即数
 */

.text
.global _start

_start:

	/*  配置GPF5为输出引脚
	 *  把0x400写入地址0x56000050
	 */
	ldr R1 , =0x56000050
  	ldr R0 , =0x400
  	str R0, [R1]

	/* 设置GPF5输出低电平
	 * 把0写入到地址0x56000054
	 */
	ldr R1, =0x56000054
	ldr r0, =0
	str r0, [R1]
	
	/*防止读取后面的不确定的代码*/
halt:
	b halt;

  
