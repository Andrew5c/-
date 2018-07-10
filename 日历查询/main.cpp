
#include "main.h"

int main()
{
	int year,month,days,weekday;
	int i,d;
	while(1)
	{
		printf("please input the year:\n");
		scanf("%d",&year);
		days = year-1+(year-1)/400+(year-1)/4-(year-1)/100;//计算某年第一天是星期几 
		
		for(month=1;month<=12;month++)
		{
			printf("\t\t****%d年--%d月****\n",year,month);
			printf("sun\tmon\ttues\twed\tthur\tfir\tsat\t\n");//表头
			i = 1;	d = 1;
			weekday = (days + 1)%7;  //求星期几 
			while(i<=weekday)   //输出前面的空格 
			{
				printf("\t");
				i++;
			} 
			
			while(d<=monthday(month,year))     //输出日期 
			{
				weekday = (days + 1)%7;
				if(weekday==6)   //最后一个是星期六，输出之后要换行 
					printf("%d\n",d);
				else             //不是星期六的输出后不换行 
			 		printf("%d\t",d);
	 			if(d==monthday(month,year))
	 				printf("\n");
 				d++;
 				days++;
			}
		}
	}
	
}

