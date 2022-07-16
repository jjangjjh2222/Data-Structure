#include "array_sort.h"
#include <stdlib.h>
#include <stdbool.h>


void init_array(Array* array)
{
	array->len = 0;
}

bool is_empty(Array* array)
{
	if (array->len == 0)
		return true;
	return false;
}

bool is_full(Array* array)
{
	if (array->len == MAX_ARRAY_SIZE)
		return true;
	return false;
}

void print_array(Array* array)
{
	if (!is_empty(array))
	{
		for (int i = 0; i < array->len; i++)
			printf("%d -> ", array->array[i]);

		printf("\n");
	}
}

/*
* return 0	: success
* return -1	: fail
*/
int insert_array(Array* array, int data)
{
	if (!is_full(array))
	{
		array->array[array->len] = data;
		array->len++;
		return 0;
	}
	return -1;
}


//-----------------------------------------------------------
// If you need a another function, write it here.

// #define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환

void SWAP(int *a, int *b)
{
    int t = *a;
	*a = *b;
	*b = t;
}

void recursion_quick_sort(Array* array, int L, int R) {
	int left = L, right = R;
	if (left >= right) {
		return;
	}

	int pivot = left;
	int i = left + 1;
	int j = right;

	while (i <= j) {
		while (array->array[i] <= array->array[pivot])
			i++;
		while (array->array[j] >= array->array[pivot] && j > left)
			j--;

		if(i>j)
			SWAP(&array->array[j], &array->array[pivot]);
		else
			SWAP(&array->array[i], &array->array[j]);
	}
	recursion_quick_sort(array, left, j-1);
	recursion_quick_sort(array, j+1, right);
}

//-----------------------------------------------------------


/*
* -----------------------------------------------------------------------------------
* Sorting Algorithm
* -----------------------------------------------------------------------------------
*/

void sequence_sort(Array* array)
{
	if(!is_empty(array)) {
		int i, j;
		
		for (i = 0; i<array->len; i++)
		{
			for (j = i; j<array->len; j++)
			{
				if (array->array[i]>array->array[j])//앞쪽 원소가 더 크면
				{	
					SWAP(&array->array[i], &array->array[j]);//교환
				}
			}
		}
	}

}

void selection_sort(Array* array)
{	
	if(!is_empty(array)) {
	int i, j;

    for (i = 0; i<array->len; i++)
    {
		int min = i;
        for (j = i+1; j<array->len; j++)
        {
            if (array->array[min]>array->array[j])
            {	 
				min = j;
            }
        }
		SWAP(&array->array[i], &array->array[min]);//교환
    }
	}
}

void insertion_sort(Array* array)
{
	if(!is_empty(array)) {
	int i, j, key;
	
    for (i = 1; i<array->len; i++)
    {
		key = array->array[i];
        for (j = i-1; j>=0 && array->array[j]>key; j--)
        {
            array->array[j+1] = array->array[j];
        }
		array->array[j+1] = key;
    }
	}

}

void bubble_sort(Array* array)
{
	if(!is_empty(array)) {
	int i, j;
    for (i = 0; i<array->len; i++)
    {
        for (j = 0; j<array->len-1; j++)
        {
            if (array->array[j] > array->array[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
            {                                 // 큰 값을
                int t = array->array[j];
                array->array[j] = array->array[j + 1];
                array->array[j + 1] = t;            // 다음 요소로 보냄
            }
        }
    }
	}
}

void quick_sort(Array* array)
{
	if(!is_empty(array)) {
	int left = 0, right = array->len-1;
	if (left >= right) {
		return;
	}

	int pivot = left;
	int i = left + 1;
	int j = right;

	while (i <= j) {
		while (array->array[i] <= array->array[pivot])
			i++;
		while (array->array[j] >= array->array[pivot] && j > left)
			j--;

		if(i>j)
			SWAP(&array->array[j], &array->array[pivot]);
		else
			SWAP(&array->array[i], &array->array[j]);
	}
	recursion_quick_sort(array, left, j-1);
	recursion_quick_sort(array, j+1, right);
	}
}