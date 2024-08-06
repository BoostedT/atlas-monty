#include "monty.h"
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
char *content;
FILE *file;
ssize_t read_line = 1;
stack_t *stack = NULL;
unsigned int counter = 0;
bus_t bus = {NULL, NULL, NULL, 0};
instruction_t instructions[] = {
{"push", f_push},
{"pall", f_pall},
{NULL, NULL}
};
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
bus.file = file;
while (read_line != -1)
{
read_line = getline(&content, &(size_t){0}, file);
counter++;
if (read_line == -1)
{
free(content);
break;
}
bus.content = content;
content = clean_line(content);
if (content)
{
bus.arg = strtok(content, " \n");
if (bus.arg && bus.arg[0] != '#')
{
for (int i = 0; instructions[i].opcode; i++)
{
if (strcmp(instructions[i].opcode, bus.arg) == 0)
{
instructions[i].f(&stack, counter);
break;
}
if (!instructions[i + 1].opcode)
{
fprintf(stderr, "L%u: unknown instruction %s\n", counter, bus.arg);
exit(EXIT_FAILURE);
}
}
}
}
free(bus.content);
}
free_stack(stack);
fclose(file);
return (0);
}
