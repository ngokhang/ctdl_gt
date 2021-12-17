#include<stdio.h>
#define length 10

int a[] = {5,8,2,3,1,7,6,9,10,4};

void swap(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int a[])
{
	for(int i = 0; i < length; i++) 
	{
		int index_min = i;
		
		for(int j = i + 1; j < length; j++)
		{
			if(a[index_min] > a[j]) 
			{
				index_min = j;
			}
		}
		
		if(index_min != i) 
		{
			swap(&a[index_min], &a[i]);
		}
	}
}

void print(int a[]) 
{
	for(int i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
	}
}

int main() 
{
	print(a);
	selection_sort(a);
	printf("\n");
	print(a);
	return 0;
}
