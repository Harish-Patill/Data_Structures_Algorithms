#include "arbitary_precision_calculator_header.h"

void print_list(node *head){
	if (head == NULL){
		printf("INFO : List is empty\n");
	}
    else{
		printf("\nAns: ");
	    while (head){
		    printf("%d", head -> data);
		    head = head -> next;
	    }
	    printf("\n");
    }
}