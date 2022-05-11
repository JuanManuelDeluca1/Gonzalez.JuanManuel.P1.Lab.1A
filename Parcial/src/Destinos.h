/*
 * Destinos.h
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */

#ifndef DESTINOS_H_
#define DESTINOS_H_

typedef struct{

    int id;
    char descripcion[25];
    float precio;
    int isEmpty;

}eDestino;

#endif /* DESTINOS_H_ */

int listarDestino(eDestino aerolineas[], int tam);
int cargarDescripcionDestino(eDestino aerolineas[], int tam, int id, char descripcion[]);
int buscarDestino(eDestino aerolineas[], int tam, int id, int* pIndice);
int validarDestino(eDestino aerolineas[], int tam, int id);
