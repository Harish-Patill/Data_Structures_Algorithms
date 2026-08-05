#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND -2
#define LIST_EMPTY -4
#define POSITION_NOT_FOUND -3

typedef struct node{										// structure
	int data;
	struct node *link;
}S_list;


int insert_at_last(S_list **head, int);					
int insert_at_first(S_list **head, int);				
int sl_delete_last(S_list **);
int sl_delete_first(S_list **);
int sl_delete_list(S_list **);
int find_node(S_list *head, int key);
void print_list(S_list *head);







int sl_insert_after(S_list **head, int , int);
int sl_insert_before(S_list **head, int , int );
int sl_insert_nth(S_list **head, int , int);
int sl_delete_element(S_list **head, int);


#endif








