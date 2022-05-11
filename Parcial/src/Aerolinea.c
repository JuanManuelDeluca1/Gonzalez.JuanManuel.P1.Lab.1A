/*
 * Aerolinea.c
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aerolinea.h"



int listarAerolinea(eAerolinea aerolineas[], int tam){
int todoOk = 0;

    if(aerolineas != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Aerolinea  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", aerolineas[i].id, aerolineas[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarAerolinea(aerolineas,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, aerolineas[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarAerolinea(eAerolinea aerolineas[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(aerolineas != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(aerolineas[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarAerolinea(eAerolinea aerolineas[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarAerolinea(aerolineas, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}






