/*
 * tipo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */

#include "tipo.h"
void TIPO_mostrarSector(eTipo sector)
{
	printf("\n%3d         %10s",sector.idTipo,sector.descripcion);
}



int TIPO_mostrarSectores(eTipo sector[],int tam)
{
	int todoOk=0;
	if(sector!=NULL&&tam>0)
	{
		printf("\n  ID        DESCRIPCION");
		for(int i=0;i<tam;i++)
		{
			TIPO_mostrarSector(sector[i]);
		}
	}

	return todoOk;
}

eTipo TIPO_buscarSecPorId(eTipo listaSec[],int tamSec,int id)
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
