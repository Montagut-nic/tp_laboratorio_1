#include "validaciones.h"

/** \brief Valida si la cadena de caracteres ingresada es un id valido
 * \param idStr char*: cadena de caracteres que se valida
 * \return int: retorna 0 si es false, 1 si es true, -1 si la cadena es NULL
 */
int isValidId (char* idStr){
	int retorno = -1;
	int i=0;
	if(idStr != NULL){
		retorno=1;
		for(;idStr[i]!='\0';i++){
			if(idStr[i]>'9'||idStr[i]<'0'){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Valida si la cadena de caracteres ingresada es un nombre valido
 * \param nombreStr char*: cadena de caracteres que se valida
 * \return int: retorna 0 si es false, 1 si es true, -1 si la cadena es NULL
 */
int isValidNombre(char *nombreStr){
	int retorno=-1;
	int i=0;
	if(nombreStr!=NULL){
		retorno=1;
		for (;nombreStr[i]!='\0';i++){
			if ( (nombreStr[i]>'Z'||nombreStr[i]<'A') &&
				 (nombreStr[i]>'z'||nombreStr[i]<'a') &&
				 nombreStr[i]!=' '
				)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Valida si la cadena de caracteres ingresada es un numero entero valido
 * \param horasTrabajadasStr char*: cadena de caracteres que se valida
 * \return int: retorna 0 si es false, 1 si es true, -1 si la cadena es NULL
 */
int isValidHorasTrabajadas (char* horasTrabajadasStr)
{
	int retorno = -1;
	int i=0;
	if(horasTrabajadasStr != NULL){
		retorno=1;
		for(;horasTrabajadasStr[i]!='\0';i++){
			if(horasTrabajadasStr[i]>'9'||horasTrabajadasStr[i]<'0'){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Valida si la cadena de caracteres ingresada es un sueldo valido
 * \param sueldoStr char*: cadena de caracteres que se valida
 * \return int: retorna 0 si es false, 1 si es true, -1 si la cadena es NULL
 */
int isValidSueldo (char* sueldoStr){
	int retorno = -1;
	int i=0;
	if(sueldoStr != NULL){
		retorno=1;
		for(;sueldoStr[i]!='\0';i++){
			if(sueldoStr[i]>'9'||sueldoStr[i]<'0'){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
