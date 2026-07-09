import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Euclid {

	public static int cmmdc(int a, int b) {
		int result = 1;
		int max = a;
		if(b < max)
			max = b;
		for(int index = 2; index <= max; index++) {
			if((a % index == 0) && (b % index == 0)) {
				result = index;
			}
		}
		return result;
	}

	public static void main(String[] args) throws IOException {
		File inputFile = new File("euclid2.in");
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
				
		File outputFile = new File("euclid2.out");
		FileWriter fWriter = new FileWriter (outputFile);
	    PrintWriter pWriter = new PrintWriter (fWriter);	    
		
		Scanner scanner = null;
		int result = 1;
		int a = 0;
		int b = 0;
		String line = reader.readLine();
		int T = Integer.parseInt(line);
		System.out.println(T);
		
		
		while ((line = reader.readLine()) != null) {
			scanner = new Scanner(line);
			a = scanner.nextInt();
			b = scanner.nextInt();		
						
			result = cmmdc(a,b);
			pWriter.println(result);			
			System.out.println("a=" + a + " b=" + b + "-> cmmdc=" + result);
		}
		
		pWriter.close();
		reader.close();
		

	}
}
