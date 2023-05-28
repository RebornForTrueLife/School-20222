/*	
	This class to represent and operate on list of customer
	DVDs 
 * @author: minh
 */

package hust.soict.dsai.aims.cart;

import hust.soict.dsai.aims.media.Media;
import hust.soict.dsai.aims.media.DigitalVideoDisc;
import hust.soict.dsai.aims.media.CompactDisc;
import hust.soict.dsai.aims.media.Book;

import java.util.List;
import java.util.ArrayList;


public class Cart {

	// Properties
	private List<Media> itemsOrdered;		// list of Media in the cart

	// Behaviors

	// constructor
	public Cart() {
		itemsOrdered = new ArrayList<Media>();
	}	// close constructor


	// add a media in the cart
	public void addMedia(Media media) {
		if (itemsOrdered.contains(media)) {
			System.out.println(media.getTitle() + " has already existed on the cart!");
			return;
		}	// close if
		itemsOrdered.add(media);
		System.out.println("Successfully add " + media.getTitle() + " in the cart!");
	}	// close addMedia


	/* add arbitrary number of arguments for media */
	public void addMedia(Media ... listMedia) {
		for (Media media: listMedia)
			addMedia(media);
	}	// close addDigitalVideoDisc


	public void removeMedia(Media media) {
		if (!itemsOrdered.contains(media)) {
			System.out.println(media.getTitle() + " does not exist in the cart!");
			return;
		}	// close if
		itemsOrdered.remove(media);
		System.out.println("Successfully removed " + media.getTitle() + " from the cart!");
	}	// close removeMedia


	public float totalCost() {
		float total = 0f;
		for (Media media: itemsOrdered) 
			total += media.getCost();
		return total;
	}	// close totalCost


	/* list all dvd in the cart */
	public void print() {
		if (itemsOrdered.isEmpty()) {
			System.out.println("# The cart is empty!");
			return;
		}	// close if
		System.out.println("***********************CART***********************");
		System.out.println("Ordered Items: ");		
		int i = 1;
		for (Media media: itemsOrdered) {
			System.out.println(i + ". " + media.toString());
			i += 1;
		}	// close for
		System.out.println("Total cost: " + totalCost());
		System.out.println("***************************************************");
	}	// close print


	// /* search dvd by id */
	// public void search(int id) {
	// 	for (int i = 0; i < qtyOrdered; i ++ ) {
	// 		DigitalVideoDisc dvd = itemsOrdered[i];
	// 		if (dvd.getId() == id) {
	// 			System.out.println("# Found DVD: " + dvd.toString());
	// 			return;
	// 		}	// close if
	// 	}	// close for
	// 	System.out.println("# There is no DVD with Id: " + id);
	// }	// close seach by id


	// /* search dvd by title */
	// public void search(String title) {
	// 	int count = 0;
	// 	for (int i = 0; i < qtyOrdered; i ++ ) {
	// 		DigitalVideoDisc dvd = itemsOrdered[i];
	// 		if (dvd.isMatch(title)) {
	// 			count += 1;
	// 			System.out.println("# Found: " + dvd.toString());
	// 		}	// close if
	// 	}	// close for
	// 	if (count == 0)
	// 		System.out.println("# No DVD found with title: " + title);
	// }	// close search by title


	public static void main(String[] args) {
		Cart cart = new Cart();
		cart.addMedia(new Book("jungle", "adventure", 10.5f));
		cart.addMedia(new CompactDisc("mountain", "view", "holme", "dr.who", 5.6f));
		cart.addMedia(new DigitalVideoDisc("conan", "detective", "conan", 90, 2.7f));
		cart.print();
	}	// close main
	
}	// close class
