/*
 * vehiculo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include "utn.h"
#define TAM_DESCVEHI 20
#ifndef VEHICULO_H_
#define VEHICULO_H_
typedef struct
{
	int idVehiculo;
	char descripcion[TAM_DESCVEHI];
	int anioModelo;
	char color[10];
	int tipoId;
	int isEmpty;
}eVehiculo;
#endif /* VEHICULO_H_ */


int VEHICU_inicializarArray(eVehiculo empleados[], int tam);
int VEHICU_buscarArrayLibre(eVehiculo empleados[],int tam);
eVehiculo VEHICU_pedirDatoEmpleado(int id);
int VEHICU_altaEmpleados(eVehiculo empleados[],int tam,int id);
void VEHICU_mostrarEmpleado(eVehiculo empleado);
int VEHICU_mostrarEmpleados(eVehiculo empleados[],int tam);
eVehiculo VEHICU_buscarUnoPorId(eVehiculo empleados[],int tam,int id);
int VEHICU_buscarPosicionPorId(eVehiculo empleados[],int tam,int id);
