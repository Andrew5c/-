
/****************
1、尽量把变量的定义放在源文件中，如果有两个以上的源文件需要引用这个变量，那么就在头文件中用 extern 关键字
在声明一次就可以了，就可以作为全局变量使用。
2、不管是普通变量的定义，还是结构体变量都是一样。 
3、头文件中只用来声明 。 
****************/

//引用函数的头文件
 
#ifndef FUNCTIONS_H__
#define FUNCTIONS_H__

#include "stdio.h"
#include "stdlib.h" //包含system()
#include "conio.h" //包含getch() 
#include "string.h"//包含strcmp() 

#define MAX 20

/*尽量把变量定义在源文件中，在头文件中用 extern 声明为全局变量 */
extern int fog;//管理员标志 ,=1为管理员 
extern int j;
extern FILE *fp;//指向 information.txt  ，这个变量在两个源文件中都有用到 ，

struct personal_message{//个人基本信息 
	char name[MAX];
	char age[MAX];
	char gender[MAX];
	char QQ[MAX];
	char classes[MAX];
	char tel[MAX];
	
};

/*
sy为用户登录时输入的用户名和密码的临时变量；
sd为注册过的人员的信息，通过对比这两个变量，可知此用户是否注册过。 
*/
struct sysuser{//用户名和密码  
	char username[MAX];
	char password[MAX];
};


struct book{//图书信息  
	char book_name[MAX];
	char book_num[MAX];
	int member;
	int borrow;
	
};


struct consumables{//耗材信息  
	char name[MAX];
	int member;
};

void registe();//注册  
void enter();//登录  
int  validate();//验证管理员  
void find_password();//找回密码 
void modificate_information();  //修改信息  
void modificate_password();//修改密码  
void resource_record();//查询书籍信息 
void add_book();//添加书籍 
void borrow_repay();//书籍借还 
void borrow();//借书 
void repay();//还书 
void consumables_record();//耗材管理  
void check_consumables();//查询耗材 
void add_consumables();//添加耗材 
void add_administrator();//添加管理员  
void star(char password[]);//密码转换为 * 号  
  
void page_design1();  //登录页面 
void page_design2();   //用户操作界面     
void page_design3();  //管理员操作界面 
void page_design4();  //借书还书选择界面 
void page_design5();  //实验室材料 查看界面 
void page_design6();  //返回界面  

 

#endif

