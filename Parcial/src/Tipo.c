/*
 * Tipo.c
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipo.h"



int listarTipo(eTipo tipos[], int tam){
int todoOk = 0;

    if(tipos != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Tipos  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarTipo(tipos,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, tipos[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarTipo(eTipo tipos[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(tipos != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(tipos[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarTipo(eTipo tipos[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarTipo(tipos, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}




