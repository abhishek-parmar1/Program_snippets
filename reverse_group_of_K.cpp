// reverse group of K nodes in a linked list
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
	struct node* a=NULL;
	struct node* b=NULL;
	struct node* c=l;
	struct node* t=r->next;
	r->next=NULL;
	while(c!=NULL)
	{
		b=c;
		c=c->next;
		b->next=a;
		a=b;
	}
	l->next=t;
	return(r);
}

// function to reverse K group of nodes
struct node* adjacent_node(struct  node* h,int k)
{
	if(h==NULL || h->next==NULL)
		return h;
	struct node* head=NULL;
	struct node* l=h;
	struct node* r=h;
	int i=1;
	
	while(i<k && r->next!=NULL)
	{
		r=r->next;
		i++;
	}
	if(i<k)
	{
		return h;
	}
	h=head=reverse(l,r);
	while(l->next!=NULL)
	{
		l=l->next;
		r=l;
		i=1;
		while(r->next!=NULL && i<k)
		{
			r=r->next;
			i++;
		}
		if(i<k)
		{
			return head;
		}
		while(h->next!=l)
		{
			h=h->next;
		}
		h->next=reverse(l,r);
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
	root=adjacent_node(root,3);
	display(root);
	return 0;
}
