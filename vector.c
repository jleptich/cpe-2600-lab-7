/*
*   Title: Lab5 vector calculator
*   By: Joseph Leptich
*   Date: 10/12/2026
*   Outcome: let the user use the vector calculator
*
*
*
*/
#include <stdio.h>
#include <string.h>
#include "vect.h"
#include "linkedlist.h"
#include <stdlib.h>
#include "arithmetic.h"


int main(){
    linked *initial = NULL;
    linked *end = initial;
    int index = 0;

    printf("WELCOME TO VECTOR CALCULATOR: YOU CAN QUIT BY SAYING QUIT AND GET HELP BY SAYING -h.\n ELSE CREATE A VECTOR LIMIT COMMANDS TO 30 CHARACTERS\n");

    while(1){

        //initializes the input array and the 5 string tokens
        char input[30];
        char* token1;
        char* token2;
        char* token3;
        char* token4;
        char* token5;
        printf("Enter your command:");
        fgets(input, 30, stdin);

        //all the tokens scan from input
        token1 = strtok(input, " \n");
        token2 = strtok(NULL, " \n");
        token3 = strtok(NULL, " \n");
        token4 = strtok(NULL, " \n");
        token5 = strtok(NULL, " \n");
        

        //if only token1 has a input
        if(token2 == NULL && token3 == NULL && token4 == NULL && token5 == NULL){
            //checking if token1 is empty
            if(token1 == NULL){
                printf("You entered a incorrect command: type in -h for help\n\n");
                continue;
            }
            
            //checks to see if the user wants to quit
            else if(!strcmp(token1,"quit")){
                printf("Thank you for using the VECTOR CALCULATOR\n");
                if(initial == NULL){    //if initial has no nodes
                    return 0;
                }
                //cleans the linkedlist then returns 0
                linked *endpoint = end;
                linked *next_endpoint = end->prev;
                while(next_endpoint != NULL){
                    delNode(endpoint);
                    endpoint = next_endpoint;
                    next_endpoint = next_endpoint->prev;
            }
                delNode(endpoint);
                return 0;
            }

            //checks to see if the user raised the help flag
            else if(!strcmp(token1,"-h")){
                printf("-------------HELP------------------\n");
                printf("REMEMBER NEVER USE A COMMA, PUT SPACES BETWEEN EVERY INPUT WHEN CREATING A NEW VECTOR\n\n");
                printf("TO ADD TWO VECTORS YOU CAN DO VEC1 + VEC2: THIS WILL PRINTOUT THE TWO VECTORS ADDED TOGETHER\n\n");
                printf("YOU CAN ALSO ASSIGN A VECTOR BY ADDING OR SUBTRACTING TWO VECTORS BY DOING VEC = VEC1 + VEC2\n\n");
                printf("YOU CAN DO SUBTRACTION WITH VEC1 - VEC2 AND ASSIGN A VECTOR WITH ABOVE MENTION NOTATION\n\n");
                printf("YOU CAN DO SCALAR MULTIPICATION BY MULTIPLING A VECTOR BY AN INT: VEC1*2\n\n");
                printf("IF YOU WISH TO SEE ALL THE VECTORS CREATED ENTER LIST\n\n");
                printf("IF YOU WISH TO LEAVE ENTER quit\n\n");
                printf("IF YOU WISH TO CLEAN OUT YOUR VECTOR LIST INPUT clean\n\n");
                printf("IF YOU WISH TO LOAD A FILE OF VECTORS INPUT load filename.csv\n\n");
                printf("IF YOU WISH TO SAVE A FILE OF VECTORS INPUT save filename.csv\n\n");
                printf("-------------HELP------------------\n");
            
            }

            //checks to see if the user wanted a list of all vectors created
            else if(!strcmp(token1, "list")){
                linked *temp = initial;
                if(index > 0){
                 while(temp != NULL){
                    printf("%s = < %.2f, %.2f, %.2f >\n",temp->vect.name,temp->vect.x,temp->vect.y,temp->vect.z);
                    temp = temp->next;
            }
        }
                else{
                    printf("No vectors have been created\n\n");
                }
            }
            //starts from the end of the linkedlist and frees each node and sets initial and end to NULL
            else if(!strcmp(token1, "clean")){
                printf("Cleaning vector list\n\n");
                linked *endpoint = end;
                linked *next_endpoint = end->prev;
                while(next_endpoint != NULL){
                    delNode(endpoint);
                    endpoint = next_endpoint;
                    next_endpoint = next_endpoint->prev;
            }
                delNode(endpoint);
                initial = NULL;
                index = 0;
                end = initial;
                continue;
        }
            //Prints out a single vectors value
            else{
            int incorrect = 0;
            linked *temp_node = initial;
            while(temp_node != NULL){
                if(!strcmp(temp_node->vect.name,token1)){
                    printf("%s = < %.2f, %.2f, %.2f >\n",temp_node->vect.name,temp_node->vect.x,temp_node->vect.y,temp_node->vect.z);
                    incorrect = 1;
                    break;
                }
                temp_node = temp_node->next;
            }
            //if the user inputted a incorrect value
            if(!incorrect){
            printf("You entered a incorrect command: type in -h for help\n\n");
            continue;
            }
            }
        }

        
        //No such operators that only use token1 and token2
        else if(token3 == NULL && token4 == NULL && token5 == NULL){
            //Loads a file of vectors into the linkedlist
            if(!strcmp(token1, "load")){
                FILE *fp = fopen(token2, "r");
                //checks if the file was opened correctly
                if(fp == NULL){
                    printf("FILE NOT FOUND: RETURNING TO TERMINAL\n");
                    continue;
                }
                else{
                    char read[50];
                    //reads the file line by line and creates a new node if a vector is found
                    while(fgets(read, 50, fp) != NULL){
                        char *read1 = strtok(read, " ,\n");
                        char *read2 = strtok(NULL, " ,\n");
                        char *read3 = strtok(NULL, " ,\n");
                        char *read4 = strtok(NULL, " ,\n");
                        //if any of the reads are NULL continues to the next line in the file
                        if(read1 == NULL || read2 == NULL || read3 == NULL || read4 == NULL){
                            continue;
                        }
                        //adds a new node to the linkedlist with the vector values from the file
                        else{
                            linked *node = newNode();
                            strcpy(node->vect.name,read1);
                            node->vect.x = atof(read2);
                            node->vect.y = atof(read3);
                            node->vect.z = atof(read4);
                            index++;
                            if(initial == NULL){
                                initial = node;
                                end = initial;
                            }
                            else{
                                assignNext(end, node);
                                assignPrev(node, end);
                                end = node;
                            }
                        }
                    }
                    //closes file
                    fclose(fp);
                    printf("File loaded!\n\n");
                    
                }
                
            }
            //saves the linkedlist of vectors to a file
            else if(!strcmp(token1, "save")){
                FILE *fp = fopen(token2, "w");
                if(fp == NULL){
                    printf("FILE NOT FOUND: RETURNING TO TERMINAL\n");
                    continue;
                }
                else{
                    linked *temp_node = initial;
                    //outputs until no more nodes are left
                    while(temp_node != NULL){
                        fprintf(fp,"%s, %.2f, %.2f, %.2f\n",temp_node->vect.name,temp_node->vect.x,temp_node->vect.y,temp_node->vect.z);
                        temp_node = temp_node->next;
                    }
                    //closes file
                    printf("file saved to: %s\n",token2);
                    fclose(fp);
                }

            }

            else{
                printf("INVALID COMMAND: TYPE IN -h FOR HELP\n");
            }
        }

        //Used to check if only vector arithmetic is being used without being inputted to a new vector
        else if(token4 == NULL && token5 == NULL){
            vector *hold1 = NULL;
            vector *hold2 = NULL;
            float hold3 = 0;  //if a vector is being multiplied by a float 
            linked *temp_node = initial;
            //checks to see if token1 is a vector
            while(temp_node != NULL){
                if(!strcmp(temp_node->vect.name,token1)){
                    hold1 = &(temp_node->vect);
                }
                
                if(!strcmp(temp_node->vect.name,token1)){
                    hold2 = &(temp_node->vect);
                }
                temp_node = temp_node->next;
            }
                if(hold1 == NULL){
                    if(atof(token1) != 0){
                        hold3 = atof(token1);
                        
                    }
                    else{
                        printf("YOU'VE ENTERED A INVALID COMMAND\n\n");
                        continue;
                    }
                }

            if(hold2 == NULL){
                    if(atof(token3) != 0){
                        hold3 = atof(token3);
                    }
                    else{
                        printf("YOU'VE ENTERED A INVALID COMMAND\n");
                        continue;
                    }
                }
            
            char op;
            op = assignment(token2);

            //if no valid operation is chosen
            if(op == 'a'){
                printf("Invalid assignment character used\n");
                continue;
            }
            //If neither hold variables are vectors
            if(hold1 != NULL && hold2 != NULL && op == '*'){
                printf("Invalid command entered, enter -h for help\n\n");
                continue;   
            }
            vector temp = check_operation(hold1, hold2, op,hold3);
            printf("output = < %.2f, %.2f, %.2f >\n", temp.x, temp.y, temp.z);
        }

        //No commands have only 4 inputs
        else if(token5 == NULL){
            printf("NO COMMAND ONLY HAS 4 INPUTS: INVALID COMMAND\n");
        }

        //uses all five tokens
        else{
            char assign = assignment(token2);   //token2 has to be a equals sign '='
            char operator = assignment(token4); //token4 has to be some symbol for arithmetic

                vector *hold1 = NULL;
                vector *hold2 = NULL; 
                vector *hold3 = NULL;
                float mult = 0;
                linked *iterate = initial;
                //sees if token1, token3, or token5 are prexisting vectors in the vect_list array
                while(iterate != NULL){
                if(!strcmp(iterate->vect.name,token1)){
                    hold1 = &(iterate->vect);
                }

                if(!strcmp(iterate->vect.name,token3)){
                    hold2 = &(iterate->vect);
                }

                if(!strcmp(iterate->vect.name,token5)){
                    hold3 = &(iterate->vect);
                }
                iterate = iterate->next;

            }
            
            //Detecting if no vectors are being used
            if(hold2 == NULL && hold3 == NULL && operator != 'a'){
                printf("You entered a incorrect operation: Please type in -h if you require help\n\n");
                continue;
            }
            //If vector hold1 doesn't have a name then it needs to be set up as a new vector
            if(hold1 == NULL){
                if(initial == NULL){
                    initial = newNode();
                    end = initial;
                    hold1 = &(initial->vect);
                }
            else{
             linked *node = newNode();
             hold1 = &(node->vect);
             assignNext(end, node);
             assignPrev(node, end);
             end = node;
            }
             index++;
             strcpy(hold1->name,token1);
            }
            
            //Statement for if token2 and token5 are not vectors and are assigning values to a new/prexisting vector
            if(hold2 == NULL && hold3 == NULL && operator == 'a' && assign == '='){
                hold1->x = atof(token3);
                hold1->y = atof(token4);
                hold1->z = atof(token5);
            }

             //looks to see if a vector is being multiplied by a scalar
            if(hold2==NULL && operator == '*'){
                mult = atof(token3);
            }
            

            
            //checks to see if token3 is a scalar multiplier
            if(hold3 ==NULL && operator == '*'){
                mult = atof(token5);
            }

            //If vector arithmetic is being done
            if(operator != 'a' && assign == '='){
            vector temp = check_operation(hold2, hold3, operator, mult);
            hold1->x = temp.x;
            hold1->y = temp.y;
            hold1->z = temp.z;
            printf("%s = < %.2f, %.2f, %.2f >\n",hold1->name,hold1->x,hold1->y,hold1->z);
            }
    }
}
    return 0;

}   