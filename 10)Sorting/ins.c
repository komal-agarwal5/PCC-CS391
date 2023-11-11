#include<stdio.h>
void main()
{
	int x,y,n,key;
	printf("Enter array size : ");
	scanf("%d",&n);
	int a[n];
	for(x=0;x<n;x++)
	{
		printf("Enter array element : ");
		scanf("%d",&a[x]);
	}
	printf("Original array is :\n");
	for(x=0;x<n;x++)
		printf("%d ",a[x]);
	for(x=1;x<n;x++)
	{
		key=a[x];
		y=x-1;
		while(y>=0 && a[y]>key)
		{
			a[y+1]=a[y];
			y=y-1;
		}
		a[y+1]=key;
	}
	printf("\nSorted array is :\n");
	for(x=0;x<n;x++)
		printf("%d ",a[x]);
	printf("\n");
}			
		
