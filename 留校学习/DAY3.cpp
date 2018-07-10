

#include <stdio.h>
#include <string.h>
/*
int main(int argc,char **argv)   //这里面的参数可以通过控制台给出  
{
	int i = 0;
	
	for(i = 0;i < argc;i++)
	{
		printf("the argv[%d] is %s\n",i,argv[i]);
	}
	
	//另一种方式实现  
	while(argv[i] != NULL)
	{
		printf("the argv[%d] is %s\n",i,argv[i]);
		i++;
	}
} 
*/


//字符串的初始化测试  
//这样只能对字符串进行一次初始化，这是编辑器带给我们的方便，但是如果后面你还想进行数组的第二次改变的话，就没有
//那么简单了，记住无论什么样的赋值，数组空间只能逐一赋值，其他方便的赋值方法都是对逐一赋值进行的封装而已。其
//实质都是在对空间进行逐一赋值。
//思想上可以使用 strcpy()函数进行二次赋值，但是工程中这个函数绝对不能使用，由于这个函数只有在遇到0时才结束赋值 
//所以他存在内存泄露问题，一般也不使用strncpy()，可以使用memcpy()函数。 

unsigned char out_side = 0;

int main()
{
	
	unsigned char in_side = 0;//测试不同位置的变量地址值。 
	
	unsigned char buf1[10] = {"1234"};//大括号只是开辟了一块连续的存储区域，和下面那句话一样。 
	
	char buf2[10] = "abcde";//这句话 执行完之后，其实在内存中开辟了两个区域，常亮abc，和数组变量buf2 
	//然后把常量区的abc逐一拷贝到数组空间中去，我们能操作变量空间，但是不能操作常量空间  
	
	char *buf3 = "abc";//这句话其实只是开辟了一个常量区存放abc，然后定义了一个指针buf3指向这块常量 
	
	unsigned char buf4[100] = {20,30,40,50,60};
	
	int buf5[3][4] = {0};//二维数组按照行来读取。 
	
	unsigned char *p1 = buf1;//利用指针指向数组空间
	 
	int (*p2)[4] = buf5;//定义一个指针p2按照4个int类型的数据块读取，指向二维数组，符合二维数组的遍历方式。 
	
	buf1[2] = 'e';
	
	buf2[2] = 'e';//实际上这个操作的是buf2的数组变量区的内容，并没有动常量区的abc，所以这个是对的。 
	
//	buf3[2] = 'e';//因为buf3指向的是常量区，所以这个操作是错误的。 
	
	printf("the first word is %s\n",buf1);
	printf("the second word is %s\n",buf2);
	printf("the third word is %s\n",buf3);
	
//	strcpy(buf2,"hello world!");
	
	memcpy(buf1,buf4,4*sizeof(unsigned char));//内存空间到内存空间的拷贝  
	
	printf("after copy buf1[0] is \"%d\" \n\n",buf1[0]);//使用\" 转意字符，可以在printf函数的双引号中打印双引号  
	printf("after copy buf1[1] is \"%d\" \n\n",buf1[1]);
	printf("after copy buf1[2] is \"%d\" \n\n",buf1[2]);
	printf("after copy buf1[3] is \"%d\" \n\n",buf1[3]);
	printf("-----------------------------------------\n\n"); 
	printf("the addr of main is %p\n",main);           //利用%p可以输出完整的地址值。main标签也是段地址值。 
	printf("the addr of outside is %p\n",&out_side);   //外部变量和代码区离的比较近。 
	printf("the addr of inside is %p\n",&in_side);     //局部变量是临时的，一般放在较高地址的堆区上。 
	
} 



