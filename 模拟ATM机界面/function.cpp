
#include"main.h"

//��ѯ�˻����  
int  check_balance(int balance)
{
	int b;
	b = balance;
	printf("your account balance is :%d $\n\n",b);
}


//ȡǮ������Ҫȡ�����㣬������ 
int drewmoney(int balance)
{
	int drew_account,deviation;
	printf("please input the account you want to  drew :");
	scanf("%d",&drew_account);
	deviation = balance - drew_account;
	if(deviation < 0)
		printf("your account balance is not enough!\n");
	else printf("please keep your cash: %d $\n",drew_account);
	
	return deviation;	//�������	
}

//�������룬���������� 
int reset_password(int password)
{
	int original,new_pass;
	while(1)
	{
		printf("please input the original password:\n");
		scanf("%d",&original);
		if(original==password)
			break;
		else 
		{
			printf("input error!!\n");
			continue;
		}
	}
	
	while(1)
	{
		printf("please input your new password with Six digit number:\n");
		scanf("%d",&password);
		printf("please input again:\n");
		scanf("%d",&new_pass);
		if(password == new_pass)
		{
			if(new_pass>100000&&new_pass<999999)
			{
				printf("reset success!!\n\n");
				break;
			}
			else
			{
				printf("input error!!\n");
				continue;
			}
			
		}
		else
		{
			printf("input error --> not same!!\n");
			continue;
		}
		
	}
	return password;
}


void take_card()
{
	printf("please take your card!!\n\n");
} 

//��Ǯ�������µ���� 
int save_money(int balance)
{
	int save_account;
	printf("please input the save account:\n");
	scanf("%d",&save_account);
	if(save_account<0)
		printf("sorry,no negative account!!\n");
	else 
		printf("you have saved money %d $\n",save_account);
	return balance+save_account;
}


