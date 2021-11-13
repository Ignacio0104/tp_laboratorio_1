#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#define NOMBRE_LEN 128

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* pEmpleadoAux;
	char idAux[256];
	char nombreAux[NOMBRE_LEN];
	char horasAux[256];
	char sueldoAux[256];

	if(pFile!=NULL&&pArrayListEmployee!=NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux); // salteo la 1era
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux)==4)
			{
				pEmpleadoAux = employee_newParametros(idAux,nombreAux,horasAux,sueldoAux);
				if(pEmpleadoAux!=NULL)
				{
					ll_add(pArrayListEmployee,pEmpleadoAux);
					retorno=0;
				}
				else
				{
					employee_delete(pEmpleadoAux);
					retorno=-1;
					break;
				}
			}

		}while(feof(pFile)==0);
	}


    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;

	Employee*pEmpleadoAux;

	if(pFile!=NULL&&pArrayListEmployee!=NULL)

	{
		 do
		{
			 pEmpleadoAux = employee_new();
			 if(pEmpleadoAux!=NULL)
			 {
				 if(fread(pEmpleadoAux,sizeof(Employee),1,pFile)==1)
					{
						ll_add(pArrayListEmployee,pEmpleadoAux);
						retorno=0;
					} else
					{
						employee_delete(pEmpleadoAux);
						break;
					}
			 }

		}while( feof(pFile)==0 );

	}


    return retorno;;
}
