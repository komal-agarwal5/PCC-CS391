#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int exp,coeff;
	struct Node *next;
};
typedef struct Node Node;
void insert(Node** poly,int coeff,int exp)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->coeff=coeff;
	temp->exp=exp;
	temp->next=NULL;
	if(*poly==NULL)
	{
		*poly=temp;
		return;
	}
	Node *current=*poly;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=temp;
}
void print(Node *poly)
{
	if(poly==NULL)
	{
		printf("0\n");
		return;
	}
	Node *current=poly;
	while(current!=NULL)
	{
		printf("%dx^%d",current->coeff,current->exp);
		if(current->next!=NULL)
			printf("+");
		current=current->next;
	}
	printf("\n");
}
Node *add(Node *poly1,Node *poly2)
{
	Node *result=NULL;
	while(poly1!=NULL && poly2!=NULL)
	{
		if(poly1->exp == poly2->exp)
		{
			insert(&result,poly1->coeff+poly2->coeff,poly1->exp);
			poly1=poly1->next;
			poly2=poly2->next;
		}
		else if(poly1->exp>poly2->exp)
		{
			insert(&result,poly1->coeff,poly1->exp);
			poly1=poly1->next;
		}
		else
		{
			insert(&result,poly2->coeff,poly2->exp);
			poly2=poly2->next;
		}
	}
	while (poly1 != NULL) {
        insert(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insert(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
	return result;
}
void main()
{
	int coeff,exp;
	Node *poly1=NULL;
	Node *poly2=NULL;
	int m,n;
	printf("Enter number of terms in first polynomial : ");
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		printf("Enter coefficient and exponent : \n");
		scanf("%d%d",&coeff,&exp);
		insert(&poly1,coeff,exp);
	}
	printf("Enter number of terms in second polynomial : ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("Enter coefficient and exponent : \n");
		scanf("%d%d",&coeff,&exp);
		insert(&poly2,coeff,exp);
	}
	printf("Polynomial 1 is : ");
	print(poly1);
	printf("Polynomial 2 is : ");
	print(poly2);
	Node *result=add(poly1,poly2);
	printf("Resultant polynomial is : ");
	print(result);
}





