#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void display(int*, int*, int*);
void insert(int,int*,int*,int*);
void del(int*, int*, int*);
void peek(int*, int*);
int isEmpty(int*);
int isFull(int*, int*);
void main()
{
	int queue[MAX],front=-1,rear=-1;
	int choice,item;
	while(1)
	{
		printf("Menu\n");
		printf("1 to insert, 2 to delete, 3 to peek, 4 to display, 5 to exit : ");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item value to be inserted : \n");
				scanf("%d",&item);
				insert(item,queue,&rear,&front);
				break;
			case 2:del(queue,&rear,&front);
				break;
			case 3:peek(queue, &front);
				break;
			case 4:display(queue, &rear, &front);
				break;
			case 5:printf("Program exited\n");
				exit(0);
				break;
			default:printf("Invalid Choice\n");
		}
	}
}
void insert(int item, int*queue, int*rear, int*front)
{
	if(isFull(rear, front))
	{
		printf("\nQueue Overflow\n");
		return;
	}
	if (*front==-1)
		*front=0;
	if (*rear==MAX-1)
		*rear=0;
	else
		*rear=*rear+1;
	queue[*rear]=item;
	printf("Element inserted in queue\n");
}
void del(int*queue, int*rear, int*front)
{
	int item;
	if(isEmpty(front))
	{
		printf("\nQueue Underflow\n");
		return;
	}
	item=queue[*front];
	if(*front==*rear)
	{
		*front=-1;
		*rear=-1;
	}
	else if(*front==MAX-1)
	       *front=0;
	else
		*front=*front+1;
	printf("Data deleted is : %d\n",item);
}
int isEmpty(int*front)
{
	if(*front==-1)
		return 1;
	else
		return 0;
}
int isFull(int*rear, int*front)
{
	if((*front==0 && *rear==MAX-1) || (*front==*rear+1))
		return 1;
	else
		return 0;
}
void peek(int*queue, int*front)
{
	if(isEmpty(front))
	{
		printf("\nQueue Underflow\n");
		return;
	}
	printf("The element at the front is : %d\n", queue[*front]);
}
void display(int*queue, int*rear, int*front)
{
	int i;
	if (isEmpty(front))
	{
		printf("Queue is empty, nothing to display\n");
		return;
	}
	printf("The elements in the circular queue are : \n");
	i=*front;
	if(*front<=*rear)
	{
		while(i<=*rear)
			printf("%d ",queue[i++]);
	}
	else
	{
		while(i<=MAX-1)
			printf("%d ",queue[i++]);
		i=0;
		while(i<=*rear)
			printf("%d ",queue[i++]);
	}
	printf("\n");
}	
	

	
