#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void push(int a[],int *top,int i);
void pop(int a[],int *top);
void display(int a[],int *top);
void main()
{
	int arr[MAX];
	int top=-1,item;
	while(1)
	{
		printf("Menu:\n");
		printf("Enter 1 to insert element\n");
		printf("Enter 2 to delete element\n");
		printf("Enter 3 to display stack elements\n");
		printf("Enter 4 to exit\n");
		int ch;
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter value to be inserted : ");
				scanf("%d",&item);
				push(arr,&top,item);
				break;
			case 2:pop(arr,&top);
				break;
			case 3:display(arr,&top);
				break;
			case 4:printf("Exit");
				exit(0);
				break;
			default:printf("Invalid choice");
				break;
		}
	}
}
void push(int a[],int *top,int i)
{
	if(*top==MAX-1)
		printf("Stack overflow");
	else
	{
		*top=*top+1;
		a[*top]=i;
		printf("%d inserted at index %d\n",i,*top);
	}	
}
void pop(int a[],int *top)
{
	if(*top==-1)
		printf("Stack underflow\n");
	else
	{
		int p=a[*top];
		*top=*top-1;
		printf("Popped element is %d\n",p);
	}
}
void display(int a[],int *top)
{
	if(*top==-1)
		printf("Element not present for display due to underflow\n");
	else
	{
		printf("Stack elements in LIFO order are :\n");
		for(int i=*top;i>=0;i--)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
}




