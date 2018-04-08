
#include<stdio.h>
int main()
{
	int n,i,large;
int a[100];
printf("enter number of elements in array ");
scanf("%d",&n);

printf("enter elements of array");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
large=a[0];
for(i=1;i<n;i++)
{
	if(a[i]>large)
	large=a[i];
}
int large2=a[0];
for(i=1;i<n;i++)
{
	if(a[i]>large2 && a[i]!=large)
	large2=a[i];
}
int small=a[0];
for(i=1;i<n;i++)
{
	if(a[i]<small)
	small=a[i];
}
printf("\nelements of array are");
for(i=0;i<n;i++)
{
printf("\n %d",a[i]);
}
printf("\nsecond largest element is %d",large2);
printf("\nsmallest value is %d",small);
}
