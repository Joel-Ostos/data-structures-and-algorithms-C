#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include <stdlib.h>

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
  void push_back_##type(LinkedList_##type* list, type data)		\
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
  
#endif
