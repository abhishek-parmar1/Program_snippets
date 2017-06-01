// wap  to reverse an array 
#include<stdio.h>

//recursively
void reverse_recursion(int* a,int n)
{
	if(n==0 || n==1)
	return;
	int temp=a[0];
	a[0]=a[n-1];
	a[n-1]=temp;
	reverse_recursion(a+1,n-2);
}

//itteratively
void reverse_itteratively(int* a,int n)
{
	if(n==0 || n==1)
	return;
	int i;
	for(i=0;i<n/2;i++)
	{
		int temp=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=temp;
	}
}

//  print array
void print(int *a ,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}

int main()
{
	int  a[]={1,2,3,4,5};
	int  n=5;
	print(a,n);
	printf("\n");
	reverse_recursion(a,n);
	print(a,n);
	printf("\n");
	reverse_itteratively(a,n);
	print(a,n);
	return 0;
}
