import java.util.*;
import java.io.*;
public class Main {
    public static void main (String [] args){
        
        try{
            Scanner scanner = new Scanner (new File("euclid2.in"));
            FileWriter writer = new FileWriter(new File ("euclid2.out"));
            int T = scanner.nextInt();
            //Vector <Integer> v = new Vector<>();
            int [] v = new int [T];
            int n = 0;
            for( int i = 0; i < T; i++){
                int a = scanner.nextInt();
                int b = scanner.nextInt();
                    while(a!=b){
                        if (a > b){
                            a = a - b;
                        }    
                        if(b > a){
                            b = b - a;
                        }
                    }
           //v.add(b);
           v[n]=b;
           n++;
            }
            for (int i = 0; i < v.length; i++){
                writer.write(Integer.toString(v[i]) + "\n");
                //writer.newLine();
            }
            scanner.close();
           writer.close();
        } 
        catch (Exception e){}    
    }
}