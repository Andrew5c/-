
//����ʵ�ֲ��� 
 
#include "functions.h"

/*����ṹ�����*/
struct personal_message p;
struct sysuser sd,sy;
struct book books1,books2[50];
struct consumables con1,con2;

/*FILEΪ�������ͣ�����һ�� fp ָ�� */
FILE *fp;//ָ�� information.txt  
FILE *fp1;//ָ�� resource.txt
FILE *fp2;//ָ��consumables.txt
FILE *fp3;//ָ�� sysusers.txt  



/*****************��¼**********************/
void enter(){
	
	int count = 0;
	while(1){
		printf("�������û�����");
		scanf("%s",sy.username);
		printf("���������룺");
		star(sy.password);
		if((fp3 = fopen("sysusers.txt","r")) == NULL){//'r'Ϊֻ��ģʽ�����ļ��������   
			printf("�ļ���ʧ�ܣ�");
			exit(0); //���������˳�����,������������κ����ͳ���,���ö���һ����;  
		}
		
		while(!feof(fp3)){//feof()���ڼ���Ƿ�����ļ�β�� �����ط���ֵ�������ļ�β�� ;
		
			//fread()���ļ��ж�ȡ���ݣ�����ȡ��������������sizeof()��Byteʱ������ֵΪ1  
			fread(&sd,sizeof(struct sysuser),1,fp3);
			
			if(strcmp(sy.username,sd.username)==0&&strcmp(sy.password,sd.password)==0){
				count = 1;
				break;
			}
			
			j++;//��ʲô������������������������������������				 
		}
		
		if(fclose(fp3)){//���ɹ��رգ��򷵻�0�����򷵻�EOF; 
			printf("can't close the file!\n");
			exit(0);
		}
		if(count == 1){
			printf("��¼�ɹ���\n"); 
			exit(0);
		}
		else
			printf("�û�����ƥ�䣡\n");
	} 
}



/*******************************************/
void star(char password[]){//����ת *  
	for(int i=0;;i++){		
		password[i] = getch();
		
		if(password[i]=='\r'){//getch�����س��� ���˳�  
			printf("\n");
			password[i] = '\0';
			break;
		}
		
		else if(password[i]==8 && i>0){//getch����ɾ������ɾ������ASCII��Ϊ8  
			printf("\b \b");// \b�˸񣬿��ƹ����ǰ�ƶ�  
			i-=2;
		}
		
		else{
			printf("*");
		}
	}
}



/***********************
��֤����Ա�ķ�ʽ�Ǽ�����Ա�û��������ĸ���ĸ�Ƿ�Ϊroot
�������ʹ���һ��©���������ͨ�û����Լ����������ĺ���λ��Ϊroot��ô�죿 
************************/
int validate(){//��֤�Ƿ�Ϊ����Ա (root)
	int flag1 = strlen(sd.username);
	if(sd.username[flag1-4]=='r'&&sd.username[flag1-3]=='o'&&sd.username[flag1-2]=='o'&&sd.username[flag1-1]=='t')
		fog = 1;//ȷ�Ϲ���Ա
	else
		fog = 0;
	return fog;
	
}



/********************ע��************************/
void registe(){ 
	
	char flag2[MAX];
	struct sysuser sa;
	printf("�û�����");
	scanf("%s",sa.username);
	for(;;){
		printf("���룺");
		star(sa.password);
		printf("ȷ�����룺");
		star(flag2);
		if(strcmp(flag2,sa.password)==0)
			break;
		else
			printf("���벻һ�£�");			 
	}
	
	if((fp3=fopen("sysusers.txt","a"))==NULL){//a �򿪷�ʽ��ʾ����������ļ��������򴴽�һ�� 
		printf("can not open the file!\n");
		exit(0);		
	} 
	
	fwrite(&sa,sizeof(struct sysuser),1,fp3);//�� sa �ṹ���еĲ���д��txt�ļ��� ��
	 
 	if(fclose(fp3)){
	 	printf("can not close the file!\n");
	 	exit(0);
	 }
	 
	system("CLS"); 
	
	printf("������");
	scanf("%s",p.name);
	
	printf("�Ա�");
	scanf("%s",p.gender);
	
	printf("���䣺");
	scanf("%s",p.age);
	
	printf("ѧ�ţ�");
	scanf("%s",p.classes);
	
	printf("�ֻ���");
	scanf("%s",p.tel);
	
	printf("QQ��");
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
	printf("ע��ɹ���");
	
}


/******************�һ�����*********************/
void find_password(){
	
	struct sysuser sr1,sr;//sr1����������ʱ������srΪԭ�ı�  
	int b = 0;
	char new_password[MAX];//ȷ��������  
	
	lp:printf("�������û�����");
	scanf("%s",sr1.username);
	
	if((fp3=fopen("sysuers.txt","r+"))==NULL){// r+ ��һ�������ļ�����д  
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
	
	if(feof(fp3)==-1){//feof()���ط���ֵ��ʾ�ļ����������򷵻�0���ı��ļ������ı�־��EOF��ASCII��Ϊ-1�� 
		printf("�Ҳ����û�����\n");
		goto lp;//��������  
	}
	
	else{//�ļ�û�н�������ʱ�ҵ��û�����
		for(;;){
			printf("�����������룺");
			star(sr1.password);
			printf("ȷ�������룺");
			star(new_password);
			
			if(strcmp(sr1.password,new_password)==0)
				break;
			else
				printf("���벻һ�£�\n");
		} 
		/*
		���ļ��տ�ʼ������ʱ���ļ�ָ��ָ���ļ��Ŀ�ʼ�������ļ��Ķ�д��ָ��ָ���ļ�����λ�ã�
		rewind()ʹָ�����ָ���ļ��Ŀ�ʼ�� 
		*/
		rewind(fp3);
		strcpy(sr.password,sr1.password);//��һ���������Ƶ�ǰһ���������� 
		
		/*fseek()���ļ�ָ���ƶ���ָ��λ�ã������ƶ������ļ���ͷ�� b*sizeof(struct sysuser) �ֽڴ�*/		 
		fseek(fp3,b*sizeof(struct sysuser),0);
	 	fwrite(&sr,sizeof(struct sysuser),1,fp3);
	}
	if(fclose(fp3)){
		printf("can not close the file!\n");
		exit(0);
	}
}



/******************�޸ĸ�����Ϣ *********************/
void modificate_information(){
	
	struct personal_message p1;
	
	printf("������");
	scanf("%s",p1.name);
	printf("���䣺");
	scanf("%s",p1.age);
	printf("�Ա�");
	scanf("%s",p1.gender);
	printf("ѧ�ţ�");
	scanf("%s",p1.classes);
	printf("QQ��");
	scanf("%s",p1.QQ);
	printf("�ֻ���");
	scanf("%s",p1.tel);
	
	if((fp=fopen("information.txt","w"))==NULL){
		printf("can not open the file!\n");
		exit(0);
	}
	
	rewind(fp);
	/*****����Ϊʲô����j�أ�******/
	fseek(fp,j*sizeof(struct personal_message),0);//�ļ�ָ���ƶ�����ĩ�ڿ�ʼд�� 
	fwrite(&p1,sizeof(struct personal_message),1,fp);
	
	if(fclose(fp)){
		printf("can not close the file!\n");
		exit(0);
	}
	printf("�޸ĳɹ���\n");
}


/****************�޸�����*************/
void modificate_password(){
	struct sysuser sy3,sy2;
	char  flag3[MAX];
	while(1){
		printf("�����������룺");
		star(sy3.password);
		if(strcmp(sy3.password,flag3)==0)//�Ƿ��Ǽ������Ϊ��  
			break; 
		
		printf("ȷ�����룺");
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
	printf("�޸ĳɹ���\n");
} 



/************��ѯ�鼮��Ϣ*************/
void resource_record(){
	if((fp1=fopen("resource.txt","r"))==NULL){
		printf("can not open the file!\n");
		exit(0);
	}
	
	while(!feof(fp1)){
		fread(&books1,sizeof(struct book),1,fp1);
		printf("������%s\n",books1.book_name);
		printf("��ţ�%s\n",books1.book_num);
		printf("������%d\n",books1.member);
		printf("�����%d\n\n",books1.borrow);
	}
	
	if(fclose(fp1)){
		printf("can not close the file!\n");
		exit(0);
	}
}


/****************���ͼ��***************/
void add_book(){
	int count;
	printf("��������Ҫ������������");
	scanf("%d",&count);
	while(count--){
		printf("������");
		scanf("%s",books1.book_name);
		printf("��ţ�");
		scanf("%s",books1.book_num);
		printf("������");
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


/****************�鼮�軹*********************/
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

/*****************����************************/
void borrow(){
	int i;
	char b[MAX];
	printf("������Ҫ����ı�ţ�");
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
	printf("����ɹ���\n");
}


/*******************����*********************/
void repay(){
	char repay_flag[MAX];
	int i;
	printf("�����뻹���ţ�\n");
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
	printf("����ɹ���\n");
}

/***********�ĲĹ���**************/
void consumables_record(){
	int s;
	page_design5();
	printf("���������ѡ��\n");
	scanf("%d",&s);
	if(s==1)
		check_consumables();
	else if(s==2)
		add_consumables();
	else
		printf("input error!\n");
}

/*************�鿴�Ĳ�*****************/
void check_consumables(){
	system("CLS");
	if((fp2=fopen("consumables.txt","r"))==NULL){//��ֻ���ļ�  
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

/***************��ӺĲ�******************/
void add_consumables(){
	system("CLS");
	printf("��������ӺĲĵ����ƣ�\n");
	scanf("%s",&con1.name);//Ϊʲô����Ҫȡ��ַ��  
	printf("��������ӺĲĵ�������\n");
	scanf("%d",&con1.member);
	if((fp2=fopen("consumables.txt","a"))==NULL){//a��ʽ�򿪣��������ڣ������µ��ļ��������ڣ���д���ļ�β 
		printf("open error!\n");
		exit(0);
	}
	fwrite(&con1,sizeof(struct consumables),1,fp2);
	if(fclose(fp2)){
		printf("close error!\n");
		exit(0);		
	}
	printf("��ӳɹ���\n");
}


/******************��ӹ���Ա*********************/
void add_administrator(){
	
	struct sysuser user_flag;
	char sys_name[MAX];
	char root[5] = {"root"};
	int loop_num = 0;
	int w2;

	loop:printf("��������ӹ���Ա���û�����");
	scanf("%s",&sys_name);
	if((fp3=fopen("sysusers.txt","r+"))==NULL){//�ļ�������ڣ��ɶ�д  
		printf("open error!\n");
		exit(0);
	}
	
	fseek(fp3,0,2);
	w2 = ftell(fp3);
	fseek(fp3,0,0);
	
	while(!feof(fp3)){
		fread(&user_flag,sizeof(struct sysuser),1,fp3);//���ļ� 
		if(strcmp(user_flag.username,sys_name)==0){//�ж��û����Ƿ���ϵͳ���û�  
			strcat(user_flag.username,root);
			fseek(fp3,loop_num*sizeof(struct sysuser),0);
			fwrite(&user_flag,sizeof(struct sysuser),1,fp3);
			printf("��ӳɹ�!\n");
			break;
		}
		else{
			loop_num++;
			if(w2==ftell(fp3)){
				printf("�Ҳ����û�����\n");
				goto loop;
			}		
		}		
	}
	if(fclose(fp3)){
		printf("close error!\n");
		exit(0);
	}
}


