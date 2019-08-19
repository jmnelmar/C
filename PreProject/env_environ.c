#include <stdio.h>
#include <unistd.h>
#include <unistd.h>

extern char **environ;

/**
* main - prints the environment
*
* Return: Always 0.
*/
int main(int ac, char **av, char **env)
{
    unsigned int i;
    i = 0;
    printf("%p\n", &env);
    printf("%p\n", &environ);
    
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
    return (0);
}