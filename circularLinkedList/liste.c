#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

/*
Scambia di posto due elementi all'interno della lista
restituisce il secondo elemento
*/
struct nodo *swap(struct nodo *tmp1,struct nodo *tmp2){
    //struct nodo *tmp3;
    (tmp2->prev)->next = tmp2->next;
    (tmp2->next)->prev = tmp2->prev;

    tmp2->next = tmp1;
    tmp2->prev = tmp1->prev;

    (tmp1->prev)->next = tmp2;
    tmp1->prev = tmp2;
    return tmp2;
}
/*
Verifica se la lista in questione è vuota oppure no;
Restituisce 0 se la lista non è vuota 1 se la lista è vuota;
*/
int isEmpty(struct nodo *lista){
    int res = 0;
    if(lista->next == lista) res = 1;
    return res;
}

//Crea una lista contenente unicamente il valore sentinella
struct nodo *creaLista(){
    struct nodo *sentinella = NULL;
    sentinella = (struct nodo *)malloc(sizeof(struct nodo));
    sentinella->prev = sentinella;
    sentinella->next = sentinella;
    return sentinella;
}
/*
La procedura inserisce un elemento in testa sia che la lista sia vuota, sia che la lista abbia contenga altri elementi
Viene utilizzata la funzione isEmpty per semplificare il controllo
*/
void insInTesta(struct nodo *lista,int k){
    struct nodo *top = NULL;
    struct nodo *tmp = (struct nodo *)malloc(sizeof(struct nodo));
    tmp->data = k;//inizializzo il valore del nuovo elemento

    if(isEmpty(lista)){
        lista->prev = tmp;
        lista->next = tmp;
        tmp->prev = lista;
        tmp->next = lista;
    }
    else{
        top = lista->next;
        top->prev = tmp;
        tmp->prev = lista;
        tmp->next = top;
        lista->next = tmp;
    }
    return;
}
/*
La procedura inserisce un elemento in coda sia che la lista sia vuota sia che la lisa contenga altri elementi
Viene utilizzata la funzione isEmpty per semplificare il tutto
*/
void insInCoda(struct nodo *lista,int k){
    struct nodo *last = NULL;
    struct nodo *tmp = (struct nodo *)malloc(sizeof(struct nodo));
    tmp->data = k;

    if(isEmpty(lista)){
        lista->prev = tmp;
        lista->next = tmp;
        tmp->next = lista;
        tmp->prev = lista;
    }
    else{
        last = lista->prev;
        last->next = tmp;
        tmp->prev = last;
        lista->prev = tmp;
        tmp->next = lista;
    }
}
/*
La procedura inserisce un elemento in ordine, se la lista è vuota, ovvero continene solo il valore sentinella, lo inserisce in testa
*/
void insInOrdine(struct nodo *lista, int k){
        struct nodo *tmp = (struct nodo *)malloc(sizeof(struct nodo *));
        struct nodo *top = lista->next;
        tmp->data = k;
        while(top!=lista && top->data < k){
            top = top->next;
        }
        tmp->next = top;
        tmp->prev = top->prev;
        top->prev->next = tmp;
        top->prev = tmp;

}
//Stampa una lista circolare
void stampaLista(struct nodo *lista){
    struct nodo *tmp = lista->next;

    if(isEmpty(lista)){
        printf("\tLa lista e' vuota;\n");
    }
    else{
        while(tmp!=lista){
            printf("%4d",tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
}
/*
Cancella l'intera lista tranne l'elemento fittizio
*/
void cancellaLista(struct nodo *lista){
    struct nodo *tmp = lista->next;
    while(tmp!=lista){
        lista->next = tmp->next;
        tmp->next->prev = lista;
        free(tmp);
        tmp = lista->next;
    }
}
/*
Cancella un elemento e le sue ripetizioni
*/
void cancellaElemento(struct nodo *lista,int k){
    struct nodo *tmp = NULL;
    struct nodo *top = lista->next;

    while(top!=lista){
        if(top->data == k){
            tmp = top;
            (top->next)->prev = top->prev;
            (top->prev)->next = top->next;
            free(tmp);
        }
        top = top->next;
    }
}
/*
Ordina una lista in ordine crescente
*/
void ordinaCrescente(struct nodo *top){
    struct nodo *tmp = NULL;
    struct nodo *rmp = top->next;

    while(rmp != top){
        tmp = rmp;
        while(tmp != top){
            if(rmp->data > tmp->data){
                rmp = swap(rmp,tmp);
            }
            tmp = tmp->next;
        }
        rmp = rmp->next;
    }
    return;
}
/*
Ordina una lista in ordine decrescente
*/
void ordinaDecrescente(struct nodo *top){
    struct nodo *tmp = NULL;
    struct nodo *rmp = top->next;

    while(rmp != top){
        tmp = rmp;
        while(tmp != top){
            if(rmp->data < tmp->data){
                rmp = swap(rmp,tmp);
            }
            tmp = tmp->next;
        }
        rmp = rmp->next;
    }
    return;
}
/*
La vunzione cerca un elemento all'interno della lista
restituisce 1 se lo trova 0 altrimenti
*/
int cercaElemento(struct nodo *lista, int k){
    struct nodo *tmp = lista->next;
    int ris = 0;
    while(tmp != lista && ris == 0){
        if(tmp->data == k) ris = 1;
        tmp = tmp->next;
    }
    return ris;
}
