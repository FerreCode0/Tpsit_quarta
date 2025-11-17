#ifndef MYLIB_H  /*se non è definito*/
#define MYLIB_H 

#include <stdio.h>
#include <string.h>
#include <errno.h>   /*contiene gli errori, tipo error number*/
#include <stdlib.h>  /*malloc e qui*/

#define MAX_STRING_LENGTH 256

void errore(char* s, int n);
char* readLine(FILE* f);
char** splitString(char* s, char delimiter);  /*riceve una stringa e un delimitatore*/
void disposeStringArray(char** arr);   /*char** è un puntatore di un vettore*/
int randomRange(int min, int max);  /*numero randomico*/

#include "myLib.c"

#endif // MYLIB_H

