#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data){ 
    
    Slist*new_node=malloc(sizeof(Slist));
    if(new_node==NULL){
        return FAILURE;
    }
    
    new_node->data=data;
    new_node->link=NULL;
    
    if(*head==NULL){                                                    // if the list is empty, just insert and end
        *head=new_node;
        return SUCCESS;
    }
    
    
    if(data < (*head)->data){                                           // if the new data is smaller than the first nodes data, do insert first
        new_node->link=*head;
        *head=new_node;
        return SUCCESS;
    }
    
    Slist*temp=*head;
    
    while((temp->link!=NULL) && ((temp->link->data) < data)){           // traverse until we reach the temp
        temp=temp->link;
    }
    
    new_node->link=temp->link;                                          // update the new nodes link and its prvious nodes link
    temp->link=new_node;
    return SUCCESS;
}