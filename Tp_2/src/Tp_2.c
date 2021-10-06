/*
 ============================================================================
 Name        : Tp_2.c
 Author      : Ignacio Martín Smirlian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_input.h"
#include "ArrayEmployees.h"
#define EMPLOYEE_LENGHT 3

int main(void) {

	setbuf(stdout,NULL);

	int i=0;
	int requestedPosition;
	char seguir;

	Employee employeeList [EMPLOYEE_LENGHT];

	initEmployees(employeeList,EMPLOYEE_LENGHT);

	pedirCharSiNo(&seguir,'s', 'n', 3, "Desea cargar un dato?", "Error");

	while(i<EMPLOYEE_LENGHT&&seguir=='s')

	{
		addEmployees(employeeList,EMPLOYEE_LENGHT);
		pedirCharSiNo(&seguir,'s', 'n', 3, "Desea cargar un dato?", "Error");
	}

	requestedPosition=findEmployeeById (employeeList,EMPLOYEE_LENGHT);

	if(requestedPosition>=0)
	{
		printEmployeesById(employeeList,EMPLOYEE_LENGHT,requestedPosition);
	}

	//printEmployees(employeeList,EMPLOYEE_LENGHT);

	return EXIT_SUCCESS;
}
