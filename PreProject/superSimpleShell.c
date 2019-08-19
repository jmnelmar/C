#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


int exc(char *comand, int len)
{

  int result;
  char token[len-1];
  int i;
  
  for(i=0;i<len-1;i++){
    token[i]=comand[i];
  }
  

  char *argv[] = {token, NULL, NULL, NULL};
  char *env[] = { "TERM=xterm", (char *)0 };

  result = execve(argv[0], argv,env);

  if(result < 0){ 
    
    exit(1);
    return (1);
    
  }
  
  return ( 0 );
}

int main(int argc, char *argv[], char *env[])
{
  size_t letters;
  char *input = NULL;
  int isEnd=0;
  size_t bufsize=3;
  pid_t pid;
  int status;
 
  do{
    write(STDOUT_FILENO, "$", 1);
    if((letters=getline(&input,&bufsize,stdin)) != EOF){
      pid=fork();
      if( pid == -1)
      {
        perror("fork error");
      }else if(pid == 0){

      isEnd = exc(input,letters);
      if(isEnd == 1)
      {
        perror("Error");
        exit(0);
      }
      }else{
        wait(&status);
      }
    }else{
      break;
    }
  }while(1);

  printf("\n");
  free(input);
  return (0);

}
