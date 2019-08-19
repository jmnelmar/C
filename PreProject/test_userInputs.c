#include <stdio.h>
#include<stdlib.h>

int main()
{
    //char *buffer=NULL;
    char *input = NULL;//lo que el usuario ingresa desde la linea de comandos
    size_t bufsize=3;// el tamanio de lo que ingresa
    size_t letters;// el contador de las letras que ingreso el usuario

    printf("$ ");//imprimimos el prompt
    letters = getline(&input,&bufsize,stdin);//llamamos a la funcion get line, ella asigna o re-asigna el tamanio del input y bufsize en caso de ser necesario

    int i;
    for(i=0;input[i]!='\0';i++){//recorremos lo que el usuario ingreso para inprimirlo en pantalla.
      putchar(input[i]);
    }

    return(0);
}
