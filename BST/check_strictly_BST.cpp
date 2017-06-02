// wap  to check a BST is strictly binary tree or not
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

// add a node to the the BST
struct node* add_node(struct node* root,int key)
{
	if(root==NULL)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->data=key;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	else if(root->data>key)
	{
		root->left=add_node(root->left,key);
		return root;
	}
	else
	{
		root->right=add_node(root->right,key);
		return root;
	}
}

// create the BST
struct node* create_BST(struct node* root,int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		root=add_node(root,a[i]);
	}
	return root;
}

// display in inorrder
void display(struct node* root)
{
	if(root==NULL)
		return;
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}

// check a tree is  stictly BST or not
bool check_strictly_BST(struct node *root)
{
	if(root==NULL)
	 	return false;
	if(root->left==NULL && root->right==NULL)
		return true;
	if( (root->left==NULL && root->right!=NULL) || 	(root->left!=NULL && root->right==NULL) )
		return false;
	/*
	OR	
	if(root->left!=NULL && root->right!=NULL && root->left->left==NULL && root->left->right==NULL && root->right->left==NULL && root->right->right==NULL)
		return true;
	*/
	return check_strictly_BST(root->left) && check_strictly_BST(root->right);	
}

// main function
int main()
{
	int  a[]={8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	int n=15;
	struct node* root=NULL;
	root=create_BST(root,a,n);
	display(root);
	cout<<"\n"<<check_strictly_BST(root);
}
