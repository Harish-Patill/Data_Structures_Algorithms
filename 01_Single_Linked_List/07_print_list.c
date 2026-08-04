#include "sll.h"

void print_list(S_list *head){
	if (head == NULL){
		printf("List is empty\n");
	}
    
	while(head){
		printf("%d -> ",head->data);
		head=head->link;
	}

	printf("NULL\n");
}