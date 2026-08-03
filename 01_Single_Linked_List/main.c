#include "sll.h"
int main(){
	int option, data, key;

	S_list *head = NULL; //initialize the header to NULL

	printf("1. Insert last\n");
	printf("2. Insert first\n");
	printf("3. Delete Last\n");
	printf("4. Delete first\n");
	printf("5. Delete list\n");
	printf("6. Find node\n");
	printf("7. Print list\n");
	printf("8. Exit\n");
	
	while (1){
		printf("Enter your choice : ");
		scanf("%d", &option);
		
		switch (option){
			case 1:
				printf("Enter the number that you want to insert at last: ");
				scanf("%d", &data);
			
                
				if (insert_at_last(&head, data) == FAILURE){							// here we are doing pass by referece for head, as we need to modify the address the head is pointing to.
					printf("INFO : Insertion Failure\n");
				}
				break;

			case 2:
				printf("Enter the element you have to insert at the first : ");
				scanf("%d", &data);
				
				if (insert_at_first(&head, data) == -1){
					printf("INFO : Insertion Failure\n");
				}
				break;

			case 3:
				/* Delete a last link*/
				if (sl_delete_last(&head) == -1)
				{
					printf("INFO : Delete last Failure\nList is empty\n");
				}
				else
				{
				    printf("INFO : Delete last successfull\n");
				}
			
				break;
			case 5:
				/* Delete list */
				if (sl_delete_list(&head) == -1)
				{
					printf("INFO : Delete list Failure\nList is empty\n");
				}
				else
				{
					printf("INFO : Delete list Successfull\n");
				}
	
				break;
			case 4:
				/*To delete first node */
				if (sl_delete_first(&head))
				{
					printf("INFO : Delete first Failure\n List is empty\n");
				}
				else
				{
				    printf("INFO : Delete first successfull\n");
				}
				break;
			case 6:
				printf("Enter the key to find : ");
				scanf("%d", &key);
				int count;
				if ((count = find_node(head, key)) == FAILURE)
				{
					printf("INFO : Failure\nList is empty or Key not found\n");
				}
				else
				{
					printf("%d found in the list at the position %d\n", key, count);
				}
		
				break;
			case 7:
				/* print list function call*/
				print_list(head);
				break;
	
			case 8:
				return SUCCESS;

			default: printf("Enter proper choice !!\n");
				break;
		}
	    

	}
}

