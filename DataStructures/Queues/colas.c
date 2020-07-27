#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
//Programa tipo colas de una agenda de contactos
//Queue program of one contact agenda
typedef struct node{
  int dato;
  char nombre[30];
  struct node *siguiente;
}node;

node *contactos=NULL;
node *primero=NULL;
node *ultimo=NULL;
void insert_node();
void print_nodes();
void search_node(int id);
void delete_node_by_id(int id);
int menu();

int main(void){
  int opcion=0;
  opcion=menu();
  int idx;

    system("clear");
    while(opcion!=4){
      system("clear");
      //clrscr();
      if(opcion==1){
        insert_node();
      }
      if(opcion==2){

        printf("Ingrese el ID a busar: ");
        scanf("%d",&idx);
        search_node(idx);
      }
      if(opcion==3){
        print_nodes();
      }
      if(opcion==5){
        printf("Ingrese el ID a busar: ");
        scanf("%d",&idx);
        delete_node_by_id(idx);
      }
      opcion=menu();
    }
    system("clear");


  return 0;
}

void insert_node(){
  node *nuevoNodo= (node *)malloc(sizeof(node));

  printf("Ingrese el contacto\n");
  printf("ID:");
  scanf("%i",&nuevoNodo->dato);
  printf("nombre:");
  scanf("%s",nuevoNodo->nombre);

  if(primero==NULL){
      primero=nuevoNodo;
      primero->siguiente=NULL;
      ultimo=nuevoNodo;
  }else{
    ultimo->siguiente=nuevoNodo;
    nuevoNodo->siguiente=NULL;
    ultimo=nuevoNodo;
  }

  printf("\nEl contacto se ingreso con exito");
  getchar();
  getchar();
}

void print_nodes(){
  node *actual= (node *)malloc(sizeof(node));
  actual=primero;

  if(primero!=NULL){
    printf("Lista de contactos:\n");
    while(actual!=NULL){
      printf("Id: %i , Nombre:%s\n", actual->dato,actual->nombre);
      actual=actual->siguiente;
    }
  }else{
    printf("La lisa esta vacia");
  }

  getchar();
  getchar();
}

void search_node(int id){
  node *actual= (node *)malloc(sizeof(node));
  actual=primero;

  if(primero!=NULL){
    while(actual!=NULL){
      if(actual->dato==id){
        printf("El contacto fue encontrado\n");
        printf("Id: %i , Nombre:%s\n", actual->dato,actual->nombre);
        getchar();
        getchar();
        return;
      }else{
          actual=actual->siguiente;
      }
    }
  }else{
    printf("El contacto con Id:%i no se encuentra en la lista",id);
  }
  getchar();
  getchar();

}

void delete_node_by_id(int id){

  printf("En construccion!");
  getchar();
  getchar();
}

int menu(){
  system("clear");
  int opcion;
  printf("Bienvenido\n");
  printf("1 - Insertar un contacto.\n");
  printf("2 - Buscar un contacto por id.\n");
  printf("3 - Ver todos los contactos.\n");
  printf("5 - Eliminar un contacto.\n");
  printf("4 - Salir.\n");
  printf("Seleccione una opcion: ");
  scanf("%i",&opcion);
  return opcion;
}
