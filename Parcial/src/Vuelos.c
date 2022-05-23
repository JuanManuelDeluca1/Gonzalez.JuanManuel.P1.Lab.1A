
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


void mostrarVuelos(eVuelos e)
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
                mostrarVuelos(vec[i]);
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

int altaVuelo(eVuelos vec[], int tam,eAvion avion[], int tama,eDestino destino[] ,int tamd,ePiloto pilotos, int tamp, int* pLegajo)
{
    int todoOk = 0;
    int indice;
    int idAvion;
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

            	listarAvion(vec, tam, pilotos, tamp);

                printf("Ingrese el id del Avion: \n");
                fflush(stdin);
                scanf("%d", &idAvion);

                for(int i=0; i < tam; i++)
                {
                	if(avion[i].id != idAvion)
                	{
                		 printf("Id inexistente, ingrese el id del Avion: \n");
                         fflush(stdin);
                		 scanf("%d", &idAvion);
                	}
                	break;
                }
                nuevoVuelo.idAvion = idAvion;

                listarDestino(destino, tamd);

                printf("Ingrese el id del tipo de vuelo: \n");
                fflush(stdin);
                scanf("%d", &nuevoVuelo.idDestino);

                while( nuevoVuelo.idDestino > 20003 ||  nuevoVuelo.idDestino  < 20000)
                {
                    printf("No exite el id del tipo de vuelo. Reingrese el id: \n");
                    scanf("%d", & nuevoVuelo.idDestino);
                }
                printf("Ingrese Fecha ingreso dd/mm/aaaa: \n");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                //validarFecha(fecha, tam);
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
int listarVulosConAvion(eVuelos vec[], int tam, int idAvion)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
    	printf("          *** Listado de Vuelos ***\n\n");
    	printf(" id          idAvion        idDestino    F.Ingreso\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
        	if(!vec[i].isEmpty && vec[i].idAvion == idAvion)
        	{
        		mostrarVuelos(vec[i]);
        	}
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}
int vuelosDeUnAvion(eVuelos vec[], eAvion avion[], int tam, ePiloto pilotos, int tamp)
{
	int todoOk = 0;
	int idAvion;
	if(vec != NULL && avion != NULL && tam > 0 )
	{
		listarAvion(vec, tam, pilotos, tamp);

		printf("Ingrese el id del Avion: \n");
		fflush(stdin);
		scanf("%d", &idAvion);

		for(int i=0; i < tam; i++)
		{
			if(avion[i].id != idAvion)
			{
				printf("Id inexistente, ingrese el id del Avion: \n");
				fflush(stdin);
				scanf("%d", &idAvion);
			}
			break;
		}
		for(int i=0; i < tam; i++)
		{
			if(idAvion == vec[i].idAvion)
			{
				 listarVulosConAvion(vec, tam, idAvion);
			}
		}
		todoOk=1;
	}
	return todoOk;
}
/*int costosDeUnAvion(eVuelos vec[], eAvion avion[], int tam)
{
	int todoOk = 0;
	int idAvion;
	int contadorPrecio;
	int contadorVuelos = 0;
	if(vec != NULL && avion != NULL && tam > 0 )
	{
		listarAvion(avion, tam);

		printf("Ingrese el id del Avion: \n");
		fflush(stdin);
		scanf("%d", &idAvion);

		for(int i=0; i < tam; i++)
		{
			if(avion[i].id != idAvion)
			{
				printf("Id inexistente, ingrese el id del Avion: \n");
				fflush(stdin);
				scanf("%d", &idAvion);
			}
			break;
		}
		for(int i=0; i < tam; i++)
		{
			if(idAvion == vec[i].idAvion)
			{
				contadorVuelos++;
				if()

			}
		}
		todoOk=1;
	}
	return todoOk;
}*/

int listarAvionConDestinos(eVuelos vec[], int tam, int idDestino)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
    	printf("          *** Listado de Vuelos ***\n\n");
    	printf(" id          idAvion        idDestino    F.Ingreso\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
        	if(!vec[i].isEmpty && vec[i].idDestino == idDestino)
        	{
        		mostrarVuelos(vec[i]);
        	}
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarAvionPorDestino(eVuelos vec[], int tam, eDestino destinos[], int tamd)
{
	int todoOk = 0;
	int idDestino;
	if(vec != NULL && destinos != NULL && tam > 0 && tamd > 0)
	{
		listarDestino(destinos, tamd);

		printf("Ingrese el id del destino que quiera saver los aviones que fueron: \n");
		fflush(stdin);
		scanf("%d", &idDestino);

		for(int i=0; i < tam; i++)
		{
			if(destinos[i].id != idDestino)
			{
				printf("Id inexistente, ingrese el id del destino: \n");
				fflush(stdin);
				scanf("%d", &idDestino);
			}
			break;
		}
		for(int i=0; i < tam; i++)
		{
			if(idDestino == vec[i].idDestino)
			{
				listarAvionConDestinos(vec, tam, idDestino);
			}
		}
		todoOk=1;
	}
	return todoOk;
}

int listarVuelosConFechas(eVuelos vec[], int tam, int fechadia, int fechames, int fechaanio)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
    	printf("          *** Listado de Vuelos ***\n\n");
    	printf(" id          idAvion        idDestino    F.Ingreso\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
        	if(!vec[i].isEmpty && fechadia == vec[i].fIngreso.dia && fechames == vec[i].fIngreso.mes && fechaanio == vec[i].fIngreso.anio)
        	{
        		mostrarVuelos(vec[i]);
        	}
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarVuelosPorFecha(eVuelos vec[], int tam)
{
	int todoOk = 0;
	int fechadia;
	int fechames;
	int fechaanio;
	if(vec != NULL && tam > 0 )
	{

		printf("Ingrese una fecha para ver los vuelos: \n");
		fflush(stdin);
		scanf("%d/%d/%d", &fechadia, &fechames, &fechaanio);

		for(int i=0; i < tam; i++)
		{
			if(fechadia == vec[i].fIngreso.dia && fechames == vec[i].fIngreso.mes && fechaanio == vec[i].fIngreso.anio)
			{
				listarVuelosConFechas(vec, tam, fechadia, fechames, fechaanio);
			}
		}
		todoOk=1;
	}
	return todoOk;
}


