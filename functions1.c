#include "monty.h"
/**
 * addnode - add node to the head stack
 * @head: stack head
 * @n: integer to add
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
stack_t *new_node, *aux;
aux = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{ printf("Error\n");
exit(0); }
if (aux)
aux->prev = new_node;
new_node->n = n;
new_node->next = *head;
new_node->prev = NULL;
*head = new_node;
}

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opst[] = {
{"push", f_push},
{"pall", f_pall},
{"pint", f_pint},
{"pop", f_pop},
{"swap", f_swap},
{"add", f_add},
{"nop", f_nop},
{"sub", f_sub},
{NULL, NULL}
};
unsigned int i = 0;
char *op;
op = strtok(content, " \n\t");
if (op && op[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{	opst[i].f(stack, counter);
return (0);
}
i++;
}
if (op && opst[i].opcode == NULL)
{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE); }
return (1);
}
/**
  *f_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
stack_t *aux;
int sus, nodes;
aux = *head;
for (nodes = 0; aux != NULL; nodes++)
aux = aux->next;
if (nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = *head;
sus = aux->next->n - aux->n;
aux->next->n = sus;
*head = aux->next;
free(aux);
}
