// remove duplicates from linked list recursively and itteratively
#include<iostream>
#include<stdlib.h>

using namespace std;

// create the structure
struct node{
	int data;
	struct node* next;
};

// crete the linked list or add a node to the linked list 
struct node* create_linked_list(struct node* root,int key)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->data=key;
	if(root==NULL)
	{
		return temp;	
	}
	else
	{
		struct node* head=root;
		while(head->next!=NULL)
		{
			head=head->next;
		}
		head->next=temp;
		return root;
	}
}

// displlay the linked list
void display(struct node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	display(root->next);
}

/*
// remove duplicates recursively
void remove_duplicates(struct node* root)
{
	if(root==NULL || root->next==NULL) 
		return ;
	if(root->next!=NULL && root->data==root->next->data)
	{
		struct node*temp=root->next;
		root->next=root->next->next;
		free(temp);
		remove_duplicates(root);
	}
	else
		remove_duplicates(root->next);	
}
*/

// remove duplicates itteratively
void remove_duplicates(struct node * root)
{
	if(root==NULL)
		return;
	while(root!=NULL)
	{
		if( root->next!=NULL && root->data==root->next->data)
		{
			struct node* temp=root->next;
			root->next=root->next->next;
			free(temp);
		}
		else
		root=root->next;
	}		
}

int main()
{
	struct node* root=NULL;
	root=create_linked_list(root,1);
	root=create_linked_list(root,1);
	root=create_linked_list(root,2);
	root=create_linked_list(root,3);
	root=create_linked_list(root,3);
	root=create_linked_list(root,4);
	root=create_linked_list(root,4);
	root=create_linked_list(root,4);
	root=create_linked_list(root,5);
	display(root);
	cout<<"\n";
	remove_duplicates(root);
	display(root);
	return 0;
}
