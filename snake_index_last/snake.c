#include <12864.h>
#include <snake_resource.h>
#define num 7

//用来描述蛇在液晶上面一个点的结构体
struct she
{
	unsigned char x,y;
	unsigned int value;
	unsigned char direction;	
};

struct loop_queue  //利用数组实现循环队列，拐点不会超过15个。所以大小选15足以。
{    
	unsigned int front;
	unsigned int rear;
	unsigned int count;
	struct she dat[num];
};
//不熟悉数组实现循环队列的可以在纸上画一下操作过程

struct she tou,wei,food; //蛇的头尾节点  和食物点 
struct loop_queue queue;//循环队列  蛇转弯则形成拐点 将拐点入队列  尾巴到达拐点则拐点出队列 

unsigned char flag_exit_game; //返回标志  为1时  从贪吃蛇游戏返回菜单
unsigned char flag_game_over; //结束标志  为1时  显示游戏结束画面 同时使返回标志为1
unsigned char tcs_key_flag;  //贪吃蛇在一次移动中   只允许捕获一次按键  也就是只能产生一个拐点
unsigned char tcs_key_state; //用于按键状态机的实现
unsigned int  tcs_df;  //贪吃蛇得分
unsigned char tcs_stop;//贪吃蛇暂定功能的实现

unsigned char tcs_nd=2;  //贪吃蛇难度的选择
unsigned char tcs_dt;  //贪吃蛇地图的选择 这2个是全局变量  在menu里面要用到 


void tcs_bianjie(unsigned int he);//贪吃蛇游戏地图的实现和边界
void timer0_initial();
void timer1_initial();

//循环队列的基本操作
void queue_initial(struct loop_queue *q);  
void queue_in(struct loop_queue *q,struct she h)  ;
struct she queue_out(struct loop_queue *q)  ;

void tcs_game_initial();
void food_produce();

void tcs_game()
{
	struct she check;  //用与暂存蛇即将移动的点  从而进行判断
	unsigned int he;
	unsigned char flag;//flag作为吃到食物的标志

	flag_exit_game=0; 
	flag_game_over=0;
	tcs_key_state=0;
	tcs_df=0;
	tcs_stop=1;

//	draw_lcd_picture(&tcs_picture[0]); //贪吃蛇游戏画面
//	delay_ms(2000);

	tcs_bianjie(tcs_dt); //贪吃蛇游戏边界
	tcs_game_initial();//贪吃蛇初始化  主要是设定蛇头蛇尾  并显示蛇
	timer0_initial(); //定时器0工作在方式2  8位自动装初值  只计数不中断 用来产生随机数
	timer1_initial(); //定时器1工作在方式1	16位     10ms中断一次扫描键盘

	do
	{
		food_produce();//产生一个随机数 即随即产生x y value3个值确定一个点为食物
		he=test_point_exist(food.x,food.y,food.value);//检测产生的点的地方是否已经有点存在
	}
	while(he==food.value);//如果随机数产生在蛇的身体以及边界上 则重新再产生一个  
	draw_lcd_point(food.x,food.y,food.value);//显示食物 先读取这个点所在xy的情况 以免破坏现场
	
	queue_initial(&queue);//初始化循环队列  使队列空  front rear 即头尾指针为0

	while(1)
	{
		if(flag_exit_game==1)//如果游戏过程中按下返回键  则立即结束游戏  返回菜单
			break;
		if(flag_game_over==1)//如果游戏过程中蛇死了  则立即结束游戏 显示结束动画 按键后返回菜单
			break;
		
		ET1=1;   //允许扫描按键	  贪吃蛇游戏难度决定蛇2次移动之间的间隔时间  也就是检测按键的时间
		tcs_key_flag=0; //允许捕获按键  在检测按键时间内  只允许生产一个拐点  即捕获到一个有效的
						//按键以后  就置一这个变量 不允许再增加拐点
		while(tcs_stop==0);//暂定键按下会取反tcs_stop的值  从而实现暂停功能
		switch(tcs_nd)
		{
			case 0:  {delay_ms(50); break;}//0代表变态难度  蛇的2次移动之间只有10ms的机会检测键盘按下
			case 1:  {delay_ms(100); break;}//难度减小  2次移动间隔增加
			case 2:  {delay_ms(150); break;}
		}
		ET1=0; 

		switch(tou.direction)//这个switch用来根据蛇头的x y value值以及当前蛇头移动的方向 
							 //取出蛇头要到达的下一个点  存入check中  来判断是否撞墙 吃到食物 什么的···
		{	
			case 0: { 	
						check.y=tou.y; 
						if(tou.value==0x0001)//x的值要发生改变
						{
							if(tou.x==3)//蛇碰到上屏幕的右边界  则回到左边界 
								check.x=0;
							else if(tou.x==11)//蛇碰到下屏幕的右边界  则回到左边界
								check.x=8;
							else
								check.x=tou.x+1;
							check.value=0x8000;
						}
						else
						{
							check.x=tou.x;
							check.value=tou.value>>1;
						}
						 break ;
					}//->向右y不变 

			case 1: {//向下value值不变 					 
						check.value=tou.value;
						if(tou.y==31) //蛇头从在上下屏之间移动
						{
							if(tou.x<=3)//蛇头从上屏移动到下屏
								check.x=tou.x+8;
							else 		//蛇头从下屏移动到上屏
								check.x=tou.x-8;
							check.y=0;
						}
						else
						{
							check.y=tou.y+1;
							check.x=tou.x;  //蛇头的x值不变
					    }
						break ;
					}

			case 2: {//<-向左y不变 	
						check.y=tou.y; 
						if(tou.value==0x8000)//x的值要发生改变
						{
							if(tou.x==0)//蛇碰到上屏幕的左边界  则回到右边界 
								check.x=3;
							else if(tou.x==8)//蛇碰到下屏幕的左边界  则回到右边界
								check.x=11;
							else
								check.x=tou.x-1;
							check.value=0x0001;
						}
						else
						{
							check.x=tou.x;
							check.value=tou.value<<1;
						}
						 break ;
					}

			case 3: { //↑	 向上value不变
						check.value=tou.value;
						if(tou.y==0) //蛇头从在上下屏之间移动
						{
							if(tou.x<=3)//蛇头从上屏移动到下屏
								check.x=tou.x+8;
							else 		//蛇头从下屏移动到上屏
								check.x=tou.x-8;
							check.y=31;
						}
						else
						{
							check.y=tou.y-1;
							check.x=tou.x;  //蛇头的x值不变
					    }
						break ;
					}	
		}			
		flag=0;//初始化吃到食物标志  表示没有吃到	
		he=test_point_exist(check.x,check.y,check.value); // 检测蛇头移动的下一个点是否几经有点存在
		if(he==check.value) //如果前面的点已经存在	则可以是食物 或者是墙和蛇身
		{
			if(	(check.x==food.x) && (check.y==food.y) && (check.value==food.value) )//吃到食物
			{
				flag=1;//吃到食物
				tcs_df++;
				write_lcd_shuzi(5,16,tcs_shuzi[tcs_df/100]       ); 			//显示分数的百位
				write_lcd_shuzi(6,16,tcs_shuzi[ (tcs_df%100)/10] );				//			十
				write_lcd_shuzi(7,16,tcs_shuzi[tcs_df%10]        );				//          个
			
				food.direction=tou.direction;//食物本没有方向 但是为了下面的语句
				tou=food; //食物就成了蛇头···蛇头的方向依然不变
				 
				do
				{
					food_produce();
					he=test_point_exist(food.x,food.y,food.value);
				}
				while(he==food.value);  
				draw_lcd_point(food.x,food.y,food.value);//上面有说过  这个是产生并显示食物
			}
			else//撞到身体或者墙
			{
				flag_game_over=1; // 游戏结束
			}
		}
		else  //什么都么有遇到 继续前进
		{
			check.direction=tou.direction;//这么做的理由同上 为了保持蛇头当前的移动方向
			tou=check;
			draw_lcd_point(tou.x,tou.y,tou.value);//画出此时的蛇头
		}

		//下面是对尾巴的操作		
		
		if(flag==1)//如果吃到食物 直接结束此轮循环 尾巴不做任何操作
		{
		
		}
		else
		{
			if (  (wei.x == queue.dat[queue.front].x) && ( wei.y==queue.dat[queue.front].y ) && ( wei.value== queue.dat[queue.front].value)  ) //如果尾巴到达拐点
			{
			 	check=queue_out(&queue); 	
				wei.direction=check.direction; //尾巴按照拐点指示的方向走
			}
			else //如果没有到达拐点 尾巴移动的方向不变
			{
					
			}						
									
			switch( wei.direction ) //这个是尾巴的移动  以及尾巴节点数据的修改
			{
				case 0:	{//->向右y不变	
							clear_lcd_point(wei.x,wei.y,wei.value);
							if(wei.value==0x0001)//x的值要发生改变
							{
								if(wei.x==3)//蛇碰到上屏幕的右边界  则回到左边界 
									wei.x=0;
								else if(wei.x==11)//蛇碰到下屏幕的右边界  则回到左边界
									wei.x=8;
								else
									wei.x=wei.x+1;
								wei.value=0x8000;
							}
							else
							{
								wei.value=wei.value>>1;
							}
							break;
						}
				case 1:	{//向下value值不变	
							clear_lcd_point(wei.x,wei.y,wei.value);
							if(wei.y==31) //蛇从在上下屏之间移动
							{
								if(wei.x<=3)//蛇从上屏移动到下屏
									wei.x=wei.x+8;
								else 		//蛇从下屏移动到上屏
									wei.x=wei.x-8;
								wei.y=0;
							}
							else
							{
								wei.y=wei.y+1;
						    }
							break ;
							
					   	 }										
				case 2:	{//<-向左y不变   
							clear_lcd_point(wei.x,wei.y,wei.value);
							if(wei.value==0x8000)//x的值要发生改变
							{
								if(wei.x==0)//蛇碰到上屏幕的左边界  则回到右边界 
									wei.x=3;
								else if(wei.x==8)//蛇碰到下屏幕的左边界  则回到右边界
									wei.x=11;
								else
									wei.x=wei.x-1;
								wei.value=0x0001;
							}
							else
							{
								wei.value=wei.value<<1;
							}
							break;
						 }
				case 3:	{//↑	 向上value不变  
							clear_lcd_point(wei.x,wei.y,wei.value); 
							if(wei.y==0) //蛇从在上下屏之间移动
							{
								if(wei.x<=3)//蛇从上屏移动到下屏
									wei.x=wei.x+8;
								else 		//蛇从下屏移动到上屏
									wei.x=wei.x-8;
								wei.y=31;
							}
							else
							{
								wei.y=wei.y-1;
					   		 }
							break;
						 }	
  			}
		}							
	}	
	TR0=0;
	TR1=0;
	ET1=0;  //退出游戏时 关闭游戏过程中用到的定时器0和1  然后定时器中断也要关闭


}

//状态机实现按键   参考里面资料别人的技术贴
void timer1() interrupt 3
{	
	unsigned char tou_last_direction; //记录蛇头原来的移动方向
	
	TR1=0;
	TH1=0xDC;		
	TL1=0x00;

	switch (tcs_key_state)
	{
		case 0:	{		// 按键初始态
					if ( (P2 & 0xfe) != 0xfe )   tcs_key_state = 1;	// 键被按下，状态转换到键确认态
						else	  tcs_key_state = 0;
					break;
				}
	
		case 1:	{			// 按键确认态
					if ( (P2 & 0xfe) != 0xfe)
					{
						// 按键仍按下，此时确定记录一次有效按键
							tcs_key_state = 2;	// 状态转换到键释放态
							if(tcs_key_flag==0 )	 //如果此时允许捕获按键
							{
								tou_last_direction=tou.direction;
								if(tcs_stop == 1)
								{
									switch(P2 & 0xfe)
									{	
										case 0xfc:	break; // 确定键  不进行任何操作
										case 0xfa:	{  flag_exit_game=1;   break; }//返回键  	 结束游戏 返回菜单
										case 0xbe:	{  tou.direction=3;break; }//↑
										case 0xee:	{  tou.direction=2;break; }//←
										case 0xde:	{  tou.direction=1;break; }//↓
										case 0x7e:	{  tou.direction=0;break; }//->	 
										case 0xf6:  {  if(tcs_stop==0) tcs_stop=1; else tcs_stop=0; break;}//暂停键
									}
						
									if( (tou.direction==tou_last_direction) || (tou.direction+tou_last_direction==2) || (tou.direction+tou_last_direction==4) )
									//如果本来就是按此方向移动   或者按键给的方向与蛇移动方向相反 则不做任何操作 此次按键无效
									{
										tou.direction=tou_last_direction; //   还原蛇头的移动方向
									}
									else //否则记录此头结点成为拐点           
									{			
										queue_in(&queue,tou);
										tcs_key_flag=1; //已经捕获到一次按键信息 这次移动拐点已经产生 关闭捕获键盘 
									}
								}
								else
								{
									if((P2 & 0xfe) == 0xf6)	tcs_stop = 1;
								}
							}

					}
					else
					{
						tcs_key_state = 0;	// 按键已抬起，转换到按键初始态
						break;
					}
				}

		case 2:	{           //等待按键弹起状态
						if ( (P2 & 0xfe) == 0xfe) tcs_key_state=0;	//按键已释放，转换到按键初始态
						else	  tcs_key_state = 2;
						break;
				}	
	}	 		
	TR1=1;
}

void tcs_bianjie(unsigned int he)
{
	unsigned char i,j;
	clear_lcd();
	for(i=0;i<=31;i++)
		for(j=0;j<=3;j++)
		{
			set_lcd_xy(j,i);
			write_lcd_dat(tcs_map[he][i*8+j*2]); 
			write_lcd_dat(tcs_map[he][i*8+j*2+1]);
		}
	for(i=0;i<=31;i++)
		for(j=8;j<=11;j++)
		{
			set_lcd_xy(j,i);
			write_lcd_dat(tcs_map[he][256+i*8+(j-8)*2]);
			write_lcd_dat(tcs_map[he][256+i*8+(j-8)*2+1]);
		}
	//到这里是画地图	

	write_lcd_hanzi(4,0,df[0]);
	write_lcd_hanzi(5,0,df[1]);

	write_lcd_shuzi(5,16,tcs_shuzi[tcs_df/100]       ); 			//显示分数的百位
	write_lcd_shuzi(6,16,tcs_shuzi[ (tcs_df%100)/10] );				//			十
	write_lcd_shuzi(7,16,tcs_shuzi[tcs_df%10]        );				//          个


	write_lcd_hanzi(12,0,jb[0]);
	write_lcd_hanzi(13,0,jb[1]);

	switch(tcs_nd)
	{ 
		case 0 :  { write_lcd_hanzi(14,16,tcs_bt[0]); write_lcd_hanzi(15,16,tcs_bt[1]);  break;}
		case 1 :  { write_lcd_hanzi(14,16,tcs_kn[0]); write_lcd_hanzi(15,16,tcs_kn[1]);  break;}
		case 2 :  { write_lcd_hanzi(14,16,tcs_jd[0]); write_lcd_hanzi(15,16,tcs_jd[1]);  break;}
	}
}
void timer0_initial()
{ 	
	TMOD=(0xf0 & TMOD) | 0x01; //定时器0 8位自动装初值(TH0->TL0)定时器模式   用来产生随机数
	TH0=0x00;
	TL0=0x00;
	TR0=1;   
}

void timer1_initial()
{ 	
	EA=1;
	TMOD= (0x0f & TMOD) | 0x10 ; //定时器一16位定时器模式 	10ms中断一次  用来扫描键盘
	TH1=0xDC;//10ms中断一次
	TL1=0x00;
	TR1=1;   
}

void queue_initial(struct loop_queue *q)   
{   
    struct she check;
	unsigned int i;
	q->front =q->rear=0;   
    q->count = 0;
	check.x=0;
	check.y=0;
	check.value=0;
	check.direction=0;
	for(i=0;i<num;i++)
		queue.dat[i]=check;   
}   

void queue_in(struct loop_queue *q,struct she h)  
{   
        q->dat[q->rear] = h;   
        q->rear = (q->rear + 1) % num;   
        q->count = q->count + 1;   
}   
  
struct she queue_out(struct loop_queue *q)   
{   
        struct she he;
		he = q->dat[q->front];   
        q->front = (q->front + 1) % num;   
        q->count = q->count - 1;
		return (he);   
}  

void tcs_game_initial()
{
	unsigned char he;
	tou.x=0;
	tou.y=5;
	tou.value=0x0001;      //初始化蛇头
	tou.direction=0;    // 初始化蛇头移动方向为向右 

	wei.x=0;
	wei.y=5;
	wei.value=0x0080;		//初始化蛇尾
	wei.direction=0;
	
	set_lcd_xy(0,5);
	he=read_lcd_dat();
	he=read_lcd_dat();
	set_lcd_xy(0,5);
	write_lcd_dat(he);
	write_lcd_dat(0xff);
}

void food_produce()
{
	unsigned char code a[16]={0x0001,0x0002,0x0004,0x0008,	0x0010,0x0020,0x0040,0x0080,	0x0100,0x0200,0x0400,0x0800,	0x1000,0x2000,0x4000,0x8000};
	unsigned char code b[16]={0,1,2,3,8,9,10,11,0,1,2,3,8,9,10,11};
	    	
	food.x=b[ TL0 & 0x0f];  //取TL0的低四位 用0-15的数确定食物的x值
	food.y= (TL0 & 0x0f) + (TL0 & 0xf0)>>4 + 1;// 用0-31的数确定食物的y值
	food.value=a[TL0 & 0x0f]; //用0-15的数   在数组中找出value的值
}


