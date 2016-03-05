// Author: Karan Bhamra
// Email: karan.bhamra@gmail.com
// Date: Feb 23, 2016

import java.util.*;

public class Caesar
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		String plaintext = "meet me after the toga party";
		// Remove all spaces from the plaintext
		String newtext = plaintext.replaceAll("\\s+","");
		
		System.out.println("Original text: " + newtext);
		
		// output all the shifts for each of the 26 keys
		// EXPECTED: PHHW PH DIWHU WKH WRJD SDUWB
		for (int i = 0; i < 26; i++)
		{
			System.out.println ("Shift of " + (i + 1) + ": " + Caesar.Caesar(newtext, i));
		}
		
	}
	
	public static String Caesar(String plaintext, int key)
	{
		String output = "";
		String alphabet = "abcdefghijklmnopqrstuvwxyz";
		int newChar = 0;
		
		// shift it by key value and then get the new character
		for (int i = 0; i < plaintext.length(); i++)
		{
			newChar = (plaintext.toLowerCase().charAt(i) + key) % 26;
			
			output += "" + (alphabet.charAt(newChar));
		}
		
		return output;
	}
}
