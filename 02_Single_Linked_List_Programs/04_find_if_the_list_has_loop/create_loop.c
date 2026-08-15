#include "sll.h"

/* Function to create the loop */
int create_loop(Slist **head, data_t data){
    int flag=0;
    
    if(*head == NULL){
        return LIST_EMPTY;
    }
    
    Slist *temp=*head;
    Slist *loop_node;
    
    
    while(temp->link != NULL){
        if(temp->data == data){
            loop_node=temp;
            flag=1;
        }
        temp=temp->link;
        
    }
    
    if(flag == 0){
        return DATA_NOT_FOUND;
    }
    
    temp->link = loop_node;
    
    return SUCCESS;
}