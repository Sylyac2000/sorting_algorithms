#include "sort.h"


/**
 * swap - swaps two nodes
 * @head: the head node
 * @node1: The first node
 * @node2: the second node
 *
 * Return: void
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}
/**
* insertion_sort_list - sorting algorithm
* @list: list to sort
* Return void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *suiv, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (suiv = (*list)->next; suiv && suiv->prev; suiv = suiv->next)
	{
		for (; suiv && suiv->prev && suiv->n < suiv->prev->n;
		     suiv = suiv->prev)
		{
			tmp = suiv->prev;
			swap(list, tmp, suiv);
			print_list(*list);
			suiv = suiv->next;
		}
	}
}
