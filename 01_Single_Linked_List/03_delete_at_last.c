#include "sll.h"
int sl_delete_last(S_list **head){
    S_list *temp=*head;

    // case 1: list is empty
    if(*head == NULL){                              // check if the List is empty, end;
        printf("List is Empty\n");
        return FAILURE;
    }

    // case 2: list has exactly 1 element
    if((*head)->link == NULL){                      // if list has exactly one element, free it and update the head to NULL;
        free(*head);
        *head=NULL;

        return SUCCESS;
    }

    // case 3: list has more than 1 elements
    while (temp->link->link != NULL){               // temp will now point to the last second node
        temp=temp->link;
    }

    free(temp->link);                               // free the last node using its address present in the last second node
    temp->link=NULL;                                // now sice the last scond node is last node, update its link part with the NULL;

    return SUCCESS;
}







/*  another way to get the last second nodes address:

S_list=*prev=*head;

while(temp->link != NULL){                          
    prev=temp;                                      here the prev will hold the last second node's address
    temp=temp->link;                                temp will be one node ahead of the prev
}


free(prev->link);                                   free the last node
prev->link=NULL;                                    updat the new last nodes link part with the NULL

*/ 
