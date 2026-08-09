#include "sll.h"

int sl_delete_list(S_list **head){
	S_list *temp=*head;                             // a temporary variable that holds the current address of where head is pointing to

    if(*head == NULL){                              // if list is empty, end
        return FAILURE;
    }

    while(temp != NULL){                            // let this run until we hit the last node
        *head=(*head)->link;                        // update the head with the next nodes address
        free(temp);                                 // free the current node(1st node as of now as it is pointing to the first node)
        temp=*head;                                 // now assign temp with the next nodes address;

    }
    return SUCCESS;
}   