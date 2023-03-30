
# Code design

## Data
1. input
	- [inputString] a char array, a string no space
	- [firstChar] a char, the char is replaced
	- [secondChar] a char, the char to replace

2. output
	- print [inputString] after being replaced [firstChar] with [secondChar]

## Code flow
1. main
	> `Enter` string [inputString]

	> `Enter` [firstChar] and [secondChar]

	> `Call` function to replace [firstChar] to [secondChar] in the [inputString]

	> `Print` the [inputString]

2. replace_char
	- a function to replace [firstChar] with [secondChar] in the [inputString]

	> `Take` [inputString] [firstChar] [secondChar]

	<!-- go through each char in string -->
	> `For each` [c] in [inputString]:

		> `If` [c] is equal to [firstChar]:

			> `Assign` [c] to [secondChar]
