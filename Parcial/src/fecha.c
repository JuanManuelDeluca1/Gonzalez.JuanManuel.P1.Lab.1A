/*
 * fecha.c
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fecha.h"

int validarFecha(eFecha e, int tam)
{
	int todoOk;
	if(tam > 0)
	{
		while(e.mes > 12)
		{
			printf("el mes es inexistente: \n");
			scanf("%d", &e.mes);
		}

		while(e.dia < 32)
		{
			if(e.mes == 2 && e.dia < 29)
			{
				printf("el mes es febrero, ingrese el dia de nuevo: \n");
				scanf("%d", &e.dia);
				while(e.dia < 29)
				{
				   printf("el mes es febrero, ingrese el dia de nuevo: \n");
				   scanf("%d", &e.dia);
			    }
			 }
		}
		printf("dia inexistente: \n");
		scanf("%d", &e.dia);

		while(e.anio > 2022)
		{
		    printf("el anio ya paso, reingrese anio: \n");
		    scanf("%d", &e.anio);
		}


	 todoOk = 1;
	}
	return todoOk;
}

