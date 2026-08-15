#include "sll.h"

int insert_at_last(Slist **head, data_t data){
	Slist *temp = *head;

	// create new node 
	Slist *new = malloc(sizeof(Slist));
	if(!new){
		return FAILURE;
	}

	// if new node created, update data + link 
	new->data = data;
	new->link = NULL;

	// If list is empty, add new node to first position
	if(*head == NULL){
		*head=new;
		return SUCCESS;
	}
	
	// traverse to next node check next node is present or not
	while (temp->link != NULL){
		temp = temp->link;
	}

	// establish the link between last and new node
	temp->link = new;

	return SUCCESS;
}