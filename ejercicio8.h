#ifndef EJERCICIO8_H
#define EJERCICIO8_H

VECTOR_ELEMENT max_element(Vector* v,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT));
VECTOR_ELEMENT min_element(Vector* v,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT));
VECTOR_ELEMENT suma_elementos(Vector* v);
VECTOR_ELEMENT promedio_elementos(Vector* v);
void print_vector(Vector* v);
void print_vector_inv(Vector* v);
#endif // EJERCICIO8_H