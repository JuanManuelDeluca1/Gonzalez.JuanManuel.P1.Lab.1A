/*
 * Avion.c
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Avion.h"
#include "Tipo.h"
#include "Aerolinea.h"

int inicializarAvion(eAvion vec[], int tam)
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




int buscarAvionLibre(eAvion vec[], int tam, int* pIndex)
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
int buscarAvion(eAvion vec[], int tam,int id, int* pIndex)
{
	int todoOk=-0;
	    if(vec != NULL && tam>0 && pIndex != NULL && id > 0)
		{
	    	*pIndex=-1;
			for(int i=0;i<tam;i++)
			{
				if(vec[i].isEmpty == 0 && vec[i].id == id)
				{
					*pIndex=i;
					break;
				}
			}
			todoOk=1;
		}
		return todoOk;
}
int altaAvion(eAvion vec[], int tam,eTipo tipos[], int tamt,eAerolinea aerolineas[] ,int tamae, int* pLegajo)
{
    int todoOk = 0;
    int indice;
    eAvion nuevoAvion;


    if(vec != NULL && tam > 0 && pLegajo != NULL)
    {
        if( buscarAvionLibre(vec, tam, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar

            	listarAerolinea(aerolineas, tamae);

                printf("Ingrese el id de la Aerolinea: ");
                fflush(stdin);
                scanf("%d", &nuevoAvion.idAerolinea);

                while(nuevoAvion.idAerolinea <= 5000 && nuevoAvion.idAerolinea >= 5004)
                {
                    printf("No exite el id de la Aerolinea. Reingrese el id: ");
                    scanf("%d", &nuevoAvion.idAerolinea);
                }

                listarTipo(tipos, tamt);

                printf("Ingrese el id del tipo de vuelo: ");
                fflush(stdin);
                scanf("%d", &nuevoAvion.idTipo);

                while( nuevoAvion.idTipo <= 1000 &&  nuevoAvion.idTipo >= 1004)
                {
                    printf("No exite el id del tipo de vuelo. Reingrese el id: ");
                    scanf("%d", & nuevoAvion.idTipo);
                }

                printf("Ingrese la capacidad de pasajeros de vuelo: ");
                fflush(stdin);
                scanf("%d", &nuevoAvion.capacidad);

                while( nuevoAvion.capacidad <= 300 &&  nuevoAvion.capacidad >= 301)
                {
                   printf("Capacaidad maxima superada. Reingrese la capacidad: ");
                   scanf("%d", & nuevoAvion.capacidad);
                }


                nuevoAvion.isEmpty = 0;
                nuevoAvion.id = *pLegajo;
                *pLegajo = *pLegajo + 1;
                vec[indice] = nuevoAvion;
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

int modificarAvion(eAvion vec[], int tam,eTipo tipos[], int tamt,eAerolinea aerolineas[] ,int tamae, int* pLegajo)
{
	int todoOk=0;
	int indice;
	int id;
	char salir;

	if(vec != NULL && tam>0)
	{
		listarAvion(vec, tam);
		printf("ingrese id:\n");
		scanf("%d", &id);
	   	if(buscarAvion(vec, tam, id, &indice))
	   	{
			 if(indice==-1)
	   		 {
	   			  printf("no hay un avion con id %d\n", id);
			 }
	   		 else
		     {
	   			 mostrarAvion(vec[indice]);

	   			do
	   			{
	   				switch(opcionesDeCambio())
	   				{
	   				case 1:

	   					listarAerolinea(aerolineas, tamae);

	   					printf(" su tipo actual es: %d\n", vec[indice].idAerolinea);

	   	                printf("Ingrese el id de la Aerolinea: ");
	   	                scanf("%d", &vec[indice].idAerolinea);

	                    while(vec[indice].idAerolinea <= 5000 && vec[indice].idAerolinea >= 5004)
	   	                {
	                        printf("No exite el id de la Aerolinea. Reingrese el id: ");
	   	                    scanf("%d", &vec[indice].idAerolinea);
	   					}
					break;
	   				case 2:
	   				 listarTipo(tipos, tamt);

	   				 printf("su tipo actual es: %d\n", vec[indice].idTipo);

	                 printf("Ingrese el id del tipo de vuelo: ");
	                 scanf("%d", &vec[indice].idTipo);

	   	             while( vec[indice].idTipo <= 1000 &&  vec[indice].idTipo >= 1004)
	                 {
	   	                 printf("No exite el id del tipo de vuelo. Reingrese el id: ");
	   	                 scanf("%d", & vec[indice].idTipo);
	                 }

	   			   break;
	   			   case 3:
	   				   confirmarSalida(&salir);
	   			   break;
	   			   default:
	   					printf("opcion Invalida!\n\n");
	   		      }
	   	        system("pause");
	          }while(salir != 's');
	     }
      }
	  else
	  {
			printf("Ocurrio un problema\n");
      }
    todoOk=1;
    }
 return todoOk;
}

int bajaAvion(eAvion vec[], int tam)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;
    if(vec != NULL && tam > 0)
    {
        listarAvion(vec, tam);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        if( buscarAvion(vec, tam, legajo, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un empleado con legajo %d\n", legajo);
            }
            else
            {
                mostrarAvion(vec[indice]);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


























void mostrarAvion(eAvion e)
{

    printf("%d      %d      %d     %d\n", e.id, e.idAerolinea, e.idTipo,e.capacidad);

}


int listarAvion(eAvion vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        //system("cls");
        printf("          *** Listado de Aviones ***\n\n");
        printf("id    idAereolinea    idTipo    capacidad\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
        	if(!vec[i].isEmpty)
        	{
        		mostrarAvion(vec[i]);
        	}
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

//MENUS
int menu()
{
	int opcion;
	printf("1) Alta de avion\n");
	printf("2) Modificar avion\n");
	printf("3) Baja de avion\n");
	printf("4) Listar aviones\n");
	printf("5) Listar aerolinea\n");
	printf("6) Listar tipos\n");
	printf("7) Listar destino\n");
	printf("8) Alta vuelo\n");
	printf("9) Listar vuelos\n");
	printf("10) Salir\n");
	printf("Ingrese una opcion: \n");
	scanf("%d", &opcion);

	return opcion;
}

void confirmarSalida(char* p)
{
	char confirmar;
	printf("Confirmar salida?:");
	fflush(stdin);
	scanf("%c", &confirmar);

	*p = confirmar;
}

int opcionesDeCambio()
{
	int opcion;
	printf("1) Cambiar id Aeroline\n");
	printf("2) Cambiar id Tipo\n");
	printf("3) Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

