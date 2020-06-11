#include<stdio.h>
#include <string.h>
#include<stdlib.h>
struct Node
{
	char data;
	struct Node *next;
};
struct Node * top;
struct Node * temp;

void push(char x)
{
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = top;
	top = temp;
}

char pop(int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		temp = top;
		top = temp->next;
		temp->next = NULL;
		return temp->data;	
	}		
}

char pop()
{
		temp = top;
		top = temp->next;
		temp->next = NULL;
		return temp->data;
}

void display(int n)
{
	int i;
	temp = top;
	for(i = 0 ; i < n ; i++)
	{
		printf("%c ",temp->data);
		temp = temp->next;	
	}	
}

void display()
{
	temp = top;
	while(temp != NULL)
	{
		printf("%c ",temp->data);
		temp = temp->next;
	}
}

int isOperand(char x)
{
	if(x == '+' || x == '-' || x == '*' || x == '/')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int isExists(char x)
{	

		if(x == '+' || x == '-')
		{
			return 1;
		}
		else
		{
			return 2;
		}

}

int onTop()
{
	if(top == NULL)
	{
		return 0;
	}
	else
	{
	if(top->data == '*' || top->data == '/')
	{
		return 2;
	}
	else
	{
		return 1;
	}
	}
}


void displayPostfix(char z[] , int j)
{
	int i;
	printf("Infix to Postfix Conversion :- \t");
	for(i = 0 ; z[i] != '\0' ; i++)
	{
		printf("%c",z[i]);
	}
	printf("\n");	
}

void displayPrefix(char z[] , int j)
{
	int i;
	printf("Infix to Prefix Conversion :- \t");
	for(i = 0 ; i < j ; i++)
	{
		printf("%c",z[i]);
	}
}

int evalisOperand(char x)
{
	if(x == '+' || x == '-' || x == '*' || x == '/')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	int n,i=0,j=0;
	char y[50];
	char postfix[50];
	char prefix[50];
	char x;
	printf("Enter a Infix expression : - \t");
	scanf("%s" , y);
	while(y[i] != '\0')
	{
		if(isOperand(y[i]))
		{
			postfix[j] = y[i];
			i++;
			j++;
		}
		else
		{
		if(isExists(y[i]) > onTop())
		{
			push(y[i]);	
			i++;
		}
		else
		{
			x = pop(1);
			postfix[j] = x;
			free(temp);
			j++;
		}
		}
		//scanf("%c",&y);
		//push(y[i]);
 }
 
 if(y[i] == '\0')
 {
 	while(top != NULL)
 	{
 		x = pop();
		postfix[j] = x;
		free(temp);
		j++;
	 }
	 postfix[j] = '\0';
 }
 
 	displayPostfix(postfix , j);
 	
 	int s = i-1;
 	int t = s;
 	while(s != -1)
 	{
 		if(isOperand(y[s]))
 		{
 			prefix[t] = y[s];
			 s--;
			 t--;	
		}
		else
		{
		if(isExists(y[s]) > onTop())
		{
			push(y[s]);
			s--;
		}
		else
		{
		if(isExists(y[s]) == onTop())
		{
			push(y[s]);
			s--;	
		}
		else
		{
			x = pop(1);
			prefix[t] = x;
			free(temp);
			t--;
		}
		}
		}
	}
if(s == -1)
{
	while(top != NULL)
	{
	   x = pop();
	   prefix[t] = x;
	   t--;
	}
}

displayPrefix(prefix , i);

i = 0;
char x2;
char x1;
char x3;
while(postfix[i] != '\0')
{
if(evalisOperand(postfix[i]))
{
	push(postfix[i] - '0');
	i++;
}
else
{
	x2 = pop();
	x1 = pop();
	if(postfix[i] == '*')
	{
	x3 = x1 * x2;
	push(x3);
	i++;
	}
	else if(postfix[i] == '+')
	{
	x3 = x1 + x2;
	push(x3);
	i++;
	}
 	else if(postfix[i] == '-')
	{
	x3 = x1 - x2;
	push(x3);
	i++;
	}
	else if(postfix[i] == '/')
	{
	x3 = x1/x2;
	push(x3);
	i++;
	}
}
}
printf("\n");
printf("The Postfix Evaluation to this equation is :- \t %d",x3);
}
