#include "Controller.h"

void* ll_getNext (LinkedList* this,int isFirst){
	void* pRetorno=NULL;
	static Node* pNodeAux;
	if(this!=NULL && (isFirst==0 || isFirst==1) ){
		if(isFirst){
			pNodeAux=ll_get(this,0);
			if(pNodeAux!=NULL){
				pRetorno=pNodeAux->pElement;
			}
		}else{
			if(pNodeAux!=NULL){
				pNodeAux=pNodeAux->pNextNode;
				if(pNodeAux!=NULL){
					pRetorno=pNodeAux->pElement;
				}
			}
		}
	}
	return pRetorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* idMaxAlta)
{
	FILE* pFile=NULL;
	int r;
	int retorno=-1;
	int idMax;
	if(path!=NULL && pArrayListEmployee!=NULL){
		pFile=fopen(path,"r+");
		if(pFile!=NULL){
			r=parser_EmployeeFromText(pFile, pArrayListEmployee,&idMax);
			if(r>0){
				printf("\nSe cargaron %d empleados\n",r);
				retorno=0;
			}
			fclose(pFile);
			*idMaxAlta=idMax;
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
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* idMaxAlta)
{
	FILE* pFile=NULL;
	int r;
	int retorno=-1;
	int idMax;
	if(path!=NULL && pArrayListEmployee!=NULL){
		pFile=fopen(path,"r+b");
		if(pFile!=NULL){
			r=parser_EmployeeFromBinary(pFile, pArrayListEmployee,&idMax);
			if(r>0){
				printf("\nSe cargaron %d empleados\n",r);
				retorno=0;
			}
			fclose(pFile);
			*idMaxAlta=idMax;
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
    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
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
	FILE* pFile=NULL;
	Employee* pE=NULL;
	int flagIsFirst=1;
	char nomEmp[128];
	int idEmp;
	int horasTrabajadasEmp;
	int sueldoEmp;
	int retorno=-1;
	int r=0;
	if(path!=NULL && pArrayListEmployee!=NULL){
		pFile=fopen(path,"w+");
		if(pFile!=NULL){
			fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
			do{
				pE=ll_getNext(pArrayListEmployee,flagIsFirst);
				if( pE!=NULL &&
					!employee_getNombre(pE,nomEmp) &&
					!employee_getId(pE,&idEmp) &&
					!employee_getHorasTrabajadas(pE,&horasTrabajadasEmp) &&
					!employee_getSueldo(pE,&sueldoEmp) )
				{
					fprintf(pFile,"%d,%s,%d,%d\n",idEmp,nomEmp,horasTrabajadasEmp,sueldoEmp);
					r++;
				}
				flagIsFirst=0;
			}while(pE!=NULL);
			if(r>0){
				printf("\nSe han guardado %d empleados",r);
				retorno=0;
			}
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
	FILE* pFile=NULL;
	int r=0;
	int retorno=-1;
	Employee* pE=NULL;
	int flagIsFirst=1;
	if(path!=NULL && pArrayListEmployee!=NULL){
		pFile=fopen(path,"w+b");
		if(pFile!=NULL){
			do{
				pE=ll_getNext(pArrayListEmployee, flagIsFirst);
				if(pE!=NULL)
				{
					fwrite(pE,sizeof(Employee),1,pFile);
					r++;
					flagIsFirst=0;
				}
			}while(pE!=NULL);
			if(r>0){
				printf("\nSe han guardado %d empleados\n",r);
				retorno=0;
			}
			fclose(pFile);
		}
	}
    return retorno;
}

