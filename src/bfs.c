#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"

#define ROWS 10
#define COLS 10

arraylist(char)
arraylist(ArrayList_char)
extension(char)

typedef struct tupla tupla;
struct tupla {
  int ff;
  int ss;
};

void bfs()
{
  tupla parent[ROWS][COLS];
  ArrayList_ArrayList_char map;

  for (int i = 0; i < ROWS; i++) {
    char tmp[COLS];
    scanf("%s", tmp);
    ArrayList_char str = set_array_char(tmp, strlen(tmp));
    push_back_arraymatrix_char(&map,&str, true);
  }

  for (int i = 0; i < ROWS;  i++) {
    for (int j = 0; j < COLS;  j++) {
      parent[i][j].ff = -1;
      parent[i][j].ss = -1;
    }
  }
}

int main(void)
{
  bfs();
}
