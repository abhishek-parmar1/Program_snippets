// shift a 2D array 90 degree 
#include <stdio.h>

// for transpose of the array using recursion
void transpose(int s,int n,int a[n][n])
{
    if(s==n-1)
    return;
    
    int i,j;
    for(i=s;i<n;i++)
    {
        for(j=s;j<n;j++)
        {
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
        break;
    }
    transpose(s+1,n,a);
}

//for mirror image of the array
void mirror(int n,int a[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n/2;j++)
        {
            int temp=a[i][j];
            a[i][j]=a[i][n-1-j];
            a[i][n-1-j]=temp;
        }
    }
}
//main function
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    transpose(0,n,a);
    mirror(n,a);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

