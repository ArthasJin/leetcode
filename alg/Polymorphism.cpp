#include<stdlib.h>
#include<stdio.h>

void task1(){
    printf("I am base class object\n");
}

void task2(){
    printf("I am derived class object\n");
}

typedef void (*fnptr_t)(void );

static fnptr_t vatable_A[1]={task1};
static fnptr_t vatable_B[1]={task2};

struct A{
    fnptr_t *vptr;
    int _a;
};

struct B{
    fnptr_t * vptr;
    int _b;
};

void init_A(struct A* p ){
    p->vptr= vatable_A;
    p->_a=0;
}

void init_B(struct B* p){
    p->vptr= vatable_B;
    p->_b=0;
}

void func(void* ob){
    /*And this something dark magic.*/
    struct A* p = (struct A*)ob;
    p->vptr[0]();
}

int main(){
    struct A ob_a;
    struct B ob_b;
    init_A(&ob_a);
    func((void*)&ob_a);

    init_B(&ob_b);
    func((void*)&ob_b);
    return 0;
}

