#include <stdio.h>
#include "../data_structures.h"

arraylist(int)
arraylist(ArrayList_int)

int main(void)
{
  // ----------- Arreglos --------------------
  int array[5];
  ArrayList_int arreglo = set_array_int(array, 5);
  ArrayList_int arreglo2 = init_array_int(3);

  // Colocando elementos en el arraylist 1
  push_back_array_int(&arreglo, 22,0);
  push_back_array_int(&arreglo, 22,0);
  push_back_array_int(&arreglo, 39,0);
  push_back_array_int(&arreglo, 50,01);

  // Colocando elementos en el arraylist 2, tanto en posiciones especificas como en la cola
  insert_array_int(&arreglo2,103,0);
  insert_array_int(&arreglo2,104,1);
  insert_array_int(&arreglo2,105,2);
  insert_array_int(&arreglo2,107,3);
  push_back_array_int(&arreglo2, 2, 0);
  push_back_array_int(&arreglo2, 3, 0);
  push_back_array_int(&arreglo2, 5, 0);

  for (size_t i = 0; i < arreglo2.capacity; i++) {
    printf("%d ", arreglo2.array[i]);
  }
  // Eliminando todos los elementos del arreglo
  for (size_t i = 0; i < arreglo2.capacity; i++) {
    delete_array_int(&arreglo2, 0);
  }
  printf("\nLuego de eliminar todos los elementos del arreglo 2: \n");

  for (size_t i = 0; i < arreglo2.capacity; i++) {
    printf("%d ", arreglo2.array[i]);
  }

  // Deinicializar los arreglos, es decir, dealocarlos, en el caso en el que estén alocadas en el heap.
  deinit_array_int(&arreglo2);
  if (arreglo.state) {
    deinit_array_int(&arreglo);
  }
}
