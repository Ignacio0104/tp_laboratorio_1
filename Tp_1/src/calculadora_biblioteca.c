/*
 * utn_biblioteca.c
 *
 *  Created on: 9 sept 2021
 *      Author: Nacho
 */

#include "calculadora_biblioteca.h"

#include <stdio.h>
#include <stdlib.h>


/// \fn int calculadora_pedirFloat(char*, char*, float*)
/// \brief La función pide un numero float al usuario y valida que sea del tipo correcto
///
/// \param variableTexto >>> Aquí se ingresa el mensaje para el usuario ("Ingrese un numero")
/// \param textoError >>> Aquí se ingresa el mensaje de error en caso de que el usuario se equivoque
/// \param pVariableNumero >>> Aquí se indica la dirección de la variable donde se guardará el número
/// \return retorno >>> El retorno indica si la función pudo ejecutarse, es decir, si la dirección de memoria y los mensajes son distintos de NULL o no

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

/// \fn int calculadora_pedirIntAUsuario(int*, int, int, char*, char*)
/// \brief La función pide un numero int al usuario y valida que sea del tipo correcto
///
/// \param pVariableNumero >>> Aquí se indica la dirección de la variable donde se guardará el número
/// \param min >>> Se ingresa el valor mínimo que puede ingresar el usuario y lo valida
/// \param max >>> Se ingresa el valor máximo que puede ingresar el usuario y lo valida
/// \param variableTexto >>> Aquí se ingresa el mensaje para el usuario ("Ingrese un numero")
/// \param textoError >>> Aquí se ingresa el mensaje de error en caso de que el usuario se equivoque
/// \return retorno >>> El retorno indica si la función pudo ejecutarse, es decir, si la dirección de memoria y los mensajes son distintos de NULL o no y si
/// 					el mínimo es menor que el máximo


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

/// \fn float calculadora_dividir(int, int, float*)
/// \brief La función verifica que el divisor sea distinto de 0 y luego realiza la división
///
/// \param operador1 >>> Se pasa la variable donde se guardó el primer número que ingresó el usuario.
/// \param operador2 >>> Se pasa la variable donde se guardó el segundo número que ingresó el usuario.
/// \param direccionVariable >>> Se pasa la dirección de la variable donde se va a guardar el resultado.
/// \return huboError >>> Identifica si la división pudo realizarse (0) o no (-1)

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

/// \fn int calculadora_pedirChar(char[], char*, char*, char, char)
/// \brief La función pide un caracter al usuario, valida que este sea correcto y luego lo guarda en la direccióm de memoria que le indicamos
///
/// \param mensaje >>> Aquí se ingresa el mensaje para el usuario ("Ingrese un caracter")
/// \param textoError >>> Aquí se ingresa el mensaje de error en caso de que el usuario se equivoque
/// \param pRespuesta >>> Se pasa la dirección de la variable donde se va a guardar la respuesta del usuario (en caso de ser correcta)
/// \param opcionUno >>> Se pasa una de las opciones a validar.
/// \param opcionDos >>> Se pasa la otra de las opciones a validar. Si la respuesta es distinta a alguna de estas 2, va a mostrar el mensaje de error.
/// \return huboError >>> El retorno indica si la función pudo ejecutarse, es decir, si la dirección de memoria y los mensajes son distintos de NULL o no


int calculadora_pedirChar (char mensaje[],char* textoError,char*pRespuesta, char opcionUno, char opcionDos)
{

	char respuesta;
	int huboError;

	huboError=-1;

	if(mensaje != NULL && textoError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c", &respuesta);


		while(respuesta!=opcionUno&&respuesta!=opcionDos)

				{
					printf("%s\n",textoError);
					printf("%s",mensaje);
					fflush(stdin);
					scanf("%c", &respuesta);
				}

		*pRespuesta=respuesta;
		huboError=0;

	}
	return huboError;
}


/// \fn float calculadora_sumar(float, float)
/// \brief La función recibe 2 números y realiza la suma. No es necesario validarlo ya que fue validado al momento de pedir el dato.
///
/// \param operadorUno >>> Se pasa la variable donde se guardó el primer número que ingresó el usuario.
/// \param operadorDos >>> Se pasa la variable donde se guardó el segundo número que ingresó el usuario.
/// \return resultado >>> Esta función retorna el resultado ya que no hay ninguna validación dentro.


float calculadora_sumar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno+operadorDos;

	return resultado;
}

/// \fn float calculadora_restar(float, float)
/// \brief La función recibe 2 números y realiza la resta. No es necesario validarlo ya que fue validado al momento de pedir el dato.
///
/// \param operadorUno >>> Se pasa la variable donde se guardó el primer número que ingresó el usuario.
/// \param operadorDos >>> Se pasa la variable donde se guardó el segundo número que ingresó el usuario.
/// \return resultado >>> Esta función retorna el resultado ya que no hay ninguna validación dentro.

float calculadora_restar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno-operadorDos;

	return resultado;
}

/// \fn float calculadora_multiplicar(float, float)
/// \brief La función recibe 2 números y realiza la multiplicación. No es necesario validarlo ya que fue validado al momento de pedir el dato.
///
/// \param operadorUno >>> Se pasa la variable donde se guardó el primer número que ingresó el usuario.
/// \param operadorDos >>> Se pasa la variable donde se guardó el segundo número que ingresó el usuario.
/// \return resultado >>> Esta función retorna el resultado ya que no hay ninguna validación dentro.


float calculadora_multiplicar (float operadorUno, float operadorDos)
{
	float resultado;

	resultado=operadorUno*operadorDos;

	return resultado;
}

/// \fn int calculadora_factorial(float, int*)
/// \brief La función recibe un número y calcula su factorial
///
/// \param operadorUno >>> Se pasa la variable donde se guardó el primer número que ingresó el usuario.
/// \param pResultado >>> Se pasa la dirección de la variable donde se va a guardar el resultado.
/// \return huboError >>> El retorno indica si la función pudo ejecutarse, es decir, si la dirección de memoria es distinta de NULL y si el numero es mayor a 0

int calculadora_factorial (float operadorUno, int*pResultado)
{

	int huboError;
	int factUno;
	int i;

	huboError=-1;

	factUno=1;
	if(pResultado!= NULL&&operadorUno>0)
	{
		if(operadorUno<13)
		{
			for(i=1;i<=(int)operadorUno;i++)
			{
				factUno=factUno*i;
				huboError=0;
			}
		}

	}

	*pResultado=factUno;
	return huboError;

}

/// \fn int calculadora_menuInicial(void)
/// \brief Función para mostar el menú y tomar la elección del usuario. No se realizan validaciones ya que el switch se encarga de verificar que la opción ingresada
/// 		sea correcta
///
/// \return eleccionUsuario >>> Retorna el número elegido por el usuario

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
	printf("5. Salir\n\n");


	scanf("%d",&eleccionUsuario);
	return eleccionUsuario;


}

/// \fn int calculadora_menuDeOperaciones(float, float, char, char)
/// \brief La función muestra el menú con los números ya ingresados por el usuario. No se realizan validaciones ya que el switch se encarga de verificar que la opción ingresada
/// 		sea correcta. Recibe los 2 numeros y las 2 banderas como paramentros
///
/// \param operadorUno >>> Se pasa la variable donde se guardó el primer número que ingresó el usuario.
/// \param operadorDos >>> Se pasa la variable donde se guardó el segundo número que ingresó el usuario.
/// \param banderaUno >>> Se pasa la variable que indica si se ingresó el operadorUno o no. Si no está ingresado, el operadorUno toma el valor de 0 (solo a modo gráfico
/// 						las operaciones no van a ser calculadas tomando este valor como cero al menos que el usuario así lo ingrese)
/// \param banderaDos >>> Se pasa la variable que indica si se ingresó el operadorDos o no. Si no está ingresado, el operadorDos toma el valor de 0 (solo a modo gráfico
/// 						las operaciones no van a ser calculadas tomando este valor como cero al menos que el usuario así lo ingrese)
/// \return eleccionUsuario >>> Retorna el número elegido por el usuario

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
	printf("5. Salir\n\n");

	fflush(stdin);
	scanf("\n\n%d",&eleccionUsuario);

	return eleccionUsuario;
}

/// \fn int mostrarResultado(float, float, float, int, char*, char*)
/// \brief Funcion para mostrar resultado de las operaciones
///
/// \param operadorUno >>> Se pasa la variable donde se guardó el primer número que ingresó el usuario.
/// \param operadorDos >>> Se pasa la variable donde se guardó el segundo número que ingresó el usuario.
/// \param resultadoOperacion >>>  Se pasa la variable donde se guardó el resultado de la operación (si es que pudo hacerse)
/// \param retornoOperacion >>> Se pasa la variable donde se guardó el retorno de la función de la operación
/// \param mensajeError >>> Mensaje para indicar que hubo un error.
/// \param operacion >>> Mensaje para indicar a qué operación se hace referencia
/// \return retorno >>> El retorno indica si la función pudo ejecutarse, es decir, si los 2 mensajes que se pasaron son distintos de NULL

int mostrarResultado (float operadorUno,float operadorDos,float resultadoOperacion,int retornoOperacion, char*mensajeError, char*operacion)
{
	int retorno;

	retorno=-1;

	if(mensajeError!=NULL&&operacion!=NULL)
	{
		retorno=0;
		if(retornoOperacion==-1)
		{
			printf("%s\n",mensajeError);
		} else
		{
			printf("El resultado de %s de %.2f y %.2f es %.2f\n",operacion,operadorUno,operadorDos,resultadoOperacion);
		}
	}

	return retorno;

}

/// \fn int mostrarResultadoFact(float, int, int, char*)
/// \brief Función para mostrar resultado de factoriales (solo un operador)
///

/// \param operadorUno >>> Se pasa la variable donde se guardó el segundo número que ingresó el usuario.
/// \param resultadoOperacion >>>  Se pasa la variable donde se guardó el resultado de la operación (si es que pudo hacerse)
/// \param retornoOperacion >>> Se pasa la variable donde se guardó el retorno de la función de la operación
/// \param mensajeError mensajeError >>> Mensaje para indicar que hubo un error.
/// \return retorno >>> El retorno indica si la función pudo ejecutarse, es decir, si el mensaje que se pasó es distinto de NULL


int mostrarResultadoFact (float operadorUno,int resultadoOperacion,int retornoOperacion, char*mensajeError)
{
	int retorno;
	int numero;

	retorno=-1;

	if(mensajeError!=NULL)
	{
		numero=(int)operadorUno;
		retorno=0;
		if(retornoOperacion==-1)
		{
			printf("%s\n",mensajeError);
		} else
		{
			printf("El factorial de %d es %d\n",numero,resultadoOperacion);
		}
	}

	return retorno;

}





