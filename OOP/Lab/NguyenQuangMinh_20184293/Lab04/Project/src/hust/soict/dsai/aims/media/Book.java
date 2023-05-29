/*
	Media kind: Book
	@author: minh
 */
package hust.soict.dsai.aims.media;

import hust.soict.dsai.aims.media.Media;
import java.util.List;
import java.util.ArrayList;


public class Book extends Media {
	private List<String> authors;

	// default constructor
	public Book() {
		setId(count);
		count += 1;			// The total number of Media created
		authors = new ArrayList<String> ();
	}	// close constructor


	public Book(String title, String category, float cost) {
		this();
		setTitle(title);
		setCategory(category);
		setCost(cost);
	}	// close constructor #2


	// Add an author to the authors list, if the author has already existed -> do nothing
	public void addAuthor(String author) {
		for (String name: authors) {
			if (name.equalsIgnoreCase(author)) {
				System.out.println(author + " is already on the author list");
				return;
			}	// if
		}	// for
		authors.add(author);
		System.out.println(author + " is added to the authors list!");
	}	// close addAuthor


	// Remove an author from the author list, if the author does not exist -> Do nothing
	public void removeAuthor(String author) {
		for (String name: authors) {
			if (name.equalsIgnoreCase(author)) {
				authors.remove(name);
				System.out.println("Successfully removed " + author + " from the list!");
				return;
			}	// close if
		}	// close for
		System.out.println(author + " does not exist on the list!");
	}	// close removeAuthor


	@Override
	public String toString() {
		StringBuffer buffer = new StringBuffer("Book ___ ");
		buffer.append("ID: " + getId() + " ___ ");
		buffer.append("Title: " + getTitle() + " ___ ");
		buffer.append("Category: " + getCategory() + " ___ ");
		buffer.append("Authors: ");
		if (authors.isEmpty())
			buffer.append("unknown");
		for (String author: authors)
			buffer.append("'" + author + "' ");
		buffer.append(" ___ " + getCost() + " $");
		return buffer.toString();
	}	// close toString

}	// close Book