/*
 * utn_biblioteca.c
 *
 *  Created on: 9 sept 2021
 *      Author: Nacho
 */

#include "utn_biblioteca.h"
#include <stdio.h>
#include <stdlib.h>


int utn_pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			salidaScanf=scanf("%f", &buffer);

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}

float utn_pedirFloatSinIntentos(char* variableTexto, char* textoError)
{
	float numero;
	int salidaScanf;
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

	}
	return numero;
}



int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			salidaScanf=scanf("%d", &buffer);

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}


int utn_pedirCharAUsuario(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError)
{
	char buffer;
	int retorno=-1;
	int i;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			fflush(stdin);
			scanf("%c", &buffer);

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-1;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}



float utn_dividir (int operador1,int operador2,float*direccionVariable)
{
	float resul;
	int huboError;

	if(operador2!=0)
	{
		resul=(float)operador1/operador2;
		*direccionVariable=resul; //Escribime en la memoria esto
		huboError=0;
	} else
	{
		huboError=1;
	}

	return huboError;
}


float utn_pedirNumero (char mensaje[],char* textoError)
{
	float num;
	int salidaScanf;
	int retorno;

	retorno=-1;

	if( mensaje != NULL && textoError != NULL)
	{
		while(retorno==-1)
		{
			printf("%s",mensaje);
			salidaScanf=scanf("%f",&num);

			if(salidaScanf>0)
			{
				retorno=0;
			} else
			{
				printf("%s\n",textoError);
			}

		}
	}

	return num;

}


float utn_sumar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno+operadorDos;

	return resultado;
}

float utn_restar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno-operadorDos;

	return resultado;
}

/*int utn_dividir (float operadorUno, float operadorDos, float* pResultado)
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

}*/

float utn_multiplicar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno*operadorDos;

	return resultado;
}

float utn_factorial (float operadorUno)
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

int utn_menuInicial (void)
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

int utn_menuDeOperaciones (float operadorUno, float operadorDos)
{
	int eleccionUsuario;

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



