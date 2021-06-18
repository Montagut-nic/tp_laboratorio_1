#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*: cadena de caracteres que representa la ruta y nombre del archivo
 * \param pArrayListEmployee LinkedList*: puntero a estructura tipo LinkedList
 * \param pFlagCarga int*: puntero a int, flag para validar la carga de la lista
 * \return int: retorna [-1 en caso de error] [0 en caso que se pueda cargar por lo menos
 * los datos de un empleado al LinkedList]
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee,int*pFlagCarga)
{
	FILE* pFile;
	int r;
	int retorno=-1;
	int idMax;
	if(path!=NULL && pArrayListEmployee!=NULL && pFlagCarga!=NULL){
		if((*pFlagCarga)==1) //ya se cargo la data a la lista
		{
			printf("\nError. No se pueden cargar los datos mas de una vez\n");
		} else {
			pFile=fopen(path,"r");
			if(pFile!=NULL)
			{
				r=parser_EmployeeFromText(pFile, pArrayListEmployee,&idMax);
				if(r>0)// se ha cargado por lo menos 1 empleado
				{
					printf("\nSe cargaron %d empleados\n",r);
					retorno=0;
					*pFlagCarga=TRUE;
					employee_initId(idMax);
				}else{
					printf("\nHa ocurrido un error con la carga de datos a la lista, no se ha podido cargar ningun empleado.\n");
				}
				fclose(pFile);
			}else
			{
				printf("\nError. Ha fallado la apertura del archivo data.csv (modo texto), no se ha creado todavia O no hay suficiente espacio en memoria\n");
			}
		}
	}else{
		printf("\nError: path es NULL o pArrayListEmployee es NULL o pFlagCarga es NULL\n");
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo dataBinario.csv (modo binario).
 *
 * \param path char*: cadena de caracteres que representa la ruta y nombre del archivo
 * \param pArrayListEmployee LinkedList*: puntero a estructura tipo LinkedList
 * \param pFlagCarga int*: puntero a int, flag para validar la carga de la lista
 * \return int: retorna [-1 en caso de error] [0 en caso que se pueda cargar por lo menos
 *  los datos de un empleado al LinkedList]
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee,int*pFlagCarga)
{
	FILE* pFile;
	int r;
	int retorno=-1;
	int idMax;
	if(path!=NULL && pArrayListEmployee!=NULL && pFlagCarga!=NULL){
		if((*pFlagCarga)==1) //ya se cargo la data
		{
			printf("\nError. No se pueden cargar los datos mas de una vez\n");
		} else
		{
			pFile=fopen(path,"rb");
			if(pFile!=NULL)
			{
				r=parser_EmployeeFromBinary(pFile, pArrayListEmployee,&idMax);
				if(r>0)// se ha cargado por lo menos 1 empleado
				{
					printf("\nSe cargaron %d empleados\n",r);
					retorno=0;
					*pFlagCarga=TRUE;
					employee_initId(idMax);
				}else{
					printf("\nHa ocurrido un error con la carga de datos a la lista, no se ha podido cargar ningun empleado.\n");
				}
				fclose(pFile);
			}else
			{
				printf("\nError. Ha fallado la apertura del archivo dataBinario.csv, no se ha creado todavia O no hay suficiente espacio en memoria\n");
			}
		}
	}else{
		printf("\nError: path es NULL o pArrayListEmployee es NULL o pFlagCarga es NULL\n");
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*: puntero a estructura tipo LinkedList
 * \param flagCarga int: flag para validar la carga de la lista
 * \return int: retorna [-1 en caso de error O la verificacion de la funcion ll_add falla O se cancele el alta por continuos errores al cargar]
 * [0 en caso que la funcion ll_add agregue el elemento al LinkedList]
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int flagCarga)
{
	int ret=-1;
	char nombreAux[128];
	char sueldoAux[256];
	char horasAux[256];
	char idAux[256];
	int idGen;
	Employee* pE;
	if(pArrayListEmployee!=NULL && (flagCarga||!flagCarga) ) {
		if(flagCarga)
		{
			if( !utn_getNombre(nombreAux, sizeof(nombreAux), "\nIngrese el nombre\n","\nERROR! Se han ingresado datos invalidos\n", 3) &&
				!utn_getStringSoloNumeros(sueldoAux, sizeof(sueldoAux),"\nIngrese el sueldo\n","ERROR! Se han ingresado datos invalidos",3) &&
				!utn_getStringSoloNumeros(horasAux, sizeof(horasAux),"\nIngrese las horas trabajadas\n","\nERROR! Se han ingresado datos invalidos\n",3) )
			{
				idGen=employee_generateId();
				snprintf(idAux,sizeof(idAux),"%d",idGen);
				pE=employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);
				if(pE!=NULL){
					ll_add(pArrayListEmployee, pE);
					ret=0;
					printf("\nSe ha cargado con exito con el id %d\n",idGen);
					employee_printEmployee(pE);
				}else{
					printf("\nHa ocurrido un error en el alta. Se ha ingresado algun valor invalido o no hay espacio en memoria\n");
				}
			}else{
				printf("\nSe ha cancelado el alta. Se ha equivocado muchas veces y se le acabaron los reintentos\n");
			}
		}else{
			printf("\nSe debe cargar el listado con los datos del archivo antes de poder cargar mas informacion\n");
		}
	}else{
		printf("\nHa ocurrido un error, pArrayListEmployee es NULL o flagCarga es distinto de TRUE y FALSE\n");
	}
	return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*: puntero a estructura tipo LinkedList
 * \param flagCarga int: flag para validar la carga de la lista
 * \return int: retorna [-1 en caso de error O cancelacion de la operacion] [0 si se modifica con exito el elemento]
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee, int flagCarga)
{
	int ret=-1;
	char nombreAux[128];
	int sueldoAux;
	int horasAux;
	int idAux;
	int idBuscar;
	Employee* pE;
	int resp;
	int indice=0;
	if(pArrayListEmployee!=NULL && (flagCarga||!flagCarga)){
		if(flagCarga){
			if( !utn_getIntLimitMaxOrMin(&idBuscar, "\nIngrese el id del empleado a modificar\n", "\nERROR! Se han ingresado datos invalidos\n",3,0,0,LIM_MIN) )
			{
				for(;indice<ll_len(pArrayListEmployee);indice++){
					pE=ll_get(pArrayListEmployee,indice);
					if(!employee_getId(pE, &idAux) && idBuscar==idAux){
						break;
					}
					pE=NULL;
				}
				if( pE!=NULL ){
					employee_printEmployee(pE);
					if( !utn_getNombre(nombreAux, sizeof(nombreAux), "\nIngrese el nombre\n","\nERROR! Se han ingresado datos invalidos\n", 3) &&
						!utn_getIntLimitMaxOrMin(&sueldoAux,"\nIngrese el sueldo\n","ERROR! Se han ingresado datos invalidos",3,0,0,LIM_MIN) &&
						!utn_getIntLimitMaxOrMin(&horasAux,"\nIngrese las horas trabajadas\n","\nERROR! Se han ingresado datos invalidos\n",3,0,0,LIM_MIN) &&
						!utn_getInt(&resp, "\nDesea confirmar los cambios?\n[SI:1]\t[NO:0]\n","\nERROR! Se han ingresado datos invalidos\n",3,0,1) &&
						resp==1 &&
						!employee_setHorasTrabajadas(pE,horasAux) &&
						!employee_setSueldo(pE, sueldoAux) &&
						!employee_setNombre(pE, nombreAux) )
					{
						ret=0;
						printf("\nSe ha cambiado la informacion con exito\n");
						employee_printEmployee(pE);
					}else{
						printf("\nNo se ha modificado ningun dato. Se han cancelado los cambios o se han ingresado datos invalidos y se acabaron los reintentos\n");
					}
				}else{
					printf("\nNo se ha encontrado ese id\n");
				}
			}else{
				printf("\nSe ha cancelado la modificacion de datos. Se han ingresado IDs invalidas y se acabaron los reintentos\n");
			}
		}else{
			printf("\nSe debe cargar el listado con los datos del archivo antes de poder modificar informacion\n");
		}
	}else{
		printf("\nHa ocurrido un error, pArrayListEmployee es NULL o flagCarga es distinto de TRUE y FALSE\n");
	}
	return ret;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*: puntero a estructura tipo LinkedList
 * \param flagCarga int: flag para validar la carga de la lista
 * \return int: retorna [-1 en caso de error O cancelacion de la operacion] [0 si se elimina con exito el elemento]
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee, int flagCarga)
{
	int retorno=-1;
	int idBuscar;
	Employee*pE;
	int idAux;
	int resp;
	int indice=0;
	if( pArrayListEmployee!=NULL && (!flagCarga||flagCarga) )
	{
		if(flagCarga){
			if(!utn_getIntLimitMaxOrMin(&idBuscar, "\nIngrese el id del empleado a borrar\n", "\nERROR! Se han ingresado datos invalidos\n",3,0,0,LIM_MIN) )
			{
				for(;indice<ll_len(pArrayListEmployee);indice++){
					pE=ll_get(pArrayListEmployee, indice);
					if(!employee_getId(pE, &idAux) && idBuscar==idAux){
						break;
					}
					pE=NULL;
				}
				if(pE!=NULL){
					employee_printEmployee(pE);
					if( !utn_getInt(&resp,"\nDesea remover esta informacion?\n[SI:1]\t[NO:0]\n","\nERROR! No se ha ingresado una opcion valida\n",3,0,1) &&
						resp==1)
					{
						employee_delete(pE);
						ll_remove(pArrayListEmployee,indice);
						retorno=0;
						printf("\nSe ha removido la informacion con exito\n");
					}
				}else{
					printf("\nNo se ha encontrado ese id\n");
				}
			}else{
				printf("\nSe han ingresado IDs invalidas y se acabaron los reintentos\n");
			}
			if(retorno!=0){
				printf("\nSe ha cancelado la operacion\n");
			}
		}else{
			printf("\nSe debe cargar el listado con los datos del archivo antes de poder borrar informacion\n");
		}
	}else {
		printf("\nHa ocurrido un error, pArrayListEmployee es NULL o flagCarga es distinto de TRUE y FALSE\n");
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*: puntero a estructura tipo LinkedList
 * \param flagCarga int: flag para validar la carga de la lista
 * \return int: retorna [-1 en caso de error] [0 si se imprime con exito por lo menos un elemento]
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee, int flagCarga)
{
	int retorno=-1;
	Employee*pE;
	int indice=0;
	int contador=0;
	if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)>0 && (flagCarga||!flagCarga) ){
		if(flagCarga){
			for(;indice<ll_len(pArrayListEmployee);indice++){
				pE=ll_get(pArrayListEmployee, indice);
				if(pE!=NULL && !employee_printEmployee(pE)){
					retorno=0;
					contador++;
				}
			}
			printf("\nSe han podido mostrar %d empleados\n",contador);
		}else{
			printf("\nSe debe cargar el listado con los datos del archivo antes de poder listar la informacion\n");
		}
	}else{
		printf("\nNo es posible listar empleados\n");
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*: puntero a estructura tipo LinkedList
 * \param flagCarga int: flag para validar la carga de la lista
 * \return int: retorna [-1 en caso de error O cancelacion de la operacion] [0 si se reordena con exito la linkeList]
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee, int flagCarga)
{
	int opcion;
	char mensaje[ARRAY_LEN];
	int orden;
	int retorno=-1;
    if( pArrayListEmployee!=NULL && (flagCarga||!flagCarga) )
    {
    	if(flagCarga){
			snprintf(mensaje,sizeof(mensaje),"\nElija el criterio para ordenar:\n\n"
							"1. ID\n"
							"2. Nombre\n"
							"3. Sueldo\n"
							"4. Horas Trabajadas\n");
			if(!utn_getInt(&opcion, mensaje, "\nERROR! No se ha ingresado una opcion valida\n",3,1,4) )
			{
				snprintf(mensaje,sizeof(mensaje),"\nElija el tipo de ordenamiento:\n[Ascendente:1]\t[Descendiente:0]\n");
				if(!utn_getInt(&orden, mensaje, "\nERROR! No se ha ingresado una opcion valida\n",3,0,1) )
				{
					switch(opcion)
					{
						case 1:
							if(!ll_sort(pArrayListEmployee, employee_comparaId, orden))
							{
								printf("\nSe ha ordenado la lista por id con exito\n");
								retorno=0;
							}
							break;
						case 2:
							if(!ll_sort(pArrayListEmployee, employee_comparaNombre, orden))
							{
								printf("\nSe ha ordenado la lista por nombre con exito\n");
								retorno=0;
							}
							break;
						case 3:
							if(!ll_sort(pArrayListEmployee, employee_comparaSueldo, orden))
							{
								printf("\nSe ha ordenado la lista por sueldo con exito\n");
								retorno=0;
							}
							break;
						case 4:
							if(!ll_sort(pArrayListEmployee, employee_comparaHoras, orden))
							{
								printf("\nSe ha ordenado la lista por horas trabajadas con exito\n");
								retorno=0;
							}
							break;
					}
				}
			}
			if(retorno!=0){
				printf("\nSe ha cancelado el reordenamiento de la lista\n");
			}
    	}else{
    		printf("\nSe debe cargar el listado con los datos del archivo antes de poder reordenar la informacion\n");
    	}
    }else{
    	printf("\nHa ocurrido un error, pArrayListEmployee es NULL o flagCarga es distinto de TRUE y FALSE\n");
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*: cadena de caracteres que representa la ruta y nombre del archivo
 * \param pArrayListEmployee LinkedList*: puntero a estructura tipo LinkedList
 * \param flagCarga int: flag para validar la carga de la lista
 * \param pFlagGuardado int*: puntero a int, flag para validar el guardado de los datos en el archivo
 * \return int: retorna [-1 en caso de error] [0 si se guarda con exito por lo menos un elemento]
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee,int flagCarga,int*pFlagGuardado)
{
	FILE* pFile;
	Employee* pE=NULL;
	char nomEmp[128];
	int idEmp;
	int horasTrabajadasEmp;
	int sueldoEmp;
	int retorno=-1;
	int contador=0;
	int indice=0;
	if(path!=NULL && pArrayListEmployee!=NULL && (flagCarga||!flagCarga) && pFlagGuardado!=NULL){
		if(flagCarga){
			pFile=fopen(path,"w");
			if(pFile!=NULL){
				fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
				for(;indice<ll_len(pArrayListEmployee);indice++)
				{
					pE=ll_get(pArrayListEmployee, indice);
					if( pE!=NULL &&
						!employee_getNombre(pE,nomEmp) &&
						!employee_getId(pE,&idEmp) &&
						!employee_getHorasTrabajadas(pE,&horasTrabajadasEmp) &&
						!employee_getSueldo(pE,&sueldoEmp) )
					{
						fprintf(pFile,"%d,%s,%d,%d\n",idEmp,nomEmp,horasTrabajadasEmp,sueldoEmp);
						contador++;
					}
				}
				printf("\nSe han guardado %d empleados en el archivo en Modo Texto\n",contador);
				retorno=0;
				*pFlagGuardado=TRUE;
				fclose(pFile);
			}else{
				printf("\nError. Ha fallado la apertura del archivo data.csv (modo texto)\n");
			}
		}else{
			printf("\nSe debe cargar el listado con los datos del archivo antes de poder guardar la informacion en el archivo\n");
		}
	}else{
		printf("\nError: path es NULL o pArrayListEmployee es NULL o pFlagGuardado es NULL o flagCarga es distinto de TRUE y FALSE\n");
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo dataBinario.csv (modo binario).
 *
 * \param path char*: cadena de caracteres que representa la ruta y nombre del archivo
 * \param pArrayListEmployee LinkedList*: puntero a estructura tipo LinkedList
 * \param flagCarga int: flag para validar la carga de la lista
 * \param pFlagGuardado int*: puntero a int, flag para validar el guardado de los datos en el archivo
 * \return int: retorna [-1 en caso de error] [0 si se guarda con exito por lo menos un elemento]
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee,int flagCarga,int*pFlagGuardado)
{
	FILE* pFile;
	int retorno=-1;
	Employee* pE=NULL;
	int indice=0;
	int contador=0;
	if(path!=NULL && pArrayListEmployee!=NULL && pFlagGuardado!=NULL && (flagCarga||!flagCarga) )
	{
		if(flagCarga){
			pFile=fopen(path,"wb");
			if(pFile!=NULL){
				for(;indice<ll_len(pArrayListEmployee);indice++)
				{
					pE=ll_get(pArrayListEmployee, indice);
					if(pE!=NULL)
					{
						fwrite(pE,sizeof(Employee),1,pFile);
						contador++;
					}
				}
				printf("\nSe han guardado %d empleados en el archivo en Modo Binario\n",contador);
				retorno=0;
				*pFlagGuardado=TRUE;
				fclose(pFile);
			}else{
				printf("\nError. Ha fallado la apertura del archivo dataBinario.csv (modo binario)\n");
			}
		}else{
			printf("\nSe debe cargar el listado con los datos del archivo antes de poder guardar la informacion en el archivo\n");
		}
	}else{
		printf("\nError: path es NULL o pArrayListEmployee es NULL o pFlagGuardado es NULL o flagCarga es distinto de TRUE y FALSE\n");
	}
    return retorno;
}

