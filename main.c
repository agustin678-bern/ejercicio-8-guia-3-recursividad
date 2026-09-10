#include "vector.h"
#include "ejercicio8.h"
int cmp_entero(int a,int b){
    return a-b;
}
int main(){
    Vector* nuevo=vector_new(10);

    vector_add(nuevo,fraction_new(1,2));
    vector_add(nuevo,fraction_new(1,3));
    vector_add(nuevo,fraction_new(1,25));
    vector_add(nuevo,fraction_new(1,4));
    vector_add(nuevo,fraction_new(3,2));
    vector_add(nuevo,fraction_new(1,2));
    vector_add(nuevo,fraction_new(1,2));
    vector_add(nuevo,fraction_new(1,2));
    vector_add(nuevo,fraction_new(1,4));


    printf("vector impreso:");
    vector_print(nuevo,fraction_print);
    printf("\n");
    printf("valor maximo:");
    fraction* maximo=max_element(nuevo,fraction_cmp);
    fraction_print(maximo);
    printf("\n");
    printf("valor minimo:");
    fraction* minimo=min_element(nuevo,fraction_cmp);
    fraction_print(minimo);
    printf("\n");
    printf("elementos del vector sumados");
    fraction* suma=suma_elementos(nuevo);
    fraction_print(suma);
    printf("\n");
    printf("promedio de los elementos del vector:");
    fraction* promedio=promedio_elementos(nuevo);
    fraction_print(promedio);
    printf("\n");
    printf("vector impreso en forma recursiva: ");
    print_vector(nuevo,fraction_print);
    printf("\n");
    printf("vector impreso en forma recursiva inversa: ");
    print_vector_inv(nuevo,fraction_print);
    printf("\n");
    int cant=vector_size(nuevo);
    for(int i=0;i<cant;i++){
        fraction_destroy(vector_get(nuevo,i));
    }
    vector_free(nuevo);
    printf("vector eliminado correctamente");
    return 0;
}