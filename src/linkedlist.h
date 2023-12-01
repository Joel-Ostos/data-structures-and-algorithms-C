#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define linkedlist(type)						\
  typedef struct LinkedList_##type LinkedList_##type;			\
  typedef struct Node_##type Node_##type;				\
  struct Node_##type {							\
    type data;								\
    Node_##type* next;							\
    Node_##type* prev;							\
  };									\
  struct LinkedList_##type {						\
    Node_##type* head;							\
    Node_##type* tail;							\
    size_t size;							\
  };									\
  static Node_##type* create_node_##type(type data)			\
  {									\
    Node_##type* node = (Node_##type*)malloc(sizeof(Node_##type));	\
    node->data = data;							\
    node->next = NULL;							\
    node->prev = NULL;							\
    return node;							\
  }									\
  LinkedList_##type init_list_##type()					\
  {									\
    return (LinkedList_##type){						\
      .head = NULL,							\
      .tail = NULL,							\
      .size = 0,							\
    };									\
  }									\
  void push_back_list_##type(LinkedList_##type* list, type data)	\
  {									\
    Node_##type* node = create_node_##type(data);			\
    if (!list->head) {							\
      list->head = node;						\
      list->tail = node;						\
      list->size++;							\
      return;								\
    }									\
    list->head->next = node;						\
    node->prev = list->head;						\
    list->head = node;							\
    list->size++;							\
  }									\
  void delete_node_list_##type(LinkedList_##type* list, size_t index)	\
  {									\
    size_t cont = 0;							\
    if (index != 0 && index <= list->size/2) {				\
      Node_##type* current = list->tail;				\
      while (current){							\
	if (cont == index){						\
	  current->prev->next = current->next;				\
	  current->next->prev = current->prev;				\
	  free(current);						\
	  return;							\
	}								\
	cont++;								\
	current = current->next;					\
      }									\
      return;								\
    } else if (index != list->size-1 && index > list->size/2) {	\
      Node_##type* current = list->head;				\
      cont = (list->size-1)-index;					\
      while (current){							\
	if (cont == index){						\
	  current->prev->next = current->next;				\
	  current->next->prev = current->prev;				\
	  free(current);						\
	  return;							\
	}								\
	cont++;								\
	current = current->prev;					\
      }									\
      return;								\
    } else if (index == 0){						\
      Node_##type* tmp = list->tail->next;				\
      free(list->tail);							\
      list->tail = tmp;							\
    }									\
    Node_##type* tmp = list->head->prev;				\
    free(list->tail);							\
    list->head = tmp;							\
  }									\
  void deinit_list_##type(LinkedList_##type* list) {			\
    Node_##type* current = list->tail;					\
    while (current) {							\
      Node_##type* tmp = current->next;					\
      free(current);							\
      current = tmp;							\
    }									\
  }									\

#define arraylist(type)							\
  typedef struct ArrayList_##type ArrayList_##type;			\
  struct ArrayList_##type {						\
    type* array;							\
    size_t capacity;							\
    size_t occupied;							\
    bool state;								\
  };									\
  ArrayList_##type init_array_##type(size_t initial_size)		\
  {									\
    type* arr = (type*) malloc(sizeof(type)*initial_size+1);		\
    return (ArrayList_##type) {						\
      .array = arr,							\
      .capacity = initial_size,						\
      .occupied = 0,							\
      .state = true,							\
    };									\
  }									\
  ArrayList_##type set_array_##type(type* arr, size_t initial_size)	\
  {									\
    return (ArrayList_##type) {						\
      .array = arr,							\
      .capacity = initial_size,						\
      .occupied = 0,							\
      .state = false,							\
    };									\
  }									\
  void push_back_array_##type(ArrayList_##type* array, type data)	\
  {									\
    if (array->state){							\
      if (array->occupied < array->capacity) {				\
	array->array[array->occupied] = data;				\
	array->occupied += 1;						\
	return;								\
      }									\
      array->array = realloc(array->array,(array->capacity + 1) * sizeof(type)); \
      array->array[array->occupied] = data;				\
      array->occupied += 1;						\
      array->capacity += 1;						\
      return;								\
    }									\
    if (array->occupied < array->capacity) {				\
      array->array[array->occupied] = data;				\
      array->occupied += 1;						\
      return;								\
    }									\
    type* new = (type*) malloc(sizeof(type) * (array->capacity+1));	\
    array->array = memcpy(new, array->array, sizeof(type) * array->capacity); \
    array->array[array->occupied] = data;				\
    array->occupied += 1;						\
    array->capacity += 1;						\
    array->state = true;						\
    return;								\
  }									\
  void insert_array_##type(ArrayList_##type* array, type data, size_t index) \
  {									\
    if (array->occupied < array->capacity && index <= array->occupied) { \
      type* new = (type*) malloc(sizeof(type) * array->capacity);	\
      memcpy(new, array->array, sizeof(type) * index);			\
      memcpy(new+index, array->array+index-1, sizeof(type) * (array->capacity-index)+1); \
      new[index] = data;						\
      free(array->array);						\
      array->array = NULL;						\
      array->array = new;						\
      array->occupied += 1;						\
      return;								\
    }else if (array->occupied == array->capacity && index <= array->occupied){ \
      type* new = (type*) malloc(sizeof(type) * array->capacity+1);	\
      memcpy(new, array->array, sizeof(type) * index);			\
      memcpy(new+index, array->array+index-1, sizeof(type) * (array->capacity-index)+1); \
      new[index] = data;						\
      free(array->array);						\
      array->array = NULL;						\
      array->array = new;						\
      array->occupied += 1;						\
      array->capacity += 1;						\
      return;								\
    }									\
  }									\
  void delete_array_##type(ArrayList_##type* array, size_t index)	\
  {									\
    if (array->occupied <= array->capacity && index <= array->occupied) { \
      memcpy(array->array+index, array->array+index+1, sizeof(type) * (array->capacity-index)); \
      array->occupied -= 1;						\
      return;								\
    }									\
  }									\
  void deinit_array_##type(ArrayList_##type* array)			\
  {									\
    free(array->array);							\
    array->array = NULL;						\
  }									\

#endif
// TODO on line 105: Design Decision, Bitacora TODO (1)
