
#ifndef "BOARD_H"
#define "BOARD_H"

#include "stdio.h"
#include "time.h"//����������������õ�time���� 
#include "conio.h"//����Windowsƽ̨����������ַ��������Ժͻس�ȷ�ϵ�getch()���� 
#include "windows.h"//����Windowsƽ̨������趨������λ�ôﵽ�������ܵĺ���

//��ʼ������ 
void start_game();
void reset_game();

//�ĸ������ƶ� 
void move_up();
void move_down();
void move_left();
void move_right();

void refresh_show();//ˢ�½���
void get_rand_num();
void get_null_count();//��ȡ��λ�õ����� 
int  check_game_over();//1��ʾ������Ϸ��0��ʾû�н��� 


#endif


