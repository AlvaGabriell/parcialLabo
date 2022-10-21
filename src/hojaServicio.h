/*
 * hojaServicio.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include "fecha.h"
#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_
typedef struct
{
	int idHoja;
	int vehiculoId;
	char descripcion[25];
	int precioServicio;
	eFecha fecha;
	int isEmpty;
}eHojaServicio;

#endif /* HOJASERVICIO_H_ */
int HOJA_inicializarArray(eHojaServicio empleados[], int tam);
int HOJA_buscarArrayLibre(eHojaServicio empleados[],int tam);
eHojaServicio HOJA_pedirDatoEmpleado(int id);
int HOJA_altaEmpleados(eHojaServicio empleados[],int tam,int id);
void HOJA_mostrarEmpleado(eHojaServicio empleado);
int HOJA_mostrarEmpleados(eHojaServicio empleados[],int tam);
eHojaServicio HOJA_buscarUnoPorId(eHojaServicio empleados[],int tam,int id);
int HOJA_buscarPosicionPorId(eHojaServicio empleados[],int tam,int id);
