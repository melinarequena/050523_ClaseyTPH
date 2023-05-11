//
// Created by Administrador on 11/5/2023.
//

#ifndef INC_050523PAVON_DEPOSITO_H
#define INC_050523PAVON_DEPOSITO_H

typedef struct nodo{
    int codigo;
    int volumen;
    char destino[30];
    struct nodo * sig;
}Nodo;

typedef struct deposito{
    char nombre[30];
    Nodo * primero;
    Nodo * ultimo;
}Deposito;

Deposito * newDeposito (char * nombre);
Nodo * newNodo(int codigo, int volumen, char * destino);
void ingresar(Deposito * deposito, Nodo * nodo);
Nodo * entregar(Deposito * deposito); //no se
#endif //INC_050523PAVON_DEPOSITO_H
