#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;
    /*test 1*/
    head = NULL;
    printf("test 1\n");
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    printf("-----------------\n");
    insert_node(&head, 27);

    print_listint(head);
    free_listint(head);

    /*test 2*/
    head = NULL;
    printf("test 2\n");
    print_listint(head);
    printf("-----------------\n");
    insert_node(&head, 27);

    print_listint(head);
    free_listint(head);

    /*test 3*/
    head = NULL;
    printf("test 3\n");
    add_nodeint_end(&head, 30);
    add_nodeint_end(&head, 30);
    add_nodeint_end(&head, 30);
    add_nodeint_end(&head, 30);
    add_nodeint_end(&head, 30);
    print_listint(head);
    printf("-----------------\n");
    insert_node(&head, 52);

    print_listint(head);
    free_listint(head);

    /*test 3*/
    head = NULL;
    printf("test 3\n");
    add_nodeint_end(&head, -34);
    add_nodeint_end(&head, -25);
    add_nodeint_end(&head, -9);
    add_nodeint_end(&head, -5);
    add_nodeint_end(&head, -3);
    print_listint(head);
    printf("-----------------\n");
    insert_node(&head, -10);

    print_listint(head);
    free_listint(head);

    return (0);
}