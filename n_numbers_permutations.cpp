//  wap to print the n! permutations
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

// function to swap the values
void swap(int *a, int l, int r)
{
	int temp=a[l];
	a[l]=a[r];
	a[r]=temp;
}

// function to generate the permutations recursively
void permutate(int *a, int l, int r)
{
	//if left limit equal to right limit print the permuatation
	if(l==r)
	{
		for(int i=0; i<=r; i++)
			cout<<a[i];
		cout<<"\t";
	}
	
	// call for a for loop from l to r
	for(int i=l; i<=r; i++)
	{
		// swap every time l with r 
		swap(a,l,i);
		// call for l+1 with r
		permutate(a,l+1,r);
		// restore the original permutation after generation of sub perutations
		swap(a,l,i);
	}
}

int main()
{
	int n=4;
	int a[n];
	
	for(int i=0;i<n;i++)
		a[i]=i+1;
	
	permutate(a,0,n-1); 
	
	return 0;
}
