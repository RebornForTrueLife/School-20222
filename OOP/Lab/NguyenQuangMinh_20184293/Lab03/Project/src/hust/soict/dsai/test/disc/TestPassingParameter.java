/*
	To test passing parameter in java
 * @author: minh
 */

package hust.soict.dsai.test.disc;

import hust.soict.dsai.aims.disc.DigitalVideoDisc;


public class TestPassingParameter {
	
	public static void main(String[] args) {
		// create 2 dvds
		DigitalVideoDisc jungleDvd = new DigitalVideoDisc("Jungle");
		DigitalVideoDisc cinderellaDvd = new DigitalVideoDisc("Cinderella");

		// swap titles
		swap(jungleDvd, cinderellaDvd);
		System.out.println("Title of jungleDvd: " + jungleDvd.getTitle());
		System.out.println("Title of cinderellaDvd: " + cinderellaDvd.getTitle());

		// change title
		changeTitle(jungleDvd, cinderellaDvd.getTitle());
		System.out.println("Title of jungleDvd: " + jungleDvd.getTitle());
	}	// close main


	public static void swap(Object o1, Object o2) {
		DigitalVideoDisc dvd1 = (DigitalVideoDisc) o1;
		DigitalVideoDisc dvd2 = (DigitalVideoDisc) o2;
		String title = dvd1.getTitle();
		changeTitle(dvd1, dvd2.getTitle());
		changeTitle(dvd2, title);
	}	// close swap


	public static void changeTitle(DigitalVideoDisc dvd, String title) {
		dvd.setTitle(title);
	}	// close changeTitle
}	// close class TestPassingParameter