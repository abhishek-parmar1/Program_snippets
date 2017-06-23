// wap to print the lowest common ancestor in binary tree
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

//queue
queue<struct node*> q1;

// node structure
struct node{
	int data;
	struct node* left;
	struct node* right;
};

// add the node to tree
struct node* add_node(struct node* root,int key)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->data=key;
		root->left=NULL;
		root->right=NULL;
	}
	return root;
}

//display tree postorder recursively
void display(struct node* root)
{
	if(root==NULL)
	return;
	display(root->left);
	display(root->right);
	cout<<root->data<<" ";
}

//return lowest common ancestor
struct node* lowest_common_ancestor(struct node* root,int v1,int v2)
{
	if(root==NULL)
		return NULL;
	if(root->data==v1 || root->data==v2)
		return root;
	struct node *temp1=NULL;
	struct node *temp2=NULL;
	temp1=lowest_common_ancestor(root->left,v1,v2);
	temp2=lowest_common_ancestor(root->right,v1,v2);
	if(temp1!=NULL && temp2!=NULL)
		return root;
	if(temp1!=NULL && temp2==NULL)
		return temp1;
	if(temp2!=NULL && temp1==NULL)
		return temp2;		
	else
		return NULL;
}

// main function
int main()
{
	struct node* root=NULL;
	root=add_node(root,3);
	root->left=add_node(NULL,6);
	root->right=add_node(NULL,8);
	root->left->left=add_node(NULL,2);
	root->left->right=add_node(NULL,11);
	root->left->right->left=add_node(NULL,9);
	root->left->right->right=add_node(NULL,5);
	root->right->right=add_node(NULL,13);
	root->right->right->left=add_node(NULL,7);
	display(root);
	cout<<"\n";
	cout<<lowest_common_ancestor(root,8,11)->data<<"\n";
	cout<<lowest_common_ancestor(root,2,8)->data<<"\n";
	cout<<lowest_common_ancestor(root,2,5)->data<<"\n";
	cout<<lowest_common_ancestor(root,9,5)->data<<"\n";
	cout<<lowest_common_ancestor(root,8,7)->data<<"\n";
	cout<<lowest_common_ancestor(root,9,3)->data<<"\n";
}
