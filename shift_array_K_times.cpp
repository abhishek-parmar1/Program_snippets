// WAP to  shift an array K times
#include<iostream>
#include<stdio.h>
using namespace std;

// reverse the array 
void reverse(int *a,int i,int j)
{
	while(i<j)
	{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}
}

// to shift the array
void shift_array(int  *a ,int k,int  n)
{
	reverse(a,0,k-1);
	reverse(a,k,n-1);
	reverse(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}

// main function
int main()
{
	int  a[10]={0,1,2,3,4,5,6,7,8,9};
	int k=15;
	int n=10;
	k=k%n;
	shift_array(a,k,n);
}
