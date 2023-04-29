
# AIMS

***An Internet Media Store***

*Preliminary Specification*

## Purpose
> Provide a system that help user to buy DVD from the store


## Description

### SERVICEs

*Note: there are 2 kinds of information: (1)display information and (2) detail information*


#### For User

1. Show list of DVDs(customer can browse the list)

	> Display in order of added date: lastest to oldest


2. Searching DVD

	- There are 3 searchin options, customers need to choose one: (1)By title; (2)By category; (3)By price

	- System will display list of all matches(in order) and their information


3. Play demo of DVD

	- Then the customers can choose to play an demo part of selected DVDs

	- The system will play the selected DVD

		> If the DVD has length 0 or less, warning to user: Unable to play


4. Adding DVD

	- There are 2 places, where customers can add DVDs to their cart: (1)from list of DVDs; (2)detail screen of a DVD


5. Display current cart

	- Customer can see the list of DVDs in their cart

	- The system will display the list of DVDs and the total cost

		> The system has to pick a random DVDs and make it free (relate to total cost)

	- From the current frame, customer can

		> (1)	Sort the list of DVDs by (1)title or (2)price

		> (2) 	Play demo part of selected DVDs

		> (3)  	Change the quantity of a DVD or remove from it from the cart

		> (4) 	Filter the cart's DVDs list by (1)ID or (2)title (Display if found, otherwise, notify not found)

		> (5) 	Place order

			- The system will ask users for delivery information and delivery instruction.

			- The system will calculate the delivery fee based on (1)the total mass of the order and (2)the delivery location

			- The system will display the invoice

			...


#### For store manager

1. Display the list of pending orders

	- System will display the list

	- From here, manager can (1)approve or (2)reject the order


2. Add DVDs

	- Manager need to give the detail of DVDs

3. Remove DVDs

