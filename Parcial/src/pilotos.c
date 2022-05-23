/*
 * pilotos.c
 *
 *  Created on: 23 may. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilotos.h"

int listarPilotos(ePiloto pilotos[], int tam){
int todoOk = 0;

    if(pilotos != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Sectores  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %5d    %s    %c\n", pilotos[i].id, pilotos[i].nombre, pilotos[i].sexo);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int buscarPilto(ePiloto pilotos[], int tam, int id, int* pIndice)
{
    int todoOk = 0;
    if(pilotos != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(pilotos[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarPilotos(ePiloto pilotos[], int tam, int id)
{
    int esValido = 0;
    int indice;

    buscarPiloto(pilotos, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int cargarDescripcionPilotos(ePiloto pilotos[], int tam, int id, char nombre[]){
int todoOk = 0;
int indice;

    buscarPiloto(pilotos,tam, id,&indice);

    if(pilotos != NULL && indice != -1 ){
       strcpy(pilotos, pilotos[indice].nombre);
       todoOk = 1;
    }
  return todoOk;
}
