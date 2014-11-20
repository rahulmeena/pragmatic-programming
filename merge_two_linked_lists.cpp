/*
Program to merge a linked list into another linked list 
at alternate positions.
*/


//#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

void push_into_list(struct node **head, int new_data)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->next = (*head);
	*head = temp;
}

void merge_lists(struct node **primary, struct node **secondary)
{
	struct node *curr_p, *curr_s, *next_s;
	curr_p = (*primary);
	curr_s = (*secondary);
	
	while(curr_p != NULL && curr_s != NULL)
	{
		next_s = curr_s->next;
		curr_s->next = curr_p->next;
		curr_p->next = curr_s;
		curr_p = curr_s->next;
		curr_s = next_s;
		
	}	
	
	*secondary = curr_s;
	
}

void print_list(struct node* list)
{
	while(list!=NULL)
	{
		printf("%d ",list->data);
		list = list->next;
	}
}

int main()
{
	struct node *p = NULL,*q = NULL;
	
	push_into_list(&p,3);
	push_into_list(&p,2);
	push_into_list(&p,1);
	
	push_into_list(&q,8);
	push_into_list(&q,7);
	push_into_list(&q,6);
	push_into_list(&q,5);
	push_into_list(&q,4);
	
	printf("First Linked List:\n");
	print_list(p);
	printf("\nSecond Linked List:\n");
	print_list(q);
	
	merge_lists(&p,&q);
	
	printf("\nModified First Linked List:\n");
	print_list(p);
	printf("\nModified Second Linked List:\n");
	print_list(q);
	
	return 0;
}
