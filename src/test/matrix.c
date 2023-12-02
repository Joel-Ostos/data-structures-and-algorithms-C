#include <stdio.h>
#include "../data_structures.h"

arraylist(int)
arraylist(ArrayList_int)
extension(int)

int main(void)
{
  // ----------- Arreglos --------------------
  int array[5];
  ArrayList_int arreglo = set_array_int(array, 4);
  ArrayList_int arreglo2 = init_array_int(3);

  ArrayList_ArrayList_int matriz = init_array_ArrayList_int(2);

  // Colocando elementos en el arraylist 1
  push_back_array_int(&arreglo, 22);
  push_back_array_int(&arreglo, 22);
  push_back_array_int(&arreglo, 39);
  push_back_array_int(&arreglo, 50);
  push_back_array_int(&arreglo, 50);
  insert_array_int(&arreglo,103,0);
  push_back_arraymatrix_int(&matriz, &arreglo, true);
  delete_array_ArrayList_int(&matriz, 0);
  push_back_arraymatrix_int(&matriz, &arreglo, true);
  push_back_arraymatrix_int(&matriz, &arreglo, true);
  push_back_arraymatrix_int(&matriz, &arreglo, true);
  insert_array_int(&arreglo,103,0);

  // Colocando elementos en el arraylist 2, tanto en posiciones especificas como en la cola
  insert_array_int(&arreglo2,103,0);
  insert_array_int(&arreglo2,104,1);
  insert_array_int(&arreglo2,105,2);
  insert_array_int(&arreglo2,107,3);
  push_back_array_int(&arreglo2, 2);
  push_back_array_int(&arreglo2, 3);
  push_back_array_int(&arreglo2, 5);
  push_back_arraymatrix_int(&matriz, &arreglo2, true);
  
  // Deinicializar los arreglos, es decir, dealocarlos, en el caso en el que estén alocadas en el heap.
  deinit_array_int(&arreglo2);
  printf("Impresión elementos de la matriz: \n");

  for (size_t i = 0; i < matriz.occupied; i++) {
    for (size_t j = 0; j < matriz.array[i].occupied; j++) {
      printf("%d ", matriz.array[i].array[j]);
    }
  }

  printf("\nImpresión elementos de la matriz luego de insertar en el subarreglo 1 en la posición 2: \n");
  insert_array_int(&matriz.array[0],5,2);

  for (size_t i = 0; i < matriz.occupied; i++) {
    for (size_t j = 0; j < matriz.array[i].occupied; j++) {
      printf("%d ", matriz.array[i].array[j]);
    }
  }
  printf("\nImpresión elementos de la matriz luego de eliminar en el subarreglo 1 en la posición 2: \n");
  delete_array_int(&matriz.array[0],2);
  
  for (size_t i = 0; i < matriz.occupied; i++) {
    for (size_t j = 0; j < matriz.array[i].occupied; j++) {
      printf("%d ", matriz.array[i].array[j]);
    }
  }

  printf("\nImpresión elementos de la matriz luego de eliminar el subarreglo 1,2,3\n");
  delete_array_ArrayList_int(&matriz, 0);
  delete_array_ArrayList_int(&matriz, 0);
  delete_array_ArrayList_int(&matriz, 0);

  for (size_t i = 0; i < matriz.occupied; i++) {
    for (size_t j = 0; j < matriz.array[i].occupied; j++) {
      printf("%d ", matriz.array[i].array[j]);
    }
  }

  printf("\nImpresión elementos de la matriz luego de eliminar el último subarreglo \n");
  delete_array_ArrayList_int(&matriz, 0);

  for (size_t i = 0; i < matriz.occupied; i++) {
    for (size_t j = 0; j < matriz.array[i].occupied; j++) {
      printf("%d ", matriz.array[i].array[j]);
    }
  }

  printf("\nImpresión elementos de la matriz luego de añadir un arreglo\n");
  push_back_array_ArrayList_int(&matriz, arreglo);

  for (size_t i = 0; i < matriz.occupied; i++) {
    for (size_t j = 0; j < matriz.array[i].occupied; j++) {
      printf("%d ", matriz.array[i].array[j]);
    }
  }
  insert_array_int(&matriz.array[0], 10, 2);
  printf("\nImpresión elementos de la matriz luego de eliminar uno por uno los elementos del subarreglo\n");

  size_t size = matriz.array[0].occupied;

  for (size_t i = 0; i < size; i++) {
    delete_array_int(&matriz.array[0],0);
  }

  for (size_t i = 0; i < matriz.occupied; i++) {
    for (size_t j = 0; j < matriz.array[i].occupied; j++) {
      printf("%d ", matriz.array[i].array[j]);
    }
  }

  if (arreglo.state) {
    deinit_array_int(&arreglo);
  }
  deinit_array_ArrayList_int(&matriz);
}
