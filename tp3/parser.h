/*
 * parser.h
 *
 *  Created on: 1 jun. 2021
 *      Author: Montagut
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee, int* idMaxObt);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee, int*idMaxObt);

#endif /* PARSER_H_ */
