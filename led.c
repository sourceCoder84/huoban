
void delay(volatile int d){

	while(d--);
}


int main(void)
{
		int vals[3] = {3, 5, 6 };
		volatile unsigned int *pGPFCON = (volatile unsigned int *)0x56000050;
		volatile unsigned int *pGPFDAT = (volatile unsigned int *)0x56000054;

		/*设置GPFCON让GPF4/5/6配置为输出引脚*/
		*pGPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
		*pGPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));

		/*循环点亮*/
		int  i = 0;
		while(1){

			for(i = 0; i < 3; i++){
				*pGPFDAT &= ~(7 << 4);
				*pGPFDAT |= (vals[i] << 4);
				delay(100000);
			}
		}
	return 0;
}


