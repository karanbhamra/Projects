
public class BTree extends Tree234{
		
	public void split(Node thisNode)	// assumes node is full
	{
		int med = Node.getOrder()/2;	// index of data item to move up
				
	      //DataItem itemB, itemC;	// data items CREATE AN NEW DATAITEMS ARRAY// LEAVE 1 data item to be the 'center'
	      DataItem[] items = new DataItem[med-1];
	      DataItem center;
	      Node parent;	// parent node
	      //Node child2, child3;	// children nodes CREATE A NEW CHILD ARRAY
	      Node[] childs = new Node[med];
	      int itemIndex;

	      
	      for (int x=0; x<items.length;x++)		// remove items from this node
	    	  items[x] = thisNode.removeItem();
	      center = thisNode.removeItem();
	      //itemC = thisNode.removeItem();    // remove items from
	      //itemB = thisNode.removeItem();    // this node
	      
	      int index =0;
	      for (int y=med+1;y<childs.length;y++)			// remove children from this node
	    	  childs[index++] = thisNode.disconnectChild(y);
	      
	      //child2 = thisNode.disconnectChild(2); // remove children
	      //child3 = thisNode.disconnectChild(3); // from this node

	      Node newRight = new Node();       // make new node
	      if(thisNode==this.getRoot())                // if this is the root,
	         {
	         this.setRoot(new Node());                // make new root
	         parent = this.getRoot();                    // root is our parent
	         this.getRoot().connectChild(0, thisNode);   // connect to parent
	         }
	      else                              // this node not the root
	         parent = thisNode.getParent();    // get parent

	      // deal with parent
	      //itemIndex = parent.insertItem(itemB); // item B to parent
	      itemIndex = parent.insertItem(center);	// item B to parent
	      int n = parent.getNumItems();         // total items?

	      for(int j=n-1; j>itemIndex; j--)          // move parent's
	         {                                      // connections
	         Node temp = parent.disconnectChild(j); // one child
	         parent.connectChild(j+1, temp);        // to the right
	         }
	                                   // connect newRight to parent
	      parent.connectChild(itemIndex+1, newRight);

	      for (int x=0; x<items.length;x++)		// item C to newRight
	    	  newRight.insertItem(items[x]);
	      
	      for (int y=0; y<childs.length;y++)	// connect to 0 and 1
	    	  newRight.connectChild(y, childs[y]);	// on newRight
	    	  
	      
	      // deal with newRight
	     // newRight.insertItem(itemC);       // item C to newRight
	     // newRight.connectChild(0, child2); // connect to 0 and 1
	     // newRight.connectChild(1, child3); // on newRight
		
	}


}
