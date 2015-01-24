
import java.awt.Graphics;
import java.util.*;               // for Stack class
////////////////////////////////////////////////////////////////

public class Tree
   {
   private Node root;             // first node of tree
   private int nodeLevel;
   

// -------------------------------------------------------------
   public Tree()                  // constructor
      { 
	   root = null;
	   nodeLevel = -1;
	   }            // no nodes in tree yet
// -------------------------------------------------------------
   public Node find(int key)      // find node with given key
      {                           // (assumes non-empty tree)
      Node current = root;               // start at root
      while(current.iData != key)        // while no match,
         {
         if(key < current.iData)         // go left?
            current = current.leftChild;
         else                            // or go right?
            current = current.rightChild;
         if(current == null)             // if no child,
            return null;                 // didn't find it
         }
      return current;                    // found it
      }  // end find()
// -------------------------------------------------------------
   public void insert(int id, double dd)
      {
      Node newNode = new Node();    // make new node
      newNode.iData = id;           // insert data
      newNode.dData = dd;
      if(root==null)                // no node in root
         root = newNode;
      else                          // root occupied
         {
         Node current = root;       // start at root
         Node parent;
         while(true)                // (exits internally)
            {
            parent = current;
            if(id < current.iData)  // go left?
               {
               current = current.leftChild;
               if(current == null)  // if end of the line,
                  {                 // insert on left
                  parent.leftChild = newNode;
                  return;
                  }
               }  // end if go left
            else                    // or go right?
               {
               current = current.rightChild;
               if(current == null)  // if end of the line
                  {                 // insert on right
                  parent.rightChild = newNode;
                  return;
                  }
               }  // end else go right
            }  // end while
         }  // end else not root
      }  // end insert()
// -------------------------------------------------------------
   public boolean delete(int key) // delete node with given key
      {                           // (assumes non-empty list)
      Node current = root;
      Node parent = root;
      boolean isLeftChild = true;

      while(current.iData != key)        // search for node
         {
         parent = current;
         if(key < current.iData)         // go left?
            {
            isLeftChild = true;
            current = current.leftChild;
            }
         else                            // or go right?
            {
            isLeftChild = false;
            current = current.rightChild;
            }
         if(current == null)             // end of the line,
            return false;                // didn't find it
         }  // end while
      // found node to delete

      // if no children, simply delete it
      if(current.leftChild==null && current.rightChild==null)
         {
         if(current == root)             // if root,
            root = null;                 // tree is empty
         else if(isLeftChild)
            parent.leftChild = null;     // disconnect
         else                            // from parent
            parent.rightChild = null;
         }

      // if no right child, replace with left subtree
      else if(current.rightChild==null)
         if(current == root)
            root = current.leftChild;
         else if(isLeftChild)
            parent.leftChild = current.leftChild;
         else
            parent.rightChild = current.leftChild;

      // if no left child, replace with right subtree
      else if(current.leftChild==null)
         if(current == root)
            root = current.rightChild;
         else if(isLeftChild)
            parent.leftChild = current.rightChild;
         else
            parent.rightChild = current.rightChild;

      else  // two children, so replace with inorder successor
         {
         // get successor of node to delete (current)
         Node successor = getSuccessor(current);

         // connect parent of current to successor instead
         if(current == root)
            root = successor;
         else if(isLeftChild)
            parent.leftChild = successor;
         else
            parent.rightChild = successor;

         // connect successor to current's left child
         successor.leftChild = current.leftChild;
         }  // end else two children
      // (successor cannot have a left child)
      return true;                                // success
      }  // end delete()
   
   public void displayTree(Graphics g, Node localTree, int x, int y, int lorCall, Node parent)
   {   
	   if(localTree != null)
       {
		   nodeLevel++;		// level of the node, starts out at -1 and increments to 0th level
		   localTree.xPos = x;		// set the xpos and ypos of the local node
		   localTree.yPos = y;
		   
		   localTree.nlevel = nodeLevel;	// set the localtree nlevel
		   
		   switch(nodeLevel)
		   {
		   		// level 0
		   		case 0: g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
				   		g.drawOval(localTree.xPos-2, localTree.yPos-15, 20,20);
				   		break;
				// level 1
		   		case 1: 
		   			if (lorCall == 0) {			// left root
		   				localTree.xPos -= 120;
		   				localTree.yPos += 30;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);
		   				
		   			}
		   			else		// right root
		   			{
		   				localTree.xPos += 120;
		   				localTree.yPos += 30;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);
		   				
		   			}
		   			break;
		   		// level 2
		   		case 2: 
		   			if (lorCall == 0) {			// left root
		   				localTree.xPos -= 60;
		   				localTree.yPos += 40;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);
		
		   			}
		   			else		// right root
		   			{
		   				localTree.xPos += 60;
		   				localTree.yPos += 40;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);
		   			}
		   			break;
		   			// level 3
		   		case 3:
		   			if (lorCall == 0) {			// left root
		   				localTree.xPos -= 40;
		   				localTree.yPos += 40;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);

		   			}
		   			else		// right root
		   			{
		   				localTree.xPos += 40;
		   				localTree.yPos += 40;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);   				
		   			
		   			}
		   			break;
		   			// level 4
		   		case 4:
		   			if (lorCall == 0) {			// left root
		   				localTree.xPos -= 30;
		   				localTree.yPos += 40;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);
		   		
		   			}
		   			else		// right root
		   			{
		   				localTree.xPos += 30;
		   				localTree.yPos += 40;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);
		   			
		   			}
		   			break;
		   			// level 5
		   		case 5:
		   			if (lorCall == 0) {			// left root
		   				localTree.xPos -= 10;
		   				localTree.yPos += 40;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);
		   				
		   			}
		   			else		// right root
		   			{
		   				localTree.xPos += 10;
		   				localTree.yPos += 40;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);
		   			
		   			}
		   			break;
		   			// level 6
		   		case 6:
		   			if (lorCall == 0) {			// left root
		   				localTree.xPos -= 20;
		   				localTree.yPos += 40;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);
		   			
		   			}
		   			else		// right root
		   			{
		   				localTree.xPos += 20;
		   				localTree.yPos += 40;
		   				g.drawString(""+localTree.iData, localTree.xPos, localTree.yPos);
		   				g.drawOval(localTree.xPos-2, localTree.yPos-15, 20, 20);
		   				
		   			}
		   			break;  				   				
		   }	// switch statement end
		   
		   if (parent.xPos != localTree.xPos)
			   g.drawLine(localTree.xPos+8, localTree.yPos-15, parent.xPos+5, parent.yPos+5);
		   
		   displayTree(g,localTree.leftChild, localTree.xPos, localTree.yPos, 0, localTree);
		   displayTree(g,localTree.rightChild, localTree.xPos, localTree.yPos, 1, localTree);		   
	   
		   nodeLevel--;
       }
   
   }
   
// -------------------------------------------------------------
   public Node getRoot()
   {
	// returns the root
	return root;
	   
   }
//--------------------------------------------------------------
   // returns node with next-highest value after delNode
   // goes to right child, then right child's left descendents
   private Node getSuccessor(Node delNode)
      {
      Node successorParent = delNode;
      Node successor = delNode;
      Node current = delNode.rightChild;   // go to right child
      while(current != null)               // until no more
         {                                 // left children,
         successorParent = successor;
         successor = current;
         current = current.leftChild;      // go to left child
         }
                                           // if successor not
      if(successor != delNode.rightChild)  // right child,
         {                                 // make connections
         successorParent.leftChild = successor.rightChild;
         successor.rightChild = delNode.rightChild;
         }
      return successor;
      }
// -------------------------------------------------------------
   public void traverse(int traverseType)
      {
      switch(traverseType)
         {
         case 1: System.out.print("\nPreorder traversal: ");
                 preOrder(root);
                 break;
         case 2: System.out.print("\nInorder traversal:  ");
                 inOrder(root);
                 break;
         case 3: System.out.print("\nPostorder traversal: ");
                 postOrder(root);
                 break;
         }
      System.out.println();
      }
// -------------------------------------------------------------
   private void preOrder(Node localRoot)
      {
      if(localRoot != null)
         {
         System.out.print(localRoot.iData + " ");
         preOrder(localRoot.leftChild);
         preOrder(localRoot.rightChild);
         }
      }
// -------------------------------------------------------------
   private void inOrder(Node localRoot)
      {
      if(localRoot != null)
         {
         inOrder(localRoot.leftChild);
         System.out.print(localRoot.iData + " ");
         inOrder(localRoot.rightChild);
         }
      }
// -------------------------------------------------------------
   private void postOrder(Node localRoot)
      {
      if(localRoot != null)
         {
         postOrder(localRoot.leftChild);
         postOrder(localRoot.rightChild);
         System.out.print(localRoot.iData + " ");
         }
      }
   }  // end class Tree
