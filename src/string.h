#include <stdio.h>
typedef struct string string;

struct string {
  char* str;
  size_t size;
};

string init(size_t size);
string* concat(string* dst, string* src);
string* push_back_string(string* dst, char* src);
