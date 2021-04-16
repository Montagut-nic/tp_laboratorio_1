/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: Montagut
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Numeros.h"

#define ARRAY_LEN 16


/** \brief Solicita un numero de tipo entero al usuario y lo valida
 * \param int* pNumero: es el puntero al int donde se guarda el numero ingresado
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \param int min: es el numero minimo que se le permite ingresar al usuario
 * \param int max: es el numero maximo que se le permite ingresar al usuario
 * \return int: retorna -1 si hay un error en los parametros, -2 si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getInt(int* pNumero,char mensajePedido[],char mensajeError[],int intentos, int min, int max)
{
	int retorno = -1;
	int bufferInt;
	int respuesta;
	if(pNumero != NULL && mensajePedido != NULL && mensajeError != NULL && min<=max && intentos >= 0){
		retorno = -2;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getInt(&bufferInt);
			if (respuesta==0){
				printf("Ingresaste: %d\n",bufferInt);
				if(bufferInt>=min&&bufferInt<=max){
					retorno = 0;
					*pNumero=bufferInt;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

/** \brief Solicita un numero de tipo float al usuario y lo valida
 * \param float* pNumero: es el puntero al float donde se guarda el numero ingresado
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \param float min: es el numero minimo que se le permite ingresar al usuario
 * \param float max: es el numero maximo que se le permite ingresar al usuario
 * \return int: retorna -1 si hay un error en los parametros, -2 si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getFloat(float* pNumero,char mensajePedido[],char mensajeError[],int intentos,float min,float max)
{
	int retorno = -1;
	float bufferFloat;
	int respuesta;
	if(pNumero != NULL && mensajePedido != NULL && mensajeError != NULL && min<=max && intentos >= 0){
		retorno = -2;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getFloat(&bufferFloat);
			if (respuesta==0){
				printf("Ingresaste: %.2f\n",bufferFloat);
				if(bufferFloat>=min&&bufferFloat<=max){
					retorno = 0;
					*pNumero=bufferFloat;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

/** \brief Solicita un caracter al usuario y lo valida
 * \param char* pLetra: es el puntero al char donde se guarda el caracter ingresado
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \param char min: es el caracter minimo que se le permite ingresar al usuario
 * \param char max: es el caracter maximo que se le permite ingresar al usuario
 * \return int: retorna -1 si hay un error en los parametros, -2 si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getChar(char* pLetra,char mensajePedido[],char mensajeError[],int intentos,char min,char max)
{
	int retorno = -1;
	char bufferChar;
	int respuesta;
	if(pLetra != NULL && mensajePedido != NULL && mensajeError != NULL && min<=max && intentos >= 0){
		retorno = -2;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getChar(&bufferChar);
			if (respuesta==0){
				printf("Ingresaste: %c\n",bufferChar);
				if(bufferChar>=min&&bufferChar<=max){
					retorno = 0;
					*pLetra=bufferChar;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

/** \brief Valida si el array ingresado es un numero de tipo float
 * \param char* array: array que se valida
 * \return int: retorna -1 si el array es NULL, 0 es false, 1 es true
 */
int esNumericoFloat(char* array){
	int retorno=-1;
	int i=0;
	int flagPunto=0;
	if(array!=NULL){
		retorno=1;
		if(array[0]=='-'){
			i=1;
		}
		for(;array[i]!='\0';i++){
			if(array[i]>'9'||array[i]<'0'){
				if(array[i]=='.'&&flagPunto==0&&i!=(strlen(array)-1)){
					flagPunto=1;
				}else{
					retorno=0;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Valida si el array ingresado es un numero de tipo int
 * \param char* array: array que se valida
 * \return int: retorna -1 si el array es NULL, 0 es false, 1 es true
 */
int esNumericoInt(char* array){
	int retorno=-1;
	int i=0;
	if(array!=NULL){
		retorno=1;
		if(array[0]=='-'){
			i=1;
		}
		for(;array[i]!='\0';i++){
			if(array[i]>'9'||array[i]<'0'){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Valida si el array ingresado es una letra
 * \param char* array: array que se valida
 * \return int: retorna -1 si el array es NULL, 0 es false, 1 es true
 */
int esLetra(char*array){
	int retorno=-1;
	int i;
	if(array!=NULL){
		retorno=1;
		for (i=0;array[i]!='\0';i++){
			if((array[i]>'Z'||array[i]<'A')&&(array[i]>'z'||array[i]<'a')){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief pide un array al usuario, lo pasa a int y lo guarda en una variable int
 * \param int* pResultado: puntero al int donde se guarda el numero
 * \return int: retorna -1 si el puntero es NULL, -2 si el array no puede ser int, 0 si todo OK
 */
int getInt(int*pResultado){
	int retorno=-1;
	char buffer[ARRAY_LEN];
	if (pResultado!=NULL){
		retorno=-2;
		myGets(buffer,sizeof(buffer));
		if(esNumericoInt(buffer)==1){
			*pResultado=atoi(buffer);
			retorno=0;
		}
	}
	return retorno;
}

/** \brief pide un array al usuario, lo pasa a float y lo guarda en una variable de tipo float
 * \param float* pResultado: puntero al float donde se guarda el numero
 * \return int: retorna -1 si el puntero es NULL, -2 si el array no puede ser float, 0 si todo OK
 */
int getFloat(float*pResultado){
	int retorno=-1;
	char buffer[ARRAY_LEN];
	if (pResultado!=NULL){
		retorno=-2;
		myGets(buffer,sizeof(buffer));
		if(esNumericoFloat(buffer)==1){
			*pResultado=atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}

/** \brief pide un char al usuario, valida que sea una letra y lo guarda en una variable de tipo char
 * \param char* pResultado: puntero al char donde se guarda la letra
 * \return int: retorna -1 si el puntero es NULL, -2 si no se ingresa una letra, 0 si todo OK
 */
int getChar(char*pResultado){
	int retorno=-1;
	char buffer;
	if(pResultado!=NULL){
		retorno=-2;
		myGets(&buffer,sizeof(buffer));
		if(esLetra(&buffer)==1){
			*pResultado=buffer;
			retorno=0;
		}
	}
	return retorno;
}

/** \brief pide un array al usuario y inserta un '\0' al final de la cadena ingresada
 * \param char* cadena: array donde se guarda la cadena de caracteres ingresada
 * \return int: retorna -1 si hay un error, 0 si todo OK
 */
int myGets(char*cadena,int longitud){
	int retorno = -1;
	if (cadena!=NULL&&longitud>0&&fgets(cadena,longitud,stdin)==cadena){
		fflush(stdin);
		if(cadena[strlen(cadena)-1]=='\n'){
			cadena[strlen(cadena)-1]='\0';
		}
		retorno=0;
	}
	return retorno;
}
