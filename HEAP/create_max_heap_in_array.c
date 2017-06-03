// wap to create the max heap both itteratively and recursively 
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

// make the subtree a max heap
void heapify(int *a,int i,int n)
{
	if(i>=n)
	return;
	if( ((2*i+1)<n && a[i]<a[2*i+1]) || ((2*i+2)<n && a[i]<a[2*i+2]))
	{
		int index=max(a,2*i+1,2*i+2,n);
		if(index==2*i+1)
		{
			int temp=a[i];
			a[i]=a[2*i+1];
			a[2*i+1]=temp;
			heapify(a,2*i+1,n);
		}
		if(index==2*i+2)
		{
			int temp=a[i];
			a[i]=a[2*i+2];
			a[2*i+2]=temp;
			heapify(a,2*i+2,n);
		}
	}
	else
	{
		return;
	}
}

// create max heap recursively
void create_max_heap(int * a, int n)
{
	int i;
	for(i=(n/2)-1;i>=0;i--)
	{
		heapify(a,i,n);
	}	
}

// create max heap itteratively
/*int * create_max_heap(int * a, int n)
{
	int i,j;
	int *b = (int*)malloc(sizeof(int)*n);
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
}*/

int main()
{
	int n,i;
	n=7;
	int a[]={2,5,3,6,1,0,10};	
	create_max_heap(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

