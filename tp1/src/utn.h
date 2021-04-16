/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: Montagut
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int* pNumero,char*pMensajePedido,char*pMensajeError,int intentos, int min, int max);
int utn_getFloat(float* pNumero,char*pMensajePedido,char*pMensajeError,int intentos,float min,float max);
int utn_getChar(char* pLetra,char*pMensajePedido,char*pMensajeError,int intentos,char min,char max);

int esNumericoInt(char* array);
int esNumericoFloat(char* array);
int esLetra(char*array);
int getInt(int*pResultado);
int getFloat(float*pResultado);
int getChar(char*pResultado);
int myGets(char*cadena,int longitud);

#endif /* UTN_H_ */
