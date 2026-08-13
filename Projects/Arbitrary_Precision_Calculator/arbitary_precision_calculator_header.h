#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define SUCCESS		1
#define FAILURE		0

#define POSITIVE	1
#define NEGATIVE	0

#define SAME		0
#define OPERAND1	1
#define OPERAND2	2

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

// void addition(node *tail1, node *tail2, node **headR, node **tailR);
void addition(node *tail1, node *tail2, node **result_head, node **result_tail, int op1_len, int op2_len);
void subtraction(node *tail1, node *tail2, node **result_head, node **result_tail, int op1_len, int op2_len);
void multiplication(node *tail1, node *tail2, node **headR, node **tailR);
void division(node *head1, node *head2, node **headR, node **tailR);

int cla_validation(int argc, char *argv[]);
void create_list(char *opr, node **head, node **tail);

// int insert_first(node **head, node **tail, int data);
int insert_at_first(node **head, node **tail, int data);

int insert_last(node **head, node **tail, int data);
int delete_list(node **head, node **tail);
void print_list(node *head);

int compare_list(node *head1, node *head2);
int list_len(node *head);
void remove_pre_zeros(node **head);

void insert_operand(node **head, node **tail, char *operand, int len);

#endif
