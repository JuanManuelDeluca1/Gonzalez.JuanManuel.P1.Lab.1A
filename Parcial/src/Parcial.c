/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Tipo.h"
#include "Aerolinea.h"
#include "Avion.h"
#include "DestinoS.h"
#include "Vuelos.h"

#define TAMAV  300
#define TAMT 4
#define TAMAE 5
#define TAMD 4


int main(void)
{
	setbuf(stdout,NULL);
	char salir;
	int flagCarga = 0;
	int flagCargaV = 0;
	int indice;
	int proximoIdAvion = 10000;
	int proximoIdVuelo = 30000;
	eAvion aviones[TAMAV];
	eVuelos vuelos[TAMAV];
	eTipo tipos[TAMT] =
	{
	   {5000, "Jet"},
	   {5001, "Helice"},
	   {5002, "Planeador"},
	   {5003, "Carga"}
	};

	eAerolinea aerolineas[TAMAE] =
	{
	   {1000, "Lan"},
	   {1001, "Iberia"},
	   {1002, "Norwegian"},
	   {1003, "American"},
	   {1004, "Austral"}
	};

	eDestino destinos[TAMD] =
	{
		{20000, "Calafate", 22250},
		{20001, "Miami", 103000},
		{20002, "Madird", 84400},
	    {20003, "Amsterdam", 95600},
	};
	do
		{
			switch(menu())
			{
				case 1:
					if(flagCarga == 0)
					{
						inicializarAvion(aviones, TAMAV);
						buscarAvionLibre(aviones, TAMAV, &indice);
						flagCarga = 1;
					}
					if(flagCarga == 1)
					{
						altaAvion(aviones, TAMAV, tipos, TAMT, aerolineas, TAMAE, &proximoIdAvion);
					}
					else
					{
						printf("Ubo un problema al cargar\n");
					}
				break;
				case 2:
					if(flagCarga == 1)
					{
						modificarAvion(aviones, TAMAV, tipos, TAMT, aerolineas, TAMAE, &proximoIdVuelo);
					}
					else
					{
						printf("debe cargar un pasajero primero\n\n");
					}
				break;
				case 3:
					if(flagCarga == 1)
					{
						bajaAvion(aviones, TAMAV);
					}
					else
					{
						printf("debe cargar un pasajero primero\n\n");
					}
				break;
				case 4:
					if(flagCarga == 1)
					{
						listarAvion(aviones, TAMAV);
					}
					else
					{
						printf("debe cargar un pasajero primero\n\n");
					}
				break;
				case 5:
					listarAerolinea(aerolineas, TAMAE);
				break;
				case 6:
					listarTipo(tipos, TAMT);
				break;
				case 7:
					listarDestino(destinos, TAMD);
				break;
				case 8:
					if(flagCarga == 1)
					{
						if(flagCargaV == 0)
						{
						inicializarVuelos(vuelos , TAMAV);
						buscarVuelosLibre(vuelos , TAMAV, &proximoIdVuelo);
						flagCargaV=1;
						}
						if(flagCargaV == 1)
						{
							altaVuelo(vuelos , TAMAV, aviones, TAMAV, destinos , TAMD, &proximoIdVuelo);
						}

					}
					else
			        {
						printf("debe cargar un pasajero primero\n\n");
					}

				break;
				case 9:
					if(flagCarga == 1)
					{
						listarVuelos(vuelos , TAMAV);
					}
					else
					{
						printf("debe cargar un pasajero primero\n\n");
					}

				break;
				case 10:
					confirmarSalida(&salir);
				break;
				default:
					printf("opcion Invalida!\n\n");
			}
			system("pause");

		}while(salir != 's');
	return 0;
}

