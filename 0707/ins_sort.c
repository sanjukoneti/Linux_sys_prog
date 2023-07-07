#include<stdio.h>

void ins_sort(int a[] ,int size)
{
	int key,i,j;
   for( i=1 ; i<size ;i++)
   {
	key=a[i];
	j=i-1;
     while( j>= 0 && a[j] > key)
     {
	     a[j+1]=a[j];
	     j=j-1;
     }
     	    a[j+1]=key;
   }
}

void print_array(int a[] ,int size)
{
	for(int i=0 ; i<size ; i++)
	{
		printf("%d \t ",a[i]);
	}
}
int main()
{
	int a[]={12,8,13,6,9};
	int size=sizeof(a)/sizeof(a[0]);
	ins_sort(a,size);
	print_array(a,size);
return 0;
}
