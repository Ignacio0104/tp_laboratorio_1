/*
 * Empleados.c
 *
 *  Created on: 6 oct 2021
 *      Author: Nacho
 */

#include "biblioteca_input.h"
#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOT_EMPTY 0
#define EMPTY 1

static int createNewId (void);
static int searchAvailable(Employee *list,int lenght, int *pEmptyPosition);

/// \fn int createNewId(void)
/// \brief create a new id for each new employee.
///
/// \return the new ID
static int createNewId (void)
{
	static int id=1;
	return (id++);
}


static int searchAvailable(Employee *list,int lenght, int *pEmptyPosition)
{
	int retorno;
	int posicionLibre;
	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			if(list[i].isEmpty==EMPTY)
			{
				posicionLibre=i;
				break;
			} else
			{
				retorno=-2;
			}

		}

		*pEmptyPosition=posicionLibre;
	}

	return retorno;

}



/// \fn int initEmployees(Employee*, int)
/// \brief To indicate that all position in the array are empty,
/// 		this function put the flag (isEmpty) in EMPTY in all position of the array
///
/// \pre
/// \post
/// \param list Employee* Pointer to array of employees
/// \param lenght Array lenght
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok

int initEmployees(Employee *list,int lenght)
{
	int retorno;

	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			list[i].isEmpty=EMPTY;
		}
	}

	return retorno;
}



int addEmployees(Employee *list, int lenght)
{
	int retorno;

	retorno=-1;

	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;


	if(list!=NULL&&lenght>0)
	{
		int position;
		searchAvailable(list,lenght, &position);

		if(pedirTexto(nameAux,sizeof(nameAux), 3, "Please enter the name of the employee: ", "Error, invalid entry")==0)
		{
			if(pedirTexto(lastNameAux,sizeof(lastNameAux), 3, "Please enter the last name of the employee: ", "Error, invalid entry")==0)
			{
				if(pedirFloat(&salaryAux, 3, "Please enter salary: " , "Error, invalid entry")==0)
				{
					if(pedirInt(&sectorAux, 3, "Enter the sector: ", "Error, invalid entry")==0)
					{
						list[position].id=createNewId();
						strncpy(list[position].name,nameAux,sizeof(list[position].name));
						strncpy(list[position].lastName,lastNameAux,sizeof(list[position].lastName));
						list[position].salary=salaryAux;
						list[position].sector=sectorAux;
						list[position].isEmpty=NOT_EMPTY;
						retorno=0;
					}

				}
			}
		}

	}

	return retorno;

}

int findEmployeeById (Employee *list, int lenght)
{
	int retorno;

	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		retorno=0;
		int requestedId;
		pedirIntIntentosRango(&requestedId, 0, 10000000, 3, "Enter ID", "Error. Invalid entry");

		for(int i=0;i<lenght;i++)
		{
			if(list[i].id==requestedId&&list->isEmpty==NOT_EMPTY)
			{
				retorno=i;
				break;
			} else
			{
				retorno=-2;
			}

		}

	}

	return retorno;

}



int printEmployees(Employee *list,int lenght)
{
	int retorno;
	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			if(list[i].isEmpty==NOT_EMPTY)

			{
				printf("ID: %d. Name: %s. Last name: %s. Salary: %f. Sector: %d.  Vacio: %d\n",
									list[i].id ,list[i].name,list[i].lastName,list[i].salary,list[i].sector, list[i].isEmpty);
			} else
			{
				printf("Espacio VACIO\n");
			}


		}

	}

	return retorno;

}

int printEmployeesById(Employee *list,int lenght,int position)
{
	int retorno;
	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		retorno=0;
		printf("ID: %d. Name: %s. Last name: %s. Salary: %f. Sector: %d.  Vacio: %d\n",
		list[position].id ,list[position].name,list[position].lastName,list[position].salary,list[position].sector, list[position].isEmpty);

	}

	return retorno;

}


