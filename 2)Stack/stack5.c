#include<stdio.h>
#include<stdlib.h>
void tower(int n,char source,char dest,char aux);
void tower(int n,char source,char dest,char aux)
{
	if(n==1)
	{
		printf("Move disk 1 from %c to %c\n",source,dest);
		return ;
	}
	tower(n-1,source,aux,dest);
	printf("Move disk %d from %c to %c\n",n,source,dest);
	tower(n-1,aux,dest,source);
}
void main()
{
	int n;
	printf("Enter number of disks : ");
	scanf("%d",&n);
	tower(n,'a','c','b');
}
