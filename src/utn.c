/*
 * utn.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include "vehiculo.h"

int mostrarMenuP()
{
	int respuesta;
	printf("\n\n              ----------Menu Principal-------------");
	printf("\n1. ALTA VEHICULO");
	printf("\n2. MODIFICAR VEHICULO");
	printf("\n3. BAJA VEHICULO");
	printf("\n4. LISTAR VEHICULO");
	printf("\n5. LISTAR TIPOS");
	printf("\n6. ALTA HOJA DE SERVICIO.");
	printf("\n7. LISTAR HOJAS DE SERVICIO");
	printf("\n8. INFORMES");
	printf("\n9. SALIR");
	scanf("%d",&respuesta);
	return respuesta;
}

int submenuModificar()
{
	int respuesta;
	printf("\n\n              ----------Menu modificaciones-------------");
	printf("\n1. descripcion");
	printf("\n2. precio servicio");
	scanf("%d",&respuesta);
	return respuesta;
}

int mostrarMenuInformes()

{
	int respuesta;
	printf("\n----------Menu Informes-------------");
	printf("\n1. Mostrar viajes de un tipo seleccionado");
	printf("\n2. Mostrar todos los vouchers efectuados en una fecha seleccionada");
	printf("\n3. Informar importe total de los vouchers realizados para un viaje seleccionado");
	printf("\n4. Informar importe total de todos los vouchers de un tipo en una fecha seleccionada");
	scanf("%d",&respuesta);
	return respuesta;
}

int UTN_pedirEnteroRango(char* mensaje, int numMin, int numMax)
{
	int numero;
	printf("%s (entre %d - %d)",mensaje, numMin, numMax);
	scanf("%d",&numero);
	while(numero< numMin || numero > numMax)
	{
		printf("Error !! %s (entre %d - %d",mensaje, numMin, numMax);
		scanf("%d",&numero);
	}
	return numero;
}

int UTN_pedirEnteroSinRango(char* mensaje)
{
	int numero;
	printf("%s",mensaje);
	scanf("%d",&numero);
	return numero;
}



int UTN_pedirFlotanteRango(char* mensaje, int numMin, int numMax)
{
	float numero;
	printf("%s (entre %d - %d)",mensaje, numMin, numMax);
	scanf("%f",&numero);
	while(numero< numMin || numero > numMax)
	{
		printf("Error !! %s (entre %d - %d",mensaje, numMin, numMax);
		scanf("%f",&numero);
	}
	return numero;
}

void UTN_pedirCadena(char mensaje[],char* nombre, int largoNombre)
{
	printf(mensaje);
	fflush(stdin);
	fgets(nombre,largoNombre,stdin);
	nombre[strlen(nombre)-1]='\0';
}

int validarLetras(char* cadena)
{
	int todoOk=-1;
	int auxCad;
	if(cadena!=NULL)
	{
		for(int i=0;i<strlen(cadena);i++)
		{
			if((auxCad=isalpha(cadena[i])==0))
			{
				todoOk=0;
				break;
			}
			todoOk=1;
		}
	}
	return todoOk;
}

int validarEspacio(char* cadena)
{
	int todoOk=-1;
	if(cadena!=NULL)
	{
		for(int i=0;i<strlen(cadena);i++)
		{
			if(isspace(cadena[i]))
			{
				todoOk=0;
				break;
			}
			todoOk=1;
		}
	}
	return todoOk;
}

int UTN_validarIntSinEspoCad(char cadenaNum[])
{
	int todoOk=-1;
	if(cadenaNum!=NULL)
	{
		for(int i=0;i<strlen(cadenaNum);i++)
		{
			if(isdigit(cadenaNum[i])==0 || isspace(cadenaNum[i]==1))
			{
				todoOk=0;
				break;
			}else
				{
					todoOk=1;
				}
		}

	}
	return todoOk;
}

int UTN_pedirEnterosArray(char mensaje[],int rangoArray, char numero[])
{
	int todoOk=0;
	if(mensaje!=NULL)
	{
		printf(mensaje);
		fflush(stdin);
		fgets(numero,rangoArray,stdin);
		numero[strlen(numero)-1]='\0';
		todoOk=1;
	}
	return todoOk;
}

