import java.awt.Font;
import java.awt.Graphics;

public class HashTable
   {
   public DataItem[] hashArray;    // array holds hash table
   private int arraySize;
   private DataItem nonItem;        // for deleted items
   private int crashCount = 0;
   public int crashLocation;
   private Font plainfont = new Font ("TimesRoman",Font.PLAIN,12);

   // -------------------------------------------------------------
   public HashTable(int size)       // constructor
      {
      arraySize = size;
      hashArray = new DataItem[arraySize];
      nonItem = new DataItem("-1");   // deleted item key is -1
      }
// -------------------------------------------------------------

   public int getCrashCount()
   {
	   return crashCount;
   }
   
   public void displayCrash(Graphics g)
   {
	   int xpos = 20, ypos = 30;
	   
	   int originallocation =0;		// hashvalue
       g.setFont(plainfont);
	   g.drawString("Hash Crash count is " + getCrashCount() ,xpos,ypos);       
       
       for (int i =0; i<hashArray.length; i++)		// loop through array
       {
    	   if (hashArray[i] != null)		// while not null
    	   {
    		   originallocation = hashFunc3(hashArray[i].getKey());		// calculate hashvalue
    		   
    		   if (originallocation != i)		// if the hashvalue doesn't equal to position
    		   {
    			   int x = i;			// set x to position
    			   
    			   while (originallocation != x)		// while the hashvalue doesn't equal to x
    			   {
    				   x++;				// increment x
    				   if (x == hashArray.length)
    				   {
    					   x = 0;			// set it to 0 if it reaches the array length
    				   }		   
    			   }
    			   // print the victims			   
    			   g.drawString("Hash Crash: " + hashArray[i].getKey()+ "             should be at           "+originallocation + "          found at " + i,xpos, ypos+=30);
    		   }
    	   }
       }
   }
   
   public void displayTable()
      {
      System.out.println("Table: ");
      for(int j=0; j<arraySize; j++)
         {
         if(hashArray[j] != null)
            System.out.println(hashArray[j].getKey() + " ");
         else
            System.out.println("** ");
         }
      System.out.println("");
      }
// -------------------------------------------------------------
   public int hashFunc(int key)
      {
      return key % arraySize;       // hash function
      }
   
   public int hashFunc3(String key)
   {
	   int hashVal = 0;
	   for (int j=0; j<key.length(); j++)
	   {
		   int letter = key.charAt(j) - 96;
		   hashVal = (hashVal * 27 + letter) % arraySize;
	   }
	   return hashVal;
   }

// -------------------------------------------------------------
   public void insert(DataItem item) // insert a DataItem
   // (assumes table not full)
      {
	   boolean count = false;
      String key = item.getKey();      // extract key
      int hashVal = hashFunc3(key);  // hash the key
                                    // until empty cell or -1,
      while(hashArray[hashVal] != null && !hashArray[hashVal].getKey().equalsIgnoreCase("-1"))
         {         
    	  if (count == false)
    	  {
    		  crashCount++;		// victim crash counter
    		  count = true;
    	  }

         ++hashVal;                 // go to next cell
         hashVal %= arraySize;      // wraparound if necessary
         }
      hashArray[hashVal] = item;    // insert item
      }  // end insert()
// -------------------------------------------------------------
   public DataItem delete(String key)  // delete a DataItem
      {
      int hashVal = hashFunc3(key);  // hash the key

      while(hashArray[hashVal] != null)  // until empty cell,
         {                               // found the key?
         if(hashArray[hashVal].getKey().equalsIgnoreCase(key))
            {
            DataItem temp = hashArray[hashVal]; // save item
            hashArray[hashVal] = nonItem;       // delete item
            return temp;                        // return item
            }
         ++hashVal;                 // go to next cell
         hashVal %= arraySize;      // wraparound if necessary
         }
      return null;                  // can't find item
      }  // end delete()
// -------------------------------------------------------------
   public DataItem find(String key)    // find item with key
      {
      int hashVal = hashFunc3(key);  // hash the key

      while(hashArray[hashVal] != null)  // until empty cell,
         {                               // found the key?
         if(hashArray[hashVal].getKey().equalsIgnoreCase(key))
            return hashArray[hashVal];   // yes, return item
         ++hashVal;                 // go to next cell
         hashVal %= arraySize;      // wraparound if necessary
         }
      return null;                  // can't find item
      }
// -------------------------------------------------------------
   }  // end class HashTable