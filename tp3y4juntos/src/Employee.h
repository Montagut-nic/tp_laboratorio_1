#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

void employee_initId(int id);
int employee_generateId();
Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_comparaId(void*pEmpleadoA,void*pEmpleadoB);
int employee_comparaSueldo(void*pEmpleadoA,void*pEmpleadoB);
int employee_comparaHoras(void*pEmpleadoA,void*pEmpleadoB);
int employee_comparaNombre(void*pEmpleadoA,void*pEmpleadoB);

int employee_printEmployee(Employee* this);

#endif // employee_H_INCLUDED
