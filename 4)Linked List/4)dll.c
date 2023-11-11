#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};
int getLength (struct Node *node);
void insertStart (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;
  newNode->next = *head;
  newNode->prev = NULL;
  if (*head != NULL)
    (*head)->prev = newNode;
  *head = newNode;
}
void insertLast (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL)
    {
      *head = newNode;
      newNode->prev = NULL;
      return;
    }
  struct Node *temp = *head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = newNode;
  newNode->prev = temp;
}
void insertPosition (struct Node **head, int n, int data)
{
  int len = getLength (*head);
  if (n == 0)
    {
      insertStart (head, data);
      return;
    }
  if (n == len)
    {
      insertLast (head, data);
      return;
    }
  if (n < 0 || n > len)
    printf ("Invalid position to insert\n");
  else
    {
      struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
      newNode->data = data;
      newNode->next = NULL;
      newNode->prev = NULL;
      struct Node *temp = *head;
      while (--n)
	temp = temp->next;
      (temp->next)->prev = newNode;
      newNode->next = temp->next;
      newNode->prev = temp;
      temp->next = newNode;
    }
}
void deleteStart (struct Node **head)
{
  struct Node *temp = *head;
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete\n\n");
      return;
    }
  if (temp->next == NULL)
    {
      printf ("%d deleted\n\n", temp->data);
      *head = NULL;
      return;
    }
  *head = (*head)->next;
  (*head)->prev = NULL;
  printf ("%d deleted \n", temp->data);
  free (temp);
}
void deleteLast (struct Node **head)
{
  struct Node *temp = *head;
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete \n");
      return;
    }
  if (temp->next == NULL)
    {
      printf ("%d deleted\n\n", temp->data);
      *head = NULL;
      return;
    }
  while (temp->next != NULL)
    temp = temp->next;
  struct Node *secondLast = temp->prev;
  secondLast->next = NULL;
  printf ("%d deleted \n", temp->data);
  free (temp);
}
void deleteNthNode (struct Node **head, int n)
{
  int len = getLength (*head);
  if (n < 1 || n > len)
    {
      printf ("Enter valid position\n\n");
      return;
    }
  if (n == 1)
    {
      deleteStart (head);
      return;
    }
  if (n == len)
    {
      deleteLast (head);
      return;
    }
  struct Node *temp = *head;
  while (--n)
    {
      temp = temp->next;
    }

  struct Node *previousNode = temp->prev;	
  struct Node *nextNode = temp->next;	
  previousNode->next = temp->next;
  nextNode->prev = temp->prev;
  printf ("%d deleted \n", temp->data);
  free (temp);
}
void display (struct Node *node)
{
  struct Node *end = NULL;
  printf ("List : ");
  while (node != NULL)
    {
      printf (" %d ", node->data);
      end = node;
      node = node->next;
    }
    printf("\n");
}
int getLength (struct Node *node)
{
  int len = 0;

  while (node != NULL)
    {
      node = node->next;
      len++;
    }
  return len;
}
void reverse(struct Node **head)
{
	struct Node *t1,*t2;
    struct Node *temp = *head;
	t1=t2=NULL;
	if(*head==NULL)
		printf("List is empty\n");
	else
	{
		while(*head!=NULL)
		{
			t2=(*head)->next;
			(*head)->next=t1;
			t1=*head;
			*head=t2;
		}
		*head=t1;
		temp=*head;
		printf("Reversed list is : ");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
int main ()
{
  struct Node *head = NULL;
  int ch,item,pos;
	while(1)
	{
		printf("Menu : \n");
		printf("1.Insert at front 2.Insert at end 3.Insert at other position 4.Delete at front 5.Delete at end 6.Delete at other position 7.Display 8.Reverse 9.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter value to be inserted : ");
					scanf("%d",&item);
					insertStart(&head,item);
					break;
			case 2:printf("Enter value to be inserted : ");
					scanf("%d",&item);
					insertLast(&head,item);
					break;
			case 3:printf("Enter value to be inserted : ");
					scanf("%d",&item);
                    printf("Enter position : ");
					scanf("%d",&pos);
					insertPosition(&head,pos,item);
					break;
			case 4:deleteStart(&head);
					break;
			case 5:deleteLast(&head);
					break;
			case 6:printf("Enter position : ");
					scanf("%d",&pos);
                    deleteNthNode(&head,pos);
					break;
			case 7:display(head);
					break;
			case 8:reverse(&head);
					break;
			default:printf("Program exited : ");
					exit(0);
		}
	}
  return 0;
}