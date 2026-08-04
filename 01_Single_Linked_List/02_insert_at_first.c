#include "sll.h"

int insert_at_first(S_list **head, int data){
    S_list *new_node=malloc(sizeof(S_list));                // create a new node

    if(new_node == NULL){                                   // check if node is created or not
        printf("Error Occured\n");
        return FAILURE;
    }

    new_node->data=data;                                    // update new_node's data part
    new_node->link=*head;                                   // update new_node's link part

    // update where the head is pointing to, no need to check if the list is empty or not, because no matter the situtaion, we need to upate the header to the new nodes address
    *head=new_node;
                                       

    return SUCCESS;
}