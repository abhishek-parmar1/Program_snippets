// create a binary serach tree and add a node to it and delete a node from it
#include<stdio.h>

// structure of BST
struct node{
	int  data;
	struct node* left;
	struct node* right;
};

// add a node to BST
struct node* add_node(struct node* root, int n)
{
	struct node* temp=NULL;
	if(root==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=n;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	else
	{
		if((root->data)>n)
		{
			root->left=add_node(root->left,n);
			return root;
		}
		else
		{
			root->right=add_node(root->right,n);
			return root;
		}
	}
}

// create a BST
struct node* create_tree(int a[],int n)
{
	int i;
	struct node* root=NULL;
	for(i=0;i<n;i++)
	{
		root=add_node(root,a[i]);
	}
	return root;
}

// find maximum from let sub tree
int maximum_from_left_subtree(struct node* root)
{
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return(root->data);
}

//delete from BST
struct node* delete_node(struct node* root,int n)
{
	if(root==NULL)
	return NULL;
	if(root->data==n)
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left==NULL && root->right!=NULL)
		{
			struct node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->left!=NULL && root->right==NULL)
		{
			struct node* temp=root->left;
			free(root);
			return temp;
		}
		else
		{
			int max= maximum_from_left_subtree(root->left);
			root->data=max;
			root->left=delete_node(root->left,max);
			return root;
		}
	}
	else
	{
		if((root->data)>n)
		{
			root->left=delete_node(root->left,n);
			return root;
		}
		else
		{
			root->right=delete_node(root->right,n);
			return root;
		}
	}
}

// display the tree in postorder
void display(struct node* root)
{
	if(root==NULL)
	return;
	display(root->left);
	printf("%d ",root->data);
	display(root->right);
}

int main()
{
	struct node* root=NULL;
	int  a[8]={9,17,8,6,5,3,2,0};      // create array to be inserted
	int n=8;
	root=create_tree(a,n);             // create tree
	display(root);                     // display tree
	printf("\n");
	root=add_node(root,19);            // add node to tree
	display(root);                     // display tree
	printf("\n");
	root=delete_node(root,9);          // delete from tree
	display(root);                     // display tree
	return 0;
}
