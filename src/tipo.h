/*
 * tipo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include "utn.h"
#define TAM_DESCRIPCION 25
#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
	int idTipo;
	char descripcion[TAM_DESCRIPCION];

}eTipo;
#endif /* TIPO_H_ */
void TIPO_mostrarSector(eTipo sector);
int TIPO_mostrarSectores(eTipo sector[],int tam);
eTipo TIPO_buscarSecPorId(eTipo listaSec[],int tamSec,int id);
