import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) throws FileNotFoundException{
		Scanner sc = new Scanner(new FileInputStream("euclid2.in"));
		PrintWriter pw = new PrintWriter(new File("euclid2.out"));
		int n , a , b , r;
		
		n = sc.nextInt();
		
		while(n != 0)
		{
			a = sc.nextInt();
			b = sc.nextInt();
			
			while(b != 0)
			{
				r =a % b;
				a = b;
				b = r;
			}
			
			pw.println(a);
			n--;
		}
		
		pw.close();
		sc.close();
	}
}
