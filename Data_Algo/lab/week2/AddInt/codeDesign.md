
# Code design

## Data
1. input
	- [stringInt1], [stringInt2]: 2 integer in string format
2. output
	- [stringSum] : sum of 2 integer in string format
3. used
	- CONST
		- BLOCK_SIZE : we divide string integer into set of blocks, each block has BLOCK_SIZE number of characters


## Code flow
1. main
	> `enter` [stringInt1] [stringInt2]

	> `Add` 2 string integer, `Assign` to [stringSum]

	> `Print` [stringSum]

2. add_Int
	- add 2 integer in string format, return the sum in string format
	123456789
	  9876532

	> `Take` [stringInt1] [stringInt2]

	> `Declare` [bigInt] = the longer string of ([stringInt1] and [stringInt2])

	> `Declare` [smallInt] = the shorter string of ([stringInt1] and [stringInt2])

	> `Declare` [startIndex] = 0

	> `Declare` [mem] = 0

	<!-- block index from the end of string to the begin -->
	> `For each` [block] from [bigInt]:

		> `Assign` [endIndex] = [startIndex] + BLOCK_SIZE - 1

		> `Assign` [sum] with `Call` <add_block>:[stringInt1] [stringInt2] [startIndex] [endIndex] [mem]

		> `Check` if <len>:[sum] > BLOCK_SIZE:

			<!-- add 1 to mem for next adding -->
			> `If` TRUE, [mem] = 1

			> `ELSE`, [mem] = 0

		> `If` <len>of[sum] Small BLOCK_SIZE:
			<!-- because still number add after this sum block -->
			> `If` [endIndex] < <len>of[bigInt]

				> `Fill` to the left of [sum] with '0'


		> `Concatenate` (last substring of [sum] with size BLOCK_SIZE ) to [stringSum]

	<!-- in case memory = 1 -->
	> `If` [mem] is 1:

		> `Concatenate` "1" to the begin of [stringSum]

	> `return` [stringSum]

3. add_block
	- Info
		> a block is defined by: substring from startIndex to endIndex, in right-left order
	
	- to add a block 1 one string integer to block of other string integer

	- Input: 
		1. 2 string integer: [bigInt] [smallInt]
		2. [startIndex] [endIndex]: this is index of the [bigInt]
		3. [mem] :  an integer, implying there need add 1 or not to the sum

	- Output: result of adding in string format

	> `take` [bigInt] [smallInt] [startIndex] [endIndex] [mem]

	> `Assign` [bigBlock] = <get_block>:[bigInt] [startIndex] [endIndex]

	> `Assign` [smallBlock] = <get_block>:[bigInt] [startIndex] [endIndex]

	> `Convert` [bigBlock] to an integer

	> `Convert` [smallBlock] to an integer

	> `Assign` [sum] = [bigBlock] + [smallBlock] + [mem]

	> `Convert` [sum] to string

	> `return` [sum]

4. get_block
	- to return a substring from [startIndex] to [endIndex] of a string in right-to-left order
	- Input: [string] [startIndex] [endIndex]
	- Output: a substring of [string], which start from [startIndex] to [endIndex] in right-to left order. 

	> `Take` [string] [startIndex] [endIndex]

	> `Check` if [startIndex] is Greater or Equal to <len>:[string]

		> `If` TRUE: `return` EMPTY_STRING

		> `Else`: `Check` if [endIndex] is Greater or Equal to <len>:[string]:

			> `If` TRUE: `Assign` [endIndex] = <len>:[string] - 1

	> `Assign` [end] = <len>:[string] - [startIndex] - 1

	> `Assign` [start] = <len>:[string] - [endIndex] - 1

	> `Assign` [subString] = [string][start..end]

	> `return` [subString]

