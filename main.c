#include <stdio.h>
#include "lista.h"

int main()
{
    Lista l;

    init(&l);
    stampa(&l);

    inserisci(&l, 15);
    stampa(&l);

    inserisci(&l, 8);
    stampa(&l);

    inserisci(&l, 3);
    stampa(&l);

    inserisci(&l, 6);
    stampa(&l);

    inserisci(&l, 5);
    stampa(&l);

    rimuovi(&l, 3);
    stampa(&l);

    rimuovi(&l, 8);
    stampa(&l);

    rimuovi(&l, 19);

    rimuovi(&l, 15);
    stampa(&l);

    clear(&l);
    
    return 0;
}