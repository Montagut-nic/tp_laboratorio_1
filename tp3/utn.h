/*
 * utn.h
 *
 *  Created on: 11 jun. 2021
 *      Author: Montagut
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LEN 2048
#define OK 0
#define ERROR_PARAM -1
#define ERROR_DATOS -2
#define TRUE 1
#define FALSE 0
#define LIM_MAX 1
#define LIM_MIN -1

int utn_getInt(int* pNumero,char mensajePedido[],char mensajeError[],int intentos, int min, int max);
int utn_getIntLimitMaxOrMin(int* pNumero,char mensajePedido[],char mensajeError[],int intentos, int min, int max, int limite);
int utn_getFloat(float* pNumero,char mensajePedido[],char mensajeError[],int intentos,float min,float max);
int utn_getFloatLimitMinOrMax(float* pNumero,char mensajePedido[],char mensajeError[],int intentos,float min,float max,int limite);
int utn_getChar(char* pLetra,char mensajePedido[],char mensajeError[],int intentos,char min,char max);
int utn_getString(char array[],int longitud,char mensajePedido[],char mensajeError[],int intentos);
int utn_getStringSoloNumeros(char array[],int longitud,char mensajePedido[],char mensajeError[],int reintentos);
int utn_getNombre(char array[],int longitud,char mensajePedido[],char mensajeError[],int intentos);
int esNumericoFloat(char array[]);
int esNumericoInt(char array[]);
int esLetra(char array[]);
int esNombre(char *array);
int getInt(int*pResultado);
int getFloat(float*pResultado);
int getChar(char*pResultado);
int getString(char array[], int longitud);
int getStringSoloNumeros(char array[], int longitud);
int getNombre(char array[], int longitud);
int myGets(char* cadena,int longitud);

#endif /* UTN_H_ */
