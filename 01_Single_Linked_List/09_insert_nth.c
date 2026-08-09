// #include "sll.h"

// int sl_insert_nth(S_list **head, int data, int n){
//     S_list *temp=*head;                                 // maintaining a temperoray and a prev variable
//     S_list *prev=NULL;
    
//     if(n<=0){                                           // if the nth position is not valid, end it
//         return POSITION_NOT_FOUND;
//     }
    
//     if(*head==NULL && n>1){                             // if the head is empty and the nth node is greater than 1(if list is empty, can only insert at the first node)
//         return LIST_EMPTY;
//     }
    
//     S_list *new_node=malloc(sizeof(S_list));            // create the node to be inserted
//     if(new_node==NULL){                                 // check if the node is created or not
//         return FAILURE;              
//     }
//     new_node->data=data;                                // update the new nodes data with the given data
//     new_node->link=NULL;                                // update the new nodes link part witht the NULL
    
//     if(n == 1){                                         // if the new node need to be inserted at the first
//         new_node->link=*head;                           // pointing the new node to the previous 1st node
//         *head=new_node;                                 // update head with the new nodes address    
//         return SUCCESS;
//     }
    
//     // this is when the nth node in inside the lists valid length
//     while(temp){                                        
//         if(n == 1){                                     // here we keep on decrementing the n untill we get n==1
//             new_node->link=prev->link;
//             prev->link=new_node;
//             return SUCCESS;
//         }
//         n--;
//         prev=temp;
//         temp=temp->link;
//     }

//     //  this is when the nth node is the new last node
//     if(n==1){
//         new_node->link=prev->link;
//         prev->link=new_node;
//         return SUCCESS;
//     }
    
//     free(new_node);                                     // position didn't exist — clean up before returning
//     return POSITION_NOT_FOUND;
// }





#include "sll.h"

int sl_insert_nth(S_list **head, int data, int n){
    int count=1;
    S_list *temp=*head;
    S_list *prev=NULL;

    if(*head == NULL && n>1){                                   // if list is empty and then the new node cant be other than the first node
        return LIST_EMPTY;
    }

    while(temp && count<n){                                     // this will update the temp and prev until the count and the n are equal
        prev=temp;
        temp=temp->link;
        count++;
    }
    
    S_list *new_node=malloc(sizeof(S_list));                    // create a new node
    if(new_node == NULL){
        return FAILURE;
    }

    new_node->data=data;                                        // update the new nodes data with the given data
    new_node->link=NULL;                                        // update the new nodes link with NULL;

    if(count==n){                                               // if the count and the n match then do the insertion (they should match as of now)          
        new_node->link=temp;                                    // temp is the next node after new_node             

        if(prev){                                               
            prev->link=new_node;                                // prev is the previous node to the new_node
        }
        else{                                                   // if the prev is empty then the new node is first node
            *head=new_node;
        }
        return SUCCESS;
    }

    free(new_node);
    return POSITION_NOT_FOUND;
}