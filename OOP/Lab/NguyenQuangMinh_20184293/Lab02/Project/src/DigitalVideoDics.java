/*
 * This class is used to represent and operate on DVDs data 
 * */


public class DigitalVideoDics {
	
	// Properties
	private String title;			// DVD title
	private String category;		// DVD category
	private String director;		// DVD director
	private int length;				// length of DVD, time unit
	private float cost;				// DVD's price
	
	
	// Operators
	
	// Constructor
	public DigitalVideoDics() {
		// Do nothing
	}	// close constructor #1
	
	
	public DigitalVideoDics(String title) {
		setTitle(title);
	}	// close constructor #2
	
	
	public DigitalVideoDics(String title, String category, float cost) {
		setCategory(category);
		setTitle(title);
		setCost(cost);
	}	// close constructor #3
	
	
	public DigitalVideoDics(String title, String category, String director, float cost) {
		this(title, category, cost);
		setDirector(director);
	}	// close constructor #4
	
	
	public DigitalVideoDics(String title, String category, String director, int length, float cost) {
		this (title, category, director, cost);
		setLength(length);
	}	// close constructor #5
	
	
	// getters
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
	
}	// close DigitalVideoDics
