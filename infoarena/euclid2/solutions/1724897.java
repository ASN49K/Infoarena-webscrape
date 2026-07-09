import java.io.*;

public class Main {
	public static int cmmdc(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return cmmdc(b, a % b);
		}
	}
	
	public static void main(String[] args) throws IOException {
			BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("euclid2.in")));
			BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("euclid2.out")));
			int n = Integer.parseInt(reader.readLine()), c = 0;
			for (String line; (line = reader.readLine()) != null;) {
				String[] nr = line.split(" ");
				writer.write(String.valueOf(cmmdc(Integer.parseInt(nr[0]), Integer.parseInt(nr[1]))));
				writer.newLine();
			}
			reader.close();
			writer.close();		
	}
}