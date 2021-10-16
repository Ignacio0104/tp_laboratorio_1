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

/// \fn int createNewId(void)
/// \brief Create a new unique ID each time is called
/// \return Return the created ID
static int createNewId (void);



/// \fn int searchAvailable(Employee*, int)
/// \brief Search the array for an empty slot (isEmpty flag == EMPTY)
/// \param list Employee* pointer to array of employees
/// \param lenght Array lenght
/// \return -1 if there was an error [Invalid length or NULL pointer], -2 if there's no empty slot, empty position if OK.
static int searchAvailable(Employee *list,int lenght);


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
		if(pedirIntIntentosRango(&userChoice, 1, 5, 5, "Ingrese el número del campo que desea modificar:\n"
				"		1) Nombre\n"
				"		2) Apellido\n"
				"		3) Salario\n"
				"		4) Sector\n"
				"		5) Volver al menú principal", "Error dato ingresado inválido")==0)
		{
			while(userChoice!=5)
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

						pedirIntIntentosRango(&userChoice, 1, 5, 5, "Ingrese el número del campo que desea modificar:\n"
										"		1) Nombre\n"
										"		2) Apellido\n"
										"		3) Salario\n"
										"		4) Sector\n"
										"		5) Volver al menú principal", "Error dato ingresado inválido");
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
						pedirIntIntentosRango(&userChoice, 1, 5, 5, "Ingrese el número del campo que desea modificar:\n"
									"		1) Nombre\n"
									"		2) Apellido\n"
									"		3) Salario\n"
									"		4) Sector\n"
									"		5) Volver al menú principal", "Error dato ingresado inválido");
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

						pedirIntIntentosRango(&userChoice, 1, 5, 5, " Ingrese el número del campo que desea modificar:\n"
									"		1) Nombre\n"
									"		2) Apellido\n"
									"		3) Salario\n"
									"		4) Sector\n"
									"		5) Volver al menú principal", "Error dato ingresado inválido");
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

						pedirIntIntentosRango(&userChoice, 1, 5, 5, "Ingrese el número del campo que desea modificar:\n"
									"		1) Nombre\n"
									"		2) Apellido\n"
									"		3) Salario\n"
									"		4) Sector\n"
									"		5) Volver al menú principal", "Error dato ingresado inválido");
						break;

					case 5:
					default:
						printf("Volviendo al menu principal...\n");
						break;

				}
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
			printf("\nDato ingresado correctamente!\n");
		} else
		{
			printf("No quedan lugares libres\n");
		}
	}

	return retorno;

}

int askForId (void)
{
	int retorno;
	int requestedId;

	retorno=0;
	if(pedirIntIntentosRango(&requestedId, 0, INT_MAX, 3, "Ingrese el ID: ", "Error, dato ingresado invalido")==0)
	{
		retorno=requestedId;
	} else
	{
		retorno=-2;
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
			printf("Error, ID no existe en el sistema\n\n");
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
		for(int i=0;i<lenght;i++)
		{

			if(list[i].id==id&&list[i].isEmpty==NOT_EMPTY)
			{

				printf("\nSe va a eliminar al siguiente empleado: \n\n"
						"ID: %02d. Nombre: %15s.   Apellido: %15s.   Salario: %18.2f.   Sector: %-2d.\n\n",
									list[i].id ,list[i].name,list[i].lastName,list[i].salary,list[i].sector);


				if(pedirCharSiNo(&userChoice, 's', 'n', 5, "Presione [s] para confirmar o [n] para volver al menu principal\n",
						"Error, dato ingresado inválido\n")==0)
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
							printf("No se borrará al empleado. Volviendo al menú principal...\n");
							retorno=0;
						}
					}

				}
				break;
			}
		}

		if(retorno==-1)
		{
			printf("\nNo se pudo procesar la acción \n");
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

int printEmployees(Employee *list,int lenght, int totalEmpty, int totalNotEmpty)
{
	int retorno;
	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		retorno=0;

		printf("ID  \t       Nombre        \t       Apellido        \t       Salario        \t Sector \t\n\n");
		for(int i=0;i<lenght;i++)
		{
			if(list[i].isEmpty==NOT_EMPTY)

			{
				printf("%2d  \t %15s  \t  %15s \t   %15.2f \t   %2d \t \n",
									list[i].id ,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}

		}

		printf("\n\nLugares disponibles: %d. Lugares ocupados %d\n\n",totalEmpty,totalNotEmpty);

	}

	return retorno;

}

int printEmployeesBySalary(Employee *list,int lenght,float salaryVar)
{
	int retorno;
	retorno=-1;

	if(list!=NULL&&lenght>0)
	{
		retorno=0;
		printf("Los empleados que se encuentran por encima del salario promedio son: \n\n");

		printf("ID  \t       Nombre        \t       Apellido        \t       Salario        \t Sector \t\n\n");

		for(int i=0;i<lenght;i++)
		{

			if(list[i].salary>salaryVar&&list[i].isEmpty==NOT_EMPTY)

			{
				printf("%2d  \t %15s  \t  %15s \t   %15.2f \t   %2d \t \n\n",
									list[i].id ,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}

		}

	}

	return retorno;

}

int mainMenu (void)
{
	int retorno;

	retorno=-1;

	printf("Favor, elegir una de las siguientes opciones:\n\n"
			"1)ALTAS\n"
			"2)MODIFICAR\n"
			"3)BAJAS\n"
			"4)INFORMAR\n"
			"5)SALIR\n");

	pedirIntIntentosRango(&retorno, 1, 5, 5, "\nEscriba aquí su elección:  ", "Error, dato ingresado invalido");


	return retorno;

}

int averageSalaryFunction (Employee *list,int lenght, float* pPromedio,float* pTotal)
{
	int retorno;
	float acumuladorSalarios;
	int contadorSalarios;
	int i;
	float promedio;

	acumuladorSalarios=0;
	contadorSalarios=0;


	retorno=-1;
	if(list!=NULL&&lenght>0)
	{
		retorno=0;

		for (i=0;i<lenght;i++)
		{
			if(list[i].isEmpty==NOT_EMPTY)
			{
				acumuladorSalarios+=list[i].salary;
				contadorSalarios++;
			}

		}

		if(acumuladorSalarios>0&&contadorSalarios>0)
		{
			promedio=acumuladorSalarios/contadorSalarios;
		} else
		{
			retorno=-2;
		}

		*pPromedio=promedio;
		*pTotal=acumuladorSalarios;
	}

	return retorno;
}

int submenuReports (void)
{
	char retorno;

	retorno='x';

	printf("\na)Listado orden alfabético descendiente\n"
			"b)Listado orden alfabético ascendiente\n"
			"c)Total y promedio de salarios\n"
			"d)Listo de empleados por encima del salario promedio\n"
			"e)Salir\n");

	pedirCharAUsuarioIntentosRango(&retorno, 'a', 'e', 5, "Ingrese aquí su elección: ", "Error, dato ingresado inválido");

	return retorno;
}

int printReports (Employee *list,int lenght,char userChoice, float totalSalary, float averageSalary, int totalEmpty, int totalNotEmpty)
{
	int retorno;

	retorno=-1;

	if(list!=NULL&&lenght>0)
		{
			retorno=0;
			switch (userChoice)
				{
					case 'a':
						sortEmployees (list,lenght,2);
						printEmployees(list,lenght,totalEmpty,totalNotEmpty);
						break;
					case 'b':
						sortEmployees (list,lenght,1);
						printEmployees(list,lenght,totalEmpty,totalNotEmpty);
						break;
					case 'c':
						printf("\nEl total de la suma de todos los salarios es: $%.2f\n",totalSalary);
						printf("\nEl promedio de todos los salarios es: $ %.2f\n\n",averageSalary);
						break;
					case 'd':
						printEmployeesBySalary(list,lenght,averageSalary);
						break;
					case 'e':
					default:
						printf("Volviendo al menú principal...");
				}


		}


	return retorno;
}

int occupancy (Employee *list,int lenght, int* pEmpty, int* pNotEmpty)
{
	int retorno;
	int empty;
	int notEmpty;
	int i;

	retorno=-1;
	empty=0;
	notEmpty=0;

	if(list!=NULL&&lenght>0)
		{
			retorno=0;

			for (i=0;i<lenght;i++)
			{
				if(list[i].isEmpty==NOT_EMPTY)
				{
					notEmpty++;
				} else
				{
					empty++;
				}

			}
		}

	*pEmpty=empty;
	*pNotEmpty=notEmpty;

	return retorno;
}



