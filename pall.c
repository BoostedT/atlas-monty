#include "monty.h"
/**
 * f_pall - prints all the values on the stack, starting from the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number
 *
 * Return: void
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
