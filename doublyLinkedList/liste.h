/*
Raffaele Sarracino
*/
#ifndef LISTE_LIB_H
#define LISTE_LIB_H

struct nodo{
    int data;
    struct nodo *next;
    struct nodo *prev;
};

//verifica se la lista è vuota oppure no, usata per semplicità
int isEmpty(struct nodo *);
//Crea una lista costituita unicamente dal valore sentinella
struct nodo *creaNodo(int);
//Inserisce un elemento in testa alla lista
struct nodo *insInTesta(struct nodo *,int );
//Inserisce un elemento in coda alla lista o in testa se la lista è vuota
struct nodo *insInCoda(struct nodo *,int);
//inserisce un elemento in ordine oppure in testa se la lista è vuota
struct nodo *insInOrdine(struct nodo *,int);
//Stampa una lista doppiamente linkata
void stampaLista(struct nodo *);
//canella l'intera lista
struct nodo *cancellaLista(struct nodo *);
//cancella un elemento e le sue ripetiozioni
struct nodo *cancellaElemento(struct nodo*,int);
//ordina una lista in ordine crescente
struct nodo *ordinaCrescente(struct nodo*);
//ordina una lista in ordine crescente
struct nodo *ordinaDecrescente(struct nodo*);
//cerca un elemento nella lista
int cercaElemento(struct nodo *,int);
#endif
