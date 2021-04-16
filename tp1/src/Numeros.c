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

void nums_suma (float valorA,float valorB, float* resultadoSuma) {
	*resultadoSuma=valorA+valorB;
}
void nums_resta (float valorA,float valorB, float* resultadoResta) {
	*resultadoResta=valorA-valorB;
}
void nums_multiplicacion (float valorA,float valorB, float* resultadoMult) {
	*resultadoMult=valorA*valorB;
}
int nums_division (float valorA,float valorB, float* resultadoDiv) {
	int retorno=-1;
	if(valorB!=0){
		*resultadoDiv=valorA/valorB;
		retorno=0;
	}
	return retorno;
}
void nums_factorial (float valorA,float valorB, double* resultadoFactorialA, double* resultadoFactorialB){

	double buffer=1;
	double bufferAux=1;
	if(valorA==0){
		*resultadoFactorialA=1;
	}else{
		if(valorA>0){
			for(int i=1;i<=(int)valorA;i++){
				buffer=buffer*i;
			}
			*resultadoFactorialA=buffer;
		}
	}
	if(valorB==0){
		*resultadoFactorialB=1;
	}else{
		if(valorB>0){
			for(int j=1;j<=(int)valorB;j++){
				bufferAux=bufferAux*j;
			}
			*resultadoFactorialB=bufferAux;
		}
	}
}
void nums_informarResultados(Numeros operandos){
	printf("\nEl resultado de %.2f + %.2f es: %f\n",operandos.valorA,operandos.valorB,operandos.resultadoSuma);
	printf("El resultado de %f - %f es: %f\n",operandos.valorA,operandos.valorB,operandos.resultadoResta);
	if(operandos.valorB!=0){
		printf("El resultado de %.2f / %.2f es: %.2f\n",operandos.valorA,operandos.valorB,operandos.resultadoDiv);
	}else{
		printf("No es posible dividir por cero\n");
	}
	printf("El resultado de %.2f * %.2f es: %.2f\n",operandos.valorA,operandos.valorB,operandos.resultadoMult);
	if(operandos.valorB>=0&&operandos.valorA>=0){
		if(operandos.valorB<=170&&operandos.valorA<=170){
			printf("El factorial de %d es: %g y el factorial de %d es: %g\n\n",(int)operandos.valorA,operandos.factorialA,(int)operandos.valorB,operandos.factorialB);
		}else{
			if(operandos.valorB>170&&operandos.valorA<=170){
				printf("El factorial de %d es: %g y el factorial de %d es mayor a lo que permite la variable(1.7E+308)\n\n",(int)operandos.valorA,operandos.factorialA,(int)operandos.valorB);
			}
			if(operandos.valorB<=170&&operandos.valorA>170){
				printf("El factorial de %d es mayor a lo que permite la variable(1.7E+308) y el factorial de %d es: %g\n\n",(int)operandos.valorA,(int)operandos.valorB,operandos.factorialB);
			}
		}

	}else{
		if(operandos.valorB<0&&operandos.valorA>=0){
			printf("No es posible realizar el factorial de %d y el factorial de %d es: %g,\n\n",(int)operandos.valorB,(int)operandos.valorA,operandos.factorialA);
		}
		if(operandos.valorB>=0&&operandos.valorA<0){
			printf("No es posible realizar el factorial de %d y el factorial de %d es: %g\n\n",(int)operandos.valorA,(int)operandos.valorB,operandos.factorialB);
		}
		if(operandos.valorB<0&&operandos.valorA<0){
			printf("No es posible realizar el factorial de ninguno de los operandos\n\n");
		}
	}

}
