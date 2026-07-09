import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	
	public static int cmmdc(int a , int b)
	{
		int r;
		
		while(b != 0)
		{
			r =a % b;
			a = b;
			b = r;
		}
		
		return a;
	}
	public static void main(String[] args) throws FileNotFoundException{
		Scanner sc = new Scanner(new FileInputStream("euclid2.in"));
		PrintWriter pw = new PrintWriter(new File("euclid2.out"));
		int n , a , b;
		
		n = sc.nextInt();
		
		while(n != 0)
		{
			a = sc.nextInt();
			b = sc.nextInt();
			
			
			pw.println(cmmdc(a , b));
			n--;
		}
		
		pw.close();
		sc.close();
	}
}
