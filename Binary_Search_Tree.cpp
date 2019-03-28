#include<stdio.h> 
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};


struct node *newnode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
	inorder(root->left);
	printf("%d\n",root->data);
	inorder(root->right);
	}
}

struct node *insert(struct node *node,int data)
{
	if(node==NULL)
	{
		return(newnode(data));
	}
	if(data<node->data)
	{
		node->left=insert(node->left,data);
	}
	else if(data>node->data)
	{
		node->right=insert(node->right,data);
	}
	return(node);
}
struct node* search(struct node *node,int data)
{
	if (node->data == data) 
	{
	printf("Data Found");
	}
	if(data<node->data)
	{
		return(search(node->left,data));
	}
	else if(data>node->data)
	{
		return(search(node->right,data));
	}
}

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current->left != NULL) 
	current = current->left; 
	return current; 
} 

struct node *deleteNode(struct node *root,int data)
{
	if(root==NULL)
	{
		return root;
	}
	
	if(data<root->data)
	{
		root->left=deleteNode(root->left,data);
	}
	else if(data>root->data)
	{
		root->right=deleteNode(root->right,data);
	}
	else
	{
	if(root->left==NULL)
	{
		struct node *temp=root->right;
		free(root);
		return(temp);
	}
	if(root->right==NULL)
	{
		struct node *temp=root->left;
		free(root);
		return(temp);
	}
	struct node *temp=minValueNode(root->right);
	root->data=temp->data;
	root->right=deleteNode(root->right, temp->data); 
}
return root;
}
int main()
{
	struct node *root=NULL;
	root=insert(root,50);
	insert(root,30);
	insert(root,20); 
    insert(root,40); 
    insert(root,70); 
    insert(root,60); 
    insert(root,80);	
    inorder(root);
    
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 20\n"); 
    root = deleteNode(root, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 30\n"); 
    root = deleteNode(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 50\n"); 
    root = deleteNode(root, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
}
