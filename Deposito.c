//
// Created by Administrador on 11/5/2023.
//

#include "Deposito.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
Deposito * newDeposito(char * nombre){
    Deposito * auxDepo = malloc(sizeof(Deposito));
    if(auxDepo == NULL){
        printf("Error al asignar memoria\n");
        exit -1;
    }
    strcpy(auxDepo->nombre, nombre);
    auxDepo->primero = NULL;
    auxDepo->ultimo = auxDepo->primero;

    return auxDepo;
}

Nodo * newNodo(int codigo, int volumen, char * destino){
    Nodo * auxNodo = malloc(sizeof(Nodo));
    if(auxNodo == NULL){
        printf("Error al asignar memoria\n");
        exit -1;
    }
    auxNodo->codigo = codigo;
    auxNodo->volumen = volumen;
    strcpy(auxNodo->destino, destino);
    auxNodo->sig = NULL;

    return auxNodo;
}

void ingresar(Deposito * deposito, Nodo * nodo){
    if(deposito->primero == NULL){ //Si el 1° antes de B esta vacio
        deposito->primero = nodo; //llenar esa posicion
        deposito->ultimo = nodo; //llenar la posicion del ultimo
    }else {
        deposito->ultimo->sig = nodo;
        deposito->ultimo = nodo;
    }
}

Nodo * entregar(Deposito * deposito){
    if(deposito->primero == NULL){
        printf("\nDeposito vacio\n");
        return NULL; //DEVUELVE VACIO, NO DEVUELVE NADA

    }else {
        Nodo *aux = deposito->primero;
        deposito->primero = aux->sig;
        aux->sig = NULL;
        if (deposito->primero == NULL) {
            deposito->ultimo = NULL;
        }
        return aux;
    }
}