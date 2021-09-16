/*
 * utn_biblioteca.c
 *
 *  Created on: 9 sept 2021
 *      Author: Nacho
 */

#include "calculadora_biblioteca.h"

#include <stdio.h>
#include <stdlib.h>


int calculadora_pedirFloat(char* variableTexto, char* textoError, float* pVariableNumero)
{
	float numero;
	int salidaScanf;
	int retorno;
	retorno=-1;
	if(variableTexto != NULL && textoError != NULL)
	{
		printf("%s",variableTexto);
		salidaScanf=scanf("%f", &numero);

		while(salidaScanf!=1)
			{
				printf("%s\n",textoError);
				printf("%s",variableTexto);
				fflush(stdin);
				salidaScanf=scanf("%f", &numero);
			}

		*pVariableNumero=numero;

		retorno=0;

	}

	return retorno;
}




int calculadora_pedirIntAUsuario(int* pVariableNumero, int min, int max, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	int salidaScanf;
	if(pVariableNumero != NULL && min<max && variableTexto != NULL && textoError != NULL)
	{
		while (retorno==-1)
		{
			printf("%s",variableTexto);
			salidaScanf=scanf("%d", &buffer);

			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pVariableNumero=buffer;
				break;
			}
			else
			{
				printf("%s\n",textoError);
				salidaScanf=scanf("%d", &buffer);
			}
		}
	}
	return retorno;
}




float calculadora_dividir (int operador1,int operador2,float*direccionVariable)
{
	float resul;
	int huboError;

	huboError=-1;

	if(direccionVariable != NULL)
	{
		if(operador2!=0)
			{
				resul=(float)operador1/operador2;
				*direccionVariable=resul;
				huboError=0;
			}
	}

	return huboError;
}




int calculadora_pedirChar (char mensaje[],char* textoError,char*pRespuesta, char opcionUno, char opcionDos)
{

	char respuesta;
	int salidaScanf;
	int huboError;

	huboError=-1;

	if(mensaje != NULL && textoError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		salidaScanf=scanf("%c", &respuesta);

		while(salidaScanf!=1)
		{
			while(salidaScanf!=opcionUno&&salidaScanf!=opcionDos)

				{

					printf("%s\n",textoError);
					printf("%s",mensaje);
					fflush(stdin);
					salidaScanf=scanf("%c", &respuesta);
				}
			}

		*pRespuesta=respuesta;
		huboError=0;

	}
	return huboError;
}



float calculadora_sumar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno+operadorDos;

	return resultado;
}

float calculadora_restar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno-operadorDos;

	return resultado;
}

float calculadora_multiplicar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno*operadorDos;

	return resultado;
}

int calculadora_factorial (float operadorUno, int*pResultado)
{

	int huboError;
	int factUno;
	int i;

	huboError=-1;

	factUno=1;
	if(pResultado!= NULL&&operadorUno>0)
	{
		for(i=1;i<=(int)operadorUno;i++)
		{
			factUno=factUno*i;
			huboError=0;
		}

	}

	*pResultado=factUno;
	return huboError;

}

int calculadora_menuInicial (void)
{
	int eleccionUsuario;

	printf("1. Ingresar el 1er operando (A=x)\n");
	printf("2. Ingresar el 2do operando (B=y)\n");
	printf("3. Calcular todas las operaciones: \n");
	printf("   a) Calcular la suma (A+B)\n");
	printf("   b) Calcular la resta (A-B)\n");
	printf("   c) Calcular la division (A/B)\n");
	printf("   d) Calcular la multiplicacion (A*B)\n");
	printf("   e) Calcular el factorial (A! y B!)\n");
	printf("4. Informar resultados: \n");
	printf("5. Salir");


	scanf("%d",&eleccionUsuario);
	return eleccionUsuario;


}

int calculadora_menuDeOperaciones (float operadorUno, float operadorDos, char banderaUno, char banderaDos)
{
	int eleccionUsuario;

	if(banderaUno=='n')
	{
		operadorUno=0;
	}

	if(banderaDos=='n')
	{
		operadorDos=0;
	}

	printf("1. Operando 1 (A=%.2f)\n",operadorUno);
	printf("2. Operando 2 (B=%.2f)\n",operadorDos);
	printf("3. Calcular todas las operaciones: \n");
	printf("   a) Calcular la suma (%.2f+%.2f)\n",operadorUno, operadorDos);
	printf("   b) Calcular la resta (%.2f-%.2f)\n",operadorUno, operadorDos);
	printf("   c) Calcular la division (%.2f/%.2f)\n",operadorUno, operadorDos);
	printf("   d) Calcular la multiplicacion (%.2f*%.2f)\n",operadorUno, operadorDos);
	printf("   e) Calcular el factorial (%.0f! y %.0f!)\n",operadorUno, operadorDos);
	printf("4. Informar resultados: \n");
	printf("5. Salir");

	fflush(stdin);
	scanf("%d",&eleccionUsuario);

	return eleccionUsuario;
}



