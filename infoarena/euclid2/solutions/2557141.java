import java.util.*;
import java.io.*;
public class Main {
    public static void main (String [] args){
        
        try{
            Scanner scanner = new Scanner (new File("euclid2.in"));
            FileWriter writer = new FileWriter(new File ("euclid2.out"));
            int a = scanner.nextInt();
            Vector <Integer> v = new Vector<>();
            for( int i = 0; i < a; i++){
                int b = scanner.nextInt();
                int c = scanner.nextInt();
                    while(b!=c){
                        if (b > c){
                            b = b - c;
                        }    
                        if(c > b){
                            c = c - b;
                        }
                    }
           v.add(b);
            }
            for (int i = 0; i < v.size(); i++){
                writer.write(v.elementAt(i).toString() + " ");
            }
            scanner.close();
            writer.close();
        } 
        catch (Exception e){}    
    }
}