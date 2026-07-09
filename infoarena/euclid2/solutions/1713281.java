import java.io.*;
public class Main {

    public static int cmmdc( int a, int b ){
        if( b==0 )
            return a;
        else
            return cmmdc( b, a%b );
    }
    public static void main(String[] args) throws IOException{
        int n, i, a, b, d;
        StreamTokenizer fin = new StreamTokenizer( new BufferedReader( new FileReader ( "euclid2.in" ) ) );
        PrintWriter fout = new PrintWriter(new BufferedWriter( new FileWriter ( "euclid2.out" ) ) );
        n = fin.nextToken();
        for( i=0; i<n; i++ ){
            a = fin.nextToken();
            b = fin.nextToken();
            d = cmmdc( a, b );
            fout.println( d );
        }
        fout.close();
    } 
}
