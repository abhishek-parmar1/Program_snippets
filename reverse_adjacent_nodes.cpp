// reverse adjacent nodes in a linked list
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
struct node* reverse(struct node* l,struct node* r)
{
	struct node* t=NULL;
	t=r->next;
	r->next=l;
	l->next=t;
	return r;
}

// function to reverse adjacent node
struct node* adjacent_node(struct  node* h)
{
	if(h==NULL || h->next==NULL)
		return h;
	struct node* head=h->next;
	struct node* l=h;
	struct node* r=h;
	
	while(l->next!=NULL)
	{
		if(r->next!=NULL)
		{
			r=r->next;
		}
		if(h!=l)
		{
			while(h->next!=l)
			{
				h=h->next;
			}
			h->next=reverse(l,r);
		}
		else
		{
			h=reverse(l,r);
		}
		if(l->next!=NULL)
		{
			l=l->next;
			r=l;
		}
	}
	
	return head;	
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
	cout<<"\n";
	root=adjacent_node(root);
	display(root);
	return 0;
}
