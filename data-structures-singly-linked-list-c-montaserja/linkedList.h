#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

typedef struct node {
    int val;
    struct node * next;
}node;

node* createList(int val);
void print_list(node *head);
void push_back(node * head, int val);
void push_front(node **head, int val);
int pop(node **head);
int remove_node(node **head, int index);
void reverse_list(node **head);
node* reverseList_recursion(node* head);


#endif /* __LINKEDLIST_H__ */
