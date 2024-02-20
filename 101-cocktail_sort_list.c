#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swaps a node in a listint_t dll
 * list of integers with the node ahead of it.
 * @list: pointer to the head of a dll of integers.
 * @tail: pointer to the tail of the dll.
 * @shaker: pointer to the current swapping node
*/
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swaps a node in a listint_t dll of integers
 *   with the node behind it.
 * @list: pointer to the head of a dll of integers.
 * @tail: pointer to the tail of the dll.
 * @tip: pointer to the current swapping node.
*/
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **tip)
{
	listint_t *tmp = (*tip)->prev;

	if ((*tip)->next != NULL)
		(*tip)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*tip)->next;
	(*tip)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *tip;
	else
		*list = *tip;
	(*tip)->next = tmp;
	tmp->prev = *tip;
	*tip = tmp;
}

/**
 * cocktail_sort_list - Sorts a listint_t dll of integers in
 * ascending order using the cocktail shaker algorithm.
 * @list: pointer to the head of a listint_t dll.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
