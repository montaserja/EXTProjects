

#include"linkedList.h"

int main()
{
	node *head = createList(1);
	print_list(head);
	push_back(head,2);
	push_back(head,3);
	push_back(head,4);
	push_back(head,5);
	push_back(head,6);
	print_list(head);
	push_front(&head,0);
	print_list(head);
	pop(&head);
	print_list(head);
	remove_node(&head,0);
	print_list(head);
	reverse_list(&head);
	print_list(head);
	head = reverseList_recursion(head);
	print_list(head);
	
	

	return 0;
}
