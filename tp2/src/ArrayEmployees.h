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

int generateId(void);
int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmptyEmployee (Employee* list, int len);
int printEmployees(Employee* list, int length);
int printOneEmployee(Employee* element);

float getSalaryEmployee(Employee* this);
int getNameEmployee(Employee* this, char name[]);
int getLastNameEmployee(Employee* this, char lastName[]);
int getSectorEmployee(Employee* this);
int getIdEmployee(Employee* this);
int setSalaryEmployee(Employee* this, float salary);
int setNameEmployee(Employee* this, char name[]);
int setLastNameEmployee(Employee* this, char lastName[]);
int setSectorEmployee(Employee* this, int sector);
int setIdEmployee(Employee* this, int id);


#endif /* ARRAYEMPLOYEES_H_ */
