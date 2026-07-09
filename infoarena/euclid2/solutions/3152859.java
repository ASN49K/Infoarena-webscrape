import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static int cmmdc(int a, int b){

        while (a!=b & a%b!=0 & b%a!=0){
            if (a>b) a%=b;
            else b%=a;
        };
        if (a>b) return b;
        else return a;
    }

    public static void main (String[] args) throws Exception{
        Scanner scanner = new Scanner(new FileInputStream(new File("euclid2.in")));
        PrintWriter writer = new PrintWriter(new FileOutputStream(new File("euclid2.out")));
        int n = scanner.nextInt();
        
        for (int i=0;i<n;i++){
          int a = scanner.nextInt();
          int b = scanner.nextInt();
          writer.println(cmmdc(a, b));
        }
       
        scanner.close();
        writer.close();

    }
}