/*
 * hojaServicio.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include "nexo.h"

#define OCUPADO 0
#define LIBRE 1
int HOJA_inicializarArray(eHojaServicio empleados[], int tam)
{
	int todoOk=0;

	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			empleados[i].isEmpty=LIBRE;
			todoOk=1;
		}
	}
	return todoOk;
}

int HOJA_buscarArrayLibre(eHojaServicio empleados[],int tam)
{
	int retorno=-1;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

eHojaServicio HOJA_pedirDatoEmpleado(int id)
{
	eHojaServicio aux;
	aux.idHoja=id;
	aux.vehiculoId=UTN_pedirEnteroRango("Ingrese id del vehiculo", 1, 400);
	UTN_pedirCadena("\nIngrese descipcion :",aux.descripcion,20);
	while(!validarLetras(aux.descripcion))
	{
		UTN_pedirCadena("\nIngrese destino :",aux.descripcion,20);
	}
	aux.precioServicio=UTN_pedirEnteroRango("\nIngrese el precio :",1000,500000);
	aux.fecha.dia=UTN_pedirEnteroRango("\nIngrese dia : " , 1, 31);
	aux.fecha.mes=UTN_pedirEnteroRango("\nIngrese mes : " , 1, 12);
	aux.fecha.anio=UTN_pedirEnteroRango("\nIngrese anio desde 2022 al 2025: " , 2022, 2025);
	aux.isEmpty=OCUPADO;
	return aux;
}

int HOJA_altaEmpleados(eHojaServicio empleados[],int tam,int id)
{
	int todoOk=0;
	int posicionLibre;
	eHojaServicio empleado;

	if(empleados!=NULL&&tam>0)
	{
		posicionLibre=HOJA_buscarArrayLibre(empleados, tam);
		empleado=HOJA_pedirDatoEmpleado(id);
		if(posicionLibre!=-1)
		{
			empleados[posicionLibre]=empleado;
			todoOk=1;
		}
	}
	return todoOk;
}

void HOJA_mostrarEmpleado(eHojaServicio empleado)
{
	printf("\n%3d     %d      %s          %d         %d/%d/%d",empleado.idHoja,empleado.vehiculoId,empleado.descripcion,empleado.precioServicio,
			empleado.fecha.dia,empleado.fecha.mes,empleado.fecha.anio);
}

int HOJA_mostrarEmpleados(eHojaServicio empleados[],int tam)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0)
	{
		printf("\n  IDHOJA       VEHICULOID         DESCRIPCION            PRECIO 		FECHA");
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				HOJA_mostrarEmpleado(empleados[i]);
			}
		}
	}

	return todoOk;
}

eHojaServicio HOJA_buscarUnoPorId(eHojaServicio empleados[],int tam,int id)
{
	eHojaServicio aux;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].vehiculoId==id)
			{
				aux=empleados[i];
				break;
			}
		}
	}
	return aux;
}

int HOJA_buscarPosicionPorId(eHojaServicio empleados[],int tam,int id)
{
	int aux;
	aux=-1;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO && empleados[i].vehiculoId==id)
			{
				aux=i;
				break;
			}
		}
	}
	return aux;
}
