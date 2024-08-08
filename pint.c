#include "monty.h"
/**
 * f_pint - prints the value at the top of the stack
 * @head: head linked list
 * @number: line_number
 * Return: no return
 */
void f_pint(stack_t **head, unsigned int number)
{
stack_t *current = *head;
if (!current)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", number);
exit(EXIT_FAILURE);
}
printf("%d\n", current->n);
}
