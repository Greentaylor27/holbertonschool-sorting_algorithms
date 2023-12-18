#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order using insertion sort
 * @list: pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;
    current = (*list)->next;
    while (current != NULL)
    {
        tmp = current->prev;
        while (tmp != NULL && tmp->n > current->n)
        {
            if (tmp->next != NULL)
                tmp->next->prev = current;
            current->prev = tmp->prev;
            tmp->next = current->next;
            if (current->next != NULL)
                current->next->prev = tmp;
            current->next = tmp;
            tmp->prev = current;
            if (current->prev != NULL)
                current->prev->next = current;
            else
                *list = current;
            print_list(*list);
            tmp = current->prev;
        }
        current = current->next;
    }
}