#include "sll.h"

int sl_delete_first(S_list **head){
    S_list *temp=*head;

    if(*head == NULL){                          // is list is empty
        printf("List is empty\n");
        return FAILURE;
    }

    temp=(*head)->link;                         // temp holds the second node's address

    free(*head);                                // free the first node
    *head=temp;                                 // update the head with the second nodes address


    /*  or(anothe method) 

    *head=(*head)->link;                        // the head will now point to the second node
    free(temp);                                 // since the temp holds the addess of the first node(initialized during the declaration), we can just free it.
    */

    return SUCCESS;
}