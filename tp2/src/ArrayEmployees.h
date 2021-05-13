/*
 * ArrayEmployees.h
 *
 *  Created on: 13 may. 2021
 *      Author: Montagut
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "utn.h"

#define CHAR_LEN 51

struct
{
	int id;
	char name[CHAR_LEN];
	char lastName[CHAR_LEN];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

#endif /* ARRAYEMPLOYEES_H_ */
