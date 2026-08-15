#include "sll.h"
// Function to create the loop
int create_loop(Slist **head, data_t data){
    int flag=0;
    
    if(*head == NULL){                                  // if list is empty, end it
        return LIST_EMPTY;
    }
    
    Slist *temp=*head;
    Slist *loop_node;
    
    
    while(temp->link != NULL){                          // traverse through the list while searching for the node that matches the data where we need to loop the list
        if(temp->data == data){
            loop_node=temp;                             // if the node is found, store its address.
            flag=1;
        }
        temp=temp->link;
        
    }
    
    if(flag == 0){
        return DATA_NOT_FOUND;
    }
    
    temp->link = loop_node;                             // now the temp is pointing to the last node of the list, make the temp to point back to the address we saved earlier
                                                        // this now creates a loop in the list, we traverse to the last node and then go back to the node where we have established
                                                        // the loop
    
    return SUCCESS;
}