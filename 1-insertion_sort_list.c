#include "sort.h"

/**
 * swap_back - swaps a node with the one behind it
 * @node: the node to swap
 *
 * Return: void
 */
void swap_back(listint_t *node)
{
	listint_t *prev = node->prev;

	prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = prev;
	node->next = prev;
	node->prev = prev->prev;
	if (prev->prev != NULL)
		prev->prev->next = node;
	prev->prev = node;
}

/**
 * insertion_sort_list - uses the insertion sort algorithm to
 * sort a list
 * @list: pointer to the pointer of the head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *min = NULL, *h = NULL;
	int *tmp;


	if (!list || !*list || !(*list)->next)
		return;
	h = *list;
	min = malloc(sizeof(listint_t));
	min->prev = NULL;
	min->next = h;
	h->prev = min;
	tmp = (int *)&min->n;
	*tmp = -2147483648; /*Set false head to min int */
	*list = min;

	while (h)
	{
		while (h->prev && (h->prev->n > h->n))
		{
			swap_back(h);
			print_list(min->next);
		}
		h = h->next;
	}
	min->next->prev = NULL;
	*list = min->next;
	free(min);
}
