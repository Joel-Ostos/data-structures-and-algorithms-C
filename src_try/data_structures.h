#ifndef _DATASTRUCTURES_H_
#define _DATASTRUCTURES_H_
#include <stddef.h> 
/* Defining for the single and doubly linked list */
typedef struct single_linked s_linked;
typedef struct single_node s_node;
typedef struct doubly_linked d_linked;
typedef struct doubly_node d_node;

struct single_node {
  void* data;
  s_node* next;
};

struct single_linked {
  s_node* head;
  s_node* tail;
  size_t size;
};

struct doubly_node {
  void* data;
  d_node* next;
  d_node* prev;
};

struct doubly_linked {
  d_node* head;
  d_node* tail;
  size_t size;
};

extern d_linked init_doubly_linked();
extern s_linked init_single_linked();

extern d_node* create_d_node(void* data);
extern s_node* create_s_node(void* data);

extern void push_back_s_linked(s_linked* list, void* data);
extern void push_back_d_linked(d_linked* list, void* data);

extern void insert_s_linked(s_linked* list, void* data, size_t index);
extern void insert_d_linked(d_linked* list, void* data, size_t index);

extern void* delete_s_linked(s_linked* list,size_t index);
extern void* delete_d_linked(d_linked* list, size_t index);

extern void* find_s_linked(s_linked* list, void* target);
extern void* find_d_linked(d_linked* list, void* target);

extern void print_s_list(s_linked* list, void(*print)(void*));
extern void print_d_list(d_linked* list, void(*print)(void*));

extern void print_int(void* data);
extern void print_char(void* data);
extern void print_string(void* data);
extern void print_float(void* data);

#endif
