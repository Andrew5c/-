#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX 50

//����ջ�ṹ�� 
struct stack
{
	int arr[MAX];  //ջ�ܳ���  
	int top;		//ջ��ָ��  
};

//��ʼ��ջ����top = 0 
void init_stack(struct stack *st)
{
	st = (struct stack *)malloc(sizeof(struct stack));
	st->top = 0;
	free(st);
	
//	memset(&st,0,sizeof(struct stack));
} 

//����Ԫ����ջ 
void push(struct stack *st,int val)
{
	st = (struct stack *)malloc(sizeof(struct stack));
	if(st->top < MAX)
		st->arr[st->top++] = val;
	else
		printf("stack is full\n");
	free(st);
} 

//��ջ  
int pop(struct stack *st)
{
	st = (struct stack *)malloc(sizeof(struct stack));
	int val = 0;
	
	if(st->top > 0)
	{
		st->top--;
		val = st->arr[st->top];
		return val;
	}
	else
	{
		printf("stack is empty\n");
		return -1;
	}
	
	free(st);
}

//��ʾջ������Ԫ��  
void display_stack(struct stack *st)
{
	st = (struct stack *)malloc(sizeof(struct stack));
	int i = 0;
	
	printf("all the stack elements:\n");
	for(i=0;i<st->top;i++)
		printf("%d\t",st->arr[i]);
}


int main(void)
{
	int choice = 0,val = 0;
	struct stack *st;
//	struct stack sta;
	
	st = (struct stack *)malloc(sizeof(struct stack));
	init_stack(st);  //���е�����ͷ�������  
	
	while(choice != 4)
	{
		printf("stack operations:\n");
		printf("----------------\n");
		printf("1:PUSH elements\n");
		printf("2:POP elements\n");
		printf("3:display all elements\n");
		printf("4:EXIT\n");
		printf("\n your choice: \n");
		
		scanf("%d",&choice);	
		
		switch(choice)
		{
			case 1:
				printf("enter element: ");
				scanf("%d",&val);
				push(st,val);
				break;
			case 2:
				val = pop(st);
				if(val != -1)
					printf("\n popped element :%d",val);
				else
					printf("\n stack is empty!\n");
				break;
			case 3:
				display_stack(st);
				break;
			case 4:
				break;
			default:
				printf("input error!");
				break;
		}
		free(st);
	}
}


