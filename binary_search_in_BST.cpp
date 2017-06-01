// WAP to serach in a BST in tree recursively
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

// structure of node
struct node{
	struct node* left;
	struct node* right;
	int data;
};

// create the BST tree
struct node* create_BST(struct node* root,int x)
{
	if(root==NULL)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	else
	{
		if(root->data>x)
		{
			root->left=create_BST(root->left,x);
			return root;
		}
		else
		{
			root->right=create_BST(root->right,x);
			return root;	
		}	
	}
}

//display tree in preorder
void display(struct node* root)
{
	if(root==NULL)
	return;
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}

// binary serach in BST recursively
int binary_search(struct node* root,int x)
{
	if(root==NULL)
		return 0;
	if(root->data==x)
		return 1;
	else if(root->data>x)
		binary_search(root->left,x);
	else if(root->data<x)
		binary_search(root->right,x);
	else
		return 0;
}

// main function
int main()
{
	struct node* root=NULL;
	root=create_BST(root,3);
	root=create_BST(root,2);
	root=create_BST(root,1);
	root=create_BST(root,4);
	root=create_BST(root,5);
	root=create_BST(root,6);
	root=create_BST(root,7);
	display(root);
	cout<<"\n";
	cout<<binary_search(root,5);
	return 0;	
}
