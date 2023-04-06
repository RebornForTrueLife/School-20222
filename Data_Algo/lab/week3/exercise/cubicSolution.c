/*	
	The program is used to find integer solution of a cubic equation in the below form:
		x^3 + ax^2 + bx + c, where x is the root; a, b, c is the input variables
	Output: (2)
		1. IF there is no integer solution: print NO SOLUTION
		2. If there is integer solution, then list all integer solution found
	// THe algorithms: (in simple)
	1. Find all divisors of [c], put them into a [array]
		> The integer solutions if exist, will be the subset of [array]
	2. For each element in [array]:
		> CHECK if the element is a solution
	3. If found, print out
		- else: print: NO SOLUTION
 */