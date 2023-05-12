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

Nodo * newNodo(int prior, int codigo, int volumen, char * destino){
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

Nodo * entregar_prioridad_tph(Deposito * deposito, Nodo * nodo){
    if(deposito->primero == NULL){
        printf("Deposito vacio\n");
        return NULL;
    }else{
        //while(deposito->primero != NULL) {
            if (nodo->prior == 1) {
                printf("Entregar nodo por prioridad\n");
                Nodo *aux = deposito->primero;
                deposito->primero = aux->sig;
                aux->sig = NULL;
                if (deposito->primero == NULL) {
                    deposito->ultimo = NULL;
                }
                return aux;

            } else {
                printf("Nodo con codigo incorrecto/Nodo sin prioridad");

            }


    }
}

Nodo * entregar_xcod_tph(Deposito * deposito, Nodo * nodo, int codmanu /*(PPValor? Esta mal)*/){
    if(deposito->primero == NULL) {
        printf("Deposito vacio\n");
        return NULL;
    }else{
        if(nodo->codigo == codmanu){
            Nodo *aux = deposito->primero;
            deposito->primero = aux->sig;
            aux->sig = NULL;
            if (deposito->primero == NULL) {
                deposito->ultimo = NULL;
            }
            return aux;
            }else
                printf("No existen coincidencias\n");
        }
    }
