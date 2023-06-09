//Se cuenta con un depósito (nombre) que recibe paquetes (nodos) y luego los entrega.
//Los paquetes al ingresar sobre en la puerta A, se los lleva lo más cercano posible a la puerta de entrega B.
//Para retirar, siempre se entrega el paquete más próximo a la puerta B.

//TPH: Relizar los comportamientos para: 1. ingresarPrioridad (lo deja en la puerta B) 2. entregaEspecial (retirar un
//paquete con un código específico)

#include<stdio.h>

#include "Deposito.h"


int main(){
    int codmanu;
    Deposito * depo = newDeposito("MeliCentral");

    entregar(depo);

    ingresar(depo, newNodo(1,1, 5, "FIE"));
    ingresar(depo, newNodo(0, 2,  3, "Casa"));
    ingresar(depo, newNodo(0, 3, 4, "Trabajo"));

    printf("Ingrese codigo para retirar manualmente\n");
    scanf("%d", &codmanu);

    Nodo * codmanual = entregar_xcod_tph(depo, codmanual, codmanu);
    Nodo * prioridad = entregar_prioridad_tph(depo, prioridad);

    printf("Se entrego el paquete %d manualmente por codigo\n", codmanual->codigo);
    printf("Se entrego el paquete %d por ser de prioridad\n", prioridad->codigo);

    Nodo * retiro = entregar(depo);
    printf("\nEl paquete de codigo %d salio hacia %s", retiro->codigo, retiro->destino);

    entregar(depo);

    retiro = entregar(depo);

    printf("\nEl paquete de codigo %d, salio hacia %s", retiro->codigo, retiro->destino);


    return 0;
}
