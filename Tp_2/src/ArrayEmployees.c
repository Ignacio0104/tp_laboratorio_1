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
#include <limits.h>
#define NOT_EMPTY 0
#define EMPTY 1

static int createNewId (void);
static int searchAvailable(Employee *list,int lenght);

/// \fn int createNewId(void)
/// \brief create a new id for each new employee.
///
/// \return the new ID
static int createNewId (void)
{
	static int id=1;
	return (id++);
}


static int searchAvailable(Employee *list,int lenght)
{
	int retorno;

	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			if(list[i].isEmpty==EMPTY)
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

int askInformation (Employee *list, int lenght, int *pId, char pName[], char pLastName[], float *pSalary, int * pSector)
{

	int retorno;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;
	int idAux;

	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		if(searchAvailable(list,lenght)!=-1&&searchAvailable(list,lenght)!=-2)
		{
			idAux=createNewId();
			if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre del empleado:  ", "Error, dato ingresado invalido")==0)
			{
				if(pedirTexto(lastNameAux,sizeof(lastNameAux), 3, "Ingrese el apellido del empleado: ", "Error, dato ingresado invalido")==0)
				{
					if(pedirFloatIntentosRango(&salaryAux, 0, INT_MAX, 3, "Ingrese el salario:  ", "Error, dato ingresado invalido")==0)
					{
						if(pedirIntIntentosRango(&sectorAux, 0, 10, 3, "Ingrese el numero del sector: ", "Error, dato ingresado invalido")==0)
						{
							*pId=idAux;
							strncpy(pName,nameAux,51);
							strncpy(pLastName,lastNameAux,51);
							*pSalary=salaryAux;
							*pSector=sectorAux;
							retorno=0;
							printf("\nDato ingresado correctamente!\n");
						}

					}
				}
			}

		} else
		{
			printf("\nNo hay lugares disponibles\n");
			retorno=-2;
		}

	}

	return retorno;

}

int modification (Employee *list)
{

	int retorno;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;
	int userChoice;

	retorno=-1;

	if(list!=NULL)
	{
		retorno=0;
		if(pedirIntIntentosRango(&userChoice, 1, 5, 5, " Ingrese el n�mero del campo que desea modificar:\n"
				"1) Nombre\n"
				"2) Apellido\n"
				"3) Salario\n"
				"4) Sector\n"
				"5) Volver al men� principal", "Error dato ingresado inv�lido")==0)
		{
			switch (userChoice)
			{
				case 1:
					if(pedirTexto(nameAux,sizeof(nameAux), 3, "Ingrese el nombre del empleado:  ", "Error, dato ingresado invalido")==0)
					{
						strncpy(list->name,nameAux,sizeof(list->name));
						printf("Dato modificado exitosamente\n");
					} else
					{
						printf("No se pudo modificar el campo solicitado\n");
					}

					pedirIntIntentosRango(&userChoice, 1, 5, 5, " Ingrese el n�mero del campo que desea modificar:\n"
									"1) Nombre\n"
									"2) Apellido\n"
									"3) Salario\n"
									"4) Sector\n"
									"5) Volver al men� principal", "Error dato ingresado inv�lido");
					break;

				case 2:
					if(pedirTexto(lastNameAux,sizeof(lastNameAux), 3, "Ingrese el apellido del empleado:  ", "Error, dato ingresado invalido")==0)
					{
						strncpy(list->lastName,lastNameAux,sizeof(list->lastName));
						printf("Dato modificado exitosamente\n");
					} else
					{
						printf("No se pudo modificar el campo solicitado\n");
					}
					pedirIntIntentosRango(&userChoice, 1, 5, 5, " Ingrese el n�mero del campo que desea modificar:\n"
								"1) Nombre\n"
								"2) Apellido\n"
								"3) Salario\n"
								"4) Sector\n"
								"5) Volver al men� principal", "Error dato ingresado inv�lido");
					break;
				case 3:
					if(pedirFloatIntentosRango(&salaryAux, 0, INT_MAX, 3, "Ingrese el salario:  ", "Error, dato ingresado invalido")==0)
					{
						list->salary=salaryAux;
						printf("Dato modificado exitosamente\n");
					}else
					{
						printf("No se pudo modificar el campo solicitado\n");
					}

					pedirIntIntentosRango(&userChoice, 1, 5, 5, " Ingrese el n�mero del campo que desea modificar:\n"
								"1) Nombre\n"
								"2) Apellido\n"
								"3) Salario\n"
								"4) Sector\n"
								"5) Volver al men� principal", "Error dato ingresado inv�lido");
					break;

				case 4:
					if(pedirIntIntentosRango(&sectorAux, 0, 10, 3, "Ingrese el numero del sector: ", "Error, dato ingresado invalido")==0)
					{
						list->sector=sectorAux;
						printf("Dato modificado exitosamente\n");
					}else
					{
						printf("No se pudo modificar el campo solicitado\n");
					}

					pedirIntIntentosRango(&userChoice, 1, 5, 5, " Ingrese el n�mero del campo que desea modificar:\n"
								"1) Nombre\n"
								"2) Apellido\n"
								"3) Salario\n"
								"4) Sector\n"
								"5) Volver al men� principal", "Error dato ingresado inv�lido");
					break;

				case 5:
				default:
					printf("Volviendo al menu principal...");
					break;

			}
		}
	}

	return retorno;

}

int addEmployees(Employee *list, int lenght, int id, char name[], char lastName[],float salary, int sector)
{
	int retorno;

	if(list!=NULL&&lenght>0)
	{
		int position;

		position=searchAvailable(list,lenght);
		if(position!=-1&&position!=-2)
		{
			list[position].id=id;
			strncpy(list[position].name,name,sizeof(list[position].name));
			strncpy(list[position].lastName,lastName,sizeof(list[position].lastName));
			list[position].salary=salary;
			list[position].sector=sector;
			list[position].isEmpty=NOT_EMPTY;
			retorno=0;
		}
	}

	return retorno;

}

int askForId (Employee *list, int lenght)
{
	int retorno;
	int requestedId;

	retorno=-1;
	if(list!=NULL&&lenght>0)
		{
			retorno=0;
			if(pedirIntIntentosRango(&requestedId, 0, INT_MAX, 3, "Ingrese el ID: ", "Error, dato ingresado invalido")==0)
			{
				retorno=requestedId;
			} else
			{
				retorno=-2;
			}
		}

	return retorno;
}

int findEmployeeById (Employee *list, int lenght, int id)
{
	int retorno;

	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		retorno=0;
		for(int i=0;i<lenght;i++)
		{
			retorno=-2;
			if(list[i].id==id&&list[i].isEmpty==NOT_EMPTY)
			{
				retorno=i;
				break;
			}
		}

		if(retorno==-2)
		{
			printf("\nLa ID ingresada no existe en el sistema\n");
		}

	}

	return retorno;

}

int removeEmployee (Employee *list, int lenght, int id)
{
	int retorno;
	char userChoice;

	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		retorno=-2;
		for(int i=0;i<lenght;i++)
		{

			if(list[i].id==id&&list[i].isEmpty==NOT_EMPTY)
			{

				printf("\nSe va a eliminar al siguiente empleado: \n"
						"ID: %02d. Nombre: %8s.   Apellido: %15s.   Salario: %10.2f.   Sector: %-2d.\n",
									list[i].id ,list[i].name,list[i].lastName,list[i].salary,list[i].sector);


				if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione s para confirmar o n para volver al menu principal\n",
						"Error, dato ingresado inv�lido\n")==0)
				{
					if(userChoice=='s')
					{
						list[i].isEmpty=EMPTY;
						printf("Empleado borrado exitosamente.\n");
						retorno=0;
					} else
					{
						if(userChoice=='n')
						{
							printf("No se borrar� al empleado. Volviendo al men� principal...\n");
							retorno=0;
						}
					}

				}
				break;
			}
		}

		if(retorno==-2)
		{
			printf("\nNo se pudo realizar la acci�n\n");
		}

	}

	return retorno;

}


int sortEmployees (Employee *list, int lenght, int order)
{
    int i;
    int retorno;
    Employee aux;
    int j;

    retorno=-1;

    if(list!=NULL&&lenght>0)
    {
    	retorno=0;

    	if(order==1)
    	{
    		for(i=0;i<lenght-1;i++)
			{
				for(j=i+1;j<lenght;j++)
				{
					if(strcmp(list[i].lastName,list[j].lastName)>0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					} else
					{
						if(strcmp(list[i].lastName,list[j].lastName)==0)
						{
							if(list[i].sector>list[j].sector)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}

    	}else
    	{
        	if(order==2)
            	{
            		for(i=0;i<lenght-1;i++)
        			{
        				for(j=i+1;j<lenght;j++)
        				{
        					if(strcmp(list[i].lastName,list[j].lastName)<0)
        					{
        						aux = list[i];
        						list[i] = list[j];
        						list[j] = aux;
        					} else
        					{
        						if(strcmp(list[i].lastName,list[j].lastName)==0)
        						{
        							if(list[i].sector<list[j].sector)
        							{
        								aux = list[i];
        								list[i] = list[j];
        								list[j] = aux;
        							}
        						}
        					}
        				}
        			}

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
				printf("ID: %02d. Nombre: %8s.   Apellido: %15s.   Salario: %10.2f.   Sector: %-2d.  Vacio: %d\n",
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
		printf("ID: %02d. Nombre: %8s. Apellido: %8s. Salario: %02.2f. Sector: %-2d.  Vacio: %d\n",
		list[position].id ,list[position].name,list[position].lastName,list[position].salary,list[position].sector, list[position].isEmpty);

	}

	return retorno;

}

int mainMenu (void)
{
	int retorno;

	retorno=-1;

	printf("Favor, elegir una de las siguientes opciones:\n"
			"1)ALTAS\n"
			"2)MODIFICAR\n"
			"3)BAJAS\n"
			"4)INFORMAR\n"
			"5)SALIR\n");

	pedirIntIntentosRango(&retorno, 1, 5, 5, "\nEscriba aqu� su elecci�n:  ", "Error, dato ingresado invalido");


	return retorno;

}



