import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) throws FileNotFoundException{
	Scanner reader = new Scanner(new FileInputStream("euclid2.in"));
	
	PrintWriter writer = new PrintWriter("euclid2.out");
	 
	 
     int n = reader.nextInt(),i=0;

    while(i<n)
    {

    	int x=reader.nextInt();
    	int y= reader.nextInt();
    	while(x!=y)
    	{   
    		if(x>y) x-=y;
    		else    y-=x;
    	}
    	writer.write(x + "\n");
    	i++;
    	
    }
    
    writer.close();
    reader.close();}
}
