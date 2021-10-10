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
#define EMPLOYEE_LENGHT 10

int main(void) {

	setbuf(stdout,NULL);

	int userChoice;
	int idAux;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;
	int requestedId;
	int requestedPosition;
	char closeVariable;
	int listOrder;

	closeVariable='n';

	Employee employeeList [EMPLOYEE_LENGHT];
	initEmployees(employeeList,EMPLOYEE_LENGHT);

	addEmployees(employeeList,EMPLOYEE_LENGHT, 10, "Nacho","Smirlian",23500,1);
	addEmployees(employeeList,EMPLOYEE_LENGHT, 11, "Antonella","Strangio",30000,3);
	addEmployees(employeeList,EMPLOYEE_LENGHT, 12, "Juan","Gonzalez",20000,1);
	addEmployees(employeeList,EMPLOYEE_LENGHT, 13 ,"Catalina","Vazquez",100000,1);
	addEmployees(employeeList,EMPLOYEE_LENGHT, 14, "Sofia","Estebanez",50000,2);
	addEmployees(employeeList,EMPLOYEE_LENGHT, 15, "Nicolas","Sivori",60000,2);
	addEmployees(employeeList,EMPLOYEE_LENGHT, 16, "Ramiro","Gonzalez",55000,1);
	addEmployees(employeeList,EMPLOYEE_LENGHT, 17, "Nacho","Smirlian",90000,2);
	addEmployees(employeeList,EMPLOYEE_LENGHT, 18, "Rodrigo","Sanchez",30000,3);

	userChoice=mainMenu();

	while(closeVariable!='s')
	{
		switch(userChoice)
		{
			case 1:

				askInformation (employeeList,EMPLOYEE_LENGHT, &idAux, nameAux, lastNameAux, &salaryAux, &sectorAux);
				addEmployees(employeeList,EMPLOYEE_LENGHT, idAux, nameAux, lastNameAux,salaryAux, sectorAux);
				userChoice=mainMenu();
				break;

			case 2:
				requestedId=askForId(employeeList,EMPLOYEE_LENGHT);
				if(requestedId!=-1&&requestedId!=-2)
					{
						requestedPosition=findEmployeeById (employeeList,EMPLOYEE_LENGHT, requestedId);
						modification(&employeeList[requestedPosition]);
					}
				userChoice=mainMenu();
				break;
			case 3:
				requestedId=askForId(employeeList,EMPLOYEE_LENGHT);
				if(requestedId!=-1&&requestedId!=-2)
					{
						removeEmployee (employeeList,EMPLOYEE_LENGHT, requestedId);
					}
				userChoice=mainMenu();
				break;

			case 4:
				pedirIntIntentosRango(&listOrder, 1, 2, 5, "Ingrese 1 para mostar en orden alfabético descendente o 2 para"
						"mostrar en orden alfabético descendente:  ", "Error, dato ingresado inválido");
				sortEmployees (employeeList,EMPLOYEE_LENGHT,listOrder);
				printEmployees(employeeList,EMPLOYEE_LENGHT);
				printf("\n\n\n");
				userChoice=mainMenu();
				break;

			case 5:
				printf("Saliendo del sistema...");
				closeVariable='s';
				break;

		}

	}


	return EXIT_SUCCESS;
}
