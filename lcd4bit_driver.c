#include <LPC21xx.H>
#include "header1.h"
#define RS (1<<17)
#define RW (1<<18)
#define EN (1<<19)
void lcd_data(unsigned char data)
 {
    unsigned int temp;
	IOCLR1=0X00FE0000;
	temp=(data & 0XF0)<<16;
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;	

	IOCLR1=0X00FE0000;
	temp=(data&0X0F)<<20;
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
}
void lcd_cmd(unsigned char cmd)
{
    unsigned int temp;
	IOCLR1=0X00FE0000;
	temp=(cmd&0XF0)<<16;
	IOSET1=temp;
	IOCLR1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;

	IOCLR1=0X00FE0000;
	temp=(cmd&0X0F)<<20;
	IOSET1=temp;
	IOCLR1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;

}
void lcd_init(void)
{
IODIR1 |= 0X00FE0000;
PINSEL2=0;
lcd_cmd(0x02);
lcd_cmd(0x03);
lcd_cmd(0x28);
lcd_cmd(0x0E);
lcd_cmd(0x01);
}
void lcd_string(char *ptr)
{
while(*ptr!=0)
{
lcd_data(*ptr);
ptr++;
}
}
