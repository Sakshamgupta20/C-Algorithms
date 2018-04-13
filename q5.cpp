#include<stdio.h>
int main()
{
	int n,i,target,count=0;
int a[100];
printf("enter number of elements in array ");
scanf("%d",&n);

printf("enter elements of array");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter element want to find ");
scanf("%d",&target);
for(i=1;i<n;i++)
{
	if(a[i]==target)
	{
	count++;
	
}
}
printf("occourance of element is %d times",count);
}



