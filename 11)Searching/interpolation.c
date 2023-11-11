#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int interpolation(int arr[], int x, int low, int high)
{
	if(low<=high && x>=arr[low] && x<=arr[high])
	{
	 	int pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));
		if (arr[pos] < x)
            return interpolation(arr, x, pos + 1, high);
        else if (arr[pos] > x)
            return interpolation(arr, x, low, pos - 1);
        else
            return pos;
    }
    else
        return -1;
}
int main()
{
	int arr[MAX],n,i,x;
	printf("Enter the number of elements : \n");
	scanf("%d",&n);
	printf("Enter the elements in the array : \n");
	for(i=0;i<n;i++)
	{
		printf("Enter element at index %d\n",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be searched : \n");
	scanf("%d",&x);
	int pos = interpolation(arr, x, 0, n-1);
	if (pos != -1)
        printf("%d is in at index %d in the array\n", x, pos);
    else
        printf("%d is not in the array\n", x);
    return 0;
}

