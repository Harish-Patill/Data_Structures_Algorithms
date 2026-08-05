#include "sll.h"
int sl_insert_after(S_list **head, int given_data, int new_data){

    if(*head==NULL){                                      // if list is empty, end
        return LIST_EMPTY;
    }

    S_list *temp=*head;                                  // temporary variable that holds the same addrss which head is pointing at;
    
    while(temp!=NULL){                                   // traverse through the whole list
        if(temp->data == given_data){                    // check if the data is the same as the given data

            S_list *new_node=malloc(sizeof(S_list));    // create a new node
            
            if(new_node == NULL){                       // check if node is created or not.
                return FAILURE;
            }
            
            new_node->data=new_data;                    // update the new nodes data with the new data
            new_node->link=temp->link;                  // update the new nodes link with the temp->link, meaning adding the address of where the temp is pointing as of now(which is one node before)
            temp->link=new_node;                        // and update the temp->link with the new_nodes address
            
            return SUCCESS;
        }

        temp=temp->link;                                // keep updating the temp
    }
    return DATA_NOT_FOUND;
}