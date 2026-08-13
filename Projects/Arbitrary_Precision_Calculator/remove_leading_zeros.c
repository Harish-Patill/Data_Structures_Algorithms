#include "arbitary_precision_calculator_header.h"
void remove_leading_zeros(node **head, node **tail){
    // strip zero-digit nodes from the head, but always leave at least one digit
    // (so "000" stays "0", not an empty list)
    while((*head)->next != NULL && (*head)->data == 0){
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}