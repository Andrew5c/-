
/****************
1�������ѱ����Ķ������Դ�ļ��У�������������ϵ�Դ�ļ���Ҫ���������������ô����ͷ�ļ����� extern �ؼ���
������һ�ξͿ����ˣ��Ϳ�����Ϊȫ�ֱ���ʹ�á�
2����������ͨ�����Ķ��壬���ǽṹ���������һ���� 
3��ͷ�ļ���ֻ�������� �� 
****************/

//���ú�����ͷ�ļ�
 
#ifndef FUNCTIONS_H__
#define FUNCTIONS_H__

#include "stdio.h"
#include "stdlib.h" //����system()
#include "conio.h" //����getch() 
#include "string.h"//����strcmp() 

#define MAX 20

/*�����ѱ���������Դ�ļ��У���ͷ�ļ����� extern ����Ϊȫ�ֱ��� */
extern int fog;//����Ա��־ ,=1Ϊ����Ա 
extern int j;
extern FILE *fp;//ָ�� information.txt  ���������������Դ�ļ��ж����õ� ��

struct personal_message{//���˻�����Ϣ 
	char name[MAX];
	char age[MAX];
	char gender[MAX];
	char QQ[MAX];
	char classes[MAX];
	char tel[MAX];
	
};

/*
syΪ�û���¼ʱ������û������������ʱ������
sdΪע�������Ա����Ϣ��ͨ���Ա���������������֪���û��Ƿ�ע����� 
*/
struct sysuser{//�û���������  
	char username[MAX];
	char password[MAX];
};


struct book{//ͼ����Ϣ  
	char book_name[MAX];
	char book_num[MAX];
	int member;
	int borrow;
	
};


struct consumables{//�Ĳ���Ϣ  
	char name[MAX];
	int member;
};

void registe();//ע��  
void enter();//��¼  
int  validate();//��֤����Ա  
void find_password();//�һ����� 
void modificate_information();  //�޸���Ϣ  
void modificate_password();//�޸�����  
void resource_record();//��ѯ�鼮��Ϣ 
void add_book();//����鼮 
void borrow_repay();//�鼮�軹 
void borrow();//���� 
void repay();//���� 
void consumables_record();//�ĲĹ���  
void check_consumables();//��ѯ�Ĳ� 
void add_consumables();//��ӺĲ� 
void add_administrator();//��ӹ���Ա  
void star(char password[]);//����ת��Ϊ * ��  
  
void page_design1();  //��¼ҳ�� 
void page_design2();   //�û���������     
void page_design3();  //����Ա�������� 
void page_design4();  //���黹��ѡ����� 
void page_design5();  //ʵ���Ҳ��� �鿴���� 
void page_design6();  //���ؽ���  

 

#endif

