#include "s3c2440_soc.h"

void delay(volatile int d){

	while(d--);
}


int main(void)
{
		int val1, val2;

		/*����GPFCON��GPF4(D10)/5(D11)/6(D12)����Ϊ�������*/
		GPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
		GPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));

		/*���ð������ƼĴ���Ϊ��������*/
		/*GPF0(EINT0), GPF2(EINT2)  GPG3(EINT11)*/
		GPFCON &= ~((3 << 0) | (3 << 4));
		GPGCON &= ~(3 << 6);

		
		
		/*��������
		 * ��Ӧ��ϵ:
		 * ����                               led
		 * ENIT0(GPF0)                D12(GPF6)
		 * ENIT2(GPF2)                D11(GPF5)
		 * ENIT11(GPG3)               D10(GPF4)
		 */
		while(1){

			val1 = GPFDAT;
			val2 = GPGDAT;

			if(val1 & (1 << 0)){                               
				/*����Ǹߵ�ƽ�������ɿ�״̬��ledϨ��
				 * GPFDAT6 = 1	
				 */
				 GPFDAT |= (1 << 6);
			}else{
				/*GPFDAT6 = 0*/
				 GPFDAT &= ~(1 << 6);
			}
			if(val1 & (1 << 2)){                               
				/*����Ǹߵ�ƽ�������ɿ�״̬��ledϨ�� 
				 * GPFDAT5 = 1	
				 */	
				 GPFDAT |= (1 << 5);
			}else{
				/*GPFDAT5 = 0*/
				 GPFDAT &= ~(1 << 5);
			}
			if(val2 & (1 << 3)){                               
				/*����Ǹߵ�ƽ�������ɿ�״̬��ledϨ��
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


