#include<reg52.h>

#define lcd  P1             //数据口

sbit lcd_psb =  P3^5;            //串/并方式控制  0=serial 1=parallel
sbit lcd_id  =  P3^2;            //寄存器选择输入 0=IR 1=DR 
sbit lcd_wr  =  P3^3;            //液晶读/写控制  0=write 1=read
sbit lcd_en  =  P3^4;            //液晶使能控制	  1 valid

bit lcd_busy();			//测忙
void initial_lcd(); //LCD初始化
void clear_lcd();		//LCD清屏

void write_lcd_com(unsigned char com);   	//写指令
void write_lcd_dat(unsigned char dat);		//写数据
unsigned char read_lcd_dat();             //读数据
	
void delay_ms(unsigned int z);   												//延时
void set_lcd_xy(unsigned char  x,unsigned char  y);			//设置坐标

void write_lcd_hanzi(unsigned char x,unsigned char y,unsigned char code *dat);   //写汉字
void write_lcd_shuzi(unsigned char x,unsigned char y,unsigned char code *dat);	 //写数字	

unsigned int test_point_exist(unsigned char x, unsigned char y, unsigned int value);	//
void draw_lcd_point(unsigned char x, unsigned char y, unsigned int value);						//
void clear_lcd_point(unsigned char x, unsigned char y, unsigned int value);						//