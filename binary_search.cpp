// WAP to  perform binary serach on an array recursively and itteratively
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

//perform binary search recursively
int binary_search(int *a,int l,int r,int x)
{
	if(l<=r)
	{
		int mid=floor((l+r)/2);
		if(a[mid]==x)
		return mid;
		else if(a[mid]>x)
		binary_search(a,l,mid-1,x);
		else
		binary_search(a,mid+1,r,x);
	}
	else
	return -1;
}

/*
// perform binary search  itteratively
int binary_search(int *a, int n,int x)
{
	int s,e,mid;
	s=0;
	e=n-1;
	while(s<=e)
	{
		mid=floor((s+e)/2);
		if(a[mid]==x)
		return mid;
		else if(a[mid]>x)
		e=mid-1;
		else
		s=mid+1;
	}
	return -1;
}
*/
// main function
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int n=10;
	cout<<binary_search(a,0,9,11);
	//cout<<binary_search(a,n,11);
}
