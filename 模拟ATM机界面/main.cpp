
#include "main.h"

int main()
{
	int account_temp,password_temp,slect_temp;
	int account = 123456;//’Àªß  
	int password = 123456;//√‹¬Î  
	int balance = 1000;//”‡∂Ó  
	printf("welcome to use the ATM !\n\n");
	while(1)
	{
		printf("please input your account number :");
		scanf("%d",&account_temp);
		printf("please input your password :");
		scanf("%d",&password_temp);
		
		if (account_temp==account&&password_temp==password)
		{
			printf("your account balance is : %d\n\n",balance);
			break;
		}
		else
		{
			printf("account or password error!!\n");
			continue;
		}
	}
	
	do
	{	
		printf("**************\n");
		printf("1.check the balance.\n");
		printf("2.withdrew money.\n");
		printf("3.reset password.\n");
		printf("4.take card.\n");
		printf("5.save money.\n");
		printf("**************\n");
		printf("\n\t\t please Select the project you want to serve:\n");
		scanf("%d",&slect_temp);
		
		switch(slect_temp)
		{
			case 1:
				check_balance(balance);
				break;
			case 2:
				balance = drewmoney(balance);
				break;
			case 3:
				password = reset_password(password);
				break;
			case 4:
				take_card();
				break;
			case 5:
				balance = save_money(balance);
				break;		
		}
	}while(slect_temp!=4);
	return 0;
}



