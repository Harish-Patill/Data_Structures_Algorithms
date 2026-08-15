#include "sll.h"
int main(){
	char check_char;
	int option, data, pos;

	Slist *head = NULL; //initialize the header to NULL

	printf("1. Insert at last\n");
	printf("2. Find Mid\n");
	printf("3. Print list \n");
	printf("4. Exit\n");
	printf("Enter the Option : ");

	while(1){
		scanf("%d", &option);

		switch (option){
			case 1:{
				printf("Enter the number that you want to insert at last: ");
				scanf("%d", &data);

				// insert_at_last function call
				if (insert_at_last(&head, data) == FAILURE){ 	
					printf("INFO : Insert last failed\n");
				}
			}
			break;

			case 2:
				printf("Enter the Number to find the last : ");
				scanf("%d", &pos);
				
				int key;
				if((key = find_nth_last(head, pos, &data)) == FAILURE){
				    printf("INFO : Position not found\n");
				}
				else if(key == LIST_EMPTY){
				    printf("INFO : List is empty");
				}
				else{
				    printf("%dth last is %d\n", pos, data);
			    }
			break;

			case 3:
				// print list function call
				print_list(head);
				break;

			case 4:
				return SUCCESS;

			default:
				printf("Invalid Option\n");
		}
	}
	return SUCCESS;
}