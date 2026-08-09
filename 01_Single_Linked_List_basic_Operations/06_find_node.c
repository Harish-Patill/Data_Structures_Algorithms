#include "sll.h"
int find_node(S_list *head, int data){
	S_list *temp=head;                              // temp starts pointing to the same node as head
	
	int count=1;                                    // a count variable to keep track of the position
	
	if(head == NULL){                               // if list is empty, end
	    return FAILURE;
	}
	while(temp != NULL){                            // while temp is not equal to NULL, traverse
	    if(temp->data == data){                     // keep checking if the data from the link is the same as of the user given data
	        return count;                           // if YES, return count
	    }
	    count++;                                    
	    temp=temp->link;                            // update temp with next nodes address
	}
	
	return FAILURE;
	
}
