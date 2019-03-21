#include<stdio.h> 
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};


struct node *front(struct node *head, int data)
{
printf("Inserting %d in Front \n",data);
struct node *p=(struct node*)malloc(sizeof(struct node));
p->data=data;
p->next=head;
return(p);
}

void end(struct node *head, int data)
{
	printf("Inserting %d in End \n",data);
	struct node *p,*q;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=data;
	p->next=NULL;
	q=head;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
}

void after(struct node *a, int data)
{
	printf("Inserting %d after %d \n",data,a->data);
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=data;
	p->next=a->next;
	a->next=p;
}

void display(struct node *head)
{
	printf("Elements in Linked List Are:- \n");
		while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
		//printf("%d \n",head);
	}
}

int main()
{
	int n;
	struct node *prev,*head,*p;	
	
	printf("How many Elements Do you want to insert \n");
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		p=(struct node*)malloc(sizeof(struct node));
		printf("Enter %d element \n",i+1);
		scanf("%d",&p->data);
		p->next=NULL;
		if(head==NULL)
		{
			head=p;
		}
		else
		{
			prev->next=p;
			
		}
		prev=p;
		
	}
	
	head=front(head,10);
	end(head,20);
	after(head->next->next,30);
	
	display(head);
}
