#include "sll.h"
int main(){
	int option, data, ret;

	Slist *head = NULL; //initialize the header to NULL

	printf("1. Insert sorted\n");
	printf("2. Print list\n");
	printf("3. Exit\n");
	printf("Enter Your choice : ");
	while (1){
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
				print_list(head);
				break;

			case 3: return SUCCESS;
			default: printf("Enter proper choice !!\n");
				break;
		}
	}
	return SUCCESS;
}