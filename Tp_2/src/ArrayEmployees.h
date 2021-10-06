/*
 * Empleados.h
 *
 *  Created on: 6 oct 2021
 *      Author: Nacho
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "biblioteca_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOT_EMPTY 0
#define EMPTY 1

typedef struct {

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

int initEmployees(Employee *list,int lenght);
int printEmployees(Employee *list,int lenght);
int printEmployeesById(Employee *list,int lenght,int position);
int addEmployees(Employee *list, int lenght);
int findEmployeeById (Employee *list, int lenght);


#endif /* ARRAYEMPLOYEES_H_ */
