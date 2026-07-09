import java.io.*;

public class Euclid {
	public static void main(String[] args) throws IOException {
			BufferedReader reader = new BufferedReader(new FileReader("euclid2.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter("euclid2.out"));
			int n = Integer.parseInt(reader.readLine());
			for (int i = 0; i < n; i++) {
				String[] nr = reader.readLine().split("\\s+");
				writer.write(String.valueOf(cmmdc(Integer.parseInt(nr[0]), Integer.parseInt(nr[1]))));
				writer.newLine();
			}
			reader.close();
			writer.flush();
			writer.close();		
	}
	
	public static int cmmdc(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return cmmdc(b, a % b);
		}
	}
}