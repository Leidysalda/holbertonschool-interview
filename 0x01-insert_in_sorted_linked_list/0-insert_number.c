#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: index the node
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number) {

  listint_t *new, *current;

  new = malloc(sizeof(listint_t));

  new->n = number;
 
  if (*head == NULL || (*head)->n >= new->n)
    {
      new->next = *head;
      *head = new;
    }
  else
    {
      current = *head;
      while (current->next != NULL && current->next->n < new->n) 
        {
	  current = current->next;
	}
      new->next = current->next;
      current->next = new;
    }
  return (current);
}
