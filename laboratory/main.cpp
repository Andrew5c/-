
#include "functions.h"

int fog;//����Ա��־ ,=1Ϊ����Ա 
int j;

 int main(){
 	
 	struct personal_message h,*pointer;//ע��ṹ��ָ���ʹ�ã� 
 	pointer = &h;
 	
 	int m,back_flag; 	
 	int login_options;
 	
 	loop1:page_design1();//��¼����  
 	scanf("%d",&login_options);
 	system("CLS");//ִ�п���̨����cls,���� 
 	
 	switch(login_options){
 		
	 	case 1:{//��¼  
	 		enter();
	 		validate();
	 		system("CLS");	 		
	 	}break;
	 	
	 	case 2:{//ע��  
	 		registe();
	 		system("CLS");
			 goto loop1;			 	
	 	}break;
	 	
	 	case 3:{//�һ�����  
	 		find_password();	 		
	 		system("CLS");
	 		goto loop1;
	 	}break;
	 		 	
	 }
 	
 	
 	loop2:if((fp=fopen("information.txt","r"))==NULL){//��ʾ������Ϣ  
	 	printf("can not open the file!\n");
	 	exit(0);	 	
	 }
	 
	 rewind(fp);
	 fseek(fp,j*sizeof(struct personal_message),0);
	 fread(&h,sizeof(struct personal_message),1,fp);//���ļ��ж�ȡָ�����ȵ����� ,��һ�� 
	 
	 printf("������%s",h.name);
	 printf("���䣺%s",h.age);
	 printf("�Ա�%s",h.gender);
	 printf("ѧ�ţ�%s",h.classes);
	 printf("QQ��%s",h.QQ);
	 printf("�ֻ���%s",h.tel);
	 
	 if(fclose(fp)){
 		printf("can not close the file!\n");
 		exit(0);
 	}
 	
 	
 	page_design2();
 	
 	if(fog==1){//����Աѡ��  
	 	page_design3();
	 }
	 printf("/------------------------------/\n");
	 printf("���������ѡ��");
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
 	
 	page_design6();//������ҳ�����˳�  
 	scanf("%d",&back_flag);
 	system("CLS");
 	if(back_flag==1)
 		goto loop2;
 		
	return 0;
 }
 


