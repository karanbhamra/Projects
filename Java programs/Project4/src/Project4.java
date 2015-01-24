/***************************************************************
 * 
 * Name: Karan Bhamra
 * Project: CS182, 4
 * Date Modified: May 10, 2010
 * Description: There are four buttons: new button, hit, stand and exit.
 * 				When the player hits, he is given another card and the face value
 * 				of the card is added to the score. When the player stands, it becomes
 * 				computers turn to hit or deal, the dealer hits on 16 and stands on 17.
 * 				There are numerous checks to see who wins, dealer always wins on tie.
 * 				The player starts out with 500 dollars, and each loss reduces it by 50.
 * 				When the player reaches 0 dollars, he is kicked out of the game.
----------------------------------------------------------------------------------------
  Project Number 4 - Comp Sci 182 - Data Structures (w/ Swing)
  Start Code - Build your program starting with this code
               Card Game
  Copyright 2005 Christopher C. Ferguson
  This code may only be used with the permission of Christopher C. Ferguson
  
***************************************************************/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

@SuppressWarnings("serial")
public class Project4 extends JFrame implements ActionListener {

  private JButton exitButton, newButton, hitButton, standButton;
  private CardList theDeck = null, playerDeck = null, dealerDeck = null;
  private JPanel northPanel, southPanel;
  private MyPanel centerPanel;
  private static JFrame myFrame = null;
  private int playerMoney;
  private JLabel playerscore = new JLabel("Player Score: ");
  private JLabel emptyspace1=new JLabel("   "), emptyspace2=new JLabel("   ");
  private JLabel dealerscore = new JLabel("Dealer Score: ");
  private JLabel money = new JLabel("Total money: $");
  private boolean showcard;		// true = reveal dealer card, false = hide
  private int scoreplayer, scoredealer, realscoredealer, playerAces, dealerAces;

  ////////////              MAIN      ////////////////////////
  public static void main(String[] args) {
     @SuppressWarnings("unused")
	Project4 tpo = new Project4();
  }

  ////////////            CONSTRUCTOR   /////////////////////
  public Project4 ()
  {
        myFrame = this;                 // need a static variable reference to a JFrame object
        myFrame.setTitle("BlackJack by Karan Bhamra");
        playerMoney = 500;
        
        // Buttons panel
        northPanel = new JPanel();
        northPanel.setBackground(new Color(175,1,0));
        
        // Labels panel
        southPanel = new JPanel();
        southPanel.setBackground(Color.black);
        
        // add buttosn to panel
        newButton = new JButton("New Deck");
        northPanel.add(newButton);
        newButton.addActionListener(this);    
        hitButton = new JButton("Hit");
        northPanel.add(hitButton);
        hitButton.addActionListener(this);
        standButton = new JButton("Stand");
        northPanel.add(standButton);
        standButton.addActionListener(this);
        exitButton = new JButton("Exit");
        northPanel.add(exitButton);
        exitButton.addActionListener(this);
        
        // add labels
        playerscore.setForeground(Color.white);
        dealerscore.setForeground(Color.white);
        money.setForeground(Color.white);
        southPanel.add(playerscore);
        southPanel.add(emptyspace1);
        southPanel.add(dealerscore);
        southPanel.add(emptyspace2);
        southPanel.add(money);
        
        // add panels to the frame
        getContentPane().add("North",northPanel);
        getContentPane().add("South", southPanel);

        centerPanel = new MyPanel();
        getContentPane().setBackground(new Color(64,107,2));
        getContentPane().add("Center",centerPanel);

        initGame();		// initialize the game variables

        setSize(850,500);
        this.setLocationRelativeTo(null);	// center the window
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	// X button exits the program

        setVisible(true);
   }
  
  public void initGame()		// populates the player hand and the dealer hand from the card deck
  {
	  showcard = false;		// if true, it will reveal the dealers hidden card
	  scoreplayer=0;
	  scoredealer=0;
	  playerAces = 0;
	  dealerAces = 0;
	  theDeck = new CardList(52);
	  theDeck.shuffle();  
	  playerDeck = new CardList(0);
      dealerDeck = new CardList(0);
      
      // buttons disabled after stand and enabled on new game
      hitButton.setEnabled(true);
      standButton.setEnabled(true);
      
      // if player runs out of money
      if (playerMoney == 0)
      {
    	  JOptionPane.showMessageDialog(this, "You have run out of money. Get lost.");
    	  dispose();
    	  System.exit(0);
      }
     
      // insert first card into players deck
	  playerDeck.insertCard(new Card(theDeck.getFirstCard().getCardNum()));
	  checkPlayerAces();
	  scoreplayer = playerDeck.getFirstCard().getCardValue(playerDeck.getFirstCard().getCardNum());
	  theDeck.deleteCard(0);
	  
	  // insert second card into players deck
	  playerDeck.insertCard(new Card(theDeck.getFirstCard().getCardNum()));
	  checkPlayerAces();
	  scoreplayer += playerDeck.getFirstCard().getCardValue(playerDeck.getFirstCard().getCardNum());
	  theDeck.deleteCard(0);
	  
	  // insert first card into dealer deck
	  // scoredealer will keep track of displayed dealer card, realscoredealer calculates both cards
	  dealerDeck.insertCard(new Card(theDeck.getFirstCard().getCardNum()));
	  checkDealerAces();
	  scoredealer = dealerDeck.getFirstCard().getCardValue(dealerDeck.getFirstCard().getCardNum());
	  realscoredealer = dealerDeck.getFirstCard().getCardValue(dealerDeck.getFirstCard().getCardNum());
	  theDeck.deleteCard(0);
	  
	  // insert second card into dealer deck
	  dealerDeck.insertCard(new Card(theDeck.getFirstCard().getCardNum()));
	  checkDealerAces();
	  realscoredealer += dealerDeck.getFirstCard().getCardValue(dealerDeck.getFirstCard().getCardNum());
	  theDeck.deleteCard(0);

	  // update the score labels on the screen
	  repaint();
	  playerscore.setText("Player score: ");
	  dealerscore.setText("Dealer score: ");
	  money.setText("Total money: $");
	  playerscore.setText(playerscore.getText()+ scoreplayer);
	  dealerscore.setText(dealerscore.getText()+ scoredealer);
	  money.setText(money.getText()+playerMoney);
	  

	  repaint();
	  
	  // checks the win conditions for the first two cards of player and dealer
	  if (scoreplayer == 21 && realscoredealer < 21)	
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You win. Dealer loses.");
    	  playerMoney+=50;
      }
	  if (scoreplayer == 21 && realscoredealer == 21)	
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You lose. Dealer wins.");
    	  playerMoney-=50;
      }
	  if (scoreplayer < 21 && realscoredealer == 21)	
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You lose. Dealer wins.");
    	  playerMoney-=50;
      }
	  repaint();
	  
	  // update the labels
	  playerscore.setText("Player score: ");
	  dealerscore.setText("Dealer score: ");
	  money.setText("Total money: $");
	  playerscore.setText(playerscore.getText()+ scoreplayer);
	  dealerscore.setText(dealerscore.getText()+ scoredealer /*+ "    " + realscoredealer*/);
	  money.setText(money.getText()+playerMoney);
	  
  }


  ////////////   BUTTON CLICKS ///////////////////////////
  public void actionPerformed(ActionEvent e) {

	  // Exit button closes the JVM
      if (e.getSource()== exitButton) {
        dispose(); System.exit(0);
      }
      
      // New Deck button reinitializes the game
      if (e.getSource()== newButton) {
        initGame();
        repaint();
      }
      
      // On hit, another card is added to the player deck and removed from deck
      if (e.getSource()== hitButton) {
    	  playerDeck.insertCard(new Card(theDeck.getFirstCard().getCardNum()));
    	  checkPlayerAces();
    	  scoreplayer += playerDeck.getFirstCard().getCardValue(playerDeck.getFirstCard().getCardNum());
    	  checkAces();
    	  theDeck.deleteCard(0);

    	  // Update the labels and check the hit win conditions
    	  playerscore.setText("Player score: ");
    	  playerscore.setText(playerscore.getText()+ scoreplayer);
          repaint();
          hitChecks();
         }
      
      // On stand, the dealer loops through and hits if the his total is less than 17
      if (e.getSource()== standButton) {
    	  boolean endloop = false;		// checks to see when to exit out of the loop
    	  hitButton.setEnabled(false);

    	  while (realscoredealer < 17 && endloop == false)  //dealer hits on 16 or lower, stands otherwise
    	  {
    		  // Insert a new card into dealers hand and check for aces and update the text
    		  dealerDeck.insertCard(new Card(theDeck.getFirstCard().getCardNum()));
    		  checkDealerAces();
    		  theDeck.deleteCard(0);
        	  realscoredealer += dealerDeck.getFirstCard().getCardValue(dealerDeck.getFirstCard().getCardNum());
        	  scoredealer += dealerDeck.getFirstCard().getCardValue(dealerDeck.getFirstCard().getCardNum()); 
        	  endloop = checkAces2();
        	  
        	  dealerscore.setText("Dealer score: ");
        	  dealerscore.setText(dealerscore.getText()+ scoredealer /*+ "    " + realscoredealer*/);
        	  repaint();
    	  }
    	  
    	  // Check the win conditions for stand
    	  standChecks();
    	  standButton.setEnabled(false);
    	  repaint();   	  
         }
  }

  public void checkPlayerAces()
  {
	  // This method checks for aces in players hand
	  // If the first card in the players deck is an ace, increment the number of player aces counter
	  if (theDeck.getFirstCard().getCardValue(playerDeck.getFirstCard().getCardNum()) == 11)
		  playerAces++;
	  
	  // If the player aces counter is greater than zero and if 10 is added check if the total will be > than 21
	  if (playerAces > 0 && (scoreplayer +10) >21 )
	  {
		  // If playerscore + 11 goes over 21
		  if ((scoreplayer + 11) > 21)
		  {
			  // Decrease the player score by 10 and then decrement the number of aces counter by 1
			  playerAces--;
			  scoreplayer -=10;
			  playerscore.setText("Player score: ");
	    	  playerscore.setText(playerscore.getText()+ scoreplayer);
			  
		  }
	  }
	  
  }
  public void checkDealerAces()
  {
	  // Performs the same checks as checkPlayerAces() method
	  if (theDeck.getFirstCard().getCardValue(dealerDeck.getFirstCard().getCardNum()) == 11)
		  dealerAces++;
	  if (dealerAces > 0 && (realscoredealer +10) >21 )
	  {
		  if ((realscoredealer + 11) > 21)
		  {
			  dealerAces--;
			  realscoredealer -=10;
			  dealerscore.setText("Dealer score: ");
	    	  dealerscore.setText(dealerscore.getText()+ scoredealer);
			  
		  }
	  }	  
  }
  
  public void checkAces()
  {
	  // Checks is the number of aces is greater than 0 and the score is greater than 21
	  while (playerAces > 0 && scoreplayer > 21)
	  {
		  // Reduce score by 10 and then decrement playeraces counter
		  scoreplayer -=10;
		  playerAces--;
	  }
	  
  }
  
  public boolean checkAces2()
  {
	  // Returns the exit value for the dealer hit loop
	  while (dealerAces > 0 && realscoredealer >21)
	  {
		  realscoredealer -=10;
		  dealerAces--;
		  return false;
	  }
	  return true;		  
  }
  
  // Checks the winning combinations on a card hit
  public void hitChecks()
  {
	  if (scoreplayer>21 && realscoredealer <=21)	// if you bust and dealer is under
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You busted. Dealer wins.");
    	  playerMoney-=50;
      }
      if (scoreplayer == 21 && realscoredealer == 21)	// if dealer and player hits 21
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "Tie. Dealer wins.");
    	  playerMoney-=50;
      }
      if (scoreplayer == 21 && realscoredealer <21)	// you hit 21 and dealer is less than 21
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You win. Dealer loses.");
    	  playerMoney+=50;
      }
      repaint();
	  
  }
  
  // Checks the winning combinations on card stand
  public void standChecks()
  {
	  if (scoreplayer < 21 && realscoredealer < 21 && scoreplayer < realscoredealer)	
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You lose. Dealer wins.");
    	  playerMoney-=50;
      }
	  if (scoreplayer < 21 && realscoredealer < 21 && scoreplayer > realscoredealer)	
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You win. Dealer loses.");
    	  playerMoney+=50;
      }
	  if (scoreplayer < 21 && realscoredealer == 21)	
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You lose. Dealer wins.");
    	  playerMoney-=50;
      }
	  if (scoreplayer < 21 && realscoredealer > 21)	
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You win. Dealer busted.");
    	  playerMoney+=50;
      }
	  if (scoreplayer == 21 && realscoredealer == 21)	
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You lose. Dealer wins.");
    	  playerMoney-=50;
      }
	  if (scoreplayer == 21 && realscoredealer < 21)	
      {
    	  showcard = true;
    	  JOptionPane.showMessageDialog(this, "You win. Dealer loses.");
    	  playerMoney+=50;
      }
	  if (scoreplayer == realscoredealer)
	  {
		  showcard = true;
		  JOptionPane.showMessageDialog(this, "Tie. Dealer wins.");
		  playerMoney-=50;
	  }
	  repaint();
	  
  }
  

// This routine will load an image into memory
//
public static Image load_picture(String fname)
{
        // Create a MediaTracker to inform us when the image has
        // been completely loaded.
        Image image;
        MediaTracker tracker = new MediaTracker(myFrame);


        // getImage() returns immediately.  The image is not
        // actually loaded until it is first used.  We use a
        // MediaTracker to make sure the image is loaded
        // before we try to display it.

        image = myFrame.getToolkit().getImage(fname);

        // Add the image to the MediaTracker so that we can wait
        // for it.
        tracker.addImage(image, 0);
        try { tracker.waitForID(0); }
        catch ( InterruptedException e) { System.err.println(e); }

        if (tracker.isErrorID(0)) { image=null;}
        return image;
}
// --------------   end of load_picture ---------------------------

class MyPanel extends JPanel {

 ////////////    PAINT   ////////////////////////////////
  public void paintComponent (Graphics g) {
    
	//display player cards
    int xpos = 25, ypos = 100;
    if (playerDeck == null) return;
    Card current = playerDeck.getFirstCard();
    g.setColor(Color.white);
    g.drawString("Player", xpos, ypos-20);
    while (current!=null) {
       Image tempimage = current.getCardImage();
       g.drawImage(tempimage, xpos, ypos, this);
        //note: tempimage member variable must be set BEFORE paint is called
       xpos += 80;
       if (xpos > 700) {
          xpos = 25; ypos += 105;
       }
       current = current.getNextCard();
    } //while
    
    
    // display dealer cards
    xpos = myFrame.getWidth()-100;
    ypos = 100;
    if (dealerDeck == null) return;
    current = dealerDeck.getFirstCard();
    g.setColor(Color.white);
    g.drawString("Dealer", xpos, ypos-20);
    int counter=0;
    while (current!=null) {
       Image tempimage = current.getCardImage();
       
       // hide the first dealer card
       if (counter==0 && showcard == false)
       {
    	   tempimage = Project4.load_picture("images/gbCard52.gif");
    	   counter = 1;
    	   
       }
       else		// reveal the dealer card
    	   tempimage = current.getCardImage();
           
       g.drawImage(tempimage, xpos, ypos, this);
        //note: tempimage member variable must be set BEFORE paint is called
       xpos -= 80;
       if (xpos < 400) {
          xpos = 25; ypos += 105;
       }
       current = current.getNextCard();
    } //while
    
    
    // display back of the card in the middle
    g.setColor(Color.white);
    g.drawString("Deck", 400, 80);
    Image backcardimage = theDeck.backCard();
    g.drawImage(backcardimage, 400,100,this);
 
  }

}

}    // End Of class Project4