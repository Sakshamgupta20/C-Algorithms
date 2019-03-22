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
	printf("\nElements in Linked List Are:- \n");
		while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
		//printf("%d \n",head);
	}
}

void delete_link(struct node *before_delete)
{
	printf("Deleting Element after %d \n",before_delete->data);
	struct node *temp;
	temp=before_delete->next;
	before_delete->next=temp->next;	
}

struct node *reverse(struct node *head)
{
	struct node *next,*prev=NULL;
	struct node *current=head;
	while(current !=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return(prev);
}

struct node *reverse_every_knode(struct node *head,int k)
{	
	struct node *next,*prev=NULL;
	struct node *current=head;
	int count=0;
	while(current !=NULL && count<k )
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	
	if(next!=NULL)
	{
		head->next=reverse_every_knode(next,k);
	}
	return(prev);
}

struct node *reverse_upto_knode(struct node *head,int k)
{	
	struct node *next,*prev=NULL;
	struct node *current=head;
	int count=0;
	while(current !=NULL && count<k )
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	
	if(next!=NULL)
	{
		head->next=next;
	}
	
	return(prev);
}

void middle_element(struct node *head)
{	
	struct node *tortoise=head;
	struct node *hare=head;
	if(head!=NULL)
	{
		while(hare!=NULL && hare->next!=NULL)
		{
			hare=hare->next->next;
			tortoise=tortoise->next;
		}
		printf("\nThe Middle element is %d \n",tortoise->data);
	}
}

void cycle_detect(struct node *head)
{	
	struct node *tortoise=head;
	struct node *hare=head;
	if(head!=NULL)
	{
		while(hare!=NULL && tortoise!=NULL && hare->next!=NULL)
		{
			hare=hare->next->next;
			tortoise=tortoise->next;
			if(tortoise==hare)
			{
				printf("\nLoop Found\n");
				break;
			}
		}
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
	
	//head=front(head,10);
	//end(head,20);
	//after(head->next->next,30);

	//delete_link(head->next->next);
	//head=reverse(head);
	//int k;
	//printf("\nEnter upto which group you want to reverse \n");
	//scanf("%d",&k);
	//head=reverse_every_knode(head,k);
	
	//int k;
	//printf("\nEnter upto which node you want to reverse \n");
	//scanf("%d",&k);
	//head=reverse_upto_knode(head,k);
	//display(head);

	display(head);
	middle_element(head);

	head->next->next->next->next=head;  //If elements are 5 then loop will be formed
	cycle_detect(head);
}
