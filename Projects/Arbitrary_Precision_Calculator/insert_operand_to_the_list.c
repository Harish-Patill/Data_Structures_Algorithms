#include "arbitary_precision_calculator_header.h"

void insert_operand(node **head, node **tail, char *operand, int len){
    int start = (operand[0] == '+' || operand[0] == '-') ? 1 : 0;                           // skip sign if it is present

    for(int i=start; i<len; i++){
        node *newNode = malloc(sizeof(node));
        if(newNode == NULL){
            printf("Error Occured\n");
            exit(FAILURE);
        }
        newNode->data = operand[i] - '0';                                                  // char digit -> int
        newNode->next = NULL;
        newNode->prev = *tail;

        if(*tail != NULL)
            (*tail)->next = newNode;
        else
            *head = newNode;                                                              // first node becomes head

        *tail = newNode;
    }
}