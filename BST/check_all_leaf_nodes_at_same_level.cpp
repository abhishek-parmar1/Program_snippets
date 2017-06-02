// wap  to check in a BST all the leaf nodes at the same level or not
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

// check all the leaf nodes at same level or not
int same_level(struct node *root,int level)
{
	if(root==NULL)
	 	return -1;
	if(root->left==NULL && root->right==NULL)
		return level+1;
	if(root->left!=NULL && root->right!=NULL && root->left->left==NULL && root->left->right==NULL && root->right->left==NULL && root->right->right==NULL)
		return level+1;
	int x=same_level(root->left,level+1);
	int y=same_level(root->right,level+1);
	if(x==y && x!=0)
		return level+1;
	else
		return 0;	
}

// main function
int main()
{
	int  a[]={8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	int n=15;
	struct node* root=NULL;
	root=create_BST(root,a,n);
	display(root);
	cout<<"\n";
	if(same_level(root,0)>0)
	{
		cout<<"TRUE";
	}
	else
	{
		cout<<"FALSE";
	}
}
