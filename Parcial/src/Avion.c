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
int altaAvion(eAvion vec[], int tam,eTipo tipos[], int tamt,eAerolinea aerolineas[] ,int tamae, ePiloto pilotos[], int tamp, int* pLegajo)
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

                printf("Ingrese el id de la Aerolinea: \n");
                fflush(stdin);
                scanf("%d", &nuevoAvion.idAerolinea);

                while(nuevoAvion.idAerolinea > 1004 || nuevoAvion.idAerolinea < 1000)
                {
                    printf("No exite el id de la Aerolinea. Reingrese el id: \n");
                    scanf("%d", &nuevoAvion.idAerolinea);
                }

                listarTipo(tipos, tamt);

                printf("Ingrese el id del tipo de vuelo: \n");
                fflush(stdin);
                scanf("%d", &nuevoAvion.idTipo);

                while( nuevoAvion.idTipo > 5003 || nuevoAvion.idTipo < 5000)

                {
                    printf("No exite el id del tipo de vuelo. Reingrese el id: \n");
                    scanf("%d", & nuevoAvion.idTipo);
                }

                printf("Ingrese la capacidad de pasajeros de vuelo(la capacidad min es 10 y max es 300): \n");
                fflush(stdin);
                scanf("%d", &nuevoAvion.capacidad);

                while( nuevoAvion.capacidad > 300 || nuevoAvion.capacidad < 10)
                {
                   if(nuevoAvion.capacidad > 300)
                   {
                	   printf("Capacaidad maxima superada. Reingrese la capacidad: \n");
                	   scanf("%d", & nuevoAvion.capacidad);
                   }
                   if(nuevoAvion.capacidad < 10)
                   {
                	   printf("Capacaidad minima superada. Reingrese la capacidad: \n");
                       scanf("%d", & nuevoAvion.capacidad);
                   }

                   listarPilotos(pilotos, tamp);

                   printf("Ingrese Id piloto: ");
                   scanf("%d", &nuevoAvion.idPiloto);

                   while( !validarPilotos(pilotos, tamp, nuevoAvion.idPiloto))
                   {
                       printf("Sector invalido.Ingrese Id sector: ");
                       scanf("%d", &nuevoAvion.idPiloto);
                    }

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

int modificarAvion(eAvion vec[], int tam,eTipo tipos[], int tamt,eAerolinea aerolineas[] ,int tamae, ePiloto pilotos, int tamp, int* pLegajo)
{
	int todoOk=0;
	int indice;
	int id;
	char salir;

	if(vec != NULL && tam>0)
	{
		listarAvion(vec, tam, pilotos, tamp);
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
	   			 mostrarAviones(vec[indice]);

	   			do
	   			{
	   				switch(opcionesDeCambio())
	   				{
	   				case 1:

	   					listarAerolinea(aerolineas, tamae);

	   					printf(" su tipo actual es: %d\n", vec[indice].idAerolinea);

	   	                printf("Ingrese el id de la Aerolinea: \n");
	   	                scanf("%d", &vec[indice].idAerolinea);

	                    while(vec[indice].idAerolinea > 1004 || vec[indice].idAerolinea < 1000)
	   	                {
	                        printf("No exite el id de la Aerolinea. Reingrese el id: \n");
	   	                    scanf("%d", &vec[indice].idAerolinea);
	   					}
					break;
	   				case 2:
	   				 listarTipo(tipos, tamt);

	   				 printf("su tipo actual es: %d\n", vec[indice].idTipo);

	                 printf("Ingrese el id del tipo de vuelo: \n");
	                 scanf("%d", &vec[indice].idTipo);

	   	             while( vec[indice].idTipo > 5003 || vec[indice].idTipo < 5000)
	                 {
	   	                 printf("No exite el id del tipo de vuelo. Reingrese el id: \n");
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

int bajaAvion(eAvion vec[], int tam, ePiloto pilotos, int tamp)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;
    if(vec != NULL && tam > 0)
    {
    	listarAviones(vec, tam, pilotos, tamp);
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

int ordenarAvionPorAerolineaYCapacidadAcd(eAvion vec[], int tam, ePiloto pilotos, int tamp)
{
    int todoOk = 0;
    int mostrar = 0;
    eAvion auxPasajeros;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if( ((vec[i].idAerolinea == vec[j].idAerolinea) &&  (vec[i].capacidad > vec[j].capacidad))
                	|| ((vec[i].idAerolinea != vec[j].idAerolinea) &&(vec[i].idAerolinea > vec[j].idAerolinea)) )
                {
                    auxPasajeros = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajeros;
                    mostrar = 1;
                }
            }
        }
        if(mostrar == 1)
        {
        	printf(" ORDENADO POR AEROLINEA Y CAPACIDAD\n");
        	listarAviones(vec, tam, pilotos, tamp);;
        }
        todoOk = 1;
    }
    return todoOk;
}











int mostrarAviones(eAvion e, ePiloto pilotos[], int tam)
{
    int todoOk = 0;
    char descPiloto[50];

    if(pilotos != NULL && tam > 0)
    {
        cargarDescripcionSector( pilotos, tam, e.idPiloto, descPiloto);

        printf("%d      %d      %d     %d    %s\n",
        		e.id,
				e.idAerolinea,
				e.idTipo,
				e.capacidad,
               descPiloto
              );
        todoOk = 1;
    }
    return todoOk;
}

int listarAvion(eAvion vec[], int tam, ePiloto pilotos, int tamp)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        //system("cls");
        printf("          *** Listado de Aviones ***\n\n");
        printf("id    idAereolinea    idTipo    capacidad   piloto\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
        	if(!vec[i].isEmpty)
        	{
        		mostrarAvion(vec[i], pilotos, tamp);
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
	printf("10) Avion por aerolinea\n");
	printf("11) Avion por tipo\n");
	printf("12) Promedio Jets\n");
	printf("13) Ordenar Avion por aerolinea\n");
	printf("20) Salir\n");
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



int listarAvionConAerolineas(eAvion vec[], int tam, int idAerolineas, ePiloto pilotos, int tamp)
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
        	if(!vec[i].isEmpty && vec[i].idAerolinea == idAerolineas)
        	{
        		mostrarAvion(vec[i], pilotos, tamp);
        	}
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}


int mostarAvionesConAreolineas(eAvion vec[], eAerolinea aerolineas[],  int tam, int tamae, ePiloto pilotos, int tamp)
{
	int todoOk = 0;
	int idAerolinea;
	int j = 0;
	if(tam > 0 && tamae > 0)
	{
		listarAerolinea(aerolineas, tamae);
		printf("ingrese id de la aerolinea que quiera ver los aviones: \n ");
		scanf("%d", &idAerolinea);
		while(idAerolinea > 1004 || idAerolinea < 1000)
		{
			printf("El id no exite. Reingrese id de la aerolinea que quiera ver los aviones: \n ");
			scanf("%d", &idAerolinea);
		}
		for(int i=0; i<tam; i++)
		{
			if(vec[i].idAerolinea == idAerolinea)
			{
				listarAvionConAerolineas(vec, tam, idAerolinea, pilotos, tamp);
				break;
			}
			j++;
		}
		if(j == tam)
		{
		   printf("no hay vuelos con esa aerolinea\n");
		}
		todoOk=1;
	}
	return todoOk;
}

int listarAvionConTipos(eAvion vec[], int tam, int idTipo, ePiloto, pilotos, int tamp)
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
        	if(!vec[i].isEmpty && vec[i].idTipo == idTipo)
        	{
        		mostrarAvion(vec[i], pilotos, tamp);
        	}
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostarAvionesConTipos(eAvion vec[], eTipo tipos[],  int tam, int tamt, ePiloto pilotos, int tamp)
{
	int todoOk = 0;
	int idTipo;
	int j = 0;
	if(tam > 0 && tamt > 0)
	{
		listarTipo(tipos, tamt);
		printf("ingrese id de la aerolinea que quiera ver los aviones: \n ");
		scanf("%d", &idTipo);
		while(idTipo > 5003 || idTipo < 5000)
		{
			printf("El id no exite. Reingrese id del tipo que quiera ver los aviones: \n ");
			scanf("%d", &idTipo);
		}
		for(int i=0; i<tam; i++)
		{
			if(vec[i].idTipo == idTipo)
			{
				listarAvionConTipos(vec, tam, idTipo, pilotos, tamp);
				break;
			}
			j++;
		}
		if(j == tam)
		{
		   printf("no hay vuelos de ese tipo\n");
		}
		todoOk=1;
	}
	return todoOk;
}

int mostrarAerolineasMenosElegidas(eAvion vec[], int tam)
{
	int todoOk = 0;
	int contadorDeLan = 0;
	int contadorDeIberia = 0;
	int contadorDeNorwegian = 0;
	int contadorDeAmerican = 0;
	int contadorDeAustral = 0;
	if(vec != NULL && tam > 0)
	{
		for(int i=0; i < tam; i++)
		{
			if(vec[i].isEmpty == 1)
			{
				if(vec[i].idAerolinea == 1000)
				{
					contadorDeLan++;
				}
				if(vec[i].idAerolinea == 1001)
				{
					contadorDeIberia++;
				}
				if(vec[i].idAerolinea == 1002)
				{
					contadorDeNorwegian++;
				}
				if(vec[i].idAerolinea == 1003)
				{
					contadorDeAmerican++;
				}
				if(vec[i].idAerolinea == 1004)
				{
					contadorDeAustral++;
				}
			}
		}
		if(contadorDeAustral <= contadorDeAmerican && contadorDeAustral <= contadorDeNorwegian
			&& contadorDeAustral <= contadorDeIberia && contadorDeAustral <= contadorDeLan)
		{
			printf("Las mas elegida de las aerolineas es Austral con: %d\n", contadorDeAustral);
		}
		if(contadorDeAmerican <= contadorDeNorwegian && contadorDeAmerican <= contadorDeIberia
				&& contadorDeAmerican <= contadorDeLan)
		{
			printf("Las mas elegida de las aerolineas es American con: %d\n", contadorDeAmerican);
		}
		if(contadorDeNorwegian <= contadorDeLan && contadorDeNorwegian <= contadorDeIberia)
		{
			printf("Las mas elegida de las aerolineas es Norwegian con: %d\n", contadorDeNorwegian);
		}
		if(contadorDeIberia <= contadorDeLan)
		{
			printf("Las mas elegida de las aerolineas es Iberia con: %d\n", contadorDeIberia);
		}
		else
		{
			printf("Las mas elegida de las aerolineas es Lan con: %d\n", contadorDeLan);
		}
	}
	return todoOk;
}

int mostrarAvionesPorAerolinea(eAvion vec[], int tam, ePiloto pilotos, int tamp)
{
    int todoOk = 0;
    int mostrar = 0;
    eAvion auxAvion;
    if(vec != NULL && tam > 0)
    {
    	listarAvion(vec, tam, pilotos, tamp);
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if((vec[i].idAerolinea >= vec[j].idAerolinea))
                {
                	auxAvion = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxAvion;
                    mostrar = 1;
                }
            }
        }
        if(mostrar == 1)
        {
        	printf(" POR AEROLINEA\n");
        	listarAvion(vec, tam, pilotos, tamp);
        }
        else
        {
        	printf("No hay Aviones cargados");
        }
        todoOk = 1;
    }
    return todoOk;
}

int promJetPorAerolinea(eAvion vec[], int tam, eAerolinea aerolineas[], int tamae)
{
	int todoOk = 0;
	int auxAerolineas;
	float contadorDeAerolineas = 0;
	float contadorDeJets=0;
	float promJets;
	if(vec != NULL && tam > 0 && aerolineas != NULL && tamae)
	{
		listarAerolinea(aerolineas, tamae);
		printf("ingrese la aerolinea de cual quiera saber el proomedio de jets: \n");
		scanf("%d", &auxAerolineas);
		while(auxAerolineas > 1004 || auxAerolineas < 1000)
		{
			printf("Error. Reingrese una aerolinea que quiera saber la cantidad de aviones: \n");
			scanf("%d", &auxAerolineas);
		}
		for(int i=0; i < tam; i++)
		{
			if(auxAerolineas == vec[i].idAerolinea)
			{
				contadorDeAerolineas++;
				if(vec[i].idTipo == 5000)
				{
					contadorDeJets++;
				}
			}
			todoOk = 1;
		}
		if(contadorDeJets != 0 && contadorDeAerolineas != 0)
		{
			promJets =  contadorDeJets / contadorDeAerolineas;
		}

		printf("El promedio de jets en la aerolinea que elgio es %.13f\n", promJets);

	}
	return todoOk;
}


int informarAvionMasCantidad(eAvion aviones[], int tam, eAerolinea aerolineas[])
{
	int todoOk = 0;
	int masCant = 0;
	int auxAerolinea=0;

	if(aviones != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(aviones[i].isEmpty == 1 && masCant < aviones[i].capacidad)
			{
				masCant = aviones[i].capacidad;
			    auxAerolinea = aviones[i].idAerolinea;
			}
		}
		if(masCant == 0)
		{
		    printf("no hay aviones ingresados \n");
		}
		else
		{
			printf("La aerolinea con mas cantidad es %d  %d\n", auxAerolinea, masCant);
		}

		todoOk=1;
	}
	return todoOk;
}




