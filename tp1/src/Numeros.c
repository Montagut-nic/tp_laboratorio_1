/*
 * Numero.c
 *
 *  Created on: 15 abr. 2021
 *      Author: Montagut
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Numeros.h"

#define LIMITE_LONG 1754

/**\brief Realiza la suma de dos numeros float y la guarda en un float
 * \param float valorA: es el primer numero float a sumar
 * \param float valorB: es el segundo numero float a sumar
 * \param float* pResultadoSuma: es el puntero al float donde se guarda el resultado de la suma
 * \return int: retorna -1 si hay un error en los parametros, 0 si todo OK
 */
int nums_suma (float valorA,float valorB, float* pResultadoSuma) {
	int retorno =-1;
	if(pResultadoSuma!=NULL){
		*pResultadoSuma=valorA+valorB;
		retorno=0;
	}
	return retorno;
}

/**\brief Realiza la resta entre dos numeros float y la guarda en un float
 * \param float valorA: es el primer numero float de la resta, el minuendo
 * \param float valorB: es el segundo numero float de la resta, el sustraendo
 * \param float* pResultadoResta: es el puntero al float donde se guarda el resultado de la resta
 * \return int: retorna -1 si hay un error en los parametros, 0 si todo OK
 */
int nums_resta (float valorA,float valorB, float* pResultadoResta) {
	int retorno=-1;
	if(pResultadoResta!=NULL){
		*pResultadoResta=valorA-valorB;
		retorno=0;
	}
	return retorno;
}

/**\brief Realiza la multiplicacion entre dos numeros float y la guarda en un float
 * \param float valorA: es el primer numero float de la multiplicacion
 * \param float valorB: es el segundo numero float de la multiplicacion
 * \param float* pResultadoMult: es el puntero al float donde se guarda el resultado de la multiplicacion
 * \return int: retorna -1 si hay un error en los parametros, 0 si todo OK
 */
int nums_multiplicacion (float valorA,float valorB, float* pResultadoMult) {
	int retorno=-1;
	if(pResultadoMult!=NULL){
		*pResultadoMult=valorA*valorB;
		retorno=0;
	}
	return retorno;
}

/**\brief Realiza la division entre dos numeros float y la guarda en un float
 * \param float valorA: es el primer numero float de la division, el dividendo
 * \param float valorB: es el segundo numero float de la division, el divisor
 * \param float* pResultadoDiv: es el puntero al float donde se guarda el resultado de la division, el cociente
 * \return int: retorna -1 si hay un error en los parametros o el divisor es 0, 0 si todo OK
 */
int nums_division (float valorA,float valorB, float* pResultadoDiv) {
	int retorno=-1;
	if(valorB!=0&&pResultadoDiv!=NULL){
		*pResultadoDiv=valorA/valorB;
		retorno=0;
	}
	return retorno;
}

/**\brief Busca el factorial de dos numeros float positivos y lo guarda en un long double
 * \param float valorA: es el primer numero float
 * \param float valorB: es el segundo numero float
 * \param long double* pResultadoFactorialA: es el puntero al long double donde se guarda el resultado del producto de todos los numeros enteros positivos desde 1 hasta el numero de valorA
 * \param long double* pResultadoFactorialB: es el puntero al long double donde se guarda el resultado del producto de todos los numeros enteros positivos desde 1 hasta el numero de valorB
 * \return int: retorna -1 si hay un error en los parametros, 0 si todo OK
 */
int nums_factorial (float valorA,float valorB,long double* pResultadoFactorialA, long double* pResultadoFactorialB){
	int retorno=-1;
	long double buffer=1;
	long double bufferAux=1;
	if(pResultadoFactorialA!=NULL&&pResultadoFactorialB!=NULL&&((int)valorA>=0||(int)valorB>=0)){
		retorno=0;
		if((int)valorA==0){
			*pResultadoFactorialA=1;
		}else{
			if((int)valorA>0&&(int)valorA<=LIMITE_LONG){
				for(int i=1;i<=(int)valorA;i++){
					buffer=buffer*i;
				}
				*pResultadoFactorialA=buffer;
			}
		}
		if((int)valorB==0){
			*pResultadoFactorialB=1;
		}else{
			if((int)valorB>0&&(int)valorB<=LIMITE_LONG){
				for(int j=1;j<=(int)valorB;j++){
					bufferAux=bufferAux*j;
				}
				*pResultadoFactorialB=bufferAux;
			}
		}
	}
	return retorno;
}

/**\brief Imprime los resultados de las operaciones, guardados en las campos de una variable tipo estructura S_Numeros
 * \param S_Numeros operandos: es una variable de tipo estructura de S_Numeros
 */
void nums_informarResultados(S_Numeros operandos){
	printf("\nEl resultado de %.2f + %.2f es: %f\n",operandos.valorA,operandos.valorB,operandos.resultadoSuma);
	printf("El resultado de %.2f - %.2f es: %.2f\n",operandos.valorA,operandos.valorB,operandos.resultadoResta);
	if(operandos.valorB!=0){
		printf("El resultado de %.2f / %.2f es: %.2f\n",operandos.valorA,operandos.valorB,operandos.resultadoDiv);
	}else{
		printf("No es posible dividir por cero\n");
	}
	printf("El resultado de %.2f * %.2f es: %.2f\n",operandos.valorA,operandos.valorB,operandos.resultadoMult);
	if(operandos.valorB>=0&&operandos.valorA>=0){
		if(operandos.valorB<=LIMITE_LONG&&operandos.valorA<=LIMITE_LONG){
			__mingw_printf("El factorial de %d es: %LG y el factorial de %d es: %LG\n\n",(int)operandos.valorA,operandos.factorialA,(int)operandos.valorB,operandos.factorialB);
		}else{
			if(operandos.valorB>LIMITE_LONG&&operandos.valorA<=LIMITE_LONG){
				__mingw_printf("El factorial de %d es: %LG y el factorial de %d es mayor a lo que permite la variable(1.19E+4932)\n\n",(int)operandos.valorA,operandos.factorialA,(int)operandos.valorB);
			}
			if(operandos.valorB<=LIMITE_LONG&&operandos.valorA>LIMITE_LONG){
				__mingw_printf("El factorial de %d es mayor a lo que permite la variable(1.19E+4932) y el factorial de %d es: %LG\n\n",(int)operandos.valorA,(int)operandos.valorB,operandos.factorialB);
			}
		}
	}else{
		if(operandos.valorB<0&&operandos.valorA>=0){
			__mingw_printf("No es posible realizar el factorial de %d y el factorial de %d es: %LG,\n\n",(int)operandos.valorB,(int)operandos.valorA,operandos.factorialA);
		}
		if(operandos.valorB>=0&&operandos.valorA<0){
			__mingw_printf("No es posible realizar el factorial de %d y el factorial de %d es: %LG\n\n",(int)operandos.valorA,(int)operandos.valorB,operandos.factorialB);
		}
		if(operandos.valorB<0&&operandos.valorA<0){
			printf("No es posible realizar el factorial de ninguno de los operandos\n\n");
		}
	}

}
