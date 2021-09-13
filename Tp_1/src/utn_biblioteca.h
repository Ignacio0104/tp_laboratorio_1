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

int utn_pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);
float utn_pedirFloatSinIntentos(char* variableTexto, char* textoError);
int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirIntAUsuarioSinIntentos(int* pResultado, int min, int max, char* variableTexto, char* textoError);
int utn_pedirCharAUsuario(char* pResultado, char min, char max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirCharAUsuarioSinIntentos(char* pResultado, char min, char max, char* variableTexto, char* textoError);
float utn_dividir (int operador1,int operador2,float*direccionVariable);
float utn_pedirNumero (char mensaje[],char* textoError);
float utn_sumar (float operadorUno, float operadorDos);
float utn_restar (float operadorUno, float operadorDos);
//int utn_dividir (float operadorUno, float operadorDos, float* pResultado);
float utn_multiplicar (float operadorUno, float operadorDos);
float utn_factorial (float operadorUno);
int utn_menuInicial (void);
int utn_menuDeOperaciones (float operadorUno, float operadorDos);

#endif /* UTN_BIBLIOTECA_H_ */




