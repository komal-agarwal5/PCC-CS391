#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
void insertStart (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;
  if (*head == NULL)
    {
      *head = newNode;
      (*head)->next = *head;
      return;
    }
  struct Node *curr = *head;
  while (curr->next != *head)
    {
      curr = curr->next;
    }
  curr->next = newNode;
  newNode->next = *head;
  *head = newNode;
}
void insertLast (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;
  if (*head == NULL)
    {
      *head = newNode;
      (*head)->next = *head;
      return;
    }
  struct Node *curr = *head;
  while (curr->next != *head)
    {
      curr = curr->next;
    }
  curr->next = newNode;
  newNode->next = *head;
}
int getCurrSize (struct Node *node)
{
  int size = 0;

  while (node != NULL)
    {
      node = node->next;
      size++;
    }
  return size;
}
void insertPosition (int data, int pos, struct Node **head)	
{
  struct Node *newnode, *curNode;
  int i;

  if (*head == NULL)
    {
      printf ("List is empty");
    }
  if (pos == 1)
    {
      insertStart (head, data);
      return;
    }
  else
    {
      newnode = (struct Node *) malloc (sizeof (struct Node));
      newnode->data = data;
      curNode = *head;
      while (--pos > 1)
	{
	  curNode = curNode->next;
	}
      newnode->next = curNode->next;
      curNode->next = newnode;
    }
}

void display (struct Node *head)
{
  if (head == NULL)
    return;

  struct Node *temp = head;
  do
    {
      printf ("%d ", temp->data);
      temp = temp->next;

    }
  while (temp != head);
  printf ("\n");
}
void deleteBegin (struct Node **head)
{
  struct Node *tempNode = *head;
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }
  if (tempNode->next == *head)
    {
      *head = NULL;
      return;
    }
  struct Node *curr = *head;
  while (curr->next != *head)
    curr = curr->next;
  curr->next = (*head)->next;
  *head = (*head)->next;
  free (tempNode);
}
void deleteEnd (struct Node **head)
{
  struct Node *tempNode = *head;
  struct Node *previous;
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }
  if (tempNode->next == *head)
    {
      *head = NULL;
      return;
    }
  while (tempNode->next != *head)
    {
      previous = tempNode;
      tempNode = tempNode->next;
    }
  previous->next = *head;
  free (tempNode);
}
int calcSize (struct Node *head)
{
  int size = 0;
  struct Node *temp = head;
  if (temp == NULL)
    return size;

  do
    {
      size++;
      temp = temp->next;

    }
  while (temp != head);
  return size;
}
void deletePos (struct Node **head, int n)
{

  int size = calcSize (*head);

  if (n < 1 || size < n)
    {
      printf ("Can't delete, %d is not a valid position\n", n);
    }
  else if (n == 1)
    deleteBegin (head);
  else if (n == size)
    deleteEnd (head);
  else
    {
      struct Node *tempNode = *head;
      struct Node *previous;	
      while (--n)
	{ 
	  previous = tempNode;
	  tempNode = tempNode->next;
	}
      previous->next = tempNode->next;
      free (tempNode);
    }
}
int main ()
{
    struct Node *head = NULL;
int ch,item,pos;
	while(1)
	{
		printf("Menu : \n");
		printf("1.Insert at front 2.Insert at end 3.Insert at other position 4.Delete at front 5.Delete at end 6.Delete at other position 7.Display 8.Exit\n");
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
					insertPosition(item,pos,&head);
					break;
			case 4:deleteBegin(&head);
					break;
			case 5:deleteEnd(&head);
					break;
			case 6:printf("Enter position : ");
					scanf("%d",&pos);
                    deletePos(&head,pos);
					break;
			case 7:display(head);
					break;
			default:printf("Program exited : ");
					exit(0);
		}
	}
  return 0;
}