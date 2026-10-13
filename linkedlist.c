#include "vect.h"
#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>


linked *newNode(){
    linked *node = malloc(sizeof(linked));

    if(node == NULL){
        return NULL;
    }
    node->next = NULL;
    node->prev = NULL; 
    return node;
}


void delNode(linked *node){
    if(node != NULL){
        free(node);
    }
}

void assignPrev(linked* node, linked* previous){
    node->prev = previous;
}

void assignNext(linked* node, linked* next){
    node->next = next;
}