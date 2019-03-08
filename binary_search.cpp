#include<stdio.h>

int binarysearch(int arr[],int l, int r, int x)
	{
	while(l<=r)
		{
		int mid=l+(r-l)/2;
		printf("%d",mid);
		if(arr[mid]==x)
			{
			return mid;	
			}
		if(arr[mid]>x)
			{
			r=mid-1;
			}
		else
			{
			l=mid+1;
			}
		}
	return -1;
	}

int main()
{
int result;
int arr[]={1,3,4,10,40,50};
int n=sizeof(arr)/sizeof(arr[0]);
int x=50;
result= binarysearch(arr,0,n-1,x);
(result == -1) ? printf("Element is not present in array"): printf("Element is present at index %d", result);
}


