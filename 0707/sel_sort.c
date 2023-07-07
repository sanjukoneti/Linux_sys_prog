#include<stdio.h>

void swap(int a[],int m ,int n)
{
	int temp;
	temp=a[m];
	a[m]=a[n];
	a[n]=temp;
}


void sel_sort(int a[] ,int size)
{

  int i ,j ,minindex;
  for(i=0 ;i <size-1 ;i++)
  {
	  minindex=i;
	  j=i+1;
	for(;j <size ;j++)
	{
		if(a[minindex] > a[j])
		{
			minindex=j;
		}

	}

		printf("%d",j);
	if(minindex !=i)
	swap(a,minindex,i);
  }


}

void print_array(int a[],int size)
{
for(int i=0 ; i<size ;i++)
        {
                printf("%d\n",a[i]);
        }

}

int main()
{
	int a[]={18,23,3,14,9,98,2};
	int size=sizeof(a) / sizeof(a[0]);

	sel_sort(a,size);
	print_array(a,size);
return 0;
}
