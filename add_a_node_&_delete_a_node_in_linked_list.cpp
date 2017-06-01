// wap  to add a node in linked list : at top, between and end
#include<stdio.h> 
#include<iostream>
#include<stdlib.h>
using namespace std;

// structure  of node
struct node{
	struct node* next;
	int data;
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

//delete a node from linked list
struct node* delete_node(struct node* root, int x)
{
	if(root==NULL)
		return root;
	if(root->data==x)
		return  root->next;
	else
	{
		struct node* head=root;
		while(root->next!=NULL && root->next->data!=x)
			root=root->next;
		if(root->next!=NULL)
		{
			struct node* temp=root->next;
			root->next=root->next->next;
			free(temp);
		}
		return head;
	}	
}

// display linked list
void display(struct node* root)
{
	if(root==NULL)
		return;
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		root=root->next;
	}
}

//main function
int main()
{
	struct node* root=NULL;
	root=add_node(root,4);
	display(root);
	cout<<"\n";
	root=add_node(root,2);
	display(root);
	cout<<"\n";
	root=add_node(root,1);
	display(root);
	cout<<"\n";
	root=add_node(root,7);
	display(root);
	cout<<"\n";
	root=add_node(root,5);
	display(root);
	cout<<"\n";
	root=add_node(root,3);
	display(root);
	cout<<"\n";
	root=add_node(root,6);
	display(root);
	cout<<"\n";
	root=delete_node(root,1);
	display(root);
	cout<<"\n";
	root=delete_node(root,6);
	display(root);
	cout<<"\n";
	root=delete_node(root,7);
	display(root);
	cout<<"\n";
	root=delete_node(root,3);
	display(root);
	cout<<"\n";
	return 0;
}
