#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}node;
typedef struct stack
{
    node *data;
    struct stack *next;
}stack;
typedef struct queue{
    node *data;
    struct queue *next;
}queue;
node* createNode(int data){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->data = data;
    return ptr;
}
int isEmpty(stack *top){
    if (top == NULL)
        return 1;
    return 0;
}
int isQueueEmpty(queue *front){
    if (front == NULL)
        return 1;
    return 0;
}
void push(stack **top,node *new){
    stack *temp = (stack*) malloc (sizeof(stack));
    temp->data = new;
    temp->next = *top;
    *top = temp;
}
node *pop(stack **top){
    node *ptr = (node*) malloc (sizeof(node));
    stack *temp = (stack*) malloc (sizeof(stack));
    temp = *top;
    *top = temp->next;
    ptr = temp->data;
    free(temp);
    return ptr;
}
void enqueue(queue **front,queue **rear,node *new){
    queue *temp = (queue*)malloc(sizeof(queue));
    temp->data = new;
    temp->next = NULL;
    if (isQueueEmpty(*front)){
        *front = temp;
        *rear = temp;
    }
    else{
        (*rear)->next = temp;
        *rear = temp;
    }
}
node* dequeue(queue **front,queue **rear){
    queue *temp = (queue*)malloc(sizeof(queue));
    node *ptr = (node*)malloc(sizeof(node));
    temp = *front;
    ptr = temp->data;
    if(temp->next == NULL){
        *front = *rear = NULL;
    }
    else{
        *front = temp->next;
    }
    free(temp);
    return ptr;
}
int queue_size(queue *front,queue *rear){
    int size;
    if (isQueueEmpty(front)){
        size = 0;
    }
    else {
        queue *ptr = (queue*)malloc(sizeof(queue));
        ptr = front;
        size = 1;
        while(ptr!=rear){
            size++;
            ptr = ptr->next;
        }
    }
    return size;
}
void preOrder(node *root){
    if(root == NULL){
        printf("Tree is empty!\n");
        return;
    }
    stack *top = (stack*)malloc(sizeof(stack));
    node *ptr = (node*)malloc(sizeof(node));
    top = NULL;
    ptr = root;
    int flag = 1;
    while(flag){
        if (ptr!=NULL) {
            printf("%d ",ptr->data);
            push(&top,ptr);
            ptr = ptr->left;
        }
        else if(!isEmpty(top)){
            ptr = pop(&top);
            ptr = ptr->right;
        }
        else{
            flag = 0;
        }
    }
}
void inOrder(node *root){
    if(root == NULL){
        printf("Tree is empty!\n");
        return;
    }
    stack *top = (stack*)malloc(sizeof(stack));
    node *ptr = (node*)malloc(sizeof(node));
    top = NULL;
    ptr = root;
    int flag = 1;
    while(flag){
        if (ptr!=NULL) {
            push(&top,ptr);
            ptr = ptr->left;
        }
        else if(!isEmpty(top)){
            ptr = pop(&top);
            printf("%d ",ptr->data);
            ptr = ptr->right;
        }
        else{
            flag = 0;
        }
    }
}
void postOrder(node *root){
    if(root == NULL){
        printf("Tree is empty!\n");
        return;
    }
    stack *top = (stack*)malloc(sizeof(stack));
    node *ptr = (node*)malloc(sizeof(node));
    node *q = (node*)malloc(sizeof(node));
    top = NULL;
    ptr = root;
    q = root;
    while(1){
        while(ptr->left!=NULL)
        {
            push(&top,ptr);
            ptr=ptr->left;
        }

        while( ptr->right==NULL || ptr->right==q )
        {
            printf("%d  ",ptr->data);
            q = ptr;
            if( isEmpty(top) )
                return;
            ptr = pop(&top);
        }
        push(&top,ptr);
        ptr = ptr->right;
    }
}

int height(node *root){
    if(root == NULL){
        return 0;
    }
    node *ptr = (node*)malloc(sizeof(node));
    ptr = root;
    queue *front = (queue*)malloc(sizeof(queue));
    queue *rear = (queue*)malloc(sizeof(queue));
    front = rear = NULL;
    int h = 0;
    int count = 0;
    enqueue(&front,&rear,ptr);
    while(!isQueueEmpty(front)){
        h++;
        count = queue_size(front,rear);
        while(count--){
            ptr = front->data;
            if (ptr->left != NULL){
                enqueue(&front,&rear,ptr->left);
            }
            if (ptr->right != NULL){
                enqueue(&front,&rear,ptr->right);
            }
            dequeue(&front,&rear);
        }
    }
    return h;
}

void insert(node **root,int data){
    if(*root == NULL){
        *root = createNode(data);
        printf("%d is inserted at root of the tree.\n",data);
        return;
    }
    node *ptr = (node*) malloc (sizeof(node));
    node *prev = (node*) malloc (sizeof(node));
    ptr = *root;
    while(ptr != NULL){
        prev = ptr;
        if (ptr->data == data){
            printf("Invalid Input : Duplicate element\n");
            return;
        }
        else if(ptr->data > data){
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    ptr = createNode(data);
    if (prev->data > data){
        prev->left = ptr;
    }
    else{
        prev->right = ptr;
    }
    printf("%d is inserted in the tree.\n",data);
}
void main(){
    int n,data;
    node *root = NULL;
    
    do{
        printf("Menu for Binary Search Tree :\n");
        printf("1 => Insert 2 => Preorder 3 => Inorder 4 => Postorder 5 => Height 0 => Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&n);
        switch(n){
            case 1 :
                printf("Enter the data : ");
                scanf("%d",&data);
                insert(&root,data);
                break;
            case 2 :
                printf("Preorder : ");
                preOrder(root);
                printf("\n");
                break;
            case 3 :
                printf("Inorder : ");
                inOrder(root);
                printf("\n");
                break;
            case 4 :
                printf("Postorder : ");
                postOrder(root);
                printf("\n");
                break;
            case 5 :
                printf("Height of the tree = %d\n",height(root));
                break;
            case 0 :
                printf("Terminating the program.\n");
                break;
            default :
                printf("Invalid Input!\n");
                break;
        }
    } while(n!=0);
}













