/*
	A place to test the Store class
 * @author: minh
 */

package hust.soict.dsai.test.store;

import hust.soict.dsai.aims.disc.DigitalVideoDisc;
import hust.soict.dsai.aims.store.Store;


public class StoreTest {
	
	public static void main(String[] args) {
		Store repo = new Store();
		DigitalVideoDisc dvd1 = new DigitalVideoDisc("Jungle");
		DigitalVideoDisc dvd2 = new DigitalVideoDisc("Star");
		repo.addDVD(dvd1);
		repo.addDVD(dvd2);
		repo.removeDVD(dvd1);
	}	// close main

}	// close StoreTest