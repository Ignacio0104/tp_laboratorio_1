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
#define EMPLOYEE_LENGHT 1000

int main(void) {

	setbuf(stdout,NULL);

	int userChoice;
	char userChoiceSubMenu;
	int idAux;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;
	int requestedId;
	int requestedPosition;
	char closeVariable;
	float totalSalary;
	float averageSalary;
	int totalEmpty;
	int totalNotEmpty;

	closeVariable='n';

	Employee employeeList [EMPLOYEE_LENGHT];
	initEmployees(employeeList,EMPLOYEE_LENGHT);

	userChoice=mainMenu();

	while(closeVariable!='s')
	{
		switch(userChoice)
		{
			case 1:

				if(askInformation (employeeList,EMPLOYEE_LENGHT, &idAux, nameAux, lastNameAux, &salaryAux, &sectorAux)==0)
				{
					addEmployees(employeeList,EMPLOYEE_LENGHT, idAux, nameAux, lastNameAux,salaryAux, sectorAux);
				} else
				{
					printf("\nNo pudo realizarse la carga \n\n");
				}

				userChoice=mainMenu();
				break;

			case 2:
				occupancy (employeeList,EMPLOYEE_LENGHT, &totalEmpty, &totalNotEmpty);
				if(totalNotEmpty>0)
				{
					printEmployees(employeeList,EMPLOYEE_LENGHT,totalEmpty, totalNotEmpty);
					requestedId=askForId();
					requestedPosition=findEmployeeById(employeeList,EMPLOYEE_LENGHT, requestedId);
					if(requestedPosition>=0)
						{
							modification(&employeeList[requestedPosition]);
						}
				} else
				{
					printf("No hay datos para modificar\n");
				}

				userChoice=mainMenu();
				break;

			case 3:
				occupancy (employeeList,EMPLOYEE_LENGHT, &totalEmpty, &totalNotEmpty);
				if(totalNotEmpty>0)
				{
					printEmployees(employeeList,EMPLOYEE_LENGHT,totalEmpty, totalNotEmpty);
					requestedId=askForId();
					if(requestedId!=-1&&requestedId!=-2)
						{
							removeEmployee (employeeList,EMPLOYEE_LENGHT, requestedId);
						}
				}else
				{
					printf("No hay datos para modificar\n");
				}

				userChoice=mainMenu();
				break;

			case 4:
				occupancy (employeeList,EMPLOYEE_LENGHT, &totalEmpty, &totalNotEmpty);
				if(totalNotEmpty>0)
				{
					userChoiceSubMenu=submenuReports();
					averageSalaryFunction (employeeList,EMPLOYEE_LENGHT, &averageSalary,&totalSalary);
					printReports (employeeList,EMPLOYEE_LENGHT,userChoiceSubMenu, totalSalary, averageSalary, totalEmpty, totalNotEmpty);

				} else
				{
					printf("No hay datos para mostrar\n");
				}


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
