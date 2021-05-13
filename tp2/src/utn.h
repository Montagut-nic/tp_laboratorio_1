/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
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
#define CUIT_LEN 13
#define LIM_MAX 1
#define LIM_MIN -1
#define UP 1
#define DOWN 0

int utn_getInt(int* pNumero,char*pMensajePedido,char*pMensajeError,int intentos, int min, int max);
int utn_getIntLimitless(int* pNumero,char mensajePedido[],char mensajeError[],int intentos);
int utn_getIntLimitMaxOrMin(int* pNumero,char mensajePedido[],char mensajeError[],int intentos, int min, int max, int limite);
int utn_getFloat(float* pNumero,char*pMensajePedido,char*pMensajeError,int intentos,float min,float max);
int utn_getFloatLimitMinOrMax(float* pNumero,char mensajePedido[],char mensajeError[],int intentos,float min,float max,int limite);
int utn_getChar(char* pLetra,char*pMensajePedido,char*pMensajeError,int intentos,char min,char max);
int utn_getString(char array[],int longitud,char mensajePedido[],char mensajeError[],int intentos);
int utn_getDireccion(char array[],int longitud,char mensajePedido[],char mensajeError[],int intentos);
int utn_getCuit(char array[],int longitud,char mensajePedido[],char mensajeError[],int intentos);
int utn_getName(char array[],int longitud,char mensajePedido[],char mensajeError[],int intentos);

int esNumericoInt(char* array);
int esNumericoFloat(char* array);
int esLetra(char*array);
int esDireccion(char array[]);
int isValidName(char array[]);
int isValidSalary(float salary);
int isValidSector(int sector);
int isValidId(int id);
int esCuit(char array[],int longitud);

int getInt(int*pResultado);
int getFloat(float*pResultado);
int getChar(char*pResultado);
int getString(char array[], int longitud);
int getDireccion(char array[],int longitud);
int getCuit(char array[],int longitud);
int getName(char array[],int longitud);
int myGets(char*cadena,int longitud);

#endif /* UTN_H_ */
