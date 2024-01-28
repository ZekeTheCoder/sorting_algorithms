#include "sort.h"

/**
 * selection_sort - this function sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * algorithm
 *
 * @array: input array of integers
 * @size: size of the array
 *
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i = 0;

	while (i < size)
	{
		size_t min = i;
		size_t j = i + 1;

		while (j < size)
		{
			if (array[min] > array[j])
				min = j;
			j++;
		}

		if (i != min)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
		i++;
	}
}
