/*
	Store class to implement
 * @author: minh
 */

package hust.soict.dsai.aims.store;

import hust.soict.dsai.aims.media.Media;
import hust.soict.dsai.aims.media.Playable;
import hust.soict.dsai.aims.media.DigitalVideoDisc;
import hust.soict.dsai.aims.media.CompactDisc;
import hust.soict.dsai.aims.media.Track;
import hust.soict.dsai.aims.media.Book;

import java.util.List;
import java.util.ArrayList;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Store {

	private List<Media> itemsInStore;


	// constructor
	public Store() {
		itemsInStore = new ArrayList<Media>();
		System.out.println("# A Media repository has been created!");
	}	// close Store


	// add Media
	public void addMedia(Media media) {
		if (itemsInStore.contains(media)) {
			System.out.println(media.getTitle() + " has already existed in the store!");
			return;
		}	// if
		itemsInStore.add(media);
		System.out.println("Successfully added " + media.getTitle() + " to the store!");
	}	// close addMedia


	// remove Media
	public void removeMedia(Media media) {
		if (!itemsInStore.contains(media)) {
			System.out.println(media.getTitle() + " does not exist in the store!");
			return;
		}	// if
		itemsInStore.remove(media);
		System.out.println("Successfully removed " + media.getTitle() + " from the store!");
	}	// close removeDVD


	// find media in the store by id
	public Media findMedia(int id) {
		for (Media media: itemsInStore)
			if (media.getId() == id)
				return media;			// found
		return null;					// no found
	}	// close findMedia by id


	/* 
		given a title, find the media with that title in the media list of store
		if not found, return null
	 */
	public Media findMedia(String title) {
		for (Media media: itemsInStore) {
			if (media.isMatch(title))
				return media;			// return first match
		}	// close for
		return null;					// not found
	}	// close findMedia


	/* 
		load DVD list from given file path
	 */
	private void loadDVD(String dvdFile) throws FileNotFoundException {
		File file = new File(dvdFile);
		Scanner scan = new Scanner(file);
		int count = 0;
		// read list
		while (scan.hasNextLine()) {
			// line pattern: title  category  director  cost  length
			String line = scan.nextLine();
			Scanner scanLine = new Scanner(line);
			String title = scanLine.next();
			String category = scanLine.next();
			String director = scanLine.next();
			int length = scanLine.nextInt();
			float cost = scanLine.nextFloat();
			scanLine.close();
			// make a DVD
			DigitalVideoDisc dvd = new DigitalVideoDisc(title, category, director, length, cost);
			addMedia(dvd);
			count += 1;
		}	// while
		scan.close();
		if (count != 0)
			System.out.println("Successfully loaded " + count + " DVDs to the store!");
		else
			System.out.println("No DVD loaded!");
	}	// close loadDVD


	private void loadCD(String cdFile) throws FileNotFoundException {
		Scanner scan = new Scanner(new File(cdFile));
		int count = 0;
		// read each line
		while (scan.hasNextLine()) {
			// line pattern: title  category  director  artist  cost  length
			String line = scan.nextLine();
			Scanner scanLine = new Scanner(line);
			String title = scanLine.next();
			String category = scanLine.next();
			String director = scanLine.next();
			String artist = scanLine.next();
			float cost = scanLine.nextFloat();
			scanLine.close();
			// extract CD
			CompactDisc cd = new CompactDisc(title, category, director, artist, cost);
			// For simplicity, add 2 default Tracks
			cd.addTrack(new Track("track#1", 40));
			cd.addTrack(new Track("track#2", 30));
			addMedia(cd);
			count += 1;
		}	// while
		scan.close();
		if (count != 0) 
			System.out.println("Successfully loaded " + count + " CDs to the store!");
		else 
			System.out.println("No CD loaded!");
	}	// close loadCD


	// Load list of book from given file to store
	private void loadBook(String bookFile) throws FileNotFoundException {
		Scanner scan = new Scanner(new File(bookFile));
		int count = 0;
		while (scan.hasNextLine()) {
			// line pattern: title 	category  cost  ...authors
			Scanner scanLine = new Scanner(scan.nextLine());
			String title = scanLine.next();
			String category = scanLine.next();
			float cost = scanLine.nextFloat();
			Book book = new Book(title, category, cost);
			while (scanLine.hasNext())			// add list of authors of the book
				book.addAuthor(scanLine.next());
			scanLine.close();
			addMedia(book);
			count += 1;
		}	// close while
		scan.close();
		if (count != 0)
			System.out.println("Successfully loaded " + count + " books to the store!");
		else 
			System.out.println("No book loaded!");
	}	// close loadBook


	// Load media from given file with given type, type can be DVD, CD, Book
	public void loadMedia(String filePath, String type) {
		type = type.trim().toLowerCase();
		try {
			switch (type) {
			case "dvd":
				loadDVD(filePath);
				break;
			case "cd":
				loadCD(filePath);
				break;
			case "book":
				loadBook(filePath);
				break;
			default:
				System.out.println("Invalid media type! Media type can be: dvd, cd, book");
				break;
			}	// close switch
		} catch (FileNotFoundException e) {
			System.out.println("Unable to open file: " + filePath);
		}	// close try
	}	// close loadMedia


	// Play an media, which is playable
	public void playMedia(Media media) {
		if (!(media instanceof Playable)) {
			System.out.println(media.getTitle() + " is unable to play!");
			return;
		}	// close if
		Playable play = (Playable) media;
		play.play();
	}	// close playMedia


	// Given a title, find first media is playable, then play the media
	public void playMedia(String title) {
		Media mediaPlayable = null;
		for (Media media: itemsInStore) {
			if (media.isMatch(title))
				if (media instanceof Playable)
					mediaPlayable = media;
		}	// for
		if (mediaPlayable == null) {
			System.out.println(title + " is unable to play!");
			return;
		}	// close if
		Playable play = (Playable) mediaPlayable;
		play.play();
		System.out.println();
	}	// close playMedia


	// display all media in the store
	public void print() {
		System.out.println("_________ All media in the store __________");
		for (Media media: itemsInStore) {
			System.out.println(media.toString());
		}	// close for
		System.out.println("___________________________________________");
	}	// close print

}	// close Store