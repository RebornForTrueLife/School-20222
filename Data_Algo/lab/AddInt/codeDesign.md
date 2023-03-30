
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

	> `Take` [stringInt1] [stringInt2]

	> `Declare` [bigInt] = the longer string of ([stringInt1] and [stringInt2])

	> `Declare` [smallInt] = the shorter string of ([stringInt1] and [stringInt2])

	<!-- block index from the end of string to the begin -->
	> `For each` [block] from [bigInt]:

		> `Call` <add_block> 
