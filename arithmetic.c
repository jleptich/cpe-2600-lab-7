/*
*   Title: Lab5 vector calculator
*   By: Joseph Leptich
*   Date: 10/12/2026
*   Outcome: File that contains all the functions for the main vector calculator
*/
#include <string.h>
#include <stdio.h>
#include "vect.h"



vector add(vector *a, vector *b){
    vector assign;
    assign.x = a->x + b->x;
    assign.y = a->y + b->y;
    assign.z = a->z + b->z;

    return assign;
}

vector sub(vector *a, vector *b){
    vector assign;
    assign.x = a->x - b->x;
    assign.y = a->y - b->y;
    assign.z = a->z - b->z;

    return assign;
}

vector scalar_mult(vector *a, float p){
    vector assign;
    assign.x = a->x*p;
    assign.y = a->y*p;
    assign.z = a->z*p;
    return assign;
}


vector check_operation(vector *a, vector *b, char arith, float mult){
    switch(arith){
        
        case '+':
        return add(a, b);
        
        case '-':
        return sub(a, b);
        
        case '*':
        if(b == NULL){
        return scalar_mult(a, mult);
        }

        else{
            return scalar_mult(b, mult);
        }

        default:
        printf("UNKOWN INPUT: RETURNING BACK TO TERMINAL\n");
        vector def;
        def.x = 0;
        def.y = 0;
        def.z = 0;
        return def;
    }
}


char assignment(char* token){
            char op;
            if(!strcmp(token,"+")){
                op = '+';
            }
            else if(!strcmp(token,"-")){
                op = '-';
            }
            else if(!strcmp(token,"*")){
                op = '*';
            }
            else if(!strcmp(token,"=")){
                op = '=';
            }
            else{
                op = 'a';
            }
            return op;
}










