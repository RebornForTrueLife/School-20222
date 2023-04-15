
# Exercise on Data structure

1. Single linked List
	1. Given a linked list of integers sorted from smallest to largest, and a pointer to a single node containing
an integer, insert the node in the linked list so that it remains sorted
		- Problem: insert a new node into a sorted single linked list

		- Sol:

			> `TAKE` list, newNode

			> Node* node = list->head;

			<!-- travel from head to the first node that have value Equal or Greater than value of newNode-->
			> `WHILE` node != NULL

				> `IF` (node->data) >= (newNode->data)

					
