/*
 * Destinos.c
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Destinos.h"



int listarDestino(eDestino destinos[], int tam){
int todoOk = 0;

    if(destinos != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Destino  ***\n");
        printf("  Id    Descripcion    Precio\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %s    $%.2f\n", destinos[i].id, destinos[i].descripcion, destinos[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionDestino(eDestino destinos[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarDestino(destinos,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, destinos[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarDestino(eDestino destinos[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(destinos != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(destinos[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarDestino(eDestino destinos[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarDestino(destinos, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}








