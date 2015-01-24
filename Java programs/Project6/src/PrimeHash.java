/***************************************************************
Name: Karan Bhamra
Date: June 1st, 2010
Description: The user is given an option to create a hashtable
			of the size specified. Upon creation it prints the list
			of hash collisions, by stating the postitions found at
			and where they should have been. It also prints the name
			using the getKey() method.
--------------------------------------------------------------------
Project Number 6 - Comp Sci 182 - Data Structures
Start Code - Build your program starting with this code

Copyright 2005 Christopher C. Ferguson
This code may only be used with the permission of Christopher C. Ferguson

***************************************************************/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

@SuppressWarnings("serial")
public class PrimeHash extends JFrame implements ActionListener {

private static int win_xsize=700,win_ysize=500;//  window size

// Private state variables.

@SuppressWarnings("unused")
private Font boldfont = new Font ("TimesRoman",Font.BOLD,18);
//private Font plainfont = new Font ("TimesRoman",Font.PLAIN,12);

private JButton hashbutton,exitbutton;
private JPanel northPanel;
private MyJPanel centerPanel;
private JTextField hashsizefield;
private String thetext = "101";
private HashTable table;
private String[] names = { "fred" , "barney", "tom", "jerry", "larry", "moe","curly", 
		"betty" , "wilma", "bart", "homer", "marge", "maggie", "lisa", 
		"pebbles" , "bambam", "smithers", "burns", "milhouse", "george", "astro", 
		"dino" , "mickey", "minnie", "pluto", "goofy", "donald", "huey", 
		"louie" , "dewey", "snowwhite", "happy", "doc", "grumpy", "sneezy", 
		"dopey" , "sleepy", "bambi", "belle", "gaston", "tarzan", "jane", 
		"simba" , "scar", "mufasa", "ariel", "flounder", "bugs", "daffy", 
		"elmer" , "foghorn", "chickenhawk", "roger", "jessica", "hank", "bobby", 
		"peggy" , "spot", "pongo", "perdy", "buzz", "potatohead", "woody", 
		"chuckie" , "tommy", "phil", "lil", "angelica", "dill", "spike", 
		"pepe" , "speedy", "yosemite", "sam", "tweety", "sylvester", "granny", 
		"spiderman" , "batman", "superman", "supergirl", "robin", "jimmy","olsen", 
		"thing" , "flash", "silversurfer", "xmen", "pokemon", "joker", "wonderwoman"};
public int count;
////////////MAIN////////////////////////

public static void main(String[] args) {
        PrimeHash tpo  = new PrimeHash();

        tpo.addWindowListener(new WindowAdapter() {   // this exits the program when X box clicked
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
}

////////////CONSTRUCTOR/////////////////////

public PrimeHash ()  {
	   
       northPanel = new JPanel();
       northPanel.add(new Label("Enter a hashtable size: "));
       hashsizefield = new JTextField(thetext,20);
       northPanel.add(hashsizefield);
       hashbutton = new JButton("CreateHash");
       northPanel.add(hashbutton);
       hashbutton.addActionListener(this);
       exitbutton = new JButton("Exit");
       northPanel.add(exitbutton);
       exitbutton.addActionListener(this);
       getContentPane().add("North",northPanel);
       centerPanel = new MyJPanel();
       
       getContentPane().add("Center",centerPanel);

       // need more init stuff? try here.
       setSize(win_xsize,win_ysize);
       setLocationRelativeTo(null);
       setVisible(true);
       setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       table = new HashTable(101);
}

////////////BUTTON CLICKS ///////////////////////////

public void actionPerformed(ActionEvent e) {
         if (e.getSource()==exitbutton) {
               dispose(); System.exit(0);
         }

         if (e.getSource()==hashbutton) {
               thetext = hashsizefield.getText();
               table = new HashTable(Integer.parseInt(thetext));
                              
               for (int x = 0; x< names.length; x++)
               {
            	   table.insert(new DataItem(names[x]));		// insert names into hashtable
               } 
               
               
               //table.displayTable();
               count = table.getCrashCount();		// number of victims  
               repaint();
         }
} // end actionPerformed

class MyJPanel extends JPanel {

 ////////////    PAINT   ////////////////////////////////
  public void paintComponent (Graphics g) {
	  
	  table.displayCrash(g);

  }
} // End Of MyJPanel

}     // End Of PrimeHash