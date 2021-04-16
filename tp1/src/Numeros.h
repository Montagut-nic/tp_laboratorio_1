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
	double factorialA;
	double factorialB;
} Numeros;

void nums_suma (float valorA,float valorB, float* resultadoSuma);
void nums_resta (float valorA,float valorB, float* resultadoResta);
void nums_multiplicacion (float valorA,float valorB, float* resultadoMult);
int nums_division (float valorA,float valorB, float* resultadoDiv);
void nums_factorial (float valorA,float valorB, double* resultadoFactorialA, double* resultadoFactorialB);
void nums_informarResultados(Numeros operandos);

#endif /* NUMEROS_H_ */
