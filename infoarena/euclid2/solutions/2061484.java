import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main{

    public static void main(String[] args) throws IOException{
        long startTime = System.currentTimeMillis();
        Scan in = new Scan("euclid2.in");
        PrintWriter out = new PrintWriter("euclid2.out");
        // *****************************************************************************
        
        int t = in.nextInt();
        while(t-- != 0){
            int a = in.nextInt();
            int b = in.nextInt();
            int c;
            while((c = (a % b)) != 0){
                a = b;
                b = c;
            }
            out.println(b);
        }
        
        
        
        
        
        // *****************************************************************************
        out.close();
        long endTime   = System.currentTimeMillis();
        //.out.println("Runtime: " + ((double)(endTime - startTime) / 1000));
    }
    
    static class Scan {
        BufferedReader bufferedReader;
        StringTokenizer stringTokenizer;
 
        Scan(String file) throws IOException {
            bufferedReader = new BufferedReader(new FileReader(file));
        }
 
        String next() throws IOException {
            while (stringTokenizer == null || !stringTokenizer.hasMoreElements())
                stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            return stringTokenizer.nextToken();
        }
 
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
    
}
