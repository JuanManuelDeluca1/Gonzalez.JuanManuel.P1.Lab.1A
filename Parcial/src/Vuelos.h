/*
 * Vuelos.h
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */

#include "Destinos.h"
#include "Avion.h"
#include "fecha.h"

#ifndef VUELOS_H_
#define VUELOS_H_

typedef struct{

    int id;
    int idAvion;
    int idDestino;
    eFecha fIngreso;
    int isEmpty;

}eVuelos;

#endif /* VUELOS_H_ */

int listarVuelos(eVuelos vec[], int tam);
void mostrarVuelos(eVuelos e, int tam);
int inicializarVuelos(eVuelos vec[], int tam);
int buscarVuelosLibre(eVuelos vec[], int tam, int* pIndex);
int cargarDescripcionVuelos(eVuelos aerolineas[], int tam, int id, char descripcion[]);
int buscarVuelos(eVuelos aerolineas[], int tam, int id, int* pIndice);
int validarVuelos(eVuelos aerolineas[], int tam, int id);
int altaVuelo(eVuelos vec[], int tam,eAvion avion[], int tama,eDestino destino[] ,int tamd, int* pLegajo);
