//package javaapplication1;
import java.io.*;
import java.util.*;

public class Main {
    public static int cmmdc( int a, int b ){
        if( a==0 )
            return b;
        else
            return cmmdc( b, a%b );
    }
    public static void main(String[] args) throws IOException{
        int n, i, a, b, d;
        Scanner fin = new Scanner( new FileInputStream( "euclid2.in" ) );
        PrintStream fout = new PrintStream( "euclid2.out" );
        n = fin.nextInt();
        for( i=0; i<n; i++ ){
            a = fin.nextInt();
            b = fin.nextInt();
            d = cmmdc( a, b );
            fout.println( d );
        }
    } 
}
