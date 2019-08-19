#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i;
    char *palabra;
    const char *separadores;
    separadores = "=";
    char *stravg;

    if(argc>1){
        palabra=strtok(argv[1],separadores);
        palabra = strtok(NULL, separadores);

        separadores = ":";
        palabra = strtok(palabra, separadores);

        while (palabra != NULL)
        {
            
                printf("%s\n", palabra);
            
            
            palabra = strtok(NULL, separadores);
        }
    } 

    

    /*for (i = 0; i < argc; i++)
    {
        palabra = strtok(argv[i], separadores);
        while (palabra != NULL)
        {
            printf("%s\n", palabra);
            palabra = strtok(NULL, separadores);
        }*/
        return 0;
    /*}*/
}