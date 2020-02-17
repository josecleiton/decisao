#ifndef DECISAO
#define DECISAO
// Nossa fila
typedef struct _nodo {
   int priority, ttl;
   struct _nodo* prox;
} Nodo;

// Nossa arvore
// O id será um identificador da fila a inserir
// já que temos um intervalo [1, 3], [4, 6] e [7, 10]
// id 1 é o primeiro intervalo e assim por diante
typedef struct _arv {
   int id;
   Nodo* fila;
   struct _arv *esq, *dir;
} Arvore;

void inserirFila(Nodo* fila, int n1, int n2);
Arvore* criarArv(void);
Arvore* buscaArvore(Arvore* raiz, int id);
int calculaID(int priority, int ttl);

Nodo* escolheFila(Arvore* raiz, int priority, int ttl);

void liberaArvore(Arvore* raiz);
void liberaFila(Nodo* ini);

#endif