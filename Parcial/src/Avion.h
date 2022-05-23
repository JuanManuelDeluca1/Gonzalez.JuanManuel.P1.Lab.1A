/*
 * Avion.h
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */

#include "Tipo.h"
#include "Aerolinea.h"
#include "pilotos.h"

#ifndef AVION_H_
#define AVION_H_


typedef struct{

    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int idPiloto;
    int isEmpty;

}eAvion;


#endif /* AVION_H_ */

int inicializarAvion(eAvion vec[], int tam);
int buscarAvionLibre(eAvion vec[], int tam, int* pIndex);
int buscarAvion(eAvion vec[], int tam,int id, int* pIndex);
int altaAvion(eAvion vec[], int tam,eTipo tipos[], int tamt,eAerolinea aerolineas[] ,int tamae, ePiloto pilotos[], int tamp, int* pLegajo);
int modificarAvion(eAvion vec[], int tam,eTipo tipos[], int tamt,eAerolinea aerolineas[] ,int tamae, ePiloto pilotos, int tamp, int* pLegajo);
int bajaAvion(eAvion vec[], int tam, ePiloto pilotos, int tamp);
//Mostrat Aviones
int mostrarAviones(eAvion e, ePiloto pilotos[], int tam);
int listarAvion(eAvion vec[], int tam, ePiloto pilotos, int tamp);
int ordenarAvionPorAerolineaYCapacidadAcd(eAvion vec[], int tam, ePiloto pilotos, int tamp);

// menus
int menu();
void confirmarSalida(char* p);
int opcionesDeCambio();

//mostrar aviones
int listarAvionConAerolineas(eAvion vec[], int tam, int idAerolineas,  ePiloto pilotos, int tamp);
int mostarAvionesConAreolineas(eAvion vec[], eAerolinea aerolineas[], int tam, int tamae, ePiloto pilotos, int tamp);
int listarAvionConTipos(eAvion vec[], int tam, int idTipo, ePiloto pilotos, int tamp);
int mostarAvionesConTipos(eAvion vec[], eTipo tipos[],  int tam, int tamt, ePiloto pilotos, int tamp);
int mostrarAerolineasMenosElegidas(eAvion vec[], int tam);
int mostrarAvionesPorAerolinea(eAvion vec[], int tam, ePiloto pilotos, int tamp);
int promJetPorAerolinea(eAvion vec[], int tam, eAerolinea aerolineas[], int tamae);
int informarAvionMasCantidad(eAvion aviones[], int tam, eAerolinea aerolineas[]);



