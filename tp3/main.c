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
    char mensaje[ARRAY_LEN];
    int flagCarga=FALSE;
    int flagGuardadoBinario=TRUE;
    int flagGuardadoTexto=TRUE;

    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados!=NULL){
		do{
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
			if(!utn_getInt(&option, mensaje, "\nERROR! No se ha ingresado una opcion valida\n", 5, 1, 10) )
			{
				switch(option)
				{
					case 1:
						controller_loadFromText("data.csv",listaEmpleados, &flagCarga);
						break;
					case 2:
						controller_loadFromBinary("dataBinario.csv", listaEmpleados, &flagCarga);
						break;
					case 3:
						if(!controller_addEmployee(listaEmpleados, flagCarga) ){
							flagGuardadoBinario=FALSE;
							flagGuardadoTexto=FALSE;
						}
						break;
					case 4:
						if(!controller_editEmployee(listaEmpleados, flagCarga)){
							flagGuardadoBinario=FALSE;
							flagGuardadoTexto=FALSE;
						}
						break;
					case 5:
						if(!controller_removeEmployee(listaEmpleados, flagCarga)){
							flagGuardadoBinario=FALSE;
							flagGuardadoTexto=FALSE;
						}
						break;
					case 6:
						controller_ListEmployee(listaEmpleados, flagCarga);
						break;
					case 7:
						if(!controller_sortEmployee(listaEmpleados, flagCarga)){
							flagGuardadoBinario=FALSE;
							flagGuardadoTexto=FALSE;
						}
						break;
					case 8:
						controller_saveAsText("data.csv", listaEmpleados, flagCarga, &flagGuardadoTexto);
						break;
					case 9:
						controller_saveAsBinary("dataBinario.csv", listaEmpleados, flagCarga, &flagGuardadoBinario);
						break;
					case 10:
						if(flagGuardadoBinario==0||flagGuardadoTexto==0){
							snprintf(mensaje,ARRAY_LEN,"\nATENCION!\n"
							"Se han hecho cambios en la lista que todavia no se ha guardado en el archivo.\n"
							"Antes de salir asegurese de haber guardado en ambos archivos .csv, en modo binario Y texto\n");
							option=0;
						}
						break;
				}
			}
		}while(option != 10);
    }
    return 0;
}

