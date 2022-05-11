/*
 * Avion.h
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */

#include "Tipo.h"
#include "Aerolinea.h"

#ifndef AVION_H_
#define AVION_H_


typedef struct{

    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty;

}eAvion;


#endif /* AVION_H_ */

int inicializarAvion(eAvion vec[], int tam);
int buscarAvionLibre(eAvion vec[], int tam, int* pIndex);
int buscarAvion(eAvion vec[], int tam,int id, int* pIndex);
int altaAvion(eAvion vec[], int tam,eTipo tipos[], int tamt,eAerolinea aerolineas[] ,int tamae, int* pLegajo);
int modificarAvion(eAvion vec[], int tam,eTipo tipos[], int tamt,eAerolinea aerolineas[] ,int tamae, int* pLegajo);
int bajaAvion(eAvion vec[], int tam);
void mostrarAvion(eAvion e);
int listarAvion(eAvion vec[], int tam);
// menus
int menu();
void confirmarSalida(char* p);
int opcionesDeCambio();

