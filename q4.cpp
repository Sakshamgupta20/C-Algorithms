#include <stdio.h>
 
int main()
{
    int i, j, a, n, number[30];
 
    printf("Enter the value of N \n");
    scanf("%d", &n);
    printf("Enter the numbers \n");
    for (i = 0; i < n; ++i)
        scanf("%d", &number[i]);
    for (i = 0; i < n; i+=2)
    {
       a=number[i];
	number[i]=number[i+1];
	number[i+1]=a;
    }
    printf("swapped elements are");
for(i=0;i<n;i++)
printf("\n%d ",number[i]) ;
}
