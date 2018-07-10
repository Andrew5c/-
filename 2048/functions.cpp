

#include "board.h"


int game[4][4];//��Ϸ����Ϊһ����ά���� 
int score;//�÷� 
int best_score;
int if_add_rand_num;//�Ƿ���Ҫ�����������־ 

/* ��ʼ��Ϸ*/
void start_game()
{
	printf("welcome to 2048!\n");
	reset_game();
	char cmd;
	while(1)
	{
		cmd = _getch();//
		if(check_game_over)//�����Ϸ ��һֱѭ������ 
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
		
		if_add_rand_num = 0;//�տ�ʼĬ�ϲ���Ҫ��������� 
		
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
		
		score>best_score?best_score = score:1;//�Ƿ���Ƶ÷ּ�¼ 
		
		if(if_add_rand_num)
		{
			get_rand_num();
			refresh_show();
			
		}
	}
		
}


/*������Ϸ*/
void reset_game()
{
	score = 0;
	if_add_rand_num = 1;//�տ�ʼ��Ҫ���������
	
	//��Ϸ�տ�ʼ�������������һ��2
	int n = rand()%16;       //��n������0��16֮�� 
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


/* ��ȡ�����*/
void get_rand_num()
{
	srand(time(0));
	int n = rand()%get_null_count();
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<4;j++)
		{
			if(game[i][j] = 0&&n-- = 0)//ȷ���������λ�� 
			{
				game[i][j] = (rand()%3?2:4);//����2��4���ʵ����������Ǻܶ� 
				
			}
		}
	} 
}


