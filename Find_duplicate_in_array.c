// FIND THE DUPLICATES IN THE ARRAY
#include<stdio.h>
#include<conio.h>
// 1st method for sorted array 
/*void find_duplicates_in_sorted(int *a,int n)
{
	int temp=-1,i=0;
	for(i=0;i<n-1;i++)
	{
		if(a[i]==a[i+1]&&temp!=a[i])
		{
			printf("%d\n",a[i]);
			temp=a[i];
		}
	}
}*/

// 2nd method for sorted array
/*void find_duplicates_in_sorted(int *a,int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			printf("%d\n",a[i]);
			for(j=i+1;j<n&&a[i]==a[j];j++);
			i=j-1;	
		}
	}
}*/

// 1st method for unsorted array with no modification in original array with some more memory used
/*void find_duplicates_in_unsorted(int* a,int n)
{
	int max=0,i=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>a[max])
			max=i;
	}
	int new_a[a[max]];
	memset(new_a,0,sizeof(new_a));
	for(i=0;i<n;i++)
	{
		new_a[a[i]]++;
	}
	for(i=0;i<n;i++)
	{
		if(new_a[i]>1)
			printf("%d\n",i);
	}
}*/

// 2st method for unsorted array with modification in original array with no more memory used
/*void find_duplicates_in_unsorted(int* a,int n)
{
	int i=0,j=0,c=0;
	
	for(i=0;i<n;i++)
	{
		c=0;
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j]&&a[i]!=-999)
			{
				c=1;
				a[j]=-999;
			}
		}
		if(c==1)
		{
			printf("%d\n",a[i]);
		}
	}	
}*/

int main()
{
	int unsorted_arr[]={1,2,1,5,3,3};
	int sorted_arr[]={1,1,2,3,3,5};
	find_duplicates_in_sorted(sorted_arr,6);
	find_duplicates_in_unsorted(unsorted_arr,6);
	return 0;
}
