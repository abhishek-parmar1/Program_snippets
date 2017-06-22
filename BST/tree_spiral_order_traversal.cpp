// wap to print the spiral order traversal of tree using 2 stacks
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;

//queue
stack<struct node*> s1;
stack<struct node*> s2;

// node structure
struct node{
	int data;
	struct node* left;
	struct node* right;
};

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

//print spiral order
void spiral_order(struct node* root)
{
	if(root==NULL)
		return;
	
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			root=s1.top();
			s1.pop();
			cout<<root->data<<" ";
			if(root->left!=NULL)
				s2.push(root->left);
			if(root->right!=NULL)
				s2.push(root->right);
		}
		
		while(!s2.empty())
		{
			root=s2.top();
			s2.pop();
			cout<<root->data<<" ";
			if(root->right!=NULL)
				s1.push(root->right);
			if(root->left!=NULL)
				s1.push(root->left);
		}
	}	
}

// main function
int main()
{
	struct node* root=NULL;
	root=add_node(root,1);
	root->left=add_node(NULL,2);
	root->right=add_node(NULL,3);
	root->left->left=add_node(NULL,4);
	root->left->right=add_node(NULL,5);
	root->right->left=add_node(NULL,6);
	root->right->right=add_node(NULL,7);
	root->left->left->left=add_node(NULL,8);
	root->left->right->left=add_node(NULL,9);
	root->right->right->right=add_node(NULL,10);
	display(root);
	cout<<"\n";
	spiral_order(root);
}
