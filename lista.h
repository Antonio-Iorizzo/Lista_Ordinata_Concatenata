#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

struct lista {
    Nodo *head;
    int contatore;
};
typedef struct lista Lista;

void init(Lista *l);
void stampa(Lista *l);
void inserisci(Lista *l, int val);
void rimuovi(Lista *l, int val);
void clear(Lista *l);

#endif