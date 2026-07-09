import java.util.*;
import java.io.*;
public class Euclid
{

    public static int  euclid(int x, int y){
        if(y==0) return x;
        return euclid(y,x%y);
    }

    public static void main(String [] args) throws IOException{

        BufferedReader buf = new BufferedReader(new FileReader("euclid2.in"));
        PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("euclid2.out")));
        StringTokenizer tok =new StringTokenizer(buf.readLine());
        int numberOfPairs=Integer.parseInt(tok.nextToken());
        for(int i=0;i<numberOfPairs;i++){
            StringTokenizer str = new StringTokenizer(buf.readLine());
            int x=Integer.parseInt(str.nextToken());
            int y=Integer.parseInt(str.nextToken());
            int d=euclid(x,y);
            out.print(d);
            out.print("\n");
        }
        out.close();
    }
}