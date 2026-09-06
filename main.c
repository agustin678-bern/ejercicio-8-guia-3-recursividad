#include "vector.h"
#include "ejercicio8.h"
int cmp_entero(int a,int b){
    return a-b;
}
int main(){
    Vector* nuevo=vector_new(10);

    vector_add(nuevo,100);
    vector_add(nuevo,234);
    vector_add(nuevo,1233);
    vector_add(nuevo,3412);
    vector_add(nuevo,1232);
    vector_add(nuevo,332);
    vector_add(nuevo,2);
    vector_add(nuevo,3);
    vector_add(nuevo,4);


    printf("vector impreso:");
    vector_print(nuevo,print_entero);
    printf("\n");
    printf("valor maximo %d \n",max_element(nuevo,cmp_entero));
    printf("valor minimo %d \n",min_element(nuevo,cmp_entero));
    printf("elementos del vector sumados= %d \n",suma_elementos(nuevo));
    printf("promedio de los elementos del vector: %d \n",promedio_elementos(nuevo));
    printf("vector impreso en forma recursiva: ");
    print_vector(nuevo);
    printf("\n");
    printf("vector impreso en forma recursiva inversa: ");
    print_vector_inv(nuevo);
    printf("\n");
    
    return 0;
}