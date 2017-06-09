#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void update_segment_array(int * segment_array,int start,int end,int index,int diff,int pos)
{
	if (index < start || index > end)
        return;
    
	segment_array[pos]+=diff;
	
	if(start!=end)
	{
		int mid=start+((end-start)/2);
		update_segment_array(segment_array,start,mid,index,diff,2*pos+1);
		update_segment_array(segment_array,mid+1,end,index,diff,2*pos+2);
	}    
}

void update_input_array(int * segment_array,int * input_array,int n,int index,int new_val)
{
	if (index < 0 || index > n-1)
    {
        printf("Invalid Input");
        return;
    }
    
    int diff=new_val-input_array[index];
    input_array[index]=new_val;
    
    update_segment_array(segment_array,0,n-1,index,diff,0);
}

int search(int * segment_array,int l_query,int r_query,int start,int end,int pos)
{
	// if the range of the input query is enclosing or equal to the range of that position in segment array, then 
	// return that position value in segment array
	if(l_query<=start && r_query>=end)
	{
		return segment_array[pos];
	}
	
	// if the range of the position on segment array is out of bound of input query range, then return 0
	if(start>r_query || end<l_query)
		return 0;
		
	// else pass the input query range to left and right child of the current position	
	int mid=start+((end-start)/2);
    return search(segment_array, l_query, r_query, start, mid, 2*pos+1) +
           search(segment_array, l_query, r_query, mid+1, end, 2*pos+2);	
	
}

int build_tree(int * input_array,int start,int end,int* segment_array,int pos)
{
	if(start==end)
	{
		segment_array[pos]=input_array[start];
		return input_array[start];
	}
	
	int mid=start+((end-start)/2);
	segment_array[pos]=build_tree(input_array,start,mid,segment_array,2*pos+1) + build_tree(input_array,mid+1,end,segment_array,2*pos+2);
	return segment_array[pos];
}

int main()
{
	int input_array[6]={1,3,5,7,9,11};
	int n=6;
	
	// height of segment tree
	int h=(int)(ceil(log2(n)));
	
	// size of segment array
	int size=2*(int)pow(2,h)-1;
	
	int *segment_array=(int *)malloc(sizeof(int)*size);
	
	for(int i=0;i<size;i++)
	segment_array[i]=0;
	
	// build segment tree
	build_tree(input_array,0,n-1,segment_array,0);
	
	cout<<search(segment_array,1,4,0,n-1,0)<<"\n";
	
	update_input_array(segment_array,input_array,n,1,2);
	
	cout<<search(segment_array,1,4,0,n-1,0);
	return 0;
}

