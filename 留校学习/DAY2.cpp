

#include "stdio.h"


int main()
{
	const char *p = "hello world!";
	
	char buf[] = {
		"hello world!"
	};
	
	char *p2 = buf;
	printf("the first word is %x\n",*p);
		
	*p2 = 'w';  //���е����﷢������  
		
	printf("the back is %s\n",buf);
}

