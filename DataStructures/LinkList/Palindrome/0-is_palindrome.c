#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if it is a palindrome or 0 if it is not a palindrome
*/
int is_palindrome(listint_t **head)
{
	listint_t *aux = NULL;
	listint_t *tmp = NULL;
	
	if(head == NULL)
		return 1;

	tmp = copy_list(head);	
	aux = reverse_listint(head);

	while(tmp != NULL ){
		
		if( tmp->n != aux->n ){
			
			return 0;
		}
		tmp = tmp->next;
		aux = aux->next;
	}

	return 1;
}

/**
 * reverse_listint - function that reversed a list
 * @head: first element of tha list
 * Return: return a new list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *temp = *head;
	listint_t *prev = NULL;

	while (*head != NULL)
	{
		*head = temp->next;
		temp->next = prev;
		prev = temp;
		temp = *head;
	}
	*head = prev;
	return (*head);
}


listint_t *copy_list(listint_t **head)
{
	listint_t *temp = *head;
	listint_t *new;
	
	while (temp != NULL)
	{
		add_nodeint_end(&new, temp->n);
		temp = temp->next;
	}
	
	return (new);
}
