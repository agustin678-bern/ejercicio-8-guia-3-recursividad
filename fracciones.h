#ifndef FRACCIONES_H_INCLUDED
#define FRACCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//TDA de fracciones
typedef struct _fraction fraction;


// crear una fracci�n
fraction* fraction_new (int num, int den);

//destruir una fracci�n
void fraction_destroy (fraction* f);

//imprimir una fracci�n
void fraction_print (fraction* f);

//obtener numerador
int fraction_get_num (fraction* f);

//obtener denominador
int fraction_get_den (fraction* f);
//sumar 2 fracciones
fraction* fraction_add (fraction* f1, fraction* f2);

//restar 2 fracciones
fraction* fraction_sub (fraction* f1, fraction* f2);

//multiplicar 2 fracciones
fraction* fraction_mul (fraction* f1, fraction* f2);

//dividir 2 fracciones
fraction* fraction_div (fraction* f1, fraction* f2);

//simplificar una fracci�n
void fraction_simplify (fraction* f);

//comparar 2 fracciones
int fraction_cmp (fraction* f1, fraction* f2);


#endif // FRACCIONES_H_INCLUDED
