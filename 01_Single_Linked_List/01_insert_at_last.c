#include "sll.h"
int insert_at_last(S_list **head, int given_data){
    S_list *temp=*head;                                         // a temp variable to hold address in head

    S_list *new_node=malloc(sizeof(S_list));                    // create a node using malloc
    if(new_node == NULL){                                       
        printf("Error Occured\n");
        return FAILURE;                                         // terminate the program if the node is not created!
    }

    new_node->data=given_data;                                  // update the new nodes data and the link part
    new_node->link=NULL;                                        // sice its the last node we will assign NULL in its link part.


    // case 1: list is empty
    if(*head == NULL){                                          // if the head is empty, meaning the list is empty, we only need to update the head with the new nodes address
        *head=new_node;
        return SUCCESS;
    }


    // case 2: list is not empty
    while(temp->link != NULL){                                  // we will travese through the whole list and get to the last node
        temp=temp->link;
    }
    temp->link=new_node;                                        // and updat the last nodes link part with the new node, as it is now supposed to point to the new node.
    return SUCCESS;
}