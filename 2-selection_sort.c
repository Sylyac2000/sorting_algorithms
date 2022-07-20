#include "sort.h"

/**
* smallest - small elemnt position
* @arr: array to sort
* @k: position
* @n: number of elements
* Return: pos
*/

int smallest(int arr[], size_t k, size_t n)
{
	int pos, small;
	size_t i;

	small = arr[k];
	pos = k;
	for (i = k + 1; i < n; i++)
	{
		if (arr[i] < small)
		{
			small = arr[i];
			pos = i;
		}
	}
	return (pos);
}

/**
* selection_sort - selection sort algorithm
* @array: array to sort
* @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	int pos, temp;
	size_t k;

	for (k = 0; k < size; k++)
	{
		pos = smallest(array, k, size);
		temp = array[k];
		array[k] = array[pos];
		array[pos] = temp;
		print_array(array, size);
	}
}
