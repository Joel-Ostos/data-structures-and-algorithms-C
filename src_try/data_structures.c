#include "data_structures.h"
#include <stdio.h>
#include <stdlib.h>

d_linked init_doubly_linked()
{
  return (d_linked){NULL, NULL, 0};
}

s_linked init_single_linked()
{
  return (s_linked){NULL, NULL, 0};
}

s_node* create_s_node(void* data)
{
  s_node* node = (s_node*) malloc(sizeof(s_node));
  node->next = NULL;
  node->data = data;
  return node;
}

d_node* create_d_node(void* data)
{
  d_node* node = (d_node*) malloc(sizeof(s_node));
  node->next = NULL;
  node->prev = NULL;
  node->data = data;
  return node;
}

void push_back_s_linked(s_linked* list, void* data)
{
  s_node* node = create_s_node(data);
  if (list->head) {
    list->head->next = node;
    list->head = node;
    list->size++;
  }
  list->head = node;
  list->tail = node;
  list->size++;
}

void push_back_d_linked(d_linked* list, void* data)
{
  d_node* node = create_d_node(data);
  if (list->head) {
    node->prev = list->head;
    list->head->next = node;
    list->head = node;
    list->size++;
    return;
  } 
  list->head = node;
  list->tail = node;
  list->size++;
}

void insert_s_linked(s_linked* list, void* data, size_t index)
{
  size_t cont = 0;
  s_node* current = list->tail;
  s_node* node = create_s_node(data);
  if (index == 0) {
    node->next = list->tail;
    list->tail = node;
    list->size++;
    return;
  }

  if (index == list->size-1){
    list->head->next = node;
    list->head = node;
    list->size++;
    return;
  }
    
  while (current) {
    if (cont+1 == index){
      current->next = node;
      list->size++;
    }
    current = current->next;
    cont++;
  }
}

void insert_d_linked(d_linked* list, void* data, size_t index)
{
  d_node* node = create_d_node(data);
  if (index == 0) {
    list->tail->prev = node;
    node->next = list->tail;
    list->tail = node;
    list->size++;
    return;
  }

  if (index == (list->size)-1){
    list->head->next = node;
    node->prev = list->head;
    list->head = node;
    list->size++;
    return;
  }
  
  d_node* current = list->tail;
  size_t cont = 0;
  while (current) {
    if (cont == index) {
      d_node* tmp = current->prev;
      current->prev = node;
      node->prev = tmp;
      tmp->next = node;
      node->next = current;
      list->size++;
      break;
    }
    current = current->next;
    cont++;
  }
}

void* delete_s_linked(s_linked* list, size_t index);

void* delete_d_linked(d_linked* list, size_t index);

void* find_s_linked(s_linked* list, void* target);

void* find_d_linked(d_linked* list, void* target);

void print_s_list(s_linked* list, void(*print)(void*))
{
  s_node* current = list->tail;
  while (current) {
    print(current->data);
    current = current->next;
  }
}

void print_d_list(d_linked* list, void(*print)(void*))
{
  d_node* current = list->tail;
  while (current) {
    print(current->data);
    current = current->next;
  }
}

void print_int(void* data)
{
  printf("%d ", *(int*) data);
}

void print_char(void* data)
{
  printf("%c ", *(char*) data);
}

void print_string(void* data)
{
  printf("%s ", *(char**) data);
}

void print_float(void* data)
{
  printf("%f ", *(float*) data);
}
