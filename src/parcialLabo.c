/*
 ============================================================================
 Name        : parcialLabo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "nexo.h"
#define TAM_TIPOS 3
#define TAM_AUTITOS 100
#define TAM_SERVICIOS 100
int main(void) {
	setbuf(stdout,NULL);
	char respuesta='n';
	int id=1;
	int idHoja=20000;
	eTipo tipos[TAM_TIPOS]=
	{
			{1000,"Sedan 3PTAS"},
			{1001,"Sedan 5PTAS"},
			{1002,"Camioneta"}
	};
	eVehiculo autitos[TAM_AUTITOS];
	eHojaServicio servicios[TAM_SERVICIOS];
	VEHICU_inicializarArray(autitos, TAM_AUTITOS);
	HOJA_inicializarArray(servicios, TAM_SERVICIOS);
	while(respuesta=='n')
	{
		switch(mostrarMenuP())
		{
		case 1:
			NEXO_altaEmpleados(autitos, TAM_AUTITOS, id, tipos, TAM_TIPOS);
			id++;
			break;
		case 2:
			switch(submenuModificar())
			{
			case 1:
				NEXO_modificarVehi(autitos, TAM_AUTITOS, tipos, TAM_TIPOS, id);
				break;
			case 2:
				break;
			default:
				printf("\nOpcion invalida.");
				fflush(stdin);
			}
			break;
		case 3:
			NEXO_darDebajaVehi(autitos, TAM_AUTITOS, tipos, TAM_TIPOS);
			break;
		case 4:
			NEXO_ordenXTipoYdestino(autitos, TAM_AUTITOS, tipos, TAM_TIPOS);
			NEXO_mostrarEmpleados(autitos, TAM_AUTITOS, tipos, TAM_TIPOS);
			break;
		case 5:
			TIPO_mostrarSectores(tipos, TAM_TIPOS);
			break;
		case 6:
			NEXO_altaEmpleadosHoja(servicios, TAM_SERVICIOS, idHoja, autitos, TAM_AUTITOS, tipos, TAM_TIPOS);
			idHoja++;
			break;
		case 7:
			NEXO_mostrarHojas(servicios, TAM_SERVICIOS, autitos, TAM_AUTITOS);
			break;
		case 8:
			break;
		case 9:
			break;
		default:
			printf("\nOpcion invalida");
			fflush(stdin);
		}
	}


	return EXIT_SUCCESS;
}
