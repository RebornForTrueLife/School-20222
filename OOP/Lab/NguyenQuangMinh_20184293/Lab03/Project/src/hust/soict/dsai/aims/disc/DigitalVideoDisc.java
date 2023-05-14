/*
 * This class is used to represent and operate on DVDs data 
 * @author: minh
 */

package hust.soict.dsai.aims.disc;


public class DigitalVideoDisc {
	
	// Properties
	static int nbDigitalVideoDisc;		// number of dvds have been created
	private int id;					// unique ID of each dvd
	private String title;				// DVD title
	private String category;			// DVD category
	private String director;			// DVD director
	private int length;				// length of DVD, time unit
	private float cost;				// DVD's price


	// initialize static member
	static {
		nbDigitalVideoDisc = 0;
	}	// close static
	
	
	// Operators
	
	// Constructor
	public DigitalVideoDisc() {
		this.id = nbDigitalVideoDisc;
		nbDigitalVideoDisc += 1;
		setTitle("unknown");
		setCategory("unknown");
		setDirector("unknown");
		setLength(0);
		setCost(0);
	}	// close constructor #1
	
	
	public DigitalVideoDisc(String title) {
		this();
		setTitle(title);
	}	// close constructor #2
	
	
	public DigitalVideoDisc(String title, String category, float cost) {
		this(title);
		setCategory(category);
		setCost(cost);
	}	// close constructor #3
	
	
	public DigitalVideoDisc(String title, String category, String director, float cost) {
		this(title, category, cost);
		setDirector(director);
	}	// close constructor #4
	
	
	public DigitalVideoDisc(String title, String category, String director, int length, float cost) {
		this (title, category, director, cost);
		setLength(length);
	}	// close constructor #5
	
	
	// getters
	public int getId() {
		return id;
	}	// close getId


	public String getTitle() {
		return title;
	}	// close getTitle
	
	
	public String getCategory() {
		return category;
	}	// close getCategory

	
	public String getDirector() {
		return director;
	}	// close getDirector
	
	
	public int getLength() {
		return length;
	}	// close getLength
	
	
	public float getCost() {
		return cost;
	}	// close getCost
	
	
	// setters
	void setTitle(String title) {
		this.title = title;
	}	// close setTitle
	
	
	void setCategory(String category) {
		this.category = category;
	}	// close setCategory
	
	
	void setDirector(String director) {
		this.director = director;
	}	// close setDirector
	
	
	void setLength(int length) {
		this.length = length;
	}	// close setLength
	
	
	void setCost(float cost) {
		this.cost = cost;
	}	// close setCost


	/* get the information of the DVD */
	public String toString() {
		StringBuffer buffer = new StringBuffer("DVD - ");
		buffer.append(title + " - ");
		buffer.append(category + " - ");
		buffer.append(director + " - ");
		buffer.append(length + ": ");
		buffer.append(cost + " $");
		return buffer.toString();
	}	// close toString


	/* given a string of keywords, if the title of the DVD contains any word in the string, 
			it's considered as a match 
		Note: case - INsensitive */
	public boolean isMatch(String title) {
		String[] listKeyword = title.split(" ");
		String dvdTitle = this.getTitle().toLowerCase();
		for (String keyword: listKeyword) {
			keyword = keyword.trim().toLowerCase();
			if (dvdTitle.contains(keyword))
				return true;
		}	// close for
		return false;
	}	// close isMatch
	
}	// close DigitalVideoDisc
