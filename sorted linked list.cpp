#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*q,*start,*t,*temp;
void insert_sort()
{
	int value;
 t=(struct node*)malloc(sizeof (struct node));	
 
 printf("enter the data for linked list:- ");
 scanf("%d",&value);

 t->data=value;
 if(start==NULL)
 {
 	t->next=NULL;
 	start=t;
 }
 else
 {
   q=start;
   if(q->data >= t->data)
   {
   	t->next=q;
   	start=t;
   }
   else
   {
   	while(q->next!=NULL)
   	{
   		if(q->data >= t->data)
   		{
   				temp=q->next;
   	            q->next=t;
            	t->next=temp;
            	break;
   		}
   		q=q->next;
   	}
   	q->next=t;
   	t->next=NULL;
   }
  
 }
 

}
void display()
{
 printf("linked list in sorted form ");
 q=start;
 while(q!=NULL)
 {
 	printf("\n %d",q->data);
 	q=q->next;
 }	
}

int main()
{
	int choice;
	do
	{
		printf("\n enter your choice:-\n 1.press 1 to enter node in linked list \n 2.press 2 for display \n 3.press -1 for exit ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:insert_sort();
		break;
		
		case 2:display();
		break;
		
		default:printf("you have entered the wrong choice");
		break;
		}
		
	}while(choice!=-1);
	return 0;
}
