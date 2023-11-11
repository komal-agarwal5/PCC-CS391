#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void insert_rear(int, int*, int*, int[]);
void insert_front(int, int*, int*, int[]);
void delete_rear(int*, int*, int[]);
void delete_front(int*, int*, int[]);
void display(int*, int*, int[]);
void main()
{
	int front=-1, rear=-1,queue[MAX];
	int ch,num;
	while(1)
	{
		printf("Menu\n");
		printf("1.Insert at Front, 2.Insert at Rear, 3.Delete from Front, 4.Delete from Rear, 5.Display, 6.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be inserted : \n");
				scanf("%d",&num);
				insert_front(num,&rear,&front,queue);
				break;
			case 2:printf("Enter the element to be inserted : \n");
				scanf("%d",&num);
				insert_rear(num,&rear,&front,queue);
				break;
			case 3:delete_front(&front, &rear, queue);
				break;
			case 4:delete_rear(&front, &rear, queue);
				break;
			case 5:display(&front, &rear, queue);
				break;
			case 6:printf("Program exited\n");
				exit(0);
				break;
			default:printf("Invalid choice!\n");
		}
	}	
}
void insert_front(int num, int*rear, int*front, int queue[])
{
	if((*front==0 && *rear == MAX-1) || (*front == *rear + 1))
	{
		printf("\n Queue overflow\n");
		return;
	}
	if(*front == -1)
	{
		*front = 0;
		*rear = 0;
	}
	else
	{
		if(*front==0)
			*front = MAX - 1;
		else
			*front=*front-1;
	}
	queue[*front] = num;	
	printf("Element inserted at front\n");
}

void insert_rear(int num, int*rear, int*front, int queue[])
{
	if((*front==0 && *rear == MAX-1) || (*front == *rear + 1))
	{
		printf("\n Queue overflow\n");
		return;
	}
	if(*front == -1)
	{
		*front = 0;
		*rear = 0;
	}
	else
    	{
        if (*rear == MAX - 1)
            *rear = 0;
        else
            *rear = *rear + 1;
    	}
    	queue[*rear] = num;
    	printf("Element inserted at rear\n");
}
void delete_front(int*front, int*rear, int queue[])
{
    int item;
    if (*front == -1)
    {
        printf("Queue underflow!\n");
        return;
    }
    item = queue[*front];
    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        if (*front == MAX - 1)
            *front = 0;
        else
            *front = *front + 1;
    }
    printf("\n Data deleted is : %d\n",item);
}
void delete_rear(int*front, int*rear, int queue[])
{
    int item;
    if (*front == -1)
    {
        printf("Queue underflow\n");
        return;
    }
    item = queue[*rear];
    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        if (*rear == 0)
            *rear = MAX - 1;
        else
            *rear = *rear - 1;
    }
    printf("\n Data deleted is : %d\n",item);
}
void display(int*front, int*rear, int*queue)
{
    int i = 0;
    if (*front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("QUEUE ELEMENTS:\n");
    if (*front <= *rear)
    {
        for (i = *front; i <= *rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = *front; i < MAX; i++)
            printf("%d ",queue[i]);
        for (i = 0; i <= *rear; i++)
            printf("%d ",queue[i]);
    }
    printf("\n");
}


