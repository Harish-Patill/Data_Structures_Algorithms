#include "sll.h"
int main(){
	int option, data, ret;

	Slist *head = NULL; //initialize the header to NULL

	printf("1. Insert sorted\n");
	printf("2. Find loop\n");
	printf("3. Create loop\n");
	printf("4. Print list\n");
	printf("5. Exit\n");
	
	printf("Enter Your choice : ");
	while(1){
		scanf("%d", &option);

		switch (option){
			case 1:
				printf("Enter the data to be inserted : ");
				scanf("%d", &data);
				if (insert_sorted(&head, data) == -1){
					printf("INFO : Insert sorted failure\n");
				}
			break;

			case 2:
				// Function to find the loop
				if ((ret = find_loop(head)) == LOOP_NOT_FOUND){
					printf("INFO : Loop is not found\n");
				}
				else if (ret == LIST_EMPTY){
					printf("INFO : List is empty\n");
				}
				else
					printf("INFO : Loop found\n");
			break;
				
			case 3:
				printf("Enter a data to create the loop : ");
				scanf("%d", &data);

				int ret;
				// insert_at_last function call
				if((ret = create_loop(&head, data)) == LIST_EMPTY){ //pass by reference
					printf("INFO : List is empty\n");
				}
				else if(ret == DATA_NOT_FOUND){
					printf("INFO : %d not found at the list\n", data);
				}
				else{
					printf("INFO : Loop created successfully\n");
				}
			break;	

			case 4:
				print_list(head);
			break;

			case 5: return SUCCESS;
			
			default: printf("Enter proper choice !!\n");
			break;
		}
	}
	return SUCCESS;
}