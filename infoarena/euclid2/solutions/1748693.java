import java.io.*;
import java.util.*;
 
public class main {

    private static int euclid(int a,int b){
        if(b == 0)
            return a;
        return euclid(b,a%b);
    }

    public static void main(String[] args) throws IOException {

        Scanner in= new Scanner(new File("euclid2.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("euclid2.out"));
         
        int t,a,b;
        t= in.nextInt();
        for(int i=0;i<t;i++){
            a= in.nextInt();
            b= in.nextInt();
            out.println(euclid(a,b));
        }
        in.close();
        out.close();
        //new Main().solve(in, out);

    }
}