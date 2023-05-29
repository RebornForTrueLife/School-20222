/*
	An class for Disc, subclasses: DVD, CD
 */
package hust.soict.dsai.aims.media;

import hust.soict.dsai.aims.media.Media;


public class Disc extends Media {

	// property
	private String director;		


	// Constructor
	public Disc() {
		setId(count);
		count += 1;			// The total number of Media created
		setTitle("unknown");
		setCategory("unknown");
		setDirector("unknown");
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


	// getters	
	public String getDirector() {
		return director;
	}	// close getDirector
	
	
	public int getLength() {		// it's must be override by subclasses
		return 0;
	}	// close getLength
	
	
	// setters
	void setDirector(String director) {
		this.director = director;
	}	// close setDirector

}	// close Disc