#include "sll.h"
int find_mid(Slist *head, int *mid){
    Slist *slow=head;
    Slist *fast=head;

    if(head == NULL){                   // end it if list is empty
        return LIST_EMPTY;
    }

    while(fast!=NULL && fast->link!=NULL){          
        slow=slow->link;                            // moves one node at a time
        fast=fast->link->link;                      // moves two nodes at a time
    }

    *mid=slow->data;                                // update the mid with the slow nodes data

    return SUCCESS;
}

// while((fast->link != NULL) && (fast != NULL)){ is wrong since the compiler first checks if the fast
// of link is null or not, but if the fast is already NULL then we might be doing NULL of link, thus SEGMENTATION FAUlT