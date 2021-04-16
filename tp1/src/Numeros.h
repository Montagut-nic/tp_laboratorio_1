/*
 * Numero.h
 *
 *  Created on: 15 abr. 2021
 *      Author: Montagut
 */

#ifndef NUMEROS_H_
#define NUMEROS_H_

typedef struct{
	float valorA;
	float valorB;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDiv;
	float resultadoMult;
	long double factorialA;
	long double factorialB;
} S_Numeros;

int nums_suma (float valorA,float valorB, float* pResultadoSuma);
int nums_resta (float valorA,float valorB, float* pResultadoResta);
int nums_multiplicacion (float valorA,float valorB, float* pResultadoMult);
int nums_division (float valorA,float valorB, float* resultadoDiv);
int nums_factorial (float valorA,float valorB,long double* pResultadoFactorialA, long double* pResultadoFactorialB);
void nums_informarResultados(S_Numeros operandos);

#endif /* NUMEROS_H_ */
