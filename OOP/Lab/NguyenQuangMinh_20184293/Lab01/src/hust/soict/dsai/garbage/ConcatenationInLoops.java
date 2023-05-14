/*
	To test String builder and String concatenation
 */

package hust.soict.dsai.garbage;

import java.util.Random;


public class ConcatenationInLoops {
	
	public static void main(String[] args) {
		Random r = new Random(123);
												// using String
		long start = System.currentTimeMillis();
		String s = "";
		for (int i = 0; i < 65536; i ++ ) 
			s += r.nextInt(2);
		System.out.print("Using String - time: ");
		System.out.println(System.currentTimeMillis() - start);
												// using StringBuilder
		r = new Random(123);
		start = System.currentTimeMillis();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 65536; i ++ ) 
			sb.append(r.nextInt(2));
		s = sb.toString();
		System.out.print("Using StringBuilder - time: ");
		System.out.println(System.currentTimeMillis() - start);
	}	// close main

}	// close ConcatenationInLoops