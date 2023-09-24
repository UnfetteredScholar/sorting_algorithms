#include "sort.h"

/**
 * swap - swap two array items
 * @array: the array
 * @i: the first index
 * @j: the second index
 *
 * Return: void
 */
void swap(int *array, int i, int j)
{
	int tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;
}

/**
 * partition - partitions an array around a pivot
 * @array: the array
 * @lo: index of the start
 * @hi: index of the end
 * @size: the size of the array
 *
 * Return: final position of the pivot
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo;
	int j = lo;

	for (j = lo; j <= hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	swap(array, i, hi);
	if (i != hi)
		print_array(array, size);
	return (i);
}

/**
 * quicksort - performs recursive quicksort
 * @array: the array
 * @lo: the lower bound
 * @hi: the upper bound
 * @size: the size of the array
 *
 * Return: void
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	int p = 0;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
