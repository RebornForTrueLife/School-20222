/*
	This is class of CD
 */
package hust.soict.dsai.aims.media;

import hust.soict.dsai.aims.media.Disc;
import hust.soict.dsai.aims.media.Track;
import hust.soict.dsai.aims.media.Playable;
import java.util.List;
import java.util.ArrayList;


public class CompactDisc extends Disc implements Playable {
	private String artist;
	private List<Track> tracks = new ArrayList<Track>();


	// Constructor
	public CompactDisc() {
		super();
	}	// close constructor #1
	
	
	public CompactDisc(String title) {
		super(title);
	}	// close constructor #2
	
	
	public CompactDisc(String title, String category, float cost) {
		super(title, category, cost);
	}	// close constructor #3
	
	
	public CompactDisc(String title, String category, String director, float cost) {
		super(title, category, director, cost);
	}	// close constructor #4
	
	
	public CompactDisc(String title, String category, String director, String artist, float cost) {
		super(title, category, director, cost);
		setArtist(artist);
	}	// close constructor #5


	public void setArtist(String artist) {
		this.artist = artist;
	}	// close setArtist


	public String getArtist() {
		if (artist.isEmpty())
			return "unknown";
		return artist;
	}	// close getArtist


	// Add a new track if the track has not existed on the list
	public void addTrack(Track track) {
		if (tracks.contains(track)) {
			System.out.println(track.getTitle() + " has already existed!");
			return;
		}	// if
		tracks.add(track);
	}	// close addTrack


	// remove the given track from the list track if it exists on the list
	public void removeTrack(Track track) {
		if (!tracks.contains(track)) {
			System.out.println(track.getTitle() + " does not exist on the list");
			return;
		}	// if
		tracks.remove(track);
	}	// close removeTrack


	// get length, total length of tracks
	@Override
	public int getLength() {
		int length = 0;
		for (Track track: tracks) 
			length += track.getLength();
		return length;
	}	// close getLength


	// implement playable interface
	public void play() {
		if (getLength() == 0) {
			System.out.println("CD " + getTitle() + " is unable to play");
			return;
		}	// close if
		// play each track
		for (Track track: tracks) 
			track.play();
		System.out.println("...CD " + getTitle() + " is over!");
	}	// close play


	@Override
	public String toString() {
		StringBuffer buffer = new StringBuffer("CD - ");
		buffer.append("Title: " + getTitle() + " - ");
		buffer.append("Category: " + getCategory() + " - ");
		buffer.append("Director: " + getDirector() + " - ");
		buffer.append("Length: " + getLength() + " - ");
		buffer.append("Artist: " + getArtist() + " - ");
		buffer.append(getCost() + " $");
		return buffer.toString();
	}	// close toString

}	// close CompactDisc