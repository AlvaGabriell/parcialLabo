/*
 * utn.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
int mostrarMenuP();
int submenuModificar();
int mostrarMenuInformes();
int UTN_pedirEnteroRango(char* mensaje, int numMin, int numMax);
int UTN_pedirEnteroSinRango(char* mensaje);
int UTN_pedirFlotanteRango(char* mensaje, int numMin, int numMax);
void UTN_pedirCadena(char mensaje[],char* nombre, int largoNombre);
int validarLetras(char* cadena);
int validarEspacio(char* cadena);
int UTN_validarIntSinEspoCad(char cadenaNum[]);
int UTN_pedirEnterosArray(char mensaje[],int rangoArray, char numero[]);
