#include "sort.h"

/**
 * bubble_sort - sorts a list using the bubble sort algorithm
 * @array: the array to be sorted
 * @size: the length of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, tmp = 0;
	int swap = 0;

	for (i = 0; i < size; i++)
	{
		swap = 0;
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = 1;
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
			if (swap == 0)
				break;
	}
}
