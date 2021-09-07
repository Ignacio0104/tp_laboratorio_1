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
float pedirNumero (char mensaje[]);
char menuDeOperaciones (float operadorUno, float operadorDos);
float restar (float operadorUno, float operadorDos);
float sumar (float operadorUno, float operadorDos);
int dividir (float operadorUno, float operadorDos, float* pResultado);
float multiplicar (float operadorUno, float operadorDos);
float factorial(float operadorUno);

int main(void) {

	setbuf(stdout,NULL);

	float numeroUno;
	float numeroDos;
	char menu;
	float resultadoSuma;
	float resultadoResta;
	int retornoDivision;
	float resultadoDivision;
	float resultadoFactorizarUno;
	float resultadoFactorizarDos;

	numeroUno=pedirNumero("Ingrese el primer número: ");
	numeroDos=pedirNumero("Ingrese el segundo número: ");

	menu=menuDeOperaciones(numeroUno, numeroDos);

	printf("%c",menu);

	resultadoFactorizarUno=factorial(numeroUno);

	printf("%.2f",resultadoFactorizarUno);

	resultadoFactorizarDos=factorial(numeroDos);

	printf("%.2f",resultadoFactorizarDos);



	return EXIT_SUCCESS;
}


float pedirNumero (char mensaje[])
{
	float num;

	printf("%s",mensaje);
	scanf("%f",&num);

	return num;
}


char menuDeOperaciones (float operadorUno, float operadorDos)
{
	char eleccion;

	printf("a) Calcular la suma (%.2f + %.2f)\n",operadorUno,operadorDos);
	printf("b) Calcular la resta (%.2f - %.2f)\n",operadorUno,operadorDos);
	printf("c) Calcular la division (%.2f / %.2f)\n",operadorUno,operadorDos);
	printf("d) Calcular la multiplicación (%.2f * %.2f)\n",operadorUno,operadorDos);
	printf("e) Calcular el factorial (%.2f ! y %.2f !)\n",operadorUno,operadorDos);

	fflush(stdin);
	scanf("%c",&eleccion);

	return eleccion;
}

float sumar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno+operadorDos;

	return resultado;
}

float restar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno-operadorDos;

	return resultado;
}

int dividir (float operadorUno, float operadorDos, float* pResultado)
{
	int huboError;
	float resul;

	if(operadorDos==0)
	{
		huboError=1;
	} else
	{
		resul= operadorUno/operadorDos;
		*pResultado=resul;
		huboError=0;
	}

	return huboError;

}

float multiplicar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno*operadorDos;

	return resultado;
}

float factorial (float operadorUno)
{

	float factUno;
	int i;

	factUno=1;

	for(i=1;i<=operadorUno;i++)
	{
		factUno=factUno*i;
	}

	return factUno;

}



