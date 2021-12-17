#include<stdio.h>
#define length 10

int a[] = {5,8,2,3,1,7,6,9,10,4};

void swap(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int a[])
{
	for(int i = 0; i < length; i++) 
	{
		printf("%d ", a[i]);
	}
}

void insertion_sort(int a[]) 
{
	for(int i = 1; i < length; i++) 
	{
		int key = a[i]; // value compare to each value of pos
		int pos = i - 1;
		while(pos >= 0 && key < a[pos]) 
		{
			a[pos + 1] = a[pos];
			--pos;
		}
		a[pos + 1] = key;
	}
}

int main() 
{
	print(a);
	insertion_sort(a);
	printf("\n");
	print(a);
	return 0;	
}
