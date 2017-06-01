// wap to print an array 
#include<stdio.h>

// print array using recursion
void array_using_recursion(int *a,int n)
{
	if(n==0)
	return;
	printf("%d",a[0]);
	array_using_recursion(a+1,n-1);
}

// print array using recursion in reverse order
void array_using_recursion_reverse(int *a,int n)
{
	if(n==0)
	return;
	printf("%d",a[n-1]);
	array_using_recursion_reverse(a,n-1);
}

int main()
{
	int  a[]={1,2,3,4,5};
	int n=5;
	array_using_recursion(a,n);
	printf("\n");
	array_using_recursion_reverse(a,n);
	return 0;
}
