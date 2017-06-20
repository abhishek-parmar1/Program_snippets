// wap to print the preorder traversal using itterative method (using 2 stacks)
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;

// structure of node
struct node{
int data;
struct node* left;
struct node* right;	
};

// stack
stack<struct node*> s1;

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

//display tree preorder recursively
void display(struct node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	display(root->left);
	display(root->right);
}

// display the preorder itteratively
void pre_order(struct node* root)
{
	if(root==NULL)
		return;
	
	s1.push(root);
	while(!s1.empty())
	{
		root=s1.top();
		s1.pop();
		cout<<root->data<<" ";
		if(root->right!=NULL)
			s1.push(root->right);
		if(root->left!=NULL)
			s1.push(root->left);
		
	}
}

//main function
int main()
{
	struct node * root=NULL;
	root=add_node(root,10);
	root->left=add_node(NULL,11);
	root->right=add_node(NULL,-20);
	root->left->left=add_node(NULL,15);
	root->left->right=add_node(NULL,12);
	root->right->left=add_node(NULL,0);
	root->right->right=add_node(NULL,9);
	root->right->left->left=add_node(NULL,16);
	root->right->left->right=add_node(NULL,18);
	display(root);
	cout<<"\n";
	pre_order(root);
	return 0;
}
