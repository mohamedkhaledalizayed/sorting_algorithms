#include "sort.h"

/**
 * counting_sort - impleminting counting_sort algorithm
 *
 * @array: array of ints
 * @size: size of array
 * Return: Always 0 (Success)
 */
void counting_sort(int *array, size_t size)
{
	size_t i = 0;
	int k;

	if (!array || size < 2)
		return;
	k = array[i];
	for (; i < size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}
	k++;
	counting(array, size, k);
}
/**
 * counting - actually impleminting of counting_sort algorithm
 *
 * @array: array of ints
 * @size: size of array
 * @k: size 0f count_array
 * Return: Always 0 (Success)
 */

void counting(int *array, size_t size, int k)
{
	size_t i;
	int x;
	int *count_arr = (int *)malloc(k * sizeof(int));
	int *sort_arr = (int *)malloc(size * sizeof(int));


	for (i = 0; i < size; i++)
	{
		count_arr[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		x = array[i];
		count_arr[x]++;
	}
	for (x = 1; x < k; x++)
	{
		count_arr[x] = count_arr[x] + count_arr[x - 1];
	}

	print_array(count_arr, k);
	for (x = size - 1; x >= 0; x--)
	{
		sort_arr[--count_arr[array[x]]] = array[x];
	}

	for (i = 0; i < size; i++)
	{
		array[i] = sort_arr[i];
	}
	free(count_arr);
	free(sort_arr);

}
