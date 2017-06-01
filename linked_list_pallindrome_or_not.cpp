// check a linked list is pallindrome or not
#include<iostream>
#include<stdlib.h>

using namespace std;

// create the structure
struct node{
	char data;
	struct node* next;
};

// crete the linked list or add a node to the linked list 
struct node* create_linked_list(struct node* root,char key)
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
		return root ;
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

// check pallindrome or not
int check_pallindrome(struct node* root)
{
	if(root==NULL || root->next==NULL)
		return 1;
	struct node* f=NULL;
	struct node* s=NULL;
	f=root;
	s=root;
	while(f->next!=NULL)
	{
		s=s->next;
		f=f->next;
		if(f->next!=NULL)
			f=f->next;
	}
	struct node* temp=reverse(s);
	s=root;
	f=temp;
	while(f!=NULL)
	{
		if(s->data==f->data)
		{
			s=s->next;
			f=f->next;
		}
		else
		{
			temp=reverse(temp);
			return 0;
		}
	}
	temp=reverse(temp);
	return 1;
}

int main()
{
	struct node* root=NULL;
	root=create_linked_list(root,'A');
	root=create_linked_list(root,'B');
	root=create_linked_list(root,'C');
	root=create_linked_list(root,'D');
	root=create_linked_list(root,'D');
	root=create_linked_list(root,'C');
	root=create_linked_list(root,'B');
	root=create_linked_list(root,'A');
	display(root);
	cout<<"\n";
	if(check_pallindrome(root))
	{
		cout<<"string is pallindrome";
	}
	else
	{
		cout<<"string not a pallindrome";
	}
	cout<<"\n";
	display(root);
	return 0;
}
