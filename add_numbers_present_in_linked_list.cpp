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

// funcyion to add the numbbers 
struct node * add_num(struct node* root1,struct node* root2)
{
	if(root1==NULL && root2==NULL)
		return root1;
	if(root1!=NULL && root2==NULL)
		return root1;
	if(root1==NULL && root2!=NULL)
		return root2;
	struct node * root3=NULL;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=(root1->data+root2->data)%10;
	int c=(root1->data+root2->data)/10;
	root1=root1->next;
	root2=root2->next;
	root3=temp;
	while(root1!=NULL || root2!=NULL)
	{
		temp->next=(struct node*)malloc(sizeof(struct node));
		temp=temp->next;
		int x=0;
		temp->next=NULL;
		if(root1!=NULL)
		{
			x+=root1->data;
			root1=root1->next;
		}
		if(root2!=NULL)
		{
			x+=root2->data;
			root2=root2->next;
		}	
		temp->data=(x+c)%10;
		c=(x+c)/10;
	}
	if(c)
	{
		temp->next=(struct node*)malloc(sizeof(struct node));
		temp=temp->next;
		temp->next=NULL;
		temp->data=c;
	}
	return root3;
}

int main()
{
	struct node* root1=NULL;
	struct node* root2=NULL;
	root1=create_linked_list(root1,9);
	root1=create_linked_list(root1,7);
	root1=create_linked_list(root1,8);
	root2=create_linked_list(root2,5);
	root2=create_linked_list(root2,6);
	cout<<"first number : ";
	display(root1);
	cout<<"\n";
	cout<<"second number : ";
	display(root2);
	cout<<"\n";
	root1=reverse(root1);
	root2=reverse(root2);
	struct node* root3=add_num(root1,root2);
	root3=reverse(root3);
	cout<<"result : ";
	display(root3);
	return 0;
}
