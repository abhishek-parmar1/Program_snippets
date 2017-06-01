// reverse a linked list
#include<iostream>
#include<stdlib.h>

using namespace std;

// create the structure
struct node{
	int data;
	struct node* next;
};

// crete the linked list or add a node to the linked list 
struct node* create_linked_list(struct node* root,int key)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->data=key;
	if(root==NULL)
	{
		return temp;	
	}
	else
	{
		struct node* head=root;
		while(head->next!=NULL)
		{
			head=head->next;
		}
		head->next=temp;
		return root;
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

// reverse a linked list
struct node* reverse(struct node* root)
{
	if(root==NULL || root->next==NULL)
		return root;
	struct node *a=NULL;
	struct node *b=NULL;
	struct node *c=NULL;
	a=root;
	while(a!=NULL)
	{
		b=a;
		a=a->next;
		b->next=c;
		c=b;
	}
	return c;
}
int main()
{
	struct node* root=NULL;
	root=create_linked_list(root,1);
	root=create_linked_list(root,2);
	root=create_linked_list(root,3);
	root=create_linked_list(root,4);
	root=create_linked_list(root,5);
	root=create_linked_list(root,6);
	display(root);
	root=reverse(root);
	cout<<"\n";
	display(root);
	return 0;
}
