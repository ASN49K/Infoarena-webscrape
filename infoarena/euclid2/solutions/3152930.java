import java.io.*;

public class Main {

    public static int cmmdc(int a, int b){
        if (b==0){return a;}
        else return cmmdc(b,a%b);
    }

    public static void main (String[] args) throws Exception{
        BufferedReader scanner = new BufferedReader(new FileReader("euclid2.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("euclid2.out"));
        int n= Integer.parseInt(scanner.readLine());
        System.out.println(n);

        for (int i=0;i<n;i++){
         String[] parts = scanner.readLine().split(" ");
            int a = Integer.parseInt(parts[0]);
            int b = Integer.parseInt(parts[1]);
            System.out.println(a+" "+b);

          writer.write(Integer.toString(cmmdc(a, b)));
          writer.newLine();
        }
       
        scanner.close();
        writer.close();
    }
}