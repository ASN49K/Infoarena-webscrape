import java.*;
import java.io.File; 
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;


import java.nio.file.Path;
import java.nio.file.Paths;
public class Main{

    
    public static void main(String[] args) throws IOException {
        int n,a,b,r;
        FileWriter writer;
        writer = new FileWriter("euclid2.out");
        
        File file = new File("euclid2.in"); 
        Scanner sc = null;
        sc = new Scanner(file);
        n=sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            a=sc.nextInt();
            b=sc.nextInt();
            while(b!=0)
            {
                r=a%b;
                a=b;
                b=r;
            }
            writer.write(String.valueOf(a));
            writer.write("\n");
        }
        writer.close();
    }

}
