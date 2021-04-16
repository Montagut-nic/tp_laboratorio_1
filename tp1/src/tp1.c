/*
 ============================================================================
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir
� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Numeros.h"
#include "utn.h"

#define MENSAJE_LEN 250
#define MAX_NUM 10000
#define MIN_NUM -10000
#define REINTENTOS 5

int main(void){
	setbuf(stdout,NULL);
	int opcionInt;
	int respuesta;
	int flagSinOperaciones=1;
	char mensaje[MENSAJE_LEN];
	S_Numeros operandosAux;

	utn_getFloat(&operandosAux.valorA,"Ingrese el primer operando (A)\n","Error. No se ingreso un numero valido.\n",5,MIN_NUM,MAX_NUM);
	utn_getFloat(&operandosAux.valorB,"Ingrese el segundo operando (B)\n","Error. No se ingreso un numero valido.\n",5,MIN_NUM,MAX_NUM);
	do{
		snprintf(mensaje,sizeof(mensaje),"Seleccione alguna de las siguientes opciones:\n\n1.Modificar 1er operando (A = %.2f)\n2.Modificar 2do operando (B = %.2f)\n3.Calcular todas las operaciones\n4.Informar los resultados\n5.Salir\n\n",operandosAux.valorA,operandosAux.valorB);
		respuesta = utn_getInt(&opcionInt,mensaje,"Error. No es una opcion valida\n",REINTENTOS,1,5);
		if(respuesta==0){
			switch(opcionInt)
			{
				case 1:
					utn_getFloat(&operandosAux.valorA,"Ingrese el primer operando (A)\n","Error. No se ingreso un numero valido.\n",REINTENTOS,MIN_NUM,MAX_NUM);
					flagSinOperaciones=1;
					break;
				case 2:
					utn_getFloat(&operandosAux.valorB,"Ingrese el segundo operando (B)\n","Error. No se ingreso un numero valido.\n",REINTENTOS,MIN_NUM,MAX_NUM);
					flagSinOperaciones=1;
					break;
				case 3:
					flagSinOperaciones=0;
					nums_suma (operandosAux.valorA,operandosAux.valorB,&operandosAux.resultadoSuma);
					nums_resta (operandosAux.valorA,operandosAux.valorB,&operandosAux.resultadoResta);
					nums_multiplicacion (operandosAux.valorA,operandosAux.valorB,&operandosAux.resultadoMult);
					nums_division (operandosAux.valorA,operandosAux.valorB,&operandosAux.resultadoDiv);
					nums_factorial (operandosAux.valorA,operandosAux.valorB, &operandosAux.factorialA,&operandosAux.factorialB);
					printf("Se han realizado las operaciones. Listo para mostrar los resultados.\n");
					break;
				case 4:
					if(flagSinOperaciones==0){
						nums_informarResultados(operandosAux);
					}else{
						printf("Error. No se han realizado operaciones. No hay resultados para mostrar.\n");
					}
					break;
			}
		}
	} while(opcionInt!=5);
	return EXIT_SUCCESS;
}
