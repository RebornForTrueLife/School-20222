/*	
	This class to represent and operate on list of customer
	DVDs 
 * @author: minh
 */

package hust.soict.dsai.aims.cart;

import hust.soict.dsai.aims.disc.DigitalVideoDisc;


public class Cart {

	// Properties
	private final int MAX_NUMBERS_ORDERED;		// max number of DVDs customer can store at a time
	private int qtyOrdered;						// number of current DVDs in the cart
	private DigitalVideoDisc[] itemsOrdered;		// list of DVDs in the cart

	// Behaviors

	// constructor
	public Cart() {
		MAX_NUMBERS_ORDERED = 20;
		itemsOrdered = new DigitalVideoDisc[MAX_NUMBERS_ORDERED];
		qtyOrdered = 0;
	}	// close constructor


	// add a DVD in the cart
	public void addDigitalVideoDisc(DigitalVideoDisc disc) {
		// check if the cart is full
		if (qtyOrdered == MAX_NUMBERS_ORDERED) {
			System.out.println("The cart is almost full!");
			return;
		}	// close if
		// check if the disc is already in the cart
		for (int i = 0; i < qtyOrdered; i ++ ) {
			if (disc == itemsOrdered[i]) {
				System.out.println(disc.getTitle() + " has been already added to the cart!");
				return;
			}	// close if
		}	// close for
		itemsOrdered[qtyOrdered] = disc;
		// increase number of DVDs
		qtyOrdered += 1;
		// prompt to customer
		System.out.println(disc.getTitle() + " was added to the cart!");
	}	// close addDigitalVideoDisc


	/* add arbitrary number of arguments for dvd */
	public void addDigitalVideoDisc(DigitalVideoDisc ... listDvd) {
		for (DigitalVideoDisc disc: listDvd) {
			addDigitalVideoDisc(disc);
		}	// close for
	}	// close addDigitalVideoDisc


	public void removeDigitalVideoDisc(DigitalVideoDisc disc) {
		// find disc in the list
		int i = 0;
		for (; i < qtyOrdered; i ++ ) {
			if (disc == itemsOrdered[i])
				break;
		}	// close for
		if (i == qtyOrdered)	{	// NOt found disc
			System.out.println(disc.getTitle() + " is not in the cart!");
			return;
		}	// close if
		itemsOrdered[i] = null;
		qtyOrdered -= 1;
		System.out.println(disc.getTitle() + " was removed from the cart!");
	}	// close removeDigitalVideoDisc


	public float totalCost() {
		float total = 0f;
		for (int i = 0; i < qtyOrdered; i ++ ) {
			total += itemsOrdered[i].getCost();
		}	// close for
		return total;
	}	// close totalCost


	/* list all dvd in the cart */
	public void print() {
		if (qtyOrdered == 0) {
			System.out.println("# The cart is empty!");
			return;
		}	// close if
		System.out.println("***********************CART***********************");
		System.out.println("Ordered Items: ");		
		for (int i = 0; i < qtyOrdered; i ++ ) {
			DigitalVideoDisc dvd = itemsOrdered[i];
			System.out.println((i + 1) + ". " + dvd.toString());
		}	// close for
		System.out.println("Total cost: " + totalCost());
		System.out.println("***************************************************");
	}	// close print


	/* search dvd by id */
	public void search(int id) {
		for (int i = 0; i < qtyOrdered; i ++ ) {
			DigitalVideoDisc dvd = itemsOrdered[i];
			if (dvd.getId() == id) {
				System.out.println("# Found DVD: " + dvd.toString());
				return;
			}	// close if
		}	// close for
		System.out.println("# There is no DVD with Id: " + id);
	}	// close seach by id


	/* search dvd by title */
	public void search(String title) {
		int count = 0;
		for (int i = 0; i < qtyOrdered; i ++ ) {
			DigitalVideoDisc dvd = itemsOrdered[i];
			if (dvd.isMatch(title)) {
				count += 1;
				System.out.println("# Found: " + dvd.toString());
			}	// close if
		}	// close for
		if (count == 0)
			System.out.println("# No DVD found with title: " + title);
	}	// close search by title
}	// close class
