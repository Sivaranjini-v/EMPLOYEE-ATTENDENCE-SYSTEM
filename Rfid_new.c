#include<lpc21xx.h>
#include"header1.h"
char buf[50];
unsigned int i=0;
main()
{
//int f;
unsigned char h,m,s,D,M,Y;
uart0_init(9600);
uart1_init(9600);
lcd_init();
i2c_init();
config_vic();
en_uart0_interrupt();

i2c_byte_write_frame(0xD0,0x2,0x23);//set hrs
i2c_byte_write_frame(0xD0,0x1,0x59);//set mins
i2c_byte_write_frame(0xD0,0x0,0x50);//set secs	

i2c_byte_write_frame(0xD0,0x4,0x23);//set day
i2c_byte_write_frame(0xD0,0x5,0x11);//set Month
i2c_byte_write_frame(0xD0,0x6,0x24);//set year

while(1)
{

lcd_cmd(0x80);
lcd_string("SCAN CARD");

h=i2c_byte_read_frame(0xD0,0x2);//hour
m=i2c_byte_read_frame(0xD0,0x1);//min
s=i2c_byte_read_frame(0xD0,0x0);//sec

D=i2c_byte_read_frame(0xD0,0x4);//day
M=i2c_byte_read_frame(0xD0,0x5);//month
Y=i2c_byte_read_frame(0xD0,0x6);//year	

lcd_cmd(0xc0);
lcd_data((h/0x10)+48);
lcd_data((h%0x10)+48);
lcd_data(':');
lcd_data((m/0x10)+48);
lcd_data((m%0x10)+48);
lcd_data(':');
lcd_data((s/0x10)+48);
lcd_data((s%0x10)+48);
lcd_data(' ');
lcd_data((D/0x10)+48);
lcd_data((D%0x10)+48);
lcd_data('/');
lcd_data((M/0x10)+48);
lcd_data((M%0x10)+48);


while(i==12)
{
	buf[i++]=' ';
	buf[i++]=((h/0x10)+48);
	buf[i++]=((h%0x10)+48);
	buf[i++]=':';
	
	buf[i++]=((m/0x10)+48);
	buf[i++]=((m%0x10)+48);
	buf[i++]=':';
	
	buf[i++]=((s/0x10)+48);
	buf[i++]=((s%0x10)+48);
	buf[i++]=' ';
	
	buf[i++]=((D/0x10)+48);
	buf[i++]=((D%0x10)+48);
	buf[i++]='/';
	
	buf[i++]=((M/0x10)+48);
	buf[i++]=((M%0x10)+48);
	buf[i++]='/';
	
	buf[i++]=((Y/0x10)+48);
	buf[i++]=((Y%0x10)+48);
	buf[i++]='\r';
	buf[i++]='\n';
	buf[i]='\0';
	
	uart0_tx_string(buf);
//	lcd_cmd(0x80);
//	lcd_string(buf);
	i=0;
}
}
}




