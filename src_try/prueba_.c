#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"

int main()
{
  struct doubly_linked mi_lista = init_doubly_linked();

  for (int i = 0; i < 10; i++) {
    push_back_d_linked(&mi_lista, &i);
  }

  int d=20;
  insert_d_linked(&mi_lista, &d, 6);
  print_d_list(&mi_lista, print_int);
}
