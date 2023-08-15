#include "sort.h"
#include "print_list.c"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *sorted = NULL;
    listint_t *current = *list;
    listint_t *next_node = NULL;

    while (current != NULL)
    {
        next_node = current->next;
        if (sorted == NULL || sorted->n >= current->n)
        {
            current->next = sorted;
            current->prev = NULL;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            listint_t *temp = sorted;
            while (temp->next != NULL && temp->next->n < current->n)
                temp = temp->next;

            current->prev = temp;
            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;
            temp->next = current;
        }
        print_list(*list);
        current = next_node;
    }
    *list = sorted;
include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 *                       of integers in ascending order using the Insertion
 *                       sort algorithm
 * @list: doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	node = node->next;
	while (node)
	{
		while (node->prev && node->n < (node->prev)->n)
		{
			tmp = node;
			if (node->next)
				(node->next)->prev = tmp->prev;
			(node->prev)->next = tmp->next;
			node = node->prev;
			tmp->prev = node->prev;
			tmp->next = node;
			if (node->prev)
				(node->prev)->next = tmp;
			node->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			print_list(*list);
			node = node->prev;
		}
		node = node->next;
	}

}