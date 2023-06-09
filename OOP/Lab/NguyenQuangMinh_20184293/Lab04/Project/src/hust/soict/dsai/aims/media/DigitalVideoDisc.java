/*
 * This class is used to represent and operate on DVDs data 
 * @author: minh
 */

package hust.soict.dsai.aims.media;

import hust.soict.dsai.aims.media.Disc;
import hust.soict.dsai.aims.media.Playable;


public class DigitalVideoDisc extends Disc implements Playable {
	
	// Properties
	private int length;				// length of DVD, time unit
		
	
	// OPERATORs

	// Constructor
	public DigitalVideoDisc() {
		super();
	}	// close constructor #1
	
	
	public DigitalVideoDisc(String title) {
		super(title);
	}	// close constructor #2
	
	
	public DigitalVideoDisc(String title, String category, float cost) {
		super(title, category, cost);
	}	// close constructor #3
	
	
	public DigitalVideoDisc(String title, String category, String director, float cost) {
		super(title, category, director, cost);
	}	// close constructor #4
	
	
	public DigitalVideoDisc(String title, String category, String director, int length, float cost) {
		super(title, category, director, cost);
		setLength(length);
	}	// close constructor #5


	// SETTER for length
	void setLength(int length) {
		this.length = length;
	}	// close setLength


	// GETTER for length
	@Override
	public int getLength() {		// it's must be override by subclasses
		return length;
	}	// close getLength


	/* get the information of the DVD */
	@Override
	public String toString() {
		StringBuffer buffer = new StringBuffer("DVD ___ ");
		buffer.append("ID: " + getId() + " ___ ");
		buffer.append("Title: " + getTitle() + " ___ ");
		buffer.append("Category: " + getCategory() + " ___ ");
		buffer.append("Director: " + getDirector() + " ___ ");
		buffer.append("Length: " + getLength() + " ___ ");
		buffer.append(getCost() + " $");
		return buffer.toString();
	}	// close toString


	// implement playable interface
	public void play() {
		if (getLength() == 0) {
			System.out.println("DVD " + getTitle() + " is unable to play!");
			return;
		}	// close if
		// Playing
		System.out.print("Playing DVD: " + getTitle() + " with length: " + getLength());
	}	// close play
	
}	// close DigitalVideoDisc
