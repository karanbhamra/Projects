
/*****************************************************************
   Class Link, the base class for a link list of playing cards
   May be placed in a file named Link.java

******************************************************************/
class Link {
  
  //----------------------Global Variables----------------------
  protected Link next;

  //----------------------Public Methods------------------------	
  public Link getNext() 
  { 
  	return next; 
  }
  
  public void setNext(Link newnext) 
  { 
  	next = newnext; 
  }

}  // end class Link
