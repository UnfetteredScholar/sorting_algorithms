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
	size_t space, i, j;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (i = space; i < size; i++)
		{
			j = i;
			while (j >= space && array[j - space] > array[j])
			{
				int_swap(array + j, array + (j - space));
				j -= space;
			}
		}
		print_array(array, size);
	}
}
