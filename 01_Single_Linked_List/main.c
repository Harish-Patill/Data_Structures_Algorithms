#include "sll.h"
int main(){
	int option, data, key, ndata, gdata, ret, n;
	
	S_list *head = NULL; // initialize the header to NULL

	printf("1. Insert last\n");
	printf("2. Insert first\n");
	printf("3. Delete Last\n");
	printf("4. Delete first\n");
	printf("5. Delete list\n");
	printf("6. Find node\n");
	printf("7. Insert after\n");
	printf("8. Insert before\n");
	printf("9. Insert Nth\n");
	printf("10.Delete element\n");
	printf("11.Print list\n");
	printf("12.Exit\n");
	
	while (1){
		printf("Enter your choice : ");
		scanf("%d", &option);
		
		switch (option){
			case 1:		// insert at last
				printf("Enter the number that you want to insert at last: ");
				scanf("%d", &data);
			
				if(insert_at_last(&head,data) == FAILURE){		// here we are doing pass by referece for head, as we need to modify the address the head is pointing to.
					printf("INFO : Insertion Failure\n");
				}
				break;
	
			case 2:		// insert first
				printf("Enter the element you have to insert at the first: ");				
				scanf("%d", &data);
				
				if(insert_at_first(&head,data) == -1){
					printf("INFO : Insertion Failure\n");
				}
				break;
	
			case 3:		// delete last
				if (sl_delete_last(&head) == -1){									       
					printf("INFO : Delete last Failure\nList is empty\n");	
				}
				else{
					printf("INFO : Delete last successfull\n");
				}
			
				break;
				
			case 4:		// To delete first node
				if (sl_delete_first(&head)){												
					printf("INFO : Delete first Failure\n List is empty\n");
				}
				else{
					printf("INFO : Delete first successfull\n");
				}
	
				break;
	
			case 5:		// delete whole list
				if (sl_delete_list(&head) == -1){											
					printf("INFO : Delete list Failure\nList is empty\n");
				}
				else{
					printf("INFO : Delete list Successfull\n");
				}
	
				break;
	
			case 6:		// find an key
				printf("Enter the key to find: ");											
				scanf("%d", &key);
	
				int count;
				if((count=find_node(head, key)) == FAILURE){
					printf("INFO : Failure\nList is empty or Key not found\n");
				}
				else{
					printf("%d found in the list at the position %d\n", key, count);
				}
		
				break;
			
			case 7:
				printf("Enter the value of gdata : ");
				scanf("%d", &gdata);
	
				printf("Enter the New data that you want to insert after %d : ", gdata);
				scanf("%d", &ndata);
	
				if((ret = sl_insert_after(&head, gdata, ndata)) == DATA_NOT_FOUND){ //pass by reference
					printf("INFO : %d is not found at the list\n", gdata);
				}
				else if (ret == LIST_EMPTY){
					printf("INFO : List is empty\n");
				}
	
				break;
	
			case 8:
				printf("Enter the value of gdata : ");
				scanf("%d", &gdata);
	
				printf("Enter the ndata that you want to insert before %d : ", gdata);
				scanf("%d", &ndata);
	
				if ((ret = sl_insert_before(&head, gdata, ndata)) == DATA_NOT_FOUND){
					printf("INFO %d is not found at the list\n", gdata);
				}
				else if (ret == LIST_EMPTY){
					printf("INFO : List is empty\n");
				}
	
				break;
	
			case 9:
				printf("Enter the node number : ");
				scanf("%d", &n);
	
				printf("Enter the number that you want to insert %dth position : ", n);
				scanf("%d", &ndata);
	
				if((ret = sl_insert_nth(&head, ndata, n)) == POSITION_NOT_FOUND){
					printf("INFO : %d Position not found\n", n);
				}
				else if (ret == LIST_EMPTY){
					printf("INFO : List is empty\n");
				}
				else{
					printf("%d is successfully inserted at the position %d\n", data, n);
				}
	
				break;
	
			case 10:
				printf("Enter the element you need to delete : ");
				scanf("%d", &ndata);
	
				if((ret = sl_delete_element(&head, ndata)) == DATA_NOT_FOUND){
					printf("INFO : Element is not found\n");
				}
				else if (ret == FAILURE){
					printf("INFO : List is empty\n");
				}
				else{
					printf("Element Successfully deleted\n");
				}
				break;
	
			case 11:
				print_list(head);
				break;
	
			case 12:
				return SUCCESS;
	
			default: printf("Enter proper choice !!\n");
				break;
			
		}
	}
}