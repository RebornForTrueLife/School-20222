/*
 * This class provide user interface for DVDs store 
 * @author: minh
 * */

package hust.soict.dsai.aims;

import hust.soict.dsai.aims.disc.DigitalVideoDisc;
import hust.soict.dsai.aims.cart.Cart;



public class Aims {
	
	public static void main (String[] args) {
		System.out.println("Welcome to DVDs store!");
		// Create new cart
		Cart cart = new Cart();
		// Create DVDs
		DigitalVideoDisc dvd1 = new DigitalVideoDisc(	"The lion king", "Animation", "Roger Allers", 87, 19.95f);
		DigitalVideoDisc dvd2 = new DigitalVideoDisc("Star wars", "Science fiction", "George Lucas", 87, 24.95f);
		DigitalVideoDisc dvd3 = new DigitalVideoDisc("Aladin", "Animation", 18.95f);
		// add DVDs
		cart.addDigitalVideoDisc(dvd1, dvd2);
		cart.addDigitalVideoDisc(dvd3);
		System.out.println("Total cost = " + cart.totalCost());
		cart.removeDigitalVideoDisc(dvd3);
		System.out.println("Total cost = " + cart.totalCost());
	}	// close main
}	// close Aims
