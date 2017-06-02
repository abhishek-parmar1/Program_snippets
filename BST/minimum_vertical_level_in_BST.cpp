// wap  to find the minimum vertical level in a BST
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

// find the minimum vertical level in BST
int min_vertical_level(struct node* root,int level)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return level;
	int l1=level,l2=level;
	if(root->left!=NULL)
		l1=min_vertical_level(root->left,level-1);
	if(root->right!=NULL)
		l2=min_vertical_level(root->right,level+1);
	return l1<l2?l1:l2;
}

// main function
int main()
{
	int  a[]={9,3,17,6,5,4};
	int n=6;
	struct node* root=NULL;
	root=create_BST(root,a,n);
	display(root);
	cout<<"\n"<<min_vertical_level(root,0);
}
