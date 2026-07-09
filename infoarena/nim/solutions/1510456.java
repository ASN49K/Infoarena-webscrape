import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;

public class Main {

	public static void main(String[] args) {

		BufferedReader input;
		BufferedWriter output;
		
		try {
			input = new BufferedReader(new InputStreamReader(
					new FileInputStream("nim.in"), Charset.forName("UTF-8")));
			output = new BufferedWriter(new FileWriter("nim.out"));
			
			int nrOfTests = readInt(input);
			long nimSum, number;
			int digit;
			
			for (int i = 0; i < nrOfTests; i++){
				
				int piles = readInt(input);
				nimSum = 0;
//				String str = input.readLine();
//				String[] strs = str.trim().split("\\s+");
				
				for (int j = 0; j < piles; j++){
//					number = Integer.parseInt(strs[j]);
					Character ch = (char) input.read();
					number = Character.getNumericValue(ch);
					while ((digit = Character.getNumericValue((char) input.read())) != -1){
						number = number*10 + digit;
					}
					nimSum = nimSum ^ number;
				}
				input.readLine();
				
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
