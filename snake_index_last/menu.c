#include<12864.h>
#include<resource.h>

struct menu_index 	//菜单指针
{
	unsigned char up_num;					//向上
	unsigned char down_num;				//向下
	unsigned char confirm_num;		//确定
	unsigned char cansel_num;			//返回
};


struct menu_index code menu_num[11]=
{
							//第一层菜单
	{2,1,3,0},   	//0：开始游戏
	{0,2,4,0},		//1：选择地图
	{1,0,8,0},		//2：选择困难

							//进入游戏
	{0,0,0,0},		//3：进入游戏
						
							
	{5,5,4,1},		//4：无地图
	{4,4,5,1},   	//5：地图壹
	//地图3 4 未用
	{5,7,6,1},		//6：地图贰
	{6,4,7,1},		//7：地图叁
						
							//选择难度
	{10,9,8,2},		//8：变态
	{8,10,9,2},		//9：困难
	{9,8,10,2},		//10：简单
	
};


unsigned char present_menu_num; 			//菜单的初始化
extern unsigned char flag_exit_game;	//返回标志  为1时  从贪吃蛇游戏返回菜单
extern unsigned char tcs_nd;					//贪吃蛇难度的选择
extern unsigned char tcs_dt;					//贪吃蛇地图的选择 这2个是全局变量 


void menu_change(unsigned char he);	//这个函数用来执行当前菜单号指示的菜单需要进行的操作
void menu1();
void menu2();
void menu3();

void choose(unsigned char n);	//选中的动画
void shadow(unsigned char n);	//液晶的反白显示

void key_down(); 		//键盘
void tcs_game(); 		//游戏
void game_over();		//游戏结束



void main()
{
	initial_lcd();	//初始化

	clear_lcd();		//清屏
	
	present_menu_num = 0;
	menu_change(present_menu_num);//显示菜单

	while(1)
	{
		key_down();	
	}
	
}



void menu_change(unsigned char he)
{
	switch(he)
	{
		case 0 : { menu1();  shadow(0); break; }
		case 1 : { menu1();  shadow(1); break; }
		case 2 : { menu1();  shadow(2); break; }//0-2为第二层菜单
															   
		case 3 : {
								tcs_game();
								if(flag_exit_game == 1)
								{
									present_menu_num = 0;
									menu1();  shadow(0);
									break;
								}  
								else
								{ 
									game_over();
									break;
								}
							}
		case 4 :  { menu2();  choose(0); tcs_dt = 0; break; }
		case 5 :  { menu2();  choose(1); tcs_dt = 1; break; }
	//	case 6 :  { menu2();  choose(2); tcs_dt = 2; break; }
		//case 7 :  { menu2();  choose(3); tcs_dt = 3; break; }    //4—7为选择贪吃蛇的地图

		case 8  :  { menu3();  choose(0); tcs_nd = 0; break; }
		case 9  :  { menu3();  choose(1); tcs_nd = 1; break; }
		case 10 :  { menu3();  choose(2); tcs_nd = 2; break; }   //8-9为选择贪吃蛇的难度
			
	}
}



void menu1()
{
	unsigned int i;
	clear_lcd();
	for(i=0;i<16;i++)
	{
		if(i<4)		write_lcd_hanzi(i,0,&ksyx[i][0]);
		if(i<4)		write_lcd_hanzi(i,16,&xzdt[i][0]);
		if( (i>=8) && (i<=11) )		write_lcd_hanzi(i,0,&xznd[i-8][0]);
	}
}


void menu2()
{
	unsigned int i;
	clear_lcd();
	for(i=0;i<16;i++)
	{
		if(	(i>=1) && (i<=3)  )		write_lcd_hanzi(i,0,&wdt[i-1][0]);
		if(	(i>=1) && (i<=3)  )		write_lcd_hanzi(i,16,&dty[i-1][0]);
//		if( (i>=9) && (i<=11) )		write_lcd_hanzi(i,0,&dte[i-9][0]);
//		if( (i>=9) && (i<=11) )		write_lcd_hanzi(i,16,&dts[i-9][0]);
	}
}


void menu3()
{
	unsigned int i;
	clear_lcd();
	for(i=0;i<16;i++)
	{
		if(	(i>=2) && (i<=3)  )		write_lcd_hanzi(i,0,&bt[i-2][0]);
		if(	(i>=2) && (i<=3)  )		write_lcd_hanzi(i,16,&kn[i-2][0]);
		if( (i>=10) && (i<=11) )		write_lcd_hanzi(i,0,&jd[i-10][0]);
	}
}



//传参数 0 1 2 3 分别用来选中 1  2 3 4行 并有对勾的动画
void choose(unsigned char n)
{
	unsigned char i,j,hui1,hui2;
	unsigned char x,y;
	unsigned int code he[16]={0x8000,0xc0000,0xe000,0xf000,	0xf800,0xfc00,0xfe00,0xff00,	0xff80,0xffc0,0xffe0,0xfff0,	0xfff8,0xfffc,0xfffe,0xffff};
	switch(n)
	{
		case 0:	{y=0;x=4;break;}
		case 1:	{y=16;x=4;break;}
		case 2:	{y=0;x=12;break;}
		case 3:	{y=16;x=12;break;}
	}
	write_lcd_hanzi(x-4,y,&jt[0]);
	for(i=0;i<=15;i++)
 	{
		delay_ms(20);
		hui1=he[i]>>8;
		hui2=he[i];
		for(j=y;j<=y+15;j++)
		{
			set_lcd_xy(x,j);
			write_lcd_dat(	(dg[(j-y)*2])&(hui1)	);
			write_lcd_dat(	(dg[(j-y)*2+1])&(hui2)	);
		}
	}
}


//传参数 0 1 2 3   分别用来反白显示 1 2 3 4 行
void shadow(unsigned char n)
{
	unsigned char he,hui,i,j;
	unsigned char x,y;
	switch(n)
	{
		case 0:	{y=0;x=0;break;}
		case 1:	{y=1;x=0;break;}
		case 2:	{y=0;x=1;break;}
		case 3:	{y=1;x=1;break;}
	}	
	for(i=0+y*16;i<=15+y*16;i++)	
		for(j=0+x*8;j<=7+x*8;j++)
		{
			set_lcd_xy(j,i);
			he=read_lcd_dat();
			he=read_lcd_dat();
			hui=read_lcd_dat();
			he=he^(0xff);
			hui=hui^(0xff);
			set_lcd_xy(j,i);
			write_lcd_dat(he);
		  write_lcd_dat(hui);
		}
}




void game_over()
{
	unsigned int i;
	clear_lcd();
	for(i=0;i<16;i++)
	{
		if(i<7)		write_lcd_hanzi(i,16,&sbnbjcs[i][0]);
		if( (i>=9) && (i<=15) )		write_lcd_hanzi(i,0,&dxqcxlg[i-9][0]);
	}	
}




void key_down()
{
	unsigned char h;
	if((P2&0xfe)!=0xfe)
	{
		delay_ms(10);
		if ((P2&0xfe)!=0xfe) 
		{
			h=P2&0xfe;
			switch(h)
			{
				case 0xfc:	{
								present_menu_num=menu_num[present_menu_num].confirm_num;
								menu_change(present_menu_num);
								break;
							}	// 确定键
	
				case 0xfa:	{
								present_menu_num=menu_num[present_menu_num].cansel_num;
								menu_change(present_menu_num);
								break;
							}	//返回键

				case 0xbe:	{
								present_menu_num=menu_num[present_menu_num].up_num;
								menu_change(present_menu_num);
								break;
							}	//↑

				case 0xee: 	break;	//←

				case 0xde:  {
								present_menu_num=menu_num[present_menu_num].down_num;
								menu_change(present_menu_num);
								break;
							}		//↓

				case 0x7e:  break;	//->
			}
			while( (P2&0xfe)!=0xfe );
			P2=0xff;
			delay_ms(10);
		}
				
	}
}

