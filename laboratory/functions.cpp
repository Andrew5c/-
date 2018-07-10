
//函数实现部分 
 
#include "functions.h"

/*定义结构体变量*/
struct personal_message p;
struct sysuser sd,sy;
struct book books1,books2[50];
struct consumables con1,con2;

/*FILE为变量类型，定义一个 fp 指针 */
FILE *fp;//指向 information.txt  
FILE *fp1;//指向 resource.txt
FILE *fp2;//指向consumables.txt
FILE *fp3;//指向 sysusers.txt  



/*****************登录**********************/
void enter(){
	
	int count = 0;
	while(1){
		printf("请输入用户名：");
		scanf("%s",sy.username);
		printf("请输入密码：");
		star(sy.password);
		if((fp3 = fopen("sysusers.txt","r")) == NULL){//'r'为只读模式，该文件必须存在   
			printf("文件打开失败！");
			exit(0); //无条件的退出程序,括号里可以是任何整型常量,作用都是一样的;  
		}
		
		while(!feof(fp3)){//feof()用于检测是否读到文件尾部 ，返回非零值代表到达文件尾部 ;
		
			//fread()从文件中读取数据，当读取的数据量正好是sizeof()个Byte时，返回值为1  
			fread(&sd,sizeof(struct sysuser),1,fp3);
			
			if(strcmp(sy.username,sd.username)==0&&strcmp(sy.password,sd.password)==0){
				count = 1;
				break;
			}
			
			j++;//做什么？？？？？？？？？？？？？？？？？？				 
		}
		
		if(fclose(fp3)){//若成功关闭，则返回0；否则返回EOF; 
			printf("can't close the file!\n");
			exit(0);
		}
		if(count == 1){
			printf("登录成功！\n"); 
			exit(0);
		}
		else
			printf("用户名不匹配！\n");
	} 
}



/*******************************************/
void star(char password[]){//密码转 *  
	for(int i=0;;i++){		
		password[i] = getch();
		
		if(password[i]=='\r'){//getch读到回车键 则退出  
			printf("\n");
			password[i] = '\0';
			break;
		}
		
		else if(password[i]==8 && i>0){//getch读到删除键，删除键的ASCII码为8  
			printf("\b \b");// \b退格，控制光标向前移动  
			i-=2;
		}
		
		else{
			printf("*");
		}
	}
}



/***********************
验证管理员的方式是检查管理员用户名后面四个字母是否为root
那这样就存在一个漏洞，如果普通用户将自己的用命名的后四位设为root怎么办？ 
************************/
int validate(){//验证是否为管理员 (root)
	int flag1 = strlen(sd.username);
	if(sd.username[flag1-4]=='r'&&sd.username[flag1-3]=='o'&&sd.username[flag1-2]=='o'&&sd.username[flag1-1]=='t')
		fog = 1;//确认管理员
	else
		fog = 0;
	return fog;
	
}



/********************注册************************/
void registe(){ 
	
	char flag2[MAX];
	struct sysuser sa;
	printf("用户名：");
	scanf("%s",sa.username);
	for(;;){
		printf("密码：");
		star(sa.password);
		printf("确认密码：");
		star(flag2);
		if(strcmp(flag2,sa.password)==0)
			break;
		else
			printf("输入不一致！");			 
	}
	
	if((fp3=fopen("sysusers.txt","a"))==NULL){//a 打开方式表示增补，如果文件不存在则创建一个 
		printf("can not open the file!\n");
		exit(0);		
	} 
	
	fwrite(&sa,sizeof(struct sysuser),1,fp3);//把 sa 结构体中的参数写进txt文件中 ；
	 
 	if(fclose(fp3)){
	 	printf("can not close the file!\n");
	 	exit(0);
	 }
	 
	system("CLS"); 
	
	printf("姓名：");
	scanf("%s",p.name);
	
	printf("性别：");
	scanf("%s",p.gender);
	
	printf("年龄：");
	scanf("%s",p.age);
	
	printf("学号：");
	scanf("%s",p.classes);
	
	printf("手机：");
	scanf("%s",p.tel);
	
	printf("QQ：");
	scanf("%s",p.QQ);
	
	if((fp=fopen("information.txt","a"))==NULL){
		printf("can not open the file!\n");
		exit(0);
	}
	
	fwrite(&p,sizeof(struct personal_message),1,fp);
	
	if(fclose(fp)){
		printf("can not close the file!\n");
		exit(0);
	}
	printf("注册成功！");
	
}


/******************找回密码*********************/
void find_password(){
	
	struct sysuser sr1,sr;//sr1存放输入的临时变量，sr为原文本  
	int b = 0;
	char new_password[MAX];//确认新密码  
	
	lp:printf("请输入用户名：");
	scanf("%s",sr1.username);
	
	if((fp3=fopen("sysuers.txt","r+"))==NULL){// r+ 打开一个文字文件读、写  
		printf("can not open the file!\n");
		exit(0);
	}
	
	while(!feof(fp3)){
		
		fwrite(&sr,sizeof(struct sysuser),1,fp3);
		if(strcmp(sr1.username,sr.username)==0)
			break;
		else 
			b++;			
	}
	
	if(feof(fp3)==-1){//feof()返回非零值表示文件结束，否则返回0，文本文件结束的标志是EOF，ASCII码为-1； 
		printf("找不到用户名！\n");
		goto lp;//继续输入  
	}
	
	else{//文件没有结束，此时找到用户名，
		for(;;){
			printf("请输入新密码：");
			star(sr1.password);
			printf("确认新密码：");
			star(new_password);
			
			if(strcmp(sr1.password,new_password)==0)
				break;
			else
				printf("输入不一致！\n");
		} 
		/*
		当文件刚开始创建的时候，文件指针指向文件的开始，随着文件的读写，指针指向文件其他位置，
		rewind()使指针从新指向文件的开始。 
		*/
		rewind(fp3);
		strcpy(sr.password,sr1.password);//后一个参数复制到前一个参数后面 
		
		/*fseek()把文件指针移动到指定位置，这里移动到离文件开头处 b*sizeof(struct sysuser) 字节处*/		 
		fseek(fp3,b*sizeof(struct sysuser),0);
	 	fwrite(&sr,sizeof(struct sysuser),1,fp3);
	}
	if(fclose(fp3)){
		printf("can not close the file!\n");
		exit(0);
	}
}



/******************修改个人信息 *********************/
void modificate_information(){
	
	struct personal_message p1;
	
	printf("姓名：");
	scanf("%s",p1.name);
	printf("年龄：");
	scanf("%s",p1.age);
	printf("性别：");
	scanf("%s",p1.gender);
	printf("学号：");
	scanf("%s",p1.classes);
	printf("QQ：");
	scanf("%s",p1.QQ);
	printf("手机：");
	scanf("%s",p1.tel);
	
	if((fp=fopen("information.txt","w"))==NULL){
		printf("can not open the file!\n");
		exit(0);
	}
	
	rewind(fp);
	/*****这里为什么乘以j呢？******/
	fseek(fp,j*sizeof(struct personal_message),0);//文件指针移动到文末在开始写入 
	fwrite(&p1,sizeof(struct personal_message),1,fp);
	
	if(fclose(fp)){
		printf("can not close the file!\n");
		exit(0);
	}
	printf("修改成功！\n");
}


/****************修改密码*************/
void modificate_password(){
	struct sysuser sy3,sy2;
	char  flag3[MAX];
	while(1){
		printf("请输入新密码：");
		star(sy3.password);
		if(strcmp(sy3.password,flag3)==0)//是否是检测输入为零  
			break; 
		
		printf("确认密码：");
		star(flag3);
		if(strcmp(sy3.password,flag3)==0)
			break;
		
	}

	if((fp3=fopen("sysusers.txt","r+"))==NULL){
		printf("can not open the file!\n");
		exit(0);
	}
	
	rewind(fp3);
	fseek(fp3,j*sizeof(struct sysuser),0);
	fread(&sy2,sizeof(struct sysuser),1,fp3);
	strcpy(sy2.password,sy3.password);
	fseek(fp3,j*sizeof(struct sysuser),0);//??*************
	fwrite(&sy2,sizeof(struct sysuser),1,fp3);//??*********
	if(fclose(fp3)==0){
		printf("can not close the file!\n");
		exit(0);
	}
	printf("修改成功！\n");
} 



/************查询书籍信息*************/
void resource_record(){
	if((fp1=fopen("resource.txt","r"))==NULL){
		printf("can not open the file!\n");
		exit(0);
	}
	
	while(!feof(fp1)){
		fread(&books1,sizeof(struct book),1,fp1);
		printf("书名：%s\n",books1.book_name);
		printf("编号：%s\n",books1.book_num);
		printf("数量：%d\n",books1.member);
		printf("借出：%d\n\n",books1.borrow);
	}
	
	if(fclose(fp1)){
		printf("can not close the file!\n");
		exit(0);
	}
}


/****************添加图书***************/
void add_book(){
	int count;
	printf("请输入需要添加书的数量：");
	scanf("%d",&count);
	while(count--){
		printf("书名：");
		scanf("%s",books1.book_name);
		printf("编号：");
		scanf("%s",books1.book_num);
		printf("数量：");
		scanf("%s",books1.member);
		if((fp1=fopen("resource.txt","a"))==NULL){
			printf("can not open the file!\n");
			exit(0);
		}
		fwrite(&books1,sizeof(struct book),1,fp1);
		
		if(fclose(fp1)){
			printf("can not close the file!\n");
			exit(0);
		}
		
		if(count!=0)
			printf("\t\t***********************\n");
	}
	
}


/****************书籍借还*********************/
void borrow_repay(){
	int slection;
	page_design4();
	scanf("%d",&slection);
	if(slection=1)
		borrow();
	else if(slection=2)
		repay();
	else
		printf("error!");
}

/*****************借书************************/
void borrow(){
	int i;
	char b[MAX];
	printf("请输入要借书的编号：");
	scanf("%s",b);
	if((fp1=fopen("resource.txt","r+"))==NULL){
		printf("can not open the file!\n");
		exit (0);
	} 
	
	while(!feof(fp1)){
		fread(&books2[i],sizeof(struct book),1,fp1);
		if(strcmp(b,books2	[i].book_num)==0){
			books2[i].member--;
			books2[i].borrow++;
			rewind(fp1);
			fseek(fp1,i*sizeof(struct book),0);
			fwrite(&books2[i],sizeof(struct book),1,fp1);
			break;
		}
		i++;
	}
	if(fclose(fp1)){
		printf("close error!\n");
		exit(0);
	}
	printf("借书成功！\n");
}


/*******************还书*********************/
void repay(){
	char repay_flag[MAX];
	int i;
	printf("请输入还书编号：\n");
	scanf("%s",repay_flag);
	
	if((fp1=fopen("resource.txt","r+"))==NULL){
		printf("can not open the file!\n");
		exit (0);
	} 
	
	while(!feof(fp1)){
		fread(&books2[i],sizeof(struct book),1,fp1);
		if(strcmp(repay_flag,books2[i].book_num)==0){
			books2[i].member++;
			books2[i].borrow--;
			rewind(fp1);
			fseek(fp1,i*sizeof(struct book),0);
			fwrite(&books2[i],sizeof(struct book),1,fp1);
			break;
		}
		i++;
	}
	if(fclose(fp1)){
		printf("close error!\n");
		exit(0);
	}
	printf("还书成功！\n");
}

/***********耗材管理**************/
void consumables_record(){
	int s;
	page_design5();
	printf("请输入你的选择：\n");
	scanf("%d",&s);
	if(s==1)
		check_consumables();
	else if(s==2)
		add_consumables();
	else
		printf("input error!\n");
}

/*************查看耗材*****************/
void check_consumables(){
	system("CLS");
	if((fp2=fopen("consumables.txt","r"))==NULL){//打开只读文件  
		printf("open error!\n");
		exit(0);
	}
	while(!feof(fp2)){
		fread(&con1,sizeof(struct consumables),1,fp2);
		printf("name :%s\n",con1.name);
		printf("member :%s\n\n",con1.member);
	}
	if(fclose(fp2)){
		printf("close error!\n");
		exit(0);
	}
}

/***************添加耗材******************/
void add_consumables(){
	system("CLS");
	printf("请输入添加耗材的名称：\n");
	scanf("%s",&con1.name);//为什么不需要取地址符  
	printf("请输入添加耗材的数量：\n");
	scanf("%d",&con1.member);
	if((fp2=fopen("consumables.txt","a"))==NULL){//a方式打开，若不存在，则建立新的文件，若存在，则写到文件尾 
		printf("open error!\n");
		exit(0);
	}
	fwrite(&con1,sizeof(struct consumables),1,fp2);
	if(fclose(fp2)){
		printf("close error!\n");
		exit(0);		
	}
	printf("添加成功！\n");
}


/******************添加管理员*********************/
void add_administrator(){
	
	struct sysuser user_flag;
	char sys_name[MAX];
	char root[5] = {"root"};
	int loop_num = 0;
	int w2;

	loop:printf("请输入添加管理员的用户名：");
	scanf("%s",&sys_name);
	if((fp3=fopen("sysusers.txt","r+"))==NULL){//文件必须存在，可读写  
		printf("open error!\n");
		exit(0);
	}
	
	fseek(fp3,0,2);
	w2 = ftell(fp3);
	fseek(fp3,0,0);
	
	while(!feof(fp3)){
		fread(&user_flag,sizeof(struct sysuser),1,fp3);//读文件 
		if(strcmp(user_flag.username,sys_name)==0){//判断用户名是否是系统内用户  
			strcat(user_flag.username,root);
			fseek(fp3,loop_num*sizeof(struct sysuser),0);
			fwrite(&user_flag,sizeof(struct sysuser),1,fp3);
			printf("添加成功!\n");
			break;
		}
		else{
			loop_num++;
			if(w2==ftell(fp3)){
				printf("找不到用户名！\n");
				goto loop;
			}		
		}		
	}
	if(fclose(fp3)){
		printf("close error!\n");
		exit(0);
	}
}


