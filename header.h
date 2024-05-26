//#include<stdio.h>
extern void uart1_init(unsigned int baud);
extern void uart1_tx(unsigned char data);
extern void uart1_tx_string(char *ptr);
extern unsigned char uart1_rx(void);
extern void uart1_rx_string(char *ptr,signed int max_bytes);
extern void uart1_tx_float(float num);
extern void uart1_tx_int(int num);

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern void uart0_tx_string(char *ptr);
extern unsigned char uart0_rx(void);
extern void uart0_rx_string(char *ptr,signed int max_bytes);
extern void uart0_tx_float(float num);
extern void uart0_tx_integer(int num);

extern void UART0_Handler(void)__irq;
extern void config_vic(void);
extern void en_uart0_interrupt(void);

extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_string(char *ptr);
extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);

extern void i2c_byte_write_frame(unsigned char sa,unsigned char mr,unsigned char data);
extern unsigned char i2c_byte_read_frame(unsigned char sa,unsigned char mr);
extern void i2c_init(void);

//extern unsigned int i;
//extern char h[50];
