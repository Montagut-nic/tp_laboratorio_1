#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int r;
	int retorno=-1;
	int idMax;
	if(path!=NULL && pArrayListEmployee!=NULL){
		pFile=fopen(path,"r");
		if(pFile!=NULL){
			r=parser_EmployeeFromText(pFile, pArrayListEmployee,&idMax);
			if(r>0){
				printf("\nSe cargaron %d empleados\n",r);
				retorno=0;
			}
			fclose(pFile);
			employee_initId(idMax);
		}
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int r;
	int retorno=-1;
	int idMax;
	if(path!=NULL && pArrayListEmployee!=NULL){
		pFile=fopen(path,"rb");
		if(pFile!=NULL){
			r=parser_EmployeeFromBinary(pFile, pArrayListEmployee,&idMax);
			if(r>0){
				printf("\nSe cargaron %d empleados\n",r);
				retorno=0;
			}
			fclose(pFile);
			employee_initId(idMax);
		}
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	char nombreAux[128];
	char sueldoAux[256];
	char horasAux[256];
	char idAux[256];
	int idGen;
	Employee* pE;
	if(pArrayListEmployee!=NULL){
		if( !utn_getString(nombreAux, sizeof(nombreAux), "\nIngrese el nombre\n","\nERROR!\n", 3) &&
			!utn_getStringSoloNumeros(sueldoAux, sizeof(sueldoAux),"\nIngrese el sueldo\n","ERROR!",3) &&
			!utn_getStringSoloNumeros(horasAux, sizeof(horasAux),"\nIngrese las horas trabajadas\n","\nERROR!\n",3) )
		{
			idGen=employee_generateId();
			snprintf(idAux,sizeof(idAux),"%d",idGen);
			pE=employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);
			if(pE!=NULL){
				ret=ll_add(pArrayListEmployee, pE);
				printf("\nSe ha cargado con exito con el id %d\n",idGen);
				employee_printEmployee(pE);
			}else{
				printf("\nHa ocurrido un error con el alta\n");
			}
		}else{
			printf("\nSe ha cancelado el alta\n");
		}
	}
	return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
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
	if(pArrayListEmployee!=NULL){
		if( !utn_getIntLimitMaxOrMin(&idBuscar, "\nIngrese el id del empleado a modificar\n", "\nERROR!\n",3,0,0,LIM_MIN) )
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
				if( !utn_getNombre(nombreAux, sizeof(nombreAux), "\nIngrese el nombre\n","\nERROR!\n", 3) &&
					!utn_getIntLimitMaxOrMin(&sueldoAux,"\nIngrese el sueldo\n","ERROR!",3,0,0,LIM_MIN) &&
					!utn_getIntLimitMaxOrMin(&horasAux,"\nIngrese las horas trabajadas\n","\nERROR!\n",3,0,0,LIM_MIN) &&
					!utn_getInt(&resp, "\nDesea confirmar los cambios?\n[SI:1]\t[NO:0]\n","\nERROR!\n",3,0,1) &&
					resp==1 &&
					!employee_setHorasTrabajadas(pE,horasAux) &&
					!employee_setSueldo(pE, sueldoAux) &&
					!employee_setNombre(pE, nombreAux) )
				{
					ret=0;
					printf("\nSe ha cambiado la informacion con exito\n");
					employee_printEmployee(pE);
				}else{
					printf("\nNo se ha modificado ningun dato\n");
				}
			}else{
				printf("\nNo se ha encontrado ese id\n");
			}
		}
	}
	return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idBuscar;
	Employee*pE;
	int idAux;
	int resp;
	int indice=0;
	if( pArrayListEmployee!=NULL &&
		!utn_getIntLimitMaxOrMin(&idBuscar, "\nIngrese el id del empleado a borrar\n", "\nERROR!\n",3,0,0,LIM_MIN) )
	{
		for(;indice<ll_len(pArrayListEmployee);indice++){
			pE=ll_get(pArrayListEmployee, indice);
			if(!employee_getId(pE, &idAux) && idBuscar==idAux){
				break;
			}
			pE=NULL;
		}
		if( pE!=NULL){
			employee_printEmployee(pE);
			if( !utn_getInt(&resp,"\nDesea remover esta informacion?\n[SI:1]\t[NO:0]\n","\nERROR!\n",3,0,1) &&
				resp==1)
			{
				employee_delete(pE);
				ll_remove(pArrayListEmployee, indice);
				retorno=0;
				printf("\nSe ha removido la informacion con exito\n");
			}
		}else{
			printf("\nNo se ha encontrado ese id\n");
		}
	}
	if(retorno!=0){
		printf("\nSe ha cancelado la operacion\n");
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee*pE;
	int indice=0;
	int contador=0;
	if(pArrayListEmployee!=NULL){
		for(;indice<ll_len(pArrayListEmployee);indice++){
			pE=ll_get(pArrayListEmployee, indice);
			if(pE!=NULL && !employee_printEmployee(pE)){
				retorno=0;
				contador++;
			}
		}
		printf("\nSe han mostrado %d empleados\n",contador);
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int opcion;
	char mensaje[ARRAY_LEN];
	int orden;
	int retorno=-1;
    if( pArrayListEmployee!=NULL)
    {
    	snprintf(mensaje,sizeof(mensaje),"\nElija el criterio para ordenar:\n\n"
    					"1. ID\n"
    					"2. Nombre\n"
    					"3. Sueldo\n"
    					"4. Horas Trabajadas\n");
    	if(!utn_getInt(&opcion, mensaje, "ERROR!",3,1,4) )
    	{
    		snprintf(mensaje,sizeof(mensaje),"\nElija el tipo de ordenamiento:\n[Ascendente:1]\t[Descendiente:0]");
    		if(!utn_getInt(&orden, mensaje, "ERROR!",3,0,1) )
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
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
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
	if(path!=NULL && pArrayListEmployee!=NULL){
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
			printf("\nSe han guardado %d empleados en el archivo en Modo Texto",contador);
			retorno=0;
			fclose(pFile);
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno=-1;
	Employee* pE=NULL;
	int indice=0;
	int contador=0;
	if(path!=NULL && pArrayListEmployee!=NULL){
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
			fclose(pFile);
		}
	}
    return retorno;
}

