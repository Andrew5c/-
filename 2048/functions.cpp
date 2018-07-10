

#include "board.h"


int game[4][4];//游戏抽象为一个二维数组 
int score;//得分 
int best_score;
int if_add_rand_num;//是否需要生成随机数标志 

/* 开始游戏*/
void start_game()
{
	printf("welcome to 2048!\n");
	reset_game();
	char cmd;
	while(1)
	{
		cmd = _getch();//
		if(check_game_over)//输掉游戏 ，一直循环检验 
		{	
			if(cmd='y'||cmd='Y')
			{
				reset_game();
				continue;
			}
			else if (cmd='n'||cmd='N')
			{
				break;
			}
			else continue;
		} 
		
		if_add_rand_num = 0;//刚开始默认不需要生成随机数 
		
		switch(cmd)
		{
			case 'a':
			case 'A':
			move_left();break;
			case 's':
			case 'S':
			move_down();break;
			case 'd':
			case 'D':
			move_right();break;
			case 'w':
			case 'W':
			move_up();break;
			
		}
		
		score>best_score?best_score = score:1;//是否打破得分纪录 
		
		if(if_add_rand_num)
		{
			get_rand_num();
			refresh_show();
			
		}
	}
		
}


/*重置游戏*/
void reset_game()
{
	score = 0;
	if_add_rand_num = 1;//刚开始需要生成随机数
	
	//游戏刚开始都是先随机生成一个2
	int n = rand()%16;       //把n限制在0到16之间 
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<4;j++)
		{
			game[i][j] = (n-- == 0 ? 2 : 0);
		}
	
	}
	get_rand_num();
	refresh_show();
		 
}


/* 获取随机数*/
void get_rand_num()
{
	srand(time(0));
	int n = rand()%get_null_count();
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<4;j++)
		{
			if(game[i][j] = 0&&n-- = 0)//确定随机数的位置 
			{
				game[i][j] = (rand()%3?2:4);//生成2是4概率的两倍，不是很懂 
				
			}
		}
	} 
}


