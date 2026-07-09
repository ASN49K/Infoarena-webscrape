import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Main{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        try {
            File file = new File("euclid2.in");
            Scanner scanner = new Scanner(file);
            FileWriter fw= new FileWriter("euclid2.out");

            int aux,a=0,b=0,total = scanner.nextInt();
            
            for(int i=0;i<total;i++){
            
            a= scanner.nextInt();
            b= scanner.nextInt();

                
            while(b!=0){
            aux = b;
            b=a%b;
            a=aux;
            }
           
                fw.write(a);
		fw.write("\r\n");
                
            }
            scanner.close();
            fw.close();
        }
        catch (IOException ex) {
            System.err.println("IO EXCEPTION");
        }
    }
}
