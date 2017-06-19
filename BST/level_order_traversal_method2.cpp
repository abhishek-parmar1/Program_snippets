// wap to print the level  order traversal of tree using queue
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

//queue
queue<struct node*> q;

// node structure
struct node{
	int data;
	struct node* left;
	struct node* right;
};

// add node to BST
struct node* add_node( struct  node* root,int data)
{
	if(root==NULL)
	{
		struct node * temp=(struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	else if(root->data>data)
	{
		root->left=add_node(root->left,data);
		return root;
	}
	else
	{
		root->right=add_node(root->right,data);
		return root;
	}
}

// create BST
struct node* create_BST(int *a,int n)
{
	struct node* root=NULL;
	for(int i=0;i<n;i++)
		root=add_node(root,a[i]);
	return root;
}

// display inorder  of BST
void display(struct node* root)
{
	if(root==NULL)
		return;
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}

//print level order
void level_order(struct node* root)
{
	if(root==NULL)
		return;
		
	q.push(root);
	while(!q.empty())
	{
		root=q.front();
		q.pop();
		cout<<root->data<<" ";
		if(root->left!=NULL)
		{
			q.push(root->left);
		}
		if(root->right!=NULL)
		{
			q.push(root->right);
		}
	}
}

// main function
int main()
{
	int a[]={8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	int n=15;
	struct node* root=NULL;
	root=create_BST(a,n);
	display(root);
	cout<<"\n";
	level_order(root);
}
