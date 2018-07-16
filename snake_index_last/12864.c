#include<12864.h>

bit lcd_busy()
 {                          
    unsigned int he;
		bit result;
		lcd=0xff;
		lcd_id=0;
		lcd_wr=1;
    lcd_en = 1;
		he = lcd;
    lcd_en = 0;
    result = (bit)(he&0x80);
    return(result); 
 }


void initial_lcd()
{ 
    lcd_psb = 1;
	
    write_lcd_com(0x30);
		delay_ms(1);
	
    write_lcd_com(0x34);
		delay_ms(1);

		write_lcd_com(0x0c);
		delay_ms(1);
	
    write_lcd_com(0x01);  
    delay_ms(10);

		write_lcd_com(0x34);//扩展指令模式 0x30为基本指令模式
		write_lcd_com(0x36);//打开图片显示

}

void clear_lcd()
{
	unsigned char i,j;
	
	for(i=0;i<32;i++)
	{
		for(j=0;j<16;j++)
		{			
			set_lcd_xy(j,i);			

			write_lcd_dat(0x00);
			write_lcd_dat(0x00);
		}
		
	}
}


void write_lcd_com(unsigned char com)
{                          
	while(lcd_busy());
	lcd_id=0;
	lcd_wr=0;
  lcd=com;
	lcd_en=1;
	lcd_en=0;  
}


void write_lcd_dat(unsigned char dat)
{                          
	while(lcd_busy());
  lcd_id=1;
	lcd_wr=0;
  lcd=dat;
	lcd_en=1;
	lcd_en=0; 
	
}

unsigned char read_lcd_dat() 
{
	unsigned char save;
	while(lcd_busy());
	lcd_id=1;
	lcd_wr=1;
	lcd_en=1;
	save=lcd;
	lcd_en=0;
	return(save);
}



void delay_ms(unsigned int z)
{
	unsigned int i,j;
	for(i=z;i>0;i--)
		for(j=110;j>0;j--);
}


void set_lcd_xy(unsigned char  x,unsigned char  y)
{
	write_lcd_com(0x80+y);
	write_lcd_com(0x80+x);
}


void write_lcd_hanzi(unsigned char x,unsigned char y,unsigned char code *dat)
{
	unsigned char i;
	for(i=y;i<=y+15;i++)
	{
		set_lcd_xy(x,i);
		write_lcd_dat(dat[(i-y)*2]);
		write_lcd_dat(dat[(i-y)*2+1]);
	}
}

void write_lcd_shuzi(unsigned char x,unsigned char y,unsigned char code *dat)
{
	unsigned char i;
	for(i=y;i<=y+15;i++)
	{
		set_lcd_xy(x,i);
		write_lcd_dat(dat[i-y]);
	}
}

unsigned int test_point_exist(unsigned char x, unsigned char y, unsigned int value)
{
	unsigned int he;
	unsigned int hui1=0,hui2=0;
	set_lcd_xy(x,y);
	hui1=read_lcd_dat();
	hui1=read_lcd_dat();
	hui2=read_lcd_dat();
	he=(hui1<<8)|(hui2);
	he=he&value; //如果液晶上这个点是亮的 则he为value 若不亮则为 0
	return (he);
}

void draw_lcd_point(unsigned char x, unsigned char y, unsigned int value)
{
	unsigned int he;
	unsigned int hui1=0,hui2=0;
	set_lcd_xy(x,y);
	hui1=read_lcd_dat();
	hui1=read_lcd_dat();
	hui2=read_lcd_dat();
	he=(hui1<<8)|(hui2);//he为当前的现场
	he=he+value; //保证只会在这个点没有点亮的情况下来点亮这个点
	set_lcd_xy(x,y);
	write_lcd_dat(he>>8);
	write_lcd_dat(he);
}

void clear_lcd_point(unsigned char x, unsigned char y, unsigned int value)
{
	unsigned int he;
	unsigned int hui1=0,hui2=0;
	set_lcd_xy(x,y);
	hui1=read_lcd_dat();
	hui1=read_lcd_dat();
	hui2=read_lcd_dat();
	he=(hui1<<8)|(hui2);//he为当前的现场
	he=he-value; //会保证只会在这个点已经点亮的情况下来熄灭这个点
	set_lcd_xy(x,y);
	write_lcd_dat(he>>8);
	write_lcd_dat(he);
}

