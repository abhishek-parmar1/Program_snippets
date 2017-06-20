// wap to print the inorder traversal using itterative method 
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

//display tree inorder recursively
void display(struct node* root)
{
	if(root==NULL)
	return;
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}

// display the inorder itteratively
void in_order(struct node* root)
{
	if(root==NULL)
		return;
	
	while(true)
	{
		if(root!=NULL)
		{
			s1.push(root);
			root=root->left;
		}
		else
		{
			if(s1.empty())
				break;
			root=s1.top();
			s1.pop();
			cout<<root->data<<" ";
			root=root->right;	
		}	
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
	in_order(root);
	return 0;
}
