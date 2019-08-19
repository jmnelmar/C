#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int split( char *str, char* separator, char *value);
/**
* main - prints the environment
*
* Return: Always 0.
*/

int main(int ac, char **av, char **env)
{
    unsigned int i;
    i = 0;
    if(ac>1){
        char *value=av[1];
        while (env[i] != NULL)
        {
            if(split(env[i],"=",av[1]) == 1){
                //printf("%s\n", env[i]);
                return 0;
            }
            
            i++;
        }
    }
    return (0);
}


int split( char *str, char* separator, char *value)
{
    int i;
    char *palabra;
    char *aux=str;
    const char *separadores=separator;
    
    for(i=0;str[i]!='\0';i++){
        if(separator != '='){
            if(str[i]==value[i]){
                
            }
        }
        
    }

    palabra=strtok(aux,separadores);


    if(*palabra == *value){
        printf("%s",palabra);
        palabra = strtok(NULL, separadores);
        printf("%s",palabra);

        return 1;
        
    } 
        
    return 0;

}