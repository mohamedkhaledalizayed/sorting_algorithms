#include "sort.h"

/**
 * radix_sort - impleminting radix_sort algorithm
 *
 * @array: array of ints
 * @size: size of array
 * Return: Always 0 (Success)
 */
void radix_sort(int *array, size_t size)
{
	size_t i = 0;
	int k, per;

	if (!array || size < 2)
		return;
	k = array[i];
	for (; i < size; i++)
	{
		if (array[i + 1] > k)
		{
			k = array[i + 1];
		}
	}
	for (per = 1; (k / per) > 0; per *= 10)
	{
		radix(array, size, per, k);
	}
}
/**
 * radix - actually impleminting of counting_sort algorithm
 *
 * @array: array of ints
 * @size: size of array
 * @per: period 0f impleminting
 * @k: size
 * Return: Always 0 (Success)
 */
void radix(int *array, size_t size, int per, int k)
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
		x = (array[i] / per) % 10;
		++count_arr[x];
	}
	for (x = 1; x < k; x++)
	{
		count_arr[x] = count_arr[x] + count_arr[x - 1];
	}

	for (x = size - 1; x >= 0; x--)
	{
		sort_arr[--count_arr[(array[x] / per) % 10]] = array[x];
	}

	for (i = 0; i < size; i++)
	{
		array[i] = sort_arr[i];
	}
	print_array(array, size);
	free(count_arr);
	free(sort_arr);
}
