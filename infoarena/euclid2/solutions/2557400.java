import java.util.*;
import java.io.*;
public class Main {
    public static void main (String [] args){
        
        try{
            Scanner scanner = new Scanner (new File("euclid2.in"));
            FileWriter writer = new FileWriter(new File ("euclid2.out"));
            int T = scanner.nextInt();
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
                writer.write(Integer.toString(b) + "\n");
                    
            }
            
            scanner.close();
           writer.close();
        } 
        catch (Exception e){}    
    }
}