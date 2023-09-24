#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort
 * @array: the array to be sorted
 * @size: the length of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t min_index = 0;
	size_t sorted = 0, i = 0;
	int tmp = 0;

	while (sorted < size)
	{
		min_index = sorted;
		for (i = sorted; i < size; i++)
		{
			if (array[min_index] > array[i])
				min_index = i;
		}
		if (min_index != sorted)
		{
			tmp = array[sorted];
			array[sorted] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
		sorted++;
	}
}
