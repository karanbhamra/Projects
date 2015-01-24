/***************************************************************
Name: Karan Bhamra
Project: CS182, #5
Date Modified: 5/25/2010
Description: The program draws the inserted nodes from the Binary Tree
			It goes up to 7 levels (0-6) and draws them recursively.
			It checks which level its on and then draws the left child
			and the right child for all the cases in the switch statement.
			
----------------------------------------------------------------
Project Number 5 - Comp Sci 182 - Data Structures 
Start Code - Build your program starting with this code

Copyright 2003 Christopher C. Ferguson 
This code may only be used with the permission of Christopher C. Ferguson

***************************************************************/
import javax.swing.*; 
import java.awt.*; 
import java.awt.event.*; 
 

@SuppressWarnings("serial")
public class BinaryTree extends JFrame implements ActionListener {

private static int winxpos=0,winypos=0;// place window here

// Private state variables.

@SuppressWarnings("unused")
private Font boldfont = new Font ("TimesRoman",Font.BOLD,18); 
private Font plainfont = new Font ("TimesRoman",Font.PLAIN,12);

private JButton insertbutton,exitbutton; 
private JTextField infield; 
private JPanel northPanel; 
private MyPanel centerPanel; 
private static final int WINWIDTH = 700; 
private static final int WINHEIGHT = 500; 

private Tree theTree = new Tree(); 
 
 

////////////MAIN////////////////////////

public static void main(String[] args) { 
        BinaryTree tpo = new BinaryTree();

        tpo.addWindowListener(new WindowAdapter() {   // this exits the program when X box clicked 
            public void windowClosing(WindowEvent e) { 
                System.exit(0); 
            } 
        }); 
} 
  
 

////////////CONSTRUCTOR/////////////////////

public BinaryTree ()

{ 
       northPanel = new JPanel(); 
       northPanel.add(new Label("Enter a number to insert: ")); 
       infield = new JTextField("",20); 
       northPanel.add(infield); 
       insertbutton = new JButton("Insert"); 
       northPanel.add(insertbutton); 
       insertbutton.addActionListener(this); 
       exitbutton = new JButton("Exit"); 
       northPanel.add(exitbutton); 
       exitbutton.addActionListener(this); 
       getContentPane().add("North",northPanel);

       centerPanel = new MyPanel(); 
       getContentPane().add("Center",centerPanel); 

      theTree.insert(50, 1.5); 
      theTree.insert(25, 1.2); 
      theTree.insert(75, 1.7); 
      theTree.insert(12, 1.5); 
      theTree.insert(37, 1.2); 
      theTree.insert(43, 1.7); 
      theTree.insert(30, 1.5); 
      theTree.insert(33, 1.2); 
      theTree.insert(87, 1.7); 
      theTree.insert(93, 1.5); 
      theTree.insert(97, 1.5);  
 
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setSize(WINWIDTH,WINHEIGHT); 
      setLocation(winxpos,winypos); 
      setVisible(true);

} 
 

////////////BUTTON CLICKS ///////////////////////////

public void actionPerformed(ActionEvent e) {

          if (e.getSource()== exitbutton) { 
         dispose(); System.exit(0);

         } 

         if (e.getSource()== insertbutton) { 

                theTree.insert(Integer.parseInt(infield.getText()),2.1); 
                
                repaint(); 
         } 
} 

class MyPanel extends JPanel {

 ////////////    PAINT   //////////////////////////////// 
  public void paintComponent (Graphics g) { 
    // 
         g.setFont(plainfont); 
        
         theTree.displayTree(g,theTree.getRoot(),this.getWidth()/2,80, 1, theTree.getRoot()); 
  } 
} 
 

}     // End Of BinaryTree 