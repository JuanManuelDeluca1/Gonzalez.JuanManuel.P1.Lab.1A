/*
 * pilotos.h
 *
 *  Created on: 23 may. 2022
 *      Author: juanm
 */

#ifndef PILOTOS_H_
#define PILOTOS_H_

typedef struct{

    int id;
    char nombre[50];
    char sexo;
    int isEmpty;

}ePiloto;

#endif /* PILOTOS_H_ */
int buscarPilto(ePiloto pilotos[], int tam, int id, int* pIndice);
int listarPilotos(ePiloto pilotos[], int tam);
int validarPilotos(ePiloto pilotos[], int tam, int id);
int cargarDescripcionPilotos(ePiloto pilotos[], int tam, int id, char nombre[]);
