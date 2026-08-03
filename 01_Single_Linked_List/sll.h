#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node{										// structure
	int data;
	struct node *link;
}S_list;


int insert_at_last(S_list **head, int);					// inserts at last










int find_node(S_list *head, int key);
int insert_at_first(S_list **head, int);
int sl_delete_list(S_list **);
int sl_delete_last(S_list **);
int sl_delete_first(S_list **);
void print_list(S_list *head);

#endif
