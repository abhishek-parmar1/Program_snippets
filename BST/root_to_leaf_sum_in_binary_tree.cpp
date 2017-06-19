// wap  to print the branch  of the tree where sum is  equal to entered key in binary tree
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

// structure of node
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

// create a node
struct node* create(struct node* root,int key)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->left=NULL;
		root->right=NULL;
		root->data=key;
	}
	return root;
}

// display in preorder
void display(struct node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	display(root->left);
	display(root->right);
}

// method1: root to leaf sum in binary tree
bool sum(struct node* root,int key)
{
	if(root==NULL)
		return false;
	if(root->data==key && root->left==NULL && root->right==NULL)
	{
		cout<<root->data<<" ";
		return true;
	}
	if(root->data!=key && root->left==NULL && root->right==NULL)
		return false;
		
	bool x=false,y=false;
	if(root->left!=NULL)
		x=sum(root->left,key-root->data);
	if(root->right!=NULL)
		y=sum(root->right,key-root->data);
	if(x||y)
	{
		cout<<root->data<<" ";
		return x||y;
	} 
	else
	 	return x||y;
}

int main()
{
	struct node* root=NULL;
	root=create(root,10);
	root->left=create(NULL,16);
	root->right=create(NULL,5);
	root->left->right=create(NULL,-3);
	root->right->left=create(NULL,6);
	root->right->right=create(NULL,11);
	display(root);
	cout<<"\n";
	sum(root,26);
	
	return 0;
}
