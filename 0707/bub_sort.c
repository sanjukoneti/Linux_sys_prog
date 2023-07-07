#include<stdio.h>

//void  bub_sort(int* ,int);
void swap(int a1[] ,int  m ,int n)
{
	int temp;
	temp= a1[m];
	a1[m]=a1[n];
	a1[n]=temp;
}
void  bub_sort(int a[],int size)
{
	int i ,j ;

	for(i=0 ;i <size;i++)
	{
		for(j=0 ;j< size-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				swap(a , j ,j+1);
			}
		}
	}
}

int main()
{

	int a[]={19,5,3,24,9};
	int size= sizeof(a)/sizeof(a[0]);

	bub_sort(a,size);

	for(int i=0 ; i<size ;i++)
	{
		printf("%d\n",a[i]);
	}

	return 0;
}
