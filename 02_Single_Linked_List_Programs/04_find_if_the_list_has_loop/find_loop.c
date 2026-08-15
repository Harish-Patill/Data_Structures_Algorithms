#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head){
    Slist *slow=head;
    Slist *fast=head;

    if(head == NULL){                   // end it if list is empty
        return LIST_EMPTY;
    }

    while(fast!=NULL && fast->link!=NULL){          
        slow=slow->link;                            // moves one node at a time
        fast=fast->link->link;                      // moves two nodes at a time
    
        if(slow == fast){
            return SUCCESS;
        }
        
    }
    
    return LOOP_NOT_FOUND;
}