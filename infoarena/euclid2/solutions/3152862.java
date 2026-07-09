import java.io.*;
import java.util.Scanner;

public class Main {
   
    public static void main (String[] args) throws Exception{
        Scanner scanner = new Scanner(new FileInputStream(new File("euclid2.in")));
        PrintWriter writer = new PrintWriter(new FileOutputStream(new File("euclid2.out")));
        int n = scanner.nextInt();
        
        for (int i=0;i<n;i++){
          int a = scanner.nextInt();
          int b = scanner.nextInt();
          while (a!=b & a%b!=0 & b%a!=0){
            if (a>b) a%=b;
            else b%=a;};
        if (a>b) writer.println(b);
        else  writer.println(a);
        }
        scanner.close();
        writer.close();
    }
}