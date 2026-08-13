#include "arbitary_precision_calculator_header.h"

int subtraction(node *head1, node *head2, node *tail1, node *tail2, node **result_head, node **result_tail, int op1_len, int op2_len){
    int ans=0;
    int largest;

    // case 1: if both the numbers are of same length
    if(op1_len == op2_len){              
        
        largest = compare_magnitude(head1, head2);
        if((largest == 1) || (largest == 0)){
            while((tail1 != NULL) && (tail2 != NULL)){
                if((tail1->data) >= (tail2->data)){
                    ans=tail1->data - tail2->data;   
                    insert_at_first(result_head,result_tail,ans);
                }
                if((tail1->data) < (tail2->data)){
                    tail1->data=tail1->data+10;
                    tail1->prev->data=(tail1->prev->data)-1;
                    
                    ans=tail1->data - tail2->data;   
                    insert_at_first(result_head,result_tail,ans);
                }
                tail1=tail1->prev;
                tail2=tail2->prev;
            }
            return POSITIVE;
        }
        if(largest == 2){
            while((tail1 != NULL) && (tail2 != NULL)){
                if((tail2->data) >= (tail1->data)){
                    ans=tail2->data - tail1->data;   
                    insert_at_first(result_head,result_tail,ans);
                }
                if((tail2->data) < (tail1->data)){
                    tail2->data=tail2->data+10;
                    tail2->prev->data=(tail2->prev->data)-1;
                    
                    ans=tail2->data - tail1->data;   
                    insert_at_first(result_head,result_tail,ans);
                }
                tail1=tail1->prev;
                tail2=tail2->prev;
            }
            return NEGATIVE;
        }
    }
    
    // case 2: if the 1st operand is long
    if(op1_len>op2_len){
        while((tail1 != NULL) && (tail2 != NULL)){
            if((tail1->data) >= (tail2->data)){
                ans=tail1->data - tail2->data;   
                insert_at_first(result_head,result_tail,ans);
            }
            if((tail1->data) < (tail2->data)){
                tail1->data=tail1->data+10;
                tail1->prev->data=(tail1->prev->data)-1;
                
                ans=tail1->data - tail2->data;   
                insert_at_first(result_head,result_tail,ans);
            }
            tail1=tail1->prev;
            tail2=tail2->prev;
        }

        // drain the remaining digits of operand 1 to the ans list
        while(tail1 != NULL){     
            // once there are remaining elements in the 1st list
            
            if(tail1->data < 0){                          // a borrow from an earlier step left this digit negative
                tail1->data = tail1->data + 10;
                if(tail1->prev != NULL){
                    tail1->prev->data = tail1->prev->data - 1;
                }
            }        
            ans=tail1->data;                                                                // just go on adding them to the list with the count edge case
            insert_at_first(result_head,result_tail,ans);
            tail1=tail1->prev;
        }
        return POSITIVE;
    }

    // case 3: if the 2nd operand is long
    if(op2_len>op1_len){
        while((tail1 != NULL) && (tail2 != NULL)){
            if((tail2->data) >= (tail1->data)){
                ans=tail2->data - tail1->data;   
                insert_at_first(result_head,result_tail,ans);
            }
            if((tail2->data) < (tail1->data)){
                tail2->data=tail2->data+10;
                tail2->prev->data=(tail2->prev->data)-1;
                
                ans=tail2->data - tail1->data;   
                insert_at_first(result_head,result_tail,ans);
            }
            tail1=tail1->prev;
            tail2=tail2->prev;
        }

        // drain the remaining digits of operand 2, to the ans list
        while(tail2 != NULL){                                                                       // once there are remaining elements in the 1st list
            if(tail2->data < 0){                                                            // a borrow from an earlier step left this digit negative
                tail2->data = tail2->data + 10;
                if(tail2->prev != NULL){
                    tail2->prev->data = tail2->prev->data - 1;
                }
            }
            ans=tail2->data;                                                                // just go on adding them to the list with the count edge case
            insert_at_first(result_head,result_tail,ans);
            tail2=tail2->prev;
        }
        return NEGATIVE;
    }
}