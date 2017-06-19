// wap to check a binary tree is BST or not
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

// node structure
struct node{
	int data;
	struct node* left;
	struct node* right;
};

// add node to a tree
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

// display a tree inorder
void display(struct node* root)
{
	if(root==NULL)
	return;
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);	
}

// check tree is BST or not
bool check_BST(struct node*  root,int l,int r)
{
	if(root==NULL)
	return true;
	
	if(root->data<l || root->data>r)
		return false;
	
	else 
		return check_BST(root->left,l,root->data-1) && check_BST(root->right,root->data+1,r);
}

// main function
int main()
{
	struct node* root=NULL;
	root=add_node(root,8);
	root->left=add_node(NULL,4);
	root->right=add_node(NULL,12);
	root->left->left=add_node(NULL,2);
	root->left->right=add_node(NULL,6);
	root->right->left=add_node(NULL,10);
	root->right->right=add_node(NULL,14);
	root->left->left->left=add_node(NULL,1);
	root->left->left->right=add_node(NULL,3);
	root->left->right->left=add_node(NULL,5);
	root->left->right->right=add_node(NULL,7);
	root->right->left->left=add_node(NULL,9);
	root->right->left->right=add_node(NULL,11);
	root->right->right->left=add_node(NULL,13);
	root->right->right->right=add_node(NULL,15);
	display(root);
	cout<<"\n";
	cout<<check_BST(root,1,15);
	return 0;
}
