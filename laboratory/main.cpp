
#include "functions.h"

int fog;//管理员标志 ,=1为管理员 
int j;

 int main(){
 	
 	struct personal_message h,*pointer;//注意结构体指针的使用， 
 	pointer = &h;
 	
 	int m,back_flag; 	
 	int login_options;
 	
 	loop1:page_design1();//登录界面  
 	scanf("%d",&login_options);
 	system("CLS");//执行控制台命令cls,清屏 
 	
 	switch(login_options){
 		
	 	case 1:{//登录  
	 		enter();
	 		validate();
	 		system("CLS");	 		
	 	}break;
	 	
	 	case 2:{//注册  
	 		registe();
	 		system("CLS");
			 goto loop1;			 	
	 	}break;
	 	
	 	case 3:{//找回密码  
	 		find_password();	 		
	 		system("CLS");
	 		goto loop1;
	 	}break;
	 		 	
	 }
 	
 	
 	loop2:if((fp=fopen("information.txt","r"))==NULL){//显示个人信息  
	 	printf("can not open the file!\n");
	 	exit(0);	 	
	 }
	 
	 rewind(fp);
	 fseek(fp,j*sizeof(struct personal_message),0);
	 fread(&h,sizeof(struct personal_message),1,fp);//从文件中读取指定长度的内容 ,读一次 
	 
	 printf("姓名：%s",h.name);
	 printf("年龄：%s",h.age);
	 printf("性别：%s",h.gender);
	 printf("学号：%s",h.classes);
	 printf("QQ：%s",h.QQ);
	 printf("手机：%s",h.tel);
	 
	 if(fclose(fp)){
 		printf("can not close the file!\n");
 		exit(0);
 	}
 	
 	
 	page_design2();
 	
 	if(fog==1){//管理员选项  
	 	page_design3();
	 }
	 printf("/------------------------------/\n");
	 printf("请输入你的选择：");
	 scanf("%d",&m);
	 system("CLS");
	 
	 switch(m){
 		case 1:modificate_information();break;
 		case 2:resource_record();break;
 		case 3:borrow_repay();break;
 		case 4:modificate_password();break;
 		case 5:add_book();break;
 		case 6:consumables_record();break;
 		case 7:add_administrator();break;
 	}
 	
 	page_design6();//返回首页还是退出  
 	scanf("%d",&back_flag);
 	system("CLS");
 	if(back_flag==1)
 		goto loop2;
 		
	return 0;
 }
 


