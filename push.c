#include "monty.h"

/**
 * f_push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number being executed from script file
 */
void f_push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;
char *arg;
int i;
arg = strtok(NULL, "\n");
if (!arg || !isdigit(*arg))
{
dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
for (i = 0; arg[i]; i++)
{
if (arg[i] == '-' && i == 0)
continue;
if (!isdigit(arg[i]))
{
dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
}
new_node = malloc(sizeof(stack_t));
if (!new_node)
{
dprintf(STDERR_FILENO, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = atoi(arg);
new_node->prev = NULL;
new_node->next = *stack;
if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}
