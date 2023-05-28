/*
	Store class to implement
 * @author: minh
 */

package hust.soict.dsai.aims.store;

import hust.soict.dsai.aims.media.Media;
import hust.soict.dsai.aims.media.DigitalVideoDisc;
import hust.soict.dsai.aims.media.CompactDisc;
import hust.soict.dsai.aims.media.Book;

import java.util.List;
import java.util.ArrayList;


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


	/* 
		given a title, find the media with that title in the media list of store
		if not found, return null
	 */
	Media findMedia(String title) {
		for (Media media: itemsInStore) {
			if (media.isMatch(title))
				return media;			// return first match
		}	// close for
		return null;					// not found
	}	// close findMedia

	/* 
		given a title, find and return the information of the media found
		if not found, return EMPTY string
	 */
	public String getMediaDetail(String title) {
		Media media = findMedia(title);
		if (media == null)				// not found
			return "";
		return media.toString();		// return media info
	}	// close getMediaDetail

}	// close Store