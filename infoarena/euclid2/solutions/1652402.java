import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main{

    public static void main(String[] args) {

        try {
            File file = new File("euclid2.in");
            Scanner scanner = new Scanner(file);
            PrintWriter printWriter = new PrintWriter("euclid2.out");

            int aux,a=0,b=0,total = scanner.nextInt();
            
            for(int i=0;i<total;i++){
            
            a= scanner.nextInt();
            b= scanner.nextInt();

                
            while(b!=0){
            aux = b;
            b=a%b;
            a=aux;
            }

		char c = (char)a;
            
            printWriter.println(c);
            }
            scanner.close();
            printWriter.close();
        }
        catch (IOException ex) {
            System.err.println("IO EXCEPTION");
        }
    }
}