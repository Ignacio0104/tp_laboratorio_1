/*
 * Validaciones.h
 *
 *  Created on: 7 nov 2021
 *      Author: Nacho
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include "biblioteca_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esNombre(char cadena[]);
int pedirNombre(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError);

#endif /* VALIDACIONES_H_ */
