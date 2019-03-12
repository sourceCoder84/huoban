#include "s3c2440_soc.h"

void delay(volatile int d){

	while(d--);
}


int main(void)
{
		int vals[3] = {3, 5, 6 };

		/*����GPFCON��GPF4/5/6����Ϊ�������*/
		GPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
		GPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));

		/*ѭ������*/
		int  i = 0;
		while(1){

			for(i = 0; i < 3; i++){
				GPFDAT &= ~(7 << 4);
				GPFDAT |= (vals[i] << 4);
				delay(100000);
			}
		}
	return 0;
}


