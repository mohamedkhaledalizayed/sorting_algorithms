#include <stdio.h>
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

	quick_sort_recursive_h(array, 0, size - 1, size);
}

/**
 * hoare_partition - function to partition the array using Hoare scheme
 * @array: array of integers
 * @low: the lower index of the subarray
 * @high: the higher index of the subarray
 * @size: the size of the array
 * Return: the partition index
 */
size_t hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low - 1;
	size_t j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_integers(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_recursive_h - recursive function to perform quicksort
 * @array: array of integers
 * @low: the lower index of the subarray
 * @high: the higher index of the subarray
 * @size: the size of the array
 * Return: no return value
 */
void quick_sort_recursive_h(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t partition_index = hoare_partition(array, low, high, size);

		if (partition_index >= low)
			quick_sort_recursive_h(array, low, partition_index, size);

		quick_sort_recursive_h(array, partition_index + 1, high, size);
	}
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



