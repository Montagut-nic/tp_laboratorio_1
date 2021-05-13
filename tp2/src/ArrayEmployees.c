/*
 * ArrayEmployees.c
 *
 *  Created on: 13 may. 2021
 *      Author: Montagut
 */

#include "ArrayEmployees.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list: Employee* Pointer to array of employees
 * \param len int: Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int flagError=-1;
	int i=0;
	if (list!=NULL && len>0){
		flagError = 0;
		for (;i<len;i++){
			list[i].isEmpty=1;
		}
	}
	return flagError;
}

/** \brief add in a existing list of employees the values received as parameters in the first empty position
 * \param list employee*: Pointer to array of employees
 * \param len int: Array length
 * \param id int: int number value to add as id
 * \param name[] char: array of char value to add as name
 * \param lastName[] char: array of char value to add as lastName
 * \param salary float: float number value to add as salary
 * \param sector int: int number value to add as sector
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int flagError=-1;
	if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL)
	return -1;
}

/** \brief To get the first empty position in the array
 * \param list: Employee* Pointer to array of employees
 * \param len int: Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - first free
 * space index position if ok
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
