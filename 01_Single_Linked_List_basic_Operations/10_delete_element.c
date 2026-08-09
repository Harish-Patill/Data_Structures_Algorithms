#include "sll.h"

int sl_delete_element(S_list **head, int data){

    if(*head==NULL){                                // if empty list, end it
        return FAILURE;
    }
    
    S_list *temp=*head;
    
    if(temp->data==data){                           // check if its the first node
        *head=temp->link;
        free(temp);
        return SUCCESS;
    }

    S_list *prev=temp;
    temp = temp->link;
    
    while(temp!=NULL){                              
        if(temp->data==data){
            prev->link=temp->link;
            free(temp);
         return SUCCESS;
        }
        prev=temp;
        temp=temp->link;
    }
   return DATA_NOT_FOUND;
}