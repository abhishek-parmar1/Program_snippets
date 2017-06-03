// wap to add and delete a node from max heap 
#include<stdio.h>
#include<math.h>

// max function
int max(int *a, int l,int r,int n)
{
	if(l>n-1)
	return r;
	if(r>n-1)
	return l;
	else
	return a[l]<a[r]?r:l;
}

// create max heap itteratively
int * create_max_heap(int * a, int n)
{
	int i,j;
	int *b = (int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
		j=i;
		while(j>0 && ((j-1)/2)>=0 && (b[(j-1)/2] < b[j]))
		{
			int temp=b[j];
			b[j]=b[(j-1)/2];
			b[(j-1)/2]=temp;
			j=(j-1)/2;
		}
	}
	return b;
}

// add a node to the max heap
void add_node_to_max_heap(int * a,int  key ,int n)
{
	a[n]=key;
	int i=n;
	while(i>=0)
	{
		if( ((i-1)/2)>=0  &&  a[i]>a[(i-1)/2] )
		{
			int temp=a[i];
			a[i]=a[(i-1)/2];
			a[(i-1)/2]=temp;
			i=(i-1)/2;
		}
		else
		{
			break;
		}
	}
}

// delete a node from max heap
void delete_node_from_max_heap(int *a,int key,int n)
{
	int i,pos;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			pos=i;
			break;
		}
	}
	a[pos]=a[n-1];
	n--;
	i=pos;
	while(i<n)
	{
		if( ((2*i+1)<n && a[i]<a[2*i+1]) || ((2*i+2)<n && a[i]<a[2*i+2]) )
		{
			int index=max(a,2*i+1,2*i+2,n);
			if(index==2*i+1)
			{
				int temp=a[i];
				a[i]=a[2*i+1];
				a[2*i+1]=temp;
				i=2*i+1;
			}
			if(index==2*i+2)
			{
				int temp=a[i];
				a[i]=a[2*i+2];
				a[2*i+2]=temp;
				i=2*i+2;
			}
		}
		else
		{
			break;
		}
	}	
}

int main()
{
	int n,i;
	n=6;
	int a[]={3,6,4,7,2,1};	
	int *b=create_max_heap(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
	add_node_to_max_heap(b,10,n);
	printf("\n");
	for(i=0;i<n+1;i++)
	{
		printf("%d ",b[i]);
	}
	delete_node_from_max_heap(b,10,n+1);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}

