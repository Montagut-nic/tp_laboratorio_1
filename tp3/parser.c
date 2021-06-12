#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee, int* idMaxObt)
{
	char nombreAux[128];
	char sueldoAux[256];
	char horasAux[256];
	char idAux[256];
	int flagOnce=0;
	int r=0;
	int idEmp;
	Employee* pE=NULL;
	int idMax=0;
	if(pFile!=NULL && pArrayListEmployee!=NULL && idMaxObt!=NULL)
	{
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
		*idMaxObt=idMax;
	}
    return r;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee, int*idMaxObt)
{
	int r=-1;
	Employee* pE;
	int idEmp;
	int idMax=0;
	if(pFile!=NULL && pArrayListEmployee!=NULL && idMaxObt!=NULL)
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
		*idMaxObt=idMax;
	}
	return r;
}
