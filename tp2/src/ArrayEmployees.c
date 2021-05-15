/*
 * ArrayEmployees.c
 *
 *  Created on: 13 may. 2021
 *      Author: Montagut
 */

#include "ArrayEmployees.h"

/** \brief To generate an id
 *
 * \return int: Return the id generated
 *
 */
int generateId(void){
	static int id_autoIncrement=0;
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
			list[i].isEmpty=1;
		}
	}
	return flagError;
}

/** \brief To show the main menu and let the user interact with the list
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \return int: Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int showMainMenuEmployees(Employee* list,int len){
	int option;
	int flagError=-1;
	int qtyEmployee=0;
	int id;
	if(list!=NULL && len>0){
		flagError=0;
		do{
			if(!utn_getInt(&option,"\nSelect option:\n\n1.Add employee\n2.Modify employee\n3.Delete employee\n4.Inform\n5.Exit\n",
					"\nError. Not a valid option.\n",3,1,5))
			{
				switch(option)
				{
					case 1:
						if( !(findEmptyEmployee(list, len)<0) && !newEmployee(list, len) )
						{
							qtyEmployee++;
							printf("\nEmployee added to the list.\n");
						}
						break;
					case 2:
						if(qtyEmployee!=0){
							if(!modifyEmployee(list, len)){
								printf("\nChanges saved.\n");
							}
						}else{
							printf("\nThere are no employees on the list\n");
						}
						break;
					case 3:
						if(qtyEmployee!=0){
							utn_getIntLimitMaxOrMin(&id,"\nId?\n","\nError. Not a valid id.\n",3,1,0,LIM_MIN);
							if(!removeEmployee(list, len, id)){
								printf("\nEmployee removed.\n");
								qtyEmployee--;
							}
						}else{
							printf("\nThere are no employees on the list\n");
						}
						break;
					case 4:
						if(qtyEmployee!=0){
							showInformMenuEmployees(list, len);
						}else{
							printf("\nThere are no employees on the list\n");
						}
						break;
				}
			}
		}while(option!=5);
	}
	return flagError;
}

/** \brief To show the inform menu and let the user interact
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \return int: Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int showInformMenuEmployees(Employee* list,int len){
	int option;
	int flagError=-1;
	int order;
	if(list!=NULL && len>0){
		flagError=0;
		do{
			if(!utn_getInt(&option,"\nSelect option:\n\n"
									"1.Employees arranged by last name and sector\n"
									"2.Total salaries, average salary and quantity of employees with above average salary\n"
									"3.Go back\n", "\nError. Not a valid option.\n",3,1,3))
			{
				switch(option)
				{
					case 1:
						if(!utn_getInt(&order,"\nOrder?\n[UP:1]\t[DOWN:0]\n","\nError. Not a valid option",3,0,1)
								&&!sortEmployees(list, len, order)){
							printEmployees(list, len);
						}
						break;
					case 2:
						infoSalaries(list, len);
						break;
				}
			}
		}while(option!=3);
	}
	return flagError;
}

/** \brief To show the modify menu to the user and modify employee
 *
 * \param list Employee*: Pointer to employee
 * \return int: Return (-1) if Error [NULL pointer or employee is empty] - chosen option by the user
 * (5) to save changes or (6) to cancel changes
 *
 */
int showModifyMenuEmployees(Employee* element){
	char message[ARRAY_LEN];
	int option=-1;
	char name[CHAR_LEN];
	char lastName[CHAR_LEN];
	float salary;
	int sector;
	if(element!=NULL){
		getNameEmployee(element, name);
		getLastNameEmployee(element, lastName);
		salary=getSalaryEmployee(element);
		sector=getSectorEmployee(element);
		do{
			snprintf(message,ARRAY_LEN,"\nSelect:\n\n"
											"1. Change name ( %s )\n"
											"2. Change last name ( %s )\n"
											"3. Change sector ( %d )\n"
											"4. Change salary ( $%.2f )\n"
											"5. Save changes and continue\n"
											"6. Cancel\n",
										name,lastName,sector,salary);
			if(!utn_getInt(&option,message,"Error. Not a valid option",2,1,6))
			{
				switch (option){
					case 1:
						if(!utn_getName(name,CHAR_LEN,"\nNew name:\n","\nError. Not a valid name.\n",2)){
							setNameEmployee(element, name);
						}
						break;
					case 2:
						if(!utn_getName(lastName,CHAR_LEN,"\nNew last name:\n","\nError. Not a valid last name.\n", 2)){
							setLastNameEmployee(element, lastName);
						}
						break;
					case 3:
						if(!utn_getIntLimitMaxOrMin(&sector,"\nNew sector:","\nError. Not a valid sector.\n",2,1,0,LIM_MIN)){
							setSectorEmployee(element, sector);
						}
						break;
					case 4:
						if(!utn_getFloatLimitMinOrMax(&salary,"\nNew salary:","\nError. Not a valid salary.\n",2,1,0,LIM_MIN)){
							setSalaryEmployee(element, salary);
						}
						break;
				}
			}
		}while(option!=6&&option!=5);
	}
	return option;
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
 * \return int: Return (-1) if Error [Invalid length or NULL pointer or without free space or invalid values received] - (0) if Ok
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
			printf("\nYour id is %d\n",id);
			flagError=0;
		}
	}
	return flagError;
}


/** \brief To request information about new employee and add it to the list
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \return int: Return (-1) if Error [Invalid length or NULL pointer or user canceled or user run out of attempts] - (0) if Ok
 *
 */
int newEmployee(Employee* list, int len){
	Employee buffer;
	int flagError=-1;
	int resp;
	if(list!=NULL&&len>0){
		if(utn_getName(buffer.name, sizeof(buffer.name),"\nName?\n","\nError. Not a valid name\n",3)==0
			&& utn_getName(buffer.lastName, sizeof(buffer.lastName),"\nLast name?\n","\nError. Not a valid last name\n",3)==0
			&& utn_getIntLimitMaxOrMin(&buffer.sector,"\nSector?\n","\nError. Not a valid sector\n",3,1,0,LIM_MIN)==0
			&& utn_getFloatLimitMinOrMax(&buffer.salary,"\nSalary?\n","\nError. Not a valid salary\n",3,1,0,LIM_MIN)==0)
		{
			resp=showModifyMenuEmployees(&buffer);
			if(resp==5){
				flagError=0;
				addEmployee(list,len,generateId(),buffer.name,buffer.lastName,buffer.salary,buffer.sector);
			}
		}
	}
	return flagError;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \param id int: Id of employee to remove
 * \return int Return (-1) if Error [Invalid length or NULL pointer or invalid id or cant find a employee or cancel removal] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int i;
    int flagError=-1;
    int confirm;
    if(list!=NULL&&len>0&&id>0){
		i=findEmployeeById(list,len,id);
		if(i>=0 && list[i].isEmpty==0){
			printf("ID\t\tNAME\t\tLAST NAME\tSECTOR\tSALARY\n\n");
			printOneEmployee(&list[i]);
			if(!utn_getInt(&confirm,"\nDo you want to remove this employee from the list?\n[YES:1]\t[NO:0]\n",
					"\nError. Not a valid option\n",3,0,1)
				&& confirm == 1)
			{
				list[i].isEmpty=1;
				flagError=0;
			}
		}
    }
    return flagError;
}


/** \brief To request employee id and modify employee information
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \return int: Return (-1) if Error [Invalid length or NULL pointer
 * or user canceled/run out of attempts or employee not found] - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int len){
	int i;
	int id;
	int flagError=-1;
	int resp;
	Employee buffer;
	if(list!=NULL&&len>0){
		utn_getIntLimitMaxOrMin(&id,"\nId?\n","\nError. Not a valid id.\n",3,1,0,LIM_MIN);
		i=findEmployeeById(list,len,id);
		if(i>=0&&list[i].isEmpty==0){
			buffer = list[i];
			resp=showModifyMenuEmployees(&buffer);
			if(resp==5){
				list[i] = buffer;
				flagError=0;
			}
		}
	}
	return flagError;
}

/** \brief To get the first empty position in the array
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \return int: Return (-1) if Error [Invalid length or NULL pointer or without free space] - first
 *  free space index position if Ok
 *
 */
int findEmptyEmployee (Employee* list, int len)
{
	int position = -1;
	int i=0;
	if(list!=NULL && len>0){
		for (;i<len;i++){
			if (list[i].isEmpty==1){
				position=i;
				break;
			}
		}
		if(position<0){
			printf("\nTheres no more free space in the list.\n");
		}
	}
    return position;
}

/** \brief find an Employee by Id, returns the index position in array.
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
	int position=-1;
	if(list!=NULL && len>0 && id>0){
		for(; i<len; i++){
			if(getIdEmployee(&list[i])==id && list[i].isEmpty==0){
				position=i;
				break;
			}
		}
		if(position<0){
			printf("\nError. Id not found.\n");
		}
	}
	return position;
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
 * \return int: Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int getNameEmployee(Employee* this, char name[])
{
	int flagError = -1;
	if(this!=NULL && name!=NULL)
	{
		strncpy(name,this->name,sizeof(this->name));
		flagError = 0;
	}
	return flagError;
}

/** \brief To set the last name of a employee
 *
 * \param this Employee*: Pointer to employee
 * \param name[] char: array of char value to set as last name
 * \return int: Return (-1) if Error [NULL pointer or invalid name] - (0) if Ok
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
	float salary = -1;
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
		printf("ID\t\tNAME\t\tLAST NAME\tSECTOR\tSALARY\n\n");
		for(;i<length;i++){
			printOneEmployee(&list[i]);
		}
	}
	return flagError;
}

/** \brief print the information of one employee
 *
 * \param element Employee*: Pointer to employee
 * \return int: Return (-1) if Error [Employee is empty or NULL pointer] - (0) if Ok
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
		printf("%-15d %-15s %-15s  %d\t $%.2f\n",id,name,lastName,sector,salary);
	}
	return flagError;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \param order int: [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
	int flagSwap;
	int retorno=-1;
	Employee auxElement;
    int i=0;
    int auxCmp;
    char lastName[CHAR_LEN];
    char nextLastName[CHAR_LEN];
    int sector;
    int nextSector;
    if(list!=NULL&&len>0&&(order == UP || order == DOWN)){
    	retorno=0;
		do{
			flagSwap=0;
			for(;i<len-1;i++){
				if(list[i].isEmpty==1||list[i+1].isEmpty==1){
					continue;
				}
				getLastNameEmployee(&list[i],lastName);
				getLastNameEmployee(&list[i+1],nextLastName);
				sector=getSectorEmployee(&list[i]);
				nextSector=getSectorEmployee(&list[i+1]);
				auxCmp=strncmp(lastName,nextLastName,CHAR_LEN);
				if(order==UP && (auxCmp>0 || (auxCmp==0 && sector>nextSector)))
				{
					flagSwap=1;
					auxElement=list[i];
					list[i]=list[i+1];
					list[i+1]=auxElement;
				}
				if(order==DOWN && (auxCmp<0 || (auxCmp==0 && sector<nextSector)))
				{
					flagSwap=1;
					auxElement=list[i];
					list[i]=list[i+1];
					list[i+1]=auxElement;
				}
			}
			len--;
		}while(flagSwap);
    }
    return retorno;
}

/** \brief To show information about the salaries, total, average and quantity above average salaries
 *
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int infoSalaries(Employee* list, int len){
	int i;
	int flagError=-1;
	float averageSalary;
	float employeeSalary;
	float totalSalaries=0;
	int qtyEmployee=0;
	int qtyAboveAverage=0;
	if(list!=NULL&&len>0){
		flagError=0;
		for(i=0;i<len;i++){
			if(list[i].isEmpty==0){
				employeeSalary=getSalaryEmployee(&list[i]);
				if(employeeSalary>0){
					totalSalaries+=employeeSalary;
					qtyEmployee++;
				}
			}
		}
		averageSalary=totalSalaries/qtyEmployee;
		for(i=0;i<len;i++){
			if(list[i].isEmpty==0){
				employeeSalary=getSalaryEmployee(&list[i]);
				if(employeeSalary>averageSalary){
					qtyAboveAverage++;
				}
			}
		}
		printf("\nThe total salaries is %.2f, the average salary is %.2f, the quantity of salaries above average is %d.\n",
				totalSalaries,averageSalary,qtyAboveAverage);
	}
	return flagError;
}
