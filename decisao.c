#include "decisao.h"

#include <stdio.h>

#include "alloc.h"

/*
 * Inserção na árvore
 */
Arvore* inserirArv(Arvore* raiz, int id) {
   if (raiz == NULL) {
      raiz = (Arvore*)mylloc(sizeof(Arvore));
      raiz->id = id;
   } else {
      if (id < raiz->id) {
         raiz->esq = inserirArv(raiz->esq, id);
      } else {
         raiz->dir = inserirArv(raiz->dir, id);
      }
   }
   return raiz;
}

/**
 * Cria Árvore balanceada
 *             2
 *            / \
 *           1   4
 *              / \
 *             3   5
 */
Arvore* criarArv(void) {
   Arvore* raiz = inserirArv(NULL, 2);
   raiz = inserirArv(raiz, 1);
   raiz = inserirArv(raiz, 4);
   raiz = inserirArv(raiz, 3);
   raiz = inserirArv(raiz, 5);
   return raiz;
}

/**
 * Calcula chave (id) da arvore baseado na prioridade e no ttl
 */
int calculaID(int priority, int ttl) {
   if (priority < 7) {
      if (priority <= 3) {
         return 1;
      } else {
         return 2;
      }
   } else if (ttl <= 7) {
      return 3;
   }
   return 4;
}

/**
 * Escolhe a fila baseado na prioridade e ttl
 */
Nodo* escolheFila(Arvore* raiz, int priority, int ttl) {
   int id = calculaID(priority, ttl);
   printf("Escolhi o nó %d da árvore\n", id);
   Arvore* no = buscaArvore(raiz, id);
   if (no != NULL) {
      inserirFila(no->fila, priority, ttl);
      return no->fila;
   }
   return NULL;
}

/**
 * Busca em ordem baseado na chave (id)
 */
Arvore* buscaArvore(Arvore* raiz, int id) {
   if (raiz != NULL) {
      if (id < raiz->id) {
         return buscaArvore(raiz->esq, id);
      } else if (id > raiz->id) {
         return buscaArvore(raiz->dir, id);
      }
      return raiz;
   }
   return NULL;
}

void inserirFila(Nodo* fila, int priority, int ttl) {

}

void liberaArvore(Arvore* raiz) {
   if (raiz != NULL) {
      liberaArvore(raiz->esq);
      liberaArvore(raiz->dir);
      liberaFila(raiz->fila);
      free(raiz);
   }
}

void liberaFila(Nodo* ini) {
   if (ini != NULL) {
      liberaFila(ini->prox);
      free(ini);
   }
}
