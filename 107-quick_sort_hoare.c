#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort_hoare - function that sorts an array using QuickSort algorithm
 * @array: array of integers
 * @size: number of elements in the array
 * Return: no return value (void)
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	partition_h(array, 0, size - 1, size);
}

/**
 * swap_integers - function to swap two integers
 * @element1: the first integer
 * @element2: the second integer
 * Return: no return value
 */
void swap_integers(int *element1, int *element2)
{
	int temp;

	temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

/**
 * partition_h - function to partition the array
 * @array: array of integers
 * @low: the lower index of the subarray
 * @high: the higher index of the subarray
 * @size: the size of the array
 * Return: the partition index
 */
void partition_h(int *array, size_t low, size_t high, size_t size)
{
	int pivot;
	size_t first_pointer, secand_pointer, pivot_index;

	if (low >= high || (high > size - 1))
		return;

	pivot_index = low;
	pivot = array[pivot_index];
	first_pointer = low + 1;
	secand_pointer = high;
	while (first_pointer < secand_pointer)
	{
		if (array[first_pointer] >= pivot)
		{
			if (array[secand_pointer] < pivot)
			{
				swap_integers(&array[secand_pointer], &array[first_pointer]);
				/* new pivot index if the pivot change the place*/
				if (first_pointer == pivot_index)
					pivot_index = secand_pointer;

				else if (secand_pointer == pivot_index)
					pivot_index = first_pointer;

				print_array(array, size);
			}
			else
				secand_pointer--;
		}
		else
			first_pointer++;

	}
	partition_h(array, low, pivot_index - 1, size);
	partition_h(array, pivot_index + 1, high, size);
}
