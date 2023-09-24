#include "sort.h"

/**
 * int_swap - Function that swaps two integers
 * in an array
 * @a: First integer
 * @b: Second integer
 */

void int_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Function that sorts an array of integers
 * using shell sort algorithm
 * @array: Integer array
 * @size: Size of array
 *
 * Description: This uses Knuth sequence
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				int_swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
