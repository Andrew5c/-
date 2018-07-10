



#include <stdio.h>
#include <math.h>
#include <string.h>
//#include "least_square.h" 

#define MAX_NUM		100

//ԭʼ���� 
float x_value[MAX_NUM];
float y_value[MAX_NUM];

//ԭʼ���ݸ���
unsigned char num_count = 0;


/*
** ˵������С���˷���������ϡ� 
** ԭ�������������������Ϣ����ϳ�һ��ֱ�ߣ�ʹ���е����ֱ�ߵĲ��ƽ������С�� 
** ȱ�㣺���������̶Ⱥܵ͡����Բ��ü�Ȩ��С���˷��� 
** ����ֵ�����ֱ�ߵ�б��K 
** ʱ�䣺2018.7.7 
*/
float Least_Square(void)
{
	int i;
	float a0,a1,a2,temp,temp0,temp1,temp2;
	float sy=0,sx=0,sxx=0,syy=0,sxy=0,sxxy=0,sxxx=0,sxxxx=0;//������ر���
	
	for(i=0; i<num_count; i++)
	{
		sx+=x_value[i];//����xi�ĺ� 
		sy+=y_value[i];//����yi�ĺ� 
		sxx+=x_value[i]*x_value[i];//����xi��ƽ���ĺ� 
		sxxx+=pow(x_value[i],3);//����xi�������ĺ� 
		sxxxx+=pow(x_value[i],4);//����xi��4�η��ĺ� 
		sxy+=x_value[i]*y_value[i];//����xi��yi�ĵĺ� 
		sxxy+=x_value[i]*x_value[i]*y_value[i];//����xiƽ����yi�ĺ� 
	}
	
	temp=num_count*sxx-sx*sx;//���̵�ϵ������ʽ
	temp0=sy*sxx-sx*sxy;
	temp1=num_count*sxy-sy*sx;
	
	a0=temp0/temp;	//�ؾ� 
	a1=temp1/temp;	//б�� 
	
	return a1;
}


int main(void)
{
	float temp = 0;
	num_count = 6;
	long int adc = 1023575;

	x_value[0] = (float)adc;
	x_value[1] = 1024820;
	x_value[2] = 1031703;
	x_value[3] = 1032475;
	x_value[4] = 1040612;
	x_value[5] = 1042307;
	
	y_value[0] = 0;
	y_value[1] = 27.1;
	y_value[2] = 177.1;
	y_value[3] = 195.0;
	y_value[4] = 372.2;
	y_value[5] = 410;
	
//this is the edit by VIM.
//and i am feel good....	
	
	temp = Least_Square();
	printf("the K is %.5f\n\n",temp);
	
}

