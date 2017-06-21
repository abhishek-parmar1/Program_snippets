// wap to print the level  order traversal of tree using 1 queues and a delimiter
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

//queue
queue<struct node*> q1;

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

//print level order
void level_order(struct node* root)
{
	if(root==NULL)
		return;
	
	q1.push(root);
	q1.push(NULL);
	while(1)
	{
		if(!q1.empty())
		{
			root=q1.front();
			q1.pop();
		}
		if(root==NULL)
		{
			cout<<"\n";
			q1.push(root);	
		}
		else
		{
			cout<<root->data<<" ";
			if(root->left!=NULL)
				q1.push(root->left);
			if(root->right!=NULL)
				q1.push(root->right);
		}
		if(root==NULL && q1.front()==NULL)
			break; 
	}	
}

// main function
int main()
{
	struct node* root=NULL;
	root=add_node(root,1);
	root->left=add_node(NULL,3);
	root->right=add_node(NULL,2);
	root->left->right=add_node(NULL,6);
	root->left->right->right=add_node(NULL,8);
	root->right->left=add_node(NULL,4);
	root->right->right=add_node(NULL,5);
	root->right->left->left=add_node(NULL,9);
	root->right->left->right=add_node(NULL,10);
	display(root);
	cout<<"\n";
	level_order(root);
}
