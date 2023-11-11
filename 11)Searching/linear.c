#include<stdio.h>
void main()
{
	int i,n,pos=0,e;
	printf("Enter array size:\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter array element : ");
		scanf("%d",&a[i]);
	}
	printf("Enter element to be searched:\n");
	scanf("%d",&e);
	printf("Array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	for(i=0;i<n;i++)
	{
		if(e==a[i])
		{
			pos=i+1;
			break;
		}
	}
	if(pos==0)
		printf("\nElement %d not found\n",e);
	else
		printf("\nElement %d found at position : %d\n",e,pos);
}
