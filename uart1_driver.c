#include<lpc21xx.h>
#include "header2.h"
#include<stdio.h>
#define THRE ((U1LSR>>5)&1)
#define RDR (U1LSR&1)
void uart1_init(unsigned int baud)
{
int a[]	={15,60,30,0,15};
unsigned int pclk=a[VPBDIV]*1000000;
unsigned int result=0;
result=pclk/(16*baud);
PINSEL0|=0X00050000;
U1LCR=0X83;
U1DLL=result&0xff;
U1DLM=(result>>8)&0xff;
U1LCR =0x03;
}

void uart1_tx(unsigned char data)
{
U1THR=data;
while(THRE==0);
}

void uart1_tx_string(char *ptr)
{
while(*ptr!=0)
{
U1THR=*ptr;
	while(THRE==0);
ptr++;
}
}

unsigned char uart1_rx(void)
{
while(RDR==0);
return U1RBR;
}

void uart1_rx_string(char *ptr,signed int max_bytes)
{
signed int i;
for(i=0;i<max_bytes;i++)
{
while(RDR==0);
ptr[i]=U0RBR;
uart1_tx(ptr[i]);
if(ptr[i]=='\r')
break;
}
ptr[i]='\0';
}

void uart1_tx_integer(int num)
{
char buf[10];
sprintf(buf,"%d",num);
uart1_tx_string(buf);
}

void uart1_tx_float(float num)
{
char buf[10];
sprintf(buf,"%.1f",num);
uart1_tx_string(buf);
}
