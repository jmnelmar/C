#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct node{
  int dato;
  char nombre[30];
  struct node *siguiente;
}node;

node *contactos=NULL;
void insert_node();
void print_nodes();
void search_node(int id);
<<<<<<< HEAD
void del_node_byID(int id);
=======
void delete_node_by_id(int id);
>>>>>>> 7b23626005070c866188e2992c2c88dd78eb63a8
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
  printf("Ingrese el nodo\n");
  printf("ID:");
  scanf("%i",&nuevoNodo->dato);
  printf("nombre:");
  scanf("%s",nuevoNodo->nombre);
  nuevoNodo->siguiente=contactos;
  contactos=nuevoNodo;
}

void print_nodes(){
  node *actual= (node *)malloc(sizeof(node));
  actual=contactos;
  if(contactos!=NULL){
    printf("Los nodos se listan a continuacion\n");
    while(actual != NULL){
      printf("Id: %d , Nombre: %s\n",actual->dato,actual->nombre);
      actual=actual->siguiente;
    }
  }else{
    printf("La pila esta vacia");
  }
  printf("Precione una tecla para continuar");
  getchar();
  getchar();
}

void search_node(int id){
  node *actual= (node *)malloc(sizeof(node));
  actual=contactos;
  int encontrado=0;
  if(contactos!=NULL){
    while(actual != NULL && encontrado!=1){
      if(actual->dato==id){
          printf("El nodo con ID: %i fue encontrado\n",id);
          printf("Id: %d , Nombre: %s\n",actual->dato,actual->nombre);
<<<<<<< HEAD
          return;
=======
          encontrado=1;
>>>>>>> 7b23626005070c866188e2992c2c88dd78eb63a8
      }

      actual=actual->siguiente;
    }
  }else{
    printf("El nodo con el ID %i no pude ser encontrado.",id);
  }
  printf("Precione una tecla para continuar");
  getchar();
  getchar();
}

<<<<<<< HEAD
void del_node_byID(int id){
  node *actual= (node *)malloc(sizeof(node));
  actual=anteriorNodo;
  if(anteriorNodo!=NULL){
    while(actual != NULL){
      if(actual->dato==id){
          
          return;
      }

      actual=actual->siguiente;
    }
  }else{
    printf("El nodo con el ID %i no pude ser encontrado.",id);
  }
=======
void delete_node_by_id(int id){
  int encontrado=0;
  node *actual= (node *)malloc(sizeof(node));
  node *anterior= (node *)malloc(sizeof(node));
  actual=contactos;

  if(contactos!=NULL){
    while(actual != NULL && encontrado!=1){
      if(actual->dato==id){
          if(actual==contactos){
            contactos=contactos->siguiente;
          }else{
            anterior->siguiente=actual->siguiente;
          }
          printf("El contacto:\nId: %i\nNombre: %s\nFue eliminado",id,actual->nombre);
          encontrado=1;
      }
      anterior=actual;
      actual=actual->siguiente;
    }
    if(encontrado==0){
      printf("El contacto con id %i no pudo ser encontrado\n",id);
    }else{
      free(anterior);
    }
  }else{
    printf("Los contactos estan vacios.");
  }

>>>>>>> 7b23626005070c866188e2992c2c88dd78eb63a8
  printf("Precione una tecla para continuar");
  getchar();
  getchar();
}

<<<<<<< HEAD

=======
>>>>>>> 7b23626005070c866188e2992c2c88dd78eb63a8
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
