#ifndef _VECTOR
#define _VECTOR
#include <stdio.h>
#include <stdlib.h>

#define VECTOR_ELEMENT int
#define VECTOR_ELEMENT_DEFAULT -1000000

typedef struct _vector Vector;
void print_entero(int a);
void resize_vector(Vector* v);
Vector* vector_new(int ini_size);
// Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño
// Máximo = ini_size.

void vector_free(Vector* v);
// Eliminar el vector

int vector_size(Vector* v);
// Permite obtener el tamaño actual del vector
int vector_max_size(Vector* v);
int vector_isfull(Vector* v);
// Devuelve 0 si no está lleno y 1 si está lleno.

int vector_isempty(Vector* v);
// Devuelve 0 si no está vacío y 1 si está vacío.

VECTOR_ELEMENT vector_get(Vector* v, int index);
// Permite obtener el valor de una posición del vector

VECTOR_ELEMENT vector_set(Vector* v, int index, VECTOR_ELEMENT value);
// Permite reemplazar el valor de una posición del vector

int vector_add(Vector* v, VECTOR_ELEMENT value);
// Permite agregar un elemento al final

int vector_insert(Vector* v, int index, VECTOR_ELEMENT value);
// Permite agregar un elemento en una posición determinada.

VECTOR_ELEMENT vector_remove(Vector* v, int index);
// Permite eliminar un elemento del vector

void vector_print(Vector* v, void (*print)(VECTOR_ELEMENT));
// Permite imprimir un vector por consola
void bubble_sort_vec(Vector* v,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT));// ejercicio 12
int sequential_search(Vector* v,VECTOR_ELEMENT value,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT));
int _binary_search(Vector* v,VECTOR_ELEMENT value,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT));

#endif
