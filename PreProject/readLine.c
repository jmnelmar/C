#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
main(int argc, char *argv[])
{
    char *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;




    while ((line != EOF || line != "^D") && line==NULL) {
        printf("$ ");
        line = getline(&b,&len,STDIN);
        write(line, nread, 1, stdout);
    }


   //  line = getline(&line, &len, STDIN);
    //printf("%s",line);
    //while( line = EOF || line != "^D"){

    //}

    free(line);
    close(stream);
    exit(0);




    //char buffer[32];
    //char *b = buffer;
    //size_t bufsize = 32;
    //size_t characters;

    //printf("Type something: ");
    //characters = getline(&b,&bufsize,stdin);
    //printf("%zu characters were read.\n",characters);
    //printf("You typed: '%s'\n",buffer);

    return(0);
}
