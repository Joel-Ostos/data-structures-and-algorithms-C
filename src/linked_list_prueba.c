#include <stdio.h>
#include "linkedlist.h"
typedef struct Persona Persona;

struct Persona {
  char nombre[300];
  int edad;
  int altura;
};

linkedlist(int)
linkedlist(char)
linkedlist(Persona)

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
    printf("%d", current->data);
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
    printf("%c", current->data);
    current = current->next;
  }
}

int main(void)
{
  LinkedList_int lista = init_list_int();
  LinkedList_char lista_char = init_list_char();
  LinkedList_Persona lista_persona = init_list_Persona();
  for (int i = 0; i < 20; i++) {
    push_back_int(&lista, i);
    push_back_char(&lista_char, 'i');
    push_back_Persona(&lista_persona, crear_persona(i));
  }
  print_persona(&lista_persona);
}
