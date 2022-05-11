/*
 * Aerolinea.h
 *
 *  Created on: 11 may. 2022
 *      Author: juanm
 */

#ifndef AEROLINEA_H_
#define AEROLINEA_H_
typedef struct{

    int id;
    char descripcion[20];
    int isEmpty;

}eAerolinea;


#endif /* AEROLINEA_H_ */

int listarAerolinea(eAerolinea aerolineas[], int tam);
int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tam, int id, char descripcion[]);
int buscarAerolinea(eAerolinea aerolineas[], int tam, int id, int* pIndice);
int validarAerolinea(eAerolinea aerolineas[], int tam, int id);
