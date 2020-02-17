
#include "alloc.h"
#include <string.h>

void* mylloc(unsigned long long tam) {
   void* ptr = malloc(tam);
   if (ptr == NULL) {
      exit(EXIT_FAILURE);
   }
   memset(ptr, 0, tam);
   return ptr;
}

