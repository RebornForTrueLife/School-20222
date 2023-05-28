/*
	An abstract class: Media. Subclass can be: DVD, Book, CD
 */

package hust.soict.dsai.aims.media;

import java.util.Comparator;


public abstract class Media {
	private int id;				// book id
	private String title;	
	private String category;
	private float cost;
	public static final Comparator<Media> COMPARE_BY_TITLE_COST;
	public static final Comparator<Media> COMPARE_BY_COST_TITLE;

	static {
		MediaComparatorByCost costComparator = new MediaComparatorByCost();
		MediaComparatorByTitle titleComparator = new MediaComparatorByTitle();
		COMPARE_BY_COST_TITLE = costComparator.thenComparing(titleComparator);
		COMPARE_BY_TITLE_COST = titleComparator.thenComparing(costComparator);
	}	// static block


	// GETTERs
	public int getId() {
		return id;
	}	// close getId


	public String getTitle() {
		if (title.isEmpty())
			return "unknown";
		return title;
	}	// close getTitle
	
	
	public String getCategory() {
		if (category.isEmpty())
			return "unknown";
		return category;
	}	// close getCategory


	public float getCost() {
		return cost;
	}	// close getCost
	
	
	// SETTERs
	void setId(int id) {
		this.id = id;
	}	// close setId

	
	void setTitle(String title) {
		this.title = title;
	}	// close setTitle
	
	
	void setCategory(String category) {
		this.category = category;
	}	// close setCategory


	void setCost(float cost) {
		this.cost = cost;
	}	// close setCost


	@Override
	public boolean equals(Object obj) {
		if (!(obj instanceof Media))		// compare class
			return false;
		Media media = (Media) obj;
		if (!this.getTitle().equalsIgnoreCase(media.getTitle())) 	// compare title
			return false;
		// passed all conditions
		return true;
	}	// close equals


	/* 
		- Given a string of keywords, if the media's title contains any word in the string, 
		it's considered as a match 
		- Note: case - INsensitive 
	 */
	public boolean isMatch(String title) {
		String[] listKeyword = title.split(" ");
		String mediaTitle = this.getTitle().toLowerCase();
		for (String keyword: listKeyword) {
			keyword = keyword.trim().toLowerCase();
			if (mediaTitle.contains(keyword))
				return true;
		}	// close for
		return false;
	}	// close isMatch

}	// close Media


class MediaComparatorByCost implements Comparator<Media> {
	public int compare(Media med1, Media med2) {
		if (med1.getCost() == med2.getCost())
			return 0;
		return (med1.getCost() < med2.getCost()? -1 : 1);
	}	// close compare
}	// close MediaComparatorByCost


class MediaComparatorByTitle implements Comparator<Media> {
	public int compare(Media med1, Media med2) {
		String title1 = med1.getTitle();
		String title2 = med2.getTitle();
		return title1.compareToIgnoreCase(title2);
	}	// close compare
}	// close MediaComparatorByTitle