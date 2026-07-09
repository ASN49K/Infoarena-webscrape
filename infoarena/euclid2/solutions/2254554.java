package euclid;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class Main {
	
	public static void main(String[] args)
	{
		BufferedReader inputFile;
		try {
			inputFile = new BufferedReader(
						new FileReader("euclid2.in"));
			PrintWriter outputFile = new PrintWriter("euclid2.out");
			
			int a, b, c;
			int n = Integer.parseInt(inputFile.readLine());
			String input;
			String [] inputParsing;
			
			for(int i=0; i<n; ++i)
			{
				
				input = inputFile.readLine();
				inputParsing = input.split(" ");
				a = Integer.parseInt(inputParsing[0]);
				b =Integer.parseInt(inputParsing[1]);
				
				while(b != 0)
				{
					c = a;
					a = b;
					b = c % b;
				}
				
				outputFile.println(a);
			}
			
	
			outputFile.close();
			inputFile.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
