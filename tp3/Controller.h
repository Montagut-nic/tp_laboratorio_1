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

void* ll_getNext (LinkedList* this,int isFirst);
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* idMaxAlta);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* idMaxAlta);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

#endif /* CONTROLLER_H_ */
