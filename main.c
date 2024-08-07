#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char **argv)
{
FILE *file;
char *content = NULL;
size_t len = 0;
ssize_t read;
unsigned int counter = 0;
stack_t *stack = NULL;
if (argc != 2)
{ fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE); }
file = fopen(argv[1], "r");
if (file == NULL)
{ fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE); }
while ((read = getline(&content, &len, file)) != -1)
{
counter++;
bus.content = clean_line(content);
if (execute(bus.content, &stack, counter, file) == 1)
{
fclose(file);
free(content);
free_stack(stack);
exit(EXIT_FAILURE);
}
}
fclose(file);
free(content);
free_stack(stack);
return (0);
}
