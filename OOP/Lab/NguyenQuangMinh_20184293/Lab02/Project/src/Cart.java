/*	
	This class to represent and operate on list of customer
	DVDs 
 */


public class Cart {

	// Properties
	private final int MAX_NUMBERS_ORDERED;		// max number of DVDs customer can store at a time
	private int qtyOrdered;						// number of current DVDs in the cart
	private DigitalVideoDics[] itemsOrdered;		// list of DVDs in the cart

	// Behaviors

	// constructor
	public Cart() {
		MAX_NUMBERS_ORDERED = 20;
		itemsOrdered = new DigitalVideoDics[MAX_NUMBERS_ORDERED];
		qtyOrdered = 0;
	}	// close constructor


	// add a DVD in the cart
	public void addDigitalVideoDics(DigitalVideoDics dics) {
		// check if the cart is full
		if (qtyOrdered == MAX_NUMBERS_ORDERED) {
			System.out.println("The cart is almost full!");
			return;
		}	// close if
		// check if the dics is already in the cart
		for (int i = 0; i < qtyOrdered; i ++ ) {
			if (dics == itemsOrdered[i]) {
				System.out.println(dics.getTitle() + " has been already added to the cart!");
				return;
			}	// close if
		}	// close for
		itemsOrdered[qtyOrdered] = dics;
		// increase number of DVDs
		qtyOrdered += 1;
		// prompt to customer
		System.out.println(dics.getTitle() + " was added to the cart!");
	}	// close addDigitalVideoDics


	public void removeDigitalVideoDics(DigitalVideoDics dics) {
		// find dics in the list
		int i = 0;
		for (; i < qtyOrdered; i ++ ) {
			if (dics == itemsOrdered[i])
				break;
		}	// close for
		if (i == qtyOrdered)	{	// NOt found dics
			System.out.println(dics.getTitle() + " is not in the cart!");
			return;
		}	// close if
		itemsOrdered[i] = null;
		qtyOrdered -= 1;
		System.out.println(dics.getTitle() + " was removed from the cart!");
	}	// close removeDigitalVideoDics


	public float totalCost() {
		float total = 0f;
		for (int i = 0; i < qtyOrdered; i ++ ) {
			total += itemsOrdered[i].getCost();
		}	// close for
		return total;
	}	// close totalCost
}	// close class
