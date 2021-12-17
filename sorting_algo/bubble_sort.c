#include<stdio.h>
#define length 10

int a[] = {5,8,2,3,1,7,6,9,10,4};

void swap(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int a[]) 
{
	for(int i = 0; i < length - 1; i++) 
	{
		for(int j = i + 1; j < length; j++) 
		{
			if(a[i] > a[j]) 
			{
				swap(&a[i], &a[j]);
			}
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
	bubble_sort(a);
	printf("\n");
	print(a);
	return 0;
}
