#include "Employee.h"

static int currentId;


/** \brief Inicializa el valor del id para el alta.
 *
 * \param id int: valor int del id max obtenido de la carga del archivo
 * \return void
 *
 */
void employee_initId(int id){
	currentId=id;
}

/** \brief Genera el valor int del nuevo id para el alta.
 *
 * \return int: valor int del id para el alta
 *
 */
int employee_generateId(){
	currentId++;
	return currentId;
}

/* \brief Reserva espacio en memoria para un empleado
 *
 * \return Employee*: retorna [NULL si no hay mas memoria] [puntero a elemento tipo Employee si obtuvo un espacio en memoria]
 */
Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

/* \brief Valida y setea los valores para un elemento tipo Employee
 *
 * \param idStr char*: cadena de caracteres que representa el id
 * \param nombreStr char*: cadena de caracteres que representa el nombre
 * \param horasTrabajadasStr char*: cadena de caracteres que representa las horas trabajadas
 * \param sueldoStr char*: cadena de caracteres que representa al sueldo
 *
 * \return Employee*: retorna el puntero al elemento tipo Employee seteado con los valores
 */
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

/* \brief Libera el espacio en memoria de un elemento tipo Employee
 * \param this Employee*: puntero al elemento tipo Employee a borrar de memoria
 * \return void
 */
void employee_delete(Employee* this){
	free(this);
}

/* \brief Valida y setea el id de un elemento tipo Employee
 * \param this Employee*: puntero al elemento tipo Employee
 * \param id int : valor int que representa el id
 * \return int: [0 si esta OK] [-1 en caso de error]
 */
int employee_setId(Employee* this,int id){
	int retorno = -1;
	if(this != NULL && id > 0 )
	{
		this->id=id;
		retorno = 0;
	}
	return retorno;
}

/* \brief Obtiene el id de un elemento tipo Employee
 * \param this Employee*: puntero al elemento tipo Employee
 * \param id int*: puntero a int donde se va a guardar el valor del id
 * \return int: [0 si esta OK] [-1 en caso de error]
 */
int employee_getId(Employee* this,int* id){
	int retorno = -1;
	if(this != NULL && id != NULL )
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/* \brief Valida y setea el nombre de un elemento tipo Employee
 * \param this Employee*: puntero al elemento tipo Employee
 * \param nombre char*: cadena de caracteres que representa el nombre
 * \return int: [0 si esta OK] [-1 en caso de error]
 */
int employee_setNombre(Employee* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL && isValidNombre(nombre) > 0)
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

/* \brief Obtiene el nombre de un elemento tipo Employee
 * \param this Employee*: puntero al elemento tipo Employee
 * \param nombre char*: cadena de caracteres donde se va a guardar el nombre
 * \return int: [0 si esta OK] [-1 en caso de error]
 */
int employee_getNombre(Employee* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL )
	{
		strncpy(nombre,this->nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

/* \brief Valida y setea el campo horasTrabajadas de un elemento tipo Employee
 * \param this Employee*: puntero al elemento tipo Employee
 * \param horasTrabajadas int : valor int que representa las horas trabajadas
 * \return int: [0 si esta OK] [-1 en caso de error]
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno = -1;
	if(this != NULL && horasTrabajadas > 0 )
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/* \brief Obtiene el valor del campo horasTrabajadas de un elemento tipo Employee
 * \param this Employee*: puntero al elemento tipo Employee
 * \param horasTrabajadas int*: puntero a int donde se va a guardar el valor de las horasTrabajadas
 * \return int: [0 si esta OK] [-1 en caso de error]
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL )
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/* \brief Valida y setea el campo sueldo de un elemento tipo Employee
 * \param this Employee*: puntero al elemento tipo Employee
 * \param sueldo int : valor int que representa el sueldo
 * \return int: [0 si esta OK] [-1 en caso de error]
 */
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

/* \brief Obtiene el valor del campo sueldo de un elemento tipo Employee
 * \param this Employee*: puntero al elemento tipo Employee
 * \param sueldo int*: puntero a int donde se va a guardar el valor del sueldo
 * \return int: [0 si esta OK] [-1 en caso de error]
 */
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

/** \brief Compara el id de dos elementos tipo Employee
 *
 * \param pEmpleadoA void*: puntero a void
 * \param pEmpleadoB void*: puntero a void
 *
 * \return int: retorna [0 en caso de error] [1 si el id de pEmpleadoA es mayor al de pEmpleadoB]
 * [-1 si el id de pEmpleadoA es menor al de pEmpleadoB]
 */
int employee_comparaId(void*pEmpleadoA,void*pEmpleadoB){
	int retorno=0;
	int idA;
	int idB;
	if( pEmpleadoA!=NULL && pEmpleadoB!=NULL &&
		!employee_getId((Employee*)pEmpleadoA, &idA) &&
		!employee_getId((Employee*)pEmpleadoB, &idB) )
	{
		if(idA>idB){
			retorno=1;
		}
		if(idB>idA){
			retorno=-1;
		}
	}
	return retorno;
}

/** \brief Compara el campo sueldo de dos elementos tipo Employee
 *
 * \param pEmpleadoA void*: puntero a void
 * \param pEmpleadoB void*: puntero a void
 *
 * \return int: retorna [0 en caso de error] [1 si el sueldo de pEmpleadoA es mayor o igual al de pEmpleadoB]
 * [-1 si el sueldo de pEmpleadoA es menor al de pEmpleadoB]
 */
int employee_comparaSueldo(void*pEmpleadoA,void*pEmpleadoB){
	int retorno=0;
	int sueldoA;
	int sueldoB;
	if( pEmpleadoA!=NULL && pEmpleadoB!=NULL &&
		!employee_getSueldo((Employee*)pEmpleadoA, &sueldoA) &&
		!employee_getSueldo((Employee*)pEmpleadoB, &sueldoB) )
	{
		if(sueldoA>=sueldoB){
			retorno=1;
		}else{
			retorno=-1;
		}
	}
	return retorno;
}

/** \brief Compara el campo horasTrabajadas de dos elementos tipo Employee
 *
 * \param pEmpleadoA void*: puntero a void
 * \param pEmpleadoB void*: puntero a void
 *
 * \return int: retorna [0 en caso de error] [1 si horasTrabajadas de pEmpleadoA es mayor o igual al de pEmpleadoB]
 * [-1 si horasTrabajadas de pEmpleadoA es menor al de pEmpleadoB]
 */
int employee_comparaHoras(void*pEmpleadoA,void*pEmpleadoB){
	int retorno=0;
	int horasA;
	int horasB;
	if( pEmpleadoA!=NULL && pEmpleadoB!=NULL &&
		!employee_getHorasTrabajadas((Employee*)pEmpleadoA, &horasA) &&
		!employee_getHorasTrabajadas((Employee*)pEmpleadoB, &horasB) )
	{
		if(horasA>=horasB){
			retorno=1;
		}else{
			retorno=-1;
		}
	}
	return retorno;
}

/** \brief Compara el nombre de dos elementos tipo Employee
 *
 * \param pEmpleadoA void*: puntero a void
 * \param pEmpleadoB void*: puntero a void
 *
 * \return int: retorna [0 en caso de error] [1 si el nombre de pEmpleadoA es mayor o igual al de pEmpleadoB]
 * [-1 si el nombre de pEmpleadoA es menor al de pEmpleadoB]
 */
int employee_comparaNombre(void*pEmpleadoA,void*pEmpleadoB){
	int retorno=0;
	char nombreA[128];
	char nombreB[128];
	if( pEmpleadoA!=NULL && pEmpleadoB!=NULL &&
		!employee_getNombre((Employee*)pEmpleadoA, nombreA) &&
		!employee_getNombre((Employee*)pEmpleadoB, nombreB) )
	{
		if(strncmp(nombreA,nombreB,sizeof(nombreA))<0){
			retorno=-1;
		}else{
			retorno=1;
		}
	}
	return retorno;
}

/** \brief Imprime un elemento Employee
 * \param this Employee*: puntero a Employee a ser impreso por consola
 * \return int: retorna [-1 en caso de error] [0 si esta OK]
 */
int employee_printEmployee(Employee* this){
	int horasTrabajadasAux;
	int idAux;
	int sueldoAux;
	char nombreAux[128];
	int retorno=-1;
	if( this!=NULL &&
		!employee_getHorasTrabajadas(this, &horasTrabajadasAux) &&
		!employee_getId(this, &idAux) &&
		!employee_getNombre(this, nombreAux) &&
		!employee_getSueldo(this, &sueldoAux) )
	{
		retorno=0;
		printf("\nID: %d, Nombre: %s, Sueldo: %d, Horas Trabajadas: %d\n",idAux,nombreAux,sueldoAux,horasTrabajadasAux);
	}
	return retorno;
}
