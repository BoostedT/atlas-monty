#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
stack_t *new;
char *arg;
int n;
arg = strtok(NULL, " \n");
if (!arg)
{
fprintf(stderr, "L%u: usage: push integer\n", counter);
exit(EXIT_FAILURE);
}
if (isdigit(*arg) == 0 && *arg != '-')
{
fprintf(stderr, "L%u: usage: push integer\n", counter);
exit(EXIT_FAILURE);
}
n = atoi(arg);
new = malloc(sizeof(stack_t));
if (!new)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new->n = n;
new->prev = NULL;
new->next = *head;
if (*head)
(*head)->prev = new;
*head = new;
}
