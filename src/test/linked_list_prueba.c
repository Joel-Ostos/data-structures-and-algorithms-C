#include <stdio.h>
#include "../data_structures.h"
typedef struct Persona Persona;


struct Persona {
  char nombre[300];
  int edad;
  int altura;
};

linkedlist(int)
linkedlist(char)
linkedlist(Persona)
arraylist(int)
arraylist(ArrayList_int)

Persona crear_persona(int data)
{
  return (Persona){
    "Jose Eustacio", data, data
  };
}

void print_int(LinkedList_int* list)
{
  Node_int* current = list->tail;
  while(current) {
    printf("%d ", current->data);
    current = current->next;
  }
}

void print_persona(LinkedList_Persona* list)
{
  Node_Persona* current = list->tail;
  while (current) {
    printf("%s \t %d \t %d\n", current->data.nombre, current->data.altura, current->data.edad);
    current = current->next;
  }
}

void print_char(LinkedList_char* list) {
  Node_char* current = list->tail;
  while (current) {
    printf("%c ", current->data);
    current = current->next;
  }
}

int main(void)
{
  // ----------- Listas --------------------
  LinkedList_int lista = init_list_int();
  LinkedList_char lista_char = init_list_char();
  LinkedList_Persona lista_persona = init_list_Persona();
  for (int i = 0; i < 20; i++) {
    push_back_list_int(&lista, i);
    push_back_list_char(&lista_char, 'i');
    push_back_list_Persona(&lista_persona, crear_persona(i));
  }
  print_int(&lista);
  delete_node_list_int(&lista, 10);

  printf("\n------ Lista luego de eliminar ------\n");
  print_int(&lista);
  printf("\nDealocando\n");
  deinit_list_int(&lista);
  deinit_list_char(&lista_char);
  deinit_list_Persona(&lista_persona);

  printf("\n------ Arreglos ------\n");
  // ----------- Arreglos --------------------
  int array[20];
  ArrayList_int arreglo = set_array_int(array, 3);
  ArrayList_int arreglo2 = init_array_int(3);
  ArrayList_ArrayList_int matriz = init_array_ArrayList_int(3);
  
  push_back_array_int(&arreglo, 22);
  push_back_array_int(&arreglo, 39);
  push_back_array_int(&arreglo, 501);

  insert_array_int(&arreglo2,103,0);
  insert_array_int(&arreglo2,104,1);
  insert_array_int(&arreglo2,105,2);
  insert_array_int(&arreglo2,107,3);
  push_back_array_int(&arreglo2, 2);
  push_back_array_int(&arreglo2, 3);
  push_back_array_int(&arreglo2, 5);
  printf("%ld\n", arreglo.capacity);
  for (size_t i = 0; i < arreglo2.capacity; i++) {
    printf("%d ", arreglo2.array[i]);
  }
  //delete_array_int(&arreglo2, 5);
  //delete_array_int(&arreglo2, 0);
  //delete_array_int(&arreglo2, 0);
  //delete_array_int(&arreglo2, 0);
  //delete_array_int(&arreglo2, 0);
  //delete_array_int(&arreglo2, 0);
  //delete_array_int(&arreglo2, 0);
  //delete_array_int(&arreglo2, 0);
  printf("\n%ld\n", arreglo.capacity);

  for (size_t i = 0; i < arreglo2.capacity; i++) {
    printf("%d ", arreglo2.array[i]);
  }
  //deinit_array_int(&arreglo2);
  if (arreglo2.array){
    for (size_t i = 0; i < arreglo2.capacity; i++) {
      printf("%d ", arreglo2.array[i]);
    }
  }

  push_back_array_ArrayList_int(&matriz, arreglo);
  push_back_array_ArrayList_int(&matriz, arreglo2);

  printf("\n ----- ");
  printf("\nOcupado: %ld %ld \n", matriz.occupied,  matriz.array->occupied);

  for (size_t i = 0; i < matriz.occupied; i++) {
    for (size_t j = 0; j < matriz.array[i].occupied; j++) {
      printf("%d ", matriz.array[i].array[j]);
    }
  }
}
