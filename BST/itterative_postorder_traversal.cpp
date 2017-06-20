// wap to print the postorder traversal using itterative method (using 2 stacks)
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
stack<int> s2;

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

// display the postorder itteratively
void post_order(struct node* root)
{
	if(root==NULL)
		return;
	
	s1.push(root);
	while(!s1.empty())
	{
		root=s1.top();
		s1.pop();
		s2.push(root->data);
		if(root->left!=NULL)
			s1.push(root->left);
		if(root->right!=NULL)
			s1.push(root->right);
	}
	
	while(!s2.empty())
	{
		cout<<s2.top()<<" ";
		s2.pop();	
	}
}

//main function
int main()
{
	struct node * root=NULL;
	root=add_node(root,1);
	root->left=add_node(NULL,-1);
	root->right=add_node(NULL,11);
	root->left->left=add_node(NULL,-2);
	root->left->right=add_node(NULL,-3);
	root->right->left=add_node(NULL,21);
	root->right->right=add_node(NULL,6);
	root->left->right->right=add_node(NULL,5);
	display(root);
	cout<<"\n";
	post_order(root);
	return 0;
}
