/* 
	This class of Track, which is included in a CD
 */
package hust.soict.dsai.aims.media;

import hust.soict.dsai.aims.media.Playable;


public class Track implements Playable{
	
	private String title;
	private int length;


	public Track() {
		title = "unknown";
		length = 0;
	}	// close constructor #1


	public Track(String title, int length) {
		this.title = title;
		this.length = length;
	}	// close constructor #2


	// GETTERs
	public String getTitle() {
		return title;
	}	// close getTitle


	// GETTERs
	public int getLength() {
		return length;
	}	// close getLength


	// implement playable interface
	public void play() {
		if (getLength() == 0) {
			System.out.println("Track " + getTitle() + " is unable to play!");
			return;
		}	// close if
		// Playing
		System.out.print("Playing track: " + getTitle() + " with length: " + getLength());
	}	// close play


	@Override
	public boolean equals(Object obj) {
		if (!(obj instanceof Track))							// compare class
			return false;
		Track track = (Track) obj;
		if (!this.title.equalsIgnoreCase(track.getTitle()))		// compare title
			return false;
		if (this.getLength() != track.getLength())				// compare length
			return false;
		// passed all conditions
		return true;
	}	// close equals

}	// close Track