/*
 * ArrayEmployees.c
 *
 *  Created on: 13 may. 2021
 *      Author: Montagut
 */

#include "ArrayEmployees.h"

int id_autoIncrement=0;

/** \brief To generate an id
 *
 * \return int: Return the id generated
 *
 */
int generateId(void){
	return id_autoIncrement+=1;
}


/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all
 * position of the array
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \return int: Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int flagError=-1;
	int i=0;
	if (list!=NULL && len>0){
		flagError = 0;
		for (;i<len;i++){
			list[i].isEmpty=TRUE;
		}
	}
	return flagError;
}


/** \brief add in a existing list of employees the values received as parameters in the first empty position
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \param id int: int number value to add as id
 * \param name[] char: array of char value to add as name
 * \param lastName[] char: array of char value to add as lastName
 * \param salary float: float number value to add as salary
 * \param sector int: int number value to add as sector
 * \return int: Return (-1) if Error [Invalid length or NULL pointer or without free space or invalid values received] -
 * (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int flagError=-1;
	int i;
	if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary>0 && sector>0){
		i=findEmptyEmployee(list, len);
		if(i>=0){
			setIdEmployee(&list[i], id);
			setNameEmployee(&list[i], name);
			setLastNameEmployee(&list[i], lastName);
			setSalaryEmployee(&list[i], salary);
			setSectorEmployee(&list[i], sector);
			list[i].isEmpty=FALSE;
			flagError=0;
		}
	}
	return flagError;
}


/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all
 * position of the array
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \return int: Return (-1) if Error [Invalid length or NULL pointer or ] - (0) if Ok
 *
 */
int altaEmployee(Employee* list, int len){
	Employee buffer;
	int flagError=-1;
	if(list!=NULL&&len>0){
		flagError=-2;
		if(!utn_getName(buffer.name, sizeof(buffer.name),"Enter name","Error. Not a valid name",3)
			&& !utn_getName(buffer.lastName, sizeof(buffer.lastName),"Enter last name","Error. Not a valid last name",3)
			&& !utn_getFloatLimitMinOrMax(&buffer.salary,"Enter salary","Error. Not a valid salary",3,1,0,LIM_MIN)
			&& !utn_getIntLimitMaxOrMin(&buffer.sector,"Enter sector","Error. Not a valid sector",3,1,0,LIM_MIN))
		{
			flagError=0;
			addEmployee(list, len, generateId(), buffer.name, buffer.lastName, buffer.salary, buffer.sector);
		}
	}
	return flagError;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int i;
    int flagError=-1;
    if(list!=NULL&&len>0){
		i=findEmployeeById(list,len,id);
		if(i>=0&&list[i].isEmpty==0){
			list[i].isEmpty=1;
			flagError=0;
		}
    }
    return flagError;
}

/** \brief To get the first empty position in the array
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \return int: Return (-1) if Error [Invalid length or NULL pointer or without free space] - first free space index
 * position if Ok
 *
 */
int findEmptyEmployee (Employee* list, int len)
{
	int value = -1;
	int i=0;
	if(list!=NULL && len>0){
		for (;i<len;i++){
			if (list[i].isEmpty==1){
				value=i;
				break;
			}
		}
	}
    return value;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \param id int: id to find employee
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
	int i=0;
	int flagError=-1;
	if(list!=NULL && len>0 && id>0){
		for(; i<len; i++){
			if(list[i].id==id){
				flagError=i;
				break;
			}
		}
	}
	return flagError;
}

/** \brief To set the name of a employee
 *
 * \param this Employee*: Pointer to employee
 * \param name[] char: array of char value to set as name
 * \return int: Return (-1) if Error [Invalid length or NULL pointer or invalid name] - (0) if Ok
 *
 */
int setNameEmployee(Employee* this, char name[])
{
	int flagError = -1;
	if(this!=NULL && name!=NULL && isValidName(name) )
	{
		strncpy(this->name,name,sizeof(this->name));
		flagError = 0;
	}
	return flagError;
}

/** \brief To get the name of a employee
 *
 * \param this Employee*: Pointer to employee
 * \param name[] char: array of char value to return as name
 * \return int: Return (-1) if Error [Invalid length or NULL pointer or invalid name] - (0) if Ok
 *
 */
int getNameEmployee(Employee* this, char name[])
{
	int flagError = -1;
	if(this!=NULL && name!=NULL && isValidName(name) )
	{
		strncpy(name,this->name,sizeof(this->name));
		flagError = 0;
	}
	return flagError;
}

/** \brief To set the last name of a employee
 *
 * \param this Employee*: Pointer to employee
 * \param name[] char: array of char value to set as name
 * \return int: Return (-1) if Error [Invalid length or NULL pointer or invalid name] - (0) if Ok
 *
 */
int setLastNameEmployee(Employee* this, char lastName[])
{
	int flagError = -1;
	if(this!=NULL && lastName!=NULL && isValidName(lastName) )
	{
		strncpy(this->lastName,lastName,sizeof(this->lastName));
		flagError = 0;
	}
	return flagError;
}

/** \brief To get the last name of a employee
 *
 * \param this Employee*: Pointer to employee
 * \param name[] char: array of char value to return as last name
 * \return int: Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int getLastNameEmployee(Employee* this, char lastName[])
{
	int flagError = -1;
	if(this!=NULL && lastName!=NULL)
	{
		strncpy(lastName,this->lastName,sizeof(this->lastName));
		flagError = 0;
	}
	return flagError;
}

/** \brief To set the salary of a employee
 *
 * \param this Employee*: Pointer to employee
 * \param salary float: float value to set as the salary
 * \return int: Return (-1) if Error [NULL pointer or invalid salary] - (0) if Ok
 *
 */
int setSalaryEmployee(Employee* this, float salary)
{
	int flagError = -1;
	if(this!=NULL && isValidSalary(salary) )
	{
		this->salary=salary;
		flagError = 0;
	}
	return flagError;
}

/** \brief To get the salary of a employee
 *
 * \param this Employee*: Pointer to employee
 * \return int: Return (-1) if Error [NULL pointer] - salary value if Ok
 *
 */
float getSalaryEmployee(Employee* this)
{
	int salary = -1;
	if(this!=NULL)
	{
		salary=this->salary;
	}
	return salary;
}

/** \brief To set the sector of a employee
 *
 * \param this Employee*: Pointer to employee
 * \param sector int: int value to set as the sector
 * \return int: Return (-1) if Error [NULL pointer or invalid sector] - (0) if Ok
 *
 */
int setSectorEmployee(Employee* this, int sector)
{
	int flagError = -1;
	if(this!=NULL && isValidSector(sector) )
	{
		this->sector=sector;
		flagError = 0;
	}
	return flagError;
}

/** \brief To get the sector of a employee
 *
 * \param this Employee*: Pointer to employee
 * \return int: Return (-1) if Error [NULL pointer] - sector value if Ok
 *
 */
int getSectorEmployee(Employee* this)
{
	int sector = -1;
	if(this!=NULL)
	{
		sector=this->sector;
	}
	return sector;
}

/** \brief To set the id of a employee
 *
 * \param this Employee*: Pointer to employee
 * \param id int: int value to set as the id
 * \return int: Return (-1) if Error [NULL pointer or invalid id] - (0) if Ok
 *
 */
int setIdEmployee(Employee* this, int id)
{
	int flagError = -1;
	if(this!=NULL && isValidId(id) )
	{
		this->id=id;
		flagError = 0;
	}
	return flagError;
}

/** \brief To get the id of a employee
 *
 * \param this Employee*: Pointer to employee
 * \return int: Return (-1) if Error [NULL pointer] - id value if Ok
 *
 */
int getIdEmployee(Employee* this)
{
	int id = -1;
	if(this!=NULL)
	{
		id=this->id;
	}
	return id;
}

/** \brief print the content of employees array
 *
 * \param list Employee*: Pointer to array of employees
 * \param length int: Array length
 * \return int: Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int length)
{
	int flagError=-1;
	int i=0;
	if(list!=NULL && length>0){
		for(;i<length;i++){
			printf("ID --- NAME - LAST NAME - SECTOR - SALARY");
			printOneEmployee(&list[i]);
		}
	}
	return flagError;
}

/** \brief print the information of one employee
 *
 * \param element Employee*: Pointer to employee
 * \return int: Return (-1) if Error [Element is empty or NULL pointer] - (0) if Ok
 *
 */
int printOneEmployee(Employee* element)
{
	int flagError=-1;
	int id;
	char name[CHAR_LEN];
	char lastName[CHAR_LEN];
	int sector;
	float salary;
	if(element!=NULL && element->isEmpty==0){
		flagError=0;
		id=getIdEmployee(element);
		getNameEmployee(element, name);
		getLastNameEmployee(element, lastName);
		sector=getSectorEmployee(element);
		salary=getSalaryEmployee(element);
		printf("%d --- %s - %s - %d - $ %f",id,name,lastName,sector,salary);
	}
	return flagError;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
return 0;
}
