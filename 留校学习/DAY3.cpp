

#include <stdio.h>
#include <string.h>
/*
int main(int argc,char **argv)   //������Ĳ�������ͨ������̨����  
{
	int i = 0;
	
	for(i = 0;i < argc;i++)
	{
		printf("the argv[%d] is %s\n",i,argv[i]);
	}
	
	//��һ�ַ�ʽʵ��  
	while(argv[i] != NULL)
	{
		printf("the argv[%d] is %s\n",i,argv[i]);
		i++;
	}
} 
*/


//�ַ����ĳ�ʼ������  
//����ֻ�ܶ��ַ�������һ�γ�ʼ�������Ǳ༭���������ǵķ��㣬������������㻹���������ĵڶ��θı�Ļ�����û��
//��ô���ˣ���ס����ʲô���ĸ�ֵ������ռ�ֻ����һ��ֵ����������ĸ�ֵ�������Ƕ���һ��ֵ���еķ�װ���ѡ���
//ʵ�ʶ����ڶԿռ������һ��ֵ��
//˼���Ͽ���ʹ�� strcpy()�������ж��θ�ֵ�����ǹ���������������Բ���ʹ�ã������������ֻ��������0ʱ�Ž�����ֵ 
//�����������ڴ�й¶���⣬һ��Ҳ��ʹ��strncpy()������ʹ��memcpy()������ 

unsigned char out_side = 0;

int main()
{
	
	unsigned char in_side = 0;//���Բ�ͬλ�õı�����ֵַ�� 
	
	unsigned char buf1[10] = {"1234"};//������ֻ�ǿ�����һ�������Ĵ洢���򣬺������Ǿ仰һ���� 
	
	char buf2[10] = "abcde";//��仰 ִ����֮����ʵ���ڴ��п������������򣬳���abc�����������buf2 
	//Ȼ��ѳ�������abc��һ����������ռ���ȥ�������ܲ��������ռ䣬���ǲ��ܲ��������ռ�  
	
	char *buf3 = "abc";//��仰��ʵֻ�ǿ�����һ�����������abc��Ȼ������һ��ָ��buf3ָ����鳣�� 
	
	unsigned char buf4[100] = {20,30,40,50,60};
	
	int buf5[3][4] = {0};//��ά���鰴��������ȡ�� 
	
	unsigned char *p1 = buf1;//����ָ��ָ������ռ�
	 
	int (*p2)[4] = buf5;//����һ��ָ��p2����4��int���͵����ݿ��ȡ��ָ���ά���飬���϶�ά����ı�����ʽ�� 
	
	buf1[2] = 'e';
	
	buf2[2] = 'e';//ʵ���������������buf2����������������ݣ���û�ж���������abc����������ǶԵġ� 
	
//	buf3[2] = 'e';//��Ϊbuf3ָ����ǳ�������������������Ǵ���ġ� 
	
	printf("the first word is %s\n",buf1);
	printf("the second word is %s\n",buf2);
	printf("the third word is %s\n",buf3);
	
//	strcpy(buf2,"hello world!");
	
	memcpy(buf1,buf4,4*sizeof(unsigned char));//�ڴ�ռ䵽�ڴ�ռ�Ŀ���  
	
	printf("after copy buf1[0] is \"%d\" \n\n",buf1[0]);//ʹ��\" ת���ַ���������printf������˫�����д�ӡ˫����  
	printf("after copy buf1[1] is \"%d\" \n\n",buf1[1]);
	printf("after copy buf1[2] is \"%d\" \n\n",buf1[2]);
	printf("after copy buf1[3] is \"%d\" \n\n",buf1[3]);
	printf("-----------------------------------------\n\n"); 
	printf("the addr of main is %p\n",main);           //����%p������������ĵ�ֵַ��main��ǩҲ�Ƕε�ֵַ�� 
	printf("the addr of outside is %p\n",&out_side);   //�ⲿ�����ʹ�������ıȽϽ��� 
	printf("the addr of inside is %p\n",&in_side);     //�ֲ���������ʱ�ģ�һ����ڽϸߵ�ַ�Ķ����ϡ� 
	
} 



