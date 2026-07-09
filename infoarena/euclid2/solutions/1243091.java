import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class Test {

	private static String line;
	private static int a;
	private static int b;
	private static int counter=0;
	private static BufferedReader br;
	
	
	public static void main(String args[])
	{
		System.out.println("Test");
		
		try {
			br	 = new BufferedReader(new FileReader("adunare.in"));
			while (  (line=br.readLine())!=null)
			{
				if(counter==0)
				{
				a = Integer.parseInt(line);
				++counter;
				}
				else
				{
				b = Integer.parseInt(line);
				}
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			try {
				br.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		System.out.println(a+b);
	}
}
