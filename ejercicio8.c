#include "vector.h"
#include "ejercicio8.h"
//inciso a

int max_element_index(Vector* v,int i,int j,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT)){ // busco primero el indice del maximo valor de forma recursiva y luego devuelvo el valor con otra funcion
    int result=i;
    int n=vector_size(v);
    if(i<n && j<n){
        if(cmp(vector_get(v,i),vector_get(v,j))<0){
            result=max_element_index(v,j,j+1,cmp);
        }
        else{
            result=max_element_index(v,i,j+1,cmp);
        }
    }
    return result;
}
VECTOR_ELEMENT max_element(Vector* v,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT)){// version encapsulada
    int index=max_element_index(v,0,1,cmp);
    return vector_get(v,index);
}

//inciso b (puedo invertir solamente la funcion cmp en el anterior y me daria el minimo, si quiero hacer dos por separado seria lo mismo tambien pero preguntando si es mayor que 0 el cmp)

int min_element_index(Vector* v,int i,int j,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT)){
    int result=i;
    int n=vector_size(v);
    if(i<n && j<n){
        if(cmp(vector_get(v,i),vector_get(v,j))>0){// unico cambio-> if(cmp>0)
            result=min_element_index(v,j,j+1,cmp);
        }
        else{
            result=min_element_index(v,i,j+1,cmp);
        }
    }
    return result;
}
VECTOR_ELEMENT min_element(Vector* v,int cmp(VECTOR_ELEMENT,VECTOR_ELEMENT)){
    int index=min_element_index(v,0,1,cmp);
    return vector_get(v,index);
}

//inciso c

VECTOR_ELEMENT _suma_elementos(Vector* v,int i){
    VECTOR_ELEMENT result=NULL;
    if(i<vector_size(v)){
    result=fraction_add(vector_get(v,i),_suma_elementos(v,i+1));
    }
    if(i>=vector_size(v)){
        result=fraction_new(0,1);// si no hago esto el ultimo fraction_add devolveria NULL y perderia todas las sumas
    }
    return result;
}
VECTOR_ELEMENT suma_elementos(Vector* v){
    return _suma_elementos(v,0);
}


//inciso d
VECTOR_ELEMENT _promedio_elementos(Vector* v,int i){
    VECTOR_ELEMENT result=NULL;
    if(i<vector_size(v)){
        if(i==0){
            fraction* divisor=fraction_new(vector_size(v),1);
            result=fraction_div(fraction_add(vector_get(v,i),_promedio_elementos(v,i+1)),divisor); 
            fraction_destroy(divisor);
        }else{
            result=fraction_add(vector_get(v,i),_promedio_elementos(v,i+1));
        }
    }
    if(i>=vector_size(v)){
        result=fraction_new(0,1);
    }
    return result;
}
VECTOR_ELEMENT promedio_elementos(Vector* v){
    return _promedio_elementos(v,0);
}

// inciso e

void _print_vector(Vector* v,int i,void print(VECTOR_ELEMENT )){
    if(i<vector_size(v)){
         print(vector_get(v,i));
        _print_vector(v,i+1,print);
    }
}
void print_vector(Vector* v,void print(VECTOR_ELEMENT )){
    _print_vector(v,0,print);
}

//inciso f

void _print_vector_inv(Vector* v,int i,void print(VECTOR_ELEMENT )){
    if(i<vector_size(v)){
        _print_vector_inv(v,i+1,print);
        print(vector_get(v,i));
    }
}
void print_vector_inv(Vector* v,void print(VECTOR_ELEMENT)){
    _print_vector_inv(v,0,print);
}