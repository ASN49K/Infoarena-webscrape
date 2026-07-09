import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws FileNotFoundException, IOException{
		Scanner sc;
		sc = new Scanner(new File("E:\\Informatica\\Java\\Infoarena\\bin\\euclid2.in"));
		PrintWriter wr = new PrintWriter("E:\\Informatica\\Java\\Infoarena\\bin\\euclid2.out");
		int T = sc.nextInt();
		while(T-->0) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int rez = cmmdc(a,b);
			wr.println(rez);
			//System.out.println(rez);
		}
		sc.close();
		wr.close();
	}
	public static int cmmdc(int x, int y) {
		if(y!=0)
			return cmmdc(y,x%y);
		return x;
	}
}
