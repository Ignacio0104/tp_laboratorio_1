/*
 * utn_biblioteca.h
 *
 *  Created on: 9 sept 2021
 *      Author: Nacho
 */

#ifndef UTN_BIBLIOTECA_H_
#define UTN_BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>


float utn_dividir (int operador1,int operador2,float*direccionVariable);
//int utn_pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);
//int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirCharAUsuario(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError);
float pedirNumero (char mensaje[]);
float restar (float operadorUno, float operadorDos);
float sumar (float operadorUno, float operadorDos);
int dividir (float operadorUno, float operadorDos, float* pResultado);
float multiplicar (float operadorUno, float operadorDos);
float factorial(float operadorUno);
int menuDeOperaciones (float operadorUno, float operadorDos);
int menuInicial (void);

#endif /* UTN_BIBLIOTECA_H_ */




