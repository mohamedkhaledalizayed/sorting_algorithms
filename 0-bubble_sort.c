#include "sort.h"

/**
* bubble_sort - impleminting bubble sort algorithm
*
* @array: array of ints
* @size: size of array
* Return: Always 0 (Success)
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int x;

	for (i = 0; (i < size) && array; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;

			print_array(array, size);
			}

		}
	}
}

