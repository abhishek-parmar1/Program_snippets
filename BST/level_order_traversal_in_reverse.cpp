// wap to print the level  order traversal of tree in reverse order using 1 queues and 1 stack
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>

using namespace std;

//queue
queue<struct node*> q1;
//stack
stack<int> s1;

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
	while(!q1.empty())
	{
		root=q1.front();
		q1.pop();
		s1.push(root->data);
		if(root->right!=NULL)
			q1.push(root->right);
		if(root->left!=NULL)
			q1.push(root->left);
	}
	
	while(!s1.empty())
	{
		cout<<s1.top()<<" ";
		s1.pop();	
	}	
}

// main function
int main()
{
	struct node* root=NULL;
	root=add_node(root,10);
	root->left=add_node(NULL,20);
	root->right=add_node(NULL,30);
	root->left->left=add_node(NULL,40);
	root->left->right=add_node(NULL,50);
	root->right->right=add_node(NULL,60);
	root->left->right->left=add_node(NULL,70);
	root->left->right->right=add_node(NULL,80);
	root->right->right->left=add_node(NULL,90);
	display(root);
	cout<<"\n";
	level_order(root);
}
