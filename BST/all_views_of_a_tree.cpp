// wap  to print all the views of a tree
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<utility>

using namespace std;

// structure of node
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef pair<int,int> v_h; 
map <int,v_h> m; //map
map <int, v_h> :: iterator itr; //itterator
map <int,int> m1; //map
map <int, int> :: iterator itr1; //itterator


// add a node to the the tree (BST)
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

// create the tree(BST)
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

// store the top view in the map
void store_top_view(struct node * root,int i,int h)
    {
    if(root==NULL)
        return;
    itr=m.find(i);
    if(itr==m.end())
        m[i]=make_pair(h,root->data);
    else
    {
        if(itr->second.first > h)
            m[i]=make_pair(h,root->data);
    }
    if(root->left!=NULL)
        store_top_view(root->left,i-1,h+1);
    if(root->right!=NULL)
        store_top_view(root->right,i+1,h+1);
     
}

// store the bottom view in the map
void store_bottom_view(struct node * root,int i,int h)
    {
    if(root==NULL)
        return;
    m[i]=make_pair(h,root->data);
    if(root->left!=NULL)
        store_bottom_view(root->left,i-1,h+1);
    if(root->right!=NULL)
        store_bottom_view(root->right,i+1,h+1);
     
}

// print the top and bottom view
void print_map()
    {
    for(itr = m.begin(); itr != m.end(); ++itr)
        cout<<itr->second.second<<" ";
    m.clear();
}

// store the left view
void store_left_view(struct node * root,int i)
{
	if(root==NULL)
		return;
	m1[i]=root->data;
	if(root->right!=NULL)
		store_left_view(root->right,i+1);
	if(root->left!=NULL)
		store_left_view(root->left,i+1);
}

// store the right view
void store_right_view(struct node * root,int i)
{
	if(root==NULL)
		return;
	m1[i]=root->data;
	if(root->left!=NULL)
		store_right_view(root->left,i+1);
	if(root->right!=NULL)
		store_right_view(root->right,i+1);
}

// print the left and right view
void print_map1()
    {
    for(itr1 = m1.begin(); itr1 != m1.end(); ++itr1)
        cout<<itr1->second<<" ";
    m1.clear();
}


// views of the map
void views(struct node * root)
{
   // for top view
   store_top_view(root,0,0);
   cout<<"top view : ";
   print_map();
   cout<<"\n";
   // for bottom view
   store_bottom_view(root,0,0);
   cout<<"bottom view : ";
   print_map();
   cout<<"\n";
   // for left view
   store_left_view(root,0);
   cout<<"left view : ";
   print_map1();
   cout<<"\n";
   // for right view
   store_right_view(root,0);
   cout<<"right view : ";
   print_map1();
}

// main function
int main()
{
	int  a[]={8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	int n=15;
	struct node* root=NULL;
	root=create_BST(root,a,n);
	display(root);
	cout<<"\n";
	views(root);
}











