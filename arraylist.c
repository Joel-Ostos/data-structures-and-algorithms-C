#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct ArrayList {
  size_t size;
  size_t size_a;
  int* array;
};

static void check(int* ptr)
{
  if (!ptr) exit(1);
}

struct ArrayList allocate(size_t size)
{
  int* array =  (int*) malloc(size * sizeof(int));
  check(array);

  if (array){
    struct ArrayList arrayl = {.size = size, .size_a = 0, .array = array}; 
    return arrayl;
  }

}

void push_back(struct ArrayList* array, int el)
{
  if (array->size > array->size_a){
    array->array[array->size_a] = el;
    array->size_a += 1;
  } else {
    int* realloc_array = (int*) realloc(array->array, (array->size *sizeof(int)) + sizeof(int));
    check(realloc_array);
    
    array->array = realloc_array;
    array->array[array->size] = el;
    array->size += 1;
    array->size_a += 1;
  }
}

void add(struct ArrayList* array, size_t index, int el)
{
  int* new_array = (int*) malloc( array->size * sizeof(int) + sizeof(int));
  memcpy(new_array, array->array, (index) * sizeof(int));
  memcpy(new_array + index, array->array+index-1, (array->size - index + 1) * sizeof(int));
  free(array->array);
  array->array = new_array;
  new_array[index] = el;
  array->size += 1;
  array->size_a += 1;
}

int delete(struct ArrayList* array, int index)
{
  int* new_array = (int*) malloc((array->size-1) * sizeof(int));
  int devolver = array->array[index];
  memcpy(new_array, array->array, (index) * sizeof(int));
  memcpy(new_array + index, array->array + index + 1, (array->size-index-1) * sizeof(int));
  free(array->array);
  array->array = new_array;
  array->size -= 1;
  array->size_a -= 1;
  //assert(devolver == 50);
  return devolver;
}

void deallocate(struct ArrayList* array)
{
    free(array->array);
}

// TODO Implement all the tests
void test(char* word, int expected)
{
}

int main(void)
{
  struct ArrayList mi_arreglo = allocate(10);

  for (int i = 0; i < mi_arreglo.size; i++){
    push_back(&mi_arreglo, i);
  }

  printf("\n------Array of 10 elements---------------\n");

  for (int i = 0; i < mi_arreglo.size; i++){
    printf("%d  ", mi_arreglo.array[i]);
  }

  printf("\n------Array after add 10 elements at the end-------------\n");

  for (int i = 10; i < 20; i++){
    push_back(&mi_arreglo, i);
  }

  for (int i = 0; i < mi_arreglo.size; i++){
    printf("%d  ", mi_arreglo.array[i]);
  }

  add(&mi_arreglo, 4, 30);
  add(&mi_arreglo, 4, 40);
  add(&mi_arreglo, 0, 50);

  printf("\n---------Array afert insert in 4-------------\n");
  for (int i = 0; i < mi_arreglo.size; i++){
    printf("%d  ", mi_arreglo.array[i]);
  }
  printf("\nArreglo: %d", mi_arreglo.size);
  delete(&mi_arreglo, 4);
  printf("\n---------Array after delet in pos 4-------------\n");
  for (int i = 0; i < mi_arreglo.size; i++){
    printf("%d  ", mi_arreglo.array[i]);
  }
  printf("\nArreglo: %d", mi_arreglo.size);
  deallocate(&mi_arreglo);
}

