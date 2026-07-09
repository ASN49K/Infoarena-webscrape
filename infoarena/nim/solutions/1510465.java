import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner input;
		BufferedWriter output;
		
		try {
//			input = new BufferedReader(new InputStreamReader(
//					new FileInputStream("nim.in"), Charset.forName("UTF-8")));
			output = new BufferedWriter(new FileWriter("nim.out"));
			input = new Scanner(new FileReader("nim.in"));
			
//			input.useDelimiter(" ");
//			System.out.println(input.hasNext());
			int nrOfTests = input.nextInt();
			input.nextLine();
			long nimSum, number;
			int digit;
			
			for (int i = 0; i < nrOfTests; i++){
				
				int piles = input.nextInt();
				input.nextLine();
				nimSum = 0;
//				String str = input.readLine();
//				String[] strs = str.trim().split("\\s+");
				
				for (int j = 0; j < piles; j++){
//					number = Integer.parseInt(strs[j]);
//					Character ch = (char) input.read();
//					number = Character.getNumericValue(ch);
//					while ((digit = Character.getNumericValue((char) input.read())) != -1){
//						number = number*10 + digit;
//					}
					number = input.nextInt();
					nimSum = nimSum ^ number;
				}
				if (input.hasNextLine()) input.nextLine();
				
				if (nimSum != 0){
					output.write("DA");
					output.newLine();
				} else {
					output.write("NU");
					output.newLine();
				}
			}
			
			input.close();
			output.close();
			
			
		} catch (IOException e) {
		}
		
	}

	public static int readInt(BufferedReader input) throws IOException{
		String str = input.readLine();
		return Integer.parseInt(str);
	}

}
