
# Classes Design


1. Aims (An Internet Media Store)

	> A class to provide user interface to the DVDs store

	- Behavior:

		1. Main()


2. DigitalVideoDics

	> A class to represent, operate on DVDs data

	- Properties
		1. title 			 :String
		2. category 	 :String
		3. director 		 :String
		4. length 		 :int
		5. cost			 :float

	- Behavior
		0. Constructor method for (5) differents argumetns 

			> (1) Default, no arg

			> (2) title

			> (3) category, title, cost

			> (4) director, category, title, cost

			> (5) title, category, director, length, cost

		1. Accessor/Mutator for all properties


3. Cart

	> A class to store list of DVDs of the customers, and operate on the DVDs list

	- Properties
		1. MAX_NUMBERS_ORDERED		:final int <!-- 20 -->
		2. itemsOrdered					:DigitalVideoDics[] 
		3. qtyOrdered					:int, the number of current DVDs in the cart

	- Behaviors
		1. addDigitalVideoDics(DigitalVideoDics)		:void, adding given DVDs to the itemsOrdered, check if the list is full or not before adding
		2. removeDigitalVideoDics(DigitalVideoDics)	:void, remove given DVDs from the itemsOrdered list
		3. totalCost(void)							:float, return the current cost of the cart

	*Note: all behaviors must interact with user after performed or notified message*