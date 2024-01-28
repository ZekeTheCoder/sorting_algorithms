#include "sort.h"

/**
 * swap - This function swaps the positions of two elements in an array.
 *
 * @array: array of integers
 * @first:  first element to be swapped
 * @second:  second element to be swapped
 */
void swap(int *array, ssize_t first, ssize_t second)
{
	int temp;

	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}

/**
 * lomuto_partition - This function implements the Lomuto partition scheme for
 * the Quick Sort algorithm.
 *
 * @array: array to be sorted
 * @first:  first element of the partition
 * @last:  last element of the partition
 * @size: size of array
 *
 * Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t pivot_position = first, iterator;

	for (iterator = first; iterator < last; iterator++)
	{
		if (array[iterator] < pivot)
		{
			if (array[pivot_position] != array[iterator])
			{
				swap(array, pivot_position, iterator);
				print_array(array, size);
			}
			pivot_position++;
		}
	}

	if (array[pivot_position] != array[last])
	{
		swap(array, pivot_position, last);
		print_array(array, size);
	}

	return (pivot_position);
}

/**
 * quicksort -  recursively sorts the subarrays
 *
 * @array: array to be sorted
 * @first: first element of the subarray
 * @last: last element of the subarray
 * @size: array size
 */
void quicksort(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		quicksort(array, first, position - 1, size);
		quicksort(array, position + 1, last, size);
	}
}

/**
 * quick_sort - this function sorts an array of integers in ascending order
 * using the Quick Sort algorithm (Lomuto partition scheme).
 *
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
