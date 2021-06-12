#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char mensaje[ARRAY_LEN];
    int flagCarga=FALSE;
    int flagGuardado=TRUE;
    int resp;
    int respuesta;
    if(listaEmpleados!=NULL){
		do{
			snprintf(mensaje,ARRAY_LEN,"\nMenu:\n"
				"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
				"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
				"3. Alta de empleado.\n"
				"4. Modificar datos de empleado.\n"
				"5. Baja de empleado.\n"
				"6. Listar empleados.\n"
				"7. Ordenar empleados.\n"
				"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
				"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
				"10. Salir.\n");
			if(!utn_getInt(&option, mensaje, "\nERROR!\n", 5, 1, 10) )
			{
				switch(option)
				{
					case 1:
						if(!flagGuardado){
							snprintf(mensaje,ARRAY_LEN,"\nATENCION!\n"
									"Se esta por sobreescribir informacion que ha cambiado en la lista"
									" y no se ha guardado en el archivo\n"
									"Esta seguro que desea sobreescribir la informacion de la lista?\n"
									"[SI, continuar de todos modos:1]\t[NO, volver al menu principal:0]");
							do{
								utn_getInt(&respuesta,mensaje,"Error",5,0,1);
							}while(respuesta!=0||respuesta!=1);
							if(respuesta==1){
								if(!controller_loadFromText("data.csv",listaEmpleados)){
									flagCarga=TRUE;
								}else{
									printf("\nHa ocurrido un error con la carga de datos a la lista\n");
								}
							}
						}else{
							if(!controller_loadFromText("data.csv",listaEmpleados)){
								flagCarga=TRUE;
							}else{
								printf("\nHa ocurrido un error con la carga de datos a la lista\n");
							}
						}
						break;
					case 2:
						if(!flagGuardado){
							snprintf(mensaje,ARRAY_LEN,"\nATENCION!\n"
									"Se esta por sobreescribir informacion que ha cambiado en la lista"
									" y no se ha guardado en el archivo\n"
									"Esta seguro que desea sobreescribir la informacion de la lista?\n"
									"[SI, continuar de todos modos:1]\t[NO, volver al menu principal:0]");
							do{
								utn_getInt(&respuesta,mensaje,"Error",5,0,1);
							}while(respuesta!=0||respuesta!=1);
							if(respuesta==1){
								if(!controller_loadFromBinary("data.csv",listaEmpleados)){
									flagCarga=TRUE;
								}else{
									printf("\nHa ocurrido un error con la carga de datos a la lista\n");
								}
							}
						}else{
							if(!controller_loadFromBinary("data.csv",listaEmpleados)){
								flagCarga=TRUE;
							}else{
								printf("\nHa ocurrido un error con la carga de datos a la lista\n");
							}
						}
						break;
					case 3:
						if(!flagCarga){
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder cargar mas informacion\n");
						}else{
							if(!controller_addEmployee(listaEmpleados)){
								flagGuardado=FALSE;
							}
						}
						break;
					case 4:
						if(!flagCarga){
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder modificar informacion\n");
						}else{
							if(!controller_editEmployee(listaEmpleados)){
								flagGuardado=FALSE;
							}
						}
						break;
					case 5:
						if(!flagCarga){
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder borrar informacion\n");
						}else{
							if(!controller_removeEmployee(listaEmpleados)){
								flagGuardado=FALSE;
							}
						}
						break;
					case 6:
						if(!flagCarga){
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder listar la informacion\n");
						}else{
							controller_ListEmployee(listaEmpleados);
						}
						break;
					case 7:
						if(!flagCarga){
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder reordenar la informacion\n");
						}else{
							if(!controller_sortEmployee(listaEmpleados)){
								flagGuardado=FALSE;
							}
						}
						break;
					case 8:
						if(!flagCarga){
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder guardar la informacion en el archivo\n");
						}else{
							if(!controller_saveAsText("data.csv",listaEmpleados)){
								flagGuardado=TRUE;
							}
						}
						break;
					case 9:
						if(!flagCarga){
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder guardar la informacion en el archivo\n");
						}else{
							if(!controller_saveAsBinary("data.csv",listaEmpleados)){
								flagGuardado=TRUE;
							}
						}
						break;
					case 10:
						if(flagGuardado==0){
							snprintf(mensaje,ARRAY_LEN,"\nATENCION!\n"
								"Se han hecho cambios en la lista que todavia no se ha guardado en el archivo\n"
								"Esta seguro que desea salir sin guardar los cambios? Se perderan todos los cambios realizados\n"
								"[SI, salir sin guardar:1]\t[NO, volver al menu principal:0]");
							do{
								utn_getInt(&resp,mensaje,"Error",5,0,1);
							}while(resp!=0||resp!=1);
							if(resp==0){
								option=0;
							}
						}
						break;
				}
			}
		}while(option != 10);
    }
    return 0;
}

