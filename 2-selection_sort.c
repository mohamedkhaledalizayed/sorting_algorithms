#include "sort.h"

/**
 * selection_sort - impleminting bubble sort algorithm
 *
 * @array: array of ints
 * @size: size of array
 * Return: Always 0 (Success)
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, select;
	int  y;

	for (i = 0; i < size; i++)
	{
		select = i;
		for (j = i + 1; j < size; j++)
		{

			if (array[j] < array[select])
			{
				select = j;


			}
		}
		if (select != i)
		{
			y = array[i];
			array[i] = array[select];
			array[select] = y;

			print_array(array, size);


		}
	}

}
