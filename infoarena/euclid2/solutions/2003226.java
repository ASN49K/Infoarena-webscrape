import java.util.Scanner;

public class Main {

	private static int cmmdc(int a,int b)
	{
		int r;
		while(b!=0)
		{
			r = a%b;
			a = b;
			b = r;
		}
		return a;
	}
	
	public static void main(String[] args) {
		
		int n;
		int a,b;
		
		Scanner read = new Scanner(System.in);
		
		n = read.nextInt();
		
		while(n-- != 0)
		{
			a = read.nextInt();
			b = read.nextInt();
			
			System.out.println(cmmdc(a,b));
		}
	}

}
