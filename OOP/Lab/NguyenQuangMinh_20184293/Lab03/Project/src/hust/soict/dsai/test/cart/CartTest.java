/* 
	To test new feature of Cart class
 * @author: minh
 */

package hust.soict.dsai.test.cart;

import hust.soict.dsai.aims.cart.Cart;
import hust.soict.dsai.aims.disc.DigitalVideoDisc;


public class CartTest {
	
	public static void main(String[] args) {
		// create new cart
		Cart cart = new Cart();
		// add DVDs
		DigitalVideoDisc listDvd[] = new DigitalVideoDisc[3];
		listDvd[0] = new DigitalVideoDisc("The Lion King", "Animation", "Roger Allers", 97, 19.95f);
		listDvd[1] = new DigitalVideoDisc("Star Wars", "Science Fiction", "George Lucas", 87, 24.95f);
		listDvd[2] = new DigitalVideoDisc("Aladin", "Animation", 18.99f);
		cart.addDigitalVideoDisc(listDvd);
		// operations
		cart.print();				// print list of dvds
		cart.search(1);				// search by id 1
		cart.search("KingLion");		// search by title
	}	// close main
}	// close CartTest