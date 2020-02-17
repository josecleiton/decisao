#include "decisao.h"

int main() {
   Arvore* arv = criarArv();
   escolheFila(arv, 1, 4);
   escolheFila(arv, 2, 4);
   escolheFila(arv, 3, 4);
   escolheFila(arv, 4, 4);
   escolheFila(arv, 5, 4);
   escolheFila(arv, 6, 4);
   escolheFila(arv, 7, 4);
   escolheFila(arv, 8, 4);
   escolheFila(arv, 9, 4);
   escolheFila(arv, 10, 4);
   escolheFila(arv, 7, 10);
   escolheFila(arv, 8, 10);
   escolheFila(arv, 9, 10);

   liberaArvore(arv);
   return 0;
}
