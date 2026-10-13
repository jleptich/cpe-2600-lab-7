#include <stdio.h>
#include <string.h>
#include "vect.h"
#include "arithmetic.h"






int main(){
    vector a;
    vector b;
    strcpy(a.name,"Vec1");
    strcpy(b.name,"Vec2");
    vector *ptr_a = NULL;
    vector *ptr_b = NULL;
    a.x = 10.2;
    a.y = 4.2;
    a.z = 3.2;
    ptr_a = &a;
    b.x = 3.2;
    b.y = 4.4;
    b.z = 2.1;
    ptr_b = &b;

    char op = '*';
    int mult =5;
    vector operation = check_operation(*ptr_a, *ptr_b, op, mult);

    printf("%s + %s = <%.2f, %.2f, %.2f>",a.name,b.name,operation.x,operation.y,operation.z);





    return 0;
}