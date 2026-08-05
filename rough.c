
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