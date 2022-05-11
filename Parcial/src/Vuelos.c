/*
 * Vuelos.c
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Vuelos.h"
#include "Destinos.h"
#include "Avion.h"
#include "fecha.h"


void mostrarVuelos(eVuelos e, int tam)
{

        printf("  %d       %d       %d      %02d/%02d/%d \n",e.id,e.idAvion,e.idDestino,e.fIngreso.dia,e.fIngreso.mes,e.fIngreso.anio);

}


int listarVuelos(eVuelos vec[], int tam)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("          *** Listado de Vuelos ***\n\n");
        printf(" id          idAvion        idDestino    F.Ingreso\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarVuelos(vec[i], tam);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay empleados en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int inicializarVuelos(eVuelos vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}




int buscarVuelosLibre(eVuelos vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
int buscarVuelos(eVuelos vuelos[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(vuelos!= NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(vuelos[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarVuelos(eVuelos vuelos[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarVuelos(vuelos, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int altaVuelo(eVuelos vec[], int tam,eAvion avion[], int tama,eDestino destino[] ,int tamd, int* pLegajo)
{
    int todoOk = 0;
    int indice;
    eVuelos nuevoVuelo;
    eFecha fecha;


    if(vec != NULL && tam > 0 && pLegajo != NULL)
    {
        if( buscarVuelosLibre(vec, tam, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar

            	listarAvion(avion, tama);

                printf("Ingrese el id del Avion: ");
                fflush(stdin);
                scanf("%d", &nuevoVuelo.idAvion);

                while(nuevoVuelo.idAvion <= 10000 &&  nuevoVuelo.idAvion  >= 10301 )
                {
                    printf("No exite el id de la Avion. Reingrese el id: ");
                    scanf("%d", &nuevoVuelo.idAvion);
                }

                listarDestino(destino, tamd);

                printf("Ingrese el id del tipo de vuelo: ");
                fflush(stdin);
                scanf("%d", &nuevoVuelo.idDestino);

                while( nuevoVuelo.idDestino <= 20000 &&  nuevoVuelo.idDestino  >= 20003)
                {
                    printf("No exite el id del tipo de vuelo. Reingrese el id: ");
                    scanf("%d", & nuevoVuelo.idDestino);
                }
                printf("Ingrese Fecha ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                nuevoVuelo.fIngreso = fecha;

                nuevoVuelo.isEmpty = 0;
                nuevoVuelo.id = *pLegajo;
                *pLegajo = *pLegajo + 1;
                vec[indice] = nuevoVuelo;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}



