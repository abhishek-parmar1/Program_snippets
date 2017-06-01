// wap to find the factorial of number recursively and itterativelly
#include<stdio.h>

//recursively
int factorial(int  n)
{
if (n==0 || n==1)
	return 1;
else
	return (n*factorial(n-1));	
}

//itteratively
int fact(int n)
{
	int f=1,i;
	if(n==0 || n==1)
		return 1;
	for(i=1;i<=n;i++)
		f*=i;
	return f;
}
int main()
{
	printf("%d\n",fact(5));
	printf("%d",factorial(5));
	return 0;
}
