#include "lists.h"

/**
 * check_cycle - function that checks if a singly linked list has a cycle in it.
 * @list: list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
  listint_t *one = list;
  listint_t *two = list;

  if (list == NULL || list->next == NULL)
    return (0);

  if (list->next == list)
    return (1);

  while (one->next != NULL && one->next->next != NULL)
    {
      two = two->next;
      one = one->next->next;

      if (one == two)
	return (1);
    }
  return (0);
}
