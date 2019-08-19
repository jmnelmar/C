#include "header"
/*
**Funciones core
**Estas son las funciones necesarias para la shell trabaje
**
*/

/*
**Funcion split parte una linea segun los separadores que le envien y devuelve un puntero de punteros
**@line: Es el string que vamos a dividir en tokens
**@separators: son los separadores que vamos a utilizar par dividir nuestra linea en tokens
**arr: es el puntero de punteros(arreglo de punteros) con todos los tokens o diviciones de la linea
**Uso: Esta Funcion nos va a servir para dividir lo que el usuario ingresa en nuestra shell, incluso nos puede servir para
*******dividir la variable del PATH del enviroment y asi encontrar todas las carpetas donde se encuentran nuestros comandos.
*/
char **split(char *line, char *separators)
{
    char **arr;
    char *part;
    char *cpy;
    int parts, i;
    
    cpy = _strcpy(line);
    parts = count_parts(line, separators);

	arr = malloc(sizeof(char *) * (parts + 1));

	if (arr == NULL)
		return (NULL);
	part = strtok(cpy, separators);
	for (i = 0; part != NULL; i++)
	{
		arr[i] = _strcpy(part);
		part = strtok(NULL, separators);
	}
	arr[i] = NULL;
	free(cpy);	
    return (arr);
}

int execute_cmd(char **arguments, int len)
{
    int result;

    return (result);

}

char **find_path(char *line)
{
    char **path;
    return (path);
}

char *find_dir(char **path)
{
    char *dir;
    return (dir);
}
/*
**fin de las funciones core
*/

/*
**Funciones de ayuda.
**Funciones de ayuda de aqui para abajo son las funciones extras necesarias para que las funciones  core de las shell
**trabajen correctamente
*/
/*
**@strcpy: funcion que recibe un string y devuelve una copia de este, util cuando no queramos modificar el string original.
**@src: string original 
**Return @dest: devuelve un nuevo puntero con los mismos valores del puntero o string original. 
*/
char *_strcpy(char *src)
{
	int i;
	int len;
	char *dest;

	len = _strlen(src);
	dest = malloc(sizeof(char) * (len + 1));

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/*
**@count_parts: Funcion que cuenta cuantas diviciones tiene una linea segun los delimitadores que le envien.
**@line: linea a dividir.
**@delim: delimitadores por los que se va a dividir una linea
**Return @i: devuelve el contador que itero las partes en las que se dividio la linea.
*/
int count_parts(char *line, const char *delim)
{
	char *str;/*string copia, para no modificar el original*/
	char *line_part;/*parte de la linea en la que se dividio la linea original despues de hacer strtok*/
	int i;/*contador*/

	str = _strcpy(line);/*hacemos una copia para no modificar el original*/
	if (str == NULL)/*verificamos que la copia se creara sin problemas*/
		return (-1);
	line_part = strtok(str, delim);/*dividimos la primera vez la linea*/
	for (i = 0; line_part != NULL; i++)/*for que itera hasta que la parate de la line sea null, es decir que ya no se encuentren mas diviciones*/
		line_part = strtok(NULL, delim);/*dividimos sobre null para que continue diviendo sobre line*/
	free(str);/*alterminar liberamos la memoria*/
	return (i);
}

int _strlen(char *str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++ )
    ;

    return i;
}