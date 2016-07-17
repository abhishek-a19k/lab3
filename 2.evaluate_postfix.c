/* 
 * Program: To evaluate a postfix expression
 * Author : Abhishek Kadariya [0501]
 * BATCH OF 2019 DWIT
 * 
 * Ref    : Data structures using C and C++, Chap 2, Page 100
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define MAX 50
#define loop for(i=0;i<strlen(exp);i++)

typedef struct
{
	int top;
	int items[MAX];
}stack;



void push (stack*,int);
int pop (stack*);
float operation(int,float,float);

int main()
{
	int i;
	float opnd1,opnd2,value,data;
	char exp[100];
	stack s;
	s.top=-1;
	printf("Enter the Expression to evaluate its value\n");	
	gets(exp);
	
	loop{
		data=exp[i];
		if (data >= '0' && data <= '9')
		{
			push(&s,(float)(data - '0'));
			
		}else
		{
			opnd2=pop(&s);
			opnd1=pop(&s);
			value=operation(data,opnd1,opnd2);
			push(&s,value);
		}
	}
	printf("\n%d",pop(&s));
	return 0;
}
//function for push operation
void push (stack *s,int x)
{
	if (s->top==(MAX-1))
	{	
		printf("Stack Overflow\n");
		
	}else{
		++(s->top);
		s->items[s->top]=x;	
	}
}


//function for pop operation
int pop (stack *s)
{
	if (s->top==-1)
	{
		printf("Stack Underflow");
		exit(0);
	}else
	{
		return s->items[s->top--];
	}
}

//function for the operation of the given expression

float operation(int data,float x,float y)
{
	switch (data)
	{
		case '+' :
			return (x+y);
			
		case '-' :
			return (x-y);
			
		case '*' :
			return (x*y);
			
		case '/' :
			return (x/y);
			
		case '$' :
			return (pow(x,y));		
			
		default :
			printf("\nError");
			exit(9);			
	}
}
