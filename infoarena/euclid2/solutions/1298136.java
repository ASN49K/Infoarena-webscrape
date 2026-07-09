import java.io.*;

/**
 * Created by negreanm on 12/22/2014.
 */
public class Main {

    public static void main(String[] args) {
        FileInputStream f = null;
        BufferedReader buf = null;
        int c = 0;
        try {

            f = new FileInputStream("euclid2.in");
            buf = new BufferedReader(new InputStreamReader(f));
            int size = Integer.parseInt(buf.readLine());
            String result = "";
            for (int i = 0; i < size; i++) {
                int a = 0, b = 0;
                String line = buf.readLine();
                String[] values = line.split("\\s+");
                c = euclid(Integer.parseInt(values[0]), Integer.parseInt(values[1]));
                result += c;
                if(i < size - 1) {
                    result += '\n';
                }
            }
            print(result);
            buf.close();
            f.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void print(String c) {
        PrintWriter b = null;

//        BufferedWriter b = null;
        FileWriter f = null;
        try {
            b = new PrintWriter(new BufferedWriter(new FileWriter("euclid2.out")));
            f = new FileWriter("euclid2.out");
//            b = new BufferedWriter(f);
            b.println(c);
//            b.println();
            b.flush();
            b.close();
            f.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int euclid(int a, int b) {
        if(a == 0) return b;
        return euclid(b % a, a);
    }

}
