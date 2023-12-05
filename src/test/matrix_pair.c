#include <stdio.h>
#include "../data_structures.h"
typedef struct pair pair;

struct pair {
  int ff;
  int ss;
};

arraylist(pair)
arraylist(ArrayList_pair)
extension(pair)

pair f_init(int a, int b)
{
  return (pair) {a,b};
}

int main(void)
{
  ArrayList_ArrayList_pair matriz = init_array_ArrayList_pair(3);
  ArrayList_pair arreglo_pair = init_array_pair(3);

  for (int i = 0; i < 10; i++) {
    pair a  = f_init(i, i*i);
    push_back_array_pair(&arreglo_pair, a);
  }
  printf("Tamaño: %ld Ocupado: %ld \n", arreglo_pair.capacity, arreglo_pair.occupied);
  push_back_arraymatrix_pair(&matriz, &arreglo_pair, 1);

  for (size_t i = 0; i < matriz.occupied;i++){
    for (size_t j = 0; j < matriz.array[i].occupied; j++){
      printf("%d %d\n",matriz.array[i].array[j].ff,matriz.array[i].array[j].ss);
    }
  }
}

