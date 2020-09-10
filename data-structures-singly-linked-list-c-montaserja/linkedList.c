
#include"linkedList.h"
#include<stdlib.h>
#include <stdio.h>


node* createList(int val)
{
	node *head;
	head = malloc(sizeof(node));
	head->val = val;
	head->next = NULL;
	return head;
}

void print_list(node *head) {
    node *current = head;

    while (current) {
        printf("%d", current->val);
        current = current->next;
        if(current)
        	printf("->");
    }
    printf("\n");
}

void push_back(node *head, int val) {
    node *current = head;
    while (current->next) {
        current = current->next;
	}
	current->next = malloc(sizeof(node));
    current->next->val = val;
    current->next->next = NULL;
}

void push_front(node **head, int val) {
    node *newNode;
    newNode = malloc(sizeof(node));

    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

int pop(node **head) {
    int val = -1;
    node *next = NULL;

    if (*head == NULL) {
        return -1;
    }

    next = (*head)->next;
    val = (*head)->val;
    free(*head);
    *head = next;

    return val;
}

int remove_node(node **head, int index) {
    int i = 0;
    int val;
    node *current = *head;
    node *temp = NULL;
    
	if(index == 0)
	{
		return pop(head);
	}
    for (i = 0; i < index-1; ++i) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp = current->next;
    val = temp->val;
    current->next = temp->next;
    free(temp);
    
    return val;
}

void reverse_list(node **head)
{
	node *current= *head;
	node *next = current->next;
	current->next = NULL;
	
	while(next)
	{
		node *temp = next->next;
		next->next = current;
		current = next;
		next = temp;
	}
	*head = current;
}

node* reverseList_recursion(node* head)
{
	node *temp;
	if(!head->next)
	{
		return head;
	}
	temp = reverseList_recursion(head->next);
	head->next->next = head;
	head->next = NULL;
	
	return temp;
}





















