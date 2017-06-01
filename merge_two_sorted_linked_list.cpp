// merge two sorted linked list recursively and itteratively
#include<iostream>
#include<stdlib.h>

using namespace std;

// create the structure
struct node{
	int data;
	struct node* next;
};

//insert a node in linked list
struct node* add_node(struct node* root,int x)
{
	if(root==NULL)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->data=x;
		temp->next=NULL;
		return temp;	
	}	
	if(root->data>x)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->data=x;
		temp->next=root;
		return temp;
	}
	else
	{
		struct node* head=root;
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->data=x;
		temp->next=NULL;
		while(root->next!=NULL && root->next->data<x)
			root=root->next;
		temp->next=root->next;
		root->next=temp;
		return head;
	}
}

// displlay the linked list
void display(struct node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	display(root->next);
}

/*
// merge two sorted linked list recursively
struct node* merge(struct node* root1, struct node* root2)
{
	if(root1==NULL)
		return root2;
	if(root2==NULL)
		return root1;
	if(root1->data<root2->data)
	{
		root1->next=merge(root1->next,root2);
		return root1;
	}
	else
	{
		root2->next=merge(root1,root2->next);
		return root2;
	}
}
*/

//merge two sorted linked list itteratively
struct node* merge(struct node* root1,struct node* root2)
{
	if(root1==NULL)
		return root2;
	if(root2==NULL)
		return root1;
	struct node *temp=NULL;
	struct node* head=NULL;
	if(root1->data<root2->data)
	{
		temp=root1;
		root1=root1->next;	
	}
	else
	{
		temp=root2;	
		root2=root2->next;
	}
	head=temp;
	while(root1!=NULL && root2!=NULL)
	{
		if(root1->data<root2->data)
		{
			temp->next=root1;
			root1=root1->next;
		}
		else
		{
			temp->next=root2;
			root2=root2->next;
		}
		temp=temp->next;
	}
	if(root1==NULL)
		temp->next=root2;
	if(root2==NULL)
		temp->next=root1;
	return head;
}

int main()
{
	struct node* root1=NULL;
	struct node* root2=NULL;
	root1=add_node(root1,1);
	root1=add_node(root1,3);
	root1=add_node(root1,6);
	root1=add_node(root1,10);
	root2=add_node(root2,2);
	root2=add_node(root2,4);
	root2=add_node(root2,11);
	root2=add_node(root2,12);
	root2=add_node(root2,15);
	display(root1);
	cout<<"\n";
	display(root2);
	root1=merge(root1,root2);
	cout<<"\n";
	display(root1);
	return 0;
}
