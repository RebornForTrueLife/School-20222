
# Code design

## Data
1. input
	- [firstString] a string to be replaced
	- [secondString] a string to replace
	- [text] a string where [firstString] is replaced with [secondString]

2. output
	- print [newText] which is [text] after being replaced

## Code flow
1. main
	> `Enter` [firstString]

	> `Enter` [secondString]

	> `Enter` [text]

	> `Call ` function to replace [firstString] with [secondString] in [text]

	> `Print` [text] after being replaced

2. replace_string
	- a function to replace [firstString]with [secondString] in [text]
	- using recurrence:
		- stop: 
			- NO firsString exist in [text]
			- startIndex >= size of [text]
		- search [text] from [startIndex ... end]
	- Data
		- [startIndex] : index in [text], initial value is 0. Which will be the NEXT INDEX after last character of replaced string.

	> `Take` [text] [newText] [firstString] [secondString] [startIndex]

	> `If` [startIndex] >= len([text]): `RETURN`

	> `Assign` [foundIndex] = (`Call` <find_string> to find the index of [firstString] in [text]--- from [startIndex] to end of [text])

	<!-- if firstString exist in [text][startIndex...end] -->
	> `If` [foundIndex] Not equal to -1:

		> `Concatenate` substring: [text][startIndex, foundIndex - 1] to [newText]

		> `Concatenate` [secondString] to [newText]

		> `Call` <ITSELF>: [text], [newText], [firstString], [secondString], ([foundIndex] + len([firstString]))

	> `ELSE`:

		> `Concatenate` substring: [text][startIndex..end] to [newText]


3. find_string
	- a function to find a first string in second string, return position of first string in the second string if second string contain first string, return -1 vice versa. Start seaching from given position to the end
	- using recursive:
		- stop: startIndex > size of [text]; NOT find firstChar of [keyString] in [text]
		- break: startIndex increases to the endIndex

	> `Take` [keyString] [text] [startIndex]

	> `Check` if [startIndex] >= [size of [text]]:

		> `If` TRUE: `return` -1

	<!-- look for first char of [keyString] in the [text] from [startIndex] -->
	> `Assign` [firstIndex] = `Call` <find_char>: [firstChar of [keyString]] of [text] from [startIndex]

	> `if` [firstIndex] is Found: 

		> `Check` if [keyString] exist in [text] at [firstIndex]:

			> `If` TRUE: `return` [firstIndex]

			> `If` FALSE: `return` `Call` <ITSELF>: [keyString] [text] ([firstIndex] + 1)

	> `Else`:

		> `Return` -1

