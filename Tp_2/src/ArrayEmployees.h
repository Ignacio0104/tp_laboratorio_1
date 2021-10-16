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

/// \fn int initEmployees(Employee*, int)
/// \brief receives an array and change all of their element's status to EMPTY
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \return Return 0 if the list and lenght are valid or -1 if there was an error [Invalid length or NULL pointer]
int initEmployees(Employee *list,int lenght);



/// \fn int printEmployees(Employee*, int, int, int)
/// \brief  prints all the positions of the array that are NOT_EMPTY
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \param totalEmpty receives this var from to indicate how many slots are left
/// \param totalNotEmpty receives this var from to indicate how many slots are taken
/// \return Return 0 if the list and lenght are valid or -1 if there was an error [Invalid length or NULL pointer]
int printEmployees(Employee *list,int lenght, int totalEmpty, int totalNotEmpty);



/// \fn int printEmployeesBySalary(Employee*, int, float)
/// \brief prints all the positions of the array that are NOT_EMPTY and meet the salary condition
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \param salaryVar receives the var that indicates the salary condition
/// \return Return 0 if the list and lenght are valid or -1 if there was an error [Invalid length or NULL pointer]
int printEmployeesBySalary(Employee *list,int lenght,float salaryVar);



/// \fn int addEmployees(Employee*, int, int, char[], char[], float, int)
/// \brief add in a existing list of employees the values received as parameters in the first empty position
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \param id receives the int from the indicated var
/// \param name receives the char[] from the indicated var
/// \param lastName receives the char[] from the indicated var
/// \param salary receives the float from the indicated var
/// \param sector receives the id from the indicated var
/// \return Return 0 if the list and lenght are valid or -1 if there was an error [Invalid length, NULL pointer, No Empty slots, input errors]
int addEmployees(Employee *list, int lenght, int id, char name[], char lastName[],float salary, int sector);



/// \fn int findEmployeeById(Employee*, int, int)
/// \brief find an Employee by Id en returns the index position in array.
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \param id receives the int from the indicated var
/// \return Return the array position if the list and lenght are valid and the ID was found or -1 if there was an error [Invalid length, NULL pointer, ID not found]
int findEmployeeById (Employee *list, int lenght, int id);



/// \fn int askForId(void)
/// \brief Ask for a number and validates that it's an int within the specified range
/// \return Return input number if it is valid or -2 if the input couldn't be processed
int askForId (void);



/// \fn int removeEmployee(Employee*, int, int)
/// \brief  Remove a Employee by Id (validate that the ID exist) and put isEmpty Flag in EMPTY
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \param id receives the int from the indicated var
/// \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
int removeEmployee (Employee *list, int lenght, int id);



/// \fn int sortEmployees(Employee*, int, int)
/// \brief Sort the elements in the array of employees.
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \param order the argument indicates UP or DOWN order
/// \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortEmployees (Employee *list, int lenght, int order);



/// \fn int askInformation(Employee*, int, int*, char*, char*, float*, int*)
/// \brief Ask for all the necessary information to upload a new employee
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \param pId * pointer to the var where the ID will be stored
/// \param pName * pointer to the array where the name will be stored
/// \param pLastName * pointer to the array where the last Name will be stored
/// \param pSalary * pointer to the var where the salary will be stored
/// \param pSector * pointer to the var where the sector will be stored
/// \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int askInformation (Employee *list, int lenght, int *pId, char *pName, char * pLastName, float *pSalary, int * pSector);



/// \fn int mainMenu(void)
/// \brief Prints the menu with its options and ask for an int
/// \return Return user's choice or (-1) if the input couldn't be processed
int mainMenu (void);



/// \fn int modification(Employee*)
/// \brief prints a menu with the different options and modify the one that user chooses
/// \param list Employee* pointer to the position of the array of employees
/// \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modification (Employee *list);



/// \fn int averageSalaryFunction(Employee*, int, float*, float*)
/// \brief Calculates the average salary of all the array.
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \param pPromedio * pointer to the var where the average salary will be stored
/// \param pTotal * pointer to the var where the total salary will be stored
/// \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok - (-2) if salaries or employees are zero
int averageSalaryFunction (Employee *list,int lenght, float* pPromedio,float* pTotal);



/// \fn int submenuReports(void)
/// \brief Prints the reports sub menu with its options and ask for a char
/// \return Return user's choice or ('x') if the input couldn't be processed
int submenuReports (void);



/// \fn int occupancy(Employee*, int, int*, int*)
/// \brief Calculates the free slots to show to the user, and to let him know if the array if full (or empty)
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \param pEmpty * pointer to the var where the amount of empty slots will be stored
/// \param pNotEmpty * pointer to the var where the amount of not empty slots will be stored
/// \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int occupancy (Employee *list,int lenght, int* pEmpty, int* pNotEmpty);



/// \fn int printReports(Employee*, int, char, float, float, int, int)
/// \brief Receives the user's choice and shows the accurate report.
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \param userChoice receives the char chose by the user
/// \param totalSalary receives the var where the total salary is stored
/// \param averageSalary receives the var where the average salary is stored
/// \param totalEmpty receives the var where the amount of empty slots will be stored
/// \param totalNotEmpty receives the where the amount of not empty slots will be stored
/// \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int printReports (Employee *list,int lenght,char userChoice, float totalSalary, float averageSalary, int totalEmpty, int totalNotEmpty);


#endif /* ARRAYEMPLOYEES_H_ */
