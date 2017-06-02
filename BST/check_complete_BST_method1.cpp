// wap  to check a BST is complete binary tree or not
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

// height of BST
int height(struct node* root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	int x=0,y=0;
	if(root->left!=NULL)
	{
		x=height(root->left);
	}
	if(root->right!=NULL)
	{
		y=height(root->right);
	}
	if(x>y)
		return x+1;
	else
		return y+1;
}

// count nodes in BST
int count_nodes(struct node* root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	int x=0,y=0;
	if(root->left!=NULL)
	{
		x=count_nodes(root->left);
	}
	if(root->right!=NULL)
	{
		y=count_nodes(root->right);
	}
	return x+y+1;
}

// to check a BST is complete binary tree or not
bool check_complete_BST(struct  node* root)
{
	if(root==NULL)
	return false;
	if(count_nodes(root)+1==pow(2,height(root)))
		return true;
	else
		return false;	
}

// main function
int main()
{
	int  a[]={9,5,11,1,6,10,12};
	int n=7;
	struct node* root=NULL;
	root=create_BST(root,a,n);
	display(root);
	cout<<"\n"<<check_complete_BST(root);
}
