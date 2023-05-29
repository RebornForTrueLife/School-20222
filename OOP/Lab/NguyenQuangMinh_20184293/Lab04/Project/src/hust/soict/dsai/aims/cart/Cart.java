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

import java.util.Collections;
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


	/* search media by id */
	public Media search(int id) {
		for (Media media: itemsOrdered) {
			if (media.getId() == id)	// found
				return media;
		}	// close
		return null;					// not found
	}	// close seach by id


	/* search dvd by title */
	public List<Media> search(String title) {
		List<Media> list = new ArrayList<Media>();
		for (Media media: itemsOrdered) {
			if (media.isMatch(title))
				list.add(media);		// found a match
		}	// close count
		return list;					// return empty list if no media found
	}	// close search by title


	/*
		Sort the cart the list of media base on given option: Cost-Title or Title-Cost
	 */
	public void sort(String option) {
		option = option.trim().toLowerCase();
		switch (option) {
		case "cost-title":					// sort by cost then title
			Collections.sort(itemsOrdered, Media.COMPARE_BY_COST_TITLE);
			System.out.println("The cart is sorted by decreased cost then title!");
			break;
		case "title-cost":					// sort by title then cost
			Collections.sort(itemsOrdered, Media.COMPARE_BY_TITLE_COST);
			System.out.println("The cart is sorted by title then decreased cost");
			break;
		default:
			System.out.println("Invalid sorting option, valid options: cost-title, title-cost");
			return;
		}	// close switch
	}	// close sort


	/*
		place the order: print receive(total cost), empty the list of media
	 */
	public String placeOrder() {
		if (itemsOrdered.isEmpty())
			return "The cart is empty! - Unable to place an order";
		StringBuffer receipt = new StringBuffer();
		receipt.append("There are " + itemsOrdered.size() +" in the cart with total cost: " + totalCost() + "\n");
		itemsOrdered.clear();
		receipt.append("Order is received! Clear the cart!");
		return receipt.toString();
	}	// close placeOrder
	
}	// close class
