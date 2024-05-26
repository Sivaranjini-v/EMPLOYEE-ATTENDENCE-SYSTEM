#include<lpc21xx.h>
#include"header1.h"
//#define RDR (U0LSR&1)
extern unsigned int i;
extern char buf[60];
void UART0_Handler(void)__irq
{
	int r=U1IIR;
	if(r&4)
	{
	buf[i]=U1RBR;
	i++;
	}
   // buf[i]='\0';

VICVectAddr=0;
}

void config_vic(void)
{
VICIntSelect=0;
//VICIntSelect=(1<<6);//uart0 is FIQ
VICVectCntl0=7|(1<<5);
VICVectAddr0=(int)UART0_Handler;
VICIntEnable |=(1<<7);
}

void en_uart0_interrupt(void)
{
U0IER=0x03;
}

