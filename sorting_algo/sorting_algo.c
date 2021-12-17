#include<stdio.h>
#define length_a 10

int a[] = {5,8,2,3,1,7,6,9,10,4};

void swap(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int a[]) 
{
	for(int i = 0; i < length_a; i++)
		printf("%d ", a[i]);
}

void bubble_sort(int a[]) 
{
	for(int i = 0; i < length_a; i++) 
	{
		for(int j = 0; j < length_a - 1; j++)
		 {
			if(a[i] < a[j])
			 {
				swap(&a[i], &a[j]);
			}
		}
	}	
}
 
void selection_sort(int a[]) 
{
	for(int i = 0; i < length_a; i++) 
	{
		int temp_idx = i;
		for(int j = i + 1; j < length_a; j++) 
		{ // tim gia tri nho nhat trong mang
			if(a[temp_idx] < a[j]) 
			{ 
				temp_idx = j; // index cua gia tri nho nhat trong mang
			}	
		}
		if(temp_idx != i) 
		{ // doi cho cho phan tu dung dau va phan tu be nhat trong mang
			swap(&a[temp_idx], &a[i]);
		}
	}
}

void insertion_sort(int a[]) 
{
	for(int i = 1; i < length_a; i++)
	{
		int key = a[i];
		int pos = i - 1; // behind index
		while(pos >= 0 && key < a[pos]) 
		{
			a[pos + 1] = a[pos];
			--pos;
		}
		a[pos + 1] = key;
	}
}

void quickSort();
void heapSort();


int main() 
{

	printf("Sorting Algo\n");
	printf("Array was inited : ");
	print_array(a);
	printf("\nArray was sorted : ");
	
//	bubble_sort(a);
//	selection_sort(a);
//	insertion_sort(a);
	print_array(a);
	return 0;
}
