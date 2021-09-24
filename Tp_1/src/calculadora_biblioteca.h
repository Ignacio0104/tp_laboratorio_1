/*
 * utn_biblioteca.h
 *
 *  Created on: 9 sept 2021
 *      Author: Nacho
 */

#ifndef CALCULADORA_BIBLIOTECA_H_
#define CALCULADORA_BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>

int calculadora_pedirFloat(char* variableTexto, char* textoError, float* pVariableNumero);
int calculadora_pedirIntAUsuario(int* pVariableNumero, int min, int max, char* variableTexto, char* textoError);
float calculadora_dividir (int operador1,int operador2,float*direccionVariable);
int calculadora_pedirChar (char mensaje[],char* textoError,char*pRespuesta, char opcionUno, char opcionDos);
float calculadora_sumar (float operadorUno, float operadorDos);
float calculadora_restar (float operadorUno, float operadorDos);
float calculadora_multiplicar (float operadorUno, float operadorDos);
int calculadora_factorial (float operadorUno, int*pResultado);
int calculadora_menuInicial (void);
int calculadora_menuDeOperaciones (float operadorUno, float operadorDos, char banderaUno, char banderaDos);
int mostrarResultado (float operadorUno,float operadorDos,float resultadoOperacion,int retornoOperacion, char*mensajeError, char*operacion);
int mostrarResultadoFact (float operadorUno,int resultadoOperacion,int retornoOperacion, char*mensajeError);

#endif /* CALCULADORA_BIBLIOTECA_H_ */




