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

#define OP_LOAD_TXT 1
#define OP_LOAD_BIN 2
#define OP_ALTA_EMP 3
#define OP_MOD_EMP 4
#define OP_BAJA_EMP 5
#define OP_LIST_EMP 6
#define OP_SORT_EMP 7
#define OP_SAVE_TXT 8
#define OP_SAVE_BIN 9
#define OP_SALIR 10

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    char mensaje[ARRAY_LEN];
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosBackUp=NULL;

    if(listaEmpleados!=NULL){
    	snprintf(mensaje,ARRAY_LEN,"\nMenu:\n"
			"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
			"2. Cargar los datos de los empleados desde el archivo dataBinario.csv (modo binario).\n"
			"3. Alta de empleado.\n"
			"4. Modificar datos de empleado.\n"
			"5. Baja de empleado.\n"
			"6. Listar empleados.\n"
			"7. Ordenar empleados.\n"
			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
			"9. Guardar los datos de los empleados en el archivo dataBinario.csv (modo binario).\n"
			"10. Salir.\n");
		do{
			if(!utn_getInt(&option,mensaje,"\nERROR! No se ha ingresado una opcion valida\n",5,OP_LOAD_TXT,OP_SALIR) )
			{
				switch(option)
				{
					case OP_LOAD_TXT:
						if(listaEmpleadosBackUp==NULL){
						controller_loadFromText("data.csv",listaEmpleados);
						listaEmpleadosBackUp=ll_clone(listaEmpleados);
						}else{
							printf("\nError. No se pueden cargar los datos mas de una vez\n");
						}
						break;
					case OP_LOAD_BIN:
						if(listaEmpleadosBackUp==NULL){
						controller_loadFromBinary("dataBinario.csv", listaEmpleados);
						listaEmpleadosBackUp=ll_clone(listaEmpleados);
						}else{
							printf("\nError. No se pueden cargar los datos mas de una vez\n");
						}
						break;
					case OP_ALTA_EMP:
						if(listaEmpleadosBackUp!=NULL){
							controller_addEmployee(listaEmpleados);
						}else{
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder cargar mas informacion\n");
						}
						break;
					case OP_MOD_EMP:
						if(listaEmpleadosBackUp!=NULL)
						{
							controller_editEmployee(listaEmpleados);
						}else{
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder modificar informacion\n");
						}
						break;
					case OP_BAJA_EMP:
						if(listaEmpleadosBackUp!=NULL)
						{
							controller_removeEmployee(listaEmpleados);
						}else{
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder borrar informacion\n");
						}
						break;
					case OP_LIST_EMP:
						if(listaEmpleadosBackUp!=NULL)
						{
							controller_ListEmployee(listaEmpleados);
						}else{
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder listar la informacion\n");
						}
						break;
					case OP_SORT_EMP:
						if(listaEmpleadosBackUp!=NULL)
						{
							controller_sortEmployee(listaEmpleados);
						}else{
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder reordenar la informacion\n");
						}
						break;
					case OP_SAVE_TXT:
						if(listaEmpleadosBackUp!=NULL)
						{
							controller_saveAsText("data.csv", listaEmpleados);
							ll_clear(listaEmpleadosBackUp);
							listaEmpleadosBackUp=ll_clone(listaEmpleados);
						}else{
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder guardar la informacion en el archivo\n");
						}
						break;
					case OP_SAVE_BIN:
						if(listaEmpleadosBackUp!=NULL)
						{
							controller_saveAsBinary("dataBinario.csv",listaEmpleados);
							ll_clear(listaEmpleadosBackUp);
							listaEmpleadosBackUp=ll_clone(listaEmpleados);
						}else{
							printf("\nSe debe cargar el listado con los datos del archivo antes de poder guardar la informacion en el archivo\n");
						}
						break;
					case OP_SALIR:
						if( !ll_containsAll(listaEmpleadosBackUp,listaEmpleados) ||
							!ll_containsAll(listaEmpleados,listaEmpleadosBackUp) )
						{
							printf("\nATENCION!\n"
							"Se han hecho cambios en la lista que todavia no se ha guardado en el archivo.\n"
							"Antes de salir asegurese de haber guardado en ambos archivos .csv, en modo binario Y texto\n");
							option=0;
						}else{
							if(	!ll_deleteLinkedList(listaEmpleadosBackUp) &&
								!ll_deleteLinkedList(listaEmpleados) ){
								printf("\nADIOS\n");
							}
						}
						break;
				}
			}
		}while(option != OP_SALIR);
    }
    return 0;
}
