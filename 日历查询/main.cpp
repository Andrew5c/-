
#include "main.h"

int main()
{
	int year,month,days,weekday;
	int i,d;
	while(1)
	{
		printf("please input the year:\n");
		scanf("%d",&year);
		days = year-1+(year-1)/400+(year-1)/4-(year-1)/100;//����ĳ���һ�������ڼ� 
		
		for(month=1;month<=12;month++)
		{
			printf("\t\t****%d��--%d��****\n",year,month);
			printf("sun\tmon\ttues\twed\tthur\tfir\tsat\t\n");//��ͷ
			i = 1;	d = 1;
			weekday = (days + 1)%7;  //�����ڼ� 
			while(i<=weekday)   //���ǰ��Ŀո� 
			{
				printf("\t");
				i++;
			} 
			
			while(d<=monthday(month,year))     //������� 
			{
				weekday = (days + 1)%7;
				if(weekday==6)   //���һ���������������֮��Ҫ���� 
					printf("%d\n",d);
				else             //����������������󲻻��� 
			 		printf("%d\t",d);
	 			if(d==monthday(month,year))
	 				printf("\n");
 				d++;
 				days++;
			}
		}
	}
	
}

