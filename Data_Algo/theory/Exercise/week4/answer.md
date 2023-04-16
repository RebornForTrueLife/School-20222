
# Exercise on Data structure


1. Single linked List
	1. Given a linked list of integers sorted from smallest to largest, and a pointer to a single node containing
an integer, insert the node in the linked list so that it remains sorted
		- Problem: insert a new node into a sorted single linked list

		- Sol:

			> `TAKE` list, newNode

			> Node* node = list->head;

			> Noe* preNode = NULL

			<!-- travel from head to the first node that have value Equal or Greater than value of newNode-->
			> `WHILE` node != NULL

				<!-- find insert location -->
				> `IF` (node->data) >= (newNode->data)
					<!-- insert before current node -->
					> `IF` prevNode != NULL

						> `Assign` prevNode->next = newNode

					> `Assign` newNode->next = node

				> `Assign` prevNode = node

				> `Assign` node = node->next

	2. Given a nonempty list, delete the last node and set the new last link to null.
		- Sol
			> `Take` list

			> `Declare` Node* node = list->head

			> `Declare` Node* prevNode = NULL

			> `While` node != NULL

				<!-- Find last node -->
				> `If` node->next == NULL

					> `If` prevNode != NULL

						> `Assign` prevNode->next = NULL

					> `Free` node

				> `Assign` prevNode = node

				> `Assign` node = node->next

	3. Given a null terminated linked list, rearrange its nodes into two lists: <first node, third node, fifth
		node, ...> and <second node, fourth node, sixth node, ...>. Do not allocate any new nodes.
		- Sol
			> `Take` list

			> `Declare` Node* head = node1

			> `Declare` Node* headNext = node1->next

			> `Declare` Node* node = node1

			> `Declare` Node* next = node1->next

			<!-- Check if list has only one node -->
			> `If` next == NULL
				<!-- Do nothing -->
				> `Exit`

			<!-- travel to the end of list -->
			> `While` next != NULL

				<!-- Each travel, link the current node to the second node ahead -->
				> `Assign` node->next = next->next

				> `Assign` node = next

				> `Assign` next = node->next

			<!-- The list is separated into 2 list: even index and odd index -->
			<!-- Link last node of odd list to  The 2nd node -->
			> `Assign` node = head

			> `While` TRUE

				> `If` node->next == NULL

					> `Assign` node->next = headNext

					> `Break`

				> `Assign` node = node->next

	4. Given a null-terminated linked list, reverse the order of its nodes
		- Sol
			> `Take` list

			> `Declare` Node* node = list->head

			<!-- check if list is empty -->
			> `If` node == NULL

				> `Exit`

			> `Declare` Node* next = node->next;

			<!-- IF list has 2 nodes -->
			> `If` next == NULL

				> `Assign` node->next = NULL

				> `Assign` next->next = node

				> `Exit`

			<!-- WHen list has equal or more than 3 nodes -->
			> `Declare` Node* nextD = next->next

			<!-- travel list -->
			> `While` TRUE

				> `Assign` next->next = node

				<!-- terminate condition -->
				> `If` nextD == NULL

					> `Break`

				> `Assign` node = next

				> `Assign` next = nextD

				> `Assign` nextD = nextD->next

			<!-- link head -->
			> `Assign` list->head->next = NULL

			> `Assign` list->head = next


2. Exercise on Stack
	1. (a) A letter means push and an asterisk means pop in the following sequence. Give the sequence of
	values returned by the pop operations when this sequence of operations is performed on an initially
	empty stack.
		> Operate: `EAS*Y*QUE***ST***IO*N***`

			```
				E A S
				E A 
				E A Y
				E A Q U E 
				E A
				E A S T 
				E
				E I O
				E I
				E I N 
				<empty>
			```

		> Or number of letter = 12 And number of asterisk is 12 --> number of PUSH == number of POP

		> Result of POP stack: ERROR: STACK is empty

	2. (b) Suppose that an intermixed sequence of push and pop operations are performed. The pushes push the
			integers 0 through 9 in order; the pops print out the return value. Which of the following sequences
			could not occur?

		> PUSHes + POPes : `0 1 2 3 4 5 6 7 8 9`
		
		- Check each case (4):  DENOTE: number mean push, asterisk mean pop

			> (a) `4 3 2 1 0 9 8 7 6 5`

				> sol: `0 1 2 3 4 * * * * * 5 6 7 8 9 * * * * *`

			> (b) `4 6 8 7 5 3 2 9 0 1`

				> `0 1 2 3 4 * 5 6 * 7 8 * ERROR`: in order to have 5, we need to pop 7 and 6 first

			> (c) `2 5 6 7 4 8 9 3 1 0`

				> sol: `0 1 2 * 3 4 5 * 6 * 7 * * 8 * 9 * *  * *`

			> (d) `4 3 2 1 0 5 6 7 8 9`

				> sol: `0 1 2 3 4 * * * * * 5 * 6 * 7 * 8 * 9 *`

	3. Give a pseudo-code that reads in a positive integer and prints the binary representation of that
		integer. Hint: divide the integer by 2.

		> `Take` number

		> `Declare` Stack stack

		> `While` TRUE

			> `If` number == 0

				> `Break`

			> `Push` (number % 2) into stack

			> `Assign` number = number / 2

		<!-- when number is 0 -->
		> `If` stack is EMPTY

			> `Print` number

			> `Exit`

		> `While` stack is NOT EMPTY

			> `Assign` result = (`Pop` stack)

			> `Print` result

		> `Exit`

	4. (d) Consider the following sequence of stack commands: push(a), push(b), push(c), pop(), push(d),
			push(e), pop(), pop(), pop(), pop().
			Change the position of the pop() commands in the above sequence so that the items are popped in
			the following order: b,d,c,a,e. You are not allowed to change the ordering of the push commands
		> Push `a b c d e`, Denote asterisk mean Pop

		> Prob: insert asterisk to sequence of push to get the pop result: `b d c a e`

		> Sol: `a b * c d * * * e *`

3. Exercise on queue
	**DENOTE: asterisk mean dequeue**

	1. (a) Consider the following sequence of stack operations: push(d), push(h), pop(), push(f), push(s),
			pop(), pop(), push(m). Suppose we replace the push and pop operations with enqueue and dequeue
respectively. 
		- Prob: (1) What would be the sequence of dequeued values, 
				(2) and what would be the final state of the queue?
		- Sol
			> (1) Sequence operation: `d h * f s * * m` 

				> Sequence of dequeue result: `d h f`

				> QUeue final state: `s m`

	2. Show how to implement a stack using two queues. 
		- prob: 
			> (1) Describe how the operations push and pop will be implemented using the queue operations enqueue() and dequeue(). 
			
			> (2) Give the running time of each stack operation.
		- Sol 
			> (1) denote: we have stack and queue1, queue2

				> PUSH [ele]
					1. `Choose` queue containing elements (or random if both queue is Empty)
						> `Assign` queue found to queueActive, other as queueDeactive
					2. `Enqueue` [ele] to queueActive

				> POP
					1. `Check` if both queues are empty
						> TRUE: `Warning` stack is empty

						> `Exit`
					2. Get last element in queueActive

						> `While` number_of_elements_in_queueActive != 1

							> `Dequeue` queueActive, `Assign` result to [result]

							> `Enqueue` [result] to queueDeactive 

						> `Dequeue` queueActive, `Assign` result to [result]

						> `Mark` queueActive to queueDEactive, and vice versa

						> `return` [result]

			> (2) Calculate running time 
				- **Denote size of push is n**

				> For `Push`

					> Elemental operation: any --> t(n) = O(1)

				> For `Pop`

					> Elemental operation: `While number_of_elements_in_queueActive != 1`

					> [Number of times of EO] = [number of element in queueActive]; 

					> t(n) = O(n)

	3. Q = `[44][55R][ ][ ][F][11][22][33]`
		- Prob: given A = [a b c d e f g h] --> equals: A = [97 98 99 100 101 102 103 104]
			> (1) Write the result of each entry of Q after the execution
			> (2) what is the final value of pointer of Rear and Front

		- Sol
			> (1) 

				> [i] iterate from 0 to 7

					> i = 0: `dequeue` --> `[44][55R][ ][ ][ ][-1F][22][33]`
					
					> i = 1: `dequeue` --> `[44][55R][ ][ ][ ][-1][-1F][33]`

					> i = 2: `dequeue` --> `[44][55R][ ][ ][ ][-1][-1][-1F]`

					> i = 3: `dequeue` --> `[-1F][55R][ ][ ][ ][-1][-1][-1]`

					> i = 4: `dequeue` --> `[-1][-1RF][ ][ ][ ][-1][-1][-1]`

					> i = 5: `dequeue` --> Q is Empty

					> i = 6: `dequeue` --> Q is Empty

					> i = 7: Error due to there is no A[i + 1]

			> (2)

				> Front points to memory location 1

				> Rear points to memory location 1


