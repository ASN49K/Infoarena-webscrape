import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {

	public static void main(String[] args) {

		BufferedReader input;
		BufferedWriter output;
		
		try {
			input = new BufferedReader(new FileReader("nim.in"));
			output = new BufferedWriter(new FileWriter("nim.out"));
			
			int nrOfTests = readInt(input);
			int nimSum;
			int number;
			
			for (int i = 0; i < nrOfTests; i++){
				
				int piles = readInt(input);
				nimSum = 0;
				String str = input.readLine();
				String[] strs = str.trim().split("\\s+");
				
				for (int j = 0; j < piles; j++){
					number = Integer.parseInt(strs[j]);
					nimSum = nimSum ^ number;
				}
				
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
