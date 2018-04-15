#include<stdio.h>
#include<conio.h>
int visited[10]={0};
int min,mincost=0;
int matrix[10][10];
int a,b,u,v,n,i,j,next=1;
int main()
{
 printf("Enter the number of nodes:");
 scanf("%d",&n);
 printf("Enter the adjacency matrix:n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   printf("%d%d",i,j);
   scanf("%d",&matrix[i][j]);
   if(matrix[i][j]==0)
    matrix[i][j]=999;
  }
 visited[1]=1;
 printf("n");
 while(next<n)
 {
  for(i=1,min=999;i<=n;i++)
   for(j=1;j<=n;j++)
    if(matrix[i][j]<min)
     if(visited[i]!=0)
     {
      min=matrix[i][j];
      a=i;
      b=j;
     }
  if(visited[a]==0 || visited[b]==0)
  {
   printf("n Edge %d:(%d %d) cost:%d",next++,a,b,min);
   mincost+=min;
   visited[b]=1;
  }
  matrix[a][b]=matrix[b][a]=999;
 }
 printf("n Minimun cost=%d",mincost);
}
