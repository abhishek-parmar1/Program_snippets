// wap  to find the lowest commmon ancestor in Bst for two points
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

// function for lowest common ancestor in BST
int lowest_common_ancestor(struct node* root,int l,int r)
{
	if(root==NULL)
		return 0;
	if(root->data>l && root->data>r && root->left!=NULL)
		return lowest_common_ancestor(root->left,l,r);
	if(root->data<r && root->data<l && root->right!=NULL)
		return lowest_common_ancestor(root->right,l,r);
	else 
		return root->data;
	// donot ckeck for range between left and right because input can be reversed also 
	// like it can be 1,11 or 11,1 
}

// main function
int main()
{
	int  a[11]={9,3,5,1,8,12,16,11,2,4,6};
	int n=11;
	struct node* root=NULL;
	root=create_BST(root,a,n);
	display(root);
	cout<<"\n"<<lowest_common_ancestor(root,11,1);
}
