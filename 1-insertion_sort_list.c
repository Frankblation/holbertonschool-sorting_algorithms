#include "sort.h"

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
}

#include "sort.h"
#include <stdio.h>


/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}