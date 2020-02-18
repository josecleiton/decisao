
#include "alloc.h"

#include <string.h>

void* mylloc(size_t tam) {
   void* ptr = calloc(1, tam);
   if (ptr == NULL) {
      exit(EXIT_FAILURE);
   }
   return ptr;
}

