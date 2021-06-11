#include "validaciones.h"

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

int isValidNombre(char *nombreStr){
	int retorno=-1;
	int i=0;
	if(nombreStr!=NULL){
		retorno=1;
		for (;nombreStr[i]!='\0';i++){
			if ( (nombreStr[i]>'Z'||nombreStr[i]<'A') &&
				 (nombreStr[i]>'z'||nombreStr[i]<'a') &&
				 nombreStr[i]!=' ' &&
				 nombreStr[i]!='-' &&
				 nombreStr[i]!=39// ' (comilla simple)
				)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

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
