#include "sll.h"
int find_nth_last(Slist *head, int pos, int *data){
    int i;
    Slist *first=head;
    Slist *second=head;

    if(head == NULL){
        return LIST_EMPTY;
    }

    if(pos <= 0){               // pos should be greater than 0
        return FAILURE;
    }

    for(i=0;i<pos;i++){         // move second pointer 'pos' nodes ahead
        if(second == NULL){
            return FAILURE;     // end it if, pos is greater than list length
        }
        second=second->link;
    }

    while(second != NULL){      // now moving both the pointers together until second hits the end
        first=first->link;
        second=second->link;
    }

    *data=first->data;          // update the data with the first nodes data

    return SUCCESS;
}
