/*	- A program to define an HelloWorld class
	- Create an object and Tell it to greet*/

class HelloWorld {

	// main
	public static void main(String[] args) {
		HelloWorld greeter = new HelloWorld();
		greeter.greet();
	}	// close main


	// IMPLEMENT

	// print a greet
	public void greet() {
		System.out.println("Hello the world!");
	}	// close greet
}	// close class