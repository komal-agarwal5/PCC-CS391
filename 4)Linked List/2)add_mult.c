#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
typedef struct node
{
  int coeff;
  int exp;
  struct node *next;
} Node;

// Function to create a new term node
Node *createNode(int coeff, int exp)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  newNode->coeff = coeff;
  newNode->exp = exp;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a term into a polynomial
void insertTerm(Node **poly, int coeff, int exp)
{
  Node *newNode = createNode(coeff, exp);
  if (*poly == NULL)
  {
    *poly = newNode;
  }
  else
  {
    Node *current = *poly;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newNode;
  }
}

// Function to add two polynomials
Node *addPolynomials(Node *poly1, Node *poly2)
{
  Node *result = NULL;
  while (poly1 != NULL && poly2 != NULL)
  {
    if (poly1->exp > poly2->exp)
    {
      insertTerm(&result, poly1->coeff, poly1->exp);
      poly1 = poly1->next;
    }
    else if (poly1->exp < poly2->exp)
    {
      insertTerm(&result, poly2->coeff, poly2->exp);
      poly2 = poly2->next;
    }
    else
    {
      int sum = poly1->coeff + poly2->coeff;
      if (sum != 0)
      {
        insertTerm(&result, sum, poly1->exp);
      }
      poly1 = poly1->next;
      poly2 = poly2->next;
    }
  }
  while (poly1 != NULL)
  {
    insertTerm(&result, poly1->coeff, poly1->exp);
    poly1 = poly1->next;
  }
  while (poly2 != NULL)
  {
    insertTerm(&result, poly2->coeff, poly2->exp);
    poly2 = poly2->next;
  }
  return result;
}

// Function to multiply two polynomials
Node *multiplyPolynomials(Node *poly1, Node *poly2)
{
  Node *result = NULL;
  Node *current1 = poly1;
  while (current1 != NULL)
  {
    Node *current2 = poly2;
    while (current2 != NULL)
    {
      int coeff = current1->coeff * current2->coeff;
      int exp = current1->exp + current2->exp;
      insertTerm(&result, coeff, exp);
      current2 = current2->next;
    }
    current1 = current1->next;
  }
  return result;
}

// Function to display a polynomial
void displayPolynomial(Node *poly)
{
  Node *current = poly;
  while (current != NULL)
  {
    printf("%dx^%d ", current->coeff, current->exp);
    if (current->next != NULL)
    {
      printf("+ ");
    }
    current = current->next;
  }
  printf("\n");
}

// Function to free memory allocated for a polynomial
void freePolynomial(Node *poly)
{
  Node *current = poly;
  while (current != NULL)
  {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
}

int main()
{
  Node *poly1 = NULL;
  Node *poly2 = NULL;

  int n1, n2;
  int coeff, exp;

  printf("Enter the number of terms in the first polynomial: ");
  scanf("%d", &n1);
  printf("Enter the terms for the first polynomial (coeff exp):\n");
  for (int i = 0; i < n1; i++)
  {
    scanf("%d %d", &coeff, &exp);
    insertTerm(&poly1, coeff, exp);
  }

  printf("Enter the number of terms in the second polynomial: ");
  scanf("%d", &n2);
  printf("Enter the terms for the second polynomial (coeff exp):\n");
  for (int i = 0; i < n2; i++)
  {
    scanf("%d %d", &coeff, &exp);
    insertTerm(&poly2, coeff, exp);
  }

  printf("Polynomial 1: ");
  displayPolynomial(poly1);
  printf("Polynomial 2: ");
  displayPolynomial(poly2);

  Node *sum = addPolynomials(poly1, poly2);
  printf("Sum of the two polynomials: ");
  displayPolynomial(sum);

  Node *product = multiplyPolynomials(poly1, poly2);
  printf("Product of the two polynomials: ");
  displayPolynomial(product);

  // Free memory
  freePolynomial(poly1);
  freePolynomial(poly2);
  freePolynomial(sum);
  freePolynomial(product);

  return 0;
}
