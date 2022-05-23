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
void mostrarVuelos(eVuelos e);
int inicializarVuelos(eVuelos vec[], int tam);
int buscarVuelosLibre(eVuelos vec[], int tam, int* pIndex);
int cargarDescripcionVuelos(eVuelos aerolineas[], int tam, int id, char descripcion[]);
int buscarVuelos(eVuelos aerolineas[], int tam, int id, int* pIndice);
int validarVuelos(eVuelos aerolineas[], int tam, int id);
int altaVuelo(eVuelos vec[], int tam,eAvion avion[], int tama,eDestino destino[] ,int tamd,ePiloto pilotos, int tamp, int* pLegajo);
int listarVulosConAvion(eVuelos vec[], int tam, int idAvion);
int vuelosDeUnAvion(eVuelos vec[], eAvion avion[], int tam,ePiloto pilotos, int tamp);
int listarAvionConDestinos(eVuelos vec[], int tam, int idDestino);
int mostrarAvionPorDestino(eVuelos vec[], int tam, eDestino destinos[], int tamd);
int listarVuelosConFechas(eVuelos vec[], int tam, int fechadia, int fechames, int fechaanio);
int mostrarVuelosPorFecha(eVuelos vec[], int tam);



