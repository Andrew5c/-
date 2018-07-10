



#include <stdio.h>
#include <math.h>
#include <string.h>
//#include "least_square.h" 

#define MAX_NUM		100

//原始数据 
float x_value[MAX_NUM];
float y_value[MAX_NUM];

//原始数据个数
unsigned char num_count = 0;


/*
** 说明：最小二乘法，线性拟合。 
** 原理：根据输入的坐标点的信息，拟合出一条直线，使所有点与该直线的差的平方和最小。 
** 缺点：对噪声容忍度很低。可以采用加权最小二乘法。 
** 返回值：拟合直线的斜率K 
** 时间：2018.7.7 
*/
float Least_Square(void)
{
	int i;
	float a0,a1,a2,temp,temp0,temp1,temp2;
	float sy=0,sx=0,sxx=0,syy=0,sxy=0,sxxy=0,sxxx=0,sxxxx=0;//定义相关变量
	
	for(i=0; i<num_count; i++)
	{
		sx+=x_value[i];//计算xi的和 
		sy+=y_value[i];//计算yi的和 
		sxx+=x_value[i]*x_value[i];//计算xi的平方的和 
		sxxx+=pow(x_value[i],3);//计算xi的立方的和 
		sxxxx+=pow(x_value[i],4);//计算xi的4次方的和 
		sxy+=x_value[i]*y_value[i];//计算xi乘yi的的和 
		sxxy+=x_value[i]*x_value[i]*y_value[i];//计算xi平方乘yi的和 
	}
	
	temp=num_count*sxx-sx*sx;//方程的系数行列式
	temp0=sy*sxx-sx*sxy;
	temp1=num_count*sxy-sy*sx;
	
	a0=temp0/temp;	//截距 
	a1=temp1/temp;	//斜率 
	
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

