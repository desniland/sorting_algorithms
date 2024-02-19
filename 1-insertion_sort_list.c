#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @nd1: A pointer to the first node to swap.
 * @nd2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **nd1, listint_t *nd2)
{
	(*nd1)->next = nd2->next;
	if (nd2->next != NULL)
		nd2->next->prev = *nd1;
	nd2->prev = (*nd1)->prev;
	nd2->next = *nd1;
	if ((*nd1)->prev != NULL)
		(*nd1)->prev->next = nd2;
	else
		*h = nd2;
	(*nd1)->prev = nd2;
	*nd1 = nd2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *it, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (it = (*list)->next; it != NULL; it = tmp)
	{
		tmp = it->next;
		insert = it->prev;
		while (insert != NULL && it->n < insert->n)
		{
			swap_nodes(list, &insert, it);
			print_list((const listint_t *)*list);
		}
	}
}
