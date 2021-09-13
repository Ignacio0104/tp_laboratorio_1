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
#include "utn_biblioteca.h"


int main(void) {

	setbuf(stdout,NULL);

	char variableDeCierre = 'n';
	float numeroUno;
	int retornoPedirNumero;
	float numeroDos;
	int eleccionMenu;
	char menu;
	float resultadoSuma;
	float resultadoResta;
	int retornoDivision;
	float resultadoDivision;
	float resultadoFactorizarUno;
	float resultadoFactorizarDos;
	float resultadoMultiplicacion;

	eleccionMenu=utn_menuInicial();

	while (variableDeCierre=='n')
	{

		switch (eleccionMenu)
		{
			case 1:

				numeroUno=utn_pedirFloatSinIntentos("Ingrese el primer número", "Error. Dato ingresado inválido");
				eleccionMenu=utn_menuDeOperaciones(numeroUno, numeroDos);
				break;

			case 2:
				numeroDos=utn_pedirFloatSinIntentos("Ingrese el segundo número", "Error. Dato ingresado inválido");
				eleccionMenu=utn_menuDeOperaciones(numeroUno, numeroDos);
				break;

			case 3:

				if (numeroUno==-5000&&numeroDos==-5000)
				{
					printf("Error, falta cargar un operador");
					eleccionMenu=utn_menuDeOperaciones(numeroUno, numeroDos);

				} else
				{
					resultadoSuma=utn_sumar(numeroUno, numeroDos);
					resultadoResta=utn_restar(numeroUno, numeroDos);
					retornoDivision=utn_dividir(numeroUno, numeroDos,&resultadoDivision);
					resultadoMultiplicacion=utn_multiplicar(numeroUno, numeroDos);
					resultadoFactorizarUno=utn_factorial(numeroUno);
					resultadoFactorizarDos=utn_factorial(numeroDos);
					eleccionMenu=utn_menuDeOperaciones(numeroUno, numeroDos);
				}

				break;

			case 4:
				printf("El resultado de %.2f + %.2f es: %.2f\n",numeroUno,numeroDos,resultadoSuma);
				printf("El resultado de %.2f - %.2f es: %.2f\n",numeroUno,numeroDos,resultadoResta);

				if (retornoDivision==1)
				{
					printf("No se puede dividir por cero\n");
				} else
				{
					printf("El resultado de %.2f / %.2f es: %.2f\n",numeroUno,numeroDos,resultadoDivision);
				}

				printf("El resultado de %.2f * %.2f es: %.2f\n",numeroUno,numeroDos,resultadoMultiplicacion);
				eleccionMenu=utn_menuDeOperaciones(numeroUno, numeroDos);
				break;

			case 5:
				variableDeCierre='s';
				break;

		}

	}



	return EXIT_SUCCESS;
}


