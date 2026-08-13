#include "arbitary_precision_calculator_header.h"
int compare_magnitude(node *head1, node *head2){
    // Assumes head1 and head2 point to digit-lists of EQUAL length,
    // stored most-significant digit at head, least-significant at tail.
    // Walks both lists together from the head (most significant digit first).
    while(head1 != NULL){
        if((head1->data) > (head2->data)) return 1;   // first differing digit favors list 1 -> operand 1 is bigger, no need to check further digits
        if((head1->data) < (head2->data)) return 2;   // first differing digit favors list 2 -> operand 2 is bigger
        // digits equal at this position -> this digit alone can't decide it, move to the next (less significant) digit
        head1=head1->next;
        head2=head2->next;
    }
    return 0;   // walked every digit without finding any difference -> the two numbers are identical
}


// When two numbers have the same digit count, the first digit 
// (from the most significant end) where they differ is the only digit
// that matters for deciding which is bigger, everything before it was tied,
// and everything after it is lower place value and can't overturn that difference. 
// So compare_magnitude just walks both lists head-to-tail in lockstep and returns the instant 
// it finds a difference; if it reaches the end with no difference found, the numbers are equal.