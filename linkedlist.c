#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
  struct node* back;
};

struct ll{
  size_t size;
  struct node* head;
  struct node* tail;
};

struct node* create_node(int d)
{
  struct node* node = (struct node*) malloc(sizeof(struct node));
  node->data = d;
  node->next = NULL;
  node->back = NULL;
  return node;
}

struct ll create_ll()  
{
  return (struct ll){.size = -1,
		     .head = NULL,
		     .tail = NULL,};
}

void push_back(struct ll* list, int n)
{
  struct node* node = create_node(n);
  if (list->head == NULL){
    list->head = node;
    list->tail = node;
    list->size += 1;
    return;
  }
  list->head->next = node;
  node->back = list->head;
  list->head = node;
  list->size+=1;
}

void print_list(struct ll* list)
{
  struct node* current = list->tail;
  while (current){
    printf("%d ", current->data);
    current = current->next;
  }
}

void deinit(struct ll* list)
{
  struct node* current = list->tail;
  while (1){
    if (current == NULL){
      break;
    }
    struct node* tmp = current;
    current = current->next;
    free(tmp);
  }
}

int delete_by_name(struct ll* list, int index)
{
  if (list->head && index > 0 && index < list->size-1){
    struct node* curr = list->tail;
    int cont = 0;
    while (curr && cont < list->size){
      if (cont == index && cont != 0 && cont != list->size-1){
	int tmp = curr->data;
	curr->back->next = curr->next;
	curr->next->back = curr->back;
	list->size -=1;
	free(curr);
	return tmp;
      }
      curr = curr->next;
      cont++;
    }
  }else{
    if (list->size < 0) printf("La lista está vacía");
    else printf("Index out of range");
    return -1;
  }
}

int main(void)
{
  struct ll my = create_ll();

  for (long long i = 0; i < 10; i++){
    push_back(&my,i);
  }
  int d = delete_by_name(&my, 2);
  printf("%d\n", d);
  print_list(&my);
  printf("\n-----------\n");
  print_list(&my);
  deinit(&my);
}
