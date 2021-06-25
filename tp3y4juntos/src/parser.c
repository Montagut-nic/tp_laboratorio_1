#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*: puntero al archivo desde donde se parsean los datos
 * \param pArrayListEmployee LinkedList*: puntero a elemento tipo LinkedList donde se van a guardar los datos
 * \param pIdMaxObt int*: puntero a int donde se va a guardar el id maximo obtenido del archivo
 * \return int: retorna [-1 en caso de error] [0 o cantidad de elementos que se agregaron a la linked list]
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee, int* pIdMaxObt)
{
	char nombreAux[128];
	char sueldoAux[256];
	char horasAux[256];
	char idAux[256];
	int flagOnce=0;
	int r=-1;
	int idEmp;
	Employee* pE=NULL;
	int idMax=0;
	if(pFile!=NULL && pArrayListEmployee!=NULL && pIdMaxObt!=NULL)
	{
		r=0;
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux)==4)
			{
				if(flagOnce)
				{
					pE=employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);
					if(pE!=NULL){
						ll_add(pArrayListEmployee, pE);
						idEmp=atoi(idAux);
						if(idMax < idEmp ){
							idMax=idEmp;
						}
						r++;
					}
				}
			}
			flagOnce=1;
		}
		while(feof(pFile)==0);
		*pIdMaxObt=idMax;
	}
    return r;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*: puntero al archivo desde donde se parsean los datos
 * \param pArrayListEmployee LinkedList*: puntero a elemento tipo LinkedList donde se van a guardar los datos
 * \param pIdMaxObt int*: puntero a int donde se va a guardar el id maximo obtenido del archivo
 * \return int: retorna [-1 en caso de error] [0 o cantidad de elementos que se agregaron a la linked list]
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee, int*pIdMaxObt)
{
	int r=-1;
	Employee* pE;
	int idEmp;
	int idMax=0;
	if(pFile!=NULL && pArrayListEmployee!=NULL && pIdMaxObt!=NULL)
	{
		r=0;
		do {
			pE=employee_new();
			if(fread(pE,sizeof(Employee),1,pFile)==1){
				ll_add(pArrayListEmployee,pE);
				employee_getId(pE, &idEmp);
				if(idEmp>idMax){
					idMax=idEmp;
				}
				r++;
			}else{
				employee_delete(pE);
			}
		}while(feof(pFile)==0);
		*pIdMaxObt=idMax;
	}
	return r;
}
