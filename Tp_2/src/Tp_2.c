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
	char inputFlag;

	closeVariable='n';
	inputFlag='n';

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
				if(addEmployees(employeeList,EMPLOYEE_LENGHT, idAux, nameAux, lastNameAux,salaryAux, sectorAux)==0)
					{
					inputFlag='s';
					}
				userChoice=mainMenu();
				break;

			case 2:

				if(inputFlag=='s')
				{
					printEmployees(employeeList,EMPLOYEE_LENGHT);
					requestedId=askForId(employeeList,EMPLOYEE_LENGHT);
					if(requestedId!=-1&&requestedId!=-2)
						{
							requestedPosition=findEmployeeById (employeeList,EMPLOYEE_LENGHT, requestedId);
							modification(&employeeList[requestedPosition]);
						}
				} else
				{
					printf("Aún no se han ingresado datos\n");
				}

				userChoice=mainMenu();
				break;

			case 3:

				if(inputFlag=='s')
				{
					printEmployees(employeeList,EMPLOYEE_LENGHT);
					requestedId=askForId(employeeList,EMPLOYEE_LENGHT);
					if(requestedId!=-1&&requestedId!=-2)
						{
							removeEmployee (employeeList,EMPLOYEE_LENGHT, requestedId);
						}
				}else
				{
					printf("Aún no se han ingresado datos\n");
				}

				userChoice=mainMenu();
				break;

			case 4:
				if(inputFlag=='s')
				{
					userChoiceSubMenu=submenuReports();
					averageSalaryFunction (employeeList,EMPLOYEE_LENGHT, &averageSalary,&totalSalary);
					switch (userChoiceSubMenu)
					{
						case 'a':
							sortEmployees (employeeList,EMPLOYEE_LENGHT,2);
							printEmployees(employeeList,EMPLOYEE_LENGHT);
							break;
						case 'b':
							sortEmployees (employeeList,EMPLOYEE_LENGHT,1);
							printEmployees(employeeList,EMPLOYEE_LENGHT);
							break;
						case 'c':
							printf("El total de la suma de todos los salarios es: %.2f\n",totalSalary);
							printf("El promedio de todos los salarios es: %.2f\n",averageSalary);
							break;
						case 'd':
							printEmployeesBySalary(employeeList,EMPLOYEE_LENGHT,averageSalary);
							break;
						case 'e':
						default:
							printf("Volviendo al menú principal...");
					}
				} else
				{
					printf("Aún no se han ingresado datos\n");
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
