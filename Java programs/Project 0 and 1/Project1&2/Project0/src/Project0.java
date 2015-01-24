import java.util.Scanner;

public class Project0 {
	private static int SECTORSIZE = 4096;     // size of each disksector
	private static int MAXSECTORS = 256;     // max number of sectors
	
	public static void main(String[] args) throws Exception{	
		String readfile = userFileInput();
		readFile(readfile);
		String savefile = userFileOutput();
		saveFile(savefile);
		System.exit(0);
		
	}		// end of main
	
	public static String userFileInput()
	{
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the name of the file to dump: ");
		String fname = input.nextLine();	// Input filename
		//input.close();
		
		return fname;	
	}	// end of userInput()
	public static String userFileOutput()
	{
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the name of the file to save: ");
		String fname = input.nextLine();	// Input filename
		//input.close();
		
		return fname;	
	}	// end of userInput()

	@SuppressWarnings("static-access")
	public static void readFile(String fname)
	{
		FakeDisk tpo = new FakeDisk();	
		tpo.openDisk(fname, false);		// load up the file
		int i=0;	// sector counter
		while (tpo.readSector(i)!=null)
		{
			byte[] sectors = new byte[16];
			sectors = tpo.readSector(i);	// Read the current sector into byte array		
			String record = new String(sectors);		// convert the byte[] to string
			System.out.println("Sector " + i + ": ");	// print out the records
			System.out.println(record);
			
			i++;	// next sector
		}

		tpo.closeDisk();	// close file
	} // end of readFile()
	
	public static void saveFile(String fname)
	{
		FakeDisk tpo = new FakeDisk();
		tpo.openDisk(fname, true);
		
		tpo.clearDisk();
		byte[] buffer= new byte[1024];
//		for (int x=0; x<3;x++)
//		{
//			tpo.writeSector(x, buffer);
//		}
		for (int x=0; x<buffer.length;x++)
		{
			buffer[x] = 0;
		}
		
		tpo.writeSector(0,buffer);
		
		tpo.closeDisk();
	}

	
}	// end of Project0
