#include<stdio.h>
#define length 10

int a[] = {5,8,2,3,1,7,6,9,10,4};
int n = length;

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

void heapify(int a[], int n, int i) 
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if(l < n && a[l] > a[largest]) 
	{
		largest = l;
	}
	
	if(r < n && a[r] > a[largest])
	{
		largest = r;
	}
	
	if(largest != i)
	{
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}

void heap_sort(int a[], int n) 
{
	for(int i = n/2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	
	for(int i = n - 1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		heapify(a, i, 0);
	}
}

int main() 
{
	heap_sort(a, n);
	print(a);
	return 0;
}

