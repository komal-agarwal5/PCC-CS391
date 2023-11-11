#include<stdio.h>
void main()
{
    int n,x,c=0;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter array element : ");
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched : ");
    scanf("%d",&x);
    printf("Array is : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            c++;
            printf("\n%d is present at index %d ",x,i);
        }
    }
    if(c==0)
        printf("\n%d is not present in the array",x);
    else
        printf("\n%d is present %d times",x,c);
}
