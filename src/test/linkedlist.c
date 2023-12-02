#include <stdio.h>
#include "../data_structures.h"
typedef struct Persona Persona;

struct Persona {
  char nombre[300];
  int edad;
  int altura;
};

// Ampliación de las macros para generar el código para las listas enlazadas de tipo int, char y Persona
linkedlist(int)
linkedlist(char)
linkedlist(Persona)

Persona crear_persona(int data)
{
  return (Persona) {
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

  // Adición de elementos a las listas

  for (int i = 0; i < 20; i++) {
    push_back_list_int(&lista, i);
    push_back_list_char(&lista_char, '0' - i);
    push_back_list_Persona(&lista_persona, crear_persona(i));
  }
  printf("\n------ Lista int luego de agregar ------\n");
  print_int(&lista);
  printf("\n------ Lista char luego de agregar ------\n");
  print_char(&lista_char);
  printf("\n------ Lista Persona luego de agregar ------\n");
  print_persona(&lista_persona);

  delete_node_list_int(&lista, 10);

  printf("\n------ Lista luego de eliminar ------\n");
  print_int(&lista);
  printf("\nDealocando las listas\n");
  deinit_list_int(&lista);
  deinit_list_char(&lista_char);
  deinit_list_Persona(&lista_persona);
}
