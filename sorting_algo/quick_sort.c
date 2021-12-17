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

int partition(int a[], int low, int high) 
{
	int pivot = a[high];
	int i = (low - 1);
	
	for(int j = low; j <= high - 1; j++) 
	{
		if(a[j] <= pivot) 
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[high]);
	return i + 1;
}

void quick_sort(int a[], int low, int high)  
{
	if(low < high) 
	{
		int pi = partition(a, low, high);
		
		quick_sort(a, low, pi - 1);
		quick_sort(a, pi + 1, high);
	}
}


int main() {
	
	quick_sort(a, 0, length - 1);
	print(a);
	
	return 0;
}
