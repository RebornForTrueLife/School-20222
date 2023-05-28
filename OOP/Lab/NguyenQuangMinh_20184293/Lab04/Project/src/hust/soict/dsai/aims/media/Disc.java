/*
	An class for Disc, subclasses: DVD, CD
 */
package hust.soict.dsai.aims.media;

import hust.soict.dsai.aims.media.Media;


public class Disc extends Media {
	private int length;
	private String director;


	// Constructor
	public Disc() {
		setTitle("unknown");
		setCategory("unknown");
		setDirector("unknown");
		setLength(0);
		setCost(0);
	}	// close constructor #1
	
	
	public Disc(String title) {
		this();
		setTitle(title);
	}	// close constructor #2
	
	
	public Disc(String title, String category, float cost) {
		this(title);
		setCategory(category);
		setCost(cost);
	}	// close constructor #3
	
	
	public Disc(String title, String category, String director, float cost) {
		this(title, category, cost);
		setDirector(director);
	}	// close constructor #4
	
	
	public Disc(String title, String category, String director, int length, float cost) {
		this (title, category, director, cost);
		setLength(length);
	}	// close constructor #5


	// getters	
	public String getDirector() {
		return director;
	}	// close getDirector
	
	
	public int getLength() {
		return length;
	}	// close getLength
	
	
	// setters
	void setDirector(String director) {
		this.director = director;
	}	// close setDirector
	
	
	void setLength(int length) {
		this.length = length;
	}	// close setLength
}	// close Disc