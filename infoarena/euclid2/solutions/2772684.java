import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.File;
import java.io.IOException;

public class Main{
	public static void main(String[] args) throws IOException{
		BufferedReader br =new BufferedReader(new FileReader(new File("euclid2.in")));
		PrintWriter out = new PrintWriter(new FileWriter("euclid2.out"));
			int n = Integer.parseInt(br.readLine());
			for(int tc = 1; tc<=n; tc++){
				String []arr = br.readLine().split(" ");
				int a = Integer.parseInt(arr[0]);
				int b = Integer.parseInt(arr[1]);
				int res = gcd(Math.max(a,b),Math.min(a,b));
				out.println(res);
			}
		out.flush();
	}
	private static int gcd(int a, int b){
		if(b==0) return a;
		else return gcd(b, a%b);
	}
}