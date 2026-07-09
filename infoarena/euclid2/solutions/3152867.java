import java.io.*;
import java.util.Scanner;

public class Main {

    public static short cmmdc(int a, int b){
        if (b==0){return (short) a;}
        else return cmmdc(b,a%b);
    }

    public static void main (String[] args) throws Exception{
        Scanner scanner = new Scanner(new FileInputStream(new File("euclid2.in")));
        PrintWriter writer = new PrintWriter(new FileOutputStream(new File("euclid2.out")));
        scanner.nextInt();
        
        while (scanner.hasNextInt()){
          int a = scanner.nextInt();
          int b = scanner.nextInt();
          writer.println(cmmdc(a, b));
        }
       
        scanner.close();
        writer.close();

    }
}