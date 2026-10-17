#include "vect.h"
#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>

//creates a new node for the linkedlist and returns the nodes address
linked *newNode(){
    linked *node = malloc(sizeof(linked));

    if(node == NULL){
        return NULL;
    }
    node->next = NULL;
    node->prev = NULL; 
    return node;
}

//deletes a node from the linkedlist and frees the memory
void delNode(linked *node){
    if(node != NULL){
        free(node);
    }
}
//assigns a nodes previous node
void assignPrev(linked* node, linked* previous){
    node->prev = previous;
}
//assigns a the next node to a node
void assignNext(linked* node, linked* next){
    node->next = next;
}