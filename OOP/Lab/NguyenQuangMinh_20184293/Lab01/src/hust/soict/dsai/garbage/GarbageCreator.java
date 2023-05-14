/*
	Read file and create garbage
 */

package hust.soict.dsai.garbage;

import java.nio.file.*;
import java.io.IOException;


public class GarbageCreator {

	public static void createWithString(byte[] inputBytes) {
		long startTime, endTime;
		startTime = System.currentTimeMillis();
		String outputString = "";
		for (byte b: inputBytes) 
			outputString += (char) b;
		endTime = System.currentTimeMillis();
		// print out
		System.out.println(endTime - startTime);
	}	// close createWithString


	public static void createWithStringBuffer(byte[] inputBytes) {
		long startTime, endTime;
		startTime = System.currentTimeMillis();
		StringBuffer sb = new StringBuffer();
		for (byte b: inputBytes) 
			sb.append((char) b);
		endTime = System.currentTimeMillis();
		// print out
		System.out.println(endTime - startTime);
	}	// close createWithStringBuffer

	
	public static void main(String[] args) throws IOException {
		String fileName = "/home/minh/School/Learning/20222/OOP/Lab/NguyenQuangMinh_20184293/Lab01/Data/data.in";
		byte[] inputBytes;
		inputBytes = Files.readAllBytes(Paths.get(fileName));
		// createWithString(inputBytes);
		createWithStringBuffer(inputBytes);
	}	// close main

}	// close GarbageCreator