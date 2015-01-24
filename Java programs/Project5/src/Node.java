// tree.java
// demonstrates binary tree
// to run this program: C>java TreeApp
// for Stack class
////////////////////////////////////////////////////////////////
public class Node
{
	public int iData;
	// data item (key)
	public double dData;
	// data item
	public Node leftChild;
	// this node’s left child
	public Node rightChild;
	// this node’s right child
	public int xPos;	// xposition
	public int yPos;	// yposition
	public int nlevel;
	
	public void displayNode()
	// display ourself
	{
		System.out.print('{');
		System.out.print(iData);
		System.out.print(", ");
		System.out.print(dData);
		System.out.print("} ");
	}
} // end class Node
////////////////////////////////////////////////////////////////
