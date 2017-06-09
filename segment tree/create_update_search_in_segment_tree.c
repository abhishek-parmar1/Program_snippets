// wap to create the segment tree and update the sum in the segment tree and search the sum in the segment tree 
#include<stdio.h>
#include<math.h>

// structure of  segment tree
struct node
{
	int data,l_limit,r_limit;
	struct node* left;
	struct node* right;
};

// calculate the  sum of given range
int array_range_sum(int *a,int l,int r)
{
	int i,sum=0;
	for(i=l;i<=r;i++)
	{
		sum+=a[i];
	}
	return sum;
}

// insert node in segemnt tree
struct node* add_node_tree(struct node* root,int *a,int l ,int r)
{
struct node* temp=NULL;
	if(root==NULL)
	{
		int sum=array_range_sum(a,l,r);  
		temp=(struct node *)malloc(sizeof(struct node));
		temp->left=NULL;
		temp->right=NULL;
		temp->data=sum;
		temp->l_limit=l;
		temp->r_limit=r;
		
	}
	return temp;
}

// create segment tree
struct node* create_segment_tree(struct node* root,int *a,int l,int r)
{
	if(l<r)
	{
		root=add_node_tree(root,a,l,r);
		root->left=create_segment_tree(root->left,a,l,(l+r)/2);
		root->right=create_segment_tree(root->right,a,((l+r)/2)+1,r);
	}
	if(l==r)
	{
		root=add_node_tree(root,a,l,r);
	}
	return root;
}

// display in  preorder
void display(struct node* root)
{
	if(root==NULL)
	return;
	printf("%d ",root->data);
	display(root->left);
	display(root->right);
}

// update the sum in the segment tree
void  update(struct node * root,int index,int previous,int next)
{
	if(root==NULL)
		{
			return;
		}
	else
	{
		if( index >= root->l_limit && index <= root->r_limit)
		{
			root->data-=previous;
			root->data+=next;
			if( root->left!=NULL )
				update(root->left,index,previous,next);
			if( root->right!=NULL )
				update(root->right,index,previous,next);
		}
		else
			return;	
	}
}

//search the sum in the  segment tree
int search(struct  node* root,int l,int r)
{
	int sum=0;
	if(root==NULL)
		return 0;
	else
	{
		if(l==root->l_limit && r==root->r_limit)
			return root->data;
		else if( root->left!=NULL &&  r<=(root->l_limit + root->r_limit)/2 )
		{
			sum+=search(root->left,l,r);
		}
		else if( root->right!=NULL && l>(root->l_limit + root->r_limit)/2 )
		{
			sum+=search(root->right,l,r);
		}
		else
		{
			int mid=(root->l_limit + root->r_limit)/2;
			sum+=search(root->left,l,mid);
			sum+=search(root->right,mid+1,r);
		}
	}
	return sum;
}

int main()
{
	int a[]={8,5,2,6,4,1,0,5,8};
	int l=0,r=8;
	struct  node* root=NULL;
	root=create_segment_tree(root,a,l,r);
	printf("segment tree : ");
	display(root);
	update(root,3,6,5);  // parmeters index and previous value and updated value
	printf("\n");
	printf("segment tree (updated) : ");
	display(root);
	printf("\n");
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=i;j<9;j++)
		{
			printf("%d:%d: %d \n",i,j,search(root,i,j));
		}
	}
	return 0;	
}
