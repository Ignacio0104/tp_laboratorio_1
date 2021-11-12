#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "biblioteca_input.h"
#include "validaciones.h"

/****************************************************
   	 === Menu ===
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo dataDos.csv (modo binario). NUEVO ARCHIVO PARA BINARIOS
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo dataDos.bin(modo binario).NUEVO ARCHIVO PARA BINARIOS
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
    int eleccionUsuario = 0;
    char banderaCierre='n';
    char banderaInputTxt='n';
    char banderaOutputTxt='n';
    char banderaInputBin='n';
    char banderaOutputBin='n';
    char userConfirmation;
    LinkedList* listaEmpleados = ll_newLinkedList();


   eleccionUsuario=controller_MainMenu();

    while(banderaCierre!='s')
    {
        switch(eleccionUsuario)
        {
            case 1:

            	if(banderaInputBin=='n')
            	{
					if(controller_loadFromText("data.csv",listaEmpleados)==0)
					  {
						printf("Carga realizada con éxito");
						banderaInputTxt='s';
					  } else
					  {
						  printf("Error, no se pudo realizar la carga");
					  }

            	} else
            	{
            		printf("Ya hay un archivo binario cargado, no se puede cargar otro archivo");
            	}

                eleccionUsuario=controller_MainMenu();
                break;
            case 2:

            	if(banderaInputTxt=='n')
            	{
					if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
					  {
						printf("Carga realizada con éxito");
						banderaInputBin='s';
					  } else
					  {
						  printf("Error, no se encontró el archivo binario");
					  }

            	} else
            	{
            		printf("Ya hay un archivo de texto cargado, no se puede cargar otro archivo");
            	}

            	eleccionUsuario=controller_MainMenu();
                break;
            case 3:
            	if(banderaInputBin=='n'&&banderaInputTxt=='n')
            	{
            		pedirCharSiNo(&userConfirmation, 's', 'n', 5, "Va a realizar un alta de empleado sin haber cargado ningún archivo.\n"
            				"Esto puede generar conflicto de datos al momento de guardar. Desea continuar? [s] si o [n] no\n",
            		    									"Error, dato ingresado inválido\n");

            		if(userConfirmation=='s')
            		{
            			controller_addEmployee(listaEmpleados);
            		}
            	} else
            	{
            		controller_addEmployee(listaEmpleados);
            	}
            	eleccionUsuario=controller_MainMenu();
                break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 8:
            	if(banderaInputBin=='n'&&banderaInputTxt=='n')
				{
            		printf("Estás a punto de sobreescribir todos los datos del archivo original con la nueva carga\n");
					pedirCharSiNo(&userConfirmation, 's', 'n', 5, "Desea continuar? [s] si o [n] no\n",
																"Error, dato ingresado inválido\n");
					if(userConfirmation=='s')
					{
						if(banderaInputBin=='n')
						{
							if(controller_saveAsText("data.csv", listaEmpleados)==0)
							{
								printf("Archivo guardado con exito");
								banderaOutputTxt='s';
							} else
							{
								printf("No pudo guardarse el archivo");
							}

						} else
						{
							printf("El archivo de origen es binario, si continúa los nuevos datos se guardarán en un archivo de texto y el archivo original quedará desactualizado\n");
							pedirCharSiNo(&userConfirmation, 's', 'n', 5, "Desea continuar? [s] si o [n] no\n",
																		"Error, dato ingresado inválido\n");

							if(userConfirmation=='s')
							{
								if(controller_saveAsText("data.csv", listaEmpleados)==0)
								{
									printf("Archivo guardado con exito");
									banderaOutputTxt='s';
								} else
								{
									printf("No pudo guardarse el archivo");
								}
							}
						}
					}

				}else
				{
					if(banderaInputBin=='n')
					{
						if(controller_saveAsText("data.csv", listaEmpleados)==0)
						{
							printf("Archivo guardado con exito");
							banderaOutputTxt='s';
						} else
						{
							printf("No pudo guardarse el archivo");
						}

					} else
					{
						printf("El archivo de origen es binario, si continúa los nuevos datos se guardarán en un archivo de texto y el archivo original quedará desactualizado\n");
						pedirCharSiNo(&userConfirmation, 's', 'n', 5, "Desea continuar? [s] si o [n] no\n",
																	"Error, dato ingresado inválido\n");

						if(userConfirmation=='s')
						{
							if(controller_saveAsText("data.csv", listaEmpleados)==0)
							{
								printf("Archivo guardado con exito");
								banderaOutputTxt='s';
							} else
							{
								printf("No pudo guardarse el archivo");
							}
						}
					}
				}
            	eleccionUsuario=controller_MainMenu();
                break;
            case 9:

            	if(banderaInputBin=='n'&&banderaInputTxt=='n')
				{
					printf("Estás a punto de sobreescribir todos los datos del archivo original con la nueva carga\n");
					pedirCharSiNo(&userConfirmation, 's', 'n', 5, "Desea continuar? [s] si o [n] no\n",
																"Error, dato ingresado inválido\n");
					if(userConfirmation=='s')
					{
						if(banderaInputTxt=='n')
						{
							if(controller_saveAsBinary("data.bin", listaEmpleados)==0)
							{
								printf("Archivo guardado con exito");
								banderaOutputBin='s';
							} else
							{
								printf("No pudo guardarse el archivo");
							}

						} else
						{
							printf("El archivo de origen es de texto, si continúa los nuevos datos se guardarán en un archivo binario y el archivo original quedará desactualizado\n");
							pedirCharSiNo(&userConfirmation, 's', 'n', 5, "Desea continuar? [s] si o [n] no\n",
																		"Error, dato ingresado inválido\n");

							if(userConfirmation=='s')
							{
								if(controller_saveAsBinary("data.bin", listaEmpleados)==0)
								{
									printf("Archivo guardado con exito");
									banderaOutputBin='s';
								} else
								{
									printf("No pudo guardarse el archivo");
								}

							}
						}
					}
					}else
					{
						if(banderaInputTxt=='n')
						{
							if(controller_saveAsBinary("data.bin", listaEmpleados)==0)
							{
								printf("Archivo guardado con exito");
								banderaOutputBin='s';
							} else
							{
								printf("No pudo guardarse el archivo");
							}

						} else
						{
							printf("El archivo de origen es de texto, si continúa los nuevos datos se guardarán en un archivo binario y el archivo original quedará desactualizado\n");
							pedirCharSiNo(&userConfirmation, 's', 'n', 5, "Desea continuar? [s] si o [n] no\n",
																		"Error, dato ingresado inválido\n");

							if(userConfirmation=='s')
							{
								if(controller_saveAsBinary("data.bin", listaEmpleados)==0)
								{
									printf("Archivo guardado con exito");
									banderaOutputBin='s';
								} else
								{
									printf("No pudo guardarse el archivo");
								}

							}
						}
					}


            	eleccionUsuario=controller_MainMenu();
                break;
            case 10:
            	if(banderaOutputTxt=='n'&&banderaOutputBin=='n')
            	{
            		pedirCharSiNo(&userConfirmation, 's', 'n', 5, "Está a punto de salir del programa sin guardar los cambios.\n"
            				"Desea continuar? [s] si o [n] no\n",
            		    									"Error, dato ingresado inválido\n");
            		if(userConfirmation=='s')
            		{
            			printf("Borrando los datos temporarios y saliendo del sistema\n");
            			ll_deleteLinkedList(listaEmpleados);
            			banderaCierre='s';
            		} else
            		{
            			printf("Volviendo al menú principal...\n");
            			eleccionUsuario=controller_MainMenu();
            		}
            	}
            	else
            	{
            		printf("Saliendo del sistema....\n");
            		ll_deleteLinkedList(listaEmpleados);
					banderaCierre='s';
            	}

                break;
        }
    }
    return 0;
}

