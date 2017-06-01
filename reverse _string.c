// wap to reverse the  words in a given string
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

// function to reverse the  givven string
void word(char *ch,int l,int r)
{
	while(l<r)
	{
		char temp=ch[l];
		ch[l]=ch[r];
		ch[r]=temp;
		l++;
		r--;
	}
}

// function to select the words int the string
void reverse(char *ch,int n)
{
	word(ch,0,n-1);	
	printf("\n reversed string : ");
	puts(ch);
	
	int l=0,r=0,i=0;
	for(i=0;i<n;i++)
	{
		if(ch[i]!=' ')
		{
			l=r=i;
			while(ch[r]!=' ')
				r++;
			--r;
			word(ch,l,r);
			i=r+1;
		}
	}	
}

// main function
int main()
{
	char ch[30]="  hey  watts     up";
	
	printf("\n entered string : ");
	puts(ch);
	
	reverse(ch,strlen(ch));
	
	printf("\n final output : ");
	puts(ch);
	
	return 0;	
}

