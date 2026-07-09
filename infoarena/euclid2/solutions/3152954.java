import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int cmmdc(int a, int b){
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("euclid2.in"));
            BufferedWriter writer = new BufferedWriter(new FileWriter("euclid2.out"));

            int T = Integer.parseInt(reader.readLine());

            for (int i = 0; i < T; i++) {
                StringTokenizer st = new StringTokenizer(reader.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                writer.write(Integer.toString(cmmdc(a, b)));
                writer.newLine();
            }

            reader.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}