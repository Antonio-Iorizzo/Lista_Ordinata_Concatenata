#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "nodo.h"

void init(Lista *l)
{
    l->head=NULL;
    l->contatore=0;
}

void stampa(Lista *l)
{
    Nodo *attuale=l->head;

    printf("[%d] ", l->contatore);

    while(attuale!=NULL){
        printf("%d\t ", attuale->val);
        attuale=attuale->next;
    }
    printf("NULL\n");
}

void inserisci(Lista *l, int val)
{
    Nodo *attuale=l->head;
    Nodo *prev=NULL;

    Nodo *temp=malloc(sizeof(Nodo));
    temp->val=val;
    temp->next=NULL;

    // ricerca dell'ultimo nodo con valore minore di quello da inserire 
    while(attuale!=NULL && attuale->val<val){
        prev=attuale;
        attuale=attuale->next;
    }

    if(prev==NULL) {
        // inserimento in testa
        temp->next=l->head;
        l->head=temp;
    }else{
        // inserimento dopo prev 
        prev->next=temp;
        temp->next=attuale;
    }
    l->contatore++;
}

void rimuovi(Lista *l, int val)
{
    Nodo *attuale=l->head;
    Nodo *prev=NULL;
    Nodo *temp=NULL;

    //ricerca dell'ultimo nodo con valore minore di quello da rimuovere
    while(attuale!=NULL && attuale->val<val){
        prev=attuale;
        attuale=attuale->next;
    }

    //l'elemento non e' stato trovato 
    if(attuale==NULL){
        printf("Elemento %d non trovato, non faccio nulla\n", val);
        return;
    }

    printf("Elemento %d trovato, lo elimino\n", val);
    l->contatore--;

    //se l'elemento da rimuovere e' in testa
    if(prev == NULL){
        printf("L'elemento da eliminare e' in testa, eliminazione\n");
        
        temp=l->head;           
        l->head=l->head->next;  
        free(temp);               
        return;
    }

    // se l'elemento da eliminare e' prev->next 
    printf("L'elemento da eliminare non e' in testa, eliminazione\n");
    temp=prev->next;
    prev->next=temp->next;
    free(temp);
}

void clear(Lista *l)
{
    Nodo *temp;
    Nodo *attuale=l->head;

    while(attuale!=NULL){
        temp=attuale;    
        attuale=attuale->next;
        
        printf("Svuotamento del nodo con valore %d\n", temp->val);
        free(temp);
    }

    l->head=NULL;
    l->contatore=0;
}