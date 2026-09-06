#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef struct _vector{
   VECTOR_ELEMENT* a;
   int Size;
   int max_size;
} Vector;


/**
 * @brief Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño Máximo = ini_size.
 *
 * @param ini_size
 * @return Vector*
 */
Vector* vector_new(int ini_size){

   Vector* result=malloc(sizeof(Vector));
   result->a=malloc(sizeof(VECTOR_ELEMENT)*ini_size);
   result->Size=0;
   result->max_size=ini_size;

   return result;
}

/**
 * @brief Eliminar el vector
 *
 * @param v
 */
void vector_free(Vector* v){
    free(v);
}

/**
 * @brief Permite obtener el tamaño actual del vector
 *
 * @param v
 * @return int
 */
int vector_size(Vector* v){
    if(v==NULL)return 0;
    return v->Size;
}
int vector_max_size(Vector* v){
    if(v==NULL)return 0;
    return v->max_size;
}
/**
 * @brief Devuelve 0 si no está lleno y 1 si está lleno.
 *
 * @param v
 * @return int
 */
int vector_isfull(Vector* v) {
    if(v==NULL)return -1;
    return (v->Size>=v->max_size)? 1 : 0;
}

/**
 * @brief Devuelve 0 si no está vacío y 1 si está vacío.
 *
 * @param v
 * @return int
 */
int vector_isempty(Vector* v){
    if(v==NULL)return -1;
   return(v->Size==0)? 1 : 0;
}


/**
 * @brief Permite obtener el valor de una posición del vector
 *
 * @param v
 * @param index
 * @return VECTOR_ELEMENT
 */
VECTOR_ELEMENT vector_get(Vector* v, int index){
    if(v==NULL)return VECTOR_ELEMENT_DEFAULT;
   return v->a[index];
}

/**
 * @brief Permite reemplazar el valor de una posición del vector
 *
 * @param v
 * @param index
 * @return VECTOR_ELEMENT
 */
VECTOR_ELEMENT vector_set(Vector* v, int index, VECTOR_ELEMENT value){
    if(v==NULL)return VECTOR_ELEMENT_DEFAULT;
    VECTOR_ELEMENT ant=v->a[index];
    v->a[index]=value;
    return ant;
}

/**
 * @brief Permite agregar un elemento al final
 *
 * @param v
 * @param value
 */
 void resize_vector(Vector* v){
    VECTOR_ELEMENT* aux= realloc(v->a,(v->max_size)*2*sizeof(VECTOR_ELEMENT));
    if(aux!=NULL){
        v->a=aux;
        v->max_size*=2;
    }
 }
int vector_add(Vector* v, VECTOR_ELEMENT value){
   if(!vector_isfull(v)){
        v->a[v->Size]=value;
        v->Size++;
        return v->Size;
   }
   return -1;

}


/**
 * @brief Permite agregar un elemento en una posición determinada.
 *
 * @param v
 * @param index
 * @param value
 */
int vector_insert(Vector* v, int index, VECTOR_ELEMENT value){
    if(vector_isfull(v))resize_vector(v);
    if(vector_isfull(v))return -1;
    for(int n=v->Size;n>index;n--){
        v->a[n]=v->a[n-1];
    }
    v->a[index]=value;
    v->Size++;
    return 1;
}


/**
 * @brief Permite eliminar un elemento del vector
 *
 * @param v
 * @param index
 */
VECTOR_ELEMENT vector_remove(Vector* v, int index){
   if(index>v->Size-1)return 0;
   VECTOR_ELEMENT res=v->a[index];
   v->Size-=1;
   for(int i=index;i<v->Size;i++){
        v->a[i]=v->a[i+1];
   }
   return res;
}

/**
 * @brief print the vector
 *
 */
void print_entero(int a){
    printf(" %d ",a);
}

void vector_print(Vector* v, void (*print)(VECTOR_ELEMENT)){
   for(int i=0;i<v->Size;i++){
    print(v->a[i]);
   }
}
void bubble_sort_vec(Vector* v,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT)){
    int v_size=vector_size(v);
    char swapped=1;
    while(v_size>1 && swapped!=0){
        swapped=0;
        for(int i=1;i<v_size;i++){
            VECTOR_ELEMENT a=vector_get(v,i-1);
            VECTOR_ELEMENT b=vector_get(v,i);
            if(cmp(a,b)>0){
                vector_set(v,i-1,b);
                vector_set(v,i,a);
                swapped=1;
            }
        }
        v_size--;
    }
}
int sequential_search(Vector* v,VECTOR_ELEMENT value,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT)){
    int i=0;
    int v_size=vector_size(v);
    while(i<v_size && cmp(vector_get(v,i),value)!=0){
        i++;
    }
    return (i<v_size)? i : -1;
}

int _binary_search(Vector* v,VECTOR_ELEMENT value,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT)){
    if(v==NULL)return -1;
    int high=vector_size(v);
    int low=0;
    int mid=(high-low)/2;
    VECTOR_ELEMENT mid_value=vector_get(v,mid);
    while(low<high && cmp(mid_value,value)!=0){
        if(cmp(mid_value,value)<0){
            low=mid+1;
        }else if(cmp(mid_value,value)>0){
            high=mid-1;
        }
        mid=(high-low)/2;
        mid_value=vector_get(v,mid);
    }
    return (cmp(mid_value,value)==0)? mid : -1;
}
