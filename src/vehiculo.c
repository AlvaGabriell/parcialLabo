/*
 * vehiculo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include "vehiculo.h"
#define OCUPADO 0
#define LIBRE 1
int VEHICU_inicializarArray(eVehiculo empleados[], int tam)
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

int VEHICU_buscarArrayLibre(eVehiculo empleados[],int tam)
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

eVehiculo VEHICU_pedirDatoEmpleado(int id)
{
	eVehiculo aux;
	aux.idVehiculo=id;
	UTN_pedirCadena("\nIngrese descripcion :",aux.descripcion,20);
	while(!validarLetras(aux.descripcion))
	{
		UTN_pedirCadena("\nIngrese descripcion :",aux.descripcion,20);
		validarLetras(aux.descripcion);
	}
	aux.anioModelo=UTN_pedirEnteroRango("\nIngrese anio del modelo :", 1950,2022);
	UTN_pedirCadena("\nIngrese color :",aux.color,10);
	while(!validarLetras(aux.descripcion))
	{
		UTN_pedirCadena("\nIngrese descripcion :",aux.color,10);
		validarLetras(aux.color);
	}
	aux.tipoId=UTN_pedirEnteroRango("\nIngrese id del tipo :", 1000,1002);
	aux.isEmpty=OCUPADO;
	return aux;
}

int VEHICU_altaEmpleados(eVehiculo empleados[],int tam,int id)
{
	int todoOk=0;
	int posicionLibre;
	eVehiculo empleado;

	if(empleados!=NULL&&tam>0)
	{
		posicionLibre=VEHICU_buscarArrayLibre(empleados, tam);
		empleado=VEHICU_pedirDatoEmpleado(id);
		if(posicionLibre!=-1)
		{
			empleados[posicionLibre]=empleado;
			todoOk=1;
		}
	}
	return todoOk;
}

void VEHICU_mostrarEmpleado(eVehiculo empleado)
{
	printf("\n%3d     %10s      %d           %s			%d",empleado.idVehiculo,empleado.descripcion,empleado.anioModelo,empleado.color,empleado.tipoId);
}

int VEHICU_mostrarEmpleados(eVehiculo empleados[],int tam)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0)
	{
		printf("\n  ID       DESCRIPCION         MODELO            COLOR		TIPOID");
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				VEHICU_mostrarEmpleado(empleados[i]);
			}
		}
	}

	return todoOk;
}

eVehiculo VEHICU_buscarUnoPorId(eVehiculo empleados[],int tam,int id)
{
	eVehiculo aux;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].idVehiculo==id)
			{
				aux=empleados[i];
				break;
			}
		}
	}
	return aux;
}

int VEHICU_buscarPosicionPorId(eVehiculo empleados[],int tam,int id)
{
	int aux;
	aux=-1;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO && empleados[i].idVehiculo==id)
			{
				aux=i;
				break;
			}
		}
	}
	return aux;
}
