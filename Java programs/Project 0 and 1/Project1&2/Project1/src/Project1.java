/*******************************************************
 *
 * Project #1 - Starter code  Command Line Interface version
 *
 *  Hash disk file project
 *
 * copyright 2004 Christopher C. Ferguson
 * 
 * Name: Karan Bhamra
 * Date: Oct 19, 2010
 * Project #1- Parts 1 & 2 & 3
 * Description: Console window with 5 choices. 1st choice opens up the database file of users choice, and loads
 * 				it in memory, 2nd choice allows you to open and view each  bucket. 3rd choice allows you to 
 * 				close the open dbase file, 4th option allows you to create a new dbase file
 * 				and import data from another text file and create an index file. Option 5 exits the running application.
 *
 ****************************************************/
import java.io.*;
import java.util.Scanner;

class Project1 {
	public static final int RECORDSIZE = 512;
	public static final int SECTORSIZE = 4096;
	public static final int NUMSECTORS = 256;
	public static final int HASHSIZE = 1001;
	public static final int BUCKETSIZE = 4;

	private FakeDisk theDisk = null;   // our fake disk drive
	
	public static void main(String[] args) {
		Project1 tpo = new Project1();
        while (true) {
			tpo.showMenu();
        }
   }

    // Create and show a menu
	private void showMenu() {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a Command  1) Open DB  2) View a bucket  3) Close DB  4) Import a file 5) Exit: ");
		int command = input.nextInt();
		processCommand(command);
	}
	
	
	private void openDbFile(Scanner input) {
		System.out.print("Enter name of the file to open: ");
		String fname = input.nextLine();
		theDisk = new FakeDisk();

		if(theDisk.openDisk(fname, false) == false) {
			openDbFile(input);
      	}
	}
	
	private void openSector(Scanner input) {
		System.out.print("Enter the number of the sector to open: ");
		int sectornumber = input.nextInt();

		byte[] sector = theDisk.readSector(sectornumber);
		while (sector == null)	// keep reading till correct sector
    	{
    		System.out.println("Sector Error.");
    		System.out.print("Enter the number of the sector to open: ");
        	sectornumber = input.nextInt();
        	sector= theDisk.readSector(sectornumber);
    	}
		String stringsector = new String(sector);	// convert byte array to string
      	
		int x = 0, y = 0;
		System.out.println();
      	while (x < stringsector.length()){	// loop through and get each sector
      		y = x + 511;
      		if (y < stringsector.length()) {
				System.out.println(stringsector.substring(x,y).trim());
			}
      		x += 511;
      	}
      	System.out.println();
	}
	
	private void closeDbFile() {
    	System.out.println("File closed.\n");
    	theDisk.closeDisk();	// close the FakeDisk object	
	}
	
	private void importDbFile(Scanner input) {
    	theDisk = new FakeDisk();
    	
    	System.out.print("Enter name of new file: ");
    	String fname = input.nextLine();	// input file name
    	
    	theDisk.openDisk(fname, true);
    	theDisk.clearDisk();	// clear the disk with empty buckets
    	
    	int hash;		// holds the sector number generated from the hashFunc3()
    	String[] sector = new String[NUMSECTORS];	// hold each of the sectors
    	File file = new File("data.txt");
    	
    	String binname = fname.substring(0,fname.indexOf('.'));	// get userfilename
    	binname+=".bt";	// add extension
    	File binfile = new File(binname);
    	
    	try{
			PrintWriter output = new PrintWriter(binfile);
    		
    		for (int i=0; i<NUMSECTORS;i++){	// make sure its not null
    			sector[i] = "";
    		}
    		
    		Scanner scanner = new Scanner(file);	// load data.txt file
    		while (scanner.hasNextLine()){	// read through data.txt
    			String line = scanner.nextLine();
    			String email = line.substring(0, line.indexOf(","));	// holds the email address
    			hash = this.hashFunc3(email);	// hash the email address

    			output.println(hash+","+email);	// write it to index file
    			
    			while (line.length()<RECORDSIZE){	// add extra bytes to the record
    					line+=" ";
    			}
    			while (sector[hash].length()== SECTORSIZE)	// if full
    					hash++;		// increment to next sector
    			
    			sector[hash] += line;	// add new record
    		}
    
    			for (int i=0;i<sector.length;i++){	// write out the each sector
    				theDisk.writeSector(i, sector[i].getBytes());
    		}
    		
    		scanner.close();   // close scanner object
			output.close();
    		
    	} catch (Exception e){
    		e.printStackTrace();
    		System.out.println("File error.");	// print out file error message
    	}
	}
	
	private void exitProgram() {
		System.out.println("Program shutdown.\n");	//exit the program
		System.exit(0);
	}
	
	private void processCommand(int commandNumber) {
		Scanner input = new Scanner(System.in);
		switch(commandNumber) {
			case 1:
				openDbFile(input);
				break;
			case 2:
				openSector(input);
				break;
			case 3:
				closeDbFile();
				break;
			case 4:
				importDbFile(input);
				break;
			case 5:
				input.close();
				exitProgram();
				break;
			default: 
				System.out.println("Enter a valid choice.");
		}
    }

	private int hashFunc3(String key) {	// returns sector number
		int hashval = 0;
		for (int j = 0; j < key.length(); j++) {
			int letter = key.charAt(j) - 96;
			if (letter > 0 ) {
				hashval = (hashval * 27 + letter) % HASHSIZE;
			}
		}
		return hashval / BUCKETSIZE;
	}
}
