#include<stdio.h>
void main()
{
	int i,j,mid,l,u,n,e,pos=0,temp;
	printf("Enter array size:\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter element : ");
		scanf("%d",&a[i]);
	}
	printf("Enter element to be searched :\n");
	scanf("%d",&e);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Sorted Array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	l=0;
	u=n-1;
	while(l<=u)
	{
		mid=(l+u)/2;
		if(a[mid]==e)
		{
			pos=mid+1;
			break;
		}
		else if(a[mid]<e)
		{
			l=mid+1;
		}
		else if(a[mid]>e)
		{
			u=mid-1;
		}
	}
	if(pos==0)
		printf("\nElement %d not found\n",e);
	else
		printf("\nElement %d found at position : %d\n",e,pos);
}
