import java.io.*;
import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        File inFile = new File("euclid2.in");
        try {
            Writer outFile = new FileWriter("euclid2.out"); 
            Scanner scanner = new Scanner(inFile);
            // Integer T = scanner.nextInt();
            // int a = 0;
            // int b = 0;
            // for(int i=0; i<T; i++){
            //     a = scanner.nextInt();
            //     b = scanner.nextInt();
            //     outFile.write(Integer.valueOf(get_gcd(a,b)).toString());
            //     outFile.write('\n');
            // }
            scanner.close();
            outFile.close();
        } catch (Exception e) {
            // e.printStackTrace();
        }
    }

    private static int get_gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return get_gcd(b, a % b);
    }
}