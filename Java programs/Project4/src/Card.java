
/*****************************************************************
   Class Card, the derived class each card is one object of type Card
   May be placed in a file named Card.java
******************************************************************/
import java.awt.Image;

class Card extends Link {
  
  //--------------------Global Variables--------------
  //Holds the card image
  private Image cardimage;
  private int cardVal = 0;
  private int cardNum2 = 0;

  //---------------------Card Constructor-------------
  // Load the picture by passing card number
  public Card (int cardnum) 
  {
    cardimage = Project4.load_picture("images/gbCard" + cardnum + ".gif");
    cardNum2 = cardnum;
    // code ASSUMES there is an images sub-dir in your project folder
    if (cardimage == null) 
    {
      System.out.println("Error - image failed to load: images/gbCard" + cardnum + ".gif");
      System.exit(-1);
    }
  }
  
  // Return the next Card Object in list
  public Card getNextCard() 
  {
    return (Card)next;
  }
  
  // Return the current Card Object in list
  public Image getCardImage() 
  {
    return cardimage;
  }
  
  // returns the file number of the card
  int getCardNum()
  {
	  return cardNum2;
  }
  
  // returns the card value, used for aces
  public int getCardVal()
  {
	  return cardVal;
  }
  
  // set the card value, used for aces
  public void setCardVal(int x)
  {
	  cardVal = x;
  }
  
  // return the card value
  public int getCardValue(int cardNum)
  {	
  	if (cardNum == 0 || cardNum == 13 || cardNum == 26 || cardNum == 39)		// Aces
  		cardVal = 11;
  	else if (cardNum == 1 || cardNum == 14 || cardNum == 27 || cardNum == 40)	// Twos
  		cardVal = 2;
  	else if (cardNum == 2 || cardNum == 15 || cardNum == 28 || cardNum == 41)	// Threes
  		cardVal = 3;
  	else if (cardNum == 3 || cardNum == 16 || cardNum == 29 || cardNum == 42)	// Fours
  		cardVal = 4;
  	else if (cardNum == 4 || cardNum == 17 || cardNum == 30 || cardNum == 43)	// Fives
  		cardVal = 5;
  	else if (cardNum == 5 || cardNum == 18 || cardNum == 31 || cardNum == 44)	// Sixes
  		cardVal = 6;
  	else if (cardNum == 6 || cardNum == 19 || cardNum == 32 || cardNum == 45)	// Sevens
  		cardVal = 7;
  	else if (cardNum == 7 || cardNum == 20 || cardNum == 33 || cardNum == 46)	// Eights
  		cardVal = 8;
  	else if (cardNum == 8 || cardNum == 21 || cardNum == 34 || cardNum == 47)	// Nines
  		cardVal = 9;
  	else if (cardNum == 9 || cardNum == 22 || cardNum == 35 || cardNum == 48)	// Tens
  		cardVal = 10;
  	else if (cardNum == 10 || cardNum == 23 || cardNum == 36 || cardNum == 49)	// Jacks
  		cardVal = 10;
  	else if (cardNum == 11 || cardNum == 24 || cardNum == 37 || cardNum == 50)	// Queens
  		cardVal = 10;
  	else if (cardNum == 12 || cardNum == 25 || cardNum == 38 || cardNum == 51)	// Kings
  		cardVal = 10;
  	
  	return cardVal;	
  }
  
}  //end class Card

