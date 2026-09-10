#include "fracciones.h"
#include "math.h"

typedef struct _fraction{
    int Num;
    int Den;
} fraction;

int mcd(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}
int mcm(int a, int b) {
    return (a * b) / mcd(a, b);
}
fraction* fraction_new (int num, int den){
    if(den==0)return NULL;
    fraction* result=malloc(sizeof(fraction));
    if(result!=NULL){
        result->Num=num;
        result->Den=den;
    }
    return result;
}

void fraction_destroy (fraction* f){
    free(f);
}
void fraction_print (fraction* f){
    if(f==NULL)return;
    if(f->Den==0) return;
    if(f->Num==0){
        printf("%d",f->Num);
    }else{
        printf(" %d/%d ",f->Num,f->Den);
    }
}
int fraction_get_num (fraction* f){
    if(f==NULL)return 0;
    return f->Num;
}
int fraction_get_den (fraction* f){
    if(f==NULL)return 0;
    return f->Den;
}
void fraction_simplify (fraction* f){
    if(f!=NULL){
        int divisor = mcd(abs(f->Num), abs(f->Den));
        if(f->Den<0){
            f->Num*=-1;
            f->Den*=-1;
        }
        f->Num=f->Num/divisor;
        f->Den=f->Den/divisor;
    }
}
fraction* fraction_add (fraction* f1, fraction* f2){
    if(f1==NULL || f2==NULL)return NULL;
    int den=mcm(abs(f1->Den),abs(f2->Den));
    int num=(f1->Num)*(den/f1->Den)+(f2->Num)*(den/f2->Den);
    fraction* result=fraction_new(num,den);
    fraction_simplify(result);
    return result;
}
fraction* fraction_sub (fraction* f1, fraction* f2){
    if(f1==NULL || f2==NULL)return NULL;
    int den=mcm(abs(f1->Den),abs(f2->Den));
    int num=(f1->Num)*(den/f1->Den)-(f2->Num)*(den/f2->Den);
    fraction* result=fraction_new(num,den);
    fraction_simplify(result);
    return result;
}
fraction* fraction_mul (fraction* f1, fraction* f2){
    if(f1==NULL || f2==NULL)return NULL;
    int num=f1->Num*f2->Num;
    int den=f1->Den*f2->Den;
    fraction* res=fraction_new(num,den);
    fraction_simplify(res);
    return res;
}
fraction* fraction_div (fraction* f1, fraction* f2){
    if(f1==NULL || f2==NULL)return NULL;
    int num=f1->Num*f2->Den;
    int den=f1->Den*f2->Num;
    fraction* result=fraction_new(num,den);
    fraction_simplify(result);
    return result;
}
int fraction_cmp (fraction* f1, fraction* f2){
    fraction* sub=fraction_sub(f1,f2);
    if(sub==NULL) return -2;
    int result=0;
        if(sub->Num<0){
            result=-1;
        }else if(sub->Num>0){
            result=1;
        }
    fraction_destroy(sub);
    return result;
}
