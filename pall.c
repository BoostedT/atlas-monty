#include "monty.h"
/**
 * f_pall - print all the stack
 * @head: stack head
 * @counter: line_number
 * Return: no
 */
void f_pall(stack_t **head, unsigned int counter)
{
stack_t *current = *head;
(void)counter;
while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}
