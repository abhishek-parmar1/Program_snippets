// fin the common number of nodes in two linked list
#include<iostream>
#include<stdlib.h>

using namespace std;

// create the structure
struct node{
	int data;
	struct node* next;
};

// display and count in the linked list
int display(struct node* root,int i)
{
	if(root==NULL)
	return i;
	cout<<root->data<<" ";
	return display(root->next,++i);
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
	struct node* root1=(struct node*)malloc(sizeof(struct node));
	struct node* root2=(struct node*)malloc(sizeof(struct node));
	root1->data=1;
	root2->data=4;
	root1->next=(struct node*)malloc(sizeof(struct node));
	root2->next=(struct node*)malloc(sizeof(struct node));
	root1->next->data=2;
	root2->next->data=3;
	root1->next->next=(struct node*)malloc(sizeof(struct node));
	root1->next->next->data=8;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	root1->next->next->next=temp;
	root2->next->next=temp;
	temp->data=5;
	temp->next=(struct node*)malloc(sizeof(struct node));
	temp->next->data=6;
	temp->next->next=(struct node*)malloc(sizeof(struct node));
	temp->next->next->data=12;
	temp->next->next->next=(struct node*)malloc(sizeof(struct node));
	temp->next->next->next->data=15;
	temp->next->next->next->next=NULL;
	int x=0,y=0,z=0;
	cout<<"number of non common nodes in 1st list :m "<<" \nno of non common nodes in 2nd list : n"<<" \nnumber of common node in both list : p \n";
	x=display(root1,0);
	cout<<"\n"<<"m+p : "<<x<<"\n";
	y=display(root2,0);
	cout<<"\n"<<"n+p : "<<y<<"\n";
	root1=reverse(root1);
	z=display(root2,0);
	cout<<"\n"<<"m+n+1 : "<<z<<"\n";
	root1=reverse(root1);
	return 0;
}
