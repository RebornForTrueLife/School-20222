/*
	Store class to implement
 * @author: minh
 */

package hust.soict.dsai.aims.store;

import hust.soict.dsai.aims.disc.DigitalVideoDisc;

import java.util.List;
import java.util.ArrayList;


public class Store {

	private List<DigitalVideoDisc> itemsInStore;


	// constructor
	public Store() {
		itemsInStore = new ArrayList<DigitalVideoDisc>();
		System.out.println("# A DVD repository has been created!");
	}	// close Store


	// add DVD
	public void addDVD(DigitalVideoDisc dvd) {
		// check if dvd is already in the store
		for (DigitalVideoDisc addedDVD: itemsInStore) {
			if (addedDVD == dvd) {
				System.out.println("# The DVD has been already stored!");
				return;
			}	// close if
		}	// close for
		itemsInStore.add(dvd);
	}	// close addDVD


	// remove DVD
	public void removeDVD(DigitalVideoDisc dvd) {
		itemsInStore.remove(dvd);
		System.out.println("# Removed successfully!");
	}	// close removeDVD
	
}	// close Store