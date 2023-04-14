
# Code design

## Problem: there are many similar query --> create a list of unique query
	- using an array to store unique query
	- need to access query fast enough to check new query if it is in the array or not
		- Can not check by travel each element: too slow
		- using query account as index: large memory (choose)

## Implement
0. main
	> `declare` an array [uni], size = 1000000, element type: Query address

	> `Initialize` all element value of [uni] to NULL

	> `declare` an array [queryList], size = 1000000, element type: Query address

	> `Read each` [queryAccount] in query list:

		> `Convert` [queryAccount] to [accNumber]

		> `Check` [uni][accNumber] is NULL:

			> `if` TRUE: 

				> `Allocate` memory for new Query: [newQuery]

				> `Add` data to [newQuery]

				> `Assign` address of [newQuery] to [uni][accNumber]

			

		> `Put` [uni][accNumber] to [queryList]

	> `Calculate` total transaction for each [query] in [uni]

	> `Print` total transaction by the [queryList]



