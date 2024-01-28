#include "sort.h"

/**
 * bubble_sort - this function sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 *
 * @array: input arrray of integers
 * @size: size of the array
 *
 * Return: no return
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int temp, swapped;

	for (n = size, swapped = 1; n > 0 && swapped; n--)
	{
		swapped = 0;
		for (i = 0; (i + 1) < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
	}
}
