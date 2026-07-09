import java.util.*;
import java.io.*;
public class Main {
    public static void main (String [] args){
        try {
            Scanner scanner;
            FileWriter writer;
            scanner = new Scanner (new File("cmlsc.in"));
            writer = new FileWriter(new File("cmlsc.out"));
            int M = scanner.nextInt();
            int N = scanner.nextInt();
            Vector <Integer> v = new Vector<>();
            Vector <Integer> p = new Vector<>();
            Vector <Integer> z = new Vector <> ();
                for (int i = 0; i < M; i++){
                    v.add(scanner.nextInt());
                }
                for( int i = 0; i < N; i++){
                    p.add(scanner.nextInt());
                }
                for( int i = 0; i < M; i++){
                    int c = v.elementAt(i);
                    for(int j = 0; j < N; j++){
                        if (c == p.elementAt(j)){
                            z.add(c);
                        }
                    }
                }
                //Collections.sort(z);
                writer.write(Integer.toString(z.size()) + "\n");
                for (int i = 0; i < z.size();i++){
                    writer.write(z.elementAt(i).toString() + " ");
                }
                scanner.close();
                writer.close();

        } catch (Exception e) {
            //TODO: handle exception
        }
    }
}