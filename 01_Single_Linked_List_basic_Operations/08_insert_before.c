#include "sll.h"

int sl_insert_before(S_list **head, int given_data, int new_data){
    S_list *temp=*head;
    S_list *prev=NULL;

    if(*head == NULL){                          // list is empty
        return LIST_EMPTY;
    }

    while(temp != NULL){
        if(temp->data == given_data){                       // if element found
            S_list *new_node=malloc(sizeof(S_list));        // create a node

            if(new_node == NULL){                           // check if node is created or not
                return FAILURE;
            }

            new_node->data=new_data;     
            
            if(prev == NULL){                               // if the node if first
                new_node->link=*head;
                *head=new_node;
            }
            else{                                           // will be executed when the node is not first
                new_node->link=temp;
                prev->link=new_node;
            }
            
            return SUCCESS;
        }

        prev=temp;
        temp=temp->link;
    }
    return DATA_NOT_FOUND;
}