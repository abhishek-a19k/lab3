/* 
 * Program: To evaluate infix to postfix
 * Author : Abhishek Kadariya [0501]
 * BATCH OF 2019 DWIT
 * 
 * Ref    : Data structures using C and C++, Chap 2
*/


#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 50
#define loop for(i=0;i<=strlen(exp);i++)
typedef struct{
	int top;
	char items[max];
}stack;
void push(stack*s,char x);
int pop(stack*s);
int num(char);
int main()
{
	char d,a[max];
	int i,b=0,c;
	stack s;
	s.top=-1;
	char exp[max];
	printf("Enter a expression!:\n");
	scanf("%s",&exp);
	loop //for(i=0;i<=strlen(exp);i++)
	{
		if((exp[i]>='0' && exp[i]<='9') || (exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z'))
		{
			a[b++]=exp[i];
		}
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='$'||exp[i]=='/')
		{
			if(s.top==-1)
			{
				push(&s,exp[i]);
			}
			else if (!(s.top==-1))
			{
				d=pop(&s);
				push(&s,d);
				if (num(d)>=num(exp[i]))
				{
					a[b++]=pop(&s);
					push(&s,exp[i]);
				}
				else
				{
					push(&s,exp[i]);
				}
			}
	}
}
	while(!(s.top==-1))
	{
	a[b++]=pop(&s);
	}
	printf("The postfix expression is %s",a);	

}

//push function
void push(stack*s,char x)
{
		s->items[++(s->top)]=x;
}
int pop(stack*s)
{
	return (s->items[(s->top)--]);
}



int num(char c)
{
if(c=='+'||c=='-')
{
	return (1);
}
else if(c=='*'||c=='/')
{
	return (2);
}
else
{
	return (3);
}

	
}
