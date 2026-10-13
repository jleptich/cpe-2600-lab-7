#include "vect.h"
typedef struct linked{
    vector vect;
    struct linked *prev;
    struct linked *next;
} linked;

linked *newNode();
void delNode(linked *node);
void assignPrev(linked* node, linked* previous);
void assignNext(linked* node, linked* next);