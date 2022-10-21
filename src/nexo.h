/*
 * nexo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include "fecha.h"
#include "tipo.h"
#include "vehiculo.h"
#include "hojaServicio.h"
#include "utn.h"

#ifndef NEXO_H_
#define NEXO_H_

#endif /* NEXO_H_ */
int NEXO_inicializarArray(eVehiculo empleados[], int tam);
int NEXO_buscarArrayLibre(eVehiculo empleados[],int tam);
eVehiculo NEXO_pedirDatoEmpleado(int id, eTipo tipos[],int tamTipo);
int NEXO_altaEmpleados(eVehiculo empleados[],int tam,int id,eTipo tipos[],int tamTipo);
eTipo NEXO_buscarSecPorId(eTipo listaSec[],int tamSec,int id);
void NEXO_mostrarEmpleado(eVehiculo empleado, eTipo tipos[],int tamTipo);
int NEXO_mostrarEmpleados(eVehiculo empleados[],int tam, eTipo tipos[],int tamTipo);
eVehiculo NEXO_buscarUnoPorId(eVehiculo empleados[],int tam,int id);
int NEXO_buscarPosicionPorId(eVehiculo empleados[],int tam,int id);
eHojaServicio NEXO_pedirDatoHoja(int id, eVehiculo vehiculos[],int tamVehi,eTipo tipos[],int tamTipo);
int NEXO_altaEmpleadosHoja(eHojaServicio empleados[],int tam,int id,eVehiculo vehiculos[],int tamVehi,eTipo tipos[],int tamTipo );
void NEXO_mostrarHoja(eHojaServicio empleado,eVehiculo vehiculos[],int tamV);
int NEXO_mostrarHojas(eHojaServicio empleados[],int tam,eVehiculo vehiculos[],int tamV);
int NEXO_darDebajaVehi(eVehiculo vehiculos[],int tamV,eTipo tipos[],int tamTipo);
int NEXO_modificarVehi(eVehiculo vehiculos[],int tamV,eTipo tipos[],int tamTipo, int id);
int NEXO_ordenXTipoYdestino(eVehiculo empleados[],int tam, eTipo tipos[],int tamT);
