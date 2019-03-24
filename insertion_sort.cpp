#include<stdio.h>


void insertion(int arr[],int n)
{
	int key,j;
	
for(int i=1;i<n;i++)
{
	j=i;
	while(j>0 && arr[j-1]>arr[j])
	{
		key=arr[j-1];
		arr[j-1]=arr[j];
		arr[j]=key;
		j=j-1;
	}
}
}

void insertion_fragment(int arr[],int k1,int n)
{
	int key,j;
	
for(int i=k1;i<n;i++)
{
	j=i;
	while(j>0 && arr[j-1]>arr[j])
	{
		key=arr[j-1];
		arr[j-1]=arr[j];
		arr[j]=key;
		j=j-1;
	}
}
}

int main()
{

int n,k1,k2;
printf("\nEnter NUmber of Elemets in Array\n");
scanf("%d",&n);

int arr[n];
printf("\nEnter Elemets Of Array\n");
for(int i=0;i<n;i++)
{
	scanf("%d",&arr[i]);
}

printf("\nEnter starting point for sorting\n");
scanf("%d",&k1);
printf("\nEnter ending point for sorting\n");
scanf("%d",&k2);

//insertion(arr,n);
insertion_fragment(arr,k1,k2);

for(int i=0;i<n;i++)
{
	printf("%d",arr[i]);
}
}
