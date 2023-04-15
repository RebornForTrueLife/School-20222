/*	
	The program is used to get the number of day of month given its month and year 
 */

import java.util.Scanner;


public class DayOfMonth {

	// Variable members
	public static String[] listMonth = {"January", "Febuary", "March", "April", "May", "June", 
					"July", "August", "September", "October", "November", "December"};


	// FUNC MEMBERs
	// to check if a given string is the given month
	public static int check_month(String inputName, int month) {
		int index = month - 1;
		String monthName = listMonth[index];
		String listValid[];
		listValid = new String [4];
		listValid[0] = monthName;
		listValid[1] = monthName.substring(0, 3);
		listValid[2] = monthName.substring(0, 3) + ".";
		listValid[3] = "" + month;
		for (int i = 0; i < 4; i ++ ) {
			if (inputName.equals(listValid[i]))
				return month;
		}	// close for
		return -1;
	}	// close check_month 


	// to check if a given string is matched with a valid month or not
	public static int check_month(String inputName) {
		// check 12 months
		for (int i = 1; i <= 12; i ++ ) {
			if (check_month(inputName, i) != -1)
				return i;
		}	// close
		return -1;
	}	// close check_month


	// check if a year is a leap year
	public static boolean check_leap_year(int year) {
		// check if year is a leap year
		if ((year % 100) == 0) {		// divisible by 100
			if ((year % 400) == 0)
				return true;
		} else {
			if ((year % 4) == 0)
				return true;
		}	// close if
		return false;
	}	// close check_leap_year


	// to get number of days in given month and year
	public static int get_number_day(String inputMonth, int year) {
		// check if year is valid
		if (year < 0) {
			System.out.println("Invalid year, must be non-negative");
			System.exit(8);
		}	// close if
		// check if input month is valid
		int month = check_month(inputMonth);
		if (month == -1) {
			System.out.println("Invalid month");
			System.exit(8);
		}	// close if
		// get number of day in month
		switch (month) {
		case 1:
			return 31;
		case 2:
			if (check_leap_year(year))
				return 29;
			return 28;
		case 3:
			return 31;
		case 4:
			return 30;
		case 5:
			return 31;
		case 6:
			return 30;
		case 7:
			return 31;
		case 8:
			return 31;
		case 9:
			return 30;
		case 10:
			return 31;
		case 11:
			return 30;
		case 12:
			return 31;
		default:
			break;
		}	// close switch
		// invalid month
		return -1;
	}	// close get_number_day


	// MAIN
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter month: ");
		String inputName = scan.nextLine();
		System.out.print("Enter year: ");
		int year = scan.nextInt();
		
		System.out.println("Number of day is: " + get_number_day(inputName, year));
		scan.close();
	}	// close main
}	// close class