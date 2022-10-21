/*
 * nexo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include "nexo.h"
#define OCUPADO 0
#define LIBRE 1

int NEXO_inicializarArray(eVehiculo empleados[], int tam)
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

int NEXO_buscarArrayLibre(eVehiculo empleados[],int tam)
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

eVehiculo NEXO_pedirDatoEmpleado(int id, eTipo tipos[],int tamTipo)
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
	TIPO_mostrarSectores(tipos, tamTipo);
	aux.tipoId=UTN_pedirEnteroRango("\nIngrese id del tipo :", 1000,1002);
	aux.isEmpty=OCUPADO;
	return aux;
}

int NEXO_altaEmpleados(eVehiculo empleados[],int tam,int id,eTipo tipos[],int tamTipo)
{
	int todoOk=0;
	int posicionLibre;
	eVehiculo empleado;

	if(empleados!=NULL&&tam>0)
	{
		posicionLibre=VEHICU_buscarArrayLibre(empleados, tam);
		empleado=NEXO_pedirDatoEmpleado(id,tipos,tamTipo);
		if(posicionLibre!=-1)
		{
			empleados[posicionLibre]=empleado;
			todoOk=1;
		}
	}
	return todoOk;
}

eTipo NEXO_buscarSecPorId(eTipo listaSec[],int tamSec,int id)
{
	eTipo aux;
	for(int i=0;i<tamSec;i++)
	{
		if(listaSec[i].idTipo==id)
		{
			aux=listaSec[i];
			break;
		}
	}
	return aux;
}

void NEXO_mostrarEmpleado(eVehiculo empleado, eTipo tipos[],int tamTipo)
{
	int id;
	eTipo aux;
	id=empleado.tipoId;
	aux=NEXO_buscarSecPorId(tipos, tamTipo, id);
	printf("\n|%-5d|%-15s|%-6d|%-10s|%-10s|",empleado.idVehiculo,empleado.descripcion,empleado.anioModelo,empleado.color,aux.descripcion);
}

int NEXO_mostrarEmpleados(eVehiculo empleados[],int tam, eTipo tipos[],int tamTipo)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0&&tipos!=NULL&&tamTipo>0)
	{
		//int anchoColumnaNombres = -10;
		int anchoColumnaPasajeros=-15;
		printf("\n--------------------------------------------------------------------|");
		printf("\n|%*s|%*s|%*s|%*s|%*s|",anchoColumnaPasajeros," ID ",anchoColumnaPasajeros," DESCRIPCION ",anchoColumnaPasajeros, " MODELO ",
				anchoColumnaPasajeros," COLOR ",anchoColumnaPasajeros," TIPO ");
		printf("\n--------------------------------------------------------------------|");
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				NEXO_mostrarEmpleado(empleados[i], tipos, tamTipo);
			}
		}
	}
	return todoOk;
}

eVehiculo NEXO_buscarUnoPorId(eVehiculo empleados[],int tam,int id)
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

int NEXO_buscarPosicionPorId(eVehiculo empleados[],int tam,int id)
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

eHojaServicio NEXO_pedirDatoHoja(int id, eVehiculo vehiculos[],int tamVehi,eTipo tipos[],int tamTipo)
{
	eHojaServicio aux;
	aux.idHoja=id;
	NEXO_mostrarEmpleados(vehiculos, tamVehi, tipos, tamTipo);
	aux.vehiculoId=UTN_pedirEnteroRango("\nIngrese id del vehiculo", 1, 400);
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

int NEXO_altaEmpleadosHoja(eHojaServicio empleados[],int tam,int id,eVehiculo vehiculos[],int tamVehi,eTipo tipos[],int tamTipo )
{
	int todoOk=0;
	int posicionLibre;
	eHojaServicio empleado;

	if(empleados!=NULL&&tam>0)
	{
		posicionLibre=HOJA_buscarArrayLibre(empleados, tam);
		empleado=NEXO_pedirDatoHoja(id,vehiculos,tamVehi,tipos,tamTipo);
		if(posicionLibre!=-1)
		{
			empleados[posicionLibre]=empleado;
			todoOk=1;
		}
	}
	return todoOk;
}
void NEXO_mostrarHoja(eHojaServicio empleado,eVehiculo vehiculos[],int tamV)
{
	int id;
	eVehiculo aux;
	id=empleado.vehiculoId;
	aux=VEHICU_buscarUnoPorId(vehiculos, tamV, id);
	printf("\n%3d     %10s      %s          %d         %d/%d/%d",empleado.idHoja,aux.descripcion,empleado.descripcion,empleado.precioServicio,
			empleado.fecha.dia,empleado.fecha.mes,empleado.fecha.anio);
}

int NEXO_mostrarHojas(eHojaServicio empleados[],int tam,eVehiculo vehiculos[],int tamV)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0)
	{
		printf("\n  IDHOJA       VEHICULOID         DESCRIPCION            PRECIO 		FECHA");
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				NEXO_mostrarHoja(empleados[i],vehiculos,tamV);
			}
		}
	}

	return todoOk;
}

int NEXO_darDebajaVehi(eVehiculo vehiculos[],int tamV,eTipo tipos[],int tamTipo)
{
	int todoOk=0;
	int id;
	int posicion;
	printf("\n\t\t******BAJA DE EMPLEADOS******");
	NEXO_mostrarEmpleados(vehiculos, tamV, tipos, tamTipo);
	id=UTN_pedirEnteroRango("\nSeleccione un id : ", 1, 5000);
	posicion=VEHICU_buscarPosicionPorId(vehiculos, tamV, id);
	if(posicion!=-1)
	{
		vehiculos[posicion].isEmpty=LIBRE;
		todoOk=1;
	}else
		{
			todoOk=-2;
		}
	return todoOk;
}

int NEXO_modificarVehi(eVehiculo vehiculos[],int tamV,eTipo tipos[],int tamTipo, int id)
{
	int todoOk=0;
	int idPos;
	int posicion;
	printf("\n\t\t******MODIFICACION DE EMPLEADOS******");
	NEXO_mostrarEmpleados(vehiculos, tamV, tipos, tamTipo);
	idPos=UTN_pedirEnteroRango("\nSeleccione un id : ", 1, 5000);
	posicion=VEHICU_buscarPosicionPorId(vehiculos, tamV, idPos);
	if(posicion!=-1)
	{
		UTN_pedirCadena("\nIngrese descripcion :",vehiculos[posicion].descripcion,20);
		while(!validarLetras(vehiculos[posicion].descripcion))
		{
			UTN_pedirCadena("\nIngrese descripcion :",vehiculos[posicion].descripcion,20);
			validarLetras(vehiculos[posicion].descripcion);
		}
		todoOk=1;
	}else
		{
			todoOk=-2;
		}
	return todoOk;
}

int NEXO_ordenXTipoYdestino(eVehiculo empleados[],int tam, eTipo tipos[],int tamT)
{
	int todoOk=0;
	eVehiculo aux;
	eTipo auxT1;
	eTipo auxT2;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam-1;i++)
		{
			auxT1=TIPO_buscarSecPorId(tipos, tamT, empleados[i].tipoId);
			for(int j=i+1;j<tam;j++)
			{
				auxT2=TIPO_buscarSecPorId(tipos, tamT, empleados[j].tipoId);
				if(strcmp(auxT1.descripcion,auxT2.descripcion)==1||(strcmp(auxT1.descripcion,auxT2.descripcion)==0&&strcmp(empleados[i].descripcion,empleados[j].descripcion)==1))
				{
					aux=empleados[i];
					empleados[i]=empleados[j];
					empleados[j]=aux;
				}
			}
		}
	}

	return todoOk;
}
/*
int NEXO_mostrarImpTotalxViajeS(eVehiculo empleados[],int tam,eTipo tipos[],int tamTipo)
{
	int todoOk;
	todoOk=-1;
	int aux2;
	int acum=0;

	if(empleados!=NULL&&tam>0&&tipos!=NULL&&tamTipo>0)
	{
		todoOk=0;
		NEXO_mostrarEmpleados(empleados, tam, tipos, tamTipo);
		aux2=UTN_pedirEnteroRango("\nSeleccione id del viaje", 1, 100);
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO && empleados[i].viajeId==aux2)
			{
				acum+=empleados[i].precioViaje;
				todoOk=1;
			}
		}
		if(todoOk==1)
		{
			printf("Importe total acumulado : %d",acum);
		}
	}
	return todoOk;
}*/
