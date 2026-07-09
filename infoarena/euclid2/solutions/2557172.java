import java.util.*;
import java.io.*;
public class Main {
    public static void main (String [] args){
        
        try{
            Scanner scanner = new Scanner (new File("euclid2.in"));
            FileWriter writer = new FileWriter(new File ("euclid2.out"));
            int T = scanner.nextInt();
            Vector <Integer> v = new Vector<>();
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
           v.add(b);
            }
            for (int i = 0; i < v.size(); i++){
                writer.write(v.elementAt(i).toString() + "\n");
                //writer.newLine();
            }
            scanner.close();
           writer.close();
        } 
        catch (Exception e){}    
    }
}