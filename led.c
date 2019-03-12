#include "s3c2440_soc.h"

void delay(volatile int d){

	while(d--);
}


int main(void)
{
		int val1, val2;

		/*设置GPFCON让GPF4(D10)/5(D11)/6(D12)配置为输出引脚*/
		GPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
		GPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));

		/*设置按键控制寄存器为输入引脚*/
		/*GPF0(EINT0), GPF2(EINT2)  GPG3(EINT11)*/
		GPFCON &= ~((3 << 0) | (3 << 4));
		GPGCON &= ~(3 << 6);

		
		
		/*按键点亮
		 * 对应关系:
		 * 按键                               led
		 * ENIT0(GPF0)                D12(GPF6)
		 * ENIT2(GPF2)                D11(GPF5)
		 * ENIT11(GPG3)               D10(GPF4)
		 */
		while(1){

			val1 = GPFDAT;
			val2 = GPGDAT;

			if(val1 & (1 << 0)){                               
				/*如果是高电平表明是松开状态，led熄灭
				 * GPFDAT6 = 1	
				 */
				 GPFDAT |= (1 << 6);
			}else{
				/*GPFDAT6 = 0*/
				 GPFDAT &= ~(1 << 6);
			}
			if(val1 & (1 << 2)){                               
				/*如果是高电平表明是松开状态，led熄灭 
				 * GPFDAT5 = 1	
				 */	
				 GPFDAT |= (1 << 5);
			}else{
				/*GPFDAT5 = 0*/
				 GPFDAT &= ~(1 << 5);
			}
			if(val2 & (1 << 3)){                               
				/*如果是高电平表明是松开状态，led熄灭
				 * GPFDAT4 = 1	
				 */	
				  GPFDAT |= (1 << 4);
			}else{
				/* GPFDAT4 = 0 */
				 GPFDAT &= ~(1 << 4);
			}	
			
		}
	return 0;
}


