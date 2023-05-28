/*
 * This class provide user interface for DVDs store 
 * @author: minh
 * */

package hust.soict.dsai.aims;

import hust.soict.dsai.aims.media.*;
import hust.soict.dsai.aims.cart.Cart;
import hust.soict.dsai.aims.store.Store;
import java.util.Scanner;


public class Aims {

	private Store store;
	private Cart cart;


	public Aims() {
		store = new Store();
		cart = new Cart();
	}	// close constructor

	int getOption() {
		Scanner scan = new Scanner(System.in);
		int choice = scan.nextInt();
		scan.close();
		return choice;
	}	// close getOption


	String getInput() {
		Scanner scan = new Scanner(System.in);
		String input = scan.next();
		scan.close();
		return input;
	}	// close getInput


	public void storeUI() {
		System.out.println("Options: ");
		System.out.println("_______________________");
		System.out.println(" [1] See a media's detail");
		System.out.println(" [2] Add a media to cart");
		System.out.println(" [3] Play a media");
		System.out.println(" [4] See current cart");
		System.out.println(" [0] Back to Main menu");
		System.out.println("_______________________");
		System.out.print("Please choose a number: 0-1-2-3-4: ");
		// get user choice
		int choice = getOption();
		// solve request
		String title;
		switch (choice) {
		case 1:
			// TODO: call store to show media detail
			System.out.print("Please enter the title of media: ");
			title = getInput();
			String mediaDetail = store.getMediaDetail();
			if (mediaDetail.isEmpty())			
				System.out.println("Unable to find media with title: " + title);
			else {
				System.out.println("Information of " + title + ": ");
				System.out.print(mediaDetail);
			}	// close if
			// media info menu
			mediaDetailsMenu(title);
			break;
		case 2:
			// TODO: call store && cart to add a media to the cart
			break;
		case 3:
			// TODO: call store to play a media
			break;
		case 4:
			// TODO: call the cart to display itself
			break;
		case 0:
		default:
			mainUI();
			break;	
		}	// switch	
	}	// close storeUI


	public void mainUI() {
		System.out.println("AIMS: ");
		System.out.println("_______________________");
		System.out.println(" [1] View store");
		System.out.println(" [2] Update store");
		System.out.println(" [3] See current cart");
		System.out.println(" [0] Exit");
		System.out.println("_______________________");
		System.out.print("Please choose a number: 0-1-2-3: ");
		// ask for user choice
		int choice = getOption();
		// option
		switch (choice) {
		case 0:
			System.exit(0);
		case 1:
			storeUI();
			break;
		case 2:
			// TODO
			break;
		case 3:
			// cartUI();
			break;
		default: 
			mainUI();
		}	// switch
	}	// close mainUI
	
	public static void main (String[] args) {
		System.out.println("Welcome to DVDs store!");
		// Create new cart
		Cart cart = new Cart();
	}	// close main
}	// close Aims
