/*
 * Controller.h
 *
 *  Created on: 1 jun. 2021
 *      Author: Montagut
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee,int*pFlagCarga);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee,int*pFlagCarga);
int controller_addEmployee(LinkedList* pArrayListEmployee, int flagCarga);
int controller_editEmployee(LinkedList* pArrayListEmployee, int flagCarga);
int controller_removeEmployee(LinkedList* pArrayListEmployee, int flagCarga);
int controller_ListEmployee(LinkedList* pArrayListEmployee, int flagCarga);
int controller_sortEmployee(LinkedList* pArrayListEmployee, int flagCarga);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee,int flagCarga,int*pFlagGuardado);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee,int flagCarga,int*pFlagGuardado);

#endif /* CONTROLLER_H_ */
