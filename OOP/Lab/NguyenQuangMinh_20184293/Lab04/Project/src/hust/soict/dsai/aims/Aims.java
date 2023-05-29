/*
 * This class provide user interface for DVDs store 
 * @author: minh
 * */

package hust.soict.dsai.aims;

import hust.soict.dsai.aims.media.*;
import hust.soict.dsai.aims.cart.Cart;
import hust.soict.dsai.aims.store.Store;
import java.util.Scanner;

import java.util.List;
import java.util.ArrayList;


public class Aims {

	private Store store;
	private Cart cart;
	private static Scanner scan = new Scanner(System.in);


	public Aims() {
		store = new Store();
		// store.loadMedia("/home/minh/School/Learning/20222/OOP/Lab/NguyenQuangMinh_20184293/Lab04/Project/data/book.in", "book");
		// store.loadMedia("/home/minh/School/Learning/20222/OOP/Lab/NguyenQuangMinh_20184293/Lab04/Project/data/dvd.in", "dvd");
		// store.loadMedia("/home/minh/School/Learning/20222/OOP/Lab/NguyenQuangMinh_20184293/Lab04/Project/data/cd.in", "cd");
		cart = new Cart();
	}	// close constructor


	// Get choice from stdin
	int getOption() {
		int choice = scan.nextInt();
		return choice;
	}	// close getOption


	// get a string from stdin
	String getInput() {
		String input = scan.next();
		return input;
	}	// close getInput


	private Media getMedia() {
		System.out.print("Please enter the title of media: ");
		String title = getInput();
		Media media = store.findMedia(title);			// find media with title
		if (media == null) {							// unable to find the media with given title
			System.out.println("Unable to find the media: " + title);
		}	// close if
		return media;
	}	// close getTitle


	private Media inputMedia(String option) {
		option = option.trim().toLowerCase();
		Media media = null;
		// input title
		System.out.print("Please enter the title: ");
		String title = getInput();
		// input category
		System.out.print("Please enter the category: ");
		String category = getInput();
		// input cost
		System.out.print("Please enter the cost: ");
		float cost = scan.nextFloat();
		switch (option) {
		case "dvd":
			media = new DigitalVideoDisc(title, category, cost);
			break;
		case "cd":
			media = new CompactDisc(title, category, cost);
			break;
		case "book":
			media = new Book(title, category, cost);
			break;
		default:
			System.out.println("Invalid type of media!");
			return null;
		}	// close switch
		return media;
	}	// close 


	/*
		UI for the current cart menu
	 */
	public void cartUI() {
		System.out.println("__________________ Cart Menu _________________");
		System.out.println(" [1] Filter media in the cart");
		System.out.println(" [2] Sort media in the cart");
		System.out.println(" [3] Remove media from the cart");
		System.out.println(" [4] Play media");
		System.out.println(" [5] Place order");
		System.out.println(" [0] Back");
		System.out.println("__________________ cart menu _________________");
		System.out.print("Please choose the choice number: ");
		// get choice
		int choice = getOption();
		// solve request
		switch (choice) {
		case 1: 	// filter media
			System.out.println("Choose the filter option: [1] By-Id\t [2] By-title");
			int filterChoice = getOption();
			if (filterChoice == 1)	{						// filter by id
				System.out.print("You chosen filter by Id, please enter the media ID: ");
				int id = getOption();
				Media mediaByID = cart.search(id);
				if (mediaByID == null)
					System.out.println("Unable to find media with id: " + id);
				else {
					System.out.print("Found media with id " + id + ": ");
					System.out.println(mediaByID.toString());
				}	// close if
				break;
			} else if (filterChoice == 2)	{				// filter by title
				System.out.print("You chosen filter by title, please enter the title: ");
				String title = getInput();
				List<Media> mediaByTitle = cart.search(title);
				if (mediaByTitle.isEmpty())
					System.out.println("No result found for media title: " + title);
				else {
					System.out.println("List of meddia with match title " + title + ": ");
					for (Media med: mediaByTitle) 
						System.out.println(med.toString());
				}	// close if
			} else {
				System.out.println("Invalid for filter choice! Back to cart menu");
			}	// close if
			break;
		case 2: 	// sort media
			System.out.print("Choose the sorting option: [1] By-cost\t [2] By-title: ");
			int sortChoice = getOption();
			if (sortChoice == 1) {							// sort by cost
				cart.sort("cost-title");
				cart.print();
			} else if (sortChoice == 2) {					// sort by title
				cart.sort("title-cost");
				cart.print();
			} else {										// invalid option
				System.out.println("Invalid sorting option, back to the Cart menu");
			}	// close if
			break;
		case 3: 	// remove media in the cart by title
			System.out.print("Please enter the media's ID you want to remove from the cart: ");
			int id = getOption();
			Media mediaByID = cart.search(id);
			if (mediaByID == null) {
				System.out.println("No result for media with id: " + id);
			} else {
				cart.removeMedia(mediaByID);
			}	// close if
			break;
		case 4: 	// play a media
			Media media = getMedia();
			if (media == null)		// unable to find media		
				break;
			store.playMedia(media);
			break;
		case 5: 	// place order
			System.out.println(cart.placeOrder());
			break;
		case 0:
			return;
		default:
			break;
		}	// close switch
		cartUI();
	}	// close cartUI


	/*
		- the store UI for only manager
		- Allow to add/remove/display media in the store
	 */
	public void managerStoreUI() {
		System.out.println("__________________ Manage store ______________");
		System.out.println(" [1] Add new media");
		System.out.println(" [2] Remove a media");
		System.out.println(" [0] Back to the main menu");
		System.out.println("__________________ manage store ______________");
		// get choice
		int choice = getOption();
		// solve the request
		switch (choice) {
		case 1:				// add new media
			System.out.print("Choose the media type [1] DVD\t [2] CD\t [3] Book: ");
			int typeChoice = getOption();
			Media media;
			switch (typeChoice) {
			case 1:
				media = inputMedia("DVD");
				store.addMedia(media);
				break;
			case 2:
				media = inputMedia("CD");
				store.addMedia(media);
				break;
			case 3:
				media = inputMedia("BOOK");
				store.addMedia(media);
				break;
			default:
				System.out.println("Invalid type option, back to the Manager menu");
				managerStoreUI();
			}	// close switch
			break;
		case 2: 			// remove a media
			System.out.print("Please enter the media's id that you want to remove from the store: ");
			int id = getOption();
			Media mediaByID = store.findMedia(id);
			if (mediaByID == null) {
				System.out.println("No result for media with id: " + id);
			} else {
				store.removeMedia(mediaByID);
			}	// close if
			break;
		case 0:
			mainUI();
		default:
			break;
		}	// close switch
		managerStoreUI();
	}	// close managerStoreUI


	// A menu for each Media (when display detail of the media)
	public void mediaDetailsMenu(Media media) {
		System.out.println();
		System.out.println("__________________ Media Menu ________________");
		System.out.println(" [1] Add to cart");
		if (media instanceof Playable) 						// option for only DVD, CD
			System.out.println(" [2] Play media");
		System.out.println(" [0] Back to Store menu");
		System.out.println("__________________ media menu ________________");
		System.out.print("Please choose the choice number: ");
		// get options
		int choice = getOption();
		switch (choice) {
		case 1:
			cart.addMedia(media);
			break;
		case 2:
			store.playMedia(media);							// only playable object
			break;
		case 0:
			storeUI();
		default:
			break;
		}	// switch
		mediaDetailsMenu(media);
	}	// close mediaDetailsMenu


	// UI for store manipulation
	public void storeUI() {
		System.out.println();
		System.out.println("____________________ Store Menu ______________");
		System.out.println(" [1] See a media's detail");
		System.out.println(" [2] Add a media to cart");
		System.out.println(" [3] Play a media");
		System.out.println(" [4] See current cart");
		System.out.println(" [0] Back to Main menu");
		System.out.println("____________________ store menu ______________");
		System.out.print("Please choose a number: 0-1-2-3-4: ");
		// get user choice
		int choice = getOption();
		// solve request
		Media media = null;
		switch (choice) {
		case 1:
			// TODO: call store to show media detail
			media = getMedia();
			if (media == null)								// unable to find media
				break;
			System.out.println("Information of " + media.getTitle() + ": " + media.toString());
			// open media detail menu
			mediaDetailsMenu(media);
			break;
		case 2:
			// TODO: call store && cart to add a media to the cart
			media = getMedia();
			if (media == null)								// unable to find media		
				break;
			cart.addMedia(media);
			break;
		case 3:						// TODO: call store to play a media
			media = getMedia();
			if (media == null)		// unable to find media		
				break;
			store.playMedia(media);
			break;
		case 4:
			// TODO: call the cart to display itself
			cart.print();
			cartUI();
			break;
		case 0:
			// back to main menu
			mainUI();	
			break;	
		default:
			break;	
		}	// switch	
		// reopen Store menu
		storeUI();
	}	// close storeUI


	// the main UI for manager/customer
	public void mainUI() {
		System.out.println();
		System.out.println("____________________ Main Menu________________");
		System.out.println(" [1] View store");
		System.out.println(" [2] Update store");
		System.out.println(" [3] See current cart");
		System.out.println(" [0] Exit");
		System.out.println("____________________ main menu _______________");
		System.out.print("Please choose a number: 0-1-2-3: ");
		// ask for user choice
		int choice = getOption();
		// option
		switch (choice) {
		case 0:		// exit
			System.exit(0);
		case 1:		// view store
			store.print();
			storeUI();
			break;
		case 2:
			// TODO: update the media in store
			store.print();
			managerStoreUI();
			break;
		case 3:		// see the current cart
			cart.print();
			cartUI();
			break;
		default: 
			break;
		}	// switch
		mainUI();
	}	// close mainUI

	
	public static void main (String[] args) {
		System.out.println("Welcome to DVDs store!");
		Aims app = new Aims();
		app.mainUI();
	}	// close main
}	// close Aims
