
# Code design

## Data
1. input
	- [t] an int ([1, 100]): number of tests
	- [array1], [array2] 2 integer arrays 
	- [size1] [size2] 2 integer, which is size of corresponding array

2. output
	- list of [t] test results, which is the test of equality of each array couple respectively. 
		> 1 - is equal

		> 0 - is Not equal

## Code flow
1. main
	> `enter` [t]

	> `Declare` [resultArray], array to hold test results

	> `For each` [test] in range [1..[t]]:

		> `Call` function to input [size1] [size2] [array1] [array2]

		> `Check` if [array1] and [array2] are equal

		> `Put` result of the check to [resultArray]

	> `Print` out each element in [resultArray] in each line
		
<!--  -->
2. input_array
	- function to enter the size and array elements

	> `Take` address  of [size1] [size2] [array1] [array2]

	> `enter` [size1] and [size2]

	> `enter` elements in [array1]

	> `enter` elements in [array2]

3. check_equal
	- function to check if 2 array are equal
	- 1 for equal, 0 for Not equal

	> `Take` [size1] [size2] [array1] [array2]

	> `If` [size1] equal to [size2]
		<!-- check each pair of element in 2 arrays -->
		> `For each` [pos] in range[1..[size1]]:

			> `If` [array1][pos] NOT equal to [array2][pos]:
				<!-- if there is 1 elements not equal -->
				> `Return` 0

		> `Return` 1 when all elements are equal

	<!-- the sizes are not equal -->
	> `Return` 0