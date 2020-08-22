#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * listint_t - adds a new node in their sorted position
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;
    listint_t *prev = NULL;
    current = *head;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);
    new->n = number;
    new->next = NULL;
    if (*head == NULL ){
        *head = new;
        return new;
    }
    else{
        prev = current;
        while(current->next != NULL ){
            if(current->n > number )
            {
                if( prev == current){
                    new->next = current;
                    *head = new;
                    return new;
                }else{
                    prev->next = new;
                    new->next = current;
                    return new;                  
                }    
            }
            else
            {   
                prev = current;
            }      
            current = current->next;
        }
    }
    current->next = new;
    return (new);
}