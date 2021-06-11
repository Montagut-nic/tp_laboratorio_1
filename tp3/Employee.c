#include "Employee.h"

Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* auxEmpleado = employee_new();
	int idAux=0;
	int horasTrabajadasAux=0;
	int sueldoAux=0;
	if(auxEmpleado != NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		if ( isValidNombre(nombreStr) > 0 &&
			 isValidId(idStr) > 0 &&
			 isValidHorasTrabajadas(horasTrabajadasStr) > 0 &&
			 isValidSueldo(sueldoStr) > 0 )
		{
			idAux = atoi(idStr);
			horasTrabajadasAux = atoi(horasTrabajadasStr);
			sueldoAux = atoi(sueldoStr);
		}

		if  ( employee_setNombre(auxEmpleado,nombreStr) < 0 ||
			  employee_setId(auxEmpleado,idAux) < 0 ||
			  employee_setHorasTrabajadas(auxEmpleado,horasTrabajadasAux) < 0 ||
			  employee_setSueldo(auxEmpleado,sueldoAux) < 0 )
		{
			employee_delete(auxEmpleado);
			auxEmpleado = NULL;
		}
	}
	return auxEmpleado;
}

void employee_delete(Employee* this){
	free(this);
}

int employee_setId(Employee* this,int id){
	int retorno = -1;
	if(this != NULL && id > 0 )
	{
		this->id=id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id){
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL && isValidNombre(nombre) > 0)
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL )
	{
		strncpy(nombre,this->nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno = -1;
	if(this != NULL && horasTrabajadas > 0 )
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL )
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo > 0 )
	{
		this->sueldo=sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL )
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}
