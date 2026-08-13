#include "arbitary_precision_calculator_header.h"

int list_length(node *head){
	int count = 0;
	while(head != NULL){
		count++;
		head = head->next;
	}
	return count;
}

int main(int argc, char *argv[]){
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *result_head = NULL, *result_tail = NULL;
	int i,j; 

	// checking CLA count
	if(argc != 4){																			// need exactly 4 command line arguments
		printf("Invalid number of Command Line Arguments\n");
		return FAILURE;
	}

	// validating the operator
	if(argv[2][1] != '\0'){																	// operator must be exactly one character, to overcome ++,+9,-61 etc
		printf("Invalid Operator, enter a single valid Operator\n");
		return FAILURE;
	}
	if(argv[2][0] != '+' &&																	// checking if the operator is +, -, * or /
	   argv[2][0] != '-' && 
	   argv[2][0] != 'x' &&
	   argv[2][0] != 'X' &&
	   argv[2][0] != '/'){
		printf("Invalid Operator\n");
		return FAILURE;
	}

	// validating the operands
	i=(argv[1][0]=='+' || argv[1][0]=='-' )? 1:0;											// operand 1 checking
	if(argv[1][i] == '\0'){																	// nothing after optional sign, or empty string
		printf("Operand 1 is not a valid number\n");
		return FAILURE;
	}
	while(argv[1][i] != '\0'){
		if(!isdigit(argv[1][i])){
			printf("Operand 1 is not a valid number\n");
			return FAILURE;
		}
		i++;
	}

	
	j=(argv[3][0]=='+' || argv[3][0]=='-' )? 1:0;											// operand 2 checking
	if(argv[3][j] == '\0'){																	// nothing after optional sign, or empty string
		printf("Operand 2 is not a valid number\n");
		return FAILURE;
	}
	while(argv[3][j] != '\0'){
		if(!isdigit(argv[3][j])){
			printf("Operand 2 is not a valid number\n");
			return FAILURE;
		}
		j++;
	}
	
    char oper = argv[2][0];

	int operand_1_str_len = strlen(argv[1]);
	int operand_2_str_len = strlen(argv[3]);

	insert_operand(&head1, &tail1, argv[1], operand_1_str_len);
	insert_operand(&head2, &tail2, argv[3], operand_2_str_len);

	remove_leading_zeros(&head1, &tail1);   // len param no longer needed inside this fn if you're recomputing it next — see note below
	remove_leading_zeros(&head2, &tail2);

	int operand_1_len = list_length(head1);       // the true, sign-stripped, zero-stripped digit count
	int operand_2_len = list_length(head2);
	
	// operand testing
	// printf("%d %d",operand_1_len,operand_2_len);

    switch(oper){
	case '+':
	    addition(tail1, tail2, &result_head, &result_tail,operand_1_len,operand_2_len);
		print_list(result_head);
	    break;
		
	case '-':
		if(subtraction(head1, head2,tail1, tail2, &result_head, &result_tail,operand_1_len,operand_2_len) == POSITIVE){
			print_list(result_head);
		}
		else{
			printf("-");
			print_list(result_head);
		}
	    break;

	case 'x':
	case 'X':
	    break;

	case '/':
	    break;

	default:
	    printf("Invalid operator\n");
    }

	return SUCCESS;
}

