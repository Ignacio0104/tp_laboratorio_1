/*
 ============================================================================
 Name        : Tp_1.c
 Author      : Ignacio Martín Smirlian

 Consigna:

 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:

1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones

a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "calculadora_biblioteca.h"


int main(void) {

	setbuf(stdout,NULL);

	//variable de Cierre
	char variableDeCierre = 'n';
	//Operandos
	float numeroUno;
	float numeroDos;
	//Retorno Menu
	int eleccionMenu;
	//Resultados operaciones
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	int resultadoFactorialUno;
	int resultadoFactorialDos;
	float resultadoMultiplicacion;
	//Retorno operaciones
	int retornoDivision;
	int retornoFactorialUno;
	int retornoFactorialDos;
	//Banderas
	char banderaPrimerNumero;
	char banderaSegundoNumero;
	char banderaCalculo;
	//Confirmacion usuario char
	char confirmacionUsuario;

	banderaPrimerNumero='n';
	banderaSegundoNumero='n';
	banderaCalculo='n';

	eleccionMenu=calculadora_menuInicial();

	while (variableDeCierre=='n')
	{

		switch (eleccionMenu)
		{
			case 1:

				if(banderaPrimerNumero=='s')
				{
					fflush(stdin);
					calculadora_pedirChar("El operador 1 ya fue ingresado, desea reemplazarlo? s (si) o n (no)", "Error, opción inválida",&confirmacionUsuario, 's', 'n');

					if(confirmacionUsuario=='s')
					{

						calculadora_pedirFloat("Ingrese el primer número", "Error. Dato ingresado inválido", &numeroUno);
						eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);
						banderaCalculo='n';

					} else
					{
						printf("Volviendo al menú principal...\n\n");
						eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);
					}

				} else
				{
					calculadora_pedirFloat("Ingrese el primer número", "Error. Dato ingresado inválido", &numeroUno);
					banderaPrimerNumero='s';
					eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);
				}

				break;

			case 2:

				if(banderaSegundoNumero=='s')
					{
						fflush(stdin);
						calculadora_pedirChar("El operador 2 ya fue ingresado, desea reemplazarlo? s (si) o n (no)", "Error, opción inválida",&confirmacionUsuario, 's', 'n');

						if(confirmacionUsuario=='s')
						{

							calculadora_pedirFloat("Ingrese el segundo número", "Error. Dato ingresado inválido", &numeroDos);
							eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);
							banderaCalculo='n';
						} else
						{
							printf("Volviendo al menú principal...");
							eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);
						}

					} else
					{
						calculadora_pedirFloat("Ingrese el segundo número", "Error. Dato ingresado inválido", &numeroDos);
						banderaSegundoNumero='s';
						eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);
					}

				break;

			case 3:

				if (banderaPrimerNumero=='n'||banderaSegundoNumero=='n')
				{
					printf("\nERROR!! Falta cargar un operador o ambos operadores\n\n\n");
					eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);

				} else
				{
					resultadoSuma=calculadora_sumar(numeroUno, numeroDos);
					resultadoResta=calculadora_restar(numeroUno, numeroDos);
					retornoDivision=calculadora_dividir(numeroUno, numeroDos,&resultadoDivision);
					resultadoMultiplicacion=calculadora_multiplicar(numeroUno, numeroDos);
					retornoFactorialUno=calculadora_factorial(numeroUno,&resultadoFactorialUno);
					retornoFactorialDos=calculadora_factorial(numeroDos,&resultadoFactorialDos);

					printf("\n >>>> Operaciones calculadas <<<< \n\n");


					eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);
					banderaCalculo='s';

				}

				break;

			case 4:

				if(banderaCalculo=='n')
				{
					printf("\nERROR!! Las operaciones aún no fueron calculadas\n\n\n");
					eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);
				} else
				{
					mostrarResultado (numeroUno,numeroDos,resultadoSuma,0, "Error", "la suma");
					mostrarResultado (numeroUno,numeroDos,resultadoResta,0, "Error", "la resta");
					mostrarResultado (numeroUno,numeroDos,resultadoDivision,retornoDivision, "No se puede dividir por cero", "la división");
					mostrarResultado (numeroUno,numeroDos,resultadoMultiplicacion,0, "Error", "la multiplicacion");
					mostrarResultadoFact (numeroUno,resultadoFactorialUno,retornoFactorialUno, "No se puede sacar el factorial de cero, de un número negativo o de un número mayor a 12");
					mostrarResultadoFact (numeroDos,resultadoFactorialDos,retornoFactorialDos, "No se puede sacar el factorial de cero, de un número negativo o de un número mayor a 12");

					calculadora_pedirChar("Desea volver al menú principal? s (si) o n (no)", "Error, opción inválida",&confirmacionUsuario, 's', 'n');

					banderaPrimerNumero='n';
					banderaSegundoNumero='n';
					banderaCalculo='n';

					if(confirmacionUsuario=='s')
					{
						eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);
					} else
					{
						printf("Saliendo de la calculadora...\n\n");
						variableDeCierre='s';
					}
				}
				break;

			case 5:
				printf("Saliendo de la calculadora...\n\n");
				variableDeCierre='s';
				break;

			default:
				printf("\nERROR!! Opción ingresada inválida\n\n\n");
				eleccionMenu=calculadora_menuDeOperaciones(numeroUno, numeroDos,banderaPrimerNumero,banderaSegundoNumero);
				break;

		}

	}


	return EXIT_SUCCESS;
}


