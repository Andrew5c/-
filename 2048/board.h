
#ifndef "BOARD_H"
#define "BOARD_H"

#include "stdio.h"
#include "time.h"//产生随机数种子所用的time函数 
#include "conio.h"//包含Windows平台上完成输入字符不带回显和回车确认的getch()函数 
#include "windows.h"//包含Windows平台上完成设定输出光标位置达到清屏功能的函数

//开始与重启 
void start_game();
void reset_game();

//四个方向移动 
void move_up();
void move_down();
void move_left();
void move_right();

void refresh_show();//刷新界面
void get_rand_num();
void get_null_count();//获取空位置的数量 
int  check_game_over();//1表示结束游戏，0表示没有结束 


#endif


