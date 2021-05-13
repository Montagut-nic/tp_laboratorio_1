/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: Montagut
 */

#include "utn.h"


/** \brief Solicita un numero de tipo entero al usuario, con un limite maximo y minimo, y lo valida
 * \param int* pNumero: es el puntero al int donde se guarda el numero ingresado
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \param int min: es el numero minimo que se le permite ingresar al usuario
 * \param int max: es el numero maximo que se le permite ingresar al usuario
 * \return int: retorna -1 (ERROR_PARAM) si hay un error en los parametros, -2 (ERROR_DATOS) si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getInt(int* pNumero,char mensajePedido[],char mensajeError[],int intentos, int min, int max){
	int retorno = ERROR_PARAM;
	int bufferInt;
	int respuesta;
	if(pNumero != NULL && mensajePedido != NULL && mensajeError != NULL && min<=max && intentos >= 0){
		retorno = ERROR_DATOS;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getInt(&bufferInt);
			if (respuesta==OK){
				if(bufferInt>=min&&bufferInt<=max){
					retorno = OK;
					*pNumero=bufferInt;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}


/** \brief Solicita un numero de tipo entero al usuario, sin limites de maximo o minimo, y lo valida
 * \param int* pNumero: es el puntero al int donde se guarda el numero ingresado
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \return int: retorna -1 (ERROR_PARAM) si hay un error en los parametros, -2 (ERROR_DATOS) si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getIntLimitless(int* pNumero,char mensajePedido[],char mensajeError[],int intentos){
	int retorno = ERROR_PARAM;
	int bufferInt;
	int respuesta;
	if(pNumero != NULL && mensajePedido != NULL && mensajeError != NULL && intentos >= 0){
		retorno = ERROR_DATOS;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getInt(&bufferInt);
			if (respuesta==OK){
				retorno = OK;
				*pNumero=bufferInt;
				break;
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}


/** \brief Solicita un numero de tipo entero al usuario, con un limite maximo o minimo, y lo valida
 * \param int* pNumero: es el puntero al int donde se guarda el numero ingresado
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \param int min: es el numero minimo que se le permite ingresar al usuario
 * \param int max: es el numero maximo que se le permite ingresar al usuario
 * \param int limite: es el tipo de limite que se quiere poner, maximo(LIM_MAX) = 1, minimo(LIM_MIN) = 0
 * \return int: retorna -1 (ERROR_PARAM) si hay un error en los parametros, -2 (ERROR_DATOS) si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getIntLimitMaxOrMin(int* pNumero,char mensajePedido[],char mensajeError[],int intentos, int min, int max, int limite){
	int retorno = ERROR_PARAM;
	int bufferInt;
	int respuesta;
	if(pNumero != NULL && mensajePedido != NULL && mensajeError != NULL && intentos >= 0 && (limite==LIM_MAX||limite==LIM_MIN) ){
		retorno = ERROR_DATOS;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getInt(&bufferInt);
			if (respuesta==OK){
				if(bufferInt>=min&&limite==LIM_MIN){
					retorno = OK;
					*pNumero=bufferInt;
					break;
				}
				if(bufferInt<=max&&limite==LIM_MAX){
					retorno = OK;
					*pNumero=bufferInt;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

/** \brief Solicita un numero de tipo float al usuario, con limites de minimo y maximo, y lo valida
 * \param float* pNumero: es el puntero al float donde se guarda el numero ingresado
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \param float min: es el numero minimo que se le permite ingresar al usuario
 * \param float max: es el numero maximo que se le permite ingresar al usuario
 * \return int: retorna -1 (ERROR_PARAM) si hay un error en los parametros, -2 (ERROR_DATOS) si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getFloat(float* pNumero,char mensajePedido[],char mensajeError[],int intentos,float min,float max){
	int retorno = ERROR_PARAM;
	float bufferFloat;
	int respuesta;
	if(pNumero != NULL && mensajePedido != NULL && mensajeError != NULL && min<=max && intentos >= 0){
		retorno = ERROR_DATOS;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getFloat(&bufferFloat);
			if (respuesta==OK){
				if(bufferFloat>=min&&bufferFloat<=max){
					retorno = OK;
					*pNumero=bufferFloat;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}


/** \brief Solicita un numero de tipo float al usuario, con limites de minimo o maximo, y lo valida
 * \param float* pNumero: es el puntero al float donde se guarda el numero ingresado
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \param float min: es el numero minimo que se le permite ingresar al usuario
 * \param float max: es el numero maximo que se le permite ingresar al usuario
 * \param int limite: es el tipo de limite que se quiere poner, maximo(LIM_MAX) = 1, minimo(LIM_MIN) = 0
 * \return int: retorna -1 (ERROR_PARAM) si hay un error en los parametros, -2 (ERROR_DATOS) si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getFloatLimitMinOrMax(float* pNumero,char mensajePedido[],char mensajeError[],int intentos,float min,float max,int limite){
	int retorno = ERROR_PARAM;
	float bufferFloat;
	int respuesta;
	if(pNumero != NULL && mensajePedido != NULL && mensajeError != NULL && (limite==LIM_MAX||limite==LIM_MIN) && intentos >= 0){
		retorno = ERROR_DATOS;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getFloat(&bufferFloat);
			if (respuesta==OK){
				if(bufferFloat>=min&&limite==LIM_MIN){
					retorno = OK;
					*pNumero=bufferFloat;
					break;
				}
				if(limite==LIM_MAX&&bufferFloat<=max){
					retorno = OK;
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
 * \return int: retorna -1 (ERROR_PARAM) si hay un error en los parametros, -2 (ERROR_DATOS) si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getChar(char* pLetra,char mensajePedido[],char mensajeError[],int intentos,char min,char max){
	int retorno = ERROR_PARAM;
	char bufferChar;
	int respuesta;
	if(pLetra != NULL && mensajePedido != NULL && mensajeError != NULL && min<=max && intentos >= 0){
		retorno = ERROR_DATOS;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getChar(&bufferChar);
			if (respuesta==OK){
				if(bufferChar>=min&&bufferChar<=max){
					retorno = OK;
					*pLetra=bufferChar;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

/** \brief Solicita una cadena de caracteres al usuario y lo valida
 * \param char array[]: es el array de tipo char donde se guarda la cadena de caracteres ingresado
 * \param int longitud: es el tama�o del array donde se guarda la cadena de caracteres
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \return int: retorna -1 (ERROR_PARAM) si hay un error en los parametros, -2 (ERROR_DATOS) si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getString(char array[],int longitud,char mensajePedido[],char mensajeError[],int intentos){
	int retorno = ERROR_PARAM;
	char bufferStr[ARRAY_LEN];
	int respuesta;
	if(array != NULL && mensajePedido != NULL && mensajeError != NULL && intentos >= 0 && longitud>0){
		retorno = ERROR_DATOS;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getString(bufferStr,sizeof(bufferStr));
			if (respuesta==OK&&strnlen(bufferStr,sizeof(bufferStr))<=longitud){
				retorno = OK;
				strncpy(array,bufferStr,longitud);
				break;
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

/** \brief Solicita una cadena de caracteres al usuario y valida que sea una direccion valida
 * \param char array[]: es el array de tipo char donde se guarda la direccion ingresada
 * \param int longitud: es el tama�o del array donde se guarda la direccion
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \return int: retorna -1 (ERROR_PARAM) si hay un error en los parametros, -2 (ERROR_DATOS) si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getDireccion(char array[],int longitud,char mensajePedido[],char mensajeError[],int intentos)
{
	int retorno = ERROR_PARAM;
	char bufferStr[ARRAY_LEN];
	int respuesta;
	if(array != NULL && mensajePedido != NULL && mensajeError != NULL && intentos >= 0 && longitud>0){
		retorno = ERROR_DATOS;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getDireccion(bufferStr,sizeof(bufferStr));
			if (respuesta==OK&&strnlen(bufferStr,sizeof(bufferStr))<=longitud){
				retorno = OK;
				strncpy(array,bufferStr,longitud);
				break;
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}


/** \brief Solicita una cadena de caracteres al usuario y valida que sea un cuit valido
 * \param char array[]: es el array de tipo char donde se guarda el cuit ingresado
 * \param int longitud: es el tama�o del array donde se guarda el cuit
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \return int: retorna -1 (ERROR_PARAM) si hay un error en los parametros, -2 (ERROR_DATOS) si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getCuit(char array[],int longitud,char mensajePedido[],char mensajeError[],int intentos)
{
	int retorno = ERROR_PARAM;
	char bufferStr[ARRAY_LEN];
	int respuesta;
	if(array != NULL && mensajePedido != NULL && mensajeError != NULL && intentos >= 0 && longitud>0){
		retorno = ERROR_DATOS;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getCuit(bufferStr,sizeof(bufferStr));
			if (respuesta==OK&&strnlen(bufferStr,sizeof(bufferStr))<=longitud){
				retorno = OK;
				strncpy(array,bufferStr,longitud);
				break;
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}


/** \brief Solicita una cadena de caracteres al usuario y valida que sea un nombre
 * \param char array[]: es el array de tipo char donde se guarda el nombre ingresado
 * \param int longitud: es el tama�o del array donde se guarda el nombre
 * \param char mensajePedido[]: es el mensaje con el que se le pide al usuario que ingrese datos
 * \param char mensajeError[]: es el mensaje a mostar en caso de error del usuario al ingresar datos
 * \param int intentos: es la cantidad de reintentos que se le permite al usuario
 * \return int: retorna -1 (ERROR_PARAM) si hay un error en los parametros, -2 (ERROR_DATOS) si el usuario ingresa mal los datos y se queda sin reintentos, 0 si todo esta OK
 */
int utn_getNombre(char array[],int longitud,char mensajePedido[],char mensajeError[],int intentos)
{
	int retorno = ERROR_PARAM;
	char bufferStr[ARRAY_LEN];
	int respuesta;
	if(array != NULL && mensajePedido != NULL && mensajeError != NULL && intentos >= 0 && longitud>0){
		retorno = ERROR_DATOS;
		for(;intentos>=0;intentos--){
			printf("%s",mensajePedido);
			respuesta=getNombre(bufferStr,sizeof(bufferStr));
			if (respuesta==OK&&strnlen(bufferStr,sizeof(bufferStr))<=longitud){
				retorno = OK;
				strncpy(array,bufferStr,longitud);
				break;
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}

/** \brief Valida si el array ingresado es un numero de tipo float
 * \param char array[]: array que se valida
 * \return int: retorna -1 (ERROR_PARAM) si el array es NULL, 0 si es false, 1 si es true
 */
int esNumericoFloat(char array[]){
	int retorno=ERROR_PARAM;
	int i=0;
	int flagPunto=FALSE;
	if(array!=NULL){
		retorno=TRUE;
		if(array[0]=='-'){
			i=1;
		}
		for(;array[i]!='\0';i++){
			if(array[i]>'9'||array[i]<'0'){
				if(array[i]=='.'&&flagPunto==FALSE&&i!=(strlen(array)-1)){
					flagPunto=TRUE;
				}else{
					retorno=FALSE;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Valida si el array ingresado es un numero de tipo int
 * \param char array[]: array que se valida
 * \return int: retorna -1 (ERROR_PARAM) si el array es NULL, 0 es false, 1 es true
 */
int esNumericoInt(char array[]){
	int retorno=ERROR_PARAM;
	int i=0;
	if(array!=NULL){
		retorno=TRUE;
		if(array[0]=='-'){
			i=1;
		}
		for(;array[i]!='\0';i++){
			if(array[i]>'9'||array[i]<'0'){
				retorno=FALSE;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Valida si el array ingresado contiene solo letras
 * \param char array[]: array que se valida
 * \return int: retorna -1 (ERROR_PARAM) si el array es NULL, 0 es false, 1 es true
 */
int esLetra(char array[]){
	int retorno=ERROR_PARAM;
	int i;
	if(array!=NULL){
		retorno=TRUE;
		for (i=0;array[i]!='\0';i++){
			if((array[i]>'Z'||array[i]<'A')&&(array[i]>'z'||array[i]<'a')){
				retorno=FALSE;
				break;
			}
		}
	}
	return retorno;
}


/** \brief Valida si el array ingresado contiene solo letras, numeros y espacios
 * \param char array[]: array que se valida
 * \return int: retorna -1 (ERROR_PARAM) si el array es NULL, 0 es false, 1 es true
 */
int esDireccion(char array[]){
	int retorno=ERROR_PARAM;
	int i;
	if(array!=NULL){
		retorno=TRUE;
		for (i=0;array[i]!='\0';i++){
			if((array[i]>'Z'||array[i]<'A')
				&& (array[i]>'z'||array[i]<'a')
				&& (array[i]>'9'||array[i]<'0')
				&& array[i]!=' '){
				retorno=FALSE;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Valida si el array ingresado es un cuit (contiene solo 2 guiones y 11 numeros)
 * \param char array[]: array que se valida
 * \param int longitud: el tama�o del array que se valida
 * \return int: retorna -1 (ERROR_PARAM) si el array es NULL o longitud no es mayor a 0, 0 es false, 1 es true
 */
int esCuit(char array[],int longitud){
	int retorno=ERROR_PARAM;
	int i;
	int contadorGuiones=0;
	if(array!=NULL&&longitud>0){
		retorno=FALSE;
		if(strnlen(array,longitud)==CUIT_LEN){
			retorno=TRUE;
			for (i=0;array[i]!='\0';i++){
				if(array[i]=='-'){
					contadorGuiones++;
				}
				if((array[i]>'9'||array[i]<'0')
					&& (array[i]!='-' || (array[i]=='-'&&contadorGuiones>2) )){
					retorno=FALSE;
					break;
				}
			}
			if(contadorGuiones<2){
				retorno=FALSE;
			}
		}
	}
	return retorno;
}

/** \brief Valida si el array ingresado es un nombre (contiene letras, espacios o comilla simple)
 * \param char array[]: array que se valida
 * \return int: retorna -1 (ERROR_PARAM) si el array es NULL, 0 es false, 1 es true
 */
int esNombre(char array[]){
	int retorno=ERROR_PARAM;
	int i;
	if(array!=NULL){
		retorno=TRUE;
		for (i=0;array[i]!='\0';i++){
			if((array[i]>'Z'||array[i]<'A')
				&&(array[i]>'z'||array[i]<'a')
				&&array[i]!=' '
				&&array[i]!=39)
			{
				retorno=FALSE;
				break;
			}
		}
	}
	return retorno;
}

/** \brief pide un array al usuario, lo pasa a int y lo guarda en una variable int
 * \param int* pResultado: puntero al int donde se guarda el numero
 * \return int: retorna -1 (ERROR_PARAM) si el puntero es NULL, -2 (ERROR_DATOS) si el array no puede ser int, 0 si todo OK
 */
int getInt(int*pResultado){
	int retorno=ERROR_PARAM;
	char buffer[ARRAY_LEN];
	if (pResultado!=NULL){
		retorno=ERROR_DATOS;
		myGets(buffer,sizeof(buffer));
		if(esNumericoInt(buffer)==TRUE){
			*pResultado=atoi(buffer);
			retorno=OK;
		}
	}
	return retorno;
}

/** \brief pide un array al usuario, lo pasa a float y lo guarda en una variable de tipo float
 * \param float* pResultado: puntero al float donde se guarda el numero
 * \return int: retorna -1 (ERROR_PARAM) si el puntero es NULL, -2 (ERROR_DATOS) si el array no puede ser float, 0 si todo OK
 */
int getFloat(float*pResultado){
	int retorno=ERROR_PARAM;
	char buffer[ARRAY_LEN];
	if (pResultado!=NULL){
		retorno=ERROR_DATOS;
		myGets(buffer,sizeof(buffer));
		if(esNumericoFloat(buffer)==TRUE){
			*pResultado=atof(buffer);
			retorno=OK;
		}
	}
	return retorno;
}

/** \brief pide un char al usuario, valida que sea una letra y lo guarda en una variable de tipo char
 * \param char* pResultado: puntero al char donde se guarda la letra
 * \return int: retorna -1 (ERROR_PARAM) si el puntero es NULL, -2 (ERROR_DATOS) si no se ingresa una letra, 0 si todo OK
 */
int getChar(char*pResultado){
	int retorno=ERROR_PARAM;
	char buffer;
	if(pResultado!=NULL){
		retorno=ERROR_DATOS;
		myGets(&buffer,sizeof(buffer));
		if(esLetra(&buffer)==TRUE){
			*pResultado=buffer;
			retorno=OK;
		}
	}
	return retorno;
}

/** \brief pide una cadeana de caracteres al usuario, valida que contenga solo letras y lo guarda en un array de tipo char
 * \param char array[]: array donde se guarda la cadena de caracteres
 * \param int longitud: es el tama�o del array donde se guarda la cadena de caracteres
 * \return int: retorna -1 (ERROR_PARAM) si el array es NULL o longitud no es mayor a 0, -2 (ERROR_DATOS) si no se ingresa solo letras, 0 si todo OK
 */
int getString(char array[], int longitud){
	int retorno=ERROR_PARAM;
	char buffer[ARRAY_LEN];
	if(array!=NULL&&longitud>0){
		retorno=ERROR_DATOS;
		myGets(buffer,sizeof(buffer));
		if(esLetra(buffer)==TRUE&&strnlen(buffer,sizeof(buffer))<=longitud){
			strncpy(array,buffer,longitud);
			retorno=OK;
		}
	}
	return retorno;
}


/** \brief pide una cadeana de caracteres al usuario, valida que sea una direccion valida y lo guarda en un array de tipo char
 * \param char array[]: array donde se guarda la cadena de caracteres
 * \param int longitud: es el tama�o del array donde se guarda la cadena de caracteres
 * \return int: retorna -1 (ERROR_PARAM) si el array es NULL o longitud no es mayor a 0, -2 (ERROR_DATOS) si no se ingresa solo letras, 0 si todo OK
 */
int getDireccion(char array[],int longitud){
	int retorno=ERROR_PARAM;
	char buffer[ARRAY_LEN];
	if(array!=NULL&&longitud>0){
		retorno=ERROR_DATOS;
		myGets(buffer,sizeof(buffer));
		if(esDireccion(buffer)==TRUE&&strnlen(buffer,sizeof(buffer))<=longitud){
			strncpy(array,buffer,longitud);
			retorno=OK;
		}
	}
	return retorno;
}


/** \brief pide una cadeana de caracteres al usuario, valida que sea un cuit valido y lo guarda en un array de tipo char
 * \param char array[]: array donde se guarda la cadena de caracteres
 * \param int longitud: es el tama�o del array donde se guarda la cadena de caracteres
 * \return int: retorna -1 (ERROR_PARAM) si el array es NULL o longitud no es mayor a 0, -2 (ERROR_DATOS) si no se ingresa solo letras, 0 si todo OK
 */
int getCuit(char array[],int longitud){
	int retorno=ERROR_PARAM;
	char buffer[ARRAY_LEN];
	if(array!=NULL&&longitud>0){
		retorno=ERROR_DATOS;
		myGets(buffer,sizeof(buffer));
		if(esCuit(buffer,sizeof(buffer))==TRUE&&strnlen(buffer,sizeof(buffer))<=longitud){
			strncpy(array,buffer,longitud);
			retorno=OK;
		}
	}
	return retorno;
}

/** \brief pide una cadeana de caracteres al usuario, valida que sea un nombre valido y lo guarda en un array de tipo char
 * \param char array[]: array donde se guarda la cadena de caracteres
 * \param int longitud: es el tama�o del array donde se guarda la cadena de caracteres
 * \return int: retorna -1 (ERROR_PARAM) si el array es NULL o longitud no es mayor a 0, -2 (ERROR_DATOS) si no se ingresa solo letras, 0 si todo OK
 */
int getNombre(char array[],int longitud){
	int retorno=ERROR_PARAM;
	char buffer[ARRAY_LEN];
	if(array!=NULL&&longitud>0){
		retorno=ERROR_DATOS;
		myGets(buffer,sizeof(buffer));
		if(esNombre(buffer)==TRUE&&strnlen(buffer,sizeof(buffer))<=longitud){
			strncpy(array,buffer,longitud);
			retorno=OK;
		}
	}
	return retorno;
}

/** \brief pide un array al usuario y inserta un '\0' al final de la cadena ingresada
 * \param char* cadena: array donde se guarda la cadena de caracteres ingresada
 * \return int: retorna -1 (ERROR_PARAM) si hay un error, 0 si todo OK
 */
int myGets(char* cadena,int longitud){
	int retorno=ERROR_PARAM;
	char bufferString[4096];
	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno=OK;
			}
		}
	}
	return retorno;
}




