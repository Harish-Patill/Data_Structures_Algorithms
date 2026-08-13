#include "arbitary_precision_calculator_header.h"
void addition(node *tail1, node *tail2, node **result_head, node **result_tail, int op1_len, int op2_len){
    int ans=0;
    int count=0;
        
    // case 1: if both the numbers are of same length
    if(op1_len == op2_len){                                                                         
        while((tail1 != NULL) && (tail2 != NULL)){ 
            ans=tail1->data + tail2->data + count;                                                  // storing ans
            if(ans>9){                                                                              // if the ans results in a carry, add the carry to the prev digit addition
                count=1;
                ans=ans%10;
                insert_at_first(result_head,result_tail,ans);                                       // add the unit digit to the list
            }
            else{
                count=0;
                insert_at_first(result_head,result_tail,ans);                                       // add the unit digit to the list
            }
            tail1=tail1->prev;                                                                      // update both the tail 1 and 2 to go to the previous        
            tail2=tail2->prev;
        }      
        if(count){                                                                                  // if a count variable is left even at the end, then add it to new node
            insert_at_first(result_head, result_tail, count);
        }                                           
    }
    
    // case 2: if the 1st operand is long
    if(op1_len>op2_len){
        while((tail1 != NULL) && (tail2 != NULL)){
            ans=tail1->data + tail2->data + count;                                                  // ans holds the ans
            if(ans>9){  
                count=1;                                                                            // if we get carry, add it to the next digits addition
                ans=ans%10;                                                                         
                insert_at_first(result_head,result_tail,ans);                                       // now add the unit digit from the ans to the list
            }
            else{
                count=0;                                                                            // if no carry, simply add the ans to the list
                insert_at_first(result_head,result_tail,ans);
            }
            tail1=tail1->prev;
            tail2=tail2->prev;
        }

        // drain the remaining digits of operand 1, still propagating carry
        while(tail1 != NULL){                                                                       // once there are remaining elements in the 1st list
            ans=tail1->data + count;                                                                // just go on adding them to the list with the count edge case
            if(ans>9){
                count=1;
                ans=ans%10;
                insert_at_first(result_head,result_tail,ans);
            }
            else{
                count=0;
                insert_at_first(result_head,result_tail,ans);
            }
            tail1=tail1->prev;
        }

        if(count){                                                                                  // if a count variable is left even at the end, then add it to new node
            insert_at_first(result_head, result_tail, count);
        }
    }
    
    // case 3: if the 2nd operand is long
    if(op2_len>op1_len){
        while((tail1 != NULL) && (tail2 != NULL)){
            ans=tail1->data + tail2->data + count;
            if(ans>9){
                count=1;
                ans=ans%10;
                insert_at_first(result_head,result_tail,ans);
            }
            else{
                count=0;
                insert_at_first(result_head,result_tail,ans);
            }
            tail1=tail1->prev;
            tail2=tail2->prev;
        }

        // drain the remaining digits of operand 2, still propagating carry
        while(tail2 != NULL){
            ans=tail2->data + count;
            if(ans>9){
                count=1;
                ans=ans%10;
                insert_at_first(result_head,result_tail,ans);
            }
            else{
                count=0;
                insert_at_first(result_head,result_tail,ans);
            }
            tail2=tail2->prev;
        }

        if(count){
            insert_at_first(result_head, result_tail, count);
        }
    }
}